#include "mainwindow.h"
#include "./ui_mainwindow.h"


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
    {{6000,50,2147483647,500}}, //SetLofrequency
    {{1,0,100,1}},//SetNormalizedgain
    {{100,0,100,50}},//SetGaindb
    {{1000000,0,2147483647,10000},{1000000,0,2147483647,10000}}//SetTestsignal
};


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    connect( ui->SendData, &QPushButton::clicked, this, &MainWindow::onButtonClicked);
    connect(ui->set_get_menu, &QComboBox::currentTextChanged,this,&MainWindow::set_get_menu_changed);
    connect(ui->API_menu, &QComboBox::currentTextChanged,this,&MainWindow::API_menu_trigger);

    //NONE MENU
    ui->API_menu->clear();
    ui->API_menu->insertItems(0, QStringList() NONE_API_LIST);

    this->show();
}

void MainWindow::onButtonClicked()
{
    int set_get_state   = ui->set_get_menu->currentIndex();
    int tx_rx_stare     = ui->tx_rx_menu->currentIndex();
    int API_ID = ui->API_menu->currentIndex();
    int Ch = ui->chanel_menu->currentIndex();


    std::cout<<"YUP"<<std::endl;
}
void MainWindow :: set_get_menu_changed(const QString &text)
{
    std::string box_str = text.toUtf8().constData();
    ui->API_menu->clear();

    if(box_str == "set")
    {
        ui->API_menu->insertItems(0, QStringList() SET_API_LIST);
    }
    else if(box_str == "get")
    {
        ui->API_menu->insertItems(0, QStringList() GET_API_LIST);
    }else
    {
        ui->API_menu->insertItems(0, QStringList() NONE_API_LIST);     
    }
}

void MainWindow ::API_menu_trigger(const QString &text)
{  
    int set_get_state   = ui->set_get_menu->currentIndex();
    API_ID              = (seters_list_enum)(ui->API_menu->currentIndex());
    
    if(set_get_state == SetFill && API_ID < sizeofsetersEnum && API_ID >=0)
    {

        //labels
        units_label = params_list_str[measure_str[API_ID].first];
        ui->units_label_1->setText(units_label);
        units_label = params_list_str[measure_str[API_ID].second];
        ui->units_label_2->setText(units_label);
        
        //Slider config
        ui->Param_1_val->disconnect();
        ui->Param_2_val->disconnect();
        QObject::connect(ui->Param_1_val, &QSlider::valueChanged, this, SliderStep);
        QObject::connect(ui->Param_2_val, &QSlider::valueChanged, this, SliderStep);

        slider_cfg = slider_ranges[API_ID];
            
        ui->Param_1_val->setRange(0,slider_cfg[0].Steps);
        slider_rate[0] = ((double)(slider_cfg[0].Max - slider_cfg[0].Min))/slider_cfg[0].Steps;
            
        {
            int slidePosition =DEFAULT_FORMULA(0);
            ui->Param_1_val->setValue(slidePosition);
            ui->Param_1_val->setSliderPosition(slidePosition);
            
            if(slider_cfg.size() >1 )
            {
                ui->Param_2_val->setRange(0,slider_cfg[1].Steps);
                slider_rate[1] = ((double)(slider_cfg[1].Max - slider_cfg[1].Min))/slider_cfg[1].Steps;
                slidePosition =DEFAULT_FORMULA(1);
                ui->Param_2_val->setValue(slidePosition);
                ui->Param_2_val->setSliderPosition(slidePosition);
            }else{
                ui->Param2_slider_val->setText("");
                ui->Param_2_val->disconnect();
                }
        }

    }
    else if(set_get_state == NoneFill)
    {
        ui->Param1_slider_val->setText("");
        ui->Param2_slider_val->setText("");
        if(API_ID == 0) // enable channel 
        {
            ui->Param_1_val->setRange(0,1);
            QObject::connect(ui->Param_1_val, &QSlider::valueChanged, this, Enable_Disable_CH_print);
            ui->Param_1_val->setValue(0);
            ui->Param_1_val->setSliderPosition(0);
        }
        else{goto others;}
    }
    else
    {
        ui->Param1_slider_val->setText("");
        ui->Param2_slider_val->setText("");
        others:
        ui->Param_2_val->disconnect();
        ui->Param_1_val->disconnect();
        QString units_label = params_list_str[EMPTY];
        ui->units_label_1->setText(units_label);
        ui->units_label_2->setText(units_label);
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

MainWindow::~MainWindow()
{
    delete ui;
}

