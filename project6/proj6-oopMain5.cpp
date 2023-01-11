/**
 * file: proj6-oopMain5.cpp
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

const int PLIST_SIZE = 10;

class Person {
private:
    string name;
    int age;

public:
    /**
     * getName
     *
     * returns name
     *
     * Parameters:
     *
     * Output:
     *      return:  string
     *      reference parameters:  none
     *      stream:  none
     */
    string getName() { return name; }

    /**
     * readPerson
     *
     * reads in person information from a istream
     *
     * Parameters:
     *      istream: in
     *
     * Output:
     *      return:  none
     *      reference parameters:  none
     *      stream:  in
     */
    void readPerson(istream &);

    /**
     * writePerson
     *
     * writes out person information to an ostream
     *
     * Parameters:
     *      ostream: out
     *
     * Output:
     *      return:  none
     *      reference parameters:  none
     *      stream:  out
     */
    void writePerson(ostream &);
};

void Person::readPerson(istream &in) {
    getline(in, name);
    in >> age;
    in.ignore(3, '\n');
}

void Person::writePerson(ostream &out) {
    out << name << endl;
    out << age << endl;
}

/**
     * requestInfo
     *
     * requests info from the user
     *
     * Parameters:
     *      ostream: out
     *      string: msg
     *
     * Output:
     *      return:  none
     *      reference parameters:  none
     *      stream:  out
     */
void requestInfo(ostream &out, string msg) {
    out << msg << endl;
}

/**
     * readAgain
     *
     * asks if user wants to read in another person
     *
     * Parameters:
     *      ostream: out
     *      istream: in
     *
     * Output:
     *      return:  string
     *      reference parameters:  none
     *      stream:  in, out
     */
string readAgain(ostream &out, istream &in) {
    string choice;

    out << "Do you want to read in another person (yes/no)? " << endl;
    in >> choice;
    in.ignore(3, '\n');

    return choice;
}

class Customer{
private:
    string name;
    int age;
    double shippingRate;

public:
    Customer();
    /**
     * getName
     *
     * returns name
     *
     * Parameters:
     *
     * Output:
     *      return:  string
     *      reference parameters:  none
     *      stream:  none
     */
    string getName() { return name; }

    /**
     * getShippingRate
     *
     * returns shippingRate
     *
     * Parameters:
     *
     * Output:
     *      return:  double
     *      reference parameters:  none
     *      stream:  none
     */
    double getShippingRate();

    /**
     * readPerson
     *
     * reads in person information from a istream
     *
     * Parameters:
     *      istream: in
     *
     * Output:
     *      return:  none
     *      reference parameters:  none
     *      stream:  in
     */
    void readPerson( istream & );

    /**
     * writePerson
     *
     * writes out person information to an ostream
     *
     * Parameters:
     *      ostream: out
     *
     * Output:
     *      return:  none
     *      reference parameters:  none
     *      stream:  out
     */
    void writePerson( ostream & );
};

Customer::Customer() {
    shippingRate = 5.0;
}

double Customer::getShippingRate() {
    return shippingRate;
}

void Customer::readPerson(istream &in) {
    //Person::readPerson(in);
    getline(in, name);
    in >> age;
    in.ignore(3, '\n');
    in >> shippingRate;
    cin.ignore(3, '\n');
}

void Customer::writePerson(ostream &out) {
    //Person::writePerson(out);
    out  <<  name << endl;
    out << age << endl;
    out << shippingRate << endl;
}

class MegaCustomer{
private:
    string name;
    int age;
    double shippingRate;
public:
    MegaCustomer();
    /**
     * getName
     *
     * returns name
     *
     * Parameters:
     *
     * Output:
     *      return:  string
     *      reference parameters:  none
     *      stream:  none
     */
    string getName() { return name; }

    /**
     * readPerson
     *
     * reads in person information from a istream
     *
     * Parameters:
     *      istream: in
     *
     * Output:
     *      return:  none
     *      reference parameters:  none
     *      stream:  in
     */
    void readPerson( istream & );

    /**
     * writePerson
     *
     * writes out person information to an ostream
     *
     * Parameters:
     *      ostream: out
     *
     * Output:
     *      return:  none
     *      reference parameters:  none
     *      stream:  out
     */
    void writePerson( ostream &);
};

MegaCustomer::MegaCustomer() {
    shippingRate = 0;
}

void MegaCustomer::readPerson( istream & in ) {
    getline(in, name);
    in >> age;
    in.ignore(3, '\n');
}

void MegaCustomer::writePerson(ostream &out) {
    //Person::writePerson(out);
    out  <<  name << endl;
    out << age << endl;
    out << shippingRate << endl;
}

/**
     * findPerson
     *
     * finds a person from their name
     *
     * Parameters:
     *      Person*: pList
     *      string: name
     *
     * Output:
     *      return:  int
     *      reference parameters:  none
     *      stream:  none
     */
int findPerson(Person *pList[], string name) {
    int pos = -1, index = 0;

    while (pos == -1 && index < PLIST_SIZE) {
        if (pList[index]->getName() == name) {
            pos = index;
        }
        index++;
    }

    return pos;
}

/**
     * findPerson
     *
     * finds a Customer from their name
     *
     * Parameters:
     *      Customer*: pList
     *      string: name
     *
     * Output:
     *      return:  int
     *      reference parameters:  none
     *      stream:  none
     */
int findPerson(Customer *pList[], string name) {
    int pos = -1, index = 0;

    while (pos == -1 && index < PLIST_SIZE) {
        if (pList[index]->getName() == name) {
            pos = index;
        }
        index++;
    }

    return pos;
}

/**
     * findPerson
     *
     * finds a MegaCustomer from their name
     *
     * Parameters:
     *      MegaCustomer*: pList
     *      string: name
     *
     * Output:
     *      return:  int
     *      reference parameters:  none
     *      stream:  none
     */
int findPerson(MegaCustomer *pList[], string name) {
    int pos = -1, index = 0;

    while (pos == -1 && index < PLIST_SIZE) {
        if (pList[index]->getName() == name) {
            pos = index;
        }
        index++;
    }

    return pos;
}

int main() {
    Person **pList = new Person *[PLIST_SIZE];
    Customer **cList = new Customer *[PLIST_SIZE];
    MegaCustomer **mList = new MegaCustomer *[PLIST_SIZE];
    string choice, pTypeChoice, msg = "Please enter your name followed by your age.";
    int index = 0;
    bool fileRead = false;
    ifstream pfile;
    ofstream opfile;

    cout << "Would you like to read the data from a file (yes/no)? " << endl;
    cin >> choice;
    cin.ignore(3, '\n');

    if (choice == "yes") {
        fileRead = true;
        pfile.open("iperson.txt");

        if (!pfile) {
            cerr << "Can't open person.txt for read." << endl;
            return 1;
        }
        pfile >> pTypeChoice;
        pfile.ignore(3, '\n');

    } else {
        cout << "What type of Person? (person/customer/mega)" << endl;
        cin >> pTypeChoice;
        cin.ignore(3, '\n');
    }

    if (pTypeChoice == "person") {
        for (int i = 0; i < PLIST_SIZE; i++) {
            pList[i] = new Person;
        }
    } else if(pTypeChoice == "customer"){
        for (int i = 0; i < PLIST_SIZE; i++) {
            cList[i] = new Customer;
        }
        msg = "Please enter your name followed by your age then shipping rate.";
    } else {
        for( int i = 0; i < PLIST_SIZE; i++ ) {
            mList[i] = new MegaCustomer;
        }
    }

    opfile.open("operson.txt");

    choice = "yes";

    if (fileRead) {
        //checks to see which list is needed
        if (pTypeChoice == "person") {
            pList[index]->readPerson(pfile);
        } else if(pTypeChoice == "customer"){
            cList[index]->readPerson(pfile);
        } else {
            mList[index]->readPerson(pfile);
        }
        if (!pfile) {
            choice = "no";
        }
    }

    while (choice != "no" && index < PLIST_SIZE) {
        if (!fileRead) {
            requestInfo(cout, msg);
            if (pTypeChoice == "person") {
                pList[index]->readPerson(cin);
            } else if(pTypeChoice == "customer"){
                cList[index]->readPerson(cin);
            } else {
                mList[index]->readPerson(cin);
            }
        }

        if (pTypeChoice == "person") {
            pList[index]->writePerson(opfile);
        } else if(pTypeChoice == "customer"){
            cList[index]->writePerson(opfile);
        } else {
            mList[index]->writePerson(opfile);
        }

        index++;
        if (!fileRead) {
            choice = readAgain(cout, cin);
        } else {
            if (pTypeChoice == "person") {
                pList[index]->readPerson(pfile);
            } else if(pTypeChoice == "customer"){
                cList[index]->readPerson(pfile);
            } else {
                mList[index]->readPerson(pfile);
            }
            if (!pfile) {
                choice = "no";
            }
        }
    }

    if (fileRead) {
        pfile.close();
    }
    opfile.close();

    cout << "Which person are you looking for? " << endl;
    getline(cin, choice);

    if (pTypeChoice == "person") {
        if ((index = findPerson(pList, choice)) != -1) {
            cout << "Found your person: " << endl;
            pList[index]->writePerson(cout);
        } else {
            cout << "Couldn't find your person: " << choice << endl;
        }
    } else if(pTypeChoice == "customer"){
        if ((index = findPerson(cList, choice)) != -1) {
            cout << "Found your person: " << endl;
            cList[index]->writePerson(cout);
        } else {
            cout << "Couldn't find your person: " << choice << endl;
        }
    } else {
        if ((index = findPerson(mList, choice)) != -1) {
            cout << "Found your person: " << endl;
            mList[index]->writePerson(cout);
        } else {
            cout << "Couldn't find your person: " << choice << endl;
        }
    }

    for( int i = 0; i < PLIST_SIZE; i++ ){
        delete pList[i];
        delete cList[i];
        delete mList[i];
    }
    delete [] pList;
    delete [] cList;
    delete [] mList;

    return 0;
}
