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

unique_ptr<Matrix> Matrix::operator/(Matrix &x)
{
    return *this * (x.getInverse());
}

string Matrix::print(const Matrix &x)
{
    string ans;
    ans += '[';
    for (int i = 0; i < x.r; i++)
    {
        for (int j = 0; j < x.c; j++)
        {
            double num = x.mt[i][j];
            if (fabs(num - floor(num)) < 1e-9)
                ans += to_string((long long)num);
            else
                ans += to_string(num);

            if (i == x.r - 1 && j == x.c - 1)
                ans += ']';
            else if (j == x.c - 1)
                ans += ';';
            else
                ans += ',';
        }
    }
    return ans;
}

void Matrix::getLU()
{
    if(r != c) throw runtime_error(" r != c!!!");
    int n = r;

    low = vector<vector<double>>(r, vector<double>(c, 0));
    up = mt;


    for (int i = 0; i < n; i++)
    {
        int k = i;
        for(int j = i + 1; j < n; j++)
            if(abs(up[j][i]) > abs(up[k][i])) k = j;
        if(abs(up[k][i]) < EPS) 
            throw runtime_error("not exist!!!\n");
        
        if(i != k) 
        {
            swap(up[i], up[k]);
            swap(low[i], low[k]);
        }

        for(int j = i + 1; j < n; j++)
            if(abs(up[j][i]) > EPS)
                low[j][i] = up[j][i] / up[i][i];
        for(int j = i + 1; j < n; j++)
            if(abs(up[j][i]) > EPS)
            {
                for(int k = i + 1; k < n; k++) up[j][k] -= low[j][i] * up[i][k];
                up[j][i] = 0;           
            }
    }
    
    for (int i = 0; i < n; i++)
        low[i][i] = 1;
    
}


int Matrix::getRank()
{

    vector<vector<double>> tmp = mt;
    int rank = 0, row = 0, col = 0;

    while (row < r && col < c)
    {
        int k = row;
        for (int i = row + 1; i < r; i++)
            if (abs(tmp[i][col]) > abs(tmp[k][col]))
                k = i;
        
        if (abs(tmp[k][col]) > EPS)
        {
            swap(tmp[row], tmp[k]);

            for (int i = row + 1; i < r; i++)
            {
                if (abs(tmp[i][col]) > EPS)
                {
                    double mul = tmp[i][col] / tmp[row][col];
                    for (int j = col; j < c; j++)
                        tmp[i][j] -= mul * tmp[row][j];
                }
            }
            rank++;
            row++;
        }
        col++;
    }

    return rank;
}

unique_ptr<Matrix> Matrix::getInverse()
{
    this->getLU();
    
    vector<vector<double>> I(r, vector<double>(c, 0));
    for(int i = 0; i < r; i++) I[i][i] = 1;
    
    auto inv = make_unique<Matrix>(r, c);
    for (int j = 0; j < c; ++j) {
        for (int i = 0; i < r; ++i) {
            double sum = 0;
            for (int k = 0; k < i; ++k)
                sum += low[i][k] * inv->mt[k][j];
            inv->mt[i][j] = I[i][j] - sum;
        }
    }
    
    for (int j = 0; j < c; ++j) {
        for (int i = r - 1; i >= 0; --i) {
            double sum = 0;
            for (int k = i + 1; k < c; ++k)
                sum += up[i][k] * inv->mt[k][j];
            inv->mt[i][j] = (inv->mt[i][j] - sum) / up[i][i];
        }
    }
    return inv;
}

unique_ptr<Double> Matrix::getDet()
{
    this->getLU();
    double det = 1;
    for (int i = 0; i < r; ++i) {
        det *= up[i][i];
    }
    return make_unique<Double>(det);
}

//*-----Matrix end-----

//*-----Double start-----

Double::Double(string &s)
{ // 123.432;
    num = stod(s);
}

Double::Double(double x) : num(x) {}

string Double::getName() const
{
    return "Double";
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
    return make_unique<Double>(abs(x.num));
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

//*------GLOBAL start------

unique_ptr<Matrix> operator*(const Double &x, const Matrix &y)
{
    Matrix res(y.r, y.c);

    for (int i = 0; i < y.r; i++)
        for (int j = 0; j < y.c; j++)
        {
            res.mt[i][j] = x.num * y.mt[i][j];
        }
    return make_unique<Matrix>(res);    
}

unique_ptr<Matrix> operator*(const Matrix &y, const Double &x)
{
    Matrix res(y.r, y.c);

    for (int i = 0; i < y.r; i++)
        for (int j = 0; j < y.c; j++)
        {
            res.mt[i][j] = x.num * y.mt[i][j];
        }
    return make_unique<Matrix>(res);
} // 数乘,全局函数
