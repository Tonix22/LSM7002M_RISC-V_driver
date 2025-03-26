#include "LMS7002M.h"
#include "parser.h"
#include "LMS7002M_filter_cal.h"

Geric_Parameter Params[MAX_PARAMETERS];

// Si necesitas typedefs, colócalos aquí.

// ---- BUFF ----
// (Auto-generated array for QT Label "BUFF")
Caller BUFF[] = 
{
    /*
     * OPCODE: 7
     * API Name: LMS7002M_reset_lml_fifo
     * Description: 
Reset all logic registers and FIFO state.
Use after configuring and before streaming.

     */
    { &LMS7002M_reset_lml_fifo },

    /*
     * OPCODE: 26
     * API Name: LMS7002M_xbuf_share_tx
     * Description: 
Share the TX XBUF clock chain to the RX XBUF clock chain.
Enabled sharing when there is no clock provided to the RX input.

     */
    { &LMS7002M_xbuf_share_tx },

    /*
     * OPCODE: 46
     * API Name: LMS7002M_xbuf_enable_bias
     * Description: 
Enable input biasing the DC voltage level for clock inputs.
When disabled, the input clocks should be DC coupled.

     */
    { &LMS7002M_xbuf_enable_bias },

};

// ---- Band ----
// (Auto-generated array for QT Label "Band")
Caller Band[] = 
{
    /*
     * OPCODE: 14
     * API Name: LMS7002M_tbb_set_path
     * Description: 
Select the data path for the TX baseband.
Use this to select loopback and filter paths.
Calling LMS7002M_tbb_set_filter_bw() will also
set the path based on the filter bandwidth setting.

     */
    { &LMS7002M_tbb_set_path },

    /*
     * OPCODE: 54
     * API Name: LMS7002M_trf_select_band
     * Description: 
Select the TX RF band (band 1 or band 2)

     */
    { &LMS7002M_trf_select_band },

    /*
     * OPCODE: 74
     * API Name: LMS7002M_rbb_set_path
     * Description: 
Select the data path for the RX baseband.
Use this to select loopback and filter paths.
Calling LMS7002M_rbb_set_filter_bw() will also
set the path based on the filter bandwidth setting.

     */
    { &LMS7002M_rbb_set_path },

};

// ---- Calibrate ----
// (Auto-generated array for QT Label "Calibrate")
Caller Calibrate[] = 
{
    /*
     * OPCODE: 12
     * API Name: LMS7002M_txtsp_set_dc_correction
     * Description: 
DC offset correction value for Tx TSP chain.
Correction values are maximum 1.0 (full scale).

     */
    { &LMS7002M_txtsp_set_dc_correction },

    /*
     * OPCODE: 13
     * API Name: LMS7002M_rxtsp_set_dc_correction
     * Description: 
DC offset correction value for Rx TSP chain.
This subtracts out the average signal level.

     */
    { &LMS7002M_rxtsp_set_dc_correction },

    /*
     * OPCODE: 16
     * API Name: LMS7002M_tbb_set_filter_bw
     * Description: 
Set the TX baseband filter bandwidth.
The actual bandwidth will be greater than or equal to the requested bandwidth.

     */
    { &LMS7002M_tbb_set_filter_bw },

    /*
     * OPCODE: 32
     * API Name: LMS7002M_txtsp_set_iq_correction
     * Description: 
IQ imbalance correction value for Tx TSP chain.
- The gain is the ratio of I/Q, and should be near 1.0
- Gain values greater than 1.0 max out I and reduce Q.
- Gain values less than 1.0 max out Q and reduce I.
- A gain value of 1.0 bypasses the magnitude correction.
- A phase value of 0.0 bypasses the phase correction.

     */
    { &LMS7002M_txtsp_set_iq_correction },

    /*
     * OPCODE: 33
     * API Name: LMS7002M_rxtsp_set_iq_correction
     * Description: 
IQ imbalance correction value for Rx TSP chain.
- The gain is the ratio of I/Q, and should be near 1.0
- Gain values greater than 1.0 max out I and reduce Q.
- Gain values less than 1.0 max out Q and reduce I.
- A gain value of 1.0 bypasses the magnitude correction.
- A phase value of 0.0 bypasses the phase correction.

     */
    { &LMS7002M_rxtsp_set_iq_correction },

    /*
     * OPCODE: 36
     * API Name: LMS7002M_rbb_set_filter_bw
     * Description: 
Set the RX baseband filter bandwidth.
The actual bandwidth will be greater than or equal to the requested bandwidth.

     */
    { &LMS7002M_rbb_set_filter_bw },

};

// ---- Enable ----
// (Auto-generated array for QT Label "Enable")
Caller Enable[] = 
{
    /*
     * OPCODE: 9
     * API Name: LMS7002M_ldo_enable
     * Description: 
Enable/disable a group of LDOs.

     */
    { &LMS7002M_ldo_enable },

    /*
     * OPCODE: A
     * API Name: LMS7002M_afe_enable
     * Description: 
Enable/disable individual DACs and ADCs in the AFE section.
Use the direction and channel parameters to specify a DAC/DAC.

     */
    { &LMS7002M_afe_enable },

    /*
     * OPCODE: F
     * API Name: LMS7002M_sxx_enable
     * Description: 
Enable/disable the synthesizer.

     */
    { &LMS7002M_sxx_enable },

    /*
     * OPCODE: 2F
     * API Name: LMS7002M_txtsp_enable
     * Description: 
Initialize the TX TSP chain by:
Clearing configuration values, enabling the chain,
and bypassing IQ gain, phase, DC corrections, and filters.

     */
    { &LMS7002M_txtsp_enable },

    /*
     * OPCODE: 4F
     * API Name: LMS7002M_tbb_enable
     * Description: 
Enable/disable the TX baseband.

     */
    { &LMS7002M_tbb_enable },

    /*
     * OPCODE: 6F
     * API Name: LMS7002M_trf_enable
     * Description: 
Enable/disable the TX RF frontend.

     */
    { &LMS7002M_trf_enable },

    /*
     * OPCODE: 8F
     * API Name: LMS7002M_trf_enable_loopback
     * Description: 
Enable/disable the TX RF loopback to RFE.

     */
    { &LMS7002M_trf_enable_loopback },

    /*
     * OPCODE: AF
     * API Name: LMS7002M_rxtsp_enable
     * Description: 
Initialize the RX TSP chain by:
Clearing configuration values, enabling the chain,
and bypassing IQ gain, phase, DC corrections, filters, and AGC.

     */
    { &LMS7002M_rxtsp_enable },

    /*
     * OPCODE: CF
     * API Name: LMS7002M_rbb_enable
     * Description: 
Enable/disable the RX baseband.

     */
    { &LMS7002M_rbb_enable },

    /*
     * OPCODE: 10F
     * API Name: LMS7002M_rfe_enable
     * Description: 
Enable/disable the RX RF frontend.

     */
    { &LMS7002M_rfe_enable },

};

// ---- Enable Channel ----
// (Auto-generated array for QT Label "Enable Channel")
Caller Enable_Channel[] = 
{
    /*
     * OPCODE: 67
     * API Name: LMS7002M_txtsp_tsg_tone
     * Description: 
Test tone signal for TX TSP chain (TSP clk/8).
Use LMS7002M_txtsp_enable() to restore regular mode.

     */
    { &LMS7002M_txtsp_tsg_tone },

    /*
     * OPCODE: 87
     * API Name: LMS7002M_rxtsp_tsg_tone
     * Description: 
Test tone signal for RX TSP chain (TSP clk/8).
Use LMS7002M_rxtsp_enable() to restore regular mode.

     */
    { &LMS7002M_rxtsp_tsg_tone },

    /*
     * OPCODE: 94
     * API Name: LMS7002M_rfe_set_path
     * Description: 
Select the active input path for the RX RF frontend.

     */
    { &LMS7002M_rfe_set_path },

    /*
     * OPCODE: A7
     * API Name: rx_cal_init
     * Description: nan
     */
    { &rx_cal_init },

    /*
     * OPCODE: C7
     * API Name: tx_cal_init
     * Description: nan
     */
    { &tx_cal_init },

};

// ---- FIR ----
// (Auto-generated array for QT Label "FIR")
Caller FIR[] = 
{
    /*
     * OPCODE: D
     * API Name: LMS7002M_set_gfir_taps
     * Description: 
Set the filter taps for one of the TSP FIR filters.
If the taps array is NULL or the ntaps is 0,
then the specified filter will be bypassed,
otherwise, the specified filter is enabled.
An error will be returned when the taps size is incorrect,
or if a non-existent filter is selected (use 1, 2, or 3).
Filters 1 and 2 are 40 taps, while filter 3 is 120 taps.

     */
    { &LMS7002M_set_gfir_taps },

};

// ---- Frequency Tunning ----
// (Auto-generated array for QT Label "Frequency Tunning")
Caller Frequency_Tunning[] = 
{
    /*
     * OPCODE: C
     * API Name: LMS7002M_set_nco_freq
     * Description: 
Set the frequency for the specified NCO.
Most users should use LMS7002M_xxtsp_set_freq() to handle bypasses.
Note: there is a size 16 table for every NCO, we are just using entry 0.
Math: freqHz = freqRel * sampleRate

     */
    { &LMS7002M_set_nco_freq },

    /*
     * OPCODE: E
     * API Name: LMS7002M_set_lo_freq
     * Description: 
The simplified tuning algorithm for the RX and TX local oscillators.
Each oscillator is shared between both channels A and B.
This is a helper function that may make certain non-ideal assumptions,
for example this calculation will always make use of fractional-N tuning.

     */
    { &LMS7002M_set_lo_freq },

    /*
     * OPCODE: 17
     * API Name: LMS7002M_txtsp_set_freq
     * Description: 
Set the TX TSP CMIX frequency.
Math: freqHz = TSPRate * sampleRate

     */
    { &LMS7002M_txtsp_set_freq },

    /*
     * OPCODE: 37
     * API Name: LMS7002M_rxtsp_set_freq
     * Description: 
Set the RX TSP CMIX frequency.
Math: freqHz = TSPRate * sampleRate

     */
    { &LMS7002M_rxtsp_set_freq },

};

// ---- Gain ----
// (Auto-generated array for QT Label "Gain")
Caller Gain[] = 
{
    /*
     * OPCODE: 57
     * API Name: LMS7002M_trf_set_pad
     * Description: 
Set the PAD gain (loss) for the TX RF frontend.

     */
    { &LMS7002M_trf_set_pad },

    /*
     * OPCODE: 77
     * API Name: LMS7002M_trf_set_loopback_pad
     * Description: 
Set the PAD gain (loss) for the TX RF frontend (in RX loopback mode).

     */
    { &LMS7002M_trf_set_loopback_pad },

    /*
     * OPCODE: 97
     * API Name: LMS7002M_rbb_set_pga
     * Description: 
Set the PGA gain for the RX baseband.

     */
    { &LMS7002M_rbb_set_pga },

    /*
     * OPCODE: B7
     * API Name: LMS7002M_rfe_set_lna
     * Description: 
Set the LNA gain for the RX RF frontend.

     */
    { &LMS7002M_rfe_set_lna },

    /*
     * OPCODE: D7
     * API Name: LMS7002M_rfe_set_loopback_lna
     * Description: 
Set the LNA gain for the RX RF frontend (in TX loopback mode).

     */
    { &LMS7002M_rfe_set_loopback_lna },

    /*
     * OPCODE: F7
     * API Name: LMS7002M_rfe_set_tia
     * Description: 
Set the TIA gain for the RX RF frontend.

     */
    { &LMS7002M_rfe_set_tia },

};

// ---- INI ----
// (Auto-generated array for QT Label "INI")
Caller INI[] = 
{
    /*
     * OPCODE: 4
     * API Name: LMS7002M_dump_ini
     * Description: 
Dump the known registers to an INI format like the one used by the EVB7 GUI.

     */
    { &LMS7002M_dump_ini },

    /*
     * OPCODE: 24
     * API Name: LMS7002M_load_ini
     * Description: 
Load registers from an INI format like the one used by the EVB7 GUI.

     */
    { &LMS7002M_load_ini },

};

// ---- IQ ----
// (Auto-generated array for QT Label "IQ")
Caller IQ[] = 
{
    /*
     * OPCODE: 8
     * API Name: LMS7002M_set_diq_mux
     * Description: 
Set the DIQ mux to control CHA and CHB I and Q ordering.

     */
    { &LMS7002M_set_diq_mux },

    /*
     * OPCODE: 11
     * API Name: LMS7002M_txtsp_tsg_const
     * Description: 
Test constant signal level for TX TSP chain.
Use LMS7002M_txtsp_enable() to restore regular mode.

     */
    { &LMS7002M_txtsp_tsg_const },

    /*
     * OPCODE: 15
     * API Name: LMS7002M_tbb_enable_loopback
     * Description: 
Enable/disable the TX BB loopback to RBB.

     */
    { &LMS7002M_tbb_enable_loopback },

    /*
     * OPCODE: 31
     * API Name: LMS7002M_rxtsp_tsg_const
     * Description: 
Test constant signal level for RX TSP chain.
Use LMS7002M_rxtsp_enable() to restore regular mode.

     */
    { &LMS7002M_rxtsp_tsg_const },

};

// ---- Internal ----
// (Auto-generated array for QT Label "Internal")
Caller Internal[] = 
{
    /*
     * OPCODE: 0
     * API Name: LMS7002M_create
     * Description: 
Create an instance of the LMS7002M driver.
This call does not reset or initialize the LMS7002M.
See LMS7002M_init(...) and LMS7002M_reset(...).

     */
    { &LMS7002M_create },

    /*
     * OPCODE: 21
     * API Name: LMS7002M_destroy
     * Description: 
Destroy an instance of the LMS7002M driver.
This call simply fees the instance data,
it does not shutdown or have any effects on the chip.
Use the LMS7002M_power_down(...) call before destroy().

     */
    { &LMS7002M_destroy },

};

// ---- MAC ----
// (Auto-generated array for QT Label "MAC")
Caller MAC[] = 
{
    /*
     * OPCODE: 27
     * API Name: LMS7002M_set_mac_dir
     * Description: 
Set the MAC mux for direction TX/RX shadow registers.
For SXT and SXR, MAX is used for direction and not channel control.
This call does not incur a register write if the value is unchanged.
This call is mostly used internally by other calls that have to set the MAC.

     */
    { &LMS7002M_set_mac_dir },

    /*
     * OPCODE: 47
     * API Name: LMS7002M_set_mac_ch
     * Description: 
Set the MAC mux for channel A/B shadow registers.
This call does not incur a register write if the value is unchanged.
This call is mostly used internally by other calls that have to set the MAC.

     */
    { &LMS7002M_set_mac_ch },

};

// ---- Other ----
// (Auto-generated array for QT Label "Other")
Caller Other[] = 
{
    /*
     * OPCODE: 6
     * API Name: LMS7002M_invert_fclk
     * Description: 
Invert the feedback clock used with the transmit pins.
This call inverts both FCLK1 and FCLK2 (only one of which is used).

     */
    { &LMS7002M_invert_fclk },

    /*
     * OPCODE: 66
     * API Name: LMS7002M_sxt_to_sxr
     * Description: 
Share the transmit LO to the receive chain.
This is useful for TDD modes which use the same LO for Rx and Tx.
The default is disabled. Its recommended to disable SXR when using.

     */
    { &LMS7002M_sxt_to_sxr },

};

// ---- Power ----
// (Auto-generated array for QT Label "Power")
Caller Power[] = 
{
    /*
     * OPCODE: 81
     * API Name: LMS7002M_reset
     * Description: 
Perform all soft and hard resets available.
Call this first to put the LMS7002M into a known state.

     */
    { &LMS7002M_reset },

    /*
     * OPCODE: A1
     * API Name: LMS7002M_power_down
     * Description: 
Put all available hardware into disable/power-down mode.
Call this last before destroying the LMS7002M instance.

     */
    { &LMS7002M_power_down },

};

// ---- RSSI ----
// (Auto-generated array for QT Label "RSSI")
Caller RSSI[] = 
{
    /*
     * OPCODE: 18
     * API Name: LMS7002M_rxtsp_read_rssi
     * Description: 
Read the digital RSSI indicator in the Rx TSP chain.

     */
    { &LMS7002M_rxtsp_read_rssi },

};

// ---- Regs ----
// (Auto-generated array for QT Label "Regs")
Caller Regs[] = 
{
    /*
     * OPCODE: 1
     * API Name: LMS7002M_regs
     * Description: nan
     */
    { &LMS7002M_regs },

    /*
     * OPCODE: 41
     * API Name: LMS7002M_regs_to_rfic
     * Description: 
Write the entire internal register cache to the RFIC.

     */
    { &LMS7002M_regs_to_rfic },

    /*
     * OPCODE: 61
     * API Name: LMS7002M_rfic_to_regs
     * Description: 
Read the the entire RFIC into the internal register cache.

     */
    { &LMS7002M_rfic_to_regs },

};

// ---- SPI ----
// (Auto-generated array for QT Label "SPI")
Caller SPI[] = 
{
    /*
     * OPCODE: 2
     * API Name: LMS7002M_spi_write
     * Description: 
Perform a SPI write transaction on the given device.
This call can be used directly to access SPI registers,
rather than indirectly through the high level driver calls.

     */
    { &LMS7002M_spi_write },

    /*
     * OPCODE: 3
     * API Name: LMS7002M_spi_read
     * Description: 
Perform a SPI read transaction on the given device.
This call can be used directly to access SPI registers,
rather than indirectly through the high level driver calls.

     */
    { &LMS7002M_spi_read },

    /*
     * OPCODE: 23
     * API Name: LMS7002M_regs_spi_write
     * Description: 
Write a spi register using values from the regs structure.

     */
    { &LMS7002M_regs_spi_write },

    /*
     * OPCODE: 43
     * API Name: LMS7002M_regs_spi_read
     * Description: 
Read a spi register, filling in the fields in the regs structure.

     */
    { &LMS7002M_regs_spi_read },

    /*
     * OPCODE: 63
     * API Name: LMS7002M_set_spi_mode
     * Description: 
Set the SPI mode (4-wire or 3-wire).
We recommend that you set this before any additional communication.

     */
    { &LMS7002M_set_spi_mode },

};

// ---- Sampling ----
// (Auto-generated array for QT Label "Sampling")
Caller Sampling[] = 
{
    /*
     * OPCODE: B
     * API Name: LMS7002M_set_data_clock
     * Description: 
Configure the ADC/DAC clocking given the reference and the desired rate.
This is a helper function that may make certain non-ideal assumptions,
for example this calculation will always make use of fractional-N tuning.
Also, this function does not directly set the clock muxing (see CGEN section).

     */
    { &LMS7002M_set_data_clock },

    /*
     * OPCODE: 10
     * API Name: LMS7002M_txtsp_set_interp
     * Description: 
Set the TX TSP chain interpolation.

     */
    { &LMS7002M_txtsp_set_interp },

    /*
     * OPCODE: 30
     * API Name: LMS7002M_rxtsp_set_decim
     * Description: 
Set the RX TSP chain decimation.

     */
    { &LMS7002M_rxtsp_set_decim },

};

// ---- Test ----
// (Auto-generated array for QT Label "Test")
Caller Test[] = 
{
    /*
     * OPCODE: 34
     * API Name: LMS7002M_tbb_set_test_in
     * Description: 
Configure the test input signal to the TX BB component.
The default is disabled (LMS7002M_TBB_TSTIN_OFF).

     */
    { &LMS7002M_tbb_set_test_in },

    /*
     * OPCODE: EF
     * API Name: LMS7002M_rbb_set_test_out
     * Description: 
Configure the test output signal from the RX BB component.
The default is false meaning that the RBB outputs to the ADC.

     */
    { &LMS7002M_rbb_set_test_out },

};

// ---- loopback ----
// (Auto-generated array for QT Label "loopback")
Caller loopback[] = 
{
    /*
     * OPCODE: 5
     * API Name: LMS7002M_configure_lml_port
     * Description: 
Configure the muxing and clocking on a lime light port.
This sets the data mode and direction for the DIQ pins,
and selects the appropriate clock and stream muxes.
This call is not compatible with JESD207 operation.
The mclkDiv must be 1 for no divider, or an even value.
Odd divider values besides 1 (bypass) are not allowed.

     */
    { &LMS7002M_configure_lml_port },

    /*
     * OPCODE: C1
     * API Name: LMS7002M_setup_digital_loopback
     * Description: 
Enable digital loopback inside the lime light.
This call also applies the tx fifo write clock to the rx fifo.
To undo the effect of this loopback, call LMS7002M_configure_lml_port().

     */
    { &LMS7002M_setup_digital_loopback },

};

// Example final Group referencing each array:
Caller* Group[OPCODE_SIZE] = {
    &BUFF[0], // index=0 from QT Label
    &Band[0], // index=1 from QT Label
    &Calibrate[0], // index=2 from QT Label
    &Enable[0], // index=3 from QT Label
    &Enable_Channel[0], // index=4 from QT Label
    &FIR[0], // index=5 from QT Label
    &Frequency_Tunning[0], // index=6 from QT Label
    &Gain[0], // index=7 from QT Label
    &INI[0], // index=8 from QT Label
    &IQ[0], // index=9 from QT Label
    &Internal[0], // index=10 from QT Label
    &MAC[0], // index=11 from QT Label
    &Other[0], // index=12 from QT Label
    &Power[0], // index=13 from QT Label
    &RSSI[0], // index=14 from QT Label
    &Regs[0], // index=15 from QT Label
    &SPI[0], // index=16 from QT Label
    &Sampling[0], // index=17 from QT Label
    &Test[0], // index=18 from QT Label
    &loopback[0], // index=19 from QT Label
};

// End of auto-generated file
