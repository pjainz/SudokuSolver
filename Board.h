#ifndef BOARD_H_
#define BOARD_H_
#include <vector>
#include "Box.h"

using namespace std;

class Board
{
	private:
		vector< vector<Box> > board;
		vector<int> concatVectors(vector<int> a, vector<int> b);
	public:
		Board();
		virtual ~Board();
		vector<int> getElligable(int rowNum, int colNum);
		void writeNum(int num, int pos);
		void writeNum(int num, int rowNum, int colNum);
		int getNum(int row, int col);
		void print();
};

#endif /* BOARD_H_ */
