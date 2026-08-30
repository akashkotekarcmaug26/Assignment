#include <iostream>
using namespace std;

int main()
{
    int statusReg= 0b10110001;
    int controlReg =0b00000000;
    int dataReg = 0b11001010;

    const int* regPtr1 = &statusReg;
    cout << "Status Register : " << *regPtr1 << endl;
    // *regPtr1 = 10;
    // Cannot modify value through a pointer to const
    // regPtr1 = &dataReg;
    // Allowed because pointer itself is not a const


    int *const regPtr2 = &controlReg;
    *regPtr2 = 25;
    cout << "Control Register : " << *regPtr2 << endl;
    // regPtr2 = &dataReg;
    // regPtr2 is constant pointer so it cannot point somewhere else



    const int* const regPtr3 = &statusReg;
    cout << "Status Register : " << *regPtr3 << endl;
    // *regPtr3 = 50;
    // Cannot modify value
    // regPtr3 = &dataReg;
    // Cannot change where pointer points

    return 0;
}