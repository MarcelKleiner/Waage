/*
 * Tools.cpp
 *
 *  Created on: Oct 17, 2020
 *      Author: marcel
 */

#include "Tools.h"
#include "stdlib.h"


char* Tools::intToAsciiChar(int32_t data,uint8_t nachkommastellen) {
		data = abs(data);
		static char d[5];
		static char result[6];
		d[0] = data/10000 + 0x30;
        d[1] = data/1000 - (data/10000)*10 + 0x30;
        d[2] = data/100 - (data/1000)*10 + 0x30;
        d[3] = data/10 - (data/100)*10 + 0x30;
        d[4] = data - (data/10)*10 + 0x30;

        for(uint8_t i=0,j = 0; i<6;i++,j++){

        	if(5-i == nachkommastellen){
        		result[i] = '.';
        		j--;
        	}else{
        		result[i] = d[j];
        	}
        }
	return result;
}


int32_t Tools::Round5Rp(int32_t prize){
	int result = 0;
    int rp = prize % 10;
    int fr = rp/5;
    if(fr == 1){
    	result = prize + 5-rp;
    }else{
    	result = prize - rp;
    }
    return result;
}

char* Tools::byteToAscii(uint8_t data) {;
	static char result[3];
	result[0] = data/100 + 0x30;
	result[1] = data/10 - (data/100)*10 + 0x30;
	result[2] = data - (data/10)*10 + 0x30;
    return result;
}



uint8_t Tools::BCDDecoder(uint8_t data) {
	uint8_t TP = (data & 0xF0)>>4;
	uint8_t UP = data & 0x0F;

	return TP*10+UP;
}

uint8_t Tools::BCDEncoder(uint8_t data) {
	uint8_t TP = data/10;
	uint8_t UP = data-(TP*10);
	return (TP<<4) + UP;
}




static bool init = false;

/*
 * Mikrosenkunden delay Initialisieren
 */
void Tools::DWT_Init(void) {
	CoreDebug->DEMCR |= CoreDebug_DEMCR_TRCENA_Msk;
	DWT->CYCCNT = 0;
	DWT->CTRL |= DWT_CTRL_CYCCNTENA_Msk;
}

/*
 * Mikrosenkunden delay für Push-Pull ansteuerung
 */
void Tools::DWT_Delay_us(volatile uint32_t microseconds) {
	if(!init){
		DWT_Init();
		init = true;
	}
	uint32_t clk_cycle_start = DWT->CYCCNT;
	/* Go to number of cycles for system */
	microseconds *= (HAL_RCC_GetHCLKFreq() / 1000000);
	/* Delay till end */
	while ((DWT->CYCCNT - clk_cycle_start) < microseconds)
		;
}





