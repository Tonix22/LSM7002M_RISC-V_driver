#include "LMS7002M.h"
#include "parser.h"
#include "LMS7002M_filter_cal.h"

/**
 * @file parser_refactored.c
 * @brief Refactored version of the original parser code.
 *        Functionality remains the same, only naming, formatting,
 *        and comments have been updated.
 */

/**
 * Global parameters array
 */
Geric_Parameter Params[MAX_PARAMETERS];

/**
 * @typedef create_cb
 * Callback typedef for creating LMS7002M instances.
 */
typedef LMS7002M_t* create_cb(LMS7002M_spi_transact_t);

/**
 * @brief Array of single-callback structure for creating LMS7002M.
 */
Caller Create[] =
{
/**
 * @brief LMS7002M_create
 *	Create an instance of the LMS7002M driver.
 *	This call does not reset or initialize the LMS7002M.
 *	See LMS7002M_init(...) and LMS7002M_reset(...).
 */
    { &LMS7002M_create } // ID 0
};

/**
 * @typedef general_cfg
 * A generic configuration callback for LMS7002M.
 */
typedef void general_cfg(LMS7002M_t *);

/**
 * @brief Caller array for one-parameter LMS7002M_t type.
 *        Mapped by opcodes 0x1, 0x21, 0x41, etc.
 */
Caller One_Param_LMS7002M_t[] =
{
    { &LMS7002M_regs },                  // 0x1
/**
 * @brief LMS7002M_destroy
 *	Destroy an instance of the LMS7002M driver.
 *	This call simply fees the instance data,
 *	it does not shutdown or have any effects on the chip.
 *	Use the LMS7002M_power_down(...) call before destroy().
 */
    { &LMS7002M_destroy },               // 0x21
/**
 * @brief LMS7002M_regs_to_rfic
 *	Write the entire internal register cache to the RFIC.
 */
    { &LMS7002M_regs_to_rfic },          // 0x41
/**
 * @brief LMS7002M_rfic_to_regs
 *	Read the the entire RFIC into the internal register cache.
 */
    { &LMS7002M_rfic_to_regs },          // 0x61
/**
 * @brief LMS7002M_reset
 *	Perform all soft and hard resets available.
 *	Call this first to put the LMS7002M into a known state.
 */
    { &LMS7002M_reset },                 // 0x81
/**
 * @brief LMS7002M_power_down
 *	Put all available hardware into disable/power-down mode.
 *	Call this last before destroying the LMS7002M instance.
 */
    { &LMS7002M_power_down },            // 0xA1
/**
 * @brief LMS7002M_setup_digital_loopback
 *	Enable digital loopback inside the lime light.
 *	This call also applies the tx fifo write clock to the rx fifo.
 *	To undo the effect of this loopback, call LMS7002M_configure_lml_port().
 */
    { &LMS7002M_setup_digital_loopback } // 0xC1
};

/**
 * @typedef SPI_write_foo
 * Callback for SPI write.
 */
typedef void SPI_write_foo(LMS7002M_t *, const int, const int);

/**
 * @brief Caller array for SPI write function.
 */
Caller Spi_write[] =
{
/**
 * @brief LMS7002M_spi_write
 *	Perform a SPI write transaction on the given device.
 *	This call can be used directly to access SPI registers,
 *	rather than indirectly through the high level driver calls.
 */
    { &LMS7002M_spi_write } // 0x2
};

/**
 * @typedef SPI_config
 * Callback for SPI configuration.
 */
typedef int SPI_config(LMS7002M_t *, const int);

/**
 * @brief Caller array for SPI configuration (read/write, mode, etc.).
 */
Caller SPI_Config[] =
{
/**
 * @brief LMS7002M_spi_read
 *	Perform a SPI read transaction on the given device.
 *	This call can be used directly to access SPI registers,
 *	rather than indirectly through the high level driver calls.
 */
    { &LMS7002M_spi_read },      // 0x3
/**
 * @brief LMS7002M_regs_spi_write
 *	Write a spi register using values from the regs structure.
 */
    { &LMS7002M_regs_spi_write },// 0x23
/**
 * @brief LMS7002M_regs_spi_read
 *	Read a spi register, filling in the fields in the regs structure.
 */
    { &LMS7002M_regs_spi_read }, // 0x43
/**
 * @brief LMS7002M_set_spi_mode
 *	Set the SPI mode (4-wire or 3-wire).
 *	We recommend that you set this before any additional communication.
 */
    { &LMS7002M_set_spi_mode },  // 0x63
};

/**
 * @typedef Ini_stuff
 * Callback for INI loading/dumping.
 */
typedef int Ini_stuff(LMS7002M_t *, const char *);

/**
 * @brief Caller array for INI routines.
 */
Caller X_ini[] =
{
/**
 * @brief LMS7002M_dump_ini
 *	Dump the known registers to an INI format like the one used by the EVB7 GUI.
 */
    { &LMS7002M_dump_ini },
/**
 * @brief LMS7002M_load_ini
 *	Load registers from an INI format like the one used by the EVB7 GUI.
 */
    { &LMS7002M_load_ini }
};

/**
 * @typedef cb_configure_lml_port
 * Callback for configuring an LML port.
 */
typedef void cb_configure_lml_port(
    LMS7002M_t *,
    const LMS7002M_port_t,
    const LMS7002M_dir_t,
    const int);

/**
 * @brief Caller array for LML port configuration.
 */
Caller configure_lml_port[] =
{
/**
 * @brief LMS7002M_configure_lml_port
 *	Configure the muxing and clocking on a lime light port.
 *	This sets the data mode and direction for the DIQ pins,
 *	and selects the appropriate clock and stream muxes.
 *	This call is not compatible with JESD207 operation.
 *	The mclkDiv must be 1 for no divider, or an even value.
 *	Odd divider values besides 1 (bypass) are not allowed.
 */
    { &LMS7002M_configure_lml_port }
};

/**
 * @typedef cb_oneparam_bool
 * Callback for single boolean parameter.
 */
typedef void cb_oneparam_bool(LMS7002M_t *, const bool);

/**
 * @brief Caller array for single bool parameter.
 */
Caller One_Param_const_bool[] =
{
/**
 * @brief LMS7002M_invert_fclk
 *	Invert the feedback clock used with the transmit pins.
 *	This call inverts both FCLK1 and FCLK2 (only one of which is used).
 */
    { &LMS7002M_invert_fclk },
/**
 * @brief LMS7002M_xbuf_share_tx
 *	Share the TX XBUF clock chain to the RX XBUF clock chain.
 *	Enabled sharing when there is no clock provided to the RX input.
 */
    { &LMS7002M_xbuf_share_tx },
/**
 * @brief LMS7002M_xbuf_enable_bias
 *	Enable input biasing the DC voltage level for clock inputs.
 *	When disabled, the input clocks should be DC coupled.
 */
    { &LMS7002M_xbuf_enable_bias },
/**
 * @brief LMS7002M_sxt_to_sxr
 *	Share the transmit LO to the receive chain.
 *	This is useful for TDD modes which use the same LO for Rx and Tx.
 *	The default is disabled. Its recommended to disable SXR when using.
 */
    { &LMS7002M_sxt_to_sxr },
};

/**
 * @typedef cb_oneparam_chan
 * Callback for single channel parameter.
 */
typedef void cb_oneparam_chan(LMS7002M_t *, const LMS7002M_chan_t);

/**
 * @brief Caller array for single channel parameter.
 */
Caller One_Param_LMS7002M_chan[] =
{
/**
 * @brief LMS7002M_reset_lml_fifo
 *	Reset all logic registers and FIFO state.
 *	Use after configuring and before streaming.
 */
    { &LMS7002M_reset_lml_fifo },
/**
 * @brief LMS7002M_set_mac_dir
 *	Set the MAC mux for direction TX/RX shadow registers.
 *	For SXT and SXR, MAX is used for direction and not channel control.
 *	This call does not incur a register write if the value is unchanged.
 *	This call is mostly used internally by other calls that have to set the MAC.
 */
    { &LMS7002M_set_mac_dir },
/**
 * @brief LMS7002M_set_mac_ch
 *	Set the MAC mux for channel A/B shadow registers.
 *	This call does not incur a register write if the value is unchanged.
 *	This call is mostly used internally by other calls that have to set the MAC.
 */
    { &LMS7002M_set_mac_ch },
/**
 * @brief LMS7002M_txtsp_tsg_tone
 *	Test tone signal for TX TSP chain (TSP clk/8).
 *	Use LMS7002M_txtsp_enable() to restore regular mode.
 */
    { &LMS7002M_txtsp_tsg_tone },
/**
 * @brief LMS7002M_rxtsp_tsg_tone
 *	Test tone signal for RX TSP chain (TSP clk/8).
 *	Use LMS7002M_rxtsp_enable() to restore regular mode.
 */
    { &LMS7002M_rxtsp_tsg_tone },
    { &rx_cal_init }, // set channel
    { &tx_cal_init }
};

/**
 * @typedef cb_two_param_dir_int
 * Callback for direction + int.
 */
typedef void cb_two_param_dir_int(LMS7002M_t *, const LMS7002M_dir_t, const int);

/**
 * @brief Caller array for two params: direction + int.
 */
Caller Two_Param_LMS7002M_dir_int[] =
{
/**
 * @brief LMS7002M_set_diq_mux
 *	Set the DIQ mux to control CHA and CHB I and Q ordering.
 */
    { &LMS7002M_set_diq_mux },
};

/**
 * @typedef cb_ldo_enable
 * Callback for LDO enable.
 */
typedef void cb_ldo_enable(LMS7002M_t *, const bool, const int);

/**
 * @brief Caller array for LDO enabling.
 */
Caller LDO_enable[] =
{
/**
 * @brief LMS7002M_ldo_enable
 *	Enable/disable a group of LDOs.
 */
    { &LMS7002M_ldo_enable },
};

/**
 * @typedef cb_afe_enable
 * Callback for enabling AFE.
 */
typedef void cb_afe_enable(
    LMS7002M_t *,
    const LMS7002M_dir_t,
    const LMS7002M_chan_t,
    const bool);

/**
 * @brief Caller array for enabling AFE.
 */
Caller AFE_enable[] =
{
/**
 * @brief LMS7002M_afe_enable
 *	Enable/disable individual DACs and ADCs in the AFE section.
 *	Use the direction and channel parameters to specify a DAC/DAC.
 */
    { &LMS7002M_afe_enable },
};

/**
 * @typedef cb_set_data_clock
 * Callback for setting data clock.
 */
typedef int cb_set_data_clock(
    LMS7002M_t *,
    const double,
    const double,
    double *);

/**
 * @brief Caller array for setting data clock.
 */
Caller Set_data_clock[] =
{
/**
 * @brief LMS7002M_set_data_clock
 *	Configure the ADC/DAC clocking given the reference and the desired rate.
 *	This is a helper function that may make certain non-ideal assumptions,
 *	for example this calculation will always make use of fractional-N tuning.
 *	Also, this function does not directly set the clock muxing (see CGEN section).
 */
    { &LMS7002M_set_data_clock },
};

/**
 * @typedef cb_set_nco_freq
 * Callback for setting NCO frequency.
 */
typedef void cb_set_nco_freq(
    LMS7002M_t *,
    const LMS7002M_dir_t,
    const LMS7002M_chan_t,
    const double);

/**
 * @brief Caller array for setting NCO frequency.
 */
Caller Set_nco_freq[] =
{
/**
 * @brief LMS7002M_set_nco_freq
 *	Set the frequency for the specified NCO.
 *	Most users should use LMS7002M_xxtsp_set_freq() to handle bypasses.
 *	Note: there is a size 16 table for every NCO, we are just using entry 0.
 *	Math: freqHz = freqRel * sampleRate
 */
    { &LMS7002M_set_nco_freq },
};

/**
 * @typedef cb_set_gfir_taps
 * Callback for setting GFIR taps.
 */
typedef int cb_set_gfir_taps(
    LMS7002M_t *,
    const LMS7002M_dir_t,
    const LMS7002M_chan_t,
    const int,
    const short *,
    const size_t);

/**
 * @brief Caller array for setting GFIR taps.
 */
Caller Set_gfir_taps[] =
{
/**
 * @brief LMS7002M_set_gfir_taps
 *	Set the filter taps for one of the TSP FIR filters.
 *	If the taps array is NULL or the ntaps is 0,
 *	then the specified filter will be bypassed,
 *	otherwise, the specified filter is enabled.
 *	An error will be returned when the taps size is incorrect,
 *	or if a non-existent filter is selected (use 1, 2, or 3).
 *	Filters 1 and 2 are 40 taps, while filter 3 is 120 taps.
 */
    { &LMS7002M_set_gfir_taps },
};

/**
 * @typedef cb_set_lo_freq
 * Callback for setting LO frequency.
 */
typedef int cb_set_lo_freq(
    LMS7002M_t *,
    const LMS7002M_dir_t,
    const double,
    const double,
    double *);

/**
 * @brief Caller array for setting LO frequency.
 */
Caller Set_lo_freq[] =
{
/**
 * @brief LMS7002M_set_lo_freq
 *	The simplified tuning algorithm for the RX and TX local oscillators.
 *	Each oscillator is shared between both channels A and B.
 *	This is a helper function that may make certain non-ideal assumptions,
 *	for example this calculation will always make use of fractional-N tuning.
 */
    { &LMS7002M_set_lo_freq },
};

/**
 * @typedef cb_two_param_lms_const_bool
 * Callback for two params: channel + bool.
 */
typedef void cb_two_param_lms_const_bool(
    LMS7002M_t *,
    const LMS7002M_chan_t,
    const bool);

/**
 * @brief Caller array for channel + bool.
 */
Caller Two_Param_LMS_const_bool[] =
{
/**
 * @brief LMS7002M_sxx_enable
 *	Enable/disable the synthesizer.
 */
    { &LMS7002M_sxx_enable },
/**
 * @brief LMS7002M_txtsp_enable
 *	Initialize the TX TSP chain by:
 *	Clearing configuration values, enabling the chain,
 *	and bypassing IQ gain, phase, DC corrections, and filters.
 */
    { &LMS7002M_txtsp_enable },
/**
 * @brief LMS7002M_tbb_enable
 *	Enable/disable the TX baseband.
 */
    { &LMS7002M_tbb_enable },
/**
 * @brief LMS7002M_trf_enable
 *	Enable/disable the TX RF frontend.
 */
    { &LMS7002M_trf_enable },
/**
 * @brief LMS7002M_trf_enable_loopback
 *	Enable/disable the TX RF loopback to RFE.
 */
    { &LMS7002M_trf_enable_loopback },
/**
 * @brief LMS7002M_rxtsp_enable
 *	Initialize the RX TSP chain by:
 *	Clearing configuration values, enabling the chain,
 *	and bypassing IQ gain, phase, DC corrections, filters, and AGC.
 */
    { &LMS7002M_rxtsp_enable },
/**
 * @brief LMS7002M_rbb_enable
 *	Enable/disable the RX baseband.
 */
    { &LMS7002M_rbb_enable },
/**
 * @brief LMS7002M_rbb_set_test_out
 *	Configure the test output signal from the RX BB component.
 *	The default is false meaning that the RBB outputs to the ADC.
 */
    { &LMS7002M_rbb_set_test_out },
/**
 * @brief LMS7002M_rfe_enable
 *	Enable/disable the RX RF frontend.
 */
    { &LMS7002M_rfe_enable }
};

/**
 * @typedef cb_two_param_chant_sizet
 * Callback for two params: channel + size_t.
 */
typedef void cb_two_param_chant_sizet(
    LMS7002M_t *,
    const LMS7002M_chan_t,
    const size_t);

/**
 * @brief Caller array for channel + size_t.
 */
Caller Two_Param_chant_sizet[] =
{
/**
 * @brief LMS7002M_txtsp_set_interp
 *	Set the TX TSP chain interpolation.
 */
    { &LMS7002M_txtsp_set_interp },
/**
 * @brief LMS7002M_rxtsp_set_decim
 *	Set the RX TSP chain decimation.
 */
    { &LMS7002M_rxtsp_set_decim },
};

/**
 * @typedef cb_sp_tsg
 * Callback for TSG.
 */
typedef void cb_sp_tsg(
    LMS7002M_t *,
    const LMS7002M_chan_t,
    const int,
    const int);

/**
 * @brief Caller array for TSG.
 */
Caller sp_tsg[] =
{
/**
 * @brief LMS7002M_txtsp_tsg_const
 *	Test constant signal level for TX TSP chain.
 *	Use LMS7002M_txtsp_enable() to restore regular mode.
 */
    { &LMS7002M_txtsp_tsg_const },
/**
 * @brief LMS7002M_rxtsp_tsg_const
 *	Test constant signal level for RX TSP chain.
 *	Use LMS7002M_rxtsp_enable() to restore regular mode.
 */
    { &LMS7002M_rxtsp_tsg_const },
};

/**
 * @typedef cb_txstp_correction
 * Callback for TX STP correction.
 */
typedef void cb_txstp_correction(
    LMS7002M_t *,
    const LMS7002M_chan_t,
    const double,
    const double);

/**
 * @brief Caller array for TX STP correction.
 */
Caller txstp_correction[] =
{
/**
 * @brief LMS7002M_txtsp_set_dc_correction
 *	DC offset correction value for Tx TSP chain.
 *	Correction values are maximum 1.0 (full scale).
 */
    { &LMS7002M_txtsp_set_dc_correction },
/**
 * @brief LMS7002M_txtsp_set_iq_correction
 *	IQ imbalance correction value for Tx TSP chain.
 *	- The gain is the ratio of I/Q, and should be near 1.0
 *	- Gain values greater than 1.0 max out I and reduce Q.
 *	- Gain values less than 1.0 max out Q and reduce I.
 *	- A gain value of 1.0 bypasses the magnitude correction.
 *	- A phase value of 0.0 bypasses the phase correction.
 */
    { &LMS7002M_txtsp_set_iq_correction },
};

/**
 * @typedef cb_rxtsp
 * Callback for RX TSP.
 */
typedef void cb_rxtsp(
    LMS7002M_t *,
    const LMS7002M_chan_t,
    const bool,
    const int);

/**
 * @brief Caller array for RX TSP.
 */
Caller rxtsp[] =
{
/**
 * @brief LMS7002M_rxtsp_set_dc_correction
 *	DC offset correction value for Rx TSP chain.
 *	This subtracts out the average signal level.
 */
    { &LMS7002M_rxtsp_set_dc_correction },
/**
 * @brief LMS7002M_rxtsp_set_iq_correction
 *	IQ imbalance correction value for Rx TSP chain.
 *	- The gain is the ratio of I/Q, and should be near 1.0
 *	- Gain values greater than 1.0 max out I and reduce Q.
 *	- Gain values less than 1.0 max out Q and reduce I.
 *	- A gain value of 1.0 bypasses the magnitude correction.
 *	- A phase value of 0.0 bypasses the phase correction.
 */
    { &LMS7002M_rxtsp_set_iq_correction },
};

/**
 * @typedef cb_set_path_and_band
 * Callback for path and band selection.
 */
typedef void cb_set_path_and_band(
    LMS7002M_t *,
    const LMS7002M_chan_t,
    const int);

/**
 * @brief Caller array for path and band selection.
 */
Caller set_path_and_band[] =
{
/**
 * @brief LMS7002M_tbb_set_path
 *	Select the data path for the TX baseband.
 *	Use this to select loopback and filter paths.
 *	Calling LMS7002M_tbb_set_filter_bw() will also
 *	set the path based on the filter bandwidth setting.
 */
    { &LMS7002M_tbb_set_path },
/**
 * @brief LMS7002M_tbb_set_test_in
 *	Configure the test input signal to the TX BB component.
 *	The default is disabled (LMS7002M_TBB_TSTIN_OFF).
 */
    { &LMS7002M_tbb_set_test_in },
/**
 * @brief LMS7002M_trf_select_band
 *	Select the TX RF band (band 1 or band 2)
 */
    { &LMS7002M_trf_select_band },
/**
 * @brief LMS7002M_rbb_set_path
 *	Select the data path for the RX baseband.
 *	Use this to select loopback and filter paths.
 *	Calling LMS7002M_rbb_set_filter_bw() will also
 *	set the path based on the filter bandwidth setting.
 */
    { &LMS7002M_rbb_set_path },
/**
 * @brief LMS7002M_rfe_set_path
 *	Select the active input path for the RX RF frontend.
 */
    { &LMS7002M_rfe_set_path },
};

/**
 * @typedef cb_tbb_loop_back_enable
 * Callback for TBB loopback enable.
 */
typedef void cb_tbb_loop_back_enable(
    LMS7002M_t *,
    const LMS7002M_chan_t,
    const int,
    const bool);

/**
 * @brief Caller array for TBB loopback.
 */
Caller Tbb_loop_Back_enable[] =
{
/**
 * @brief LMS7002M_tbb_enable_loopback
 *	Enable/disable the TX BB loopback to RBB.
 */
    { &LMS7002M_tbb_enable_loopback },
};

/**
 * @typedef cb_bb_filer_set
 * Callback for BB filter set.
 */
typedef int cb_bb_filer_set(
    LMS7002M_t *,
    const LMS7002M_chan_t,
    const double,
    double *);

/**
 * @brief Caller array for BB filter set.
 */
Caller bb_filer_set[] =
{
/**
 * @brief LMS7002M_tbb_set_filter_bw
 *	Set the TX baseband filter bandwidth.
 *	The actual bandwidth will be greater than or equal to the requested bandwidth.
 */
    { &LMS7002M_tbb_set_filter_bw },
/**
 * @brief LMS7002M_rbb_set_filter_bw
 *	Set the RX baseband filter bandwidth.
 *	The actual bandwidth will be greater than or equal to the requested bandwidth.
 */
    { &LMS7002M_rbb_set_filter_bw },
};

/**
 * @typedef cb_trf_rbb_rfe
 * Callback for TRF/RBB/RFE.
 */
typedef double cb_trf_rbb_rfe(
    LMS7002M_t *,
    const LMS7002M_chan_t,
    const double);

/**
 * @brief Caller array for TRF, RBB, RFE.
 */
Caller trf_rbb_rfe[] =
{
/**
 * @brief LMS7002M_txtsp_set_freq
 *	Set the TX TSP CMIX frequency.
 *	Math: freqHz = TSPRate * sampleRate
 */
    { &LMS7002M_txtsp_set_freq },
/**
 * @brief LMS7002M_rxtsp_set_freq
 *	Set the RX TSP CMIX frequency.
 *	Math: freqHz = TSPRate * sampleRate
 */
    { &LMS7002M_rxtsp_set_freq },
/**
 * @brief LMS7002M_trf_set_pad
 *	Set the PAD gain (loss) for the TX RF frontend.
 */
    { &LMS7002M_trf_set_pad },
/**
 * @brief LMS7002M_trf_set_loopback_pad
 *	Set the PAD gain (loss) for the TX RF frontend (in RX loopback mode).
 */
    { &LMS7002M_trf_set_loopback_pad },
/**
 * @brief LMS7002M_rbb_set_pga
 *	Set the PGA gain for the RX baseband.
 */
    { &LMS7002M_rbb_set_pga },
/**
 * @brief LMS7002M_rfe_set_lna
 *	Set the LNA gain for the RX RF frontend.
 */
    { &LMS7002M_rfe_set_lna },
/**
 * @brief LMS7002M_rfe_set_loopback_lna
 *	Set the LNA gain for the RX RF frontend (in TX loopback mode).
 */
    { &LMS7002M_rfe_set_loopback_lna },
/**
 * @brief LMS7002M_rfe_set_tia
 *	Set the TIA gain for the RX RF frontend.
 */
    { &LMS7002M_rfe_set_tia },
};

/**
 * @typedef READ_rssi
 * Callback for reading RSSI.
 */
typedef uint16_t READ_rssi(LMS7002M_t *, const LMS7002M_chan_t);

/**
 * @brief Caller array for reading digital RSSI.
 */
Caller ReadRSSI[] =
{
/**
 * @brief LMS7002M_rxtsp_read_rssi
 *	Read the digital RSSI indicator in the Rx TSP chain.
 */
    { &LMS7002M_rxtsp_read_rssi },
};

/**
 * @brief Global pointer array grouping all Caller arrays by index.
 */
Caller* Group[OPCODE_SIZE] =
{
    &Create[0],                 //  0 => CREATE_NUM
    &One_Param_LMS7002M_t[0],   //  1 => ONE_PARAM_LMS7002M_T_NUM
    &Spi_write[0],              //  2 => SPI_WRITE_NUM
    &SPI_Config[0],             //  3 => SPI_CONFIG_NUM
    &X_ini[0],                  //  4 => INI_NUM
    &configure_lml_port[0],     //  5 => CONFIGURE_LML_PORT_NUM
    &One_Param_const_bool[0],   //  6 => ONE_PARAM_CONST_BOOL_NUM
    &One_Param_LMS7002M_chan[0],//  7 => ONE_PARAM_LMS7002M_CHAN_NUM
    &Two_Param_LMS7002M_dir_int[0], // 8 => TWO_PARAM_LMS7002M_DIR_INT_NUM
    &LDO_enable[0],             //  9 => LDO_ENABLE_NUM
    &AFE_enable[0],             // 10 => AFE_ENABLE_NUM
    &Set_data_clock[0],         // 11 => SET_DATA_CLOCK_NUM
    &Set_nco_freq[0],           // 12 => SET_NCO_FREQ_NUM
    &Set_gfir_taps[0],          // 13 => SET_GFIR_TAPS_NUM
    &Set_lo_freq[0],            // 14 => SET_LO_FREQ_NUM
    &Two_Param_LMS_const_bool[0],// 15 => TWO_PARAM_LMS_CONST_BOOL_NUM
    &Two_Param_chant_sizet[0],  // 16 => TWO_PARAM_CHANT_SIZET_NUM
    &sp_tsg[0],                 // 17 => SP_TSG_NUM
    &txstp_correction[0],       // 18 => TXSTP_CORRECTION_NUM
    &rxtsp[0],                  // 19 => RXTSP_NUM
    &set_path_and_band[0],      // 20 => SET_PATH_AND_BAND_NUM
    &Tbb_loop_Back_enable[0],   // 21 => TBB_LOOP_BACK_ENABLE_NUM
    &bb_filer_set[0],           // 22 => BB_FILER_SET_NUM
    &trf_rbb_rfe[0],            // 23 => TRF_RBB_RFE_NUM
    &ReadRSSI[0]               // 24 => READRSSI_NUM
};

/**
 * @brief Search function to map an integer ID to the correct function.
 *        Each Group_ID is extracted from the 5 lower bits, while SN is the upper bits.
 *
 * @param lms    pointer to LMS7002M instance
 * @param ID     integer code specifying the function to call
 */
void search_by_ID(LMS7002M_t *lms, int ID)
{
    uint8_t Group_ID = ID & 31; // only get first 5 bits
    uint8_t SN       = ID >> 5;
    void* foo        = Group[Group_ID][SN].foo; // get the function pointer

    switch (Group_ID)
    {
    case CREATE_NUM:
        ((create_cb*)foo)(NULL);
        break;
    case ONE_PARAM_LMS7002M_T_NUM:
        ((general_cfg*)foo)(lms);
        break;
    case SPI_WRITE_NUM:
        ((SPI_write_foo*)foo)(lms, INT(0), INT(1));
        break;
    case SPI_CONFIG_NUM:
        ((SPI_config*)foo)(lms, INT(0));
        break;
    case INI_NUM:
        ((Ini_stuff*)foo)(lms, STR(0));
        break;
    case CONFIGURE_LML_PORT_NUM:
        ((cb_configure_lml_port*)foo)(lms,
                                      ENUM(0),
                                      ENUM(1),
                                      CONSINT(2));
        break;
    case ONE_PARAM_CONST_BOOL_NUM:
        ((cb_oneparam_bool*)foo)(lms, BOOLEAN(0));
        break;
    case ONE_PARAM_LMS7002M_CHAN_NUM:
        ((cb_oneparam_chan*)foo)(lms, ENUM(0));
        break;
    case TWO_PARAM_LMS7002M_DIR_INT_NUM:
        ((cb_two_param_dir_int*)foo)(lms, ENUM(0), CONSINT(1));
        break;
    case LDO_ENABLE_NUM:
        ((cb_ldo_enable*)foo)(lms, BOOLEAN(0), CONSINT(1));
        break;
    case AFE_ENABLE_NUM:
        ((cb_afe_enable*)foo)(lms, ENUM(0), ENUM(1), BOOLEAN(2));
        break;
    case SET_DATA_CLOCK_NUM:
        ((cb_set_data_clock*)foo)(lms, DOUBLE(0), DOUBLE(1), DOUBLE_POINTER(2));
        break;
    case SET_NCO_FREQ_NUM:
        ((cb_set_nco_freq*)foo)(lms, ENUM(0), ENUM(1), DOUBLE(2));
        break;
    case SET_GFIR_TAPS_NUM:
        ((cb_set_gfir_taps*)foo)(lms, ENUM(0), ENUM(1), INT(2), SHORT_POINTER(3), SIZE_TYPE(4));
        break;
    case SET_LO_FREQ_NUM:
        ((cb_set_lo_freq*)foo)(lms, ENUM(0), DOUBLE(1), DOUBLE(2), DOUBLE_POINTER(3));
        break;
    case TWO_PARAM_LMS_CONST_BOOL_NUM:
        ((cb_two_param_lms_const_bool*)foo)(lms, ENUM(0), BOOLEAN(1));
        break;
    case TWO_PARAM_CHANT_SIZET_NUM:
        ((cb_two_param_chant_sizet*)foo)(lms, ENUM(0), SIZE_TYPE(1));
        break;
    case SP_TSG_NUM:
        ((cb_sp_tsg*)foo)(lms, ENUM(0), INT(1), INT(2));
        break;
    case TXSTP_CORRECTION_NUM:
        ((cb_txstp_correction*)foo)(lms, ENUM(0), DOUBLE(1), DOUBLE(2));
        break;
    case RXTSP_NUM:
        ((cb_rxtsp*)foo)(lms, ENUM(0), BOOLEAN(1), CONSINT(2));
        break;
    case SET_PATH_AND_BAND_NUM:
        ((cb_set_path_and_band*)foo)(lms, ENUM(0), INT(1));
        break;
    case TBB_LOOP_BACK_ENABLE_NUM:
        ((cb_tbb_loop_back_enable*)foo)(lms, ENUM(0), INT(1), BOOLEAN(2));
        break;
    case BB_FILER_SET_NUM:
        ((cb_bb_filer_set*)foo)(lms, ENUM(0), DOUBLE(1), DOUBLE_POINTER(2));
        break;
    case TRF_RBB_RFE_NUM:
        ((cb_trf_rbb_rfe*)foo)(lms, ENUM(0), DOUBLE(1));
        break;
    case READRSSI_NUM:
        ((READ_rssi*)foo)(lms, ENUM(0));
        break;
    default:
        break;
    }
}
