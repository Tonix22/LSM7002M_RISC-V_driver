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
#include "bridge.h"


/**************************************************
 **************** STRING LIST *********************
 **************************************************/


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
 **************** NEW CODE ************************
 **************************************************/

typedef enum
{
    Internal_num,
    Regs_num,
    Power_num,
    loopback_num,
    SPI_num,
    INI_num,
    Other_num,
    BUFF_num,
    MAC_num,
    Enable_Channel_num,
    IQ_num,
    Enable_num,
    Sampling_num,
    Frequency_Tunning_num,
    FIR_num,
    Test_num,
    Calibrate_num,
    Band_num,
    Gain_num,
    RSSI_num,
    Qt_labels_size
}Qt_label_t;

#define QT_LABELS_COLLECTION   PUSH_TO_LIST("Internal")\
                               PUSH_TO_LIST("Regs")\
                               PUSH_TO_LIST("Power")\
                               PUSH_TO_LIST("loopback")\
                               PUSH_TO_LIST("SPI")\
                               PUSH_TO_LIST("INI")\
                               PUSH_TO_LIST("Other")\
                               PUSH_TO_LIST("BUFF")\
                               PUSH_TO_LIST("MAC")\
                               PUSH_TO_LIST("Enable Channel")\
                               PUSH_TO_LIST("IQ")\
                               PUSH_TO_LIST("Enable")\
                               PUSH_TO_LIST("Sampling")\
                               PUSH_TO_LIST("Freq Tunning")\
                               PUSH_TO_LIST("FIR")\
                               PUSH_TO_LIST("Test")\
                               PUSH_TO_LIST("Calibrate")\
                               PUSH_TO_LIST("Band")\
                               PUSH_TO_LIST("Gain")\
                               PUSH_TO_LIST("RSSI")

typedef enum{
        Create_num,
        Destroy_num,
        Internal_size
}Internal_num_t;

typedef enum{
        Regs_sub_num,
        Regs_to_rfic_num,
        Rfic_to_regs_num,
        Regs_size
}Regs_num_t;

typedef enum{
        Reset_num,
        Power_down_num,
        Power_size
}Power_num_t;

typedef enum{
        Setup_digital_loopback_num,
        Configure_lml_port_num,
        loopback_size
}loopback_num_t;

typedef enum{
        Spi_write_num,
        Spi_read_num,
        Regs_spi_write_num,
        Regs_spi_read_num,
        Set_spi_mode_num,
        SPI_size
}SPI_num_t;

typedef enum{
        Dump_ini_num,
        Load_ini_num,
        INI_size
}INI_num_t;

typedef enum{
        Invert_fclk_num,
        Sxt_to_sxr_num,
        Other_size
}Other_num_t;

typedef enum{
        Xbuf_share_tx_num,
        Xbuf_enable_bias_num,
        Reset_lml_fifo_num,
        BUFF_size
}BUFF_num_t;

typedef enum{
        Set_mac_dir_num,
        Set_mac_ch_num,
        MAC_size
}MAC_num_t;

typedef enum{
        Txtsp_tsg_tone_num,
        Rxtsp_tsg_tone_num,
        Rfe_set_path_num,
        Enable_Channel_size
}Enable_Channel_num_t;

typedef enum{
        Set_diq_mux_num,
        Txtsp_tsg_const_num,
        Rxtsp_tsg_const_num,
        Tbb_enable_loopback_num,
        IQ_size
}IQ_num_t;

typedef enum{
        Ldo_enable_num,
        Afe_enable_num,
        Sxx_enable_num,
        Txtsp_enable_num,
        Tbb_enable_num,
        Trf_enable_num,
        Trf_enable_loopback_num,
        Rxtsp_enable_num,
        Rbb_enable_num,
        Rfe_enable_num,
        Enable_size
}Enable_num_t;

typedef enum{
        Set_data_clock_num,
        Txtsp_set_interp_num,
        Rxtsp_set_decim_num,
        Sampling_size
}Sampling_num_t;

typedef enum{
        Set_nco_freq_num,
        Set_lo_freq_num,
        Txtsp_set_freq_num,
        Rxtsp_set_freq_num,
        Frequency_Tunning_size
}Frequency_Tunning_num_t;

typedef enum{
        Set_gfir_taps_num,
        FIR_size
}FIR_num_t;

typedef enum{
        Rbb_set_test_out_num,
        Tbb_set_test_in_num,
        Test_size
}Test_num_t;

typedef enum{
        Txtsp_set_dc_correction_num,
        Txtsp_set_iq_correction_num,
        Rxtsp_set_dc_correction_num,
        Rxtsp_set_iq_correction_num,
        Tbb_set_filter_bw_num,
        Rbb_set_filter_bw_num,
        Calibrate_size
}Calibrate_num_t;

typedef enum{
        Tbb_set_path_num,
        Trf_select_band_num,
        Rbb_set_path_num,
        Band_size
}Band_num_t;

typedef enum{
        Trf_set_pad_num,
        Trf_set_loopback_pad_num,
        Rbb_set_pga_num,
        Rfe_set_lna_num,
        Rfe_set_loopback_lna_num,
        Rfe_set_tia_num,
        Gain_size
}Gain_num_t;

typedef enum{
        Rxtsp_read_rssi_num,
        RSSI_size
}RSSI_num_t;

#define INTERNAL_SUBMENU_COLLECTION PUSH_TO_LIST("create")\
                                      PUSH_TO_LIST("destroy")

#define REGS_SUBMENU_COLLECTION PUSH_TO_LIST("regs")\
                                  PUSH_TO_LIST("regs_to_rfic")\
                                  PUSH_TO_LIST("rfic_to_regs")

#define POWER_SUBMENU_COLLECTION PUSH_TO_LIST("reset")\
                                   PUSH_TO_LIST("power_down")

#define LOOPBACK_SUBMENU_COLLECTION PUSH_TO_LIST("setup_digital_loopback")\
                                      PUSH_TO_LIST("configure_lml_port")

#define SPI_SUBMENU_COLLECTION PUSH_TO_LIST("spi_write")\
                                 PUSH_TO_LIST("spi_read")\
                                 PUSH_TO_LIST("regs_spi_write")\
                                 PUSH_TO_LIST("regs_spi_read")\
                                 PUSH_TO_LIST("set_spi_mode")

#define INI_SUBMENU_COLLECTION PUSH_TO_LIST("dump_ini")\
                                 PUSH_TO_LIST("load_ini")

#define OTHER_SUBMENU_COLLECTION PUSH_TO_LIST("invert_fclk")\
                                   PUSH_TO_LIST("sxt_to_sxr")

#define BUFF_SUBMENU_COLLECTION PUSH_TO_LIST("xbuf_share_tx")\
                                  PUSH_TO_LIST("xbuf_enable_bias")\
                                  PUSH_TO_LIST("reset_lml_fifo")

#define MAC_SUBMENU_COLLECTION PUSH_TO_LIST("set_mac_dir")\
                                 PUSH_TO_LIST("set_mac_ch")

#define ENABLE_CHANNEL_SUBMENU_COLLECTION PUSH_TO_LIST("txtsp_tsg_tone")\
                                            PUSH_TO_LIST("rxtsp_tsg_tone")\
                                            PUSH_TO_LIST("rfe_set_path")

#define IQ_SUBMENU_COLLECTION PUSH_TO_LIST("set_diq_mux")\
                                PUSH_TO_LIST("txtsp_tsg_const")\
                                PUSH_TO_LIST("rxtsp_tsg_const")\
                                PUSH_TO_LIST("tbb_enable_loopback")

#define ENABLE_SUBMENU_COLLECTION PUSH_TO_LIST("ldo_enable")\
                                    PUSH_TO_LIST("afe_enable")\
                                    PUSH_TO_LIST("sxx_enable")\
                                    PUSH_TO_LIST("txtsp_enable")\
                                    PUSH_TO_LIST("tbb_enable")\
                                    PUSH_TO_LIST("trf_enable")\
                                    PUSH_TO_LIST("trf_enable_loopback")\
                                    PUSH_TO_LIST("rxtsp_enable")\
                                    PUSH_TO_LIST("rbb_enable")\
                                    PUSH_TO_LIST("rfe_enable")

#define SAMPLING_SUBMENU_COLLECTION PUSH_TO_LIST("set_data_clock")\
                                      PUSH_TO_LIST("txtsp_set_interp")\
                                      PUSH_TO_LIST("rxtsp_set_decim")

#define FREQUENCY_TUNNING_SUBMENU_COLLECTION PUSH_TO_LIST("set_nco_freq")\
                                               PUSH_TO_LIST("set_lo_freq")\
                                               PUSH_TO_LIST("txtsp_set_freq")\
                                               PUSH_TO_LIST("rxtsp_set_freq")

#define FIR_SUBMENU_COLLECTION  PUSH_TO_LIST("set_gfir_taps")

#define TEST_SUBMENU_COLLECTION PUSH_TO_LIST("rbb_set_test_out")\
                                  PUSH_TO_LIST("tbb_set_test_in")

#define CALIBRATE_SUBMENU_COLLECTION PUSH_TO_LIST("txtsp_set_dc_correction")\
                                       PUSH_TO_LIST("txtsp_set_iq_correction")\
                                       PUSH_TO_LIST("rxtsp_set_dc_correction")\
                                       PUSH_TO_LIST("rxtsp_set_iq_correction")\
                                       PUSH_TO_LIST("tbb_set_filter_bw")\
                                       PUSH_TO_LIST("rbb_set_filter_bw")

#define BAND_SUBMENU_COLLECTION PUSH_TO_LIST("tbb_set_path")\
                                  PUSH_TO_LIST("trf_select_band")\
                                  PUSH_TO_LIST("rbb_set_path")

#define GAIN_SUBMENU_COLLECTION PUSH_TO_LIST("trf_set_pad")\
                                  PUSH_TO_LIST("trf_set_loopback_pad")\
                                  PUSH_TO_LIST("rbb_set_pga")\
                                  PUSH_TO_LIST("rfe_set_lna")\
                                  PUSH_TO_LIST("rfe_set_loopback_lna")\
                                  PUSH_TO_LIST("rfe_set_tia")

#define RSSI_SUBMENU_COLLECTION PUSH_TO_LIST("rxtsp_read_rssi")

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
    IPDI_Bridge* bridge;
    
    QString units_label;
    std::vector<slide_utils> slider_cfg;
    std::vector<double> slider_rate={0,0};
    int API_ID = sizeofsetersEnum;
    ~MainWindow();

private:
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
