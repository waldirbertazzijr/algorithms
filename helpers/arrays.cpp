#include <iostream>
#include "arrays.h"

void print_array(size_t *arr, size_t size) {
    std::cout << "[";
    for (size_t i = 0; i < size; i++) {
        std::cout << std::to_string(arr[i]) << " ";
    };
    std::cout << "]" << '\n';
}

void initialize_array(size_t *arr, size_t size) {
    for (size_t i = 0; i < size; i++) {
        arr[i] = 0;
    };
}

void fill_with_random_data(size_t *arr, size_t size) {
    for (size_t i = 0; i < size; i++) {
        arr[i] = (rand()%10)+1;
    };
}
