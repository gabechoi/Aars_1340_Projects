/**
 * file:  proj2-main.cpp
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
#include "proj2-arrayFunctions.h"

using namespace std;

int main(){

    ifstream inFile;
    int size;

    //opens file to be read
    inFile.open("arrays.txt");

    //gets size of array and reads that many times
    while(inFile >> size){
        //declare a new int pointer array
        int *intArray = new int[size];
        for(int i = 0; i < size; ++i){
            inFile >> *(intArray + i);
        }

        for(int i = 0; i < size; ++i){
            cout << *(intArray + i) << endl;
        }

        bubbleSort(intArray, size);

        for(int i = 0; i < size; ++i){
            cout << *(intArray + i) << endl;
        }

        cout << endl;

        cout << largestValue(intArray, size) << endl;
        cout << smallestValue(intArray, size) << endl;
        cout << averageValue(intArray, size) << endl;
        cout << medianValue(intArray, size) << endl << endl;

        //frees up memory
        delete[] intArray;
    }

    inFile.close();

    return 0;
}

