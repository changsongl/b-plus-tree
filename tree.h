//
// Created by Changsong Li on 2022/2/9.
//

#include "stdio.h"
#include "node.h"

#ifndef B_PLUS_TREE_TREE_H
#define B_PLUS_TREE_TREE_H

typedef struct tree {
    FILE *fptr;
    int order;
    metadata *m;
} tree;

tree* create_tree(char *path, int order);

#endif //B_PLUS_TREE_TREE_H
