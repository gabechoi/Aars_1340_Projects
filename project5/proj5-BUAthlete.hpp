
#ifndef PROJ5_1_PROJ5_BUATHLETE_HPP
#define PROJ5_1_PROJ5_BUATHLETE_HPP

#include "proj5-NCAAAthlete.hpp"

using namespace std;

enum Position {OL, QB, RB, WR, TE, DL, DE, LB, CB, S, K};

class BUAthlete : public NCAAAthlete {
protected:
    int evaluation;
    Position bestFit;

public:
    void setEvaluation(int);
    void setPosition(Position);
    int getEvaluation();
    Position getPosition();
    string toString();
};

#endif //PROJ5_1_PROJ5_BUATHLETE_HPP
