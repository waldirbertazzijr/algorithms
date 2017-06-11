#include <iostream>
#include <string>
#include "../common.h"
#include "../helpers/vectors.h"


#define ARRAY_SIZE 10

void print(std::string s) {
    std::cout << s << std::endl;
}

void insertion_sort(IntList * arr) {
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
		}

		arr->at(j + 1) = chave;
	}
}

int main()
{
    IntList *array = new IntList(ARRAY_SIZE);

    fill_vector_with_random_data(array);

    // Do the job
    print_vector(array);
    insertion_sort(array);
    print_vector(array);
}
