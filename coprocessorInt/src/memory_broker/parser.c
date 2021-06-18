#include "LMS7002M.h"
#include "parser.h"

Geric_Parameter Params[MAX_PARAMETERS];

typedef LMS7002M_t* create_cb(LMS7002M_spi_transact_t );
Caller Create[]=
{ 
    {&LMS7002M_create} //ID 0 
};

typedef void general_cfg(LMS7002M_t *);
Caller One_Param_LMS7002M_t[] = 
{
    {&LMS7002M_regs},                  //0x1
    {&LMS7002M_destroy},               //0x21
    {&LMS7002M_regs_to_rfic},          //0x41
    {&LMS7002M_rfic_to_regs},          //0x61
    {&LMS7002M_reset},                 //0x81
    {&LMS7002M_power_down},            //0xA1
    {&LMS7002M_setup_digital_loopback} //0xC1
};

typedef void SPI_write_foo(LMS7002M_t *, const int , const int );
Caller Spi_write[] =
{
    {&LMS7002M_spi_write} //0x2 
};

typedef int SPI_config(LMS7002M_t *, const int );
Caller SPI_Config[]=
{
    {&LMS7002M_spi_read},      //0x3
    {&LMS7002M_regs_spi_write},//0x23
    {&LMS7002M_regs_spi_read}, //0x43
    {&LMS7002M_set_spi_mode},  //0x63
};

typedef int Ini_stuff(LMS7002M_t *, const char *);
Caller X_ini []=
{
    {&LMS7002M_dump_ini},
    {&LMS7002M_load_ini}
};

typedef void callback_5(LMS7002M_t *, const LMS7002M_port_t , const LMS7002M_dir_t , const int );
Caller configure_lml_port [] = 
{
    {&LMS7002M_configure_lml_port}
};

typedef void callback_6(LMS7002M_t *, const bool );
Caller One_Param_const_bool [] =
{
    {&LMS7002M_invert_fclk},
    {&LMS7002M_xbuf_share_tx},
    {&LMS7002M_xbuf_enable_bias},
    {&LMS7002M_sxt_to_sxr},
};

typedef void callback_7(LMS7002M_t *, const LMS7002M_chan_t );
Caller One_Param_LMS7002M_chan[] =
{
    {&LMS7002M_reset_lml_fifo},
    {&LMS7002M_set_mac_dir},
    {&LMS7002M_set_mac_ch},
    {&LMS7002M_txtsp_tsg_tone},
    {&LMS7002M_rxtsp_tsg_tone},
};

typedef void callback_8(LMS7002M_t *, const LMS7002M_dir_t , const int );
Caller Two_Param_LMS7002M_dir_int[] =
{
    {&LMS7002M_set_diq_mux},
};
typedef void callback_9(LMS7002M_t *, const bool , const int );
Caller LDO_enable[] =
{
    {&LMS7002M_ldo_enable},
    
};
typedef void callback_10(LMS7002M_t *, const LMS7002M_dir_t , const LMS7002M_chan_t , const bool );
Caller AFE_enable[] =
{
    {&LMS7002M_afe_enable},
    
};
typedef int callback_11(LMS7002M_t *, const double , const double , double *);
Caller Set_data_clock[] =
{
    {&LMS7002M_set_data_clock},
    
};
typedef void callback_12(LMS7002M_t *, const LMS7002M_dir_t , const LMS7002M_chan_t , const double );
Caller Set_nco_freq[]  =
{
    {&LMS7002M_set_nco_freq},
};

typedef int callback_13( LMS7002M_t *, 
                         const LMS7002M_dir_t , 
                         const LMS7002M_chan_t , 
                         const int , 
                         const short *, 
                         const size_t );

Caller Set_gfir_taps[] =
{
    {&LMS7002M_set_gfir_taps}
};

typedef int callback_14(LMS7002M_t *, const LMS7002M_dir_t , const double , const double , double *);
Caller Set_lo_freq[]  =
{
    {&LMS7002M_set_lo_freq}
};

typedef void callback_15(LMS7002M_t *, const LMS7002M_chan_t , const bool );
Caller Two_Param_LMS_const_bool [] =
{
    {&LMS7002M_sxx_enable},
    {&LMS7002M_txtsp_enable},
    {&LMS7002M_tbb_enable},
    {&LMS7002M_trf_enable},
    {&LMS7002M_trf_enable_loopback},
    {&LMS7002M_rxtsp_enable},
    {&LMS7002M_rbb_enable},
    {&LMS7002M_rbb_set_test_out},
    {&LMS7002M_rfe_enable}
};

typedef void callback_16(LMS7002M_t *, const LMS7002M_chan_t , const size_t );
Caller Two_Param_chant_sizet [] =
{
    {&LMS7002M_txtsp_set_interp},
    {&LMS7002M_rxtsp_set_decim}
};


typedef void callback_17(LMS7002M_t *, const LMS7002M_chan_t , const int , const int );
Caller sp_tsg [] =
{
    {&LMS7002M_txtsp_tsg_const},
    {&LMS7002M_rxtsp_tsg_const},
};

typedef void callback_18(LMS7002M_t *,const LMS7002M_chan_t,const double,const double);
Caller txstp_correction [] =
{
    {&LMS7002M_txtsp_set_dc_correction},
    {&LMS7002M_txtsp_set_iq_correction},
    
};

typedef void callback_19(LMS7002M_t *,const LMS7002M_chan_t,const bool,const int);
Caller rxtsp[] = 
{
    {&LMS7002M_rxtsp_set_dc_correction},
    {&LMS7002M_rxtsp_set_iq_correction},
    
};

typedef void callback_20(LMS7002M_t *, const LMS7002M_chan_t , const int );
Caller set_path_and_band [] =
{
    {&LMS7002M_tbb_set_path},
    {&LMS7002M_tbb_set_test_in},
    {&LMS7002M_trf_select_band},
    {&LMS7002M_rbb_set_path},
    {&LMS7002M_rfe_set_path}, 
};

typedef void callback_21(LMS7002M_t *, const LMS7002M_chan_t , const int , const bool );
Caller Tbb_loop_Back_enable [] = 
{
    {&LMS7002M_tbb_enable_loopback},
    
};

typedef int callback_22(LMS7002M_t *, const LMS7002M_chan_t , const double , double *);
Caller bb_filer_set []=
{
    {&LMS7002M_tbb_set_filter_bw},
    {&LMS7002M_rbb_set_filter_bw},
};


typedef double callback_23(LMS7002M_t *,const LMS7002M_chan_t, const double);
Caller trf_rbb_rfe [] = 
{
    {&LMS7002M_txtsp_set_freq},
    {&LMS7002M_rxtsp_set_freq},
    {&LMS7002M_trf_set_pad},
    {&LMS7002M_trf_set_loopback_pad},
    {&LMS7002M_rbb_set_pga},
    {&LMS7002M_rfe_set_lna},
    {&LMS7002M_rfe_set_loopback_lna},
    {&LMS7002M_rfe_set_tia},
};

typedef uint16_t READ_rssi(LMS7002M_t *, const LMS7002M_chan_t );
Caller ReadRSSI [] =
{ 
    {&LMS7002M_rxtsp_read_rssi},
};

Caller* Group [OPCODE_SIZE] =
{
    &Create[0],
    &One_Param_LMS7002M_t[0],
    &Spi_write[0],
    &SPI_Config[0],
    &X_ini[0],
    &configure_lml_port[0],
    &One_Param_const_bool[0],
    &One_Param_LMS7002M_chan[0],
    &Two_Param_LMS7002M_dir_int[0],
    &LDO_enable[0],
    &AFE_enable[0],
    &Set_data_clock[0], // double 
    &Set_nco_freq[0], // double
    &Set_gfir_taps[0],
    &Set_lo_freq[0], // double 
    &Two_Param_LMS_const_bool[0],
    &Two_Param_chant_sizet[0],
    &sp_tsg[0],
    &txstp_correction[0], // double
    &rxtsp[0],
    &set_path_and_band[0],
    &Tbb_loop_Back_enable[0],
    &bb_filer_set[0],//double
    &trf_rbb_rfe[0],//double
    &ReadRSSI[0]
};



void search_by_ID(LMS7002M_t *lms, int ID)
{
    uint8_t Group_ID = ID & 31; // only get first 5 bits
    uint8_t SN = ID >> 5;
    void* foo    = Group[Group_ID][SN].foo; // get the function

    switch (Group_ID)
    {
    case CREATE_NUM:
        ((create_cb*)foo)(NULL);
       break;
    case ONE_PARAM_LMS7002M_T_NUM:
        ((general_cfg*)foo)(lms);
        break;
    case SPI_WRITE_NUM:
        ((SPI_write_foo*)foo)(lms,INT(0),INT(1));
        break;
    case SPI_CONFIG_NUM:
        ((SPI_config*)foo)(lms,INT(0));
        break;
    case INI_NUM:
        ((Ini_stuff*)foo)(lms,STR(0));
        break;
    case CONFIGURE_LML_PORT_NUM:
        ((callback_5*)foo)(lms,
                           ENUM(0),
                           ENUM(1),
                           CONSINT(2));
        break;
    case ONE_PARAM_CONST_BOOL_NUM:
        ((callback_6*)foo)(lms,BOOLEAN(0));
        break;
    case ONE_PARAM_LMS7002M_CHAN_NUM:
        ((callback_7*)foo)(lms,ENUM(0));
        break;
    case TWO_PARAM_LMS7002M_DIR_INT_NUM:
        ((callback_8*)foo)(lms, ENUM(0),
                                CONSINT(1));
        break;
    case LDO_ENABLE_NUM:
        ((callback_9*)foo)(lms, BOOLEAN(0),
                                CONSINT(1));
        break;
    case AFE_ENABLE_NUM:
        ((callback_10*)foo)(lms,ENUM(0),
                                ENUM(1),
                                BOOLEAN(2));
        break;
    case SET_DATA_CLOCK_NUM:
        ((callback_11*)foo)(lms,DOUBLE(0),
                                DOUBLE(1),
                                DOUBLE_POINTER(2));
        break;
    case SET_NCO_FREQ_NUM:
        ((callback_12*)foo)(lms,ENUM(0),
                                ENUM(1),
                                DOUBLE(2));
        break;
    case SET_GFIR_TAPS_NUM:
        ((callback_13*)foo)(lms,ENUM(0),
                                ENUM(1),
                                INT(2),
                                SHORT_POINTER(3),
                                SIZE_TYPE(4));
        break;
    case SET_LO_FREQ_NUM:
        ((callback_14*)foo)(lms,ENUM(0),
                                DOUBLE(1),
                                DOUBLE(2),
                                DOUBLE_POINTER(3));
        break;
    case TWO_PARAM_LMS_CONST_BOOL_NUM:
        ((callback_15*)foo)(lms,ENUM(0),
                                BOOLEAN(1));
        break;
    case TWO_PARAM_CHANT_SIZET_NUM:
        ((callback_16*)foo)(lms,ENUM(0),
                                SIZE_TYPE(1));
        break;
    case SP_TSG_NUM:
        ((callback_17*)foo)(lms,ENUM(0),
                                INT(1),
                                INT(2));
        break;
    case TXSTP_CORRECTION_NUM:
        ((callback_18*)foo)(lms,ENUM(0),
                                DOUBLE(1),
                                DOUBLE(2));
        break;
    case RXTSP_NUM:
        ((callback_19*)foo)(lms,ENUM(0),
                                BOOLEAN(1),
                                CONSINT(2));
        break;
    case SET_PATH_AND_BAND_NUM:
        ((callback_20*)foo)(lms,ENUM(0),
                                INT(1));
        break;
    case TBB_LOOP_BACK_ENABLE_NUM:
        ((callback_21*)foo)(lms,ENUM(0),
                                INT(1),
                                BOOLEAN(2));
        break;
    case BB_FILER_SET_NUM:
        ((callback_22*)foo)(lms,ENUM(0),
                                DOUBLE(1),
                                DOUBLE_POINTER(2));
        break;
    case TRF_RBB_RFE_NUM:
        ((callback_23*)foo)(lms,ENUM(0),
                                DOUBLE(1));
        break;
    case READRSSI_NUM:
        ((READ_rssi*)foo)(lms,ENUM(0));
        break;

    default:
        break;
    }

}