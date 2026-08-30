#include <iostream>
#include <iomanip>
#include "classmodule.h"

using namespace std;

int main(){
    double temps[3][3];

    cout << "Enter Temps for the Rooms";

    for(int i=0;i<3;i++){
        for(int j=0;j<3;j++){
            cin >> temps[i][j];
        }
    }

        cout << setw(20) << "Room1" << setw(10) << "Room2" << setw(10) << "Room3" << endl;
        for(int i=0;i<3;i++){
            cout << "Floor " << i+1 << " : ";
        for(int j=0;j<3;j++){
            cout << setw(10) << temps[i][j] << "  ";
        }
        cout << endl;
    }

    int hot_floor,hot_room;
    double hottest=0.0;

    for(int j=0;j<3;j++){
        for(int h=0;h<3;h++){
            if(temps[j][h]>hottest)
            {
                hottest = temps[j][h];
                hot_floor = j;
                hot_room = h;
            }
        }
    }

    cout << "Hottest Room  : " << "Floor " << hot_floor+1 << ", Room " << hot_room+1 << "-> " << temps[hot_floor][hot_room] << "°C"<< endl ;

    double hot_avg=0;
    double sum=0;
    int flr;

     for(int j=0;j<3;j++){
        for(int h=0;h<3;h++){
           sum+=temps[j][h];
        }
        if((sum/3)>hot_avg){
            hot_avg=(sum/3);
            flr=j;
        }

            sum=0;
    }

    cout << "Hottest Floor :" << "Floor " << flr+1 << "  (avg " << hot_avg << "°C)" << endl;

    int warn=0;

    for(int k=0;k<3;k++){
        for(int g=0;g<3;g++){
            if(code(temps[k][g])>0)
                warn++;
        }

    }

    cout << "Rooms at WARNING or above : " << warn << endl;
}