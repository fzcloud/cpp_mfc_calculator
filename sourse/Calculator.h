#pragma once

#include <stack>
#include <vector>
#include <string>

using namespace std;

class Calculator
{
public:
	Calculator();
	void calculator(string infix);
	void getFormat(string infix);
	int getPrior(char c);
	void getPostfix();
	int calResult();
	double getResult();
	string operatorSym;
	int isError;

private:
	vector<string> bckFix;
	stack<char> symStack;
	stack<double> figStack;
	string stdInfix;
	double result;
};