#include <stdio.h>
#include <stdlib.h>
#include "interface/interface.h"

static void info() {
    printUserInfo(curUser);
    successMessage();
}

static void topUp() {
    char buffer[MAX_LEN];
    printf("Please input the amount of money: ");
    scanf("%s", buffer);
    check_double
    User* user = getUserByIndex(curUser);
    user->balance += m;
    successMessage();
}

static HANDLER handler[] = {info, MODIFY_Interface, topUp};
make_interface(I, NFO)
