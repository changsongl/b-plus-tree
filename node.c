//
// Created by Changsong Li on 2022/2/9.
//

#include "node.h"
#include "const.h"
#include "stdlib.h"

#define NODE_LEAF 0
#define NODE_NOT_LEAF 1

Metadata* create_metadata(FILE* f, int order){
    int result;
    size_t size;
    Metadata *m;
    size_t metaSize;

    metaSize = sizeof(Metadata);
    m = malloc(metaSize);
    m->order = order;
    m->rootPos = (int)metaSize;

    result = fseek(f, 0L, SEEK_SET);
    if (result != CONST_OK) {
        return NULL;
    }

    size = fwrite(m, sizeof(Metadata), 1, f);
    if (size != 1) {
        return NULL;
    }

    fflush(f);

    return m;
}

Metadata* load_metadata(FILE* f){
    int result;
    size_t size;
    Metadata *m;

    result = fseek(f, 0L, SEEK_SET);
    if (result != CONST_OK) {
        return NULL;
    }

    m = malloc(sizeof(Metadata));

    size = fread(m, sizeof(Metadata), 1, f);
    if (size != 1) {
        return NULL;
    }

    return m;
}

NodeManager* create_node_manager(int nodeLoc, int order) {
    NodeManager *nodeManager;

    nodeManager = malloc(sizeof(NodeManager));
    if (nodeManager == NULL) {
        return NULL;
    }

    nodeManager->nodeLoc = nodeLoc;
    nodeManager->order = order;

    nodeManager->node = create_node(order);
    if (nodeManager->node == NULL) {
        return NULL;
    }

    return nodeManager;
}

Node* create_node(int order) {
    Node *node;
    int *locations, *nums;

    node = malloc(sizeof(Node));
    if (node == NULL) {
        return NULL;
    }

    locations = malloc(sizeof(int) * (order+1));
    if (locations == NULL) {
        return NULL;
    }

    nums = malloc(sizeof(int) * order);
    if (nums == NULL) {
        return NULL;
    }

    node->locations = locations;
    node->nums = nums;

    return node;
}

int write_node(NodeManager* node, FILE* f) {
    int result;
    size_t size;

    result = fseek(f, (long)node->nodeLoc, SEEK_SET);
    if (result != 0) {
        return CONST_NOT_OK;
    }

    size = fwrite(&node->node->len, sizeof(int), 1, f);
    if (size != 1) {
        return CONST_NOT_OK;
    }

    size = fwrite(&node->node->leaf, sizeof(int8_t), 1, f);
    if (size != 1) {
        return CONST_NOT_OK;
    }

    size = fwrite(node->node->nums, sizeof(int), node->order, f);
    if (size != node->order) {
        return CONST_NOT_OK;
    }

    size = fwrite(node->node->locations, sizeof(int), node->order+1, f);
    if (size != node->order+1) {
        return CONST_NOT_OK;
    }

    result = fflush(f);
    if (result != CONST_OK) {
        return CONST_NOT_OK;
    }

    return CONST_OK;
}

int load_node(NodeManager* node, FILE* f) {
    int result;
    size_t size;

    result = fseek(f, (long)node->nodeLoc, SEEK_SET);
    if (result != 0) {
        return CONST_NOT_OK;
    }

    size = fread(&node->node->len, sizeof(int), 1, f);
    if (size != 1) {
        return CONST_NOT_OK;
    }

    size = fread(&node->node->leaf, sizeof(int8_t), 1, f);
    if (size != 1) {
        return CONST_NOT_OK;
    }

    size = fread(node->node->nums, sizeof(int), node->order, f);
    if (size != node->order) {
        return CONST_NOT_OK;
    }

    size = fread(node->node->locations, sizeof(int), node->order+1, f);
    if (size != node->order+1) {
        return CONST_NOT_OK;
    }

    return CONST_OK;
}
