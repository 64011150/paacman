#include "stdafx.h"

void Find_path(int maze[][col], bool& stop, int grid[row][col], int letter, monster P_B_R[], int monsters, player& G, bool& eat)
{
	int Ni = 0;					
	const int Nk = 64;			 
	bool chek = false;			

	do {
		for (int i = 0; i < row; i++)			
		{
			for (int j = 0; j < col; j++)
			{
				if (grid[i][j] == Ni)
				{
					if (i - 1 >= 0 && j - 1 >= 0) {
						if (i + 1 == P_B_R[monsters].x && j == P_B_R[monsters].y || i - 1 == P_B_R[monsters].x && j == P_B_R[monsters].y || i == P_B_R[monsters].x && j + 1 == P_B_R[monsters].y || i == P_B_R[monsters].x && j - 1 == P_B_R[monsters].y)  
						{
							chek = true;
							break;
						}
						if (grid[i + 1][j] == 254)
							grid[i + 1][j] = Ni + 1;

						if (grid[i - 1][j] == 254 && i - 1 >= 0)
							grid[i - 1][j] = Ni + 1;

						if (grid[i][j + 1] == 254)
							grid[i][j + 1] = Ni + 1;

						if (grid[i][j - 1] == 254 && j - 1 >= 0)
							grid[i][j - 1] = Ni + 1;
					}
				}
			}
			if (chek == true)
				break;
		}

		Ni += 1;						

		if (Ni > Nk)					
		{
			Random_path(maze, stop, grid, P_B_R, monsters, letter, G, eat);
			return;
		}
	} while (chek == false);			


	int x = P_B_R[monsters].x;		
	int y = P_B_R[monsters].y;

	if (grid[x + 1][y] < grid[x][y])	
	{
		P_B_R[monsters].x = x + 1;
		P_B_R[monsters].y = y;
	}
	if (grid[x - 1][y] < grid[x][y])
	{
		P_B_R[monsters].x = x - 1;
		P_B_R[monsters].y = y;
	}
	if (grid[x][y + 1] < grid[x][y])
	{
		P_B_R[monsters].x = x;
		P_B_R[monsters].y = y + 2;
	}
	if (grid[x][y - 1] < grid[x][y])
	{
		P_B_R[monsters].x = x;
		P_B_R[monsters].y = y - 2;
	}
	SetConsoleCursorPosition(y, x);

	switch (monsters)
	{
	case (0):
		if (eat == false)
			SetConsoleColorTextBackground(clMagneta, clBlack);
		else
			SetConsoleColorTextBackground(clWhite, clBlack);
		break;
	case (1):
		if (eat == false)
			SetConsoleColorTextBackground(clRed, clBlack);
		else
			SetConsoleColorTextBackground(clWhite, clBlack);
		break;
	case (2):
		if (eat == false)
			SetConsoleColorTextBackground(clCyan, clBlack);
		else
			SetConsoleColorTextBackground(clWhite, clBlack);
		break;
	}

	printf_s("%c", letter);
	SetConsoleCursorPosition(y, x);
	SetConsoleColorTextBackground(clYellow, clBlack);

	if (maze[x][y] == 142)
		SetConsoleColorTextBackground(clWhite, clBlack);

	printf_s("%c", maze[x][y]);
	
	SetConsoleCursorPosition(P_B_R[monsters].y, P_B_R[monsters].x);

	switch (monsters)
	{
	case (0):
		if (eat == false)
			SetConsoleColorTextBackground(clMagneta, clBlack);
		else
			SetConsoleColorTextBackground(clWhite, clBlack);
		break;
	case (1):
		if (eat == false)
			SetConsoleColorTextBackground(clRed, clBlack);
		else
			SetConsoleColorTextBackground(clWhite, clBlack);
		break;
	case (2):
		if (eat == false)
			SetConsoleColorTextBackground(clCyan, clBlack);
		else
			SetConsoleColorTextBackground(clWhite, clBlack);
		break;
	}

	printf_s("%c", letter);
	if (P_B_R[monsters].x == G.x && P_B_R[monsters].y == G.y)	
	{
		if (eat == false)
		{
			stop = true;										
			return;
		}
		else
		{
			switch (monsters)
			{
			case (0):
				P_B_R[monsters].x = 14;
				P_B_R[monsters].y = 24;
				break;
			case (1):
				P_B_R[monsters].x = 14;
				P_B_R[monsters].y = 20;
				break;
			case (2):
				P_B_R[monsters].x = 14;
				P_B_R[monsters].y = 28;
				break;
			}
		}
	}
}