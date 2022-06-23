//
// Created by anselme on 17/06/22.
//
#include "iostream"

#pragma once

using namespace std;

// ENUMS
enum ETransactionType {
    WITHDRAW, DEPOSE
};

// Models
typedef struct Branch {
public:
    int branch_id;
    std::string name;
} Branch;

class Account {
public:
    int account_id;
    std::string full_names;
    std::string account_number;
    std::string username;
    std::string account_pin;
};

typedef struct Transaction {
    int transaction_id;
    int account_id;
    int branch_id;
    double amount;
    ETransactionType transactionType;
} Transaction;