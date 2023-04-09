#include <stdio.h>
#include <malloc.h>

typedef struct vector {
    int *data;
    size_t size;
    size_t capacity;
} vector;

vector create_vector(size_t n) {
    vector v;
    v.capacity = n;
    v.data = (int*) malloc(n * sizeof(int));

    if (v.data == NULL) {
        fprintf(stderr, "bad alloc");
        exit(1);
    }

    return v;
}

void reserve_vector(vector *v, size_t new_capacity) {
    v->capacity = new_capacity;
    realloc(v->data, new_capacity * sizeof(int));

    if (v->data == NULL) {
        fprintf(stderr, "bad alloc");
        exit(1);
    }

    if (new_capacity < v->size) {
        v->size = new_capacity;
    }
}

void clear(vector *v) {
    v->size = 0;
}

void shrink_to_fit(vector *v) {
    v->capacity = v->size;
}

void delete_vector(vector *v) {
    free(v->data);
}