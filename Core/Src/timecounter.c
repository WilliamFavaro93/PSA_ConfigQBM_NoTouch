/*
 * TimeCounter.c
 *
 *  Created on: 30 giu 2022
 *      Author: William.Favaro
 */

#include <timecounter.h>

/*** TIME ADDING ***/
void TimeCounter_AddDecisecond(TimeCounter *TimeCounter)
{
	TimeCounter->Deciseconds++;
	TimeCounter->Deciseconds %= 10;
	if(TimeCounter->Deciseconds == 0)
	{/* If you are inside here, Seconds++ */
		TimeCounter->Seconds++;
		TimeCounter->Seconds %= 60;
		if(TimeCounter->Seconds == 0)
		{
			TimeCounter->Minutes++;
			TimeCounter->Minutes %= 60;
			if(TimeCounter->Minutes == 0)
			{
				TimeCounter->Hours++;
				TimeCounter->Hours %= 24;
				if(TimeCounter->Hours == 0)
				{
					TimeCounter->Days++;
				}
			}
		}
	}
}

/*** TIME READER ***/
uint32_t TimeCounter_GetTotalHours(TimeCounter *TimeCounter)
{
	return TimeCounter->Hours + (TimeCounter->Days*24);
}
