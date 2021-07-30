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


/***************************************************
***************** CODE COMPRESION ******************
****************************************************/

#define TRANSLATE(Param) QApplication::translate("OpcodeGenerator", Param, Q_NULLPTR)

#define PUSH_TO_LIST(Param) <<TRANSLATE(Param)

#define MAX_SET_STRING_SIZE 22
#define MAX_PARAMS_STR_SIZE 15

#define DEFAULT_FORMULA(n) ((uint64_t)(slider_cfg[n].by_default-slider_cfg[n].Min)*(uint64_t)slider_cfg[n].Steps)/(slider_cfg[n].Max-slider_cfg[n].Min);

#define Generic_FORMULA(val,k) ((double)(val-slider_cfg[k].Min)*(double)slider_cfg[k].Steps)/(slider_cfg[k].Max-slider_cfg[k].Min);

/**************************************************
 **************** STRING LIST *********************
 **************************************************/
typedef enum
{
    EnableChannel,
    LMSInit,
    samplerate,
    filterbwfreq,
    sampleratedir,
    lofrequency,
    normalizedgain,
    gaindb,
    testsignal,
    antenna,
    set_cmd_size,
}strings_enum;

typedef enum
{
    NoneFill,
    SetFill,
    GetFill
}Input_type;

typedef enum
{
    SetSamplerate,
    SetFilterbwfreq,
    SetSampleratedir,
    SetLofrequency,
    SetNormalizedgain,
    SetGaindb,
    SetTestsignal,
    sizeofsetersEnum
}seters_list_enum;

typedef enum
{
    Msps,
    Oversampling,
    Ref,
    Fout,
    Mhz,
    EMPTY,
    dB,
    DC_I,
    DC_Q,
    None,
    Size_of_parms_idx
}params_str_idx;

typedef struct
{
    int Max;
    int Min;
    int Steps;
    int by_default;
}slide_utils;

#define PARAMS_STRING_COLLECTION()  "Msps",\
                                    "Oversampling",\
                                    "Ref MHz",\
                                    "Fout MHz",\
                                    "Mhz",\
                                    " ",\
                                    "dB",\
                                    "DC_I",\
                                    "DC_Q",\
                                    "None"



#define SET_STRING_COLLECTION() "EnableChannel" ,\
                                "LMS Init",\
                                "Sample Rate",\
                                "Filter BWFreq",\
                                "Sample Rate Dir",\
                                "LO Frequency",\
                                "Normalized Gain",\
                                "GaindB",\
                                "Test Signal",\
                                "Antenna"


/**************************************************
 **************** MENU GENERATOR ******************
 **************************************************/

#define NONE_API_LIST   PUSH_TO_LIST(string_list[EnableChannel])\
                        PUSH_TO_LIST(string_list[LMSInit])

#define SET_API_LIST    PUSH_TO_LIST(string_list[samplerate])\
                        PUSH_TO_LIST(string_list[filterbwfreq])\
                        PUSH_TO_LIST(string_list[sampleratedir])\
                        PUSH_TO_LIST(string_list[lofrequency])\
                        PUSH_TO_LIST(string_list[normalizedgain])\
                        PUSH_TO_LIST(string_list[gaindb])\
                        PUSH_TO_LIST(string_list[testsignal])

#define GET_API_LIST    PUSH_TO_LIST(string_list[samplerate])\
                        PUSH_TO_LIST(string_list[lofrequency])\
                        PUSH_TO_LIST(string_list[antenna])\
                        PUSH_TO_LIST(string_list[normalizedgain])\
                        PUSH_TO_LIST(string_list[gaindb])\
                        PUSH_TO_LIST(string_list[testsignal])




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
    void Opcode_to_GUI();
    
    QString units_label;
    std::vector<slide_utils> slider_cfg;
    std::vector<double> slider_rate={0,0};
    seters_list_enum API_ID = sizeofsetersEnum;
    ~MainWindow();

private:
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
