//
// Created by anselme on 23/06/22.
//

#include "../utils/Service.cpp"

class AccountService : Service {

public:
    explicit AccountService() : Service("accounts") {}

    void update_by_id(int id, Account accountInfo){

        Account existingAccount = find_by_id(id);
        if (existingAccount.account_id == -1) {
            cout << "User not available in the system";
        }

        vector<Account> previousAccounts = read();

        fstream outputStream;

        outputStream.open(get_temp_data_store_path(), ios::out | ios::app);

        int _id = 1;
        for (const Account &account: previousAccounts) {
            if (account.account_id != id) {
                outputStream << _id << ", " << account.full_names << ", " << account.account_number << ", " << account.account_pin << ", " << account.username << "\n";
            } else {
                outputStream << _id << ", " << accountInfo.full_names << ", " << accountInfo.account_number << ", " << accountInfo.account_pin << ", " << accountInfo.username << "\n";
            }

            _id++;
        }

        remove(get_data_store_path().c_str());
        rename(get_temp_data_store_path().c_str(), get_data_store_path().c_str());

        outputStream.close();
    }

    void store(const Account &account) {
        fstream outputStream;

        outputStream.open(get_data_store_path(), ios::out | ios::app);

        outputStream << next_id() << ", " << account.full_names << ", " << account.account_number << ", "
                     << account.account_pin << ", " << account.username << "\n";
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

    void delete_by_id(int id) {
        Account existingAccount = find_by_id(id);
        if (existingAccount.account_id == -1) {
            cout << "User not available in the system";
        }

        vector<Account> previousAccounts = read();

        fstream outputStream;

        outputStream.open(get_temp_data_store_path(), ios::out | ios::app);

        int _id = 1;
        for (const Account &account: previousAccounts) {
            if (account.account_id != id) {
                outputStream << _id << ", " << account.full_names << ", " << account.account_number << ", " << account.account_pin << ", " << account.username << "\n";

                _id++;
            }

        }

        remove(get_data_store_path().c_str());
        rename(get_temp_data_store_path().c_str(), get_data_store_path().c_str());

        outputStream.close();
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
