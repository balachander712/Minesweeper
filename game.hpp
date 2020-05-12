#include <iostream>
#include "board.hpp"

using namespace std;

class Game
{
public:
    Game(int minecount,int x, int y);
    ~Game();
    int update(int x, int y);
private:
    Board board;
};

