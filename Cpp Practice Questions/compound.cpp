#include <iostream>
#include <math.h>

int main(){

    int p,r,t;

    std :: cout << "Enter Princple, Time and Rate";
    std :: cin >> p >> r >> t;

    double interest = p*pow((1+r/100.0),t) - p;

    std :: cout <<"Compound Interest is " << interest;

    return 0;

}

