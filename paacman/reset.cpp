#include "stdafx.h"

void Reset(int maze[][col], int grid[][col], int monsters, int letter, monster P_B_R[], player& G)
{
	for (int i = 0; i < row; i++)
	{
		for (int j = 0; j < col; j++)
		{
			if (maze[i][j] == 255 || maze[i][j] == 249 || maze[i][j] == 142)
				grid[i][j] = 254;

			else if (i == P_B_R[monsters].x && j == P_B_R[monsters].y)		
				grid[i][j] = letter;										

			else														 
				grid[i][j] = 255;											

			if (i == P_B_R[0].x && j == P_B_R[0].y && monsters != 0 ||		
				i == P_B_R[1].x && j == P_B_R[1].y && monsters != 1 ||
				i == P_B_R[2].x && j == P_B_R[2].y && monsters != 2)
			{
				grid[i][j] = 255;											
			}

			if (i == G.x && j == G.y)										
				grid[i][j] = 0;											
		}
	}

	if (G.x == 24 && G.y == 46)
		grid[12][24] = 255;
}