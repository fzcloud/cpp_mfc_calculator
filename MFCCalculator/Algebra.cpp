#include "pch.h"
#include "Algebra.h"
#include <vector>
#include <string>
#include <stdexcept>
#include <cmath>
#include <memory>
#include <iomanip>
#include <iostream>
using ll = long long;
using namespace std;

//*-----Matrix start-----

Matrix::Matrix(string &s)
{
    int i = 0, j = 0;
    string tmp;
    mt.push_back(vector<double>());
    for (int k = 1; k < (int)s.size(); k++)
    {
        if (s[k] == ',' || s[k] == ']' || s[k] == ';')
        {
            j++;
            mt[i].push_back(stod(tmp));
            tmp.clear();

            if (s[k] == ']' || s[k] == ';')
            {
                if (i && j != c)
                {
                    throw runtime_error("列数不相等\n");
                }
                c = j;
                i++, j = 0;
                mt.push_back(vector<double>());
            }
        }
        else
        {
            tmp += s[k];
        }
    }
    r = i; //*实际行列数量
}

Matrix::Matrix(int x, int y) : r(x), c(y)
{
    mt = vector<vector<double>>(x, vector<double>(y, 0));
}

string Matrix::getName() const
{
    return "Matrix";
}
bool Matrix::avai(const Algebra &x, char op) const
{
    if(typeid(x) == typeid(Double) && (op == '+' || op == '-'))
        return false;
    
//    if(typeid(x) == typeid(Vect))
 //       return false;//TODO: 下个版本
    
    return true;

    
}
unique_ptr<Matrix> Matrix::trans()
{
    Matrix res(c, r);
    for (int i = 0; i < c; i++)
        for (int j = 0; j < r; j++)
        {
            res.mt[i][j] = mt[j][i];
        }
    return make_unique<Matrix>(res);
}

unique_ptr<Matrix> Matrix::operator+(const Matrix &x)
{
    if (r != x.r || c != x.c)
    {
        throw runtime_error("行列不等!!\n");
    }

    Matrix res(r, c);
    for (int i = 0; i < r; i++)
        for (int j = 0; j < c; j++)
        {
            res.mt[i][j] = mt[i][j] + x.mt[i][j];
        }
    return make_unique<Matrix>(res);
}

// Scalar addition as a global function

unique_ptr<Matrix> Matrix::operator-(const Matrix &x)
{

    if (r != x.r || c != x.c)
    {
        throw runtime_error("行列不等!!\n");
    }

    Matrix res(r, c);
    for (int i = 0; i < r; i++)
        for (int j = 0; j < c; j++)
        {
            res.mt[i][j] = mt[i][j] - x.mt[i][j];
        }
    return make_unique<Matrix>(res);
}




unique_ptr<Matrix> Matrix::operator*(const Matrix &x)
{
    if (c != x.r)
    {
        throw runtime_error("行列不匹配!!\n");
    }

    Matrix res(r, x.c);

    for (int i = 0; i < r; i++)
        for (int j = 0; j < x.c; j++)
        {
            int num = 0;
            for (int k = 0; k < c; k++)
            {
                num += mt[i][k] * x.mt[k][j];
            }
            res.mt[i][j] = num;
        }

    return make_unique<Matrix>(res);
}

unique_ptr<Matrix> Matrix::operator/(const Matrix &x)
{
    throw runtime_error("下个版本再见罢\n");
    return make_unique<Matrix>(0, 0);
}

string Matrix::print(const Matrix &x)
{
    string ans;
    ans += '[';
    for (int i = 0; i < x.r; i++)
        for (int j = 0; j < x.c; j++)
        {
            ans += x.mt[i][j];
            if (i == x.r - 1 && j == x.c - 1)
            {
                ans += ']';
            }
            else if (j == x.c - 1)
            {
                ans += ';';
            }
            else
            {
                ans += ',';
            }
        }
    return ans;
}

//*-----Matrix end-----

//*-----Double start-----

Double::Double(string &s)
{ // 123.432;
    num = stod(s);
}

Double::Double(double x) : num(x)
{
}

string Double::getName() const
{
    return "Double";
}

bool Double::avai(const Algebra &x, char op) const
{
    if(typeid(x) == typeid(Double) && (op == '+' || op == '-'))
        return false;
    
//    if(typeid(x) == typeid(Vect))
//        return false;//TODO: 下个版本
    
    return true;
    
    
}

unique_ptr<Double> Double::operator+(const Double &x)
{
    return make_unique<Double>(num + x.num);
}

unique_ptr<Double> Double::operator-(const Double &x)
{
    return make_unique<Double>(num - x.num);
}

unique_ptr<Double> Double::operator*(const Double &x)
{
    return make_unique<Double>(num * x.num);
}

unique_ptr<Double> Double::operator/(const Double &x)
{
    if (fabs(x.num) < 1e-6)
        throw runtime_error("除数是0");
    return make_unique<Double>(num / x.num);
}

unique_ptr<Double> Double::operator^(const Double &x)
{
    return make_unique<Double>(pow(num, x.num));
}

unique_ptr<Double> Double::abs(const Double &x)
{
    return make_unique<Double>(std::abs(x.num));
}


string Double::print(const Double &x)
{
    if (fabs(x.num - floor(x.num)) < 1e-7)
    {
        return to_string((int)(x.num));
    }
    else 
        return to_string(x.num);
}

//*-----Double end------

//*-----Vect strat------