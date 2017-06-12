#include <iostream>
#include <string>
#include "../common.h"
#include "../helpers/vectors.h"
#include "../helpers/print.h"


#define ARRAY_SIZE 100

void sort(IntList * arr, int * iter) {
    int i, j;
    size_t chave;

    for(IntList::size_type i=1; i < arr->size(); ++i){
        // Primeiro elemento deve
        // estar no lugar certo.
		chave = arr->at(i);
        // j indica o ultimo indice que já foi
        // arranjado.
		j = i - 1;

        // enquanto j nao for -1 e
        // o elemento anterior e maior
        // que o elemento chave (a ser arrumado)
		while ((j >= 0) && (arr->at(j) > chave)) {
			arr->at(j + 1) = arr->at(j);
			j--;

            *iter = *iter + 1;
		}

		arr->at(j + 1) = chave;
	}
}

int main()
{
    int iter = 0;

    IntList *array = new IntList(ARRAY_SIZE);

    fill_vector_with_random_data(array);

    // Do the job
    print(array);
    sort(array, &iter);
    print(array);

    printf("Finishes using %u iterations.\n", iter);
}
