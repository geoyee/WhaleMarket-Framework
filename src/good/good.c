#include <stdio.h>
#include <string.h>
#include "bool.h"
#include "tools/info.h"
#include "good/good.h"

static Good goods[MAX_GOOD];
static int totalGood = 0;

static const char* filePath = "src/data/good.txt";

void pullGoodsFromFile() {
    totalGood = 0;
    FILE* pf = fopen(filePath, "r");
    if (pf) {
        while (fscanf(
	    pf,
	    "%s%s%lf%s%u%s%s",
	    goods[totalGood].id,
	    goods[totalGood].name,
	    &goods[totalGood].price,
	    goods[totalGood].seller_id,
	    &goods[totalGood].state,
	    goods[totalGood].date,
	    goods[totalGood].description
	) != EOF) {
	    totalGood++;
	}
    }
    fclose(pf);
}

void pushGoodsToFile() {
    FILE* pf = fopen(filePath, "w");
    for (int i = 0; i < totalGood; i++) {
        fprintf(
	    pf,
	    "%s %s %.1f %s %u %s %s\n",
	    goods[i].id,
	    goods[i].name,
	    goods[i].price,
	    goods[i].seller_id,
	    goods[i].state,
	    goods[i].date,
	    goods[i].description
	);
    }
    fclose(pf);
}

Good* getGoodByIndex(int index) {
    return goods + index;
}

bool addGood(Good* good) {
    if (totalGood == MAX_GOOD) {
        return false;
    }
    genID(good->id, 'G');
    getDate(good->date);
    good->state = SELLING;
    goods[totalGood++] = *good;
    return true;
}

int searchGoodByID(const char* id) {
    for (int i = 0; i < totalGood; i++) {
	if (strcmp(goods[i].id, id) == 0) {
	    return i;
	}
    }
    return -1;
}

bool deleteGoodByID(const char* id, const char* who) {
    int index = searchGoodByID(id);
    if (index == -1) {
	return false;
    }
    if (who && strcmp(goods[index].seller_id, who)) {
	return false;
    }
    goods[index].state = BANNED;
    return true;
}

static const char* stateName[] = {"Selling", "Sold", "Banned"};

void printGoodInfo(int index) {
    Good good = goods[index];
    printf("ID:            | %s\n", good.id);
    printf("Name:          | %s\n", good.name);
    printf("Description:   | %s\n", good.description);
    printf("Date:          | %s\n", good.date);
    printf("Price:         | %.1f\n", good.price);
    printf("Seller:        | %s\n", good.seller_id);
    printf("State:         | %s\n", stateName[good.state]);
}

static const char* header = "|ID         |Name       |Price      |Date       |Seller     |State      |";
static const char* divide = "+-----------+-----------+-----------+-----------+-----------+-----------+";

static void printGoodInfoInTable(int index) {
    Good good = goods[index];
    printf(
	"|%-10s |%-10s |%-10.1f |%-10s |%-10s |%-10s |\n",
	good.id,
	good.name,
	good.price,
	good.date,
	good.seller_id,
	stateName[good.state]
    );
}

void printGoodsInfo() {
    print_header
    for (int i = 0; i < totalGood; i++) {
	printGoodInfoInTable(i);
	print_divide
    }
}

void searchGoodNameInBuyer(const char* name) {
    print_header
    for (int i = 0; i < totalGood; i++) {
	if (goods[i].state == SELLING && strstr(goods[i].name, name)) {    
	    printGoodInfoInTable(i);
	    print_divide
	}
    }
}

void searchGoodNameInAdmin(const char* name) {
    print_header
    for (int i = 0; i < totalGood; i++) {
	if (strstr(goods[i].name, name)) {    
	    printGoodInfoInTable(i);
	    print_divide
	}
    }
}

void printGoodsAboutSellerID(const char* id) {
    print_header
    for (int i = 0; i < totalGood; i++) {
	if (strcmp(goods[i].seller_id, id)) {    
	    printGoodInfoInTable(i);
	    print_divide
	}
    }
}

