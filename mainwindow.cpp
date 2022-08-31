#include "mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    num_of_comp_probs = 10;

    comp_threads.assign(num_of_comp_probs, new std::thread()); // fill threads array by default constructions

    //resize(window_width, window_height);

    p_central_widget = new QWidget(this);
    p_central_widget->resize(this->size());
    setCentralWidget(p_central_widget);

    p_table_grid = new QGridLayout(p_central_widget);
    p_table_grid->setHorizontalSpacing(0);
    p_table_grid->setVerticalSpacing(0);

    for (int i = 0; i < 5; i++) {
        columns_names.push_back(new QLabel(p_central_widget));
        columns_names[i]->setStyleSheet("QLabel {border: 1px solid black; }");
    }
    columns_names[0]->setText("№");
    columns_names[1]->setText("About computation");
    columns_names[2]->setText("Arguments");
    columns_names[3]->setText("Computation progress");
    columns_names[4]->setText("Result");
}

void MainWindow::SetProblems(){

    // Here we set up a list of computing problems
    for (int i = 0; i < 2; i++) {
        comp_probs.push_back(new ConcreteComputationalProblemSumAB(0+i*5));
        comp_probs.push_back(new ConcreteComputationalProblemMultiplyAB(1+i*5));
        comp_probs.push_back(new ConcreteComputationalProblemSumABC(2+i*5));
        comp_probs.push_back(new ConcreteComputationalProblemLCG_5th_val(3+i*5));
        comp_probs.push_back(new ConcreteComputationalProblemGcdAB(4+i*5));
    }

    // Connection between progress signals and catching slots
    for (int i = 0; i < num_of_comp_probs; i++) {
        connect(comp_probs[i], SIGNAL(ProgressSignal(int, int, int, QString)), this, SLOT(GetCompProbProgress(int, int, int, QString)));
    }

    // Setting up a layout
    WindowMarking();
}

void MainWindow::WindowMarking(){

    //columns
    for (int i = 0; i < 5; i++) {
        p_table_grid->addWidget(columns_names[i],0,i,1,1);
    }
    for (int i = 1; i < 5; i++) {
        p_table_grid->setColumnMinimumWidth(i, column_minimum_width);
    }


    //rows
    argument_receivers.resize(num_of_comp_probs);
    result_presenters.resize(num_of_comp_probs);


    for (int i = 0; i < num_of_comp_probs; i++) {
        //problems numbers
        rows_numbers.push_back(new QLabel(p_central_widget));
        rows_numbers[i]->setStyleSheet("QLabel {border: 1px solid black; }");
        rows_numbers[i]->setText(QString::number(i+1));

        p_table_grid->addWidget(rows_numbers[i],i*2+1,0,2,1);


        //problems descriptions
        probs_descriptions.push_back(new QLabel(p_central_widget));
        probs_descriptions[i]->setStyleSheet("QLabel {border: 1px solid black; }");
        probs_descriptions[i]->setText(QString::fromStdString(comp_probs[i]->problem_description));
        probs_descriptions[i]->adjustSize();

        p_table_grid->addWidget( probs_descriptions[i],i*2+1,1,2,1);


        //arguments for computing
        placeholders_for_arguments_hboxes.push_back(new QWidget(p_central_widget));
        placeholders_for_arguments_hboxes[i]->setStyleSheet("QWidget {border: 1px solid black; }");
        argument_boxes.push_back(new QHBoxLayout(placeholders_for_arguments_hboxes[i]));
        PrerareArgumentsReceiver(i);

        p_table_grid->addWidget(placeholders_for_arguments_hboxes[i],i*2+1,2,2,1);


        //problems progress bars
        progress_bars_array.push_back(new QProgressBar(p_central_widget));
        progress_bars_array[i]->setStyleSheet("QProgressBar {border: 1px solid black; }");

        p_table_grid->addWidget(progress_bars_array[i],i*2+1,3,1,1);


        //finished steps of problems
        probs_finished_steps.push_back(new QLabel(p_central_widget));
        probs_finished_steps[i]->setStyleSheet("QLabel {border: 1px solid black; }");
        probs_finished_steps[i]->setText("Not started");
        probs_finished_steps[i]->adjustSize();

        p_table_grid->addWidget( probs_finished_steps[i],i*2+2,3,1,1);


        //results of computing
        placeholders_for_result_hboxes.push_back(new QWidget(p_central_widget));
        placeholders_for_result_hboxes[i]->setStyleSheet("QWidget {border: 1px solid black; }");
        result_boxes.push_back(new QHBoxLayout(placeholders_for_result_hboxes[i]));
        PrerareResultPresenter(i);

        p_table_grid->addWidget(placeholders_for_result_hboxes[i],i*2+1,4,2,1);


        //activation buttons
        comput_start_btns.push_back(new ID_PushButton(i, p_central_widget));
        comput_start_btns[i]->setText("Start");

        p_table_grid->addWidget( comput_start_btns[i],i*2+1,5,2,1);

        // "Connecting" buttons with computing problem classes by the index in array
        connect(comput_start_btns[i], SIGNAL(retClickedID(int)), this, SLOT(Compute(int)));
    }

}

void MainWindow::Compute(int problem_index){
    for (int i = 0; i < comp_probs[problem_index]->argc; i++) {
        comp_probs[problem_index]->args[i] = argument_receivers[problem_index][i]->text().toStdString();
    }
    // create a new thread for problem computing
    comp_threads[problem_index] = (new std::thread(&ComputationalProblem::ExpressionCalculation, (comp_probs[problem_index])));
}

void MainWindow::GetCompProbProgress(int problem_number, int num_of_steps,int num_of_current_step, QString status){
    std::string for_print = "";
    for_print = "**** Signal captured: comp[" + std::to_string(problem_number) + "], step "
 + std::to_string(num_of_current_step)+" finished with status [" + status.toStdString() + "]";

    qDebug(for_print.c_str());

    progress_bars_array[problem_number]->setValue(100*num_of_current_step/num_of_steps);
    probs_finished_steps[problem_number]->setText(status);

    if(num_of_current_step==num_of_steps){
        for (int i = 0; i < comp_probs[problem_number]->ret_vals_c; i++) {
            result_presenters[problem_number][i]->setText(QString::fromStdString(comp_probs[problem_number]->ret_vals[i]));
        }
    }
}

void MainWindow::PrerareArgumentsReceiver(int problem_index){
    for (int i = 0; i < comp_probs[problem_index]->argc; i++) {
        argument_receivers[problem_index].push_back(new QLineEdit(placeholders_for_arguments_hboxes[problem_index]));
        argument_boxes[problem_index]->addWidget(argument_receivers[problem_index][i]);
    }
}

void MainWindow::PrerareResultPresenter(int problem_index){
    for (int i = 0; i < comp_probs[problem_index]->ret_vals_c; i++) {
        result_presenters[problem_index].push_back(new QLabel(placeholders_for_arguments_hboxes[problem_index]));
        result_presenters[problem_index][i]->setText("-");
        result_boxes[problem_index]->addWidget(result_presenters[problem_index][i]);
    }
}

MainWindow::~MainWindow()
{
    for (int i = 0; i < num_of_comp_probs; i++) {
        // if thread is different from default construction, detach it
        if(comp_threads[i]->get_id() != std::thread().get_id()){
            comp_threads[i]->detach();
            qDebug(QString::number(i).toStdString().c_str());
        }
        delete comp_probs[i];
    }
}

