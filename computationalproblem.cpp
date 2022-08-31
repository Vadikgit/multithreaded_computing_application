#include "computationalproblem.h"

ComputationalProblem::ComputationalProblem(int num_in_arr, QObject *parent) : QObject(parent),number_in_probs_array{num_in_arr}, argc{0},ret_vals_c{0}
{
    qDebug("*** Comp_Prob constructor called ***");
    args.clear();
    ret_vals.clear();
}

void ComputationalProblem::ExpressionCalculation(){

}
