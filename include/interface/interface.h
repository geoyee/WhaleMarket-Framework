#ifndef _INTERFACE_H_
#define _INTERFACE_H_

#include "tools/hint.h"
#include "menu/menu.h"
#include "user/user.h"
#include "good/good.h"
#include "order/order.h"

typedef void (*HANDLER)(void);

#define make_interface(T, YPE) \
void T##YPE##_Interface() { \
    successMessage(); \
    int op = menu(T##YPE); \
    while (op != optionNum[T##YPE]) { \
	loadingMessage(); \
	handler[op - 1](); \
	op = menu(T##YPE); \
    } \
    loadingMessage(); \
    successMessage(); \
}

#define get_username_passwd \
    char username[MAX_LEN]; \
    char passwd[MAX_LEN]; \
    printf("Username: "); \
    scanf("%s", username); \
    printf("Password: "); \
    scanf("%s", passwd);

#define make_login(T, YPE, cond) \
static void T##YPE##_Login() { \
    get_username_passwd \
    if (cond) { \
	T##YPE##_Interface(); \
	return; \
    } \
    failureMessage(); \
}

extern int curUser;

void inv();

void MAIN_Interface();

void ADMIN_Interface();

void USER_Interface();

void BUYER_Interface();

void SELLER_Interface();

void INFO_Interface();

void MODIFY_Interface();

void GOOD_Interface();

#endif
