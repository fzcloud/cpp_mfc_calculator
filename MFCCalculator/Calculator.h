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
	int getPrior(char c);
	void getPostfix();
	int calResult();
	string getResult();

	void getSub(unique_ptr<Matrix> &m, unique_ptr<Double> &d);

	template <typename sub>
	unique_ptr<sub> getPtr(stack<unique_ptr<Algebra>> &s)
	{
		unique_ptr<Algebra> fa = move(s.top());
		s.pop();
		sub *check = dynamic_cast<sub*>(fa.get());
		if (!check) 
		{
			throw runtime_error("23333");
		}
		fa.release(); 
		return unique_ptr<sub>(check);
	}
	string operatorSym;
	int isError;
	

private:
	vector<string> bckFix;				 // 后缀表达式
	stack<char> symStack;				 // 临时运算符栈
	stack<unique_ptr<Algebra>> figStack; // 结果栈
	string stdInfix;
	unique_ptr<Algebra> result;
};

extern unordered_map<string, vector<int>> avai_mp1;
extern unordered_map<string, vector<vector<int>>> avai_mp2;

bool avai_1(const unique_ptr<Matrix> &op1_m, const unique_ptr<Double> &op1_d, const string &op);

bool avai_2(const unique_ptr<Matrix> &op1_m, const unique_ptr<Matrix> &op2_m, const unique_ptr<Double> &op1_d, const unique_ptr<Double> &op2_d, const string &op)