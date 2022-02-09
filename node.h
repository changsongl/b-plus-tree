//
// Created by Changsong Li on 2022/2/9.
//

#include "stdio.h"

#ifndef B_PLUS_TREE_NODE_H
#define B_PLUS_TREE_NODE_H

typedef struct metadata {
    int rootPos;
    int order;
} metadata;

metadata* create_metadata(FILE* f, int order);

metadata* load_metadata(FILE* f);

#endif //B_PLUS_TREE_NODE_H
