#include "./utils/headers.h"
#include "./services/account-service.cpp"

int main() {
    AccountService accountService;

    vector<Account> accounts = accountService.read();

    cout << accounts.at(0).full_names;

    return 0;
}
