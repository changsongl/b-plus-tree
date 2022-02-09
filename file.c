//
// Created by Changsong Li on 2022/2/9.
//

#include "file.h"
#include "stdlib.h"
#include "const.h"

file* open_file(char *path, int order) {
    FILE *fptr;
    file *f;

    fptr = fopen(path, "ab+");
    if (fptr == NULL) {
        fprintf(stderr, "Cannot open file: %s\n", path);
        return NULL;
    }

    f = malloc(sizeof(file));
    f->fptr = fptr;

    return f;
}

int insert_num(file *f, int num) {
    size_t s;
    s = fwrite(&num, sizeof(int), 1, f->fptr);
    if (s != 1){
        return CONST_FALSE;
    }

    return CONST_TRUE;
}

int read_num(file *f) {
    int suc;
    int num;
    suc = fseek(f->fptr, sizeof(int)*2, SEEK_SET);
    if (suc != 0) {
        return CONST_FALSE;
    }

    fread(&num, sizeof(int), 1, f->fptr);
    printf("%d\n", num);

    return CONST_TRUE;
}
