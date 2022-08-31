#ifndef COMPUTATIONALPROBLEM_H
#define COMPUTATIONALPROBLEM_H

#include <QObject>
#include <QString>
#include <thread>
#include <chrono>
#include <string>
#include <vector>

// There is a basic class of computational problem
// It keeps information about task: arguments, returning values and computing algorithm
// Inherit it to create custom computational problems

class ComputationalProblem : public QObject
{
    Q_OBJECT
public:
    int number_in_probs_array;

    int number_of_steps, current_step; // transmits information about steps with the progress signal
    int argc;
    std::vector<std::string> args; // arguments

    int ret_vals_c;
    std::vector<std::string> ret_vals; // returning values

    std::string status_str; // transmits text description of the progress with the progress signal
    std::string problem_description; // describes the process and result of the procedure

    virtual void ExpressionCalculation(); // here we describe a set of actions on arguments to get a result

    explicit ComputationalProblem(int num_in_arr, QObject *parent = nullptr);
    virtual ~ComputationalProblem(){
        qDebug("*** Comp_Prob destructor called ***");
    };
signals:
    // signal is generating in process of ExpressionCalculation() working.
    // It indicates the caller-problem by this index in common array
    // and describes current progress
    void ProgressSignal(int problem_number,int num_of_steps,int num_of_current_step, QString status);

};

#endif // COMPUTATIONALPROBLEM_H
