/* Auto-generated typedefs grouped by number of parameters */

#ifndef COMMON_H_
#define COMMON_H_

#include "LMS7002M.h"
// Typedefs for functions with 1 parameter(s)
typedef LMS7002M_t* create_num_LMS7002M_t_spi_transact_t_cb(LMS7002M_spi_transact_t);
typedef int set_gfir_taps_num_int_t_cb(LMS7002M_t *);
typedef void one_param_lms7002m_t_num_void_t_cb(LMS7002M_t *);

// Typedefs for functions with 2 parameter(s)
typedef int ini_num_int_char_cb(LMS7002M_t *,  const char *);
typedef int spi_config_num_int_int_cb(LMS7002M_t *,  const int );
typedef int one_param_lms7002m_chan_num_int_chan_t_cb(LMS7002M_t *, const LMS7002M_chan_t);
typedef uint16_t readrssi_num_uint16_t_chan_t_cb(LMS7002M_t *, const LMS7002M_chan_t);
typedef void one_param_lms7002m_chan_num_void_dir_t_cb(LMS7002M_t *,  const LMS7002M_dir_t );
typedef void one_param_const_bool_num_void_bool_cb(LMS7002M_t *,  const bool );
typedef void spi_config_num_void_int_cb(LMS7002M_t *,  const int );
typedef void one_param_lms7002m_chan_num_void_chan_t_cb(LMS7002M_t *, const LMS7002M_chan_t);

// Typedefs for functions with 3 parameter(s)
typedef double trf_rbb_rfe_num_double_chan_t_cb(LMS7002M_t *, const LMS7002M_chan_t,  const double );
typedef void two_param_lms_const_bool_num_void_dir_t_cb(LMS7002M_t *,  const LMS7002M_dir_t ,  const bool );
typedef void two_param_lms7002m_dir_int_num_void_dir_t_cb(LMS7002M_t *,  const LMS7002M_dir_t ,  const int );
typedef void ldo_enable_num_void_bool_cb(LMS7002M_t *,  const bool ,  const int );
typedef void spi_write_num_void_int_cb(LMS7002M_t *,  const int ,  const int );
typedef void two_param_lms_const_bool_num_void_chan_t_cb(LMS7002M_t *, const LMS7002M_chan_t,  const bool );
typedef void trf_rbb_rfe_num_void_chan_t_cb(LMS7002M_t *, const LMS7002M_chan_t,  const double );
typedef void set_path_and_band_num_void_chan_t_cb(LMS7002M_t *, const LMS7002M_chan_t,  const int );
typedef void two_param_chant_sizet_num_void_chan_t_cb(LMS7002M_t *, const LMS7002M_chan_t,  const size_t );

// Typedefs for functions with 4 parameter(s)
typedef int set_data_clock_num_int_double_cb(LMS7002M_t *,  const double ,  const double ,  double *);
typedef int bb_filer_set_num_int_chan_t_cb(LMS7002M_t *, const LMS7002M_chan_t,  const double ,  double *);
typedef void afe_enable_num_void_dir_t_cb(LMS7002M_t *,  const LMS7002M_dir_t ,  const LMS7002M_chan_t ,  const bool );
typedef void set_nco_freq_num_void_dir_t_cb(LMS7002M_t *,  const LMS7002M_dir_t ,  const LMS7002M_chan_t ,  const double );
typedef void configure_lml_port_num_void_port_t_cb(LMS7002M_t *,  const LMS7002M_port_t ,  const LMS7002M_dir_t ,  const int );
typedef void tbb_loop_back_enable_num_void_chan_t_cb(LMS7002M_t *, const LMS7002M_chan_t,  const int ,  const bool );
typedef void sp_tsg_num_void_chan_t_cb(LMS7002M_t *, const LMS7002M_chan_t,  const int ,  const int );
typedef void rxtsp_num_void_chan_t_cb(LMS7002M_t *, const LMS7002M_chan_t, const bool, const int);
typedef void txstp_correction_num_void_chan_t_cb(LMS7002M_t *, const LMS7002M_chan_t, const double, const double);

// Typedefs for functions with 5 parameter(s)
typedef int set_lo_freq_num_int_dir_t_cb(LMS7002M_t *,  const LMS7002M_dir_t ,  const double ,  const double ,  double *);

#endif // COMMON_H_

