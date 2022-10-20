#ifndef _GOOD_H_
#define _GOOD_H_

#include "config.h"
#include "bool.h"

typedef enum {
    SELLING,
    SOLD,
    BANNED
} State;

typedef struct {
    char id[MAX_LEN];
    char name[MAX_LEN];
    double price;
    char seller_id[MAX_LEN];
    State state;
    char date[MAX_LEN];
    char description[MAX_LEN];
} Good;

void pullGoodsFromFile();

void pushGoodsToFile();

Good* getGoodByIndex(int index);

bool addGood(Good* good);

int searchGoodByID(const char* id);

bool deleteGoodByID(const char* id, const char* who);

void printGoodInfo(int index);

void printGoodsInfo();

// 买家只能看销售中的商品
void searchGoodNameInBuyer(const char* name);

// 管理员可以看全部商品，包括下架的
void searchGoodNameInAdmin(const char* name);

void printGoodsAboutSellerID(const char* id);

void printGoodsAboutBuyerID(const char* id);

#endif
