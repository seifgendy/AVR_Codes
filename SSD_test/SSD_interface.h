/*
 * SSD_interface.h
 *
 * Created: 9/1/2023 11:16:10 PM
 *  Author: Kareem Hussein
 */ 


#ifndef SSD_INTERFACE_H_
#define SSD_INTERFACE_H_

/* Macros for SSD Id*/
#define SSD_ONE            1 //first or second
#define SSD_TWO            2

               /*************** APIS PROTO TYPES ***************/
			   
void SSD_init              (void);
void SSD_displayNumber     (u8 ssdId,u8 desiredNumber);
void SSD_displayMultiNumber(u8 desiredNumber);


#endif /* SSD_INTERFACE_H_ */
