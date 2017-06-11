#include <iostream>
#include <string>
#include <time.h>
#include "vectors.h"

void fill_vector_with_random_data(IntList *arr) {
    srand(time(NULL));

    for(IntList::size_type i=0; i < arr->size(); i++){
        arr->at(i) = (rand()%10)+1;
    }
}
