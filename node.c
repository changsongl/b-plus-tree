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
