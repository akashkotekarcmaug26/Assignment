#include <iostream>
#include <cmath>
using namespace std;


// Returns sqrt( sum of (each element squared) / n )
double computeRMS(double* signal, int n){
    double sum=0;
    double avg;
    for(int i =0; i < n ; i++)
        sum+=(*(signal+i)*(*(signal+i)));
    avg=sum/n;
    avg=sqrt(avg);

    return avg;
    
}

// Divides every element by the max absolute value in the array (in-place)
void normalise(double* signal, int n){
    double max=0;

    for(int i =0;i< n;i++){
        if(max < abs(*(signal+i)))
            max = abs(*(signal+i));
    }
    
    
     for(int i =0;i< n;i++){
        (*(signal+i))=(*(signal+i))/max;
    }

}

// Returns count of positions where adjacent elements have opposite signs
int countZeroCrossings(double* signal, int n){
    int count =0;
    for(int i=0;i<n-1;i++){
        if(*(signal+i)==0 && *(signal+i+1)==0)
            continue;
        if(*(signal+i) >=0 && *(signal+i+1)<=0)
            count++;
        if(*(signal+i) <= 0 && *(signal+i+1)>=0)
            count++;

    }
    return count;
}

// Multiplies every element by gainFactor (in-place)
void applyGain(double* signal, int n, double gainFactor){
         for(int i =0;i< n;i++){
        (*(signal+i))=(*(signal+i))*gainFactor;
    }

}


void displayArray(double* signal,int n){

    for(int i =0; i<n ; i++){
        cout << *(signal+i) << "  ";
    }
    cout << endl;
}
int main(){

    int n;
    cout << "Enter Number of Raw Signals : " << endl;
    cin >> n;
    double signals [n];
    cout << "Enter Raw signals" << endl;
    for(int j=0;j<n;j++)
        cin >> signals[j];
    double gain;
    cout << "Enter Gain Factor : " << endl;
    cin >> gain ;

    cout <<" Array of signal :" << endl ;
    displayArray(signals,n);


    double rms= computeRMS(signals,n);
    cout << "RMS of Signals : " << rms << endl;
    cout << endl;

    cout << "Before Normalise : " << endl;
    displayArray(signals,n);
    normalise(signals,n);
    cout << "After Normalise : " << endl;
    displayArray(signals,n);
    cout << endl;

    cout << countZeroCrossings(signals,n) << endl;
    cout << endl;

    cout << "Before Gain : " << endl;
    displayArray(signals,n);
    applyGain(signals,n,gain);
    cout << "After Gain : " << endl;
    displayArray(signals,n);
    cout << endl;


    return 0;

}














