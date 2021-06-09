#include "LMS7002M.h"
#include "parser.h"

#define MAX_PARAMETERS

Geric_Parameter Params[5];


typedef LMS7002M_t* create_cb(LMS7002M_spi_transact_t );
Caller Create[]=
{ 
    {0x20, &LMS7002M_create},
    {0,NULL}
};

typedef void general_cfg(LMS7002M_t *);
Caller One_Param_LMS7002M_t[] = 
{
    {0xE5,&LMS7002M_regs},
    {0x41,  &LMS7002M_destroy},
    {0x101, &LMS7002M_regs_to_rfic},
    {0x121, &LMS7002M_rfic_to_regs},
    {0x1A1, &LMS7002M_reset},
    {0x1E1, &LMS7002M_power_down},
    {0x241, &LMS7002M_setup_digital_loopback},
    {0,NULL}
};

typedef void SPI_write_foo(LMS7002M_t *, const int , const int );
Caller Spi_write[] =
{
    {0x62, &LMS7002M_spi_write},
    {0,NULL}
};

typedef int SPI_config(LMS7002M_t *, const int );
Caller SPI_Config[]=
{
    {0x83, &LMS7002M_spi_read},
    {0xA4, &LMS7002M_regs_spi_write},
    {0xC4, &LMS7002M_regs_spi_read},
    {0x184, &LMS7002M_set_spi_mode},
    {0,NULL},
};

typedef int Ini_stuff(LMS7002M_t *, const char *);
Caller X_ini []=
{
    {0x146, &LMS7002M_dump_ini},
    {0x166, &LMS7002M_load_ini},
    {0,NULL}
};

typedef void callback_7(LMS7002M_t *, const LMS7002M_port_t , const LMS7002M_dir_t , const int );
Caller configure_lml_port [] = 
{
    {0x208, &LMS7002M_configure_lml_port},
    {0,NULL}
};

typedef void callback_8(LMS7002M_t *, const bool );
Caller One_Param_const_bool [] =
{
    {0x229, &LMS7002M_invert_fclk},
    {0x2E9, &LMS7002M_xbuf_share_tx},
    {0x309, &LMS7002M_xbuf_enable_bias},
    {0x3E9, &LMS7002M_sxt_to_sxr},
    {0,NULL}
};

typedef void callback_9(LMS7002M_t *, const LMS7002M_chan_t );
Caller One_Param_LMS7002M_chan[] =
{
    {0x1C7, &LMS7002M_reset_lml_fifo},
    {0x287, &LMS7002M_set_mac_dir},
    {0x26A, &LMS7002M_set_mac_ch},
    {0x48A, &LMS7002M_txtsp_tsg_tone},
    {0x6AA, &LMS7002M_rxtsp_tsg_tone},
    {0,NULL}
};

typedef void callback_10(LMS7002M_t *, const LMS7002M_dir_t , const int );
Caller Two_Param_LMS7002M_dir_int[] =
{
    {0x2AB, &LMS7002M_set_diq_mux},
    {0,NULL}
};
typedef void callback_11(LMS7002M_t *, const bool , const int );
Caller LDO_enable[] =
{
    {0x2CC, &LMS7002M_ldo_enable},
    {0,NULL}
};
typedef void callback_12(LMS7002M_t *, const LMS7002M_dir_t , const LMS7002M_chan_t , const bool );
Caller AFE_enable[] =
{
    {0x32D, &LMS7002M_afe_enable},
    {0,NULL}
};
typedef int callback_13(LMS7002M_t *, const double , const double , double *);
Caller Set_data_clock[] =
{
    {0x34E, &LMS7002M_set_data_clock},
    {0,NULL}
};
typedef void callback_14(LMS7002M_t *, const LMS7002M_dir_t , const LMS7002M_chan_t , const double );
Caller Set_nco_freq[]  =
{
    {0x36F, &LMS7002M_set_nco_freq},
    {0,NULL}
};

typedef int callback_15( LMS7002M_t *, 
                         const LMS7002M_dir_t , 
                         const LMS7002M_chan_t , 
                         const int , 
                         const short *, 
                         const size_t );

Caller Set_gfir_taps[] =
{
    {0x390, &LMS7002M_set_gfir_taps},
    {0,NULL}
};

typedef int callback_16(LMS7002M_t *, const LMS7002M_dir_t , const double , const double , double *);
Caller Set_lo_freq[]  =
{
    {0x3D2, &LMS7002M_set_lo_freq},
    {0,NULL}
};

typedef void callback_17(LMS7002M_t *, const LMS7002M_chan_t , const bool );
Caller Two_Param_LMS_const_bool [] =
{
    {0x3B1, &LMS7002M_sxx_enable},
    {0x413, &LMS7002M_txtsp_enable},
    {0x4F3, &LMS7002M_tbb_enable},
    {0x593, &LMS7002M_trf_enable},
    {0x5D3, &LMS7002M_trf_enable_loopback},
    {0x633, &LMS7002M_rxtsp_enable},
    {0x733, &LMS7002M_rbb_enable},
    {0x773, &LMS7002M_rbb_set_test_out},
    {0x7D3, &LMS7002M_rfe_enable},
    {0,NULL}
};

typedef void callback_18(LMS7002M_t *, const LMS7002M_chan_t , const size_t );
Caller Two_Param_chant_sizet [] =
{
    {0x434, &LMS7002M_txtsp_set_interp},
    {0x654, &LMS7002M_rxtsp_set_decim},
    {0,NULL}
};


typedef void callback_19(LMS7002M_t *, const LMS7002M_chan_t , const int , const int );
Caller sp_tsg [] =
{
    {0x476, &LMS7002M_txtsp_tsg_const},
    {0x696, &LMS7002M_rxtsp_tsg_const},
    {0,NULL}
};

typedef void callback_20(LMS7002M_t *,const LMS7002M_chan_t,const double,const double);
Caller txstp_correction [] =
{
    {0x4B7, &LMS7002M_txtsp_set_dc_correction},
    {0x4D7, &LMS7002M_txtsp_set_iq_correction},
    {0,NULL}
};

typedef void callback_21(LMS7002M_t *,const LMS7002M_chan_t,const bool,const int);
Caller rxtsp[] = 
{
    {0x6F8, &LMS7002M_rxtsp_set_dc_correction},
    {0x718, &LMS7002M_rxtsp_set_iq_correction},
    {0,NULL}
};


typedef void callback_22(LMS7002M_t *, const LMS7002M_chan_t , const int );
Caller set_path_and_band [] =
{
    {0x519, &LMS7002M_tbb_set_path},
    {0x539, &LMS7002M_tbb_set_test_in},
    {0x5B9, &LMS7002M_trf_select_band},
    {0x759, &LMS7002M_rbb_set_path},
    {0x7F9, &LMS7002M_rfe_set_path},
    {0,NULL}
};

typedef void callback_23(LMS7002M_t *, const LMS7002M_chan_t , const int , const bool );
Caller Tbb_loop_Back_enable [] = 
{
    {0x55A, &LMS7002M_tbb_enable_loopback},
    {0,NULL}
};

typedef int callback_24(LMS7002M_t *, const LMS7002M_chan_t , const double , double *);
Caller bb_filer_set []=
{
    {0x57B, &LMS7002M_tbb_set_filter_bw},
    {0x7BB, &LMS7002M_rbb_set_filter_bw},
    {0,NULL}
};


typedef double callback_25(LMS7002M_t *,const LMS7002M_chan_t, const double);
Caller trf_rbb_rfe [] = 
{
    {0x455, &LMS7002M_txtsp_set_freq},
    {0x675, &LMS7002M_rxtsp_set_freq},
    {0x5FC, &LMS7002M_trf_set_pad},
    {0x61C, &LMS7002M_trf_set_loopback_pad},
    {0x79C, &LMS7002M_rbb_set_pga},
    {0x81C, &LMS7002M_rfe_set_lna},
    {0x83C, &LMS7002M_rfe_set_loopback_lna},
    {0x85C, &LMS7002M_rfe_set_tia},
    {0,NULL}
};

typedef uint16_t READ_rssi(LMS7002M_t *, const LMS7002M_chan_t );
Caller ReadRSSI [] =
{ 
    {0x6DD, &LMS7002M_rxtsp_read_rssi},
    {0,NULL}
};

Caller* Opcode_to_foo [OPCODE_SIZE] =
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
    &Set_data_clock[0],
    &Set_nco_freq[0],
    &Set_gfir_taps[0],
    &Set_lo_freq[0],
    &Two_Param_LMS_const_bool[0],
    &Two_Param_chant_sizet[0],
    &sp_tsg[0],
    &txstp_correction[0],
    &rxtsp[0],
    &set_path_and_band[0],
    &Tbb_loop_Back_enable[0],
    &bb_filer_set[0],
    &trf_rbb_rfe[0],
    &ReadRSSI[0]
};

void* callback_id(Caller* var,uint32_t opcode)
{
    while(var->foo!=NULL)
    {  
        if(var->ID == opcode)
        {
            return var->foo;
        }
        var++;
    }
    return NULL;
}

void search_by_ID(LMS7002M_t *lms, int ID)
{
    int idx = ID & 31; // only get first 5 bits
    Caller* lens = Opcode_to_foo[ID]; // return a group of functions
    
    void* foo    = callback_id(lens,idx); // get the function

    switch (ID)
    {
    case CREATE_NUM:
        ((create_cb*)foo)(NULL);
       break;
    case ONE_PARAM_LMS7002M_T_NUM:
        ((general_cfg*)foo)(lms);
        break;
    case SPI_WRITE_NUM:
        ((SPI_write_foo*)foo)(lms,Params[0].value.sint,Params[1].value.sint);
        break;
    case SPI_CONFIG_NUM:
        ((SPI_config*)foo)(lms,Params[0].value.sint);
        break;
    case INI_NUM:
        ((Ini_stuff*)foo)(lms,Params[0].value.string);
        break;
    case CONFIGURE_LML_PORT_NUM:
        ((callback_7*)foo)(lms,
                           Params[0].value.enum_type,
                           Params[1].value.enum_type,
                           Params[2].value.const_int);
        break;
    case ONE_PARAM_CONST_BOOL_NUM:
        ((callback_8*)foo)(lms,Params[0].value.b);
        break;
    case ONE_PARAM_LMS7002M_CHAN_NUM:
        ((callback_9*)foo)(lms,Params[0].value.enum_type);
        break;
    case TWO_PARAM_LMS7002M_DIR_INT_NUM:
        ((callback_10*)foo)(lms,Params[0].value.enum_type,
                                Params[1].value.const_int);
        break;
    case LDO_ENABLE_NUM:
        ((callback_11*)foo)(lms,Params[0].value.b,
                                Params[1].value.const_int);
        break;
    case AFE_ENABLE_NUM:
        ((callback_12*)foo)(lms,Params[0].value.enum_type,
                                Params[1].value.enum_type,
                                Params[2].value.b);
        break;
    case SET_DATA_CLOCK_NUM:
        ((callback_13*)foo)(lms,Params[0].value.d,
                                Params[1].value.d,
                                Params[2].value.d_pointer);
        break;
    case SET_NCO_FREQ_NUM:
        ((callback_14*)foo)(lms,Params[0].value.enum_type,
                                Params[1].value.enum_type,
                                Params[2].value.d);
        break;
    case SET_GFIR_TAPS_NUM:
        ((callback_15*)foo)(lms,Params[0].value.enum_type,
                                Params[1].value.enum_type,
                                Params[2].value.sint,
                                Params[3].value.short_p,
                                Params[4].value.size);
        break;
    case SET_LO_FREQ_NUM:
        ((callback_16*)foo)(lms,Params[0].value.enum_type,
                                Params[1].value.d,
                                Params[2].value.d,
                                Params[3].value.d_pointer);
        break;
    case TWO_PARAM_LMS_CONST_BOOL_NUM:
        ((callback_17*)foo)(lms,Params[0].value.enum_type,
                                Params[1].value.b);
        break;
    case TWO_PARAM_CHANT_SIZET_NUM:
        ((callback_18*)foo)(lms,Params[0].value.enum_type,
                                Params[1].value.size);
        break;
    case SP_TSG_NUM:
        ((callback_19*)foo)(lms,Params[0].value.enum_type,
                                Params[1].value.sint,
                                Params[2].value.sint);
        break;
    case TXSTP_CORRECTION_NUM:
        ((callback_20*)foo)(lms,Params[0].value.enum_type,
                                Params[1].value.d,
                                Params[2].value.d);
        break;
    case RXTSP_NUM:
        ((callback_21*)foo)(lms,Params[0].value.enum_type,
                                Params[1].value.b,
                                Params[2].value.const_int);
        break;
    case SET_PATH_AND_BAND_NUM:
        ((callback_22*)foo)(lms,Params[0].value.enum_type,
                                Params[1].value.sint);
        break;
    case TBB_LOOP_BACK_ENABLE_NUM:
        ((callback_23*)foo)(lms,Params[0].value.enum_type,
                                Params[1].value.sint,
                                Params[2].value.b);
        break;
    case BB_FILER_SET_NUM:
        ((callback_24*)foo)(lms,Params[0].value.enum_type,
                                Params[1].value.d,
                                Params[2].value.d_pointer);
        break;
    case TRF_RBB_RFE_NUM:
        ((callback_25*)foo)(lms,Params[0].value.enum_type,
                                Params[1].value.d);
        break;
    case READRSSI_NUM:
        ((READ_rssi*)foo)(lms,Params[1].value.enum_type);
        break;

    default:
        break;
    }

}