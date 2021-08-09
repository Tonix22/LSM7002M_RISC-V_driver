#include "common.h"

typedef enum{
	Create_submenu_num,
	Destroy_submenu_num,
	Internal_submenu_size
}Internal_num_t;

typedef enum{
	Regs_submenu_num,
	Regs_to_rfic_submenu_num,
	Rfic_to_regs_submenu_num,
	Regs_submenu_size
}Regs_num_t;

typedef enum{
	Reset_submenu_num,
	Power_down_submenu_num,
	Power_submenu_size
}Power_num_t;

typedef enum{
	Setup_digital_loopback_submenu_num,
	Configure_lml_port_submenu_num,
	loopback_submenu_size
}loopback_num_t;

typedef enum{
	Spi_write_submenu_num,
	Spi_read_submenu_num,
	Regs_spi_write_submenu_num,
	Regs_spi_read_submenu_num,
	Set_spi_mode_submenu_num,
	SPI_submenu_size
}SPI_num_t;

typedef enum{
	Dump_ini_submenu_num,
	Load_ini_submenu_num,
	INI_submenu_size
}INI_num_t;

typedef enum{
	Invert_fclk_submenu_num,
	Sxt_to_sxr_submenu_num,
	Other_submenu_size
}Other_num_t;

typedef enum{
	Xbuf_share_tx_submenu_num,
	Xbuf_enable_bias_submenu_num,
	Reset_lml_fifo_submenu_num,
	BUFF_submenu_size
}BUFF_num_t;

typedef enum{
	Set_mac_dir_submenu_num,
	Set_mac_ch_submenu_num,
	MAC_submenu_size
}MAC_num_t;

typedef enum{
	Txtsp_tsg_tone_submenu_num,
	Rxtsp_tsg_tone_submenu_num,
	Rfe_set_path_submenu_num,
	Enable_Channel_submenu_size
}Enable_Channel_num_t;

typedef enum{
	Set_diq_mux_submenu_num,
	Txtsp_tsg_const_submenu_num,
	Rxtsp_tsg_const_submenu_num,
	Tbb_enable_loopback_submenu_num,
	IQ_submenu_size
}IQ_num_t;

typedef enum{
	Ldo_enable_submenu_num,
	Afe_enable_submenu_num,
	Sxx_enable_submenu_num,
	Txtsp_enable_submenu_num,
	Tbb_enable_submenu_num,
	Trf_enable_submenu_num,
	Trf_enable_loopback_submenu_num,
	Rxtsp_enable_submenu_num,
	Rbb_enable_submenu_num,
	Rfe_enable_submenu_num,
	Enable_submenu_size
}Enable_num_t;

typedef enum{
	Set_data_clock_submenu_num,
	Txtsp_set_interp_submenu_num,
	Rxtsp_set_decim_submenu_num,
	Sampling_submenu_size
}Sampling_num_t;

typedef enum{
	Set_nco_freq_submenu_num,
	Set_lo_freq_submenu_num,
	Txtsp_set_freq_submenu_num,
	Rxtsp_set_freq_submenu_num,
	Frequency_Tunning_submenu_size
}Frequency_Tunning_num_t;

typedef enum{
	Set_gfir_taps_submenu_num,
	FIR_submenu_size
}FIR_num_t;

typedef enum{
	Rbb_set_test_out_submenu_num,
	Tbb_set_test_in_submenu_num,
	Test_submenu_size
}Test_num_t;

typedef enum{
	Txtsp_set_dc_correction_submenu_num,
	Txtsp_set_iq_correction_submenu_num,
	Rxtsp_set_dc_correction_submenu_num,
	Rxtsp_set_iq_correction_submenu_num,
	Tbb_set_filter_bw_submenu_num,
	Rbb_set_filter_bw_submenu_num,
	Calibrate_submenu_size
}Calibrate_num_t;

typedef enum{
	Tbb_set_path_submenu_num,
	Trf_select_band_submenu_num,
	Rbb_set_path_submenu_num,
	Band_submenu_size
}Band_num_t;

typedef enum{
	Trf_set_pad_submenu_num,
	Trf_set_loopback_pad_submenu_num,
	Rbb_set_pga_submenu_num,
	Rfe_set_lna_submenu_num,
	Rfe_set_loopback_lna_submenu_num,
	Rfe_set_tia_submenu_num,
	Gain_submenu_size
}Gain_num_t;

typedef enum{
	Rxtsp_read_rssi_submenu_num,
	RSSI_submenu_size
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

#define FIR_SUBMENU_COLLECTION PUSH_TO_LIST("set_gfir_taps")

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


