//
// Created by Changsong Li on 2022/2/9.
//

#include "stdio.h"
#include "stdlib.h"
#include "string.h"
#include "const.h"
#include "btree.h"
#include "file.h"

int main(int argc, char **argv){
    printf("Welcome to b+ tree!\n");
    char *line = NULL;
    size_t len = 0;
    ssize_t lineSize = 0;
    int finished = CONST_FALSE;
    int i;
    file *f;

    for (i = 0; i < argc - 1; i += 2) {

    }

    f = open_file("/Users/changsongli/Desktop/Jason/C/GitHub/b-plus-tree/btree-data", 10);
    insert_num(f, 30);
    read_num(f);
    do {
        lineSize = getline(&line, &len, stdin);
        if (lineSize > 0) {
            line[lineSize-1] = '\0';
        }

        if (strncasecmp(line, "add", 3) == 0) {
//            insert_num(f, 3);
        }else if (strncasecmp(line, "del", 3) == 0) {
            printf("del\n");
        }else if (strncasecmp(line, "size", 4) == 0) {
            printf("size\n");
        }else if (strncasecmp(line, "help", 4) == 0) {
            print_manual();
        }else if (strcasecmp(line, "exit") == 0) {
            finished = CONST_TRUE;
        }else {
            printf("Invalid command, type help for instructions.\n");
        }

    }while(finished == CONST_FALSE);

    free(line);

    return 0;
}

void print_manual() {
    printf("add  : insert number to b+ tree.\n");
    printf("del  : delete number to b+ tree.\n");
    printf("size : print size of b+ tree.\n");
    printf("help : print instructions.\n");
    printf("exit : quit the program.\n");
}

