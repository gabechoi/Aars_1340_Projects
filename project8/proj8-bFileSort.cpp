/**
 * file: proj8-bFileSort.cpp
 * author: Gabriel Choi
 * course: CSI 1440
 * assignment: project 8
 * due date: 9/24/2022
 *
 * date modified: 9/20/2022
 *      - code created
 *
 * date modified: 9/23/2022
 *      - bulk of code created
 *
 *
 */

#include <iostream>
#include <fstream>

using namespace std;

int main(){
    int x = 0;
    int y = 0;
    int amt;
    int count = 1;
    bool flag = false;
    fstream file("sortedInts", ios::in | ios::out | ios::binary);

    //checks if file is opened
    if(!file){
        cerr << "Error: bad file";
        return 1;
    }

    //it is implied that the numbers will be sorted when inputed
    cout << "Enter amount of numbers you will input: ";
    cin >> amt;
    cout << endl;

    //make array for numbers
    int numArray[amt];

    //gets all ints from user
    for(int i = 0; i < amt; ++i){
        cin >> x;
        //numArray[i] = x;
        file.write((char*)&x, sizeof(int));
    }

    //outputs the ints to the screen
    for(int i = 0; i < amt; ++i){
        file.seekg((i)*sizeof(int), ios::beg);
        file.read((char*)&y, sizeof(int));
        cout << y << endl;
    }

    cout << "Input int X into file: ";
    cin >> x;
    cout << endl;

    //insert x into file
    //flag indicates if x has been inserted
    while(count <= amt + 1 && !flag){
        file.seekg((count)*-sizeof(int),ios::end);
        file.read((char*) &y,sizeof(int));
        if (x >= y){
            flag = true;
            file.write((char*)&x,sizeof(int));
        }
        else{
            file.write((char*)&y,sizeof(int));
        }
    }

    //if x is always less than y
    if(!flag){
        file.seekg(0,ios::beg);
        file.write((char*)&x, sizeof(int));
    }

    for(int i = 0; i < amt + 1; ++i){
        file.seekg((i)*sizeof(int), ios::beg);
        file.read((char*)&y, sizeof(int));
        cout << y << endl;
    }

    file.close();

    return 0;
}

