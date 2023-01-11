/**
 * file:  proj4-testmain.cpp
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
#include <iostream>

using namespace std;
/*
int main(){

    //testing stuCstrToDbl...
    char *poop = "-85.93";
    double poop2;
    poop2 = stuCstrToDbl(poop);
    cout << poop2 << endl;
    cout << poop2 * 2 << endl << endl;

    poop = "123";
    poop2 = stuCstrToDbl(poop);
    cout << poop2 << endl;
    cout << poop2 * 2 << endl << endl;


    //testing stuDblToCstr
    char poop3[10];
    double dbl = 1003;
    stuDblToCstr(poop3, dbl);
    cout << poop3 << endl << endl;

    dbl = -98.76;
    stuDblToCstr(poop3, dbl);
    cout << poop3 << endl << endl;

    //testing stuCstrCpy
    char *a = new char[4];
    char *b = new char[4];
    a[0] = 'm';
    a[1] = 'o';
    a[2] = 'p';
    a[3] = '\0';
    b[0] = 'b';
    b[1] = 'u';
    b[2] = 't';
    b[3] = '\0';

    cout << a << " " << b << endl;
    stuCstrCpy(a, b);
    cout << a << " " << b << endl << endl;

    char c[11] = "whitespace";
    char d[11] = "splashzone";

    cout << c << " " << d << endl;
    stuCstrCpy(c, d);
    cout << c << " " << d << endl << endl;

    //testing stuCstrLen
    cout << stuCstrLen(d) << endl << endl;

    //testing all ItemInfo related functions
    ItemInfo fakeItem;
    fakeItem.setItemId("12345");
    fakeItem.setDescription("Mens White Crewneck L");
    fakeItem.setManCost("14.99");
    fakeItem.setSellPrice("29.99");
    cout << "itemId: " << fakeItem.getItemId() << endl;
    cout << "description: " << fakeItem.getDescription() << endl;
    cout << "ManCost: " << fakeItem.getManCost() << endl;
    cout << "SellPrice: " << fakeItem.getSellPrice() << endl;
    cout << "Profit: " << fakeItem.calcProfit() << endl << endl;

    //testing toJSon
    fakeItem.toAmazonJSON(cout);
    cout << endl;

    //testing displayInfo
    fakeItem.displayItemInfo(cout);
    cout << endl;

    //testing printCString
    printCString(cout, "\nThis function works!!!");



    return 0;
}
*/
