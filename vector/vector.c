#include <stdio.h>
#include <malloc.h>
#include <stdbool.h>

typedef struct vector {
    int *data;
    size_t size;
    size_t capacity;
} vector;

vector create_vector(size_t capacity) {
    vector v;
    v.capacity = capacity;
    v.data = (int*) malloc(capacity * sizeof(int));
    v.size = 0;

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

bool is_empty(vector *v) {
    return !v->size;
}

bool is_full(vector *v) {
    return v->size == v->capacity;
}

int get_vector_value(vector *v, size_t i) {
    return v->data[i];
}

void push_back(vector *v, int val) {
    if (is_full(v)) {
        reserve_vector(v, v->capacity * 2);
    }

    v->data[v->size++] = val;
}

void pop_back(vector *v) {
    if (v->size == 0) {
        fprintf(stderr, "pop empty vector");
        exit(1);
    }

    v->size--;
}

int *at_vector(vector *v, size_t index) {
    if (v->size < index) {
        fprintf(stderr, "IndexError: a[%d] is not exists", index);
        exit(1);
    }

    return v->data + index;
}

int *back(vector *v) {
    return v->data + v->size - 1;
}

int *front(vector *v) {
    return v->data;
}
