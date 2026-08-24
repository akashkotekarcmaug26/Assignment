#include <iostream>

int main()
{
    int p,r,t;

    std :: cout << "Enter Princple, Time and Rate";
    std :: cin >> p >> r >> t;
    
    int interest = (p*r*t)/100;

    std :: cout << "Simple Interest :" << interest ;
    
    return 0;
}