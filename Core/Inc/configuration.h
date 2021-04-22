/*
 * configuration.h
 *
 *  Created on: Apr 20, 2021
 *      Author: guifre
 */

#ifndef INC_CONFIGURATION_H_
#define INC_CONFIGURATION_H_

#include "main.h"

/*NOMINAL from 100 to 75, LOW from 75 to 15, CRITICAL from 15 to 10 (only to give us an idea*/
enum BatteryLevel {NOMINAL=100, LOW=75, CRITICAL=15, SURVIVAL=10};
BatteryLevel batterylevel;

/*Only at the beginning, includes the Antenna deployment, check batteries, configure payloads*/
void init(void);

/*Compute the level of battery and return batterylevel*/
batterylevel checkbatteries();

/*Check if the memory have enough space to store a photo/spectrum*/
void checkmemory();

/*Send a signal to a MOSFET(s) to burn a wire(s) and deploy Antenna
 * Check the switch to make sure the Antenna has been deployed properly*/
void deployment(void);

/*Only if it is needed
 *After that go to 'INIT STATE'*/
void payloadconfig(void);

/*Check battery level, temperature(of each PCB),etc
 *If every parameter is between a specified values returns true*/
bool system_state();

#endif /* INC_CONFIGURATION_H_ */
