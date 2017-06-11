#include <iostream>
#include <stdlib.h>
#include <time.h>
#include "arrays.h"

void initialize_array(size_t *arr, size_t size) {
    for (size_t i = 0; i < size; i++) {
        arr[i] = 0;
    };
}

void fill_with_random_data(size_t *arr, size_t size) {
    srand(time(NULL));

    for (size_t i = 0; i < size; i++) {
        arr[i] = (rand()%10)+1;
    };
}
