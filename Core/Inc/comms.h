/*
 * comms.h
 *
 *  Created on: Apr 20, 2021
 *      Author: guifre
 */

#ifndef INC_COMMS_H_
#define INC_COMMS_H_

/*Header with id (telecomand), or with the nº of piece of the photo, parity bit at the end (nº 1's odd or even)
 *
 * telecomands with (#define name nº)
 */

/*Telecommand received from comms
/*unpacking() -> redirect to the function we need to execute*/
void telecommand(void);

/*send the housekeeping (system_state) to the GS*/
void sendtelemetry();

/*Includes the packing of the data and telemetry(SPG4) we want to transmit to GS*/
void transmitpck();

/*Includes the unpacking and executes the telecomands received from GS*/
void receivepck(void);

/*The size of each packet is 59Bytes (51Bytes of data)*/
void packing();
void unpacking();

#endif /* INC_COMMS_H_ */


/*From GS the TLE is sended to the PQ, we update it inside the memory, the SPG4 uses it to propagate the orbit*/
