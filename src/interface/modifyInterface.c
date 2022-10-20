#include <stdio.h>
#include <string.h>
#include "interface/interface.h"

static void modify_passwd() {
    char buffer[MAX_LEN];
    printf("Please input current password: ");
    scanf("%s", buffer);
    User* user = getUserByIndex(curUser);
    if (strcmp(user->passwd, buffer)) {
	fail
    }
    printf("Please input new password: ");
    scanf("%s", buffer);
    strcpy(user->passwd, buffer);
    successMessage();
}

make_modify(contact, U, ser)
make_modify(address, U, ser)

static HANDLER handler[] = {modify_passwd, modify_contact, modify_address};
make_interface(M, ODIFY)
