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


unique_ptr<Algebra> operator+(const Algebra &x)
{
    throw runtime_error("illegal!!\n");
}
unique_ptr<Algebra> operator-(const Algebra &x)
{
    throw runtime_error("illegal!!\n");
}
unique_ptr<Algebra> operator*(const Algebra &x)
{
    throw runtime_error("illegal!!\n");
}
unique_ptr<Algebra> operator/(const Algebra &x)
{
    throw runtime_error("illegal!!\n");
}
unique_ptr<Algebra> divBy(const Algebra &x)
{
    throw runtime_error("illegal!!\n");
}
unique_ptr<Algebra> getPow(const Algebra &x)
{
    throw runtime_error("illegal!!\n");
}
unique_ptr<Algebra> powBy(const Algebra &x)
{
    throw runtime_error("illegal!!\n");
}
unique_ptr<Algebra> getRank()
{
    throw runtime_error("illegal!!\n");
}
unique_ptr<Algebra> getDet()
{
    throw runtime_error("illegal!!\n");
}
unique_ptr<Algebra> getInverse()
{
    throw runtime_error("illegal!!\n");
}
unique_ptr<Algebra> getTrans()
{
    throw runtime_error("illegal!!\n");
}
unique_ptr<Algebra> getAbs()
{
    throw runtime_error("illegal!!\n");
}

//*-------Algebra start-------

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

unique_ptr<Algebra> Matrix::operator+(const Algebra &x)
{
    return x + (*this);
}

unique_ptr<Algebra> Matrix::operator+(const Matrix &x)
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

unique_ptr<Algebra> Matrix::operator-(const Algebra &x)
{
    return x - (*this);
}


unique_ptr<Algebra> Matrix::operator-(const Matrix &x)
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

//*true
unique_ptr<Algebra> Matrix::operator*(const Algebra &x)
{
    return x * (*this);
}

unique_ptr<Algebra> Matrix::operator*(const Matrix &x)
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

unique_ptr<Algebra> Matrix::operator*(const Double &x)
{
    Matrix res(r, c);

    for (int i = 0; i < r; i++)
        for (int j = 0; j < c; j++)
        {
            res.mt[i][j] = x.num * mt[i][j];
        }
    return make_unique<Matrix>(res);    
}

unique_ptr<Algebra> Matrix::operator/(const Algebra &x)
{
    return x.divBy(*this);
}

unique_ptr<Algebra> Matrix::divBy(const Matrix &x)
{
    return x * this->getInverese();
}

unique_ptr<Algebra> Matrix::divBy(const Double &x)
{
    return x * this->getInverse();
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
            if (fabs(num - floor(num)) < EPS)
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

static void Matrix::getLU(vector<vector<double>> &up,vector<vector<double>> &low)
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


unique_ptr<Algebra> Matrix::getRank()
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

    return make_unique<Double>(rank);
}

unique_ptr<Algebra> Matrix::getInverse()
{
    vector<vector<double>> low, up;
    Matrix::getLU(low, up);
    
    vector<vector<double>> I(r, vector<double>(c, 0));
    for(int i = 0; i < r; i++) I[i][i] = 1;
    
    Matrix inv(r, c);
    for (int j = 0; j < c; ++j) {
        for (int i = 0; i < r; ++i) {
            double sum = 0;
            for (int k = 0; k < i; ++k)
                sum += low[i][k] * inv.mt[k][j];
            inv.mt[i][j] = I[i][j] - sum;
        }
    }
    
    for (int j = 0; j < c; ++j) {
        for (int i = r - 1; i >= 0; --i) {
            double sum = 0;
            for (int k = i + 1; k < c; ++k)
                sum += up[i][k] * inv.mt[k][j];
            inv.mt[i][j] = (inv.mt[i][j] - sum) / up[i][i];
        }
    }
    return make_unique<Matrix>(inv);
}

unique_ptr<Algebra> Matrix::getDet()
{
    vector<vetor<double>>  low, up;
    Matrix::getLU(low, up);
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


unique_ptr<Algebra> Double::operator+(const Algebra &x)
{
    return x + (*this);
}

unique_ptr<Algebra> Double::operator+(const Double &x)
{
    return make_unique<Double>(num + x.num);
}

unique_ptr<Algebra> Double::operator-(const Algebra &x)
{
    return x - (*this);
}

unique_ptr<Algebra> Double::operator-(const Double &x)
{
    return make_unique<Double>(num - x.num);
}

unique_ptr<Algebra> Double::operator*(const Algebra &x)
{
    return x * (*this);
}

unique_ptr<Algebra> Double::operator*(const Matrix &x)
{
    Matrix res(x.r, x.c);

    for (int i = 0; i < x.r; i++)
        for (int j = 0; j < x.c; j++)
        {
            res.mt[i][j] = num * x.mt[i][j];
        }
    return make_unique<Matrix>(res);
} // 数乘,全局函数

unique_ptr<Algebra> Double::operator*(const Double &x)
{
    return make_unique<Double>(num * x.num);
}

unique_ptr<Algebra> Double::operator/(const Algebra &x)
{
    return x.divBy(*this);
}

unique_ptr<Algebra> Double::divBy(const Matrix &x)
{
    if(fabs(num) < EPS)
        throw runtime_error("chushu is 0'\n");

    Matrix res(x.r, x.c);
    for(int i = 0; i < x.r; i++)
        for (int j = 0; j < x.c; j++)
            res.mt[i][j] /= num;
    return make_unique<Matrix>(res);
}

unique_ptr<Algebra> Double::divBy(const Double &x)
{

    if (fabs(num) < EPS)
        throw runtime_error("chushu is 0");
    return make_unique<Double>(x.num / num);
}

unique_ptr<Algebra> Double::getPow(const Algebra &x)
{
    return x.powBy(*this);
}

unique_ptr<Algebra> Double::powBy(const Double &x)
{
    return make_unique<Double>(pow(x.num, num));
}

unique_ptr<Algebra> Double::abs()
{
    return make_unique<Double>(abs(num));
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

