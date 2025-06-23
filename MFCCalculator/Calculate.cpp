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

#define HOLYSHIT1 unique_ptr<Matrix> op1_m; unique_ptr<Double> op1_d;
#define HOLYSHIT2 unique_ptr<Matrix> op2_m; unique_ptr<Double> op2_d;

using ll = long long;

using namespace std;

//�������ȼ�ö��
enum PRIO_LV
{
	PRIO_LV0 = 0,
	PRIO_LV1 = 1,
	PRIO_LV2 = 2,
	PRIO_LV3 = 3,
	PRIO_LV4 = 4,
};

//����ֵ���Ÿ�������ż��
enum ABS_OE {
	ABS_ODD = 1,
	ABS_EVEN = 2,
};

//��ʼ��
Calculator::Calculator()
{
	result = make_unique<Double>(0);
	isError = 0;
}

void Calculator::getSub(unique_ptr<Matrix> &m, unique_ptr<Double> &d)
{
	if (dynamic_cast<Matrix*>(figStack.top().get())) 
	{
		m = getPtr<Matrix>(figStack);
	} 
	else if (dynamic_cast<Double*>(figStack.top().get())) 
	{
		d = getPtr<Double>(figStack);
	} 
	return;
}

//�Զ����׼��ʽ����ʵ�������ￄ1�7
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

}

//��������
void Calculator::calculator(string infix)
{
	getFormat(infix); //����ʽ��ʽ�Զ���ת����ʵ����������
	getPostfix(); //��׺����ʽת��
	isError=calResult(); //������
}

//���ؽ�ￄ1�7
string Calculator::getResult()
{
	string ans;
	if (result)
	{
        if (auto d = dynamic_cast<Double*>(result.get())) 
		{
            ans = Double::print(*d);
        } 
		else if (auto m = dynamic_cast<Matrix*>(result.get())) 
		{
            ans = Matrix::print(*m);
        } 
		else 
		{
            throw ("你看不见我\n");
        }
    }

	return ans;
}

//TODO :霢�要修改，，但我懒得改
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

//������
int Calculator::calResult()
{
	string tmp;

	for (int i = 0;i < bckFix.size();i++)
	{
		tmp = bckFix[i];

		if (tmp[0] >= '0' && tmp[0] <= '9')
		{
			figStack.push(move(make_unique<Double>(tmp)));
		}
		else if (tmp[0] == '[')
		{
			figStack.push(move(make_unique<Matrix>(tmp)));
		}
		else if (bckFix[i] == "+")
		{
			HOLYSHIT1
			HOLYSHIT2
			if (!figStack.empty()) {
				getSub(op2_m, op2_d);
			}
			else return 1;
			if (!figStack.empty()) {
				getSub(op1_m, op1_d);
			}
			else return 1;
			
			if (op1_m && op2_m) 
			{
				figStack.push((*op1_m) + (*op2_m));
			} 
			else if (op1_d && op2_d)
			{
				figStack.push((*op1_d) + (*op2_d));
			}
			else
			{
				throw ("5555\n");
			}
			

		}
		else if (bckFix[i] == "-")
		{
			HOLYSHIT1
			HOLYSHIT2
			if (!figStack.empty()) {
				getSub(op2_m, op2_d);
			}
			else return 1;
			if (!figStack.empty()) {
				getSub(op1_m, op1_d);
			}
			else return 1;
			
			if (op1_m && op2_m) 
			{
				figStack.push((*op1_m) - (*op2_m));
			} 
			else if (op1_d && op2_d)
			{
				figStack.push((*op1_d) - (*op2_d));
			}
			else
			{
				throw ("5555\n");
			}
		}
		else if (bckFix[i] == "*")
		{
			HOLYSHIT1
			HOLYSHIT2
			if (!figStack.empty()) {
				getSub(op2_m, op2_d);
			}
			else return 1;
			if (!figStack.empty()) {
				getSub(op1_m, op1_d);
			}
			else return 1;
			
			if (op1_m && op2_m) 
			{
				figStack.push((*op1_m) * (*op2_m));
			} 
			else if (op1_d && op2_d)
			{
				figStack.push((*op1_d) * (*op2_d));
			}
			else if(op1_d && op2_m)
			{
				figStack.push((*op1_d) * (*op2_m));
			}
			else if(op1_m && op2_d)
			{
				figStack.push((*op1_m) * (*op2_d));
			}
			else
			{
				throw ("5555\n");
			}
			
		}
		else if (bckFix[i] == "/")
		{
			HOLYSHIT1
			HOLYSHIT2
			if (!figStack.empty()) {
				getSub(op2_m, op2_d);
			}
			else return 1;
			if (!figStack.empty()) {
				getSub(op1_m, op1_d);
			}
			else return 1;
			
			if (op1_d && op2_d)
			{
				figStack.push((*op1_d) / (*op2_d));
			}
			else
			{
				throw ("5555\n");
			}
		}
		else if (bckFix[i] == "^")
		{
			HOLYSHIT1
			HOLYSHIT2
			if (!figStack.empty()) {
				getSub(op2_m, op2_d);
			}
			else return 1;
			if (!figStack.empty()) {
				getSub(op1_m, op1_d);
			}
			else return 1;
			
			if (op1_d && op2_d)
			{
				figStack.push((*op1_d) ^ (*op2_d));
			}
			else
			{
				throw ("5555\n");
			}
		}
		else if (bckFix[i] == "|")
		{
			HOLYSHIT1
			if (!figStack.empty()) {
				getSub(op1_m, op1_d);
			}
			else return 1;
			
			if (op1_d)
			{
				figStack.push(Double::abs(*op1_d));
			}
			else
			{
				throw ("5555\n");
			}

		}
		else if (bckFix[i] == "!")
		{
			HOLYSHIT1
			if (!figStack.empty()) {
				getSub(op1_m, op1_d);
			}
			else return 1;
			if(op1_m)
			{
				return 1;
			}

			if (op1_d->num != floor(op1_d->num) || op1_d->num < 0) return 1;

			if (op1_d->num > 0) {
				try {
					op1_d->num=(unsigned long long)safe_factorial((int)op1_d->num);
				}
				catch (overflow_error o) {
					return -1;
				}
			}
			else if (op1_d->num == 0) op1_d->num = 1;
			else return 1;

			figStack.push(move(op1_d));
		}
	}
	if (!figStack.empty())
	{
    if (auto d = dynamic_cast<Double*>(figStack.top().get())) 
	{
        result = make_unique<Double>(*d);
    } 
	else if (auto m = dynamic_cast<Matrix*>(figStack.top().get())) 
	{
        result = make_unique<Matrix>(*m);
    }

	}
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
		case '[':
		
			for(; i < (int)stdInfix.size(); i++)
			{
				tmp += stdInfix[i];
				if(i == (int)stdInfix.size() - 1 && stdInfix[i] != ']')
				{
					throw runtime_error("����ȱ��]");
				}
				
				if(stdInfix[i] == ']')
				{
					bckFix.push_back(tmp);
					break;
				}	
			}//*���Դ����ڲ���double�ľ���
			break;
		

		default:
			if (stdInfix[i] >= '0' && stdInfix[i] <= '9')
			{
				while (i < stdInfix.length() && (stdInfix[i] >= '0' && stdInfix[i] <= '9' || stdInfix[i] == '.'))
				{
					tmp += stdInfix[i];
					i++;
				}
				i--;

				bckFix.push_back(tmp);
			}
			else
			{
				throw runtime_error("�쳣����\n");
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