/*
 * dma_ST.c
 *
 *  Created on: 23 янв. 2021 г.
 *      Author: Zver
 */
//*******************************************************************************************
//*******************************************************************************************

#include "dma_ST.h"

//*******************************************************************************************
//*******************************************************************************************
void DMA1_ChX_Init(uint32_t *perifAddr, uint8_t *pBuff, uint16_t len){

	DMA1_Channel6->CCR  &= ~DMA_CCR_EN;       //запретить работу канала
	//Настройка DMA для работы с таймером.
	RCC->AHBENR |= RCC_AHBENR_DMA1EN;//Включение тактирования DMA1.

	DMA1_Channel6->CCR = DMA_CCR_PL_1 | DMA_CCR_PL_0 |// PL[1:0]: Channel priority level - 11: Very high.
				 	 	 DMA_CCR_PSIZE_0 |            // PSIZE[1:0]: Peripheral size - 01: 16-bits.
						 	 	 	 	 	 	 	  // MSIZE[1:0]: Memory size     - 00: 8-bits.
						 DMA_CCR_MINC    |            // MINC: Memory increment mode  - Memory increment mode enabled.
						 DMA_CCR_DIR;                 // DIR: Data transfer direction - 1: Read from memory.

	DMA1_Channel6->CPAR  = perifAddr; //(uint32_t)&TIM3->CCR1;//Куда копировать данные.
	DMA1_Channel6->CMAR  = (uint32_t)pBuff;		 //Отуда копировать данные.
	DMA1_Channel6->CNDTR = len;                  //Количество опереций передачи данных.
	DMA1_Channel6->CCR  |= DMA_CCR_EN;           //разрешить работу канала
}
//*******************************************************************************************



//*******************************************************************************************
//*******************************************************************************************






