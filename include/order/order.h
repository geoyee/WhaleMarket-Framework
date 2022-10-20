#ifndef _ORDER_H_
#define _ORDER_H_

#include "config.h"
#include "bool.h"

typedef struct {
    char id[MAX_LEN];
    char good_id[MAX_LEN];
    double price;
    char date[MAX_LEN];
    char seller_id[MAX_LEN];
    char buyer_id[MAX_LEN];
} Order;

void pullOrdersFromFile();

void pushOrdersToFile();

bool addOrder(Order* order);

void printOrdersInfo();

void printOrdersAboutSellerID(const char* id);

void printOrdersAboutBuyerID(const char* id);

#endif
