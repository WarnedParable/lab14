#include <stdint.h>
#include "vector/vector.h"

bool are_arrays_equal(int *a, size_t size_a, int *b, size_t size_b) {
    if (size_a != size_b) {
        return false;
    }

    for (size_t i = 0; i < size_a; i++) {
        if (a[i] != b[i]) {
            return false;
        }
    }

    return true;
}

void check(bool val, char *test_name) {
    if (val) {
        printf("%s - OK\n", test_name);
    }
    else {
        fprintf(stderr, "%s - ERROR\n", test_name);
    }
}

void test_push_back_empty_vector() {
    vector v = create_vector(5);
    push_back(&v, 1);

    int target[] = {1};

    check(are_arrays_equal(v.data, v.size, target, 1), __func__);
}

void test_push_back_full_vector() {
    vector v = create_vector(1);
    push_back(&v, 1);

    push_back(&v, 12);

    int target[] = {1, 12};

    check(are_arrays_equal(v.data, v.size, target, 2), __func__);
}

void test_pop_back__not_empty_vector() {
    vector v = create_vector(1);
    push_back(&v, 10);

    int target[] = {};

    pop_back(&v);

    check(are_arrays_equal(v.data, v.size, target, 0), __func__);
}

void test_at_vector_not_empty_vector() {
    vector v = create_vector(4);
    push_back(&v, 1);
    push_back(&v, 2);
    push_back(&v, 3);
    push_back(&v, 4);

    int *i = at_vector(&v, 2);

    check(*i == 3, __func__);
}

void test_at_vector_request_to_last_element() {
    vector v = create_vector(4);
    push_back(&v, 1);
    push_back(&v, 2);
    push_back(&v, 3);
    push_back(&v, 4);

    int *i = at_vector(&v, 3);

    check(*i == 4, __func__);
}

void test_back_one_element_in_vector() {
    vector v = create_vector(1);
    push_back(&v, 1);

    int *i = back(&v);

    check(*i == 1, __func__);
}

void test_front_one_element_in_vector() {
    vector v = create_vector(1);
    push_back(&v, 1);

    int *i = front(&v);

    check(*i == 1, __func__);
}

void test() {
    test_push_back_empty_vector();
    test_push_back_full_vector();
    test_pop_back__not_empty_vector();
    test_at_vector_not_empty_vector();
    test_at_vector_request_to_last_element();
    test_back_one_element_in_vector();
    test_front_one_element_in_vector();
}


int main() {
    test();

    return 0;
}