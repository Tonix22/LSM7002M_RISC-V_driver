#include "description.h"
#include <vector>
#include <mainwindow.h>

std::vector<const char*> info[Qt_labels_size]=
{
	{{LMS7002M_CREATE_DESCRIPTION(),LMS7002M_DESTROY_DESCRIPTION()}},
	{{LMS7002M_REGS_DESCRIPTION(),LMS7002M_REGS_TO_RFIC_DESCRIPTION(),LMS7002M_RFIC_TO_REGS_DESCRIPTION()}},
	{{LMS7002M_RESET_DESCRIPTION(),LMS7002M_POWER_DOWN_DESCRIPTION()}},
	{{LMS7002M_SETUP_DIGITAL_LOOPBACK_DESCRIPTION(),LMS7002M_CONFIGURE_LML_PORT_DESCRIPTION()}},
	{{LMS7002M_SPI_WRITE_DESCRIPTION(),LMS7002M_SPI_READ_DESCRIPTION(),LMS7002M_REGS_SPI_WRITE_DESCRIPTION(),LMS7002M_REGS_SPI_READ_DESCRIPTION(),LMS7002M_SET_SPI_MODE_DESCRIPTION()}},
	{{LMS7002M_DUMP_INI_DESCRIPTION(),LMS7002M_LOAD_INI_DESCRIPTION()}},
	{{LMS7002M_INVERT_FCLK_DESCRIPTION(),LMS7002M_SXT_TO_SXR_DESCRIPTION()}},
	{{LMS7002M_XBUF_SHARE_TX_DESCRIPTION(),LMS7002M_XBUF_ENABLE_BIAS_DESCRIPTION(),LMS7002M_RESET_LML_FIFO_DESCRIPTION()}},
	{{LMS7002M_SET_MAC_DIR_DESCRIPTION(),LMS7002M_SET_MAC_CH_DESCRIPTION()}},
	{{LMS7002M_TXTSP_TSG_TONE_DESCRIPTION(),LMS7002M_RXTSP_TSG_TONE_DESCRIPTION(),LMS7002M_RFE_SET_PATH_DESCRIPTION()}},
	{{LMS7002M_SET_DIQ_MUX_DESCRIPTION(),LMS7002M_TXTSP_TSG_CONST_DESCRIPTION(),LMS7002M_RXTSP_TSG_CONST_DESCRIPTION(),LMS7002M_TBB_ENABLE_LOOPBACK_DESCRIPTION()}},
	{{LMS7002M_LDO_ENABLE_DESCRIPTION(),LMS7002M_AFE_ENABLE_DESCRIPTION(),LMS7002M_SXX_ENABLE_DESCRIPTION(),LMS7002M_TXTSP_ENABLE_DESCRIPTION(),LMS7002M_TBB_ENABLE_DESCRIPTION(),LMS7002M_TRF_ENABLE_DESCRIPTION(),LMS7002M_TRF_ENABLE_LOOPBACK_DESCRIPTION(),LMS7002M_RXTSP_ENABLE_DESCRIPTION(),LMS7002M_RBB_ENABLE_DESCRIPTION(),LMS7002M_RFE_ENABLE_DESCRIPTION()}},
	{{LMS7002M_SET_DATA_CLOCK_DESCRIPTION(),LMS7002M_TXTSP_SET_INTERP_DESCRIPTION(),LMS7002M_RXTSP_SET_DECIM_DESCRIPTION()}},
	{{LMS7002M_SET_NCO_FREQ_DESCRIPTION(),LMS7002M_SET_LO_FREQ_DESCRIPTION(),LMS7002M_TXTSP_SET_FREQ_DESCRIPTION(),LMS7002M_RXTSP_SET_FREQ_DESCRIPTION()}},
	{{LMS7002M_SET_GFIR_TAPS_DESCRIPTION()}},
	{{LMS7002M_RBB_SET_TEST_OUT_DESCRIPTION(),LMS7002M_TBB_SET_TEST_IN_DESCRIPTION()}},
	{{LMS7002M_TXTSP_SET_DC_CORRECTION_DESCRIPTION(),LMS7002M_TXTSP_SET_IQ_CORRECTION_DESCRIPTION(),LMS7002M_RXTSP_SET_DC_CORRECTION_DESCRIPTION(),LMS7002M_RXTSP_SET_IQ_CORRECTION_DESCRIPTION(),LMS7002M_TBB_SET_FILTER_BW_DESCRIPTION(),LMS7002M_RBB_SET_FILTER_BW_DESCRIPTION()}},
	{{LMS7002M_TBB_SET_PATH_DESCRIPTION(),LMS7002M_TRF_SELECT_BAND_DESCRIPTION(),LMS7002M_RBB_SET_PATH_DESCRIPTION()}},
	{{LMS7002M_TRF_SET_PAD_DESCRIPTION(),LMS7002M_TRF_SET_LOOPBACK_PAD_DESCRIPTION(),LMS7002M_RBB_SET_PGA_DESCRIPTION(),LMS7002M_RFE_SET_LNA_DESCRIPTION(),LMS7002M_RFE_SET_LOOPBACK_LNA_DESCRIPTION(),LMS7002M_RFE_SET_TIA_DESCRIPTION()}},
	{{LMS7002M_RXTSP_READ_RSSI_DESCRIPTION()}}
};