/**
  ******************************************************************************
  * @file   state.h
  * @author William Favaro
  * @date	12/05/2022
  * @brief  datetime functions
  *
  *
  ******************************************************************************
  * @note
  *
  *
  *
  ******************************************************************************
  */

/* CYCLE: Adsorption_1 -> Compensation_1 -> Compensation_2 -> Adsorption_2 -> Compensation_1 -> Compensation_2 -> */
/* -> Standby_1 -> Standby_2 -> Standby -> */

#include <psa.h>
#include "stdint.h"


#if DEBUG
void State_DebugInit();
#endif /* DEBUG */

int State_NextState(int n);
