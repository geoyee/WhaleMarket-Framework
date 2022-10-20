#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "interface/interface.h"

static void sell() {
    User* seller = getUserByIndex(curUser);
    Good* good = (Good*)malloc(sizeof(Good));
    printf("Please input the information of your product ...\n");
    printf("Name: ");
    scanf("%s", good->name);
    printf("Price: ");
    char buffer[MAX_LEN];
    scanf("%s", buffer);
    check_double
    good->price = m;
    printf("Description: ");
    scanf("%s", good->description);
    strcpy(good->seller_id, seller->id);
    if (addGood(good)) {
	successMessage();
    } else {
	failureMessage();
    }
    free(good);
}

static void modify() {
    printf("Please input the good ID to modify: ");
    char buffer[MAX_LEN];
    scanf("%s", buffer);
    curGood = searchGoodByID(buffer);
    if (curGood == -1) {
  	fail
    }
    User* user = getUserByIndex(curUser);
    Good* good = getGoodByIndex(curGood);
    if (strcmp(user->id, good->seller_id) == 0 && good->state == SELLING) {
	GOOD_Interface();
    } else {
	failureMessage();
    }
}

make_my(Goods, S, eller)
make_my(Orders, S, eller)

make_ban(G, ood, "Godd", getUserByIndex(curUser)->id);

static HANDLER handler[] = {sell, myGoods, modify, banGood, myOrders};
make_interface(S, ELLER)
