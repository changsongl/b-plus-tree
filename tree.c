//
// Created by Changsong Li on 2022/2/9.
//

#include "tree.h"
#include "stdlib.h"
#include "const.h"
#include "node.h"

int init_tree(tree *t) {
    // check file is empty
    long size;
    int result = CONST_OK;
    metadata *m;

    fseek(t->fptr, 0L, SEEK_END);
    size = ftell(t->fptr);
    if (size == 0) {
        m = create_metadata(t->fptr, t->order);
    }else {
        m = load_metadata(t->fptr);
    }

    if (m == NULL) {
        return CONST_NOT_OK;
    }

    t->m = m;

    if (t->order != m->order) {
        printf("warning: the order of tree is %d, instead of %d\n", m->order, t->order);
    }
    t->order = m->order;


    return CONST_OK;
}

tree* create_tree(char *path, int order) {
    FILE *fptr;
    tree *t;
    int result;

    fptr = fopen(path, "ab+");
    if (fptr == NULL) {
        fprintf(stderr, "Cannot open file: %s\n", path);
        return NULL;
    }

    t = malloc(sizeof(tree));
    t->fptr = fptr;
    t->order = order;

//    m = malloc(sizeof(metadata));

    result = init_tree(t);
    if (result != CONST_OK) {
        fprintf(stderr, "Cannot init tree: %s. (%d)\n", path, result);
        return NULL;
    }

    return t;
}
