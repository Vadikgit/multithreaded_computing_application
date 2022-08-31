#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "computationalproblem.h"
#include "concretecomputationalproblems.h"
#include <QGridLayout>
#include <QString>
#include <vector>
#include <thread>
#include <chrono>
#include <string>
#include <QWidget>
#include <QProgressBar>
#include <QPushButton>
#include <QLabel>
#include <QLineEdit>
#include <QHBoxLayout>
#include "id_pushbutton.h"

class MainWindow : public QMainWindow
{
    Q_OBJECT
public:
    int num_of_comp_probs;

    const int window_height = 450;
    const int window_width = 450;
    const int column_minimum_width = 200;

    std::vector<ComputationalProblem *> comp_probs; // Computational Problems are stored as pointers for basic class
    std::vector<std::thread *> comp_threads; // separate threads for computing

    // Elements of layout
    QWidget * p_central_widget;
    QGridLayout * p_table_grid;
    std::vector<QProgressBar *> progress_bars_array;
    std::vector<QLabel *> probs_finished_steps;
    std::vector<QLabel *> probs_descriptions;
    std::vector<ID_PushButton *> comput_start_btns;

    std::vector<QHBoxLayout *> argument_boxes;
    std::vector<QWidget *> placeholders_for_arguments_hboxes;
    std::vector<std::vector<QLineEdit *>> argument_receivers;

    std::vector<QHBoxLayout *> result_boxes;
    std::vector<QWidget *> placeholders_for_result_hboxes;
    std::vector<std::vector<QLabel *>> result_presenters;

    std::vector<QLabel *> rows_numbers;
    std::vector<QLabel *> columns_names;

    // Prepairing rocedures
    void SetProblems();
    void WindowMarking();
    void PrerareArgumentsReceiver(int);
    void PrerareResultPresenter(int);

    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

public slots:
    void Compute(int problem_index); // start computing of problem with the same index with clicked button
    void GetCompProbProgress(int problem_number, int num_of_steps,int num_of_current_step, QString status); // catch and process progress signals
};

#endif // MAINWINDOW_H
