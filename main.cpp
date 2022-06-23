#include "./utils/headers.h"
#include "./services/account-service.cpp"

int main() {
    AccountService accountService;

    accountService.read();

    return 0;
}
