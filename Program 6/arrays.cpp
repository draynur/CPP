//Author: John Runyard
//Class: IT 226 - 001
//Assignment 04 - C++ Functions & Arrays

#include <iostream>

using namespace std;

//Populates the array with random values and displays the value
int randomArray (int array[], int length){
    
    for (int i=0; i <= length; i++){

        /*This is where the randomoly generated number comes from, I wanted a mode to be possible so I set the value to not be more than 100
        and for the minimum value to be 1. This also prevented the values from rolling over from becoming to large*/
        array[i] = rand() % 101; 
        cout<<"Array ["<<i<<"]: "<<array[i]<<endl;
        
    }
    
}

/*Calculates the mean value for the array. I wanted to return a more exact value so I went with a double*/
double arrayMean (int array[], int length) {
    double mean = 0; int i = 0;
    for (i; i <= length; i++){
        
        mean += array[i];
        
    }
    
    return mean / i;
}

//Calculates the mode of an array
int * arrayMode (int array[], int length){
    int i = 0;int z = 0; int j; int modeCount = 0; int modeIndex; int modeCount1 = 0; int mode[];
    
    for (i; i<=length; i++){
        for(j = i+1; j<=length; j++){
            if (array[i] == array[j]){
                modeCount++;
            }
        }
        if (modeCount > modeCount1){
            modeIndex = i;
            modeCount1 = modeCount;
            mode[z++] = array[i];
        }
    }
    
    if (modeCount1 == 0){
        return 0;
    }
    
    return mode;
}

//Calculates the highest value of an array
int arrrayHigh (int array[], int length){
    int high = 0; int i = 0;
    for (i; i<=length; i++){
        
        if (high < array[i]){
            high = array[i];
        }
        
    }
    
    return high;
}

//Calculates the lowest value of an array
int arrayLow (int array[], int length){
    int low = 100; int i = 0;
    for (i; i<= length; i++){
        
        if (low > array[i]){
            low = array[i];
        }
        
    }
    
    return low;
}

int main()
{
    int size = 0;

    do {

    cout<<"Enter desired size of the array (should be more than 5): ";

    cin>>size;

    if (size <= 5 ) {
        cout<<"Must enter value larger than 5!\n : [ "<<endl;
    }

    cout<<endl;

    } while (size <= 5);
    //instantiate array
    int length = size - 1;
    int array[length];

    //Sets the random seed for the generator by pulling the time from the system clock
    srand(time(0)%100+1);

    //fill and display array
    randomArray(array,length);

    cout<<endl;
    
    cout<<"Highest number: "<<arrrayHigh(array, length)<<endl;

    cout<<"Lowest number: "<<arrayLow(array, length)<<endl;
    
    //I did this in order to be able to print out to decimal places on the average to ensure that the number wasn't too large to dipslayed properly
    cout<<"Average: ";
    printf("%.2f",arrayMean(array,length));
    cout<<endl;
    int mode;

    mode = *arrayMode(array, length);

    if (mode>0){
        cout<<"Mode: "<<mode<<endl;   
    } else {
        cout<<"There is no mode!"<<endl;
    }
    
    cout<<endl;
    
    cout<<"Finished!"<<endl;
    
}
