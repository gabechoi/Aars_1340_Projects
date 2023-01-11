/**
 * file: proj7-TestMain.cpp
 * author: Gabriel Choi
 * course: CSI 1440
 * assignment: project 7
 * due date: 11/7/2022
 *
 * date modified: 11/1/2022
 *      - code created
 *
 * date modified: 11/4/2022
 *      - all functions created
 *
 * date modified: 11/6/2022
 *      - testmain created
 *
 */

#include <iostream>
#include <stdexcept>
#include "proj7-MyVector.h"

using namespace std;

int main(){
    int t;

    //testing default constructor...
    MyVector<int> intVector;

    cout << "testing push front..." << endl;
    for(int i = 0; i < 5; ++i){
        cout << i << " ";
        intVector.pushFront(i);
    }
    cout << endl;

    for(int i = 0; i < intVector.getSize(); ++i){
        cout << intVector[i] << " ";
    }
    cout << endl << endl;

    cout << "testing push back..." << endl;
    for(int i = 0; i < 5; ++i){
        cout << i << " ";
        intVector.pushBack(i);
    }
    cout << endl;

    for(int i = 0; i < intVector.getSize(); ++i){
        cout << intVector[i] << " ";
    }
    cout << endl << endl;

    cout << "testing pop front..." << endl;
    for(int i = 0; i < 5; ++i){
        intVector.popFront(t);
        cout << t << " ";
    }
    cout << endl;

    for(int i = 0; i < intVector.getSize(); ++i){
        cout << intVector[i] << " ";
    }
    cout << endl << endl;

    cout << "testing pop back..." << endl;
    for(int i = 0; i < 5; ++i){
        intVector.popBack(t);
        cout << t << " ";
    }
    cout << endl << endl;

    cout << "testing isEmpty..." << endl;
    if(intVector.isEmpty()){
        cout << "IntVector is empty" << endl;
    }
    cout << endl;

    try{
        intVector.popBack(t);
    } catch(BADINDEX){
        cout << "Should see this message." << endl;
    }

    try{
        intVector.popFront(t);
    } catch(BADINDEX){
        cout << "Should see this message." << endl << endl;
    }

    for(int i = 0; i < 10; ++i){
        intVector.pushBack(i);
        cout << i << " ";
    }
    cout << endl << endl;

    cout << "testing front..." << endl;
    cout << intVector.front() << endl << endl;

    cout << "testing back..." << endl;
    cout << intVector.back() << endl << endl;

    cout << "testing copy constructor..." << endl;
    MyVector<int> intVector2(intVector);

    cout << "intVector: " << endl;
    for(int i = 0; i < intVector.getSize(); ++i){
        cout << intVector[i] << " ";
    }
    cout << endl;
    cout << "intVector2: " << endl;
    for(int i = 0; i < intVector2.getSize(); ++i){
        cout << intVector2[i] << " ";
    }
    cout << endl << endl;

    cout << "testing = operator..." << endl;
    MyVector<int> intVector3;
    intVector3 = intVector;
    cout << "intVector3: " << endl;
    for(int i = 0; i < intVector3.getSize(); ++i){
        cout << intVector3[i] << " ";
    }
    cout << endl << endl;

    cout << "testing every function again with char..." << endl << endl;

    MyVector<char> charVector;
    char letter = 'a';
    char c;

    cout << "testing push front..." << endl;
    for(int i = 0; i < 5; ++i, ++letter){
        cout << letter << " ";
        charVector.pushFront(letter);
    }
    cout << endl;

    for(int i = 0; i < charVector.getSize(); ++i){
        cout << charVector[i] << " ";
    }
    cout << endl << endl;

    letter = 'a';
    cout << "testing push back..." << endl;
    for(int i = 0; i < 5; ++i, ++letter){
        cout << letter << " ";
        charVector.pushBack(letter);
    }
    cout << endl;

    for(int i = 0; i < charVector.getSize(); ++i){
        cout << charVector[i] << " ";
    }
    cout << endl << endl;

    cout << "testing pop front..." << endl;
    for(int i = 0; i < 5; ++i){
        charVector.popFront(c);
        cout << c << " ";
    }
    cout << endl;

    for(int i = 0; i < charVector.getSize(); ++i){
        cout << charVector[i] << " ";
    }
    cout << endl << endl;

    cout << "testing pop back..." << endl;
    for(int i = 0; i < 5; ++i){
        charVector.popBack(c);
        cout << c << " ";
    }
    cout << endl << endl;

    cout << "testing isEmpty..." << endl;
    if(charVector.isEmpty()){
        cout << "charVector is empty" << endl;
    }
    cout << endl;

    try{
        charVector.popBack(c);
    } catch(BADINDEX){
        cout << "Should see this message." << endl;
    }

    try{
        charVector.popFront(c);
    } catch(BADINDEX){
        cout << "Should see this message." << endl << endl;
    }

    letter = 'a';
    for(int i = 0; i < 10; ++i, ++letter){
        charVector.pushBack(letter);
        cout << letter << " ";
    }
    cout << endl << endl;

    cout << "testing front..." << endl;
    cout << charVector.front() << endl << endl;

    cout << "testing back..." << endl;
    cout << charVector.back() << endl << endl;

    cout << "testing copy constructor..." << endl;
    MyVector<char> charVector2(charVector);

    cout << "charVector: " << endl;
    for(int i = 0; i < charVector.getSize(); ++i){
        cout << charVector[i] << " ";
    }
    cout << endl;
    cout << "charVector2: " << endl;
    for(int i = 0; i < charVector2.getSize(); ++i){
        cout << charVector2[i] << " ";
    }
    cout << endl << endl;

    cout << "testing = operator..." << endl;
    MyVector<char> charVector3;
    charVector3 = charVector;
    cout << "charVector3: " << endl;
    for(int i = 0; i < charVector3.getSize(); ++i){
        cout << charVector3[i] << " ";
    }
    cout << endl << endl;

    try{
        cout << charVector[20] << endl;
    }catch(BADINDEX){
        cout << "Should see this message." << endl << endl;
    }

    cout << "testing erase..." << endl;
    charVector.erase();
    if(charVector.isEmpty()){
        cout << "charVector has been erased." << endl;
    }

    return 0;
}