#include <iostream>
#include <time.h>
#include <cstdlib>

using namespace std;


class Board
{

public:
    Board();
    Board(int mines, int sizex, int sizey);
    ~Board();
    void print();
    char getData(int x, int y);
    void moveToUIF(int x, int y);
    void checkEmptyField(int x, int y);
    int addToMineCount(int x, int y, int& minecount);
    int getGameStatus();

     int sizeX;
     int sizeY;

private:

    //MULTIDIMENSIONAL ARRAYS
    char** uif;   //what user sees
    char** data;  //actual data

};

Board::Board()
{
    sizeX = 0;
    sizeY = 0;

}


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

    for(int i=0; i< sizeX;i++)
    {
        cout << (char)(97+i);
    }

    cout << endl << endl;


    for(int y=0; y < sizeY; y++)
    {
        cout << (char)(97+y)<<" ";

        for(int x=0; x<sizeX; x++)
        {
            cout << uif[x][y];
        }
        cout << endl;

    }
    cout << endl;
}

char Board::getData(int x, int y)
{
    if(x < sizeX && y < sizeY && x >= 0 && y >= 0)
    {
        return data[x][y];
    }

    return 'o';
}

void Board::moveToUIF(int x, int y)
{
    uif[x][y] = data[x][y];
}

void Board::checkEmptyField(int x, int y)
{
    //incomplete
}


int Board::addToMineCount(int x, int y, int& minecount)
{
    if(x>=0 && x < sizeX && y>=0 && y < sizeY)
    {
        if(data[x][y] == 'm')
            minecount++;
    }
    return 0;
}

int Board::getGameStatus()
{
    //incomplete
}

