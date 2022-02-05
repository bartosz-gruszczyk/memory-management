#include "myuniqueptr.hpp"
#include <iostream>

int main() {

    // int a = 32;
    MyUniquePtr<int> myptr1{new int(3)};

    std::cout << "myptr1 = " << *myptr1 << '\n';

    MyUniquePtr<int> myptr3(new int{3});
    // myptr3 = new int{4};
    // myptr3 = myptr1;
    if (myptr3) {
        std::cout << "myptr3 is not nullptr\n";
    } else {
        std::cout << "myptr3 is nullptr\n";
    }
    MyUniquePtr<int> myptr2(std::move(myptr1));
    // std::cout << std::boolalpha << "myptr1 ? " << myptr1 << '\n';
    std::cout << "myptr2 = " << *myptr2 << '\n';
    MyUniquePtr<int> myptr4;
    myptr4 = std::move(myptr2);
    // std::cout << "myptr2 = " << *myptr2 << '\n';
    std::cout << "mypt4 = " << *myptr4 << '\n';
    myptr4 = new int{98};
    std::cout << "mypt4 = " << *myptr4 << '\n';
    std::cout << "mypt4 = " << myptr4 << '\n';
    std::cout << "mypt4-> = " << myptr4 << '\n';

    const MyUniquePtr<int> myptr5(new int{55});
    const int cx = *myptr5;
    // ++cx;
    int x = *myptr5;
    ++x;
    // const int* constPtr = myptr5
    // const int* const b = myptr4.get();

    //const T*

    


    class Foo{
    public:
        int x = 90;

    };

    MyUniquePtr<Foo> fooPtr(new Foo());
    std::cout << " foo " << fooPtr->x << '\n';
    MyUniquePtr<Foo> fooPtr2(std::move(fooPtr));

    const MyUniquePtr<Foo> myptr6(new Foo());
    std::cout  << "myptr6: " << myptr6->x << '\n';
    // myptr6->x = 23;
    std::cout  << "myptr6: " << myptr6->x << '\n';
    int i6 = myptr6->x;
    Foo* cfoo6 = myptr6.get();
    cfoo6->x = 23;
    std::cout  << "myptr6: " << myptr6->x << '\n';

    return 0;
}