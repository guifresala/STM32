/*
 * configuration.cpp
 *
 *  Created on: Apr 20, 2021
 *      Author: guifre
 */
#include "configuration.h"





void checkbatteries(){

}

void deployment(){
	while(system_state() && !deployment_state){
		/*Activate the resistor to burn the wire*/
	}
	deployment_state = true;
	init();
}


bool Cameraconfig(){
	/*POWER ON?*/
	uint8_t reset[4] = {0x56, 0x00, 0x26, 0x00};
	uint8_t supposedAckReset[4] = {0x76, 0x00, 0x26, 0x00};
	uint8_t ackReset[4];
	uint8_t setCompressibility[9] = {0x56, 0x00, 0x31, 0x05, 0x01, 0x01, 0x12, 0x04, 0xFF}; //0xFF maximum compressed*/
	uint8_t supposedAckSetCompressibility[5] = {0x76, 0x00, 0x31, 0x00, 0x00};
	uint8_t ackSetCompressibility[5];

	sleep_for(std::chrono::milliseconds(DELAY_CAMERA)); /*Delay 2.5s*/
	HAL_UART_Transmit(&huart1, reset, 4, 1000); 		/*Transmit reset command*/
	HAL_UART_Receive(&huart1, ackReset, 4, 1000);		/*Receive ack reset*/
	if(ackReset == supposedAckReset){
		HAL_UART_Transmit(&huart1, setCompressibility, 9, 1000); 	/*Transmit compressibility of image*/
		HAL_UART_Receive(&huart1, ackSetCompressibility, 4, 1000);	/*Receive ack compressibility*/
		if(ackSetCompressibility == supposedAckSetCompressibility){
			return true;
		}
	}
}

void init(){
	system_state();
	deployment_state();
	deployment();
	currentState = IDLE;
}

bool system_state(){
	checkbatteries();
	checktemperature();
}
bool checktemperature(){
	Temperatures = temperatures;
	int i;
	bool temp = true;
	for(i=1; i<8; i++){
		while(temp){
			if((temperatures.raw(i)>=TEMP_MIN) && (temperatures.raw(i)<=TEMP_MAX)){ /*COM AGAFO LES TEMPERATURES DEL RAW??*/
				temp = true;
			}
			else{ temp = false;
			}
		}
	}
	if(temp) return true;
	else return false;
}

void checkmemory(){

}

void writeFlash(){

}







