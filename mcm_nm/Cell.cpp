
#include "Cell.hpp"
Cell::Cell()
{
    type = 'w';
    prevTemp = temp = INITIALTEMP;
}

double Cell::gTemp()
{
    return temp;
}

void Cell::uTemp(double t)
{
    temp = t;
}

double Cell::gPrevTemp()
{
    return prevTemp;
}

void Cell::uPrevTemp(double pt)
{
    prevTemp = pt;
}

char Cell::gType()
{
    return type;
}

void Cell::uType(char tp)
{
    type = tp;
}

double Cell::tempDiffW(Cell c)
{
    return CW * (c.prevTemp - prevTemp);
}

double Cell::tempDiffA(Cell c)
{
    return CA * (c.prevTemp - prevTemp);
}

double Cell::tempDiffB(Cell c)
{
    return CB * (c.prevTemp - prevTemp);
}

double Cell::tempDiffS(Cell c)
{
    return CS * (c.prevTemp - prevTemp);
}
