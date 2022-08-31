#ifndef CONCRETECOMPUTATIONALPROBLEMS_H
#define CONCRETECOMPUTATIONALPROBLEMS_H

#include "computationalproblem.h"


// Here you can define your own computation problem classes by template

/*
*    class ConcreteComputationalProblemPROBLEM_NAME : public ComputationalProblem
*    {
*     public:
*       ConcreteComputationalProblemPROBLEM_NAME(int num_in_arr, QObject *parent = nullptr);
*       virtual void ExpressionCalculation();
*       **
*       your own procedures
*       **
*    };
*/


class ConcreteComputationalProblemSumAB : public ComputationalProblem
{
public:
    ConcreteComputationalProblemSumAB(int num_in_arr, QObject *parent = nullptr);
    virtual void ExpressionCalculation();
};


class ConcreteComputationalProblemMultiplyAB : public ComputationalProblem
{
public:
    ConcreteComputationalProblemMultiplyAB(int num_in_arr, QObject *parent = nullptr);
    virtual void ExpressionCalculation();
};


class ConcreteComputationalProblemSumABC : public ComputationalProblem
{
public:
    ConcreteComputationalProblemSumABC(int num_in_arr, QObject *parent = nullptr);
    virtual void ExpressionCalculation();
};


class ConcreteComputationalProblemGcdAB : public ComputationalProblem
{
public:
    ConcreteComputationalProblemGcdAB(int num_in_arr, QObject *parent = nullptr);
    virtual void ExpressionCalculation();
};


class ConcreteComputationalProblemLCG_5th_val: public ComputationalProblem
{
public:
    ConcreteComputationalProblemLCG_5th_val(int num_in_arr, QObject *parent = nullptr);
    virtual void ExpressionCalculation();
    int64_t gcd(int64_t a, int64_t b);
    int64_t mult_inverse(int64_t a, int64_t module);
};
#endif // CONCRETECOMPUTATIONALPROBLEMS_H
