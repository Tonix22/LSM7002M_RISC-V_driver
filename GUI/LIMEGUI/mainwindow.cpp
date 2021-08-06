#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include <QFile>
#include <QStringList>
#include <QDebug>
#include <QPushButton>
#include <utility>

std::vector<std::pair<bool,bool>> enable_ch_dir[Qt_labels_size]=
{
    {{{false,false},{false,false}}},
    {{{false,false},{false,false},{false,false}}},
    {{{false,false},{false,false}}},
    {{{false,false},{false,true}}},
    {{{false,false},{false,false},{false,false},{false,false},{false,false}}},
    {{{false,false},{false,false}}},
    {{{false,false},{false,false}}},
    {{{false,false},{false,false},{false,true}}},
    {{{false,true},{true,false}}},
    {{{true,false},{true,false},{true,false}}},
    {{{false,true},{true,false},{true,false},{true,false}}},
    {{{false,false},{true,true},{false,true},{true,false},{true,false},{true,false},{true,false},{true,false},{true,false},{true,false}}},
    {{{false,false},{true,false},{true,false}}},
    {{{true,true},{false,true},{true,false},{true,false}}},
    {{{false,false}}},
    {{{true,false},{true,false}}},
    {{{true,false},{true,false},{true,false},{true,false},{true,false},{true,false}}},
    {{{true,false},{true,false},{true,false}}},
    {{{true,false},{true,false},{true,false},{true,false},{true,false},{true,false}}},
    {{{true,false}}},
};

std::vector<int> opcode[Qt_labels_size]={
    {{0x0,0x21}},
    {{0x1,0x41,0x61}},
    {{0x81,0xA1}},
    {{0xC1,0x5}},
    {{0x2,0x3,0x23,0x43,0x63}},
    {{0x4,0x24}},
    {{0x6,0x66}},
    {{0x26,0x46,0x7}},
    {{0x27,0x47}},
    {{0x67,0x87,0x94}},
    {{0x8,0x11,0x31,0x15}},
    {{0x9,0xA,0xF,0x2F,0x4F,0x6F,0x8F,0xAF,0xCF,0x10F}},
    {{0xB,0x10,0x30}},
    {{0xC,0xE,0x17,0x37}},
    {{0xD}},
    {{0xEF,0x34}},
    {{0x12,0x32,0x13,0x33,0x16,0x36}},
    {{0x14,0x54,0x74}},
    {{0x57,0x77,0x97,0xB7,0xD7,0xF7}},
    {{0x18}}
};


/**************************************************************
 *********************SETER STRING VARIABLES*******************
 *************************************************************/

char string_list[set_cmd_size][MAX_SET_STRING_SIZE] = 
{
    SET_STRING_COLLECTION()
};
char params_list_str[Size_of_parms_idx][MAX_PARAMS_STR_SIZE]=
{
    PARAMS_STRING_COLLECTION()
};

std::unordered_map<seters_list_enum, std::pair<params_str_idx, params_str_idx>> measure_str = 
{
    {SetSamplerate    ,{Msps, Oversampling}},
    {SetFilterbwfreq  ,{Mhz,  None}},
    {SetSampleratedir ,{Msps, Oversampling}},
    {SetLofrequency   ,{Ref,  Fout}},
    {SetNormalizedgain,{EMPTY,None}},
    {SetGaindb        ,{dB,   None}},
    {SetTestsignal    ,{DC_I, DC_Q}}
};
std::vector<slide_utils> slider_ranges[sizeofsetersEnum]
{
    //max,min,steps,default
    {{100,0  ,1000, 10},{6,0,6,0}},//SetSamplerate
    {{6000,50,2147483647,500}},     //SetFilterbwfreq
    {{100,0  ,1000, 10},{6,0,6,0}},//SetSampleratedir
    {{6000,50,2147483647,500},{6000,50,2147483647,500}}, //SetLofrequency
    {{1,0,100,1}},//SetNormalizedgain
    {{100,0,100,50}},//SetGaindb
    {{1000000,0,2147483647,10000},{1000000,0,2147483647,10000}}//SetTestsignal
};


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    connect(ui->SendData,         &QPushButton::clicked,         this,&MainWindow::onButtonClicked);
    connect(ui->set_get_menu,     &QComboBox::currentTextChanged,this,&MainWindow::set_get_menu_changed);
    connect(ui->API_menu,         &QComboBox::currentTextChanged,this,&MainWindow::API_menu_trigger);
    connect(ui->Param1_input_text,&QPlainTextEdit::textChanged,  this,&MainWindow::Text_param1_changed);
    connect(ui->Param2_input_text,&QPlainTextEdit::textChanged,  this,&MainWindow::Text_param2_changed);
    //NONE MENU
    ui->API_menu->clear();
    ui->API_menu->insertItems(0, QStringList() NONE_API_LIST);
    ui->set_get_menu->clear();
    ui->set_get_menu->insertItems(0, QStringList() QT_LABELS_COLLECTION);
}

void MainWindow::onButtonClicked()
{
    int set_get_state   = ui->set_get_menu->currentIndex();
    int tx_rx_stare     = ui->tx_rx_menu->currentIndex();
    int API_ID          = ui->API_menu->currentIndex();
    int Ch              = ui->chanel_menu->currentIndex();

    std::cout<<"opcode: "<<std::hex<<opcode[set_get_state][API_ID]<<std::endl;
    

    //bridge->clear_buff(DATA_IN);
    //bridge->data_in.op = 0x30;
//
    //bridge->WriteData();

}
void MainWindow :: set_get_menu_changed(const QString &text)
{
    std::string box_str = text.toUtf8().constData();
    Qt_label_t set_get_state   = (Qt_label_t)ui->set_get_menu->currentIndex();
    
    ui->API_menu->clear();

    switch (set_get_state)
    {
        case Internal_num:
            ui->API_menu->insertItems(0, QStringList() INTERNAL_SUBMENU_COLLECTION);
        break;
        case Regs_num:
            ui->API_menu->insertItems(0, QStringList() REGS_SUBMENU_COLLECTION);
        break;
        case Power_num:
            ui->API_menu->insertItems(0, QStringList() POWER_SUBMENU_COLLECTION);
        break;
        case loopback_num:
            ui->API_menu->insertItems(0, QStringList() LOOPBACK_SUBMENU_COLLECTION);
        break;
        case SPI_num:
            ui->API_menu->insertItems(0, QStringList() SPI_SUBMENU_COLLECTION);
        break;
        case INI_num:
            ui->API_menu->insertItems(0, QStringList() INI_SUBMENU_COLLECTION);
        break;
        case Other_num:
            ui->API_menu->insertItems(0, QStringList() OTHER_SUBMENU_COLLECTION);
        break;
        case BUFF_num:
            ui->API_menu->insertItems(0, QStringList() BUFF_SUBMENU_COLLECTION);
        break;
        case MAC_num:
            ui->API_menu->insertItems(0, QStringList() MAC_SUBMENU_COLLECTION);
        break;
        case Enable_Channel_num:
            ui->API_menu->insertItems(0, QStringList() ENABLE_CHANNEL_SUBMENU_COLLECTION);
        break;
        case IQ_num:
            ui->API_menu->insertItems(0, QStringList() IQ_SUBMENU_COLLECTION);
        break;
        case Enable_num:
            ui->API_menu->insertItems(0, QStringList() ENABLE_SUBMENU_COLLECTION);
        break;
        case Sampling_num:
            ui->API_menu->insertItems(0, QStringList() SAMPLING_SUBMENU_COLLECTION);
        break;
        case Frequency_Tunning_num:
            ui->API_menu->insertItems(0, QStringList() FREQUENCY_TUNNING_SUBMENU_COLLECTION);
        break;
        case FIR_num:
            ui->API_menu->insertItems(0, QStringList() FIR_SUBMENU_COLLECTION);
        break;
        case Test_num:
            ui->API_menu->insertItems(0, QStringList() TEST_SUBMENU_COLLECTION);
        break;
        case Calibrate_num:
            ui->API_menu->insertItems(0, QStringList() CALIBRATE_SUBMENU_COLLECTION);
        break;
        case Band_num:
            ui->API_menu->insertItems(0, QStringList() BAND_SUBMENU_COLLECTION);
        break;
        case Gain_num:
            ui->API_menu->insertItems(0, QStringList() GAIN_SUBMENU_COLLECTION);
        break;
        case RSSI_num:
            ui->API_menu->insertItems(0, QStringList() RSSI_SUBMENU_COLLECTION);
        break;
    default:
        break;
    }
}

void MainWindow ::API_menu_trigger(const QString &text)
{  
    int set_get_state   = ui->set_get_menu->currentIndex();
    API_ID              = ui->API_menu->currentIndex();
    if(set_get_state < Qt_labels_size && set_get_state >=0)
    {
        ui->chanel_menu->setEnabled(enable_ch_dir[set_get_state][API_ID].first);
        ui->tx_rx_menu->setEnabled(enable_ch_dir[set_get_state][API_ID].second);
    }
}
void MainWindow :: Enable_Disable_CH_print()
{
    ui->Param1_slider_val->setText(ui->Param_1_val->value()?"Enable":"Disable");
}
void MainWindow :: SliderStep()
{
    double val1  = (ui->Param_1_val->value()*slider_rate[0])+slider_cfg[0].Min;
    double val2  = (ui->Param_2_val->value()*slider_rate[1])+slider_cfg[1].Min;
    ui->Param1_slider_val->setText((std::to_string(val1)).c_str());
    if(API_ID == SetSamplerate || API_ID == SetSampleratedir)
    {
        std::string str;
        int mul = 0x20>>((int)val2);
        if(mul == 0)
        {
            str = "AUTO";
        }else
        {
            str = std::to_string(mul)+"X";
        }
        ui->Param2_slider_val->setText(str.c_str());
    }
    else
    {
        ui->Param2_slider_val->setText((std::to_string(val2)).c_str());
    }
}
void MainWindow :: Text_param1_changed()
{
    static std::string param1_str;
    //std::cout<<"param1"<<endl;
    Text_input_register(param1_str,0);
    
}
void MainWindow :: Text_param2_changed()
{
    static std::string param2_str;
    //std::cout<<"param2"<<endl;
    Text_input_register(param2_str,1);
}

MainWindow::~MainWindow()
{
    delete bridge;
    delete ui;
}

