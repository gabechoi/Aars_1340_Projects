/**
 * file:  proj2-testmain.cpp
 * author:  Gabriel Choi
 * course: CSI 1440
 * assignment:  project 2
 * due date:  9/04/2022
 *
 * date modified: 9/01/2022
 *      - file created
 *
 * date modified: 9/04/2022
 *      - most code written
 *      - comments created
 *
 *
 */

#include <iostream>
#include <fstream>
#include <sstream>
#include "proj2-arrayFunctions.h"

using namespace std;

int main(){

    istringstream inSS;
    int size;

    //inSS will act as a file
    inSS.clear();
    inSS.str("5\n8 2 19 26 5\n8\n76 52 51 68 90 78 2 15\n3\n70 70 70");

    //gets size of array and reads that many times
    while(inSS >> size){
        //declare a new int pointer array
        int *intArray = new int[size];
        for(int i = 0; i < size; ++i){
            inSS >> *(intArray + i);
        }

        cout << "Array before: " << endl;
        for(int i = 0; i < size; ++i){
            cout << *(intArray + i) << endl;
        }

        bubbleSort(intArray, size);

        cout << "Array After: " << endl;
        for(int i = 0; i < size; ++i){
            cout << *(intArray + i) << endl;
        }

        cout << endl;

        cout << "Testing largestValue: " << endl;
        cout << largestValue(intArray, size) << endl;
        cout << "Testing smallestValue: " << endl;
        cout << smallestValue(intArray, size) << endl;
        cout << "Testing averageValue: " << endl;
        cout << averageValue(intArray, size) << endl;
        cout << "Testing medianValue: " << endl;
        cout << medianValue(intArray, size) << endl << endl;

        //frees up memory
        delete[] intArray;
    }

    return 0;
}
