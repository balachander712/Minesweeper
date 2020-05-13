#include <iostream>
#include "board.hpp"

using namespace std;

class Game
{
public:
    Game();
    Game(int minecount,int x, int y);
    ~Game();
    int update(int x, int y);
private:
    Board board;
    int sizex;
    int sizey;
};

Game::Game()
{
    sizex = board.sizeX;
    sizey = board.sizeY;
}

Game::Game(int minecount, int x, int y) : board(Board(minecount,sizex,sizey))
{
    board.print();
}

Game::~Game()
{

}

int Game::update(int x,int y)
{
    if(board.getData(x,y) == 'm') 
    {
        return -1;
    }
    else if(board.getData(x,y))
}