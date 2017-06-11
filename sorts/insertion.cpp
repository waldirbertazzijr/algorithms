    #include <iostream>
#include <string>

#include "../helpers/arrays.h"

#define ARRAY_SIZE 10

void print(std::string s) {
    std::cout << s << std::endl;
}

void insertion_sort(size_t * arr) {
    int i, j;
    size_t chave;

    for (i = 1; i < ARRAY_SIZE; i++) {
        // Primeiro elemento deve
        // estar no lugar certo.
		chave = arr[i];
        // j indica o ultimo indice que já foi
        // arranjado.
		j = i - 1;

        // enquanto j nao for -1 e
        // o elemento anterior e maior
        // que o elemento chave (a ser arrumado)
		while ((j >= 0) && (arr[j] < chave)) {
			arr[j + 1] = arr[j];
			j--;
		}

		arr[j + 1] = chave;
	}
}

int main()
{
    size_t* array = new size_t[ARRAY_SIZE];

    fill_with_random_data(array, ARRAY_SIZE);

    // Do the job
    print_array(array, ARRAY_SIZE);
    insertion_sort(array);
    print_array(array, ARRAY_SIZE);
}
