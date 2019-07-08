
#ifndef Cell_hpp
#define Cell_hpp
#include <stdio.h>
#include <cmath>
#endif /* Cell_hpp */

const short X = 50, Y = 30, Z = 10;
const double INITIALTEMP = 308.15, HOTWATERTEMP = 315.15;
const double LAMBDA = 0.64, DELTIME = 0.02;
const double ALPHAA = 298.15, ALPHAB = 307.15, ALPHAS = 310.15;
const double C = 4200, RHO = 1000, D = 0.05;
const double RA = -0.03, RB = -0.07, RS = -0.065;//AIR BOUNDARY SKIN
const double CW = LAMBDA * DELTIME /(C * RHO  * D * D);
const double CA = 1 - exp(RA * DELTIME);
const double CB = 1 - exp(RB * DELTIME);
const double CS = 1 - exp(RS * DELTIME);

class Cell
{
public:
    Cell();
    double gTemp();
    double gPrevTemp();
    char gType();
    
    
    void uTemp(double t);
    void uPrevTemp(double pt);
    void uType(char tp);
    
    
    double tempDiffW(Cell c);
    double tempDiffA(Cell c);
    double tempDiffB(Cell c);
    double tempDiffS(Cell c);
private:
    char type;
    double temp, prevTemp;
};