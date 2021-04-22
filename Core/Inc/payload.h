/*
 * payload.h
 *
 *  Created on: Apr 20, 2021
 *      Author: guifre
 */

#ifndef INC_PAYLOAD_H_
#define INC_PAYLOAD_H_



/*configuration.system_state() must be 'true'
 *batterylevel must be at Nominal level
 * configuration.checkmemory()
 * Start preparing the payload (to take a photo)/(detect RF)
 * Start a timer (enough to have the payload prepared) and start working*/
void payloadinit(void);

/*Includes payloadinit()
 * Receive the compressed photo or spectre and store it into the memory
 * Then return to 'IDLE' state */
void receive(void);



#endif /* INC_PAYLOAD_H_ */
