#include "mainwindow.h"
#include "../ui_mainwindow.h"
#include <iostream>

void MainWindow :: Text_input_register(std::string& msg,int index)
{
    auto input_text    = (index?ui->Param2_input_text:ui->Param1_input_text);
    auto slider        = (index?ui->Param_2_val:ui->Param_1_val);
    std::string temp   = input_text->toPlainText().toUtf8().constData();
    
    if(temp.back() == '\n')
    {
        double value_proc;
        temp.pop_back();
        value_proc = Sci_to_int(temp);
        std::cout<<value_proc<<std::endl;
        //slider->setValue((int)value_proc);
        slider->setSliderPosition((int)value_proc);
        input_text->clear();
    }
    
    /*
    std::string temp    = (*(ParamN_input_text[index]))->toPlainText().toUtf8().constData();
    int  set_get_state  = set_get_menu->currentIndex();
    std::string API_str = API_menu->currentText().toUtf8().constData();
    uint64_t value_proc = 0;
    
    if(temp.back() != '\n')
    {
        msg = temp;
    }
    else
    {
        value_proc = Sci_to_int(msg);    

        (*(Param_N_val[index]))->setValue(value_proc);
        (*(Param_N_val[index]))->setSliderPosition(value_proc);
        (*(ParamN_slider_val[index]))->setText(msg.c_str());
        if(set_get_state == Set_param )
        {
            if((bounds[API_str][index].first <= value_proc) && 
               (value_proc <= bounds[API_str][index].second))
            {
               (*(ParamN_slider_val[index]))->setText(msg.c_str());
            }
            else
            {
                if(strcmp(API_menu->currentText().toUtf8().constData(), seter_strings[lo_freq]) == 0)
                {
                    (*(ParamN_slider_val[index]))->setText(msg.c_str());
                }else
                {
                    (*(ParamN_slider_val[index]))->setText("Invalid");
                }
            }
        }
        (*(ParamN_input_text[index]))->clear();
    }
    */
}

void MainWindow :: Opcode_to_GUI()
{
    /*
    static std::string GUI_Opcode_str;
    std::string temp = Opcode_input_text->toPlainText().toUtf8().constData();
    if(temp.back() != '\n')
    {
        GUI_Opcode_str = temp;
    }
    else
    {
        char * pEnd;
        long int dec_opcode = strtol (GUI_Opcode_str.c_str(),&pEnd,16);
        int mask ;
        mask = (dec_opcode & 3);
        set_get_menu->setCurrentIndex(mask) ;// set get do
        mask = (dec_opcode & (3<<2))>>2;
        tx_rx_menu->setCurrentIndex(mask);// other, rx,tx, trx
        mask =(dec_opcode & (63<<4))>>4;
        API_menu->setCurrentText(ID_LUT[mask]);// ID
        
        Opcode_input_text->clear();
    }
    */
}

