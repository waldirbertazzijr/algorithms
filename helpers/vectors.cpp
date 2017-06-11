#include <iostream>
#include <string>
#include <stdlib.h>
#include <time.h>
#include "../common.h"
#include "vectors.h"

void print_vector(IntList *arr) {
    std::cout << "[";
    for(IntList::size_type i=0; i < arr->size(); i++){
        std::cout << arr->at(i) << ' ';
    }
    std::cout << "]" << '\n';
}

void fill_vector_with_random_data(IntList *arr) {
    srand(time(NULL));

    for(IntList::size_type i=0; i < arr->size(); i++){
        arr->at(i) = (rand()%10)+1;
    }
}
