#include <fstream>
#include <iostream>
#include <vector>
#include "Board.h"

using namespace std;

bool tileSol(Board &board, int rowNum, int colNum);


bool tryNext(Board &board, int rowNum, int colNum)
{
	int nextRow=rowNum, nextCol=colNum;
	if (colNum < 8)
		nextCol = colNum+1;
	else
	{
		if(rowNum < 8)
		{
			nextRow = rowNum+1;
			nextCol = 0;
		}
		else
			return true;
	}
	return tileSol(board,nextRow, nextCol);
}

bool tileSol(Board &board, int rowNum, int colNum)
{
	vector<int>elligNums;
	if(board.getNum(rowNum,colNum)==0) //checks if cell is empty
	{
		elligNums = board.getElligable(rowNum,colNum);

		int sum = 0;

		for(int i = 0; i <9; i++) //checks if ellig is empty
		{
			sum += elligNums[i];
		}
		if(sum == 0)
			return false;

		for(int i = 0; i <9; i++)
		{
			if(elligNums[i] !=0)
			{
				board.writeNum(elligNums[i],rowNum,colNum);
				if(tryNext(board,rowNum,colNum))
					return true;
				else
					board.writeNum(0,rowNum,colNum);
			}
		}
		return false;
	}
	return tryNext(board, rowNum, colNum);

}


int main ()
{
	ifstream infile("sudokuboard.txt");
	if(infile.fail())
	{
		cerr<< "Unable to open Sudoku Board";
		return 0;
	}
	int currNum, pos=0;
	Board board;

	for(int row = 0; row < 9; row++) //inserts the numbers
	{
		for(int col = 0; col < 9; col++)
		{
			infile >> currNum;
			if(currNum<10 && currNum>=0)
				board.writeNum(currNum,pos);
			else
			{
				cout<< "Numbers must be single digit positive integers. Program Terminated" << endl;
				return 0;

			}
			pos++;
		}
	}
	cout << "Solving the following puzzle: " << endl;
	board.print();
	cout << endl;
	if(tileSol(board,0,0))
	{
		cout << "Solution: " << endl;
		board.print();
	}
	else
		cout << "Cannot solve this puzzle, double check your input";
	cout << endl;
}

