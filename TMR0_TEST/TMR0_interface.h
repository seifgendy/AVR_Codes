/*
 * TMR0_interface.h
 *
 * Created: 9/9/2023 10:56:03 PM
 *  Author: Kareem Hussein
 */ 


#ifndef TMR0_INTERFACE_H_
#define TMR0_INTERFACE_H_


                /*************** APIS PROTOTYPES ***************/
				
void TMR0_init                (void);
void TMR0_start               (void);
void TMR0_stop                (void);
void TMR0_setCallBackOVF      (void(*ptrToFun)(void));
void TMR0_setCallBackCTC      (void(*ptrToFun)(void));
void TMR0_setCompareMatchValue(u8 compareValue);
void TMR0_setDelay_ms_usingCTC(u16 delay_ms);

#endif /* TMR0_INTERFACE_H_ */