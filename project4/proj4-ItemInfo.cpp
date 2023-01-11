/**
 * file:  proj4-ItemInfo.cpp
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

void ItemInfo::setItemId(const char *num) {
    double id = stuCstrToDbl(num);
    this->itemId = int(id);
}

void ItemInfo::setDescription(const char *cstr){
    char *temp = this->description;
    while(*cstr != '\0'){
        *temp = *cstr;
        temp++;
        cstr++;
    }
    *temp = '\0';
}

void ItemInfo::setManCost(const char *num){
    this->manCost = stuCstrToDbl(num);
}

void ItemInfo::setSellPrice(const char *num){
    this->sellPrice = stuCstrToDbl(num);
}

int ItemInfo::getItemId(){
    return this->itemId;
}

const char *ItemInfo::getDescription(){
    return this->description;
}

double ItemInfo::getManCost(){
    return this->manCost;
}

double ItemInfo::getSellPrice(){
    return this->sellPrice;
}

void ItemInfo::toAmazonJSON(ostream &out){
    char item[15] = "{\n\t\t\"itemId\": ";
    char d[19] = "\n\t\t\"description\": ";
    char mP[16] = "\n\t\t\"manPrice\": ";
    char sP[17] = "\n\t\t\"sellPrice\": ";
    printCString(out, item);
    stuDblToCstr(item, this->itemId);
    printCString(out, item);
    printCString(out, d);
    printCString(out, this->description);
    printCString(out, mP);
    stuDblToCstr(mP, this->manCost);
    printCString(out, mP);
    printCString(out, sP);
    stuDblToCstr(sP, this->sellPrice);
    printCString(out, sP);
    out.put('\n');
    out.put('\t');
    out.put('}');
    out.put(',');
    out.put('\n');
}

void ItemInfo::displayItemInfo(ostream &out){
    char item[9] = "itemId: ";
    char d[15] = "\ndescription: ";
    char mP[11] = "\nmanCost: ";
    char sP[13] = "\nsellPrice: ";
    char cP[20] = "\ncalculatedProfit: ";

    printCString(out, item);
    stuDblToCstr(item, this->itemId);
    printCString(out, item);
    printCString(out, d);
    printCString(out, this->description);
    printCString(out, mP);
    stuDblToCstr(mP, this->manCost);
    printCString(out, mP);
    printCString(out, sP);
    stuDblToCstr(sP, this->sellPrice);
    printCString(out, sP);
    printCString(out, cP);
    stuDblToCstr(cP, calcProfit());
    printCString(out, cP);
    out.put('\n');

}

double ItemInfo::calcProfit(){
    return this->sellPrice - this->manCost;
}

double stuCstrToDbl(const char *num){
    double returnVal = 0;
    double neg = 1;
    int count = 0;
    //need two arguments
    if(*num == '-'){
        neg = -1;
        num++;
    }
    while(*num != '\0' && *num != '.'){
        //if there is only one digit
        if(count != 0){
            returnVal *= 10;
        }
        returnVal += *num - '0';
        num++;
        count++;
    }
    int i = 0;
    //for decimal points
    while(*num != '\0'){
        if(i == 0){
            ++num;
            returnVal += 0.1 * (*num - '0');
        }
        else {
            returnVal += 0.01 * (*num - '0');
        }
        num++;
        ++i;
    }

    return returnVal * neg;
}

void stuDblToCstr(char *cstr, double num){
    int ndx = 0;
    int count = 0;
    int num2, neg = 0;
    char swap;
    double num3;
    //check if negative
    if(num < 0){
        cstr[ndx] = '-';
        ndx++;
        num *= -1;
        neg = 1;
        ++count;
    }
    num2 = num;
    while(num2 > 0){
        //find way to make int a char
        cstr[ndx] = char(num2%10 + '0');
        num2 /= 10;
        ndx++;
        count++;
    }
    //need to reverse the order of chars in front of decimal
    for(int i = 0; i < count / 2; ++i){
        swap = cstr[i + neg];
        cstr[i + neg] = cstr[count - i - 1];
        cstr[count - i - 1] = swap;
    }
    //find way to see if there are decimal points
    num3 = num - static_cast<int>(num);
    if(num3 > 0){
        cstr[ndx] = '.';
        ndx++;
        for(int i = 0; i < 2; ++i){
            num3 *= 10;
            cstr[ndx] = char(int(num3) + '0');
            num3 = num3 - static_cast<int>(num3);
            ndx++;
        }
    }
    cstr[ndx] = '\0';
}


void stuCstrCpy(char *dest, const char *src){
    int count = 0;
    if(src != dest){
        //copy all parts of src to dest
        while(src[count] != '\0'){
            dest[count] = src[count];
            ++count;
        }
        dest[count] = '\0';
    }
}


int stuCstrLen(const char *src){
    int count = 0;
    while(*src != '\0'){
        ++count;
        ++src;
    }
    return count;
}

ostream& printCString(ostream &out, const char *src){
    int count = 0;
    while(src[count] != '\0'){
        out.put(src[count]);
        ++count;
    }
    return out;
}

