

#ifndef PROJ5_1_PROJ5_BUATHLETELIST_HPP
#define PROJ5_1_PROJ5_BUATHLETELIST_HPP

#include "proj5-BUAthlete.hpp"

class BUAthleteList {
private:
    BUAthlete *list;
    int capacity;
    int size;
    void resizeArray();

public:
    BUAthleteList();
    ~BUAthleteList();
    BUAthleteList(BUAthleteList&);
    BUAthleteList& operator=(BUAthleteList&);
    void addNCAAAthlete(int, string, string, string);
    void setBUInfo(int, Position, int);
    int findById(int);
    void sortByID();
    void sortByPosition();
    void sortByEvaluation();
    BUAthlete& operator[](int);
    string toString();
};

#endif //PROJ5_1_PROJ5_BUATHLETELIST_HPP
