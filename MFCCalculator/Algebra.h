#pragma once
#include <vector>
#include <string>
#include <memory>
#include <stdexcept>
#include <cmath>
using ll = long long;
using namespace std;

const double EPS = 1e-9;

class Algebra
{
public:

    virtual string getName() const = 0;
};

class Matrix : public Algebra
{
public:
    int r, c;
    vector<vector<double>> mt, low, up;
    string s;

    Matrix(string &s);
    Matrix(int x, int y);

    string getName() const override;
    void getLU();
    int getRank();


    unique_ptr<Double> getDet();
    unique_ptr<Matrix> getInverse();
    unique_ptr<Matrix> trans();

    unique_ptr<Matrix> operator+(const Matrix &x);
    unique_ptr<Matrix> operator-(const Matrix &x);
    unique_ptr<Matrix> operator*(const Matrix &x);
    unique_ptr<Matrix> operator/(Matrix &x);//丑陋无比但是这样简洁一点。。。。。。。。


    static string print(const Matrix &x);
};
//*---------------------------------------------

class Double : public Algebra
{
public:
    double num;

    Double(string &s);
    Double(double x);
    string getName() const override;



    unique_ptr<Double> operator+(const Double &x);
    unique_ptr<Double> operator-(const Double &x);
    unique_ptr<Double> operator*(const Double &x);
    unique_ptr<Double> operator/(const Double &x);
    unique_ptr<Double> operator^(const Double &x);

    static unique_ptr<Double> abs(const Double &x);
    static string print(const Double &x);
};


//*------GLOBAL START-------

unique_ptr<Matrix> operator*(const Double &x, const Matrix &y);

unique_ptr<Matrix> operator*(const Matrix &y, const Double &x);

