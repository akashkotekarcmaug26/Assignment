#include <iostream>
#include "classmodule.h"
using namespace std;

int main(){
    int read_num;

    cout << "Enter Number of Readings : ";
    cin >> read_num;
    

    double readings [read_num];
    int first=0;
    
    for(int i=0; i<read_num ; i++){
        cin >> readings[i];
    }
    cout << "Readings entered         : " << read_num <<endl;
    cout << "Valid readings           : ";

    int count=0;
    for(int u=0;u<read_num;u++){
        if(readings[u]<0){
            count++;
            continue;
        }
        cout << readings[u] << "  ";
    }
    cout << endl;
    cout << "Skipped (errors) : " << count << endl;

    for(int k =0;k<=read_num;k++)
    {
         if(readings[k]>=45){
            first=k;
            break;
         }
    }

    cout << "First CRITICAL           : Index " << first+1 << "-> " << readings[first] << "°C" <<endl;
    
    double min = 0, max = 0, avg = 0,sum =0;
    
    for(int j=0; j<read_num;j++)
    {
        if(readings[j] < 0)
            continue;
        if(readings[j] < min )
            min = readings[j];
        
        if(readings[j]>max)
            max= readings[j];
        
        sum+=readings[j];
        avg++;
    }
    avg=sum/avg;

    cout << "Min : " << min << "°C" << "    Max : " << max << "°C" << "     Avg : " << avg << "°C" << endl;


    int normal=0,warning=0,critical=0,shut=0,c=0;
    string l;
    for(int h=0;h<read_num; h++)
    {
        c=code(readings[h]);
        l=label(c);

        if(l == "NORMAL")
            normal++;
        else if(l == "WARNING")
            warning++;
        else if(l == "CRITICAL")
            critical++;
        else if(l == "SHUTDOWN")
            shut++;
    }
    cout << "Normal : " << normal << "   Warning : " << "   Critical : " << critical << "   Shutdown : " << shut << endl;


}