//
// Created by Changsong Li on 2022/2/9.
//

#include "stdio.h"

#ifndef B_PLUS_TREE_NODE_H
#define B_PLUS_TREE_NODE_H

#define NODE_LOCATION_END -1

typedef struct Metadata {
    int rootPos;
    int order;
    int size;
} Metadata;

Metadata* create_metadata(FILE* f, int order);

Metadata* load_metadata(FILE* f);

typedef struct Node {
    int len;
    int8_t leaf;
    int *nums;
    int *locations;
} Node;

typedef struct NodeManager {
    int nodeLoc;
    int order;
    Node *node;
} NodeManager;

NodeManager* create_node_manager(int nodeLoc, int order);

Node* create_node(int order);

int write_node(NodeManager* node, FILE* f);

int load_node(NodeManager* node, FILE* f);

int is_leaf(NodeManager *n);

#endif //B_PLUS_TREE_NODE_H
