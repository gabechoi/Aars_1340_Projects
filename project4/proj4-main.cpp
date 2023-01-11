/**
 * file:  proj4-main.cpp
 * author:  Gabriel Choi
 * course: CSI 1440
 * assignment:  project 4
 * due date:  10/03/2022
 *
 * date modified: 09/28/2022
 *      - file created
 *
 * date modified: 10/03/2022
 *      - most code written
 *      - comments created
 *
 *
 */

#include "proj4-ItemInfo.hpp"
#include <fstream>

using namespace std;

void resizeArray(ItemInfo *that, int cap){
    ItemInfo *temp = that;
    that = new ItemInfo[cap + 2];
    for(int i = 0; i < cap; ++i){
        that[i] = temp[i];
    }
    delete[] temp;
}

void sortAndPrint(ItemInfo *that){
    char name[16] = "\"ChoiStore\": [\n";
    char c1[13] = "\t\"firstItem\"";
    char c2[14] = "\t\"secondItem\"";
    char c3[13] = "\t\"thirdItem\"";
    char c4[14] = "\t\"fourthItem\"";
    char c5[13] = "\t\"fifthItem\"";
    printCString(cout, name);
    printCString(cout, c1);
    that[0].toAmazonJSON(cout);
    printCString(cout, c2);
    that[1].toAmazonJSON(cout);
    printCString(cout, c3);
    that[2].toAmazonJSON(cout);
    printCString(cout, c4);
    that[3].toAmazonJSON(cout);
    printCString(cout, c5);
    that[4].toAmazonJSON(cout);
    printCString(cout, "]");
}

int main(){
    char buffer[500];
    int capacity = 2;
    int itemNum = 0;
    ItemInfo *itemArray = new ItemInfo[capacity];
    int count = 0;
    int prodType = 0;
    char c;
    ifstream inFile;
    char ccc[80];

    inFile.open("proj4-productServices.csv");


    while(inFile.get(buffer[count])){
        if(itemNum == capacity){
            //resizeArray(itemArray, capacity);
            capacity += 2;
            ItemInfo *temp = itemArray;
            itemArray = new ItemInfo[capacity];
            for(int i = 0; i < itemNum; ++i){
                itemArray[i] = temp[i];
            }
            delete[] temp;
        }
        if(buffer[count] == ',' || buffer[count] == '\n'){
            buffer[count] = '\0';
            if(prodType == 0){
                prodType++;
                count = 0;
                itemArray[itemNum].setItemId(buffer);
            }
            else if(prodType == 1){
                prodType++;
                count = 0;
                itemArray[itemNum].setDescription(buffer);
            }
            else if(prodType == 2){
                prodType++;
                count = 0;
                itemArray[itemNum].setManCost(buffer);
            }
            else{
                prodType = 0;
                count = 0;
                itemArray[itemNum].setSellPrice(buffer);
                itemNum++;
            }
        }else{
            count++;
        }
    }

    for(int i = 0; i < itemNum - 1; ++i){
        for(int j = 0; j < itemNum - i - 1; ++j){
            if(itemArray[j].calcProfit() < itemArray[j+1].calcProfit()){
                ItemInfo temp = itemArray[j];
                itemArray[j] = itemArray[j+1];
                itemArray[j+1] = temp;
            }
        }
    }

    sortAndPrint(itemArray);

    inFile.close();

    delete[] itemArray;

    return 0;
}

