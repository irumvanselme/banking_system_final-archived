//
// Created by anselme on 23/06/22.
//

#include "../utils/Service.cpp"

class AccountService : Service {

public:
    explicit AccountService() : Service("accounts") {}

    void store(const Account &account) {
        fstream outputStream;

        outputStream.open(get_data_store_path(), ios::out | ios::app);

        outputStream << account.account_id << ", " << account.full_names << ", " << account.account_number << ", "
                     << account.account_pin << ", " << account.username << "\n";
    }

    vector<Account> read() {
        vector<Account> accounts;

        fstream fin;
        fin.open(get_data_store_path(), ios::in);

        string line;

        while (getline(fin, line)) {
            std::stringstream ss(line);
            Account account;
            int k = 0;
            for (string rowElement; ss >> rowElement;) {
                switch (k) {
                    case 0:
                        account.account_id = stoi(rowElement);
                        break;
                    case 1:
                        account.full_names = rowElement;
                        break;
                    case 2:
                        account.account_number = rowElement;
                        break;
                    case 3:
                        account.account_pin = rowElement;
                        break;
                    case 4:
                        account.username = rowElement;
                        break;
                    default:
                        break;
                }
                k++;
                if (ss.peek() == ',')
                    ss.ignore();
            }
            accounts.push_back(account);
        }

        return accounts;
    }
};
