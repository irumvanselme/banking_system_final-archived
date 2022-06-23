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

        outputStream << next_id() << ", " << account.full_names << ", " << account.account_number << ", "  << account.account_pin << ", " << account.username << "\n";
    }

    vector<Account> read() {
        vector<Account> accounts;
        fstream fin;

        fin.open(get_data_store_path(), ios::in);

        string line;

        while (getline(fin, line)) {
            std::stringstream ss(line);
            Account account = get_account(line);

            accounts.push_back(account);
        }

        return accounts;
    }

    Account find_by_id(int id) {
        Account account;
        account.account_id = -1;

        fstream fin;

        fin.open(get_data_store_path(), ios::in);

        string line;

        while (getline(fin, line)) {
            if (get_account(line).account_id == id) {
                account = get_account(line);

                return account;
            }
        }

        return account;
    }

private:
    static Account get_account(const string &line) {
        Account account;

        std::stringstream ss(line);
        int k = 0;
        for (string rowElement; ss >> rowElement;) {
            if (rowElement[rowElement.length() - 1] == ',')
                rowElement.pop_back();

            if (k == 0) account.account_id = stoi(rowElement);
            else if (k == 1) account.full_names = rowElement;
            else if (k == 2) account.account_number = rowElement;
            else if (k == 3) account.account_pin = rowElement;
            else if (k == 4) account.username = rowElement;


            k++;

        }

        return account;
    }

    int next_id() {
        int next_id = 1;

        fstream fin;
        fin.open(get_data_store_path(), ios::in);

        string line;

        while (getline(fin, line))
            next_id++;

        return next_id;
    }
};
