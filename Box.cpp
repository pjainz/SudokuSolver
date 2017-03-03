#include "Box.h"
#include <iostream>

Box::Box() // constructs box, which is the 3x3 pieces of the board
	: box(3, vector<int>(3,0))
{
}

Box::~Box() {} // destructor

void Box::writeNum(int num, int row, int col) // writes number in specified cell
{
	box[row][col] = num;
}

int Box::getNum(int row, int col)// gets number from specified cell
{
	return box[row][col];
}

void Box::print(int row) // prints the box in console
{
	for(int j=0;j<3;j++)
	{
		cout<< box[row][j] << " ";
	}
}

vector<int> Box::numbersInBox() // returns an array of numbers contained in the box
{
	vector<int> nums(9,0);
	for(int i = 0; i<3; i++)
	{
		for (int j = 0; j<3; j++)
		{
			int currNum = box[i][j];
			if(currNum>0)
				nums[currNum-1] = currNum;
		}
	}
	return nums;
}

vector<int> Box::numbersInCol(int colNum) // returns numbers in a specified column in a box
{
	vector<int> nums(9,0);
	for (int i = 0; i<3; i++)
	{
		int currNum = box[i][colNum];
		if(currNum>0)
			nums[currNum-1] = currNum;
	}

	return nums;
}

vector<int> Box::numbersInRow(int rowNum)  // returns numbers in a specified row in a box
{
	vector<int> nums(9,0);
	for (int j = 0; j<3; j++)
	{
		int currNum = box[rowNum][j];
		if(currNum>0)
			nums[currNum-1] = currNum;
	}

	return nums;
}
