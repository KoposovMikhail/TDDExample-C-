#include "LinearEquation.h"
#include<stdexcept>
#include<iostream>
#include<regex>
#include<ctime>
#include<list>
using namespace std;

vector<string> LinearEquation::resplit(const string& s, string rgx_str)
{
	vector<string> elems;
	regex rgx(rgx_str); // regex
	sregex_token_iterator iter(s.begin(), s.end(), rgx, -1);
	sregex_token_iterator end;
	while (iter != end)
	{
		elems.push_back(*iter);
		++iter;
	}
	return elems;
}
LinearEquation::LinearEquation(string _s)  // Инициализация уравнения строкой с коэфф. 
{
	vector<string> s = resplit(_s, "[^\\d-.]");
	for (int i = 0; i < s.size(); i++)
		if (s[i] != "") coefficients.push_back(stod(s[i].c_str()));
}
LinearEquation::LinearEquation(list<double>a)  // Инициализация уравнения списком коэфф.
{
	copy(a.begin(), a.end(), back_inserter(coefficients));
}
LinearEquation::LinearEquation(vector<double>a) // Инициализация уравнения вектором коэфф.
{
	coefficients = a;
}
LinearEquation::LinearEquation(int n) // Конструктор для пустого уравнения с заданным кол-вом переменных
{
	coefficients.resize(n + 1);
}

void LinearEquation::random_initialization() // Инициализация уравнения случайными числами от 0 до 3
{

	for_each(coefficients.begin(), coefficients.end(), [](double& t) {t = (rand() % 3) / 10.0; });
}

void LinearEquation::same_initialization(double value) // Инициализация всех коэффициентов уравнения одним значением
{
	for_each(coefficients.begin(), coefficients.end(), [value](double& t) {t = value; });
}
double& LinearEquation::operator[](int index)  // Обращение к переменным уравнения по индексу
{
	if (index >= 0 && index < coefficients.size())
		return coefficients.at(index);
	else throw std::out_of_range("Out of range!");
}
// Умножение на скаляр слева и справа
LinearEquation LinearEquation::operator*(const double& k) 
{
	vector<double> res = coefficients;
	for_each(res.begin(), res.end(), [k](double& t) {t *= k; });
	return LinearEquation(res);
}

LinearEquation operator*(double k, LinearEquation& a)
{
	return a * k;
}
// Сложение и вычитание двух линейных уравнений
LinearEquation LinearEquation::operator+(LinearEquation& b)
{
	vector<double> res = coefficients;
	for (int i = 0; i < size(); i++)
		res[i] += b[i];
	return LinearEquation(res);
}

LinearEquation LinearEquation::operator-(LinearEquation& b)
{
	vector<double> res = coefficients;
	for (int i = 0; i < size(); i++)
		res[i] -= b[i];
	return LinearEquation(res);
}
// Умножение на -1
LinearEquation LinearEquation::operator-()
{
	vector<double> res = coefficients;
	for_each(res.begin(), res.end(), [](double& t) {t = -t; });
	return LinearEquation(res);
}
LinearEquation::operator string() // ToString
{
	string res = "";
	int i;
	for (i = 0; i < size() - 2; i++)
	{
		res += (coefficients[i + 1] >= 0) ? (to_string(coefficients[i]) + 'x' + to_string((i + 1)) + '+') : (to_string(coefficients[i]) + 'x' + to_string((i + 1)));
	}
	res += (to_string(coefficients[i]) + 'x' + to_string((i + 1)));
	res += '=' + to_string(coefficients[size() - 1]);
	return res;
}
LinearEquation::operator bool() 
{
	for (int i = 0; i < size() - 1; i++)
		if (coefficients[i] != 0) return true;
	return (coefficients[size() - 1] != 0) ? false : true;
}

LinearEquation::operator list<double>() 
{
	list<double> coeff;
	copy(coefficients.begin(), coefficients.end(), back_inserter(coeff));
	return coeff;
}
bool LinearEquation::isNull()
{
	for (int i = 0; i < size(); i++)
		if (coefficients[i] != 0) return false;
	return true;
}
// Перегрузка операторов равенства
bool operator==(LinearEquation& a, LinearEquation& b)
{
	for (int i = 0; i < a.size(); i++) {
		if (abs(a[i] - b[i]) > 1e-9) return false;
	}
	return true;
}
bool operator!=(LinearEquation& a, LinearEquation& b)
{
	if (a == b) return false;
	else return true;
}

