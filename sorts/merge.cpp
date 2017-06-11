#include <iostream>
#include <string>
#include <math.h>
#include "../common.h"
#include "../helpers/vectors.h"
#include "../helpers/print.h"

#define ARRAY_SIZE 10
#define SENTINEL_ELEMENT 100000

void merge(IntList * arr, IntList::size_type p, IntList::size_type q, IntList::size_type r){
    int n1 = q - p + 1; // part 1 size
    int n2 = r - q; // part 2 size

    IntList L(n1);
    IntList R(n2);

    // with sentinel element...
    int i, j;
    for (i = 0; i < n1; i++) {
        L[i] = (arr->at(p + i));
    }
    for (j = 0; j < n2; j++) {
        R[j] = (arr->at(q + j + 1));
    }

    // add sentinel
    L.push_back(SENTINEL_ELEMENT);
    R.push_back(SENTINEL_ELEMENT);

    print("Merging:");
    print(&L);
    print(&R);

    i = j = 0;

    // merging...
    for (int k = p; k <= r; k++) {
        if (L[i] <= R[j]) {
            arr->at(k) = L[i];
            i++;
        } else {
            arr->at(k) = R[j];
            j++;
        }
    }
}

void sort(IntList * arr, int p, int r) {
    if (p < r) {
        int q = floor((p+r)/2);
        sort(arr, p, q);
        sort(arr, q+1, r);
        merge(arr, p, q, r);
    }
}

int main()
{
    IntList *array = new IntList(ARRAY_SIZE);

    fill_vector_with_random_data(array);

    // Do the job
    print(array);
    sort(array, 0, array->size()-1);
    print(array);
}
