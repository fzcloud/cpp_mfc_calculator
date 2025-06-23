#pragma once
#include <vector>
#include <string>
#include <memory>
#include <stdexcept>
#include <cmath>
using ll = long long;
using namespace std;

class Algebra
{
public:

    virtual string getName() const = 0;
    virtual bool avai(const Algebra& x, char op) const = 0;
};

class Matrix : public Algebra
{
public:
    int r, c;
    vector<vector<double>> mt;
    string s;

    Matrix(string &s);
    Matrix(int x, int y);

    string getName() const override;
    bool avai(const Algebra& x, char op) const override;


    unique_ptr<Matrix> trans();

    unique_ptr<Matrix> operator+(const Matrix &x);
    unique_ptr<Matrix> operator-(const Matrix &x);
    unique_ptr<Matrix> operator*(const Matrix &x);
    unique_ptr<Matrix> operator/(const Matrix &x);


    static string print(const Matrix &x);
};

class Double : public Algebra
{
public:
    double num;

    Double(string &s);
    Double(double x);
    string getName() const override;
    bool avai(const Algebra& x, char op) const override;



    unique_ptr<Double> operator+(const Double &x);
    unique_ptr<Double> operator-(const Double &x);
    unique_ptr<Double> operator*(const Double &x);
    unique_ptr<Double> operator/(const Double &x);
    unique_ptr<Double> operator^(const Double &x);

    static unique_ptr<Double> abs(const Double &x);
    static string print(const Double &x);
};


//*------全局函数-------

inline unique_ptr<Matrix> operator*(const Double &x, const Matrix &y)
{
    Matrix res(y.r, y.c);

    for (int i = 0; i < y.r; i++)
        for (int j = 0; j < y.c; j++)
        {
            res.mt[i][j] = x.num * y.mt[i][j];
        }
    return make_unique<Matrix>(res);
} // 数乘,全局函数
//

inline unique_ptr<Matrix> operator*(const Matrix &y, const Double &x)
{
    Matrix res(y.r, y.c);

    for (int i = 0; i < y.r; i++)
        for (int j = 0; j < y.c; j++)
        {
            res.mt[i][j] = x.num * y.mt[i][j];
        }
    return make_unique<Matrix>(res);
} // 数乘,全局函数

/*
class Vect : public Algebra
{
public:
    double mag;
    vector<double> v;

    Vect(string &s);
    Vect(const Vect &x);
    string getName() const override;
    bool avai(const Algebra& x, char op) const override;

    double meg() const;
    Vect operator+(const Vect &x);
    Vect operator-(const Vect &x);
    Vect operator*(const Vect &x);
    Vect operator/(const Vect &x);
    
};
*/