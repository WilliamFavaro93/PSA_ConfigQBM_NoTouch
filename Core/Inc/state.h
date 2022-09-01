/*
 * State.h
 *
 *  Created on: 12 mag 2022
 *      Author: William.Favaro
 */

/* CYCLE: Adsorption_1 -> Compensation_1 -> Compensation_2 -> Adsorption_2 -> Compensation_1 -> Compensation_2 -> */
/* -> Standby_1 -> Standby_2 -> Standby -> */

#include <psa.h>
#include "Settings.h"
#include "stdint.h"

//void State_Cycle_Adsorption_1();
//void State_Standby_1();
int State_NextState(int n);
