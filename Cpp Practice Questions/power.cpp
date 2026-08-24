#include <iostream>
#include <math.h>
int main(){
    int num,p;

    std :: cout << "Enter Numbe rand power";
    std :: cin >> num >> p ;

    double total = pow(num,p);

    std :: cout <<"Power of " << num << " to " << p << "is :" << total;

    return 0;

}