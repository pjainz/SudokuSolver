#include "Box.h"
#include <iostream>

Box::Box()
	: box(3, vector<int>(3,0))
{
}

Box::~Box() {
}

void Box::writeNum(int num, int row, int col)
{
	box[row][col] = num;
}

int Box::getNum(int row, int col)
{
	return box[row][col];
}

void Box::print(int row)
{
	for(int j=0;j<3;j++)
	{
		cout<< box[row][j] << " ";
	}
}

vector<int> Box::numbersInBox()
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

vector<int> Box::numbersInCol(int colNum)
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

vector<int> Box::numbersInRow(int rowNum)
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
