/*
 * LoadCellConfig.h
 *
 *  Created on: 11.10.2020
 *      Author: marcel
 */

#ifndef SRC_LOADCELL_LOADCELLCONFIG_H_
#define SRC_LOADCELL_LOADCELLCONFIG_H_

//-----------Command Byte settings-----------
#define Self_Calibration_Cycle 				0x90
#define System_Offset_Calibration_Cycle 	0xA0
#define System_Gain_Calibration 			0xB0
#define Immediate_Power_Down 				0x88
#define Convert_1sps 						0x80
#define Convert_2_5sps						0x81
#define Convert_5sps 						0x82
#define Convert_10sps 						0x83
#define Convert_15sps 						0x84
#define Convert_30sps 						0x85
#define Convert_60sps 						0x86
#define Convert_120sps						0x87

//-----------Register Read Selection (MODE=1)-----------
#define REG_ACCES_STAT1						0x00		//R, 8BIT
#define REG_ACCES_CTRL1						0x02		//R/W, 8BIT
#define REG_ACCES_CTRL2						0x04		//R/W, 8BIT
#define REG_ACCES_CTRL3						0x06		//R/W, 8BIT
#define REG_ACCES_DATA						0x08		//R/W, 24BIT
#define REG_ACCES_SOC						0x0A		//R/W, 24BIT
#define REG_ACCES_SGC						0x0C		//R/W, 24BIT
#define REG_ACCES_SCOC						0x0E		//R/W, 24BIT
#define REG_ACCES_SCGC						0x10		//R/W, 24BIT
#define REG_ACCES_WRITE						0x00
#define REG_ACCES_READ						0x01


//-----------CTRL1 Register settings-----------
#define LINEF_50HZ							0x80
#define LINEF_60HZ							0x00
#define INPUT_BIPOLAR						0x00
#define INPUT_UNIPOLAR						0x40
#define INTERNAL_CLK						0x20
#define EXTERNAL_CLK						0x00
#define REFBUF_ENABLE						0x10
#define REFBUF_DISABLE						0x00
#define SIGBUF_EBALE						0x08
#define SIGBUF_DISABLE						0x00
#define FORMAT_TWO_COMPLEMENT				0x00
#define FORMAT_BINARY						0x04
#define SCYCL_CONTINOUSE					0x00
#define SCYCL_SINGLE						0x02

//-----------CTRL2 Register settings-----------
#define DIO1_INPUT							0x00
#define DIO1_OUTPUT							0x10
#define DIO2_INPUT							0x00
#define DIO2_OUTPUT							0x20
#define DIO3_INPUT 							0x00
#define DIO3_OUTPUT							0x40
#define DIO4_INPUT							0x00
#define DIO4_OUTPUT							0x80

#define DIO1_W0								0x00
#define DIO1_W1								0x01
#define DIO2_W0								0x00
#define DIO2_W1								0x02
#define DIO3_W0								0x00
#define DIO3_W1								0x04
#define DIO4_W0								0x00
#define DIO4_W1								0x08

//-----------CTRL3 Register settings-----------
#define DIGITAL_GAIN_1						0x00
#define DIGITAL_GAIN_2						0x20
#define DIGITAL_GAIN_4						0x40
#define DIGITAL_GAIN_8						0x60
#define DIGITAL_GAIN_16						0x80
#define NOSYSG_ENABLE						0x00
#define NOSYSG_DISABLE						0x10
#define NOSYSO_ENABLE						0x00
#define NOSYS_DISABLE						0x80
#define NOSCG_ENABLE						0x00
#define NOSCG_DISABLE						0x40
#define NOSCO_ENABLE						0x00
#define NOSCO_DISABLE						0x20

//-----------Address settings-----------
/*
#define STAT1_ADDR							0x00
#define CTRL1_ADDR							0x01
#define CTRL2_ADDR							0x02
#define CTRL3_ADDR							0x03
#define DATA_ADDR							0x04
#define SOC_ADDR							0x05
#define SGC_ADDR							0x06
#define SCOC_ADDR							0x07
#define SCGC_ADDR							0x08
*/



#endif /* SRC_LOADCELL_LOADCELLCONFIG_H_ */
