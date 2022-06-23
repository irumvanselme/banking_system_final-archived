#include "./utils/headers.h"
#include "./services/account-service.cpp"

int main() {
    AccountService accountService;
    Account account{1, "IRUMVA", "123456789", "kagabo", "123"};

    vector<Account> accounts = accountService.read();

    cout << "Username: " << accounts.at(1).account_id << endl;

    return 0;
}
