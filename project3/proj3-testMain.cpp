/**
 * file: proj3-testMain.cpp
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
#include <sstream>

using namespace std;

int main(){
    //Testing default constructor
    MyString s1;
    //Testing constructor with char array
    MyString s2("This should print");
    //Testing copy constructor
    MyString s3(s2);
    //Testing overloaded assignment operator
    s1 = s2;

    cout << "Printing s2..." << endl;
    cout << s2 << endl;
    cout << "Printing s3..." << endl;
    cout << s3 << endl;
    cout << "Printing s1 = s2..." << endl;
    cout << s1;

    cout << endl;

    MyString a1 = "Gabriel ";
    MyString a2 = "Philip ";
    MyString a3 = "Choi";

    cout << "Testing << operator..." << endl;

    cout << a1 << a2 << a3 << endl;

    cout << endl << "Testing ==..." << endl;
    if(!(a1 == a2)){
        cout << "a1 != a2" << endl;
    }
    if(s2 == s3){
        cout << "s2 == s3" << endl;
    }

    cout << "Testing + operator..." << endl;
    s1 = a1 + a2;
    cout << s1 << endl << endl;

    cout << "Testing += operator..." << endl;
    s1 += a3;
    cout << s1 << endl << endl;

    cout << "Testing [] operator..." << endl;
    cout << a1[0] << a2[0] << a3[0] << endl << endl;

    cout << "Testing length function" << endl;
    cout << s1.length() << endl << endl;

    cout << "Testing the getline function..." << endl;
    istringstream inSS;
    inSS.clear();
    inSS.str("I love Matt Aars\n");
    s1.getline(inSS);
    cout << s1 << endl;
    inSS.clear();
    inSS.str("I love CSI\n");
    s1.getline(inSS);
    cout << s1 << endl;
    inSS.clear();
    inSS.str("This is the third line\n");
    s1.getline(inSS);
    cout << s1 << endl << endl;

    //uses destructor
    /*s1.~MyString();
    s2.~MyString();
    s3.~MyString();
    a1.~MyString();
    a2.~MyString();
    a3.~MyString();*/

    return 0;
};
