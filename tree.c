//
// Created by Changsong Li on 2022/2/9.
//

#include "tree.h"
#include "stdlib.h"
#include "const.h"
#include "node.h"

int init_tree(Tree *t) {
    // check file is empty
    long fileSize;
    Metadata *m;
    NodeManager *manager;
    int result = CONST_OK;

    fseek(t->fptr, 0L, SEEK_END);
    fileSize = ftell(t->fptr);

    if (fileSize == 0) {
        m = create_metadata(t->fptr, t->order);
    }else {
        m = load_metadata(t->fptr);
    }

    if (m == NULL) {
        return CONST_NOT_OK;
    }

    t->m = m;

    if (t->order != m->order) {
        printf("warning: the order of Tree is %d, instead of %d\n", m->order, t->order);
    }
    t->order = m->order;

    manager = create_node_manager(m->rootPos, t->order);
    if (manager == NULL) {
        return CONST_NOT_OK;
    }

    if (fileSize == 0) {
        result = write_node(manager, t->fptr);
    }


    return result;
}

Tree* create_tree(char *path, int order) {
    FILE *fptr;
    Tree *t;
    int result;

    fptr = fopen(path, "ab+");
    if (fptr == NULL) {
        fprintf(stderr, "Cannot open file: %s\n", path);
        return NULL;
    }

    t = malloc(sizeof(Tree));
    t->fptr = fptr;
    t->order = order;

    result = init_tree(t);
    if (result != CONST_OK) {
        fprintf(stderr, "Cannot init Tree: %s. (%d)\n", path, result);
        return NULL;
    }

    return t;
}
