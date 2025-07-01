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
{             //*子类：：参数Algebra的合法入口运算，子类参数作为左运算数的合法出口运算
public:
    virtual string getName() const = 0;
	virtual unique_ptr<Algebra> getSub() = 0;
    
    virtual unique_ptr<Algebra> operator+(const Algebra &x);
    virtual unique_ptr<Algebra> addTo(const Matrix &x); // matrix + double  double(matrix)
    virtual unique_ptr<Algebra> addTo(const Double &x);

    virtual unique_ptr<Algebra> operator-(const Algebra &x);
    virtual unique_ptr<Algebra> subTo(const Matrix &x);
    virtual unique_ptr<Algebra> subTo(const Double &x);

    virtual unique_ptr<Algebra> operator*(const Algebra &x);
    virtual unique_ptr<Algebra> mulTo(const Matrix &x);
    virtual unique_ptr<Algebra> mulTo(const Double &x);

    virtual unique_ptr<Algebra> operator/(const Algebra &x);
    virtual unique_ptr<Algebra> divTo(const Matrix &x);
    virtual unique_ptr<Algebra> divTo(const Double &x);

    virtual unique_ptr<Algebra> getPow(const Algebra &x); //! 原来是^，修改calculator、
    virtual unique_ptr<Algebra> powTo(const Double &x);   
	virtual unique_ptr<Algebra> powTo(const Matrix &x);
    //
    virtual unique_ptr<Algebra> getRank();
    virtual unique_ptr<Algebra> getDet();
    virtual unique_ptr<Algebra> getInverse();
    virtual unique_ptr<Algebra> getTrans();

    virtual unique_ptr<Algebra> getFac();
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
	unique_ptr<Matrix> getSub() override;

    unique_ptr<Algebra> getRank() override;
    unique_ptr<Algebra> getDet() override;
    unique_ptr<Algebra> getInverse() override;
    unique_ptr<Algebra> getTrans() override;

    unique_ptr<Algebra> operator+(const Algebra &x) override;
    unique_ptr<Algebra> addTo(const Matrix &x) override;

    unique_ptr<Algebra> operator-(const Algebra &x) override;
    unique_ptr<Algebra> subTo(const Matrix &x) override;

    unique_ptr<Algebra> operator*(const Algebra &x) override;
    unique_ptr<Algebra> mulTo(const Matrix &x) override;
    unique_ptr<Algebra> mulTo(const Double &x) override;

    unique_ptr<Algebra> operator/(const Algebra &x) override;
    unique_ptr<Algebra> divTo(const Matrix &x) override;

	unique_ptr<Algebra> getPow(const Algebra &x) override;

    static string print(const Matrix &x);
    void getLU(vector<vector<double>> &low, vector<vector<double>> &up);
};
//*---------------------------------------------

class Double : public Algebra
{
public:
    double num;

    Double(string &s);
    Double(double x);
    string getName() const override;
	unique_ptr<Double> getSub() override;

    unique_ptr<Algebra> operator+(const Algebra &x) override;
    unique_ptr<Algebra> addTo(const Double &x) override;

    unique_ptr<Algebra> operator-(const Algebra &x) override;
    unique_ptr<Algebra> subTo(const Double &x) override;

    unique_ptr<Algebra> operator*(const Algebra &x) override;
    unique_ptr<Algebra> mulTo(const Matrix &x) override;
    unique_ptr<Algebra> mulTo(const Double &x) override;

    unique_ptr<Algebra> operator/(const Algebra &x) override;
    unique_ptr<Algebra> divTo(const Matrix &x) override;
    unique_ptr<Algebra> divTo(const Double &x) override;

    unique_ptr<Algebra> getPow(const Algebra &x) override;
    unique_ptr<Algebra> powTo(const Double &x) override;
	unique_ptr<Algebra> powTo(const Matrix &x) override;

    unique_ptr<Algebra> getAbs() override; //! 从静态改为成员函数
    unique_ptr<Algebra> getFac() override;

    static string print(const Double &x);
};

//*------GLOBAL START-------
