#ifndef _USER_H_
#define _USER_H_

#include "config.h"
#include "bool.h"

typedef struct {
    char id[MAX_LEN];
    char name[MAX_LEN];
    char passwd[MAX_LEN];
    char contact[MAX_LEN];
    char address[MAX_LEN];
    double balance;
} User;

void pullUsersFromFile();

void pushUsersToFile();

User* getUserByIndex(int index);

void printUserInfo(int index);

void printUsersInfo();

bool addUser(User* user);

bool deleteUserByID(const char* id, const char* who);

bool checkPassword(const char* name, const char* passwd, int* index);

bool userTopUp(const char* id, double money);

#endif
