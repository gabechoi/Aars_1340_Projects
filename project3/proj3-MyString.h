/**
 * file: proj3-MyString.h
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

#ifndef PROJ3_1_PROJ3_MYSTRING_H
#define PROJ3_1_PROJ3_MYSTRING_H

using namespace std;
#include <iostream>

class MyString {
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
    MyString( );

    /**
     * constructor
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
    MyString(const char *);

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
    ~MyString( );

    /**
     * copy constructor
     *
     * constructor creates a copy of MyString
     *
     * Parameters:
     *      that: a reference to another MyString
     * Output:
     *      return:  none
     *      reference parameters: that
     *      stream:  none
     */
    MyString(const MyString &);

    /**
     * operator =
     *
     * overloaded assignment operator, make a copy of MyString object
     *
     * Parameters:
     *      that: a reference to another MyString
     * Output:
     *      return:  MyString
     *      reference parameters: that
     *      stream:  none
     */
    MyString& operator = (const MyString&);

    /**
     * operator ==
     *
     * overloaded equivalence relational operator
     *
     * Parameters:
     *      that: a reference to another MyString
     * Output:
     *      return:  MyString
     *      reference parameters: that
     *      stream:  none
     */
    bool operator == (const MyString&) const;

    /**
     * operator [ ]
     *
     * overloaded [ ] should return a char by reference
     *
     * Parameters:
     *      ndx: int index to return
     * Output:
     *      return:  char&
     *      reference parameters: none
     *      stream:  none
     */
    char& operator [ ] (int);

    /**
     * operator +=
     *
     * overloaded += operator, use to concatenate two MyStrings
     *
     * Parameters:
     *      that: a MyString object
     * Output:
     *      return:  none
     *      reference parameters: none
     *      stream:  none
     */
    void operator +=(const MyString);

    /**
     * operator +
     *
     * create new MyString object that is the concatenation of two MyString objects
     *
     * Parameters:
     *      that: a reference to MyString object
     * Output:
     *      return:  MyString
     *      reference parameters: that
     *      stream:  none
     */
    MyString operator + (const MyString&) const;

    /**
     * getline
     *
     * Reads an entire line from a istream. Lines are terminated with delimit
     * which is newline ‘\n’ by default
     *
     * Parameters:
     *      in: istream reference
     *      delimit: delimiter
     * Output:
     *      return:  none
     *      reference parameters: in
     *      stream: in
     */
    void getline(istream&, char delimit = '\n');

    /**
     * length
     *
     * return length of the string
     *
     * Parameters:
     *
     * Output:
     *      return: int
     *      reference parameters: none
     *      stream: none
     */
    int length( ) const;

    /**
     * operator <<
     *
     * overloaded insertion operator
     *
     * Parameters:
     *      out: ostream reference
     *      s: MyString reference
     * Output:
     *      return: ostream&
     *      reference parameters: out
     *      stream: ostream
     */
    friend ostream& operator<< (ostream&, MyString&);

private:
    int size;
    int capacity;
    char* data;

};

#endif //PROJ3_1_PROJ3_MYSTRING_H
