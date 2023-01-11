/**
 * file: proj10-Queue2.h
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

#ifndef PROJ10_1_PROJ10_QUEUE2_H
#define PROJ10_1_PROJ10_QUEUE2_H

#include "proj10-MyVector.h"

template <class T>
class Queue2 : public MyVector<T> {
private:
    int front, rear;

public:
    Queue2();
    void enqueue( T );
    void dequeue( T& ); // throws BADINDEX
};

template <class T>
Queue2<T>::Queue2(){
    this->front = -1;
    this->rear = -1;
    this->size = 0;
    this->capacity = 100;
    this->data = new T[this->capacity];
}

template <class T>
void Queue2<T>::enqueue( T t){
    //if the size has reached capacity, the size will remain the same
    if((this->rear + 1) % this->capacity == this->front){
        this->size--;
    }
    if(this->rear == -1 && this->front == -1){
        this->front = 0;
    }
    this->rear = (this->rear + 1) % this->capacity;
    this->pushBack(t);
}

template <class T>
void Queue2<T>::dequeue( T& t){
    if(this->size == 0){
        throw BADINDEX();
    }
    this->front = (this->front + 1) % this->capacity;
    this->popFront(t);
}

#endif //PROJ10_1_PROJ10_QUEUE2_H
