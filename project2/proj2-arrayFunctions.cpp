/**
 * file:  proj2-arrayFunctions.cpp
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

#include "proj2-arrayFunctions.h"

/**
 * bubbleSort
 *
 * This function sorts an array of int pointers with bubble
 * sort in ascending order
 *
 * Parameters:
 *      array:  an int pointer array
 *      size: the size of the array
 *
 * Output:
 *      return:  none
 *      reference parameters: none
 *      stream:  none
 */
void bubbleSort(int *array, int size){
    //temp variable for bubble sort
    int temp;
    for(int i = 0; i < size - 1; ++i){
        for(int j = 0; j < size - i - 1; ++j){
            if(*(array + j) > *(array+j+1)){
                temp = *(array + j);
                *(array + j) = *(array+j+1);
                *(array+j+1) = temp;
            }
        }
    }
}

/**
 * largestValue
 *
 * This function returns the largest int of the int pointer
 * array
 *
 * Parameters:
 *      array:  an int pointer array
 *      size: the size of the array
 *
 * Output:
 *      return:  largest int in the array
 *      reference parameters: none
 *      stream:  none
 */
int largestValue(int *array, int size){
    int max;

    //set max to first value
    max = *array;
    for(int i = 0; i < size; ++i){
        if(max < *(array + i)){
            max = *(array + i);
        }
    }
    return max;
}

/**
 * smallestValue
 *
 * This function returns the smallest int of the int pointer
 * array
 *
 * Parameters:
 *      array:  an int pointer array
 *      size: the size of the array
 *
 * Output:
 *      return:  smallest int in the array
 *      reference parameters: none
 *      stream:  none
 */
int smallestValue(int *array, int size){
    int min;

    //set min to first value
    min = *array;
    for(int i = 0; i < size; ++i){
        if(min > *(array + i)){
            min = *(array + i);
        }
    }
    return min;
}

/**
 * averageValue
 *
 * This function returns the average value of the int pointer
 * array
 *
 * Parameters:
 *      array:  an int pointer array
 *      size: the size of the array
 *
 * Output:
 *      return:  average of the ints in the array
 *      reference parameters: none
 *      stream:  none
 */
double averageValue(int *array, int size){
    double avg = 0;

    //adds all values to avg
    for(int i = 0; i < size; ++i){
        avg += *(array + i);
    }

    //finds average by dividing by size
    avg = avg / static_cast<double>(size);

    return avg;
}
/**
 * medianValue
 *
 * This function returns the median int of the int pointer
 * array. If the size is even, returns the smaller value
 *
 * Parameters:
 *      array:  an int pointer array
 *      size: the size of the array
 *
 * Output:
 *      return:  median int in the array
 *      reference parameters: none
 *      stream:  none
 */
int medianValue(int *array, int size){
    int median;
    //need to use bubble sort first to et median
    bubbleSort(array, size);
    if(size % 2 == 1){
        median = *(array + size/2);
    } else {
        median = *(array + size/2 - 1);
    }

    return median;
}
