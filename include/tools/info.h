#ifndef _INFO_H_
#define _INFO_H_

static const char* header = "|ID         |Name       |Contact    |Address    |Balance    |";
static const char* divide = "+-----------+-----------+-----------+-----------+-----------+";

#define print_header \
    printf("%s\n", divide); \
    printf("%s\n", header); \
    printf("%s\n", divide);

#define print_divide \
    printf("%s\n", divide);

void genID(char* dest, char type);
void getDate(char* dest);

#endif
