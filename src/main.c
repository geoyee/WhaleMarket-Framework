#include "interface/interface.h"
#include "tools/hint.h"

int main() {
    pullUsersFromFile();
    pullGoodsFromFile();
    pullOrdersFromFile();

    welcomeMessage();
    MAIN_Interface();
    exitingMessage();

    pushUsersToFile();
    pushGoodsToFile();
    pushOrdersToFile();
    return 0;
}
