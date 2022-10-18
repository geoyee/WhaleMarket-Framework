#ifndef _MENU_H_
#define _MENU_H_

typedef enum {MAIN, ADMIN, USER, BUYER, SELLER, INFO, MODIFY, GOOD} Menu;

extern const int optionNum[];

int menu(Menu type);

#endif
