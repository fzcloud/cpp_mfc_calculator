#include "pch.h"
#include "Algebra.h"
#include "Calculator.h"

#include <stack>
#include <vector>
#include <iostream>
#include <cmath>
#include <string>
#include <climits>
#include <memory>
#include <stdexcept>
#include <map> // 引入map

using ll = long long;

using namespace std;
// 1Matrix  2Double
// ȼö
enum PRIO_LV
{
	PRIO_LV0 = 0,
	PRIO_LV1 = 1,
	PRIO_LV2 = 2,
	PRIO_LV3 = 3,
	PRIO_LV4 = 4,
	PRIO_LV5 = 5
};

// 运算符优先级
map<string, int> priority = 
{
	{"+", PRIO_LV1}, {"-", PRIO_LV1}, {"*", PRIO_LV2}, 
	{"/", PRIO_LV2}, 
	{"^", PRIO_LV3},
	{"!", PRIO_LV4}, {"|", PRIO_LV4}, 
	{"inv", PRIO_LV5}, {"trans", PRIO_LV5}, {"det", PRIO_LV5}, {"rank", PRIO_LV5}
};

// ֵŸż
enum ABS_OE
{
	ABS_ODD = 1,
	ABS_EVEN = 2,
};

// ��ʼ��
Calculator::Calculator()
{
	result = make_unique<Double>(0);
	isError = 0;
}

// �Զ����׼��ʽ����ʵ�������ￄ1�7
void Calculator::getFormat(string infix)
{
	stdInfix = infix;

	for (size_t i = 0; i < stdInfix.size(); i++)
	{
		if (stdInfix[i] == '+' || stdInfix[i] == '-')
		{
			if (i == 0)
				stdInfix.insert(0, 1, '0');
			else if (stdInfix[i - 1] == '(' || stdInfix[i - 1] == ',')
			{ 
				stdInfix.insert(i, 1, '0');
			}
		}
	}
}

int Calculator::getPrior(string c)
{
	if (priority.count(c))
	{
		return priority[c];
	}
	return PRIO_LV0;
}

//
void Calculator::calculator(string infix)
{
	getFormat(infix);	   // ����ʽ��ʽ�Զ���ت����ʵ����������
	getPostfix();		   // ��׺����ʽת��
	isError = calResult(); // ������
}

// ���ؽ�ￄ1�7
string Calculator::getResult()
{
	string ans;
	if (result)
	{
		if (auto d = dynamic_cast<Double *>(result.get()))
			ans = Double::print(*d);
		else if (auto m = dynamic_cast<Matrix *>(result.get()))
			ans = Matrix::print(*m);
		else
			throw("你看不见我\n");
	}

	return ans;
}

// ������
int Calculator::calResult()
{
	unique_ptr<Algebra> left, right;

	for (const auto &token : bckFix)
	{
		if (token[0] >= '0' && token[0] <= '9')
		{
			figStack.push(make_unique<Double>(token));
		}
		else if (token[0] == '[')
		{
			figStack.push(make_unique<Matrix>(token));
		}
		else if (token == "!" || token == "|" || token == "inv" || token == "trans" || token == "det" || token == "rank")
		{
			if (figStack.size() < 1)
				return 1;
			right = move(figStack.top());
			figStack.pop();
			
			if (token == "!")
				figStack.push(right->getFac());
			else if (token == "|")
				figStack.push(right->getAbs());
			else if (token == "inv")
				figStack.push(right->getInverse());
			else if (token == "trans")
				figStack.push(right->getTrans());
			else if (token == "det")
				figStack.push(right->getDet());
			else if (token == "rank")
				figStack.push(right->getRank());
		}
		else if (token == "+" || token == "-" || token == "*" || token == "/" || token == "^")
		{
			if (figStack.size() < 2)
				return 1;
			right = move(figStack.top());
			figStack.pop();
			left = move(figStack.top());
			figStack.pop();

			if (token == "+")
				figStack.push(*left + *right);
			else if (token == "-")
				figStack.push(*left - *right);
			else if (token == "*")
				figStack.push(*left * *right);
			else if (token == "/")
				figStack.push(*left / *right);
			else if (token == "^")
				figStack.push(left->getPow(*right));
		}
	}
	if (figStack.size() != 1)
		throw runtime_error("unbelivable");

	if (!figStack.empty())
	{
		if (auto d = dynamic_cast<Double *>(figStack.top().get()))
			result = make_unique<Double>(*d);
		else if (auto m = dynamic_cast<Matrix *>(figStack.top().get()))
			result = make_unique<Matrix>(*m);
	}
	return 0;
}
//!-------------------以下必定有bug，没bug我吃------------------------
void Calculator::getPostfix()
{
	bckFix.clear();
	while (!symStack.empty())
		symStack.pop();

	for (size_t i = 0; i < stdInfix.size(); i++)
	{
		string token;
		if (stdInfix[i] == ' ')
			continue;
		else if ((stdInfix[i] >= '0' && stdInfix[i] <= '9') || (stdInfix[i] == '.' && i + 1 < stdInfix.size() && stdInfix[i + 1] >= '0' && stdInfix[i + 1] <= '9'))
		{
			while (i < stdInfix.size() && ((stdInfix[i] >= '0' && stdInfix[i] <= '9') || stdInfix[i] == '.'))
			{
				token += stdInfix[i];
				i++;
			}
			i--;
			bckFix.push_back(token);
		}
		else if (stdInfix[i] == '[')//TODO complex Matrix
		{
			while(i < stdInfix.size() && stdInfix[i] != ']')
			{
				token += stdInfix[i];
				i++;
			}
			token += ']';
			bckFix.push_back(token);
		}
		else if ((stdInfix[i] >= 'a' && stdInfix[i] <= 'z') || (stdInfix[i] >= 'A' && stdInfix[i] <= 'Z'))
		{
			while (i < stdInfix.size() && ((stdInfix[i] >= 'a' && stdInfix[i] <= 'z') || (stdInfix[i] >= 'A' && stdInfix[i] <= 'Z')))
			{
				token += stdInfix[i];
				i++;
			}
			i--;
			if (priority.count(token))
			{
				symStack.push(token);
			}
			else
			{
				throw runtime_error("??????\n");
			}
		}
		else if (stdInfix[i] == '(')
		{
			symStack.push("(");
		}
		else if (stdInfix[i] == ')')
		{
			while (!symStack.empty() && symStack.top() != "(")
			{
				bckFix.push_back(symStack.top());
				symStack.pop();
			}
			if (symStack.empty())
			{
				throw runtime_error("() do not match");
			}
			symStack.pop();
			if (!symStack.empty() && getPrior(symStack.top()) == PRIO_LV5)
			{
				bckFix.push_back(symStack.top());
				symStack.pop();
			}
		}
		else
		{
			token += stdInfix[i];
			if (priority.count(token))
			{
				while (!symStack.empty() && symStack.top() != "(" && getPrior(symStack.top()) >= getPrior(token))
				{
					bckFix.push_back(symStack.top());
					symStack.pop();
				}
				symStack.push(token);
			}
			else
			{
				throw runtime_error("what did you input???\n");
			}
		}
	}

	while (!symStack.empty())
	{
		if (symStack.top() == "(")
			throw runtime_error("() not dmatch");
		bckFix.push_back(symStack.top());
		symStack.pop();
	}
}