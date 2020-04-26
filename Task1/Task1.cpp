

#include <iostream>
#include"Indexer.h"
#include <cassert>
using namespace std;
const int n = 2;
int main()
{
	double* tested = new double[n] {30, 35};
	Indexer ind1(tested, 2, 0, 1);
	cout << ind1[0] << endl;
	cout << ind1[1];
}

