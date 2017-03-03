#ifndef BOX_H_
#define BOX_H_
#include <vector>

using namespace std;

class Box
{
	private:
		vector< vector<int> > box;
	public:
		Box();
		virtual ~Box();
		vector<int> numbersInCol(int col);
		vector<int> numbersInRow(int row);
		vector<int> numbersInBox();
		void writeNum(int num, int row,int col);
		int getNum(int row, int col);
		void print(int row);
};

#endif /* BOX_H_ */
