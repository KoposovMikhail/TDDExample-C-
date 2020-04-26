#include "Indexer.h"
#include<stdexcept>
#include<exception>
#include <iostream>
using namespace std;

Indexer::Indexer(double* arr, int array_length, int start_ind, int subarray_length)
{
	if (SubArrayCheck(array_length, start_ind, subarray_length)) // Если подмассив с указанными значениями существует
	{
		this->arr = arr;
		this->subarray_length = subarray_length;
		this->start_ind = start_ind;
	}
	else throw invalid_argument("Not supported operation");
}
double& Indexer::operator[](int index)  // Обращение по индексу
{
	if (CheckIndex(index))
		return arr[start_ind + index];
	else throw out_of_range("Not supported operation");
}
bool Indexer::SubArrayCheck(int array_length, int start_ind, int subarray_length) // Проверка на возможность существования указанного подмассива.
{
	if (subarray_length <= 0 || start_ind < 0 || start_ind + subarray_length>array_length) return false;
	else return true;
}
bool Indexer::CheckIndex(int index) // Проверка за выходом за границы подмассива
{
	if (index<0 || index + start_ind>subarray_length) return false;
	else return true;
}
int Indexer::get_sub_length()
{
	return subarray_length;
}