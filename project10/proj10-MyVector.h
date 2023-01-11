/**
 * file: proj10-MyVector.h
 * author: Gabriel Choi
 * course: CSI 1440
 * assignment: project 10
 * due date: 12/5/2022
 *
 * date modified: 12/1/2022
 *      - code created
 *
 * date modified: 12/4/2022
 *      - all functions created
 *
 */

#ifndef PROJ10_1_PROJ10_MYVECTOR_H
#define PROJ10_1_PROJ10_MYVECTOR_H

#include "proj10-ContainerIfc.h"

template <class T>
class MyVector : public ContainerIfc<T> {
public:
    /**
     * default constructor
     *
     * constructor
     *
     * Parameters:
     *
     * Output:
     *      return:  none
     *      reference parameters: none
     *      stream:  none
     */
    MyVector ();

    /**
     * destructor
     *
     * deletes data
     *
     * Parameters:
     *
     * Output:
     *      return:  none
     *      reference parameters: none
     *      stream:  none
     */
    ~MyVector ();

    /**
     * copy constructor
     *
     * sets data from this to that
     *
     * Parameters:
     *      that: reference to another MyVector
     *
     * Output:
     *      return:  none
     *      reference parameters: none
     *      stream:  none
     */
    MyVector (const MyVector&);

    /**
     * operator =
     *
     * overloaded assignment operator
     *
     * Parameters:
     *      that: a reference to another MyVector
     * Output:
     *      return:  MyVector&
     *      reference parameters: that
     *      stream:  none
     */
    MyVector<T>& operator = (const MyVector&);

    /**
     * pushFront
     *
     * shifts all values to the right and puts a new value at index 0
     *
     * Parameters:
     *      e: a value of type T
     * Output:
     *      return:  MyVector&
     *      reference parameters: none
     *      stream:  none
     */
    MyVector<T>& pushFront(T);

    /**
     * pushBack
     *
     * shifts all values to the left and puts a new value at last index
     *
     * Parameters:
     *      e: a value of type T
     * Output:
     *      return:  MyVector&
     *      reference parameters: none
     *      stream:  none
     */
    MyVector<T>& pushBack(T);

    /**
     * popFront
     *
     * shifts all values to the left and deletes value at index 0
     *
     * Parameters:
     *      e: a reference tp a value of type T
     * Output:
     *      return:  MyVector&
     *      reference parameters: e
     *      stream:  none
     */
    MyVector<T>& popFront(T&);

    /**
     * popFront
     *
     * deletes value at last index
     *
     * Parameters:
     *      e: a reference tp a value of type T
     * Output:
     *      return:  MyVector&
     *      reference parameters: e
     *      stream:  none
     */
    MyVector<T>& popBack(T&);

    /**
     * front
     *
     * returns the value at the first index
     *
     * Parameters: none
     *
     * Output:
     *      return: T
     *      reference parameters: none
     *      stream:  none
     */
    T  front();

    /**
     * back
     *
     * returns the value at the last index
     *
     * Parameters: none
     *
     * Output:
     *      return: T
     *      reference parameters: none
     *      stream:  none
     */
    T  back();

    /**
     * operator[]
     *
     * returns the value at the index provided
     *
     * Parameters:
     *      ndx: int
     *
     * Output:
     *      return: T
     *      reference parameters: none
     *      stream:  none
     */
    T&  operator [](int);

    /**
     * getSize
     *
     * returns the size of the array
     *
     * Parameters: none
     *
     * Output:
     *      return: T
     *      reference parameters: none
     *      stream:  none
     */
    int getSize();

    /**
     * isEmpty
     *
     * returns if the array is empty or not
     *
     * Parameters: none
     *
     * Output:
     *      return: bool
     *      reference parameters: none
     *      stream:  none
     */
    bool isEmpty();

    /**
     * erase
     *
     * erases the array
     *
     * Parameters: none
     *
     * Output:
     *      return: none
     *      reference parameters: none
     *      stream:  none
     */
    void erase();

protected:
    T  *data;
    int size;
    int capacity;
    /**
     * grow
     *
     * increases the capacity of the array by double
     *
     * Parameters: none
     *
     * Output:
     *      return: none
     *      reference parameters: none
     *      stream:  none
     */
    void grow();

    /**
     * shiftRight
     *
     * shifts all values of the array to the right
     *
     * Parameters: none
     *
     * Output:
     *      return: none
     *      reference parameters: none
     *      stream:  none
     */
    void shiftRight();

    /**
     * shiftLeft
     *
     * shifts all values of the array to the left
     *
     * Parameters: none
     *
     * Output:
     *      return: none
     *      reference parameters: none
     *      stream:  none
     */
    void shiftLeft();
};

template <class T>
void MyVector<T>::grow(){
    this->capacity *= 2;
    T *temp = this->data;
    this->data = new T[this->capacity];
    for(int i = 0; i < this->size; ++i){
        this->data[i] = temp[i];
    }
    delete[] temp;
}

template <class T>
void MyVector<T>::shiftRight(){
    //sets data from previous index to current index
    for(int i = this->size; i > 0; --i){
        this->data[i] = this->data[i-1];
    }
    this->size++;
}

template <class T>
void MyVector<T>::shiftLeft(){
    //sets data from next index to current index
    for(int i = 0; i < this->size - 1; ++i){
        this->data[i] = this->data[i+1];
    }
    this->size--;
}

template <class T>
MyVector<T>::MyVector (){
    this->size = 0;
    this->capacity = 10;
    this->data = new T[this->capacity];
}

template <class T>
MyVector<T>::~MyVector (){
    delete[] this->data;
}

template <class T>
MyVector<T>::MyVector (const MyVector& that){
    this->size = that.size;
    this->capacity = that.capacity;
    this->data = new T[this->capacity];
    for(int i = 0; i < this->size; ++i){
        this->data[i] = that.data[i];
    }
}

template <class T>
MyVector<T>& MyVector<T>::operator = (const MyVector& that){
    if(this != &that){
        delete[] this->data;
        this->size = that.size;
        this->capacity = that.capacity;
        this->data = new T[this->capacity];
        for(int i = 0; i < this->size; ++i){
            this->data[i] = that.data[i];
        }
    }
    return *this;
}

template <class T>
MyVector<T>& MyVector<T>::pushFront(T e){
    if(this->size == this->capacity){
        this->grow();
    }
    this->shiftRight();
    this->data[0] = e;
    return *this;
}

template <class T>
MyVector<T>& MyVector<T>::pushBack(T e){
    if(this->size == this->capacity){
        grow();
    }
    this->data[this->size] = e;
    this->size++;
    return *this;
}

template <class T>
MyVector<T>& MyVector<T>::popFront(T& e){
    //check to see if vector is empty
    if(isEmpty()){
        throw BADINDEX();
    }
    e = this->data[0];
    this->shiftLeft();
    return *this;
}

template <class T>
MyVector<T>& MyVector<T>::popBack(T& e){
    //check to see if vector is empty
    if(isEmpty()){
        throw BADINDEX();
    }
    else{
        --this->size;
        e = this->data[this->size];
        return *this;
    }
}

template <class T>
T  MyVector<T>::front(){
    //check to see if vector is empty
    if(isEmpty()){
        throw BADINDEX();
    }
    return this->data[0];
}

template <class T>
T  MyVector<T>::back(){
    //check to see if vector is empty
    if(isEmpty()){
        throw BADINDEX();
    }
    return this->data[this->size - 1];
}

template <class T>
T&  MyVector<T>::operator [](int ndx){
    //check to see if vector is empty or if index is out of bounds
    if(isEmpty() || ndx < 0 || ndx >= this->size){
        throw BADINDEX();
    }
    return this->data[ndx];
}

template <class T>
int MyVector<T>::getSize(){
    return this->size;
}

template <class T>
bool MyVector<T>::isEmpty(){
    if(this->size == 0){
        return true;
    }
    return false;
}

template <class T>
void MyVector<T>::erase(){
    this->size = 0;
    this->capacity = 10;
    delete[] this->data;
    this->data = new T[this->capacity];
}

#endif //PROJ10_1_PROJ10_MYVECTOR_H
