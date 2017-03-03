#include <iostream>
#include "Board.h"
#include "Box.h"
#include <vector>

using namespace std;

Board::Board()  //constructor
	: board(3,vector<Box>(3))
{}

Board::~Board() {} // destructor

void Board::writeNum(int num, int pos) //used to fill the original board
{
	int row = pos/9;
	int col = pos%9;
	writeNum(num,row,col);
}

void Board::writeNum(int num, int row, int col) //used to fill guesses into the empty cells
{
	int boardRow = row/3;
	int boardCol = col/3;
	int boxRow = row%3;
	int boxCol = col%3;

	board[boardRow][boardCol].writeNum(num,boxRow,boxCol);
}

int Board::getNum(int row, int col) //returns number in specific cell
{
	int boardRow = row/3;
	int boardCol = col/3;
	int boxRow = row%3;
	int boxCol = col%3;

	return board[boardRow][boardCol].getNum(boxRow,boxCol);
}

void Board::print() //prints the whole board
{
	for(int k = 0; k<3; k++)
	{
		for(int j = 0; j <3; j++)
		{
			for(int i = 0; i <3; i++)
			{
				board[k][i].print(j);
			}
			cout<< endl;
		}
	}
}

vector<int> Board::concatVectors(vector<int> a, vector<int> b) //combines the vectors without changing the final vectors size
{
	vector<int>returnVector = a;
	for(int i = 0; i<(int)b.size(); i++)
	{
		int currNum = b[i];
		if(currNum>0)
			returnVector[currNum-1] = currNum;
	}
	return returnVector;
}

vector<int> Board::getElligable(int rowNum, int colNum) // gets the elligable numbers for a certain empty cell
{
	vector<int> boxBadNums(9,0);
	vector<int> rowBadNums(9,0);
	vector<int> colBadNums(9,0);
	vector<int> tempBadNums;
	vector<int> allBadNums;
	vector<int> elligableNums(9,0);

	int boardRow = rowNum/3;
	int boardCol = colNum/3;
	int boxRow = rowNum%3;
	int boxCol = colNum%3;
	Box currBox = board[boardRow][boardCol];
	boxBadNums = currBox.numbersInBox();

	for(int i = 0; i<3; i++)
	{
		currBox = board[boardRow][i];
		rowBadNums = concatVectors(rowBadNums,currBox.numbersInRow(boxRow));
	}

	for(int i = 0; i<3; i++)
	{
		currBox = board[i][boardCol];
		colBadNums = concatVectors(colBadNums,currBox.numbersInCol(boxCol));
	}

	tempBadNums = concatVectors(boxBadNums, rowBadNums);

	allBadNums = concatVectors(colBadNums,tempBadNums);

	for(int i=0; i <9; i++)
	{
		if(allBadNums[i]==0)
			elligableNums[i] = i+1;
	}

	return elligableNums;
}

