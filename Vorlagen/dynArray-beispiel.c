#include <stdio.h>
#include "dynArray.c"

int main() {
    // declare & init new dynArray
    DynArray dynArray;
    dynArray_init(&dynArray);

    // fill it up with 150 arbitrary values
    // this should expand capacity up to 200
    int i;
    for(i = 200; i > -50; i--) {
        dynArray_append(&dynArray, i);
    }

    // set a value at an arbitrary index
    // this will expand and zero-fill the dynArray to fit
    dynArray_set(&dynArray, 4452, 21312984);

    // print out an arbitrary value in the dynArray
    printf("Heres the value at 27: %d\n", dynArray_get(&dynArray, 27));

    // we're all done playing with our dynArray,
    // so free its underlying data array
    dynArray_free(&dynArray);
}
