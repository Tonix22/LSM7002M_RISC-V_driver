#ifndef MAINWINDOW_H
#define MAINWINDOW_H
/***************************************************
******************* INCLUDES ***********************
****************************************************/

#include <QMainWindow>
#include <QApplication>
#include <QDebug>
#include <QMessageBox>
#include <QFileDialog>
#include <QDir>
#include <stdint.h>
#include <string>
#include <iostream>
#include <unordered_map>
#include <math.h>
#include "bridge.h"
#include "function_type.h"
#include "submenus.h"

#define MAX_SET_STRING_SIZE 22
#define MAX_PARAMS_STR_SIZE 15

//#define DEFAULT_FORMULA(n) ((uint64_t)(slider_cfg[n].by_default-slider_cfg[n].Min)*(uint64_t)slider_cfg[n].Steps)/(slider_cfg[n].Max-slider_cfg[n].Min);
//#define Generic_FORMULA(val,k) ((double)(val-slider_cfg[k].Min)*(double)slider_cfg[k].Steps)/(slider_cfg[k].Max-slider_cfg[k].Min);


/**************************************************
 *************** MAIN CLASS ***********************
 **************************************************/

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:

    MainWindow(QWidget *parent = nullptr);
    void onButtonClicked();
    void set_get_menu_changed(const QString &text);
    void API_menu_trigger(const QString &text);
    void SliderStep();
    void Enable_Disable_CH_print();
    void Text_param1_changed();
    void Text_param2_changed();
    void Text_input_register(std::string& msg,int index);
    double Sci_to_int(std::string& msg);
    void Opcode_to_GUI();
    IPDI_Bridge* bridge;
    
    QString units_label;
    //std::vector<slide_utils> slider_cfg;
    std::vector<double> slider_rate={0,0};
    std::string Sci_units[3] = {"K","M","G"};
    int API_ID = Qt_labels_size;
    ~MainWindow();

private:
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
