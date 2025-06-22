#include "pch.h"
#include "Calculator.h"

#include <stack>
#include <vector>
#include <iostream>
#include <cmath>
#include <string>
#include <climits>

using namespace std;

//符号优先级枚举
enum PRIO_LV
{
	PRIO_LV0 = 0,
	PRIO_LV1 = 1,
	PRIO_LV2 = 2,
	PRIO_LV3 = 3,
	PRIO_LV4 = 4,
};

//绝对值符号个数的奇偶性
enum ABS_OE {
	ABS_ODD = 1,
	ABS_EVEN = 2,
};

//初始化
Calculator::Calculator()
{
	result = 0.0;
	isError = 0;
}

//自定义标准格式化，实现正负数
void Calculator::getFormat(string infix)
{
	stdInfix = infix;

	for (size_t i = 0;i < stdInfix.size();i++)
	{
		if (stdInfix[i] == '+' || stdInfix[i] == '-')
		{
			if (i == 0) stdInfix.insert(0, 1, '0');
			else if (stdInfix[i - 1] == '(') {
				stdInfix.insert(i, 1, '0');
			}
		}
		
		
	}
 
}

int Calculator::getPrior(char c)
{
	if (c == '+' || c == '-') return PRIO_LV1;
	else if (c == '*' || c == '/') return PRIO_LV2;
	else if (c == '^') return PRIO_LV3;
	else if (c == '!') return PRIO_LV4;
	else return PRIO_LV0;

	string str = "非法符号";
	cout << str << endl;
}

//计算流程
void Calculator::calculator(string infix)
{
	getFormat(infix); //表达式格式自定义转化（实现正负数）
	getPostfix(); //后缀表达式转换
	isError=calResult(); //计算结果
}

//返回结果
double Calculator::getResult()
{
	return result;
}

//阶乘（预判溢出）
unsigned long long safe_factorial(int n)
{
	unsigned long long result = 1;
	for (int i = 1;i <= n;i++) {
		if (result > ULLONG_MAX / i)
		{
			throw std::overflow_error("");
		}
		result *= i;
	}
	return result;
}

//计算结果
int Calculator::calResult()
{
	string tmp;
	double num=0,op1=0,op2=0;

	for (int i = 0;i < bckFix.size();i++)
	{
		tmp = bckFix[i];

		if (tmp[0] >= '0' && tmp[0] <= '9')
		{
			num = atof(tmp.c_str());
			figStack.push(num);
		}
		else if (bckFix[i] == "+")
		{
			if (!figStack.empty()) {
				op2 = figStack.top();
				figStack.pop();
			}
			else return 1;
			if (!figStack.empty()) {
				op1 = figStack.top();
				figStack.pop();
			}
			else return 1;

			figStack.push(op1 + op2);
		}
		else if (bckFix[i] == "-")
		{
			if (!figStack.empty()) {
				op2 = figStack.top();
				figStack.pop();
			}
			else return 1;
			if (!figStack.empty()) {
				op1 = figStack.top();
				figStack.pop();
			}
			else return 1;

			figStack.push(op1 - op2);
		}
		else if (bckFix[i] == "*")
		{
			if (!figStack.empty()) {
				op2 = figStack.top();
				figStack.pop();
			}
			else return 1;
			if (!figStack.empty()) {
				op1 = figStack.top();
				figStack.pop();
			}
			else return 1;

			figStack.push(op1 * op2);
		}
		else if (bckFix[i] == "/")
		{
			if (!figStack.empty()) {
				op2 = figStack.top();
				figStack.pop();
			}
			else return 1;
			if (!figStack.empty()) {
				op1 = figStack.top();
				figStack.pop();
			}
			else return 1;
			if (op2 == 0) return 1;

			figStack.push(op1 / op2);
		}
		else if (bckFix[i] == "^")
		{
			if (!figStack.empty()) {
				op2 = figStack.top();
				figStack.pop();
			}
			else return 1;
			if (!figStack.empty()) {
				op1 = figStack.top();
				figStack.pop();
			}
			else return 1;

			figStack.push(pow(op1,op2));
		}
		else if (bckFix[i] == "|")
		{
			if (!figStack.empty()) {
				op1 = figStack.top();
				figStack.pop();
			}
			else return 1;

			figStack.push(abs(op1));
		}
		else if (bckFix[i] == "!")
		{
			if (!figStack.empty()) {
				op1 = figStack.top();
				figStack.pop();
			}
			else return 1;

			if (op1 != floor(op1) || op1 < 0) return 0;

			if (op1 > 0) {
				try {
					op1=(unsigned long long)safe_factorial((int)op1);
				}
				catch (overflow_error o) {
					return -1;
				}
			}
			else if (op1 == 0) op1 = 1;
			else return 1;

			figStack.push((double)op1);
		}
	}
	if (!figStack.empty()) result = figStack.top();
	return 0;
}

void Calculator::getPostfix()
{
	int absNum = ABS_ODD;
	string tmp;

	for (size_t i = 0;i < stdInfix.size();i++)
	{
		tmp = "";
		switch (stdInfix[i])
		{
		case '+':
		case '-':
		case '*':
		case '/':
		case '^':
		case '!':
			if (symStack.empty() || symStack.top() == '(' || (symStack.top() == '|' && absNum == ABS_ODD))
				symStack.push(stdInfix[i]);
			else {
				while (!symStack.empty() && (getPrior(symStack.top()) >= getPrior(stdInfix[i])))
				{
					tmp += symStack.top();
					bckFix.push_back(tmp);
					symStack.pop();
					tmp = "";
				}
				symStack.push(stdInfix[i]);
			}
			break;
		case '|':
			if (absNum == ABS_ODD)
			{
				symStack.push(stdInfix[i]);
				absNum = ABS_EVEN;

				if (i < stdInfix.length() && (stdInfix[i + 1] == '+' || stdInfix[i + 1] == '-'))
				{
					stdInfix.insert(i + 1, 1, '0');
				}
			}
			else {
				while (!symStack.empty() && symStack.top() != '|') {
					tmp += symStack.top();
					bckFix.push_back(tmp);
					symStack.pop();
					tmp = "";
				}

				if (!symStack.empty() && symStack.top() == '|')
				{
					tmp += symStack.top();
					bckFix.push_back(tmp);
					symStack.pop();
					absNum = ABS_ODD;
				}
				break;
			}
		case '(':
			symStack.push(stdInfix[i]);
			break;
		case ')':
			while (!symStack.empty() && symStack.top() != '(')
			{
				tmp += symStack.top();
				bckFix.push_back(tmp);
				symStack.pop();
				tmp = "";
			}
			if (!symStack.empty() && symStack.top() == '(')
			{
				symStack.pop();
			}
			break;

		default:
			if (stdInfix[i] >= '0' && stdInfix[i] <= '9')
			{
				tmp += stdInfix[i];
				while (i + 1 < stdInfix.length() && (stdInfix[i + 1] >= '0' && stdInfix[i + 1] <= '9' || stdInfix[i + 1] == '.'))
				{
					tmp += stdInfix[i + 1];
					i++;
				}
				if (tmp[tmp.length() - 1] == '.') tmp += '0';

				bckFix.push_back(tmp);
			}
			break;
		}
	}

	while (!symStack.empty())
	{
		tmp = "";
		tmp += symStack.top();
		bckFix.push_back(tmp);
		symStack.pop();
		
	}
}