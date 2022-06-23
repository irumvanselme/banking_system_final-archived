#include "./utils/headers.h"
#include "./services/account-service.cpp"

int main() {
    AccountService accountService;

    // get all
    // find by id
    // create
    Account account{
        1,
        "Updated_Anselme",
        "Updated_123456789",
        "updated_anselme",
        "123_u"
    };
//
//    accountService.store(account);

    accountService.update_by_id(9, account);

    // delete
    // update

    return 0;
}
