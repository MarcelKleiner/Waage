/*
 * Tools.cpp
 *
 *  Created on: Oct 17, 2020
 *      Author: marcel
 */

#include "Tools.h"
#include "math.h"
using namespace std;

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
