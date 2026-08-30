#ifndef CLASSMODULE_H
#define CLASSMODULE_H
#include <string>
#include <iostream>
using namespace std;

double code(double temp){
    int code_;
    if(temp<0)
        code_=-1;
    else if (temp>=0 && temp <=29)
        code_=0;
    else if (temp>=30 && temp <=44)
        code_=1;
    else if(temp>=45 && temp <=59)
        code_=2;
    else
        code_=3;

    return code_;
}

string label(int code){
    string label_;
    
    switch(code)
    {
        case -1:
            label_="SENSOR_ERROR";
            break;
        case 0:
            label_="NORMAL";
            break;
        case 1:
            label_="WARNING";
            break;
        case 2:
            label_="CRITICAL";
            break;
        case 3:
            label_="SHUTDOWN";
            break;
        default:
            cout << "INVALID CODE";

    }

    return label_;
}

#endif