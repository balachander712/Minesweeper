#include <iostream>
#include <time.h>
#include <cstdlib>

using namespace std;


class Board
{

public:
    Board(int mines, int sizex, int sizey);
    ~Board();
    void print();
    char getData(int x, int y);
    void moveToUIF(int x, int y);
    void checkEmptyField(int x, int y);
    int addToMineCount(int x, int y, int& minecount);
    int getGameStatus();

private:

    //MULTIDIMENSIONAL ARRAYS
    char** uif;   //what user sees
    char** data;  //actual data

    const int sizeX;
    const int sizeY;
};

Board::Board(int mines, int sizex, int sizey) : sizeX(sizex), sizeY(sizey)
{

    srand(time(NULL));


    uif = new char* [sizeX];
    data = new char* [sizeX];
    for(int i=0;i<sizeX;i++)
    {
        uif[i] = new char[sizeY];
        data[i] = new char[sizeY];
    }

    for(int y = 0; y < sizeY; y++)
    {
        for(int x = 0; x < sizeX; x++)
        {
            uif[x][y] = '.';
            data[x][y] = '.';
        }
    }


    for(int i = 0; i<mines;i++)
    {
        int x,y;
        while (true)
        {
            x = rand() % sizeX;
            y = rand() % sizeY;
            if(data[x][y] != 'm')
            {
                data[x][y] = 'm';
                break;
            }
        }
        
    }

    //add numbers to data
    for(int y=0; y<sizeY;y++)
    {
        for(int x=0; x<sizeX;x++)
        {
            if(data[x][y] != 'm')
            {
                int minecount = 0;
                //incomplete
                //after defining other functions
            }
        }
    }

}

Board::~Board()
{
	// delete inner arrays
	for(int i = 0; i < sizeY; i++)
	{
		delete[] data[i];
		delete[] uif[i];
	}
	// delete outer arrays
	delete[] data;
	delete[] uif;
}


void Board::print()
{
    cout << endl << "   ";
}