/*
 * timers_ST.h
 *
 *  Created on: 23 янв. 2021 г.
 *      Author: Zver
 */

#ifndef TIMERS_ST_H_
#define TIMERS_ST_H_
//*******************************************************************************************
//*******************************************************************************************
#include "main.h"

//*******************************************************************************************


//*******************************************************************************************
//*******************************************************************************************
void TIM1_InitForPWM(uint32_t ARRval);

//**********************************************************
void TIM3_InitForPWM(void);

//**********************************************************
void TIM4_Init(void);

//*******************************************************************************************
//*******************************************************************************************
#endif /* TIMERS_ST_H_ */