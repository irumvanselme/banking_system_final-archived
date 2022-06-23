#include "./utils/headers.h"
#include "./services/account-service.cpp"

int main() {
    AccountService accountService;

    // get all
    // find by id
    // create
//    Account account{
//        1,
//        "Anselme",
//        "123456789",
//        "anselme",
//        "123"
//    };
//
//    accountService.store(account);

    accountService.delete_by_id(15);

    // delete
    // update

    return 0;
}
