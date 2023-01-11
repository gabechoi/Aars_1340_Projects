/**
* file: proj9-TestMain.cpp
* author: Gabriel Choi
* course: CSI 1440
* assignment: Project 9
* due date: 11/28/22
*
* data modified: 11/26/22
*  - file created
*  - most of coding finished
*
* Linked Lists
*/

#include <iostream>
#include "proj9-MyList.h"

using namespace std;

int main() {
    int t;

    //testing default constructor...
    MyList<int> intVector;

    cout << "testing push front..." << endl;
    for (int i = 0; i < 5; ++i) {
        cout << i << " ";
        intVector.pushFront(i);
    }
    cout << endl;

    for (int i = 0; i < intVector.getSize(); ++i) {
        cout << intVector[i] << " ";
    }
    cout << endl << endl;

    cout << "testing push back..." << endl;
    for (int i = 0; i < 5; ++i) {
        cout << i << " ";
        intVector.pushBack(i);
    }
    cout << endl;

    for (int i = 0; i < intVector.getSize(); ++i) {
        cout << intVector[i] << " ";
    }
    cout << endl << endl;

    cout << "testing pop front..." << endl;
    for (int i = 0; i < 5; ++i) {
        intVector.popFront(t);
        cout << t << " ";
    }
    cout << endl;

    for (int i = 0; i < intVector.getSize(); ++i) {
        cout << intVector[i] << " ";
    }
    cout << endl << endl;

    cout << "testing pop back..." << endl;
    for (int i = 0; i < 5; ++i) {
        intVector.popBack(t);
        cout << t << " ";
    }
    cout << endl << endl;

    cout << "testing isEmpty..." << endl;
    if (intVector.isEmpty()) {
        cout << "IntVector is empty" << endl;
    }
    cout << endl;

    try {
        intVector.popBack(t);
    } catch (BADINDEX) {
        cout << "Should see this message." << endl;
    }

    try {
        intVector.popFront(t);
    } catch (BADINDEX) {
        cout << "Should see this message." << endl << endl;
    }

    for (int i = 0; i < 10; ++i) {
        intVector.pushBack(i);
        cout << i << " ";
    }
    cout << endl << endl;

    cout << "testing front..." << endl;
    cout << intVector.front() << endl << endl;

    cout << "testing back..." << endl;
    cout << intVector.back() << endl << endl;

    cout << "testing copy constructor..." << endl;
    MyList<int> intVector2(intVector);

    cout << "intVector: " << endl;
    for (int i = 0; i < intVector.getSize(); ++i) {
        cout << intVector[i] << " ";
    }
    cout << endl;
    cout << "intVector2: " << endl;
    for (int i = 0; i < intVector2.getSize(); ++i) {
        cout << intVector2[i] << " ";
    }
    cout << endl << endl;

    cout << "testing = operator..." << endl;
    MyList<int> intVector3;
    intVector3 = intVector;
    cout << "intVector3: " << endl;
    for (int i = 0; i < intVector3.getSize(); ++i) {
        cout << intVector3[i] << " ";
    }
    cout << endl << endl;

    cout << "testing every function again with char..." << endl << endl;

    MyList<char> charVector;
    char letter = 'a';
    char c;

    cout << "testing push front..." << endl;
    for (int i = 0; i < 5; ++i, ++letter) {
        cout << letter << " ";
        charVector.pushFront(letter);
    }
    cout << endl;

    for (int i = 0; i < charVector.getSize(); ++i) {
        cout << charVector[i] << " ";
    }
    cout << endl << endl;

    letter = 'a';
    cout << "testing push back..." << endl;
    for (int i = 0; i < 5; ++i, ++letter) {
        cout << letter << " ";
        charVector.pushBack(letter);
    }
    cout << endl;

    for (int i = 0; i < charVector.getSize(); ++i) {
        cout << charVector[i] << " ";
    }
    cout << endl << endl;

    cout << "testing pop front..." << endl;
    for (int i = 0; i < 5; ++i) {
        charVector.popFront(c);
        cout << c << " ";
    }
    cout << endl;

    for (int i = 0; i < charVector.getSize(); ++i) {
        cout << charVector[i] << " ";
    }
    cout << endl << endl;

    cout << "testing pop back..." << endl;
    for (int i = 0; i < 5; ++i) {
        charVector.popBack(c);
        cout << c << " ";
    }
    cout << endl << endl;

    cout << "testing isEmpty..." << endl;
    if (charVector.isEmpty()) {
        cout << "charVector is empty" << endl;
    }
    cout << endl;

    try {
        charVector.popBack(c);
    } catch (BADINDEX) {
        cout << "Should see this message." << endl;
    }

    try {
        charVector.popFront(c);
    } catch (BADINDEX) {
        cout << "Should see this message." << endl << endl;
    }

    letter = 'a';
    for (int i = 0; i < 10; ++i, ++letter) {
        charVector.pushBack(letter);
        cout << letter << " ";
    }
    cout << endl << endl;

    cout << "testing front..." << endl;
    cout << charVector.front() << endl << endl;

    cout << "testing back..." << endl;
    cout << charVector.back() << endl << endl;

    cout << "testing copy constructor..." << endl;
    MyList<char> charVector2(charVector);

    cout << "charVector: " << endl;
    for (int i = 0; i < charVector.getSize(); ++i) {
        cout << charVector[i] << " ";
    }
    cout << endl;
    cout << "charVector2: " << endl;
    for (int i = 0; i < charVector2.getSize(); ++i) {
        cout << charVector2[i] << " ";
    }
    cout << endl << endl;

    cout << "testing = operator..." << endl;
    MyList<char> charVector3;
    for (int i = 0; i < 5; ++i, ++letter) {
        cout << letter << " ";
        charVector3.pushFront(letter);
    }
    charVector3 = charVector;
    cout << "charVector3: " << endl;
    for (int i = 0; i < charVector3.getSize(); ++i) {
        cout << charVector3[i] << " ";
    }
    cout << endl << endl;

    try {
        cout << charVector[20] << endl;
    } catch (BADINDEX) {
        cout << "Should see this message." << endl << endl;
    }

    cout << "testing erase..." << endl;
    charVector.erase();
    if (charVector.isEmpty()) {
        cout << "charVector has been erased." << endl;
    }
}
