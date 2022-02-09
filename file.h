//
// Created by Changsong Li on 2022/2/9.
//

#include "stdio.h"

#ifndef B_PLUS_TREE_FILE_H
#define B_PLUS_TREE_FILE_H

typedef struct file {
    FILE *fptr;
} file;

file* open_file(char *path, int order);

int insert_num(file *f, int num);

int read_num(file *f);

#endif //B_PLUS_TREE_FILE_H
