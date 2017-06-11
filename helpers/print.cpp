#include <iostream>
#include <string>
#include "print.h"
#include "../common.h"

void print(IntList *arr) {
    std::cout << "[";
    for(IntList::size_type i=0; i < arr->size(); i++){
        std::cout << arr->at(i) << ' ';
    }
    std::cout << "]" << '\n';
}

void print(size_t *arr, size_t size) {
    std::cout << "[";
    for (size_t i = 0; i < size; i++) {
        std::cout << std::to_string(arr[i]) << " ";
    };
    std::cout << "]" << '\n';
}

void print(std::string s) {
    std::cout << s << std::endl;
}
void print(int s) {
    std::cout << std::to_string(s) << std::endl;
}
