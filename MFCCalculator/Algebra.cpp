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

//*-------Algebra start-------

unique_ptr<Algebra> Algebra::operator+(const Algebra &x) const
{
    throw runtime_error("错误\n");
}

unique_ptr<Algebra> Algebra::addTo(const Matrix &x) const
{
    throw runtime_error("错误\n");
}

unique_ptr<Algebra> Algebra::addTo(const Double &x) const
{
    throw runtime_error("错误\n");
}

unique_ptr<Algebra> Algebra::operator-(const Algebra &x) const
{
    throw runtime_error("错误\n");
}

unique_ptr<Algebra> Algebra::subTo(const Matrix &x) const
{
    throw runtime_error("错误\n");
}

unique_ptr<Algebra> Algebra::subTo(const Double &x) const
{
    throw runtime_error("错误\n");
}

unique_ptr<Algebra> Algebra::operator*(const Algebra &x) const
{
    throw runtime_error("错误\n");
}

unique_ptr<Algebra> Algebra::mulTo(const Matrix &x) const
{
    throw runtime_error("错误\n");
}

unique_ptr<Algebra> Algebra::mulTo(const Double &x) const
{
    throw runtime_error("错误\n");
}

unique_ptr<Algebra> Algebra::operator/(const Algebra &x) const
{
    throw runtime_error("错误\n");
}

unique_ptr<Algebra> Algebra::divTo(const Matrix &x) const
{
    throw runtime_error("错误\n");
}

unique_ptr<Algebra> Algebra::divTo(const Double &x) const
{
    throw runtime_error("错误\n");
}

unique_ptr<Algebra> Algebra::getPow(const Algebra &x) const
{
    throw runtime_error("错误\n");
}

unique_ptr<Algebra> Algebra::powTo(const Double &x) const
{
    throw runtime_error("错误\n");
}

unique_ptr<Algebra> Algebra::powTo(const Matrix &x) const
{
    throw runtime_error("错误\n");
}

unique_ptr<Algebra> Algebra::getRank() const
{
    throw runtime_error("错误\n");
}

unique_ptr<Algebra> Algebra::getDet() const
{
    throw runtime_error("错误\n");
}

unique_ptr<Algebra> Algebra::getInverse() const
{
    throw runtime_error("错误\n");
}

unique_ptr<Algebra> Algebra::getTrans() const
{
    throw runtime_error("错误\n");
}

unique_ptr<Algebra> Algebra::getAbs() const
{
    throw runtime_error("错误\n");
}
unique_ptr<Algebra> Algebra::getFac() const
{
    throw runtime_error("错误\n");
}

//*-------Algebra end-------

//*-----Matrix start-----

Matrix::Matrix(const string &s)
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

unique_ptr<Algebra> Matrix::getTrans() const
{
    Matrix res(c, r);
    for (int i = 0; i < c; i++)
        for (int j = 0; j < r; j++)
        {
            res.mt[i][j] = mt[j][i];
        }
    return make_unique<Matrix>(res);
}

unique_ptr<Algebra> Matrix::operator+(const Algebra &x) const
{
    return x.addTo(*this);
}

unique_ptr<Algebra> Matrix::addTo(const Matrix &x) const
{
    if (r != x.r || c != x.c)
    {
        throw runtime_error("行列数不相等\n");
    }

    Matrix res(r, c);
    for (int i = 0; i < r; i++)
        for (int j = 0; j < c; j++)
        {
            res.mt[i][j] = mt[i][j] + x.mt[i][j];
        }
    return make_unique<Matrix>(res);
}

unique_ptr<Algebra> Matrix::operator-(const Algebra &x) const
{
    return x.subTo(*this);
}

unique_ptr<Algebra> Matrix::subTo(const Matrix &x) const
{

    if (r != x.r || c != x.c)
    {
        throw runtime_error("行列数不相等\n");
    }

    Matrix res(r, c);
    for (int i = 0; i < r; i++)
        for (int j = 0; j < c; j++)
        {
            res.mt[i][j] = x.mt[i][j] - mt[i][j];
        }
    return make_unique<Matrix>(res);
}

unique_ptr<Algebra> Matrix::operator*(const Algebra &x) const
{
    return x.mulTo(*this);
}

unique_ptr<Algebra> Matrix::mulTo(const Matrix &x) const //! x left  *this right
{
    if (x.c != r)
    {
        throw runtime_error("行列数不相等\n");
    }

    Matrix res(x.r, c);

    for (int i = 0; i < x.r; i++)
        for (int j = 0; j < c; j++)
            for (int k = 0; k < x.c; k++)
                res.mt[i][j] += x.mt[i][k] * mt[k][j];

    return make_unique<Matrix>(res);
}

unique_ptr<Algebra> Matrix::mulTo(const Double &x) const
{
    Matrix res(r, c);

    for (int i = 0; i < r; i++)
        for (int j = 0; j < c; j++)
        {
            res.mt[i][j] = x.num * mt[i][j];
        }
    return make_unique<Matrix>(res);
}

unique_ptr<Algebra> Matrix::operator/(const Algebra &x) const
{
    return x.divTo(*this);
}

unique_ptr<Algebra> Matrix::getPow(const Algebra &x) const
{
    return x.powTo(*this);
}

unique_ptr<Algebra> Matrix::divTo(const Matrix &x) const
{
    return x * (*static_cast<Matrix *>((this->getInverse()).get())); //! must be basic intelleience point
}

string Matrix::print(const Matrix &x)
{
    string ans;
    for (int i = 0; i < x.r; i++)
    {
        ans += "|";
        for (int j = 0; j < x.c; j++)
        {
            double num = x.mt[i][j];
                ans += to_string(num);
            ans += "  ";
        }
        if(!ans.empty())
            ans.pop_back();
        ans +=  "|";
        ans += "\n"; 
    }
    return ans;
}

void Matrix::getLU(vector<vector<double>> &low, vector<vector<double>> &up) const
{
    if (r != c)
        throw runtime_error("行列数不相等");
    int n = r;

    low = vector<vector<double>>(r, vector<double>(c, 0));
    up = mt;

    for (int i = 0; i < n; i++)
    {
        int k = i;
        for (int j = i + 1; j < n; j++)
            if (abs(up[j][i]) > abs(up[k][i]))
                k = j;
        if (abs(up[k][i]) < EPS)
            throw runtime_error("不存在\n");

        if (i != k)
        {
            swap(up[i], up[k]);
            swap(low[i], low[k]);
        }

        for (int j = i + 1; j < n; j++)
            if (abs(up[j][i]) > EPS)
                low[j][i] = up[j][i] / up[i][i];
        for (int j = i + 1; j < n; j++)
            if (abs(up[j][i]) > EPS)
            {




                for (int k = i + 1; k < n; k++)
                    up[j][k] -= low[j][i] * up[i][k];
                up[j][i] = 0;
            }
    }

    for (int i = 0; i < n; i++)
        low[i][i] = 1;
}

unique_ptr<Algebra> Matrix::getRank() const
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

    return make_unique<Double>(static_cast<double>(rank));
}

unique_ptr<Algebra> Matrix::getInverse() const
{
    vector<vector<double>> low, up;
    this->getLU(low, up);

    vector<vector<double>> I(r, vector<double>(c, 0));
    for (int i = 0; i < r; i++)
        I[i][i] = 1;

    Matrix inv(r, c);
    for (int j = 0; j < c; ++j)
    {
        for (int i = 0; i < r; ++i)
        {
            double sum = 0;
            for (int k = 0; k < i; ++k)
                sum += low[i][k] * inv.mt[k][j];
            inv.mt[i][j] = I[i][j] - sum;
        }
    }

    for (int j = 0; j < c; ++j)
    {
        for (int i = r - 1; i >= 0; --i)
        {
            double sum = 0;
            for (int k = i + 1; k < c; ++k)
                sum += up[i][k] * inv.mt[k][j];
            inv.mt[i][j] = (inv.mt[i][j] - sum) / up[i][i];
        }
    }
    return make_unique<Matrix>(inv);
}

unique_ptr<Algebra> Matrix::getDet() const
{
    vector<vector<double>> low, up;
    this->getLU(low, up);
    double det = 1;
    for (int i = 0; i < r; ++i)
    {
        det *= up[i][i];
    }
    return make_unique<Double>(det);
}

//*-----Matrix end-----

//*-----Double start-----

Double::Double(const string &s)
{ // 123.432;
    num = stod(s);
}

Double::Double(double x) : num(x) {}

unique_ptr<Algebra> Double::operator+(const Algebra &x) const
{
    return x.addTo(*this);
}

unique_ptr<Algebra> Double::addTo(const Double &x) const
{
    return make_unique<Double>(num + x.num);
}

unique_ptr<Algebra> Double::operator-(const Algebra &x) const
{
    return x.subTo(*this);
}

unique_ptr<Algebra> Double::subTo(const Double &x) const
{
    return make_unique<Double>(x.num - num);
}

unique_ptr<Algebra> Double::operator*(const Algebra &x) const
{
    return x.mulTo(*this);
}

unique_ptr<Algebra> Double::mulTo(const Matrix &x) const
{
    Matrix res(x.r, x.c);

    for (int i = 0; i < x.r; i++)
        for (int j = 0; j < x.c; j++)
        {
            res.mt[i][j] = num * x.mt[i][j];
        }
    return make_unique<Matrix>(res);
} // 数乘,全局函数

unique_ptr<Algebra> Double::mulTo(const Double &x) const
{
    return make_unique<Double>(num * x.num);
}

unique_ptr<Algebra> Double::operator/(const Algebra &x) const
{
    return x.divTo(*this);
}

unique_ptr<Algebra> Double::divTo(const Matrix &x) const
{
    if (fabs(num) < EPS)
        throw runtime_error("输出为 0\n");

    Matrix res(x.r, x.c);
    for (int i = 0; i < x.r; i++)
        for (int j = 0; j < x.c; j++)
            res.mt[i][j] = x.mt[i][j] / num;
    return make_unique<Matrix>(res);
}

unique_ptr<Algebra> Double::divTo(const Double &x) const
{

    if (fabs(num) < EPS)
        throw runtime_error("输出为 0");
    return make_unique<Double>(x.num / num);
}

unique_ptr<Algebra> Double::getPow(const Algebra &x) const
{
    return x.powTo(*this);
}

unique_ptr<Algebra> Double::powTo(const Double &x) const /// x.num bottom  num pow
{
    double result = 1.0;
    if (num >= 0 && num - floor(num) < EPS)
    {
        double mul = x.num;
        int inum = static_cast<int>(num);
        while (inum)
        {
            if (inum & 1)
                result *= mul;
            mul *= mul;
            inum >>= 1;
        }
    }
    else
    {
        result = pow(x.num, num);
    }
    return make_unique<Double>(result);
}

unique_ptr<Algebra> Double::powTo(const Matrix &x) const
{
    if (x.r != x.c)
        throw runtime_error("行列数不相等\n");

    Matrix res(x.r, x.c);
    for (int i = 0; i < x.r; i++)
        res.mt[i][i] = 1.0;

    if (num >= 0 && num - floor(num) < EPS)
    {
        int inum = static_cast<int>(num);
        Matrix mul(x);
        while (inum)
        {
            if (inum & 1)
                res = *static_cast<Matrix *>((res * mul).get());
            mul = *static_cast<Matrix *>((mul * mul).get());
            inum >>= 1;
        }
    }
    else
        throw runtime_error("matrix pow must be Z+");

    return make_unique<Matrix>(res);
}

unique_ptr<Algebra> Double::getAbs() const
{
    return make_unique<Double>(fabs(num));
}

unique_ptr<Algebra> Double::getFac() const
{
    if (num < 0)
        throw runtime_error("负数没有阶乘\n");
    else if ((num - floor(num) > EPS))
        throw runtime_error("十进制没有阶乘\n");

    double result = 1.0;

    for (int i = 1; i <= num; i++)
    {
        if (result > 0x3f3f3f3f3f3f3f3f / i)
            throw runtime_error("数据溢出");
        result *= i;
    }
    return make_unique<Double>(result);
}

string Double::print(const Double &x)
{
    if (fabs(x.num - floor(x.num)) < EPS)
    {
        return to_string((int)(x.num));
    }
    else
        return to_string(x.num);
}

//*-----Double end------
