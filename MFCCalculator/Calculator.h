#pragma once

#include "Algebra.h"
#include <stack>
#include <vector>
#include <string>
#include <memory>
#include <stdexcept>



using namespace std;

class Calculator
{
	
public:
	Calculator();
	void calculator(string infix);
	void getFormat(string infix);
	int getPrior(string c); // char -> string
	void getPostfix();
	int calResult();
	string getResult();

	string operatorSym;
	int isError;
	

private:
	vector<string> bckFix;				 // 后缀表达式
	stack<string> symStack;				 // 临时运算符栈 char -> string
	stack<string> figStack; // 结果栈
	string stdInfix;
	string result;
};