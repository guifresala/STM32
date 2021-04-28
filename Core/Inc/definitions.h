/*
 * definitions.h
 *
 *  Created on: Apr 28, 2021
 *      Author: guifre
 */

#ifndef INC_DEFINITIONS_H_
#define INC_DEFINITIONS_H_


#define TEMP_MIN = -40;
#define TEMP_MAX = 125;
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

/*Total of 7bytes -> 8bytes -> 1 uit64_t*/
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
    	char tle1[69]; 									/*First line of TLE, 69 chars, 1byte each char*/
    	char tle2[69]; 									/*Second line of TLE, 69 chars, 1byte each char*/
    }fields;
} TLEUpdate;

/*Total of 20002bytes (20000+1+1) -> 20002/8 = 2500.25 rounded to 2501 uint64_t*/
typedef union __attribute__ ((__packed__)) Image {
    uint64_t raw[2501];
    struct __attribute__((__packed__)) {
    	uint8_t date;									/*When the image was acquired*/
    	uint8_t coordinates;							/*Where the image was acquired*/
    	uint8_t bufferImage[20000];						/*An Image sizes 10kB-20kB compressed -> 20000bytes worst case*/
    }fields;
} Image;

typedef union __attribute__ ((__packed__)) RadioFrequency {
    uint64_t raw[];
    struct __attribute__((__packed__)) {
    	uint8_t date;									/*When the image was acquired*/
    	uint8_t coordinates;							/*Where the image was acquired*/
    	uint64_t bufferRF[];
    }fields;
} RadioFrequency;


#endif /* INC_DEFINITIONS_H_ */
