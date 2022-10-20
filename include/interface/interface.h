#ifndef _INTERFACE_H_
#define _INTERFACE_H_

#include <stdlib.h>
#include "bool.h"
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

#define make_all(T, YPE) \
static void all##T##YPE##s() { \
    print##T##YPE##sInfo(); \
    successMessage(); \
}

#define make_ban(T, YPE, Name, Who) \
static void ban##T##YPE() { \
    char id[MAX_LEN]; \
    printf("Please input %s ID to be banned: ", Name); \
    scanf("%s", id); \
    if (delete##T##YPE##ByID(id, Who)) { \
	successMessage(); \
    } else { \
	failureMessage(); \
    } \
}

#define make_search(Who) \
static void search() { \
    char buffer[MAX_LEN]; \
    printf("Please input Good Name to search: "); \
    scanf("%s", buffer); \
    loadingMessage(); \
    searchGoodNameIn##Who(buffer); \
    successMessage(); \
}

#define check_double \
    double m = atof(buffer); \
    while (true) { \
	if (m > 0) { \
	    break; \
	} \
	illegalMessage(); \
	printf("Please try again: "); \
	scanf("%s", buffer); \
	m = atof(buffer); \
    }

#define make_modify(TYPE, W, HO) \
static void modify_##TYPE() { \
    char buffer[MAX_LEN]; \
    printf("Please input new %s: ", #TYPE); \
    scanf("%s", buffer); \
    W##HO* x = get##W##HO##ByIndex(cur##W##HO); \
    strcpy(x->TYPE, buffer); \
    successMessage(); \
}

#define make_my(TYPE, W, HO) \
static void my##TYPE() { \
    print##TYPE##About##W##HO##ID(getUserByIndex(curUser)->id); \
    successMessage(); \
}

#define fail { \
    failureMessage(); \
    return; \
}

extern int curUser;
extern int curGood;

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
