/*
 * TimeCounter.h
 *
 *  Created on: 30 giu 2022
 *      Author: William.Favaro
 */

#ifndef INC_TIMECOUNTER_H_
#define INC_TIMECOUNTER_H_

#include "stdint.h"

typedef struct
{
	uint16_t Days;
	uint8_t Hours;
	uint8_t Minutes;
	uint8_t Seconds;
	uint8_t Deciseconds;
} TimeCounter;

/*** TIME ADDING ***/
void TimeCounter_AddDecisecond(TimeCounter *TimeCounter);

/*** TIME READER ***/
uint32_t TimeCounter_GetTotalHours(TimeCounter *TimeCounter);

#endif /* INC_TIMECOUNTER_H_ */
