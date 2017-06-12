#include <iostream>
#include <string>
#include <stdio.h>
#include <math.h>
#include "../common.h"
#include "../helpers/vectors.h"
#include "../helpers/print.h"

#define ARRAY_SIZE 100
#define SENTINEL_ELEMENT 100000

void merge(IntList * arr, IntList::size_type p, IntList::size_type q, IntList::size_type r, int * iter){
    int n1 = q - p + 1; // part 1 size
    int n2 = r - q; // part 2 size

    IntList L(n1);
    IntList R(n2);

    printf("merge\tmethod(arr, p:%lu, q:%lu, r:%lu)\n", p, q, r);

    // with sentinel element...
    int i, j;
    for (i = 0; i < n1; i++) {
        L[i] = (arr->at(p + i));
    }
    for (j = 0; j < n2; j++) {
        R[j] = (arr->at(q + j + 1));
    }

    print("Merging:");
    print(&L);
    print(&R);

    // add sentinel
    L.push_back(SENTINEL_ELEMENT);
    R.push_back(SENTINEL_ELEMENT);

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

        *iter = *iter + 1;
    }
}

void sort(IntList * arr, int p, int r, int * iter) {
    int q = floor((p+r)/2);
    printf("sort\tmethod(arr, %u, %u), with q = %u\n", p, r, q);
    if (p < r) {
        sort(arr, p, q, iter);
        sort(arr, q+1, r, iter);
        merge(arr, p, q, r, iter);
    }
}

int main()
{
    int iter = 0;

    IntList *array = new IntList(ARRAY_SIZE);

    fill_vector_with_random_data(array);

    // Do the job
    print(array);
    sort(array, 0, array->size()-1, &iter);
    print(array);

    printf("Finishes using %u iterations.\n", iter);
}
