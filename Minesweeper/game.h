#ifndef GAME_H_INCLUDED
#define GAME_H_INCLUDED

#include "board.h"

class Game
{
public:
	Game(int minecount, int x, int y);
	~Game();
	int update(int x, int y);
private:
	//game board
	Board board;
};

#endif // GAME_H_INCLUDED
