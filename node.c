//
// Created by Changsong Li on 2022/2/9.
//

#include "node.h"
#include "const.h"
#include "stdlib.h"

metadata* create_metadata(FILE* f, int order){
    int result;
    size_t size;
    metadata *m;
    size_t metaSize;

    metaSize = sizeof(metadata);
    m = malloc(metaSize);
    m->order = order;
    m->rootPos = (int)metaSize;

    result = fseek(f, 0L, SEEK_SET);
    if (result != CONST_OK) {
        return NULL;
    }

    size = fwrite(m, sizeof(metadata), 1, f);
    if (size != 1) {
        return NULL;
    }

    fflush(f);

    return m;
}

metadata* load_metadata(FILE* f){
    int result;
    size_t size;
    metadata *m;

    result = fseek(f, 0L, SEEK_SET);
    if (result != CONST_OK) {
        return NULL;
    }

    m = malloc(sizeof(metadata));

    size = fread(m, sizeof(metadata), 1, f);
    if (size != 1) {
        return NULL;
    }

    return m;
}


//int insert_num(file *f, void node, int loc) {
//    size_t size;
//    int suc;
//    suc = fseek(f->fptr, loc, SEEK_SET);
//    if (suc != 0) {
//        return CONST_OK;
//    }
//
//    size = fwrite(&node, sizeof(node), 3, f->fptr);
//    if (size != 1){
//        return CONST_OK;
//    }
//
//    return CONST_NOT_OK;
//}
//
//int read_num(file *f) {
//    int suc;
//    int num;
//    suc = fseek(f->fptr, sizeof(int)*2, SEEK_SET);
//    if (suc != 0) {
//        return CONST_OK;
//    }
//
//    fread(&num, sizeof(int), 1, f->fptr);
//    printf("%d\n", num);
//
//    return CONST_NOT_OK;
//}
