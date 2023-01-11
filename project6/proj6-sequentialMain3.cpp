/**
 * file: proj6-sequentialMain3.cpp
 * author: Gabriel Choi
 * course: CSI 1440
 * assignment: project 6
 * due date: 11/14/22
 *
 * date modified: 11/13/2022
 *      - code created
 *      - all work completed
 *
 */

#include <iostream>
#include <fstream>

using namespace std;

int main() {
    string name, choice;
    int age;
    bool fileRead = false;
    ifstream pfile;
    ofstream opfile;

    cout << "Would you like to read the data from a file? " << endl;
    cin >> choice;
    cin.ignore(3, '\n');

    if( choice == "yes" ) {
        fileRead = true;
        pfile.open("iperson.txt");
        if( !pfile ) {
            cerr << "Can't open person.txt for read." << endl;
            return 1;
        }
    }

    opfile.open("operson.txt");

    choice = "yes";
    if( fileRead ) {
        //readPerson( pfile, name, age );
        getline( pfile, name );
        pfile >> age;
        pfile.ignore(3, '\n');
        if( !pfile ) {
            choice = "no";
        }
    }

    while( choice != "no" ) {
        if( !fileRead ) {
            //requestInfo( cout );
            cout << "Please enter your name followed by your age." << endl;
            //readPerson( cin, name, age );
            getline( cin, name );
            cin >> age;
            cin.ignore(3, '\n');

        }

        //writePerson( opfile, name, age );
        opfile << name << endl;
        opfile << age << endl;

        if( !fileRead ) {
            //choice = readAgain( cout, cin );
            cout << "Do you want to read in another person (yes/no)? " << endl;
            cin >> choice;
            cin.ignore(3, '\n');
        } else {
            //readPerson( pfile, name, age );
            getline( pfile, name );
            pfile >> age;
            pfile.ignore(3, '\n');
            if( !pfile ) {
                choice = "no";
            }
        }
    }

    if( fileRead ) {
        pfile.close();
    }
    opfile.close();

    return 0;
}

