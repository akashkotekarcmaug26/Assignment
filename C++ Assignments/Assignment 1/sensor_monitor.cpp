#include <iostream>
#include <cstdlib>
#include <string>

using namespace std;

int main(int argc, char* argv[]) {

    // Check for missing arguments
    if (argc < 4){
        cout << "Usage : ./sensor_monitor <warn_threshold> <critical_threshold> <num_readings>" << endl << "Error : Missing arguments.";
        return 1;
    }

    int warn = stoi(argv[1]);
    int critical = stoi(argv[2]);
    int num_readings = stoi(argv[3]);

    if(warn > critical){
        cout << "Error : Warning is greater than Critical !";
        return 1;
    }

        if(num_readings >= 500){
        cout << "Error : Number of Readings cannot exceed 500 !";
        return 1;
    }

    int readings[num_readings];
    for(int i =0 ; i<num_readings; i++)
        readings[i]= rand() % 70;

    int normal=0,warning=0,critical_=0,shutdown=0;

    for(int j=0;j<num_readings;j++)
    {
        if(readings[j]<30)
            normal++;
        else if(readings[j] >=warn && readings[j]<critical)
            warning++;
        else if(readings[j] >= critical && readings[j]<(critical+(critical-warn)))
            critical_++;
        else
            shutdown++;
    }

    cout << "Config : Warn=" << warn << "°C Critical=" << critical << "°C Readings=" << num_readings << endl;

    cout << "Results : Normal:" << normal << " Warning:" << warning << " Critical:" << critical_ << " Shutdown:" << shutdown << endl;
  
    return 0;
}