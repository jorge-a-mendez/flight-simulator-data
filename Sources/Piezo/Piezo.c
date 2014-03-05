/*
 * Piezo.c
 *
 *  Created on: Mar 3, 2014
 *      Author: Rafael Rodriguez
 */


///#################################################################################
// Funciones publicas.

byte get_shot(){
	byte shotVal = get_piezoADC;
	if(shotVal < SOFT*MAXVALUE/3){
		return NOSHOT;
	}
	else if((shotVal >= SOFT*MAXVALUE/3) && (shotVal < MEDIUM*MAXVALUE/3)){
		return SOFT;
	}
	else if((shotVal >= MEDIUM*MAXVALUE/3) && (shotVal < HARD*MAXVALUE/3)){
		return MEDIUM;
	}
	else{
		return HARD;
	}
}

///#################################################################################
// Funciones privadas.

byte get_piezoADC(){
	byte i;
	byte adc_measures[BUF_SIZE];
	ADCSC1 |= PIEZO_CH;
	for(i = 0; i < BUF_SIZE; i++){
		while(!ADCSC1_COCO);
		adc_measures[i] = ADCRL;
		ADCSC1 = ADCSC1;
	}
	return max(adc_measures);
}
byte max(byte a[BUF_SIZE]){
	byte max = a[0], i;
	for(i = 1; i < BUF_SIZE; i++){
		if(a[BUF_SIZE > max]) max = a[BUF_SIZE];
	}
	return max;
}