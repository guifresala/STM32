/*
 * definitions.h
 *
 *  Created on: Apr 28, 2021
 *      Author: guifre
 */

#ifndef INC_DEFINITIONS_H_
#define INC_DEFINITIONS_H_

/*Temperature range operation of STM32L162VE*/
#define TEMP_MIN = -40;
#define TEMP_MAX = 105;

#define DELAY_CAMERA = 2500; /*Initial operation process*/

/*Telecommands*/
#define SENDDATA = 			01;	/*If the acquired photo or spectogram is needed to be send to GS*/
#define TAKEPPHOTO =        02;	/*Might rotate the PQ into the right position +
								wait until it is in the position where the picture is wanted to be taken.*/
#define TAKERF = 			03;
#define RESET = 			04;	/*The PQ might take a reset*/
#define SPECIFICTELEMETRY = 05;
#define STOPSENDINGDATA = 	06;
#define ACKDATA = 			07;	/*It is received when all the data is received correctly*/
#define NACKDATA = 			08;	/*If it is received if the GS do not receive all the segments of the data.
 	 	 	 	 	 	 	 	 *The PQ will send since the last segment received correctly.*/
#define TLE = 				09; /*Packet from GS with the new TLE, update it inside memory
 	 	 	 	 	 	 	 	  the SPG4 uses it to propagate the orbit*/


/*Total of 8bytes -> 8bytes·1uit64_t/8bytes = 1 uit64_t*/
typedef union __attribute__ ((__packed__)) Temperatures {
    uint64_t raw[1];
    struct __attribute__((__packed__)) {
         int8_t temp1;
         int8_t temp2;
         int8_t temp3;
         int8_t temp4;
         int8_t temp5;
         int8_t temp6;
         int8_t temp7;
         int8_t temp8;
    }fields;
} Temperatures;

/*Total of 12bytes -> rounded to 16bytes -> 2 uit64_t*/
typedef union __attribute__ ((__packed__)) Voltages {
    uint64_t raw[2];
    struct __attribute__((__packed__)) {
    	uint8_t voltage1;
    	uint8_t voltage2;
    	uint8_t voltage3;
    	uint8_t voltage4;
    	uint8_t voltage5;
    	uint8_t voltage6;
    	uint8_t voltage7;
    	uint8_t voltage8;
    	uint8_t voltage9;
    	uint8_t voltage10;
    	uint8_t voltage11;
    	uint8_t voltage12;
    }fields;
} Voltages;

/*Total of 5bytes -> 8 bytes -> 1 uint64_t*/
typedef union __attribute__ ((__packed__)) BatteryLevels {
    uint64_t raw[1];
    struct __attribute__((__packed__)) {
    	uint8_t totalbattery; /*Stores the total percentage of battery*/
    }fields;
} BatteryLevels;

/*Total of 7bytes -> 8bytes -> 1 uint64_t*/
typedef union __attribute__ ((__packed__)) Currents {
    uint64_t raw[1];
    struct __attribute__((__packed__)) {
    	uint8_t current1;
    	uint8_t current2;
    	uint8_t current3;
    	uint8_t current4;
    	uint8_t current5;
    	uint8_t current6;
    	uint8_t current7;
    }fields;
} Currents;

/*Total of 69bytes·2lines = 138bytes -> 144bytes -> 18 uit64_t*/
typedef union __attribute__ ((__packed__)) TLEUpdate {
    uint64_t raw[18];
    struct __attribute__((__packed__)) {
    	char tle1[69]; 						/*First line of TLE, 69 chars, 1byte each char*/
    	char tle2[69]; 						/*Second line of TLE, 69 chars, 1byte each char*/
    }fields;
} TLEUpdate;

/*Total of 20002bytes (20000+1+1) -> 20002/8 = 2500.25 rounded to 2501 uint64_t*/
typedef union __attribute__ ((__packed__)) Image {	/*const variable is stored in FLASH memory*/
    const uint64_t raw[2501];
    struct __attribute__((__packed__)) {
    	const uint8_t date;						/*When the image was acquired*/
    	const uint8_t coordinates;				/*Where the image was acquired*/
    	const uint8_t bufferImage[20000];			/*20000bytes worst case*/
    }fields;
} Image;

typedef union __attribute__ ((__packed__)) RadioFrequency {
    const uint64_t raw[55000];
    struct __attribute__((__packed__)) {
    	const uint8_t date;						/*When the image was acquired*/
    	const uint8_t coordinates;				/*Where the image was acquired*/
    	const uint64_t bufferRF[55000];				/*The size depends on the time acquiring, at the most about 55kB (whole orbit)
    	 	 	 	 	 	 	 	 	 	  size(bytes) = 73bits/s·(time acquiring)·1byte/8bits */
    }fields;
} RadioFrequency;


#endif /* INC_DEFINITIONS_H_ */
