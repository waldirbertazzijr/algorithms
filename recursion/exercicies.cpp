#include <iostream>
#include "../common.h"
#include "../helpers/print.h"

int sum(int n) {

    if (n != 0) {
        return n + sum(n-1);
    }

    return 0;
}

int findmin(int n) {

    if (n != 0) {
        return n + sum(n-1);
    }

    return 0;
}




int main()
{
    print(sum(3));
    return 0;
}
