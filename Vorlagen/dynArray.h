#define DYNARRAY_INITIAL_CAPACITY 100

typedef struct {
    int size;
    int capacity;
    int *data;
} DynArray;

void dynArray_init(DynArray *dynArray);

void dynArray_append(DynArray *dynArray, int value);

int dynArray_get(DynArray *dynArray, int index);

void dynArray_set(DynArray *dynArray, int index, int value);

void dynArray_double_capacity_if_full(DynArray *dynArray);

void dynArray_free(DynArray *dynArray);
