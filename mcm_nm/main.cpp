#include <fstream> 
#include <iostream>
#include "Cell.hpp"
#include <ctime>

long idx(short x, short y, short z);

void update(Cell tub[]);

void updateCell(Cell tub[], short x, short y, short z);

double tempDiff(Cell tub[], short x, short y, short z, short xx, short yy, short zz);

void initialize(Cell tub[]);

void addHotWater(Cell tub[]);

int main()
{
    using namespace std;
    clock_t start = clock();
    long arraySize = X*Y*Z;
    Cell *Tub = new Cell[arraySize];
    
    //cout << CW << " " << CA << " " << CB << " " << CS << "\n";
    


	//outttttttttttttttt to file
	ofstream fout("gan.txt");
	if (!fout) {
		cout << "無法寫入檔案\n";
		return 1;
	}

    initialize(Tub);
    
    fout.setf(ios::fixed);
    fout.setf(ios::showpoint);
    fout.precision(5);
    
    for (int i = 0; i < 100000; i++)
    {
        addHotWater(Tub);
        update(Tub);
    }
	addHotWater(Tub);

	for (short x = 0; x < X; x++)
    {
        for (short y = 0; y < Y; y++)
        {
            for (short z = 0; z < Z; z++)
            {
                fout << Tub[idx(x, y, z)].gTemp() <<endl;
            }
        }
  //      cout << "\n\n";
    }
    
    cout << double(clock()-start)/CLOCKS_PER_SEC <<""<< "\n";
	fout.close();
}

long idx(short x, short y, short z)
{
    return x + Y * (y + Z *z);
}

void update(Cell tub[])
{
    for (short x = 1; x < X - 1; x++)
    {
        for (short y = 1; y < Y - 1; y++)
        {
            for (short z = 1; z < Z - 1; z++)
            {
                updateCell(tub , x, y, z);
            }
        }
    }
    for (short x = 1; x < X - 1; x++)
    {
        for (short y = 1; y < Y - 1; y++)
        {
            for (short z = 1; z < Z - 1; z++)
            {
                tub[idx(x, y, z)].uPrevTemp(tub[idx(x, y, z)].gTemp());
            }
        }
    }
}

void updateCell(Cell tub[], short x, short y, short z)
{
    double deltaT[6];
    deltaT[0] = tempDiff(tub, x, y, z, x-1, y, z);
    deltaT[1] = tempDiff(tub, x, y, z, x, y-1, z);
    deltaT[2] = tempDiff(tub, x, y, z, x, y, z-1);
    deltaT[3] = tempDiff(tub, x, y, z, x+1, y, z);
    deltaT[4] = tempDiff(tub, x, y, z, x, y+1, z);
    deltaT[5] = tempDiff(tub, x, y, z, x, y, z+1);
    double delT = deltaT[0] + deltaT[1] + deltaT[2] +
    deltaT[3] + deltaT[4] + deltaT[5];
    tub[idx(x, y, z)].uTemp(tub[idx(x, y, z)].gTemp()+delT);
}

double tempDiff(Cell tub[], short x, short y, short z, short xx, short yy, short zz)
{
    long idx1 = idx(x, y, z), idx2 = idx(xx, yy, zz);
    
    if (tub[idx1].gType() != 'w')
    {
        return 0;
    }
    else//tub[idx1].gType == 'w'
    {
        if (tub[idx2].gType() == 'w')
        {
            return tub[idx1].tempDiffW(tub[idx2]);
        }
        else if (tub[idx2].gType() == 'b')
        {
            return tub[idx1].tempDiffB(tub[idx2]);
        }
        else if (tub[idx2].gType() == 's')
        {
            return tub[idx1].tempDiffS(tub[idx2]);
        }
        else //if (tub[idx2].gType() == 'a')
        {
            return tub[idx1].tempDiffA(tub[idx2]);
        }
    }
}

void initialize(Cell tub[])
{
    //Left and right
    for (short x = 0; x < X; x++)
    {
        for (short y = 0; y < Y; y++)
        {
            tub[idx(x, y, 0)].uType('b');
            tub[idx(x, y, 0)].uTemp(ALPHAB);
            tub[idx(x, y, 0)].uPrevTemp(ALPHAB);
            tub[idx(x, y, Z-1)].uType('b');
            tub[idx(x, y, Z-1)].uTemp(ALPHAB);
            tub[idx(x, y, Z-1)].uPrevTemp(ALPHAB);
            //std::cout << "x = " << x << " y = " << y << "\n";
        }
    }
    //Front and back
    for (short y = 0; y < Y; y++)
    {
        for (short z = 0; z < Z; z++)
        {
            tub[idx(0, y, z)].uType('b');
            tub[idx(0, y, z)].uTemp(ALPHAB);
            tub[idx(0, y, z)].uPrevTemp(ALPHAB);
            tub[idx(X-1, y, z)].uType('b');
            tub[idx(X-1, y, z)].uTemp(ALPHAB);
            tub[idx(X-1, y, z)].uPrevTemp(ALPHAB);
        }
    }
    //Up and down
    for (short x = 1; x < X-1; x++)
    {
        for (short z = 1; z < Z-1; z++)
        {
            tub[idx(x, 0, z)].uType('a');
            tub[idx(x, 0, z)].uTemp(ALPHAA);
            tub[idx(x, 0, z)].uPrevTemp(ALPHAA);
            tub[idx(x, Y-1, z)].uType('b');
            tub[idx(x, Y-1, z)].uTemp(ALPHAB);
            tub[idx(x, Y-1, z)].uPrevTemp(ALPHAB);
        }
    }

	// GET BODY
	for (int i = 0; i < X; i++){
		for (int j = 0; j < Y; j++){
			if (pow(i - X / 2.0, 2) + pow(j - Y / 2.0, 2) <=
				pow(fmin(Z / 4.5, Y / 4.5), 2)){
				for (int k = 2; k < Z - 2; k++){
					tub[idx(i, j, k)].uType('s');
					tub[idx(i, j, k)].uTemp(ALPHAS);
					tub[idx(i, j, k)].uPrevTemp(ALPHAS);
				}
			}

		}
	}


	/*
    short xst,xend,yst,yend,zst,zend;
    xst = (double(X)/6.0) * 1;
    xend = (double(X)/6.0) * 5;
    zst = (double(Z)/6.0) * 1;
    zend = (double(Z)/6.0) * 5;
    yst = Y-2;
    yend = (double(X)/5.0) * 2;
    for (short x = xst; x <= xend; x++)
    {
        for (short y = yst; y >= yend; y--)
        {
            for (short z = zst; z <= zend; z++)
            {

                tub[idx(x, y, z)].uType('s');
                tub[idx(x, y, z)].uTemp(ALPHAS);
                tub[idx(x, y, z)].uPrevTemp(ALPHAS);
            }
        }
    }
	*/
}

void addHotWater(Cell tub[])
{
    short xst, xend, yst, yend, zst, zend;
    xst = 1;
    xend = 1;//double(X)/4.0*3;
    yst = 1;
    zend = double(Z)/3.0*2;
    yend = Y-1;
    zst =  Z-1;
    for (short x = xst; x <= xend; x++)
    {
        for (short y = yst; y <= yend; y++)
        {
            for (short z = zst; z >= zend; z--)
            {
                tub[idx(x, y, z)].uTemp(HOTWATERTEMP);
                tub[idx(x, y, z)].uPrevTemp(HOTWATERTEMP);
            }
            
        }
    }
}