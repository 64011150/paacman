#include <iostream>
#include <conio.h>
#include <stdio.h>
#include <ctime>
#include <iomanip>
#include <windows.h>

#include "monsters.h"
#include "G.h"
#include "scores.h"

using namespace std;
#pragma once

const int row = 26;					
const int col = 49;					

enum
{
	clBlack, clNavy, clGreen, clTeal, clBrown,
	clPurple, clOlive, clGray, clSilver, clBlue,
	clLime, clCyan, clRed, clMagneta, clYellow,
	clWhite
};

void Cout_mas(int maze[][col]);	
void Player_G(int maze[][col], int& direction, int& tmp_direction, player& G, bool& eat, monster P_B_R[], bool& stop, bool& exit);				 
void Move(int maze[][col], int turn, player& G, bool& eat, monster P_B_R[], bool& stop);										
void Find_path(int maze[][col], bool& stop, int grid[row][col], int letter, monster P_B_R[], int monsters, player& G, bool& eat);	
void Reset(int maze[][col], int grid[][col], int monsters, int letter, monster P_B_R[], player& G);											
void SetConsoleWinSizePosition(int width, int heigth, short x_position, short y_position);
void SetConsoleCursorPosition(short x_position, short y_position);
void SetConsoleColorTextBackground(unsigned short Tex, unsigned short Bg);
void Absence();
void Random_path(int maze[][col], bool& stop, int grid[row][col], monster P_B_R[], int monsters, int letter, player& G, bool& eat);
void Menu(scores* players, int& size, bool& escape, bool& start, int& difficulty);
void Cout_Scores(scores* players, int size);
void Load_scores(scores*& players, int& size);
void Save_scores(scores* players, int size);