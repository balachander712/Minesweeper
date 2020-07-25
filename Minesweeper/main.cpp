
#include <iostream>
#include "game.h"
#include <string>
#include <time.h>
#include <fstream>
#include <ctime>

using namespace std;

void getUserInput(int& result, const string message)
{
	cout << message;
	while(!(cin >> result))
	{
		cout << message;
		cin.clear();
		cin.ignore();
	}
}


int main()
{
	int minecount, sizeX, sizeY, x, y, status;
	string turn;
	ofstream fout;
	string name;
	cout << "Enter your name before Playing!!!" << endl;
	cin >> name;
	LEVEL:cout << "1. Easy" << endl;
	cout << "2. Medium" << endl;
	cout << "3. Hard" << endl;
	cout << "4. Custom" << endl;
	int level;
	cout << "Enter the difficulty level";
	cin >> level;
	int total_time;
	int flag = 0;
	if(level == 1)
    {
        Game game(minecount, sizeX, sizeY);
    }
    else if(level == 2)
    {
        Game game(minecount, sizeX, sizeY);
    }
    else if(level == 3)
    {
        Game game(minecount, sizeX, sizeY);
    }
    else if(level == 4)
    {
        getUserInput(sizeX, "Enter board width (3-16): ");
        getUserInput(sizeY, "Enter board height (3-16): ");
        getUserInput(minecount, "Enter the number of mines: ");
        Game game(minecount, sizeX, sizeY);
    }
	else
    {
        cout << "Enter a valid level ";
        goto LEVEL;
    }

	time_t start = time(0);
	// main game loop
	while(true)
	{
		cout << "Enter coords: ";
		cin >> turn;
		if(turn.length() > 2)
		{
			cout << endl << "Too long. 2 coords please." << endl;
			continue;
		}
		// convert char to int
		x = turn[1] - 97;
		y = turn[0] - 97;
		status = game.update(x, y);
		if(status == -1)
		{
            int t = (int) difftime(time(0), start);
			total_time = t;
			cout << endl << "You lost. Press any key to exit" << endl;
			break;
		}
		if(status == 1)
		{
			int t = (int) difftime(time(0), start);
			total_time = t;
			cout << endl << "Congratulations! You won the game in " << t << " seconds." << endl;
			break;
		}
	}

	try
	{
	    fout.open("log/logs.txt",fstream::app);
	    time_t now = time(0);
	    char* dt = ctime(&now);

	    fout << dt << "\t";

	    fout << name << " ";

	    if(flag == 0)
        {
            fout << "Game lost: Played for " << total_time << " seconds." << endl;
        }
        else
        {
            fout << "Game won: Played for " << total_time << " seconds." << endl;

        }
	}
	catch(const ofstream::failure& e)
	{

	}
    fout.close();
	return 0;
}
