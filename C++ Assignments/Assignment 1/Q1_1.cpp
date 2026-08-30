#include <iostream>
#include "classmodule.h"
using namespace std;

int main(){
    
    cout << "Enter Temperature: " << endl ;
    double temp;
    int c;
    bool avg;
    string l,action;
    cin >> temp;

    c=code(temp);
    l=label(c);

    avg = (temp>=25)?true:false;

        switch(c)
    {
        case -1:
            action="Sensor Fault - check wiring";
            break;
        case 0:
            action="No action required";
            break;
        case 1:
            action="Alert sent to supervisor";
            break;
        case 2:
            action="Cooling system triggered";
            break;
        case 3:
            action="Emergency shutdown initiated";
            break;
        default:
            cout << "INVALID CODE";

    }


    cout << "Temperature :  "<< temp << "°C / " << ((temp*(9.0/5.0))+32) << "°F" << endl ;
    cout << "Status      : " << l << endl ;
    cout << "Action      : " << action << endl;
    cout << "Reading     : " << ((avg)?"Above Average":"Below Average")<< endl;

}