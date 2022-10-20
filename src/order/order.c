#include "stdio.h"
#include "string.h"
#include "bool.h"
#include "order/order.h"
#include "tools/info.h"

static Order orders[MAX_ORDER];
static int totalOrder = 0;

static const char* filePath = "src/data/order.txt";

void pullOrdersFromFile() {
    totalOrder = 0;
    FILE* pf = fopen(filePath, "r");
    if (pf) {
	while (fscanf(
	    pf,
	    "%s%s%lf%s%s%s",
	    orders[totalOrder].id,
	    orders[totalOrder].good_id,
	    &orders[totalOrder].price,
	    orders[totalOrder].date,
	    orders[totalOrder].seller_id,
	    orders[totalOrder].buyer_id
	) != EOF) {
	    totalOrder++;
	}
	fclose(pf);
    }
}

void pushOrdersToFile() {
    FILE* pf = fopen(filePath, "w");
    for (int i = 0; i < totalOrder; i++) {
	fprintf(
	    pf,
	    "%s %s %.1f %s %s %s\n",
	    orders[i].id,
	    orders[i].good_id,
	    orders[i].price,
	    orders[i].date,
	    orders[i].seller_id,
	    orders[i].buyer_id
	);
    }
    fclose(pf);
}

bool addOrder(Order* order) {
    if (totalOrder == MAX_ORDER) {
	return false;
    }
    genID(order->id, 'O');
    getDate(order->date);
    orders[totalOrder++] = *order;
    return true;
}

static const char* header = "|ID         |Good       |Price      |Date       |Seller     |Buyer      |";
static const char* divide = "+-----------+-----------+-----------+-----------+-----------+-----------+";

static void printOrdersInfoInTable(int index) {
    Order order = orders[index];
    printf(
	"|%-10s |%-10s |%-10.1f |%-10s |%-10s |%-10s |\n",
	order.id,
	order.good_id,
	order.price,
	order.date,
	order.seller_id,
	order.buyer_id
    );
}

void printOrdersInfo() {
    print_header
    for (int i = 0; i < totalOrder; i++) {
        printOrdersInfoInTable(i);
	print_divide
    }
}

void printOrdersAboutSellerID(const char* id) {
    print_header
    for (int i = 0; i < totalOrder; i++) {
	if (strcmp(orders[i].seller_id, id) == 0) {
            printOrdersInfoInTable(i);
	    print_divide
	}
    }
}

void printOrdersAboutBuyerID(const char* id) {
    print_header
    for (int i = 0; i < totalOrder; i++) {
	if (strcmp(orders[i].buyer_id, id) == 0) {
            printOrdersInfoInTable(i);
	    print_divide
	}
    }
}
