#pragma once
class Indexer
{
private:
	double *arr;
	int start_ind;
	int subarray_length;
	bool SubArrayCheck(int array_length, int start_ind, int subarray_length);
	bool CheckIndex(int index);

public:
	Indexer(double* arr, int array_length, int start_ind, int subarray_length);
	double& operator[] (int index);
	int get_sub_length();
};

