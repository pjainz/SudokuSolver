#include <iostream>
#include "Board.h"
#include "Box.h"
#include <vector>

using namespace std;

Board::Board()
	: board(3,vector<Box>(3))
{
	//board() = new vector< vector<Box> >(3, vector<Box>(3));

	//board = new vector<vector<Box>(3) >(3);
}

Board::~Board() {
}

void printVec(vector<int> x)
{
	for(int i=0; i<(int)x.size(); i++)
	{
		cout<<x[i];
	}
}

void Board::writeNum(int num, int pos)
{
	int row = pos/9;
	int col = pos%9;
	writeNum(num,row,col);
}

void Board::writeNum(int num, int row, int col)
{
	int boardRow = row/3;
	int boardCol = col/3;
	int boxRow = row%3;
	int boxCol = col%3;

	board[boardRow][boardCol].writeNum(num,boxRow,boxCol);
}

int Board::getNum(int row, int col)
{
	int boardRow = row/3;
	int boardCol = col/3;
	int boxRow = row%3;
	int boxCol = col%3;

	return board[boardRow][boardCol].getNum(boxRow,boxCol);
}

void Board::print()
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

vector<int> Board::concatVectors(vector<int> a, vector<int> b)
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

vector<int> Board::getElligable(int rowNum, int colNum){
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

