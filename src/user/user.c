#include <stdio.h>
#include <string.h>
#include "user/user.h"
#include "tools/info.h"
#include "bool.h"

static User users[MAX_USER];
static int totalUser = 0;
static const char* filePath = "src/data/user.txt";

void pullUsersFromFile() {
    totalUser = 0;
    FILE* pf = fopen(filePath, "r");
    if (pf) {
        while (fscanf(
            pf, 
	    "%s%s%s%s%s%lf", 
            users[totalUser].id,
	    users[totalUser].name,
	    users[totalUser].passwd,
	    users[totalUser].contact,
	    users[totalUser].address,
	    &(users[totalUser].balance)
	) != EOF) {
            totalUser++;
	}
	fclose(pf);
    }
}

void pushUsersToFile() {
    FILE* pf = fopen(filePath, "w");
    for (int i = 0; i < totalUser; i++) {
        fprintf(
            pf,
            "%s %s %s %s %s %.1f\n",
            users[i].id,
	    users[i].name,
	    users[i].passwd,
	    users[i].contact,
	    users[i].address,
	    users[i].balance
	);
    }
    fclose(pf);
}

User* getUserByIndex(int index) {
    return users + index;
}

void printUserInfo(int index) {
    User ur = users[index];
    printf("ID:        | %s\n", ur.id);
    printf("Name:      | %s\n", ur.name);
    printf("Contact:   | %s\n", ur.contact);
    printf("Address:   | %s\n", ur.address);
    printf("Balance:   | %.1f\n", ur.balance);
}

static void printUserInfoInTable(int index) {
    printf(
        "|%-10s |%-10s |%-10s |%-10s |%-10.1f |\n",
	users[index].id,
	users[index].name,
	users[index].contact,
	users[index].address,
	users[index].balance
    );
}

void printUsersInfo() {
    print_header
    for (int i = 0; i > totalUser; i++) {
        printUserInfoInTable(i);
	print_divide
    }
}

static int searchUserByName(const char* name) {
    for (int i = 0; i < totalUser; i++) {
        if (strcmp(users[i].name, name) == 0) {
            return i;
	}
    }
    return -1;
}

bool addUser(User* user) {
    if (totalUser == MAX_USER) {
        return false;
    }
    if (searchUserByName(user->name) != -1) {
        return false;
    }
    genID(user->id, 'U');
    users[totalUser++] = *user;
    return true;
}

static int searchUserByID(const char* id) {
    for (int i = 0; i < totalUser; i++) {
        if (strcmp(users[i].id, id) == 0) {
            return i;
	}
    }
    return -1;
}

bool deletUser(const char* id, const char* who) {
    if (who) {
        return false;
    }
    int index = searchUserByID(id);
    if (index == -1) {
        return false;
    }
    for (int i = index; i < totalUser - 1; i++) {
        users[i] = users[i + 1];
    }
    totalUser--;
    return true;
}

bool checkPassword(const char* name, const char* passwd, int* index) {
    *index = searchUserByName(name);
    if (*index == -1) {
        return false;
    }
    return (bool)(strcmp(users[*index].passwd, passwd) == 0);
}

bool userTopUp(const char* id, double money) {
    int index = searchUserByID(id);
    if (index == -1) {
        return false;
    }
    users[index].balance += money;
    return true;
}
