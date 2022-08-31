#include "concretecomputationalproblems.h"


// Here you can implement your own computation problem classes, defined in .h, by template

/*
*    ConcreteComputationalProblemPROBLEM_NAME::ConcreteComputationalProblemPROBLEM_NAME(int num_in_arr, QObject *parent):
*    ComputationalProblem(num_in_arr, parent){
*
*    problem_description = "Put your problem description here";
*
*    argc = YOUR_VALUE;
*    args.resize(argc);
*
*    ret_vals_c = YOUR_VALUE;
*    ret_vals.resize(ret_vals_c);
*   }
*
*
*
*   void ConcreteComputationalProblemPROBLEM_NAME::ExpressionCalculation(){
*
*    number_of_steps = YOUR_VALUE, current_step = 1;
*
*    ----DO_SOMETHING----
*
*    status_str = "Current status";
*    emit ProgressSignal(number_in_probs_array,number_of_steps,current_step++,QString::fromStdString(status_str));
*
*    ----DO_SOMETHING----
*
*    status_str = "Current status";
*    emit ProgressSignal(number_in_probs_array,number_of_steps,current_step++,QString::fromStdString(status_str));
*
*
*    ----ret_vals now should store result values----
*
*   }
*
*
*   **
*   your own procedures
*   **
*/





ConcreteComputationalProblemSumAB::ConcreteComputationalProblemSumAB(int num_in_arr, QObject *parent):
    ComputationalProblem(num_in_arr, parent){

    problem_description = "Summing x1 and x2";

    argc = 2;
    args.resize(argc);

    ret_vals_c = 1;
    ret_vals.resize(ret_vals_c);
}

void ConcreteComputationalProblemSumAB::ExpressionCalculation(){

    number_of_steps = 3, current_step = 1;

    int x1 = QString::fromStdString(args[0]).toInt();

    status_str = "Argument 1 received";
    emit ProgressSignal(number_in_probs_array,number_of_steps,current_step++,QString::fromStdString(status_str));

    std::this_thread::sleep_for(std::chrono::milliseconds(1500));

    int x2 = QString::fromStdString(args[1]).toInt();
    status_str = "Argument 2 received";
    emit ProgressSignal(number_in_probs_array,number_of_steps,current_step++,QString::fromStdString(status_str));

    std::this_thread::sleep_for(std::chrono::milliseconds(1500));

    int res;
    res = x1 + x2;

    ret_vals[0] = QString::number(res).toStdString();

    status_str = "Sum computed";
    emit ProgressSignal(number_in_probs_array,number_of_steps,current_step++,QString::fromStdString(status_str));

}



ConcreteComputationalProblemMultiplyAB::ConcreteComputationalProblemMultiplyAB(int num_in_arr, QObject *parent):
    ComputationalProblem(num_in_arr, parent){

    problem_description = "Multiplying x1 and x2";

    argc = 2;
    args.resize(argc);

    ret_vals_c = 1;
    ret_vals.resize(ret_vals_c);
}

void ConcreteComputationalProblemMultiplyAB::ExpressionCalculation(){

    number_of_steps = 3, current_step = 1;

    int x1 = QString::fromStdString(args[0]).toInt();
    status_str = "Argument 1 received";
    emit ProgressSignal(number_in_probs_array,number_of_steps,current_step++,QString::fromStdString(status_str));

    std::this_thread::sleep_for(std::chrono::milliseconds(1500));

    int x2 = QString::fromStdString(args[1]).toInt();
    status_str = "Argument 2 received";
    emit ProgressSignal(number_in_probs_array,number_of_steps,current_step++,QString::fromStdString(status_str));

    std::this_thread::sleep_for(std::chrono::milliseconds(1500));

    int res;
    res = x1 * x2;

    ret_vals[0] = QString::number(res).toStdString();

    status_str = "Multiplying computed";
    emit ProgressSignal(number_in_probs_array,number_of_steps,current_step++,QString::fromStdString(status_str));
}



ConcreteComputationalProblemSumABC::ConcreteComputationalProblemSumABC(int num_in_arr, QObject *parent):
    ComputationalProblem(num_in_arr, parent){

    problem_description = "Summing x1, x2 and x3";

    argc = 3;
    args.resize(argc);

    ret_vals_c = 1;
    ret_vals.resize(ret_vals_c);
}

void ConcreteComputationalProblemSumABC::ExpressionCalculation(){

    number_of_steps = 4, current_step = 1;

    int x1 = QString::fromStdString(args[0]).toInt();
    status_str = "Argument 1 received";
    emit ProgressSignal(number_in_probs_array,number_of_steps,current_step++,QString::fromStdString(status_str));

    std::this_thread::sleep_for(std::chrono::milliseconds(1500));

    int x2 = QString::fromStdString(args[1]).toInt();
    status_str = "Argument 2 received";
    emit ProgressSignal(number_in_probs_array,number_of_steps,current_step++,QString::fromStdString(status_str));

    std::this_thread::sleep_for(std::chrono::milliseconds(1500));

    int x3 = QString::fromStdString(args[2]).toInt();
    status_str = "Argument 3 received";
    emit ProgressSignal(number_in_probs_array,number_of_steps,current_step++,QString::fromStdString(status_str));

    std::this_thread::sleep_for(std::chrono::milliseconds(1500));

    int res;
    res = x1 + x2 + x3;

    ret_vals[0] = QString::number(res).toStdString();

    status_str = "Sum computed";
    emit ProgressSignal(number_in_probs_array,number_of_steps,current_step++,QString::fromStdString(status_str));
}



ConcreteComputationalProblemGcdAB::ConcreteComputationalProblemGcdAB(int num_in_arr, QObject *parent):
    ComputationalProblem(num_in_arr, parent){

    problem_description = "Calculates the largest common \ndivisor of x1 and x2";

    argc = 2;
    args.resize(argc);

    ret_vals_c = 1;
    ret_vals.resize(ret_vals_c);
}

void ConcreteComputationalProblemGcdAB::ExpressionCalculation(){

    number_of_steps = 4, current_step = 1;

    int x1 = QString::fromStdString(args[0]).toInt();
    status_str = "Argument 1 received";
    emit ProgressSignal(number_in_probs_array,number_of_steps,current_step++,QString::fromStdString(status_str));

    std::this_thread::sleep_for(std::chrono::milliseconds(1500));

    int x2 = QString::fromStdString(args[1]).toInt();
    status_str = "Argument 2 received";
    emit ProgressSignal(number_in_probs_array,number_of_steps,current_step++,QString::fromStdString(status_str));

    std::this_thread::sleep_for(std::chrono::milliseconds(1500));

    int res;

    x1 = ((x1 >= 0) ? x1 : ((-1) * x1));
    x2 = ((x2 >= 0) ? x2 : ((-1) * x2));

    status_str = "Arguments are prepared \nfor the computing";
    emit ProgressSignal(number_in_probs_array,number_of_steps,current_step++,QString::fromStdString(status_str));

    std::this_thread::sleep_for(std::chrono::milliseconds(1500));


    int t;
    while (x2 != 0) {
        t = x2;
        x2 = x1 % x2;
        x1 = t;
    }

    res = x1;

    ret_vals[0] = QString::number(res).toStdString();

    status_str = "The largest common \ndivisor is calculated";
    emit ProgressSignal(number_in_probs_array,number_of_steps,current_step++,QString::fromStdString(status_str));
}



ConcreteComputationalProblemLCG_5th_val::ConcreteComputationalProblemLCG_5th_val(int num_in_arr, QObject *parent):
    ComputationalProblem(num_in_arr, parent){

    problem_description = "Calculates possible 5th value \n of Linear Congruent Generator's"
"\n sequence by known x1, x2, x3 and x4";

    argc = 4;
    args.resize(argc);

    ret_vals_c = 1;
    ret_vals.resize(ret_vals_c);
}

int64_t ConcreteComputationalProblemLCG_5th_val::gcd(int64_t a, int64_t b) {
    a = ((a >= 0) ? a : ((-1) * a));
    b = ((b >= 0) ? b : ((-1) * b));
    int64_t t;
    while (b != 0) {
        t = b;
        b = a % b;
        a = t;
    }
    return a;
}

int64_t ConcreteComputationalProblemLCG_5th_val::mult_inverse(int64_t a, int64_t module) {

    a = ((a % module) + module) % module;

    int64_t q, Q, Qp = 0, Qpp = 1, tempmod = module, counter = -1;

    while (tempmod != 0) {
        counter++;

        q = a / tempmod;
        Q = q * Qp + Qpp;
        int64_t tmp = a;
        a = tempmod;
        tempmod = tmp % tempmod;

        Qpp = Qp;
        Qp = Q;
        //std::cout << counter << ' ' << q << ' ' << Q << '\n';
    }

    int64_t res = (-1 + 2 * (((counter - 1) + 1) % 2)) * Qpp;
    if (res < 0)
    {
        res = module + res;
    }
    return res;
}

void ConcreteComputationalProblemLCG_5th_val::ExpressionCalculation(){

    number_of_steps = 5, current_step = 1;

    int64_t x1, x2, x3, x4, x5 = -1, MAX_M = 65'535, maxX, max12, max34;

    x1 = QString::fromStdString(args[0]).toInt();
    status_str = "Argument 1 received";
    emit ProgressSignal(number_in_probs_array,number_of_steps,current_step++,QString::fromStdString(status_str));

    std::this_thread::sleep_for(std::chrono::milliseconds(800));


    x2 = QString::fromStdString(args[1]).toInt();
    status_str = "Argument 2 received";
    emit ProgressSignal(number_in_probs_array,number_of_steps,current_step++,QString::fromStdString(status_str));

    std::this_thread::sleep_for(std::chrono::milliseconds(800));


    x3 = QString::fromStdString(args[2]).toInt();
    status_str = "Argument 3 received";
    emit ProgressSignal(number_in_probs_array,number_of_steps,current_step++,QString::fromStdString(status_str));

    std::this_thread::sleep_for(std::chrono::milliseconds(800));



    x4 = QString::fromStdString(args[3]).toInt();
    status_str = "Argument 4 received";
    emit ProgressSignal(number_in_probs_array,number_of_steps,current_step++,QString::fromStdString(status_str));

    std::this_thread::sleep_for(std::chrono::milliseconds(800));


    if ((x2 == x3) && (x3 == x4))
    {
        x5 = x4;
    }
    else{

        max12 = ((x1 > x2) ? x1 : x2);
        max34 = ((x3 > x4) ? x3 : x4);
        maxX = ((max12 > max34) ? max12 : max34);

        for (int64_t possible_module = maxX + 1; possible_module <= MAX_M; possible_module++)
        {

            if (((x4 - x3) * (x2 - x1) - (x3 - x2) * (x3 - x2)) % possible_module == 0)
            {
                int64_t gcd_mod_21 = gcd(x2 - x1, possible_module);

                if ((x3 - x2) % gcd_mod_21 == 0)
                {
                    int64_t a;
                    int64_t tempmod = possible_module / gcd_mod_21;
                    a = (((mult_inverse((x2 - x1) / gcd_mod_21, tempmod) * (x3 - x2) / gcd_mod_21) % tempmod)
                         + tempmod) % tempmod;

                    int64_t possible_a = a, possible_c;

                    for (int j = 0; j < (possible_module / tempmod); j++)
                    {
                        possible_a = a + tempmod * j;
                        possible_c = (((x2 - possible_a * x1) % possible_module) + possible_module) % possible_module;


                        if ((((x4 - x3) - possible_a * (x3 - x2)) % possible_module == 0))
                        {
                            x5 = (((possible_a * (x4 - x3) + x4) % possible_module) + possible_module) % possible_module;
                            break;
                        }

                    }
                    if(x5 != -1){
                        break;
                    }

                }

            }
        }
    }

    int res = x5;
    if(res != -1){
        ret_vals[0] = QString::number(res).toStdString();
    }
    else{
        ret_vals[0] = "Solution not found";
    }

    status_str = "Calculating finished";
    emit ProgressSignal(number_in_probs_array,number_of_steps,current_step++,QString::fromStdString(status_str));
}

