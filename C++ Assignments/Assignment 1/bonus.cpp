#include <iostream>
using namespace std;

struct Layout1
{
    char c1;
    int i;
    char c2;
};

struct Layout2
{
    int i;
    char c1;
    char c2;
};

int main()
{
    cout << "Size of Layout1 : " << sizeof(Layout1) << endl;
    cout << "Size of Layout2 : " << sizeof(Layout2) << endl;

    /*
    Layout1 and Layout2 have the same members but the members are arranged in a different order that is different padding is applied thus different sizes

    Padding is an extra memory added by compiler between members so that the data is properly aligned

    In Layout1, the char comes before the int so extra padding is needed before the int

    In Layout2, the int comes first, so less padding is needed. member order matters when defining network packet headers or hardware register maps because padding can change the actual memory layout
    */

    return 0;
}