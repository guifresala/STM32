/*
 * configuration.h
 *
 *  Created on: Apr 20, 2021
 *      Author: guifre
 */

#ifndef INC_CONFIGURATION_H_
#define INC_CONFIGURATION_H_

#include "main.h"


/*Only at the beginning, includes the Antenna deployment, check batteries, configure payloads*/
/*Will be executed every time we reboot the system*/
void init(void);

/*Compute the level of battery and return batterylevel*/
void checkbatteries();

/*Check if the memory have enough space to store a photo/spectrum*/
void checkmemory();

/*Check the temperature of the 8 sensors, returns true if the temperature is between TEMP_MAX and TEMP_MIN*/
bool checktemperature(void);

/*Send a signal to a resistor to burn a wire and deploy Antenna
 *Check the switch to make sure the Antenna has been deployed properly*/
void deployment(void);

 /*（1)power on
  *（2)delay 2.5s
  *（3）reset command
  *（4）set image resolution command -> 640x480 default
  *（5）set image compressibility command
  * Need 115200bps band rate at UART configuration
  * After that go to 'INIT STATE'*/
void payloadconfig(void);

/*Check battery level, temperatures,etc
 *If each parameter is between a specified values returns true*/
bool system_state();

#endif /* INC_CONFIGURATION_H_ */
