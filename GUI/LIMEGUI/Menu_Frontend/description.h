#ifndef DESCRIPTION_H 
#define DESCRIPTION_H 
 
#define LMS7002M_CREATE_DESCRIPTION() "Create an instance of the LMS7002M driver.\r\n\
This call does not reset or initialize the LMS7002M.\r\n\
See LMS7002M_init(...) and LMS7002M_reset(...).\r\n"

#define LMS7002M_DESTROY_DESCRIPTION() "Destroy an instance of the LMS7002M driver.\r\n\
This call simply fees the instance data,\r\n\
it does not shutdown or have any effects on the chip.\r\n\
Use the LMS7002M_power_down(...) call before destroy().\r\n"

#define LMS7002M_REGS_DESCRIPTION() "Get access to the registers structure and unpacked fields.\r\n\
Use LMS7002M_regs_spi_write()/LMS7002M_regs_spi_read()\r\n\
to sync the fields in this structure with the device.\r\n"

#define LMS7002M_REGS_TO_RFIC_DESCRIPTION() "Write the entire internal register cache to the RFIC.\r\n"

#define LMS7002M_RFIC_TO_REGS_DESCRIPTION() "Read the the entire RFIC into the internal register cache.\r\n"

#define LMS7002M_RESET_DESCRIPTION() "Perform all soft and hard resets available.\r\n\
Call this first to put the LMS7002M into a known state.\r\n"

#define LMS7002M_POWER_DOWN_DESCRIPTION() "Put all available hardware into disable/power-down mode.\r\n\
Call this last before destroying the LMS7002M instance.\r\n"

#define LMS7002M_SETUP_DIGITAL_LOOPBACK_DESCRIPTION() "Enable digital loopback inside the lime light.\r\n\
This call also applies the tx fifo write clock to the rx fifo.\r\n\
To undo the effect of this loopback, call LMS7002M_configure_lml_port().\r\n"

#define LMS7002M_CONFIGURE_LML_PORT_DESCRIPTION() "Configure the muxing and clocking on a lime light port.\r\n\
This sets the data mode and direction for the DIQ pins,\r\n\
and selects the appropriate clock and stream muxes.\r\n\
This call is not compatible with JESD207 operation.\r\n\
The mclkDiv must be 1 for no divider, or an even value.\r\n\
Odd divider values besides 1 (bypass) are not allowed.\r\n"

#define LMS7002M_SPI_WRITE_DESCRIPTION() "Perform a SPI write transaction on the given device.\r\n\
This call can be used directly to access SPI registers,\r\n\
rather than indirectly through the high level driver calls.\r\n"

#define LMS7002M_SPI_READ_DESCRIPTION() "Perform a SPI read transaction on the given device.\r\n\
This call can be used directly to access SPI registers,\r\n\
rather than indirectly through the high level driver calls.\r\n"

#define LMS7002M_REGS_SPI_WRITE_DESCRIPTION() "Write a spi register using values from the regs structure.\r\n"

#define LMS7002M_REGS_SPI_READ_DESCRIPTION() "Read a spi register, filling in the fields in the regs structure.\r\n"

#define LMS7002M_SET_SPI_MODE_DESCRIPTION() "Set the SPI mode (4-wire or 3-wire).\r\n\
We recommend that you set this before any additional communication.\r\n"

#define LMS7002M_DUMP_INI_DESCRIPTION() "Dump the known registers to an INI format like the one used by the EVB7 GUI.\r\n"

#define LMS7002M_LOAD_INI_DESCRIPTION() "Load registers from an INI format like the one used by the EVB7 GUI.\r\n"

#define LMS7002M_INVERT_FCLK_DESCRIPTION() "Invert the feedback clock used with the transmit pins.\r\n\
This call inverts both FCLK1 and FCLK2 (only one of which is used).\r\n"

#define LMS7002M_SXT_TO_SXR_DESCRIPTION() "Share the transmit LO to the receive chain.\r\n\
This is useful for TDD modes which use the same LO for Rx and Tx.\r\n\
The default is disabled. Its recommended to disable SXR when using.\r\n"

#define LMS7002M_XBUF_SHARE_TX_DESCRIPTION() "Share the TX XBUF clock chain to the RX XBUF clock chain.\r\n\
Enabled sharing when there is no clock provided to the RX input.\r\n"

#define LMS7002M_XBUF_ENABLE_BIAS_DESCRIPTION() "Enable input biasing the DC voltage level for clock inputs.\r\n\
When disabled, the input clocks should be DC coupled.\r\n"

#define LMS7002M_RESET_LML_FIFO_DESCRIPTION() "Reset all logic registers and FIFO state.\r\n\
Use after configuring and before streaming.\r\n"

#define LMS7002M_SET_MAC_DIR_DESCRIPTION() "Set the MAC mux for direction TX/RX shadow registers.\r\n\
For SXT and SXR, MAX is used for direction and not channel control.\r\n\
This call does not incur a register write if the value is unchanged.\r\n\
This call is mostly used internally by other calls that have to set the MAC.\r\n"

#define LMS7002M_SET_MAC_CH_DESCRIPTION() "Set the MAC mux for channel A/B shadow registers.\r\n\
This call does not incur a register write if the value is unchanged.\r\n\
This call is mostly used internally by other calls that have to set the MAC.\r\n"

#define LMS7002M_TXTSP_TSG_TONE_DESCRIPTION() "Test tone signal for TX TSP chain (TSP clk/8).\r\n\
Use LMS7002M_txtsp_enable() to restore regular mode.\r\n"

#define LMS7002M_RXTSP_TSG_TONE_DESCRIPTION() "Test tone signal for RX TSP chain (TSP clk/8).\r\n\
Use LMS7002M_rxtsp_enable() to restore regular mode.\r\n"

#define LMS7002M_RFE_SET_PATH_DESCRIPTION() "Select the active input path for the RX RF frontend.\r\n"

#define LMS7002M_SET_DIQ_MUX_DESCRIPTION() "Set the DIQ mux to control CHA and CHB I and Q ordering.\r\n"

#define LMS7002M_TXTSP_TSG_CONST_DESCRIPTION() "Test constant signal level for TX TSP chain.\r\n\
Use LMS7002M_txtsp_enable() to restore regular mode.\r\n"

#define LMS7002M_RXTSP_TSG_CONST_DESCRIPTION() "Test constant signal level for RX TSP chain.\r\n\
Use LMS7002M_rxtsp_enable() to restore regular mode.\r\n"

#define LMS7002M_TBB_ENABLE_LOOPBACK_DESCRIPTION() "Enable/disable the TX BB loopback to RBB.\r\n"

#define LMS7002M_LDO_ENABLE_DESCRIPTION() "Enable/disable a group of LDOs.\r\n"

#define LMS7002M_AFE_ENABLE_DESCRIPTION() "Enable/disable individual DACs and ADCs in the AFE section.\r\n\
Use the direction and channel parameters to specify a DAC/DAC.\r\n"

#define LMS7002M_SXX_ENABLE_DESCRIPTION() "Enable/disable the synthesizer.\r\n"

#define LMS7002M_TXTSP_ENABLE_DESCRIPTION() "Initialize the TX TSP chain by:\r\n\
Clearing configuration values, enabling the chain,\r\n\
and bypassing IQ gain, phase, DC corrections, and filters.\r\n"

#define LMS7002M_TBB_ENABLE_DESCRIPTION() "Enable/disable the TX baseband.\r\n"

#define LMS7002M_TRF_ENABLE_DESCRIPTION() "Enable/disable the TX RF frontend.\r\n"

#define LMS7002M_TRF_ENABLE_LOOPBACK_DESCRIPTION() "Enable/disable the TX RF loopback to RFE.\r\n"

#define LMS7002M_RXTSP_ENABLE_DESCRIPTION() "Initialize the RX TSP chain by:\r\n\
Clearing configuration values, enabling the chain,\r\n\
and bypassing IQ gain, phase, DC corrections, filters, and AGC.\r\n"

#define LMS7002M_RBB_ENABLE_DESCRIPTION() "Enable/disable the RX baseband.\r\n"

#define LMS7002M_RFE_ENABLE_DESCRIPTION() "Enable/disable the RX RF frontend.\r\n"

#define LMS7002M_SET_DATA_CLOCK_DESCRIPTION() "Configure the ADC/DAC clocking given the reference and the desired rate.\r\n\
This is a helper function that may make certain non-ideal assumptions,\r\n\
for example this calculation will always make use of fractional-N tuning.\r\n\
Also, this function does not directly set the clock muxing (see CGEN section).\r\n"

#define LMS7002M_TXTSP_SET_INTERP_DESCRIPTION() "Set the TX TSP chain interpolation.\r\n"

#define LMS7002M_RXTSP_SET_DECIM_DESCRIPTION() "Set the RX TSP chain decimation.\r\n"

#define LMS7002M_SET_NCO_FREQ_DESCRIPTION() "Set the frequency for the specified NCO.\r\n\
Most users should use LMS7002M_xxtsp_set_freq() to handle bypasses.\r\n\
Note: there is a size 16 table for every NCO, we are just using entry 0.\r\n\
Math: freqHz = freqRel * sampleRate\r\n"

#define LMS7002M_SET_LO_FREQ_DESCRIPTION() "The simplified tuning algorithm for the RX and TX local oscillators.\r\n\
Each oscillator is shared between both channels A and B.\r\n\
This is a helper function that may make certain non-ideal assumptions,\r\n\
for example this calculation will always make use of fractional-N tuning.\r\n"

#define LMS7002M_TXTSP_SET_FREQ_DESCRIPTION() "Set the TX TSP CMIX frequency.\r\n\
Math: freqHz = TSPRate * sampleRate\r\n"

#define LMS7002M_RXTSP_SET_FREQ_DESCRIPTION() "Set the RX TSP CMIX frequency.\r\n\
Math: freqHz = TSPRate * sampleRate\r\n"

#define LMS7002M_SET_GFIR_TAPS_DESCRIPTION() "Set the filter taps for one of the TSP FIR filters.\r\n\
If the taps array is NULL or the ntaps is 0,\r\n\
then the specified filter will be bypassed,\r\n\
otherwise, the specified filter is enabled.\r\n\
An error will be returned when the taps size is incorrect,\r\n\
or if a non-existent filter is selected (use 1, 2, or 3).\r\n\
Filters 1 and 2 are 40 taps, while filter 3 is 120 taps.\r\n"

#define LMS7002M_RBB_SET_TEST_OUT_DESCRIPTION() "Configure the test output signal from the RX BB component.\r\n\
The default is false meaning that the RBB outputs to the ADC.\r\n"

#define LMS7002M_TBB_SET_TEST_IN_DESCRIPTION() "Configure the test input signal to the TX BB component.\r\n\
The default is disabled (LMS7002M_TBB_TSTIN_OFF).\r\n"

#define LMS7002M_TXTSP_SET_DC_CORRECTION_DESCRIPTION() "DC offset correction value for Tx TSP chain.\r\n\
Correction values are maximum 1.0 (full scale).\r\n"

#define LMS7002M_TXTSP_SET_IQ_CORRECTION_DESCRIPTION() "IQ imbalance correction value for Tx TSP chain.\r\n\
- The gain is the ratio of I/Q, and should be near 1.0\r\n\
- Gain values greater than 1.0 max out I and reduce Q.\r\n\
- Gain values less than 1.0 max out Q and reduce I.\r\n\
- A gain value of 1.0 bypasses the magnitude correction.\r\n\
- A phase value of 0.0 bypasses the phase correction.\r\n"

#define LMS7002M_RXTSP_SET_DC_CORRECTION_DESCRIPTION() "DC offset correction value for Rx TSP chain.\r\n\
This subtracts out the average signal level.\r\n"

#define LMS7002M_RXTSP_SET_IQ_CORRECTION_DESCRIPTION() "IQ imbalance correction value for Rx TSP chain.\r\n\
- The gain is the ratio of I/Q, and should be near 1.0\r\n\
- Gain values greater than 1.0 max out I and reduce Q.\r\n\
- Gain values less than 1.0 max out Q and reduce I.\r\n\
- A gain value of 1.0 bypasses the magnitude correction.\r\n\
- A phase value of 0.0 bypasses the phase correction.\r\n"

#define LMS7002M_TBB_SET_FILTER_BW_DESCRIPTION() "Set the TX baseband filter bandwidth.\r\n\
The actual bandwidth will be greater than or equal to the requested bandwidth.\r\n"

#define LMS7002M_RBB_SET_FILTER_BW_DESCRIPTION() "Set the RX baseband filter bandwidth.\r\n\
The actual bandwidth will be greater than or equal to the requested bandwidth.\r\n"

#define LMS7002M_TBB_SET_PATH_DESCRIPTION() "Select the data path for the TX baseband.\r\n\
Use this to select loopback and filter paths.\r\n\
Calling LMS7002M_tbb_set_filter_bw() will also\r\n\
set the path based on the filter bandwidth setting.\r\n"

#define LMS7002M_TRF_SELECT_BAND_DESCRIPTION() "Select the TX RF band (band 1 or band 2)\r\n"

#define LMS7002M_RBB_SET_PATH_DESCRIPTION() "Select the data path for the RX baseband.\r\n\
Use this to select loopback and filter paths.\r\n\
Calling LMS7002M_rbb_set_filter_bw() will also\r\n\
set the path based on the filter bandwidth setting.\r\n"

#define LMS7002M_TRF_SET_PAD_DESCRIPTION() "Set the PAD gain (loss) for the TX RF frontend.\r\n"

#define LMS7002M_TRF_SET_LOOPBACK_PAD_DESCRIPTION() "Set the PAD gain (loss) for the TX RF frontend (in RX loopback mode).\r\n"

#define LMS7002M_RBB_SET_PGA_DESCRIPTION() "Set the PGA gain for the RX baseband.\r\n"

#define LMS7002M_RFE_SET_LNA_DESCRIPTION() "Set the LNA gain for the RX RF frontend.\r\n"

#define LMS7002M_RFE_SET_LOOPBACK_LNA_DESCRIPTION() "Set the LNA gain for the RX RF frontend (in TX loopback mode).\r\n"

#define LMS7002M_RFE_SET_TIA_DESCRIPTION() "Set the TIA gain for the RX RF frontend.\r\n"

#define LMS7002M_RXTSP_READ_RSSI_DESCRIPTION() "Read the digital RSSI indicator in the Rx TSP chain.\r\n"

#endif
