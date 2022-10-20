#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "interface/interface.h"

static void buy() {
    char buffer[MAX_LEN];
    printf("Please input Good id to buy: ");
    scanf("%s", buffer);
    int index = searchGoodByID(buffer);
    if (index == -1) {
	fail
    }
    Good* good = getGoodByIndex(index);
    User* user = getUserByIndex(curUser);  // buyer
    if (good->state != SELLING) {
	fail
    }
    if (good->price > user->balance) {
	fail
    }
    user->balance -= good->price;
    good->state = SOLD;
    userTopUp(good->seller_id, good->price);
    // generate an order
    Order* order = (Order*)malloc(sizeof(Order));
    strcpy(order->good_id, good->id);
    strcpy(order->seller_id, good->seller_id);
    strcpy(order->buyer_id, user->id);
    order->price = good->price;
    if (addOrder(order)) {
	successMessage();
    } else {
	failureMessage();
    }
    free(order);
}

static void info() {
    char buffer[MAX_LEN];
    printf("Please input Good ID for more information: ");
    scanf("%s", buffer);
    int index = searchGoodByID(buffer);
    if (index == -1) {
	fail
    }
    loadingMessage();
    printGoodInfo(index);
    successMessage();
}

make_search(Buyer)

make_my(Goods, B, uyer)
make_my(Orders, B, uyer)

static HANDLER handler[] = {myGoods, buy, search, myOrders, info};
make_interface(B, UYER)
