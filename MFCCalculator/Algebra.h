#pragma once
#include <vector>
#include <string>
#include <memory>
#include <stdexcept>
#include <cmath>
using ll = long long;
using namespace std;

const double EPS = 1e-9;

class Matrix;
class Double;

class Algebra
{
public:

    virtual string getName() const = 0;

    virtual unique_ptr<Algebra> operator+(const Algebra &x);
    virtual unique_ptr<Algebra> operator-(const Algebra &x);
    virtual unique_ptr<Algebra> operator*(const Algebra &x);
    virtual unique_ptr<Algebra> operator/(const Algebra &x); //! 影响matrix的LU,一会再说
    virtual unique_ptr<Algebra> divBy(const Algebra &x);
    virtual unique_ptr<ALgebra> getPow(const Algebra &x);//!原来是^，修改calculator
    virtual unique_ptr<Algebra> powBy(const Algebra &x);
    virtual unique_ptr<Algebra> getRank();
    virtual unique_ptr<Algebra> getDet();
    virtual unique_ptr<Algebra> getInverse();
    virtual unique_ptr<Algebra> getTrans();
    virtual unique_ptr<Algebra> getAbs();

    
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

    unique_ptr<Algebra> getRank();
    unique_ptr<Algebra> getDet();
    unique_ptr<Algebra> getInverse();
    unique_ptr<Algebra> getTrans();

    unique_ptr<Algebra> operator+(const Algebra &x) override;
    unique_ptr<Algebra> operator+(const Matrix &x) override;

    unique_ptr<Algebra> operator-(const Algebra &x) override;
    unique_ptr<Algebra> operator-(const Matrix &x) override;

    unique_ptr<Algebra> operator*(const Algebra &x) override;
    unique_ptr<Algebra> operator*(const Matrix &x) override;
    unique_ptr<Algebra> operator*(const Double &x) override;

    unique_ptr<Algebra> operator/(const Algebra &x) override;
    unique_ptr<Algebra> divBy(const Matrix &x) override;
    unique_ptr<Algebra> divBy(const Double &x) override;

    static string print(const Matrix &x);
    static void getLU(vector<vector<double>> &low, vector<vector<double>> &up);
};
//*---------------------------------------------

class Double : public Algebra
{
public:
    double num;

    Double(string &s);
    Double(double x);
    string getName() const override;

    unique_ptr<Algebra> operator+(const Algebra &x) override;
    unique_ptr<Algebra> operator+(const Double &x) override;

    unique_ptr<Algebra> operator-(const Algebra &x) override;
    unique_ptr<Algebra> operator-(const Double &x) override;

    unique_ptr<Algebra> operator*(const Algebra &x) override;
    unique_ptr<Algebra> operator*(const Matrix &x) override;
    unique_ptr<Algebra> operator*(const Double &x) override;


    unique_ptr<Algebra> operator/(const Algebra &x) override;
    unique_ptr<Algebra> divBy(const Matrix &x) override;
    unique_ptr<Algebra> divBy(const Double &x) override;

    unique_ptr<Algebra> getPow(const Double &x) override;
    unique_ptr<Algebra> powBy(const Double &x) override;

    static unique_ptr<Algebra> getAbs(const Double &x) override;
    static string print(const Double &x);
};


//*------GLOBAL START-------

