#include "myuniqueptr.hpp"
#include <iostream>

int main() {

    int a = 32;
    MyUniquePtr<int> myptr1(new int(3));

    std::cout << "myptr1 = " << *myptr1 << '\n';
    // std::cout << "myptr1 = " << *myptr1 << '\n';


    return 0;
}