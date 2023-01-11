/**
 * file: proj3-MyString.cpp
 * author: Gabriel Choi
 * course: CSI 1440
 * assignment: project 3
 * due date: 9/18/2022
 *
 * date modified: 9/12/2022
 *      - code created
 *
 * date modified: 9/14/2022
 *      - all functions created
 *
 * date modified: 9/17/2022
 *      - testmain created
 *
 */

#include "proj3-MyString.h"

MyString::MyString( ){
    this->size = 0;
    this->capacity = 10;
    this->data = new char[this->capacity];
}

MyString::MyString(const char *c){
    int i = 0;
    this->size = 0;
    this->capacity = 10;
    //check to find size
    while(c[i] != '\0'){
        this->size++;
        ++i;
    }
    //check to see if capacity too small
    while(this->size > this->capacity){
        this->capacity *= 2;
    }
    this->data = new char[this->capacity];
    for(int j = 0; j < this->size; ++j) {
        this->data[j] = c[j];
    }
    this->data[this->size] = '\0';
}

MyString::~MyString( ){
    delete[] this->data;
}

MyString::MyString(const MyString &that){
    this->capacity = that.capacity;
    this->size = that.size;
    this->data = new char[this->capacity];
    for(int i = 0; i < size; ++i){
        this->data[i] = that.data[i];
    }
    this->data[this->size] = '\0';
}

MyString& MyString::operator = (const MyString& that){
    if(this != &that) {
        //frees memory
        delete[] this->data;
        this->capacity = that.capacity;
        this->size = that.size;
        this->data = new char[this->capacity];
        for (int i = 0; i < size; ++i) {
            this->data[i] = that.data[i];
        }
    }
    return *this;
}

bool MyString::operator == (const MyString& that) const{
    bool flag = true;
    //check to see sizes are same first
    if(this->size == that.size){
        for(int i = 0; i < this->size; ++i){
            //check to see of this data matches that data
            if(this->data[i] != that.data[i]){
                flag = false;
            }
        }
    } else {
        flag = false;
    }
    return flag;
}

char& MyString::operator [ ] (int ndx){
    return this->data[ndx];
}

void MyString::operator +=(const MyString that){
    //check to see if resize is needed
    if(this->size + that.size + 1 > this->capacity){
        while(this->size + that.size + 1 > this->capacity){
            this->capacity *= 2;
        }
        char* temp = new char[this->capacity];
        for(int i = 0; i < this->size; ++i){
            temp[i] = this->data[i];
        }
        delete[] this->data;
        this->data = temp;
    }
    //sets this data to that data
    for(int i = 0; i < that.size; ++i){
        this->data[this->size + i] = that.data[i];
    }
    this->data[this->size+that.size] = '\0';
    this->size += that.size;
}

MyString MyString::operator + (const MyString& that) const{
    MyString temp = this->data;
    temp += that;
    return temp;
}

void MyString::getline(istream& in, char delimit){

    char c;
    delete[] this->data;
    this->size = 0;
    this->capacity = 10;
    this->data = new char[this->capacity];

    in.get(c);

    //loop keeps going unless delimit is found
    while(c != delimit){
        this->data[this->size] = c;
        this->size++;

        //check to see if resize is needed
        if(this->size + 1 == this->capacity){
            this->capacity *= 2;
            char *temp = new char[this->capacity];

            for(int i = 0; i < this->size; ++i){
                temp[i] = this->data[i];
            }

            delete[] this->data;
            this->data = temp;
        }
        in.get(c);
    }

    //check to see if capacity is too big
    while(4 * this->size < this->capacity){
        this->capacity /= 2;
        char *temp = new char[this->capacity];

        for(int i = 0; i < this->size; ++i){
            temp[i] = this->data[i];
        }

        delete[] this->data;
        this->data = temp;
    }
    this->data[this->size] = '\0';
}

int MyString::length( ) const{
    return this->size;
}

ostream& operator << (ostream& out, MyString& s){
    for(int i = 0; i < s.size; ++i){
        out << s.data[i];
    }

    return out;
}

