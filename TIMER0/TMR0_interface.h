

#ifndef TMR0_INTERFACE_H_
#define TMR0_INTERFACE_H_


             /*************** APIS PROTOTYPES ***************/
					   
void TMR0_init (void);
void TMR0_start(void);
void TMR0_stop (void);
void TMR0_setCallBackOVF(void(*ptrToFun)(void));//the  function that will recieve the address of action func from the main module

#endif /* TMR0_INTERFACE_H_ */
