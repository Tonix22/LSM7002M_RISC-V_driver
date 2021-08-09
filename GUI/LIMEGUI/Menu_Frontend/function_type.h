#include "common.h"

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
                               PUSH_TO_LIST("Enable Chann")\
                               PUSH_TO_LIST("IQ")\
                               PUSH_TO_LIST("Enable")\
                               PUSH_TO_LIST("Sampling")\
                               PUSH_TO_LIST("Freq Tunning")\
                               PUSH_TO_LIST("FIR")\
                               PUSH_TO_LIST("Test")\
                               PUSH_TO_LIST("Calibrate")\
                               PUSH_TO_LIST("Band")\
                               PUSH_TO_LIST("Gain")\
                               PUSH_TO_LIST("RSSI")\

