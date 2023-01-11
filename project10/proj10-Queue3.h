/**
 * file: proj10-Queue3.h
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

#ifndef PROJ10_1_PROJ10_QUEUE3_H
#define PROJ10_1_PROJ10_QUEUE3_H

#include "proj10-MyList.h"

template <class T>
class Queue3 : public MyList<T> {
public:
    void enqueue( T );
    void dequeue( T& ); // throws BADINDEX
};

template <class T>
void Queue3<T>::enqueue( T t){
    this->pushBack(t);
}

template <class T>
void Queue3<T>::dequeue( T& t){
    this->popFront(t);
}

#endif //PROJ10_1_PROJ10_QUEUE3_H
