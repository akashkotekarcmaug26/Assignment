#include <iostream>

int main(){
    int a =5;
    int b=10;
    std :: cout << "a = " << a << " b = " << b;
    int c=a;

    a=b;
    b=c;

    std :: cout << " \na = " << a << " b = " << b;
    

    return 0;
}