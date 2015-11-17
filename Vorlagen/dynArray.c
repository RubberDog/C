#include <stdio.h>
#include <stdlib.h>
#include "dynArray.h"

void dynArray_init(DynArray *dynArray) {
    // init size & cap
    dynArray->size = 0;
    dynArray->capacity = DYNARRAY_INITIAL_CAPACITY;

    // allocate memory for dynArray->data
    dynArray->data = malloc(sizeof(int) * dynArray->capacity);
}

void dynArray_append(DynArray *dynArray, int value) {
    // make sure there's room to expand into
    dynArray_double_capacity_if_full(dynArray);

    // append the value and increment dynArray->size
    dynArray->data[dynArray->size++] = value;
}

int dynArray_get(DynArray *dynArray, int index) {
    if(index >= dynArray->size || index < 0) {
        printf("Inndex %d out of bounds for dynArray of size %d\n", index, dynArray->size);
        exit(1);
    }
    return dynArray->data[index];
}

void dynArray_set(DynArray *dynArray, int index, int value) {
    // zero fill the array up to the desired index
    while (index >= dynArray->size) {
        dynArray_append(dynArray, 0);
    }

    // set the value at the desired index
    dynArray->data[index] = value;
}

void dynArray_double_capacity_if_full(DynArray *dynArray) {
    if(dynArray->size >= dynArray->capacity) {
        // double dynArray->capacity and resize the allocated memory accordingly
        dynArray->capacity *= 2;
        dynArray->data = realloc(dynArray->data, sizeof(int) * dynArray->capacity);
    }
}

void dynArray_free(DynArray *dynArray) {
    free(dynArray->data);
}
