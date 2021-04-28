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


void payloadconfig(){

}

void init(){
	system_state();
	deployment_state();
	payloadconfig();
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
			if(temperatures.raw(i)>=TEMP_MIN && temperatures.raw(i)<=TEMP_MAX){ /*COM AGAFO LES TEMPERATURES DEL RAW??*/
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







