#include <iostream>
#include <time.h>
#include <windows.h>
using namespace std;

int main()
{
	HANDLE hwnd = GetStdHandle(STD_OUTPUT_HANDLE);
	srand(time(0));

	// chess board creation - OK
	const int BOARD_SIZE = 6;
	int board[BOARD_SIZE][BOARD_SIZE] = {};
	
	// movement selection - OK
	const int MAX_MOVE_VAR = 8;
	int moveVar[2][MAX_MOVE_VAR] =
	{
		{ -2, -2, -1, -1,  1,  1,  2, 2 },
		{ -1,  1, -2,  2, -2,  2, -1, 1 }
	};

	// moving horse
	int currentY = rand() % BOARD_SIZE;
	int currentX = rand() % BOARD_SIZE;
	int moveCounter = 1;
	board[currentY][currentX] = moveCounter;
	int selectMove = 0, reversedSelectMove;
	int faultY = -1, faultX = -1;

	do 
	{		
		if (currentY + moveVar[0][selectMove] < BOARD_SIZE && currentX + moveVar[1][selectMove] < BOARD_SIZE && currentY + moveVar[0][selectMove] >= 0 && currentX + moveVar[1][selectMove] >= 0 && board[currentY + moveVar[0][selectMove]][currentX + moveVar[1][selectMove]] == 0 && selectMove < MAX_MOVE_VAR)
		{
			currentY += moveVar[0][selectMove];
			currentX += moveVar[1][selectMove];
			moveCounter++;
			board[currentY][currentX] = moveCounter;
			selectMove = 0;
			if(faultY != -1 && faultX != -1)
				board[faultY][faultX] = 0;
		}
		else if ((currentY + moveVar[0][selectMove] >= BOARD_SIZE || currentX + moveVar[1][selectMove] >= BOARD_SIZE || currentY + moveVar[0][selectMove] < 0 || currentX + moveVar[1][selectMove] < 0 || board[currentY + moveVar[0][selectMove]][currentX + moveVar[1][selectMove]] != 0) && selectMove < MAX_MOVE_VAR - 1)
		{
			selectMove++;
		}
		else if (selectMove == MAX_MOVE_VAR - 1)
		{
			reversedSelectMove = selectMove;
			board[currentY][currentX] = -1;
			while (board[currentY + moveVar[0][reversedSelectMove]][currentX + moveVar[1][reversedSelectMove]] != moveCounter - 1)
			{
				reversedSelectMove--;
			}
			board[faultY][faultX] = 0;

			faultY = currentY;
			faultX = currentX;

			currentY += moveVar[0][reversedSelectMove];
			currentX += moveVar[1][reversedSelectMove];
			moveCounter--;
			selectMove = 0;
		}
	} while (moveCounter != BOARD_SIZE * BOARD_SIZE);					
	// chess board output - OK
	for (int y = 0; y < BOARD_SIZE; y++)
	{
		for (int x = 0; x < BOARD_SIZE; x++)
		{
			if (board[y][x] != 0)
			{
				SetConsoleTextAttribute(hwnd, FOREGROUND_GREEN | FOREGROUND_INTENSITY);
				cout << board[y][x] << "\t";
			}
			else
			{
				SetConsoleTextAttribute(hwnd, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
				cout << board[y][x] << "\t";
			}
		}
		cout << endl << endl << endl;
	}
	return 0;
}