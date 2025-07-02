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

class Algebra //*基类：：参数为Algebra的入口运算，子类参数合法作为左运算数的出口运算，全部抛出异常
{             //*子类：：参数Algebra的合法入口运算，子类参数作为左运算数的合法出口运算及实现,非法操作的声明不用实现，，通过using
public:
    virtual unique_ptr<Algebra> operator+(const Algebra &x) const;
    virtual unique_ptr<Algebra> addTo(const Matrix &x) const; // matrix + double  double(matrix)
    virtual unique_ptr<Algebra> addTo(const Double &x) const;

    virtual unique_ptr<Algebra> operator-(const Algebra &x) const;
    virtual unique_ptr<Algebra> subTo(const Matrix &x) const;
    virtual unique_ptr<Algebra> subTo(const Double &x) const;

    virtual unique_ptr<Algebra> operator*(const Algebra &x) const;
    virtual unique_ptr<Algebra> mulTo(const Matrix &x) const;
    virtual unique_ptr<Algebra> mulTo(const Double &x) const;

    virtual unique_ptr<Algebra> operator/(const Algebra &x) const;
    virtual unique_ptr<Algebra> divTo(const Matrix &x) const;
    virtual unique_ptr<Algebra> divTo(const Double &x) const;

    virtual unique_ptr<Algebra> getPow(const Algebra &x) const; //! 原来是^，修改calculator、
    virtual unique_ptr<Algebra> powTo(const Double &x) const;
    virtual unique_ptr<Algebra> powTo(const Matrix &x) const;
    //
    virtual unique_ptr<Algebra> getRank() const;
    virtual unique_ptr<Algebra> getDet() const;
    virtual unique_ptr<Algebra> getInverse() const;
    virtual unique_ptr<Algebra> getTrans() const;

    virtual unique_ptr<Algebra> getFac() const;
    virtual unique_ptr<Algebra> getAbs() const;
};

class Matrix : public Algebra
{
public:
    using Algebra::addTo;
    using Algebra::divTo;
    using Algebra::mulTo;
    using Algebra::powTo;
    using Algebra::subTo;

    int r, c;
    vector<vector<double>> mt;
    string s;

    Matrix(const string &s);
    Matrix(int x, int y);
    Matrix(const Matrix &x) = default;
    

    unique_ptr<Algebra> getRank() const override;
    unique_ptr<Algebra> getDet() const override;
    unique_ptr<Algebra> getInverse() const override;
    unique_ptr<Algebra> getTrans() const override;

    unique_ptr<Algebra> operator+(const Algebra &x) const override;
    unique_ptr<Algebra> addTo(const Matrix &x) const override;

    unique_ptr<Algebra> operator-(const Algebra &x) const override;
    unique_ptr<Algebra> subTo(const Matrix &x) const override;

    unique_ptr<Algebra> operator*(const Algebra &x) const override;
    unique_ptr<Algebra> mulTo(const Matrix &x) const override;
    unique_ptr<Algebra> mulTo(const Double &x) const override;

    unique_ptr<Algebra> operator/(const Algebra &x) const override;
    unique_ptr<Algebra> divTo(const Matrix &x) const override;

    unique_ptr<Algebra> getPow(const Algebra &x) const override;

    static string print(const Matrix &x);
    void getLU(vector<vector<double>> &low, vector<vector<double>> &up) const;
};
//*---------------------------------------------

class Double : public Algebra
{
public:
    using Algebra::addTo;
    using Algebra::divTo;
    using Algebra::mulTo;
    using Algebra::powTo;
    using Algebra::subTo;

    double num;

    Double(const string &s);
    Double(double x);
    Double(int x) : num(static_cast<double>(x)) {}
    Double(const Double &x) = default;

    unique_ptr<Algebra> operator+(const Algebra &x) const override;
    unique_ptr<Algebra> addTo(const Double &x) const override;

    unique_ptr<Algebra> operator-(const Algebra &x) const override;
    unique_ptr<Algebra> subTo(const Double &x) const override;

    unique_ptr<Algebra> operator*(const Algebra &x) const override;
    unique_ptr<Algebra> mulTo(const Matrix &x) const override;
    unique_ptr<Algebra> mulTo(const Double &x) const override;

    unique_ptr<Algebra> operator/(const Algebra &x) const override;
    unique_ptr<Algebra> divTo(const Matrix &x) const override;
    unique_ptr<Algebra> divTo(const Double &x) const override;

    unique_ptr<Algebra> getPow(const Algebra &x) const override;
    unique_ptr<Algebra> powTo(const Double &x) const override;
    unique_ptr<Algebra> powTo(const Matrix &x) const override;

    unique_ptr<Algebra> getAbs() const override;
    unique_ptr<Algebra> getFac() const override;

    static string print(const Double &x);
};

//*------GLOBAL START-------
