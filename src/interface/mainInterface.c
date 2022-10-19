#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "interface/interface.h"

void inv() {
    invalidMessage();
    failureMessage();
}

make_login(U, SER, checkPassword(username, passwd, &curUser))
make_login(A, DMIN, strcmp(username, ADMIN_NAME) == 0 && strcmp(passwd, ADMIN_PASS) == 0)

static void USER_SignUp() {
    User* user = (User*)malloc(sizeof(User));
    printf("Please input your username: ");
    scanf("%s", user->name);
    printf("Please input your password: ");
    scanf("%s", user->passwd);
    printf("Please input your phone number: ");
    scanf("%s", user->contact);
    printf("Please input your address: ");
    scanf("%s", user->address);
    user->balance = 0;
    if (addUser(user)) {
 	successMessage();
    } else {
	failureMessage();
    }
    free(user);
}

static HANDLER handler[] = {USER_Login, USER_SignUp, ADMIN_Login};
make_interface(M, AIN)
