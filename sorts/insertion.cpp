#include <iostream>
#include <string>

#include "../helpers/arrays.h"

#define MAXSIZE 100

void print(std::string s) {
    std::cout << s << std::endl;
}

int main()
{
    size_t* array = new size_t[MAXSIZE];

    fill_with_random_data(array, MAXSIZE);
    print_array(array, MAXSIZE);
}
