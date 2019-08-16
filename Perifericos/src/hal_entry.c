/***********************************************************************************************************************
 * Copyright [2015-2017] Renesas Electronics Corporation and/or its licensors. All Rights Reserved.
 * 
 * This file is part of Renesas SynergyTM Software Package (SSP)
 *
 * The contents of this file (the "contents") are proprietary and confidential to Renesas Electronics Corporation
 * and/or its licensors ("Renesas") and subject to statutory and contractual protections.
 *
 * This file is subject to a Renesas SSP license agreement. Unless otherwise agreed in an SSP license agreement with
 * Renesas: 1) you may not use, copy, modify, distribute, display, or perform the contents; 2) you may not use any name
 * or mark of Renesas for advertising or publicity purposes or in connection with your use of the contents; 3) RENESAS
 * MAKES NO WARRANTY OR REPRESENTATIONS ABOUT THE SUITABILITY OF THE CONTENTS FOR ANY PURPOSE; THE CONTENTS ARE PROVIDED
 * "AS IS" WITHOUT ANY EXPRESS OR IMPLIED WARRANTY, INCLUDING THE IMPLIED WARRANTIES OF MERCHANTABILITY, FITNESS FOR A
 * PARTICULAR PURPOSE, AND NON-INFRINGEMENT; AND 4) RENESAS SHALL NOT BE LIABLE FOR ANY DIRECT, INDIRECT, SPECIAL, OR
 * CONSEQUENTIAL DAMAGES, INCLUDING DAMAGES RESULTING FROM LOSS OF USE, DATA, OR PROJECTS, WHETHER IN AN ACTION OF
 * CONTRACT OR TORT, ARISING OUT OF OR IN CONNECTION WITH THE USE OR PERFORMANCE OF THE CONTENTS. Third-party contents
 * included in this file may be subject to different terms.
 **********************************************************************************************************************/
/***********************************************************************************************************************
* File Name    : hal_entry.c
* Description  : This is a very simple example application that blinks all LEDs on a board.
***********************************************************************************************************************/

#include "hal_data.h"
#include "mainTick.h"
#include "FilterStateMachine.h"

#define LOW 1
#define HIGH 0

ioport_level_t P05_Status;
ioport_level_t P06_Status;

ioport_level_t P60_Status;
ioport_level_t P61_Status;
ioport_level_t P62_Status;

int blinkCnt;
int TriggerCnt = 0;


/************************************************************************
 Name:        hal_entry
 Description: Main thread
************************************************************************/
void hal_entry(void)
{
    bool bfmainTick;
    g_timer0.p_api->open (g_timer0.p_ctrl, g_timer0.p_cfg);
    g_timer0.p_api->start (g_timer0.p_ctrl);
    while(1)
    {
      
      bfmainTick = FN_bfPerformTick();
      if(bfmainTick == true)
        {
          SR_ClearMainTick();

          g_ioport.p_api->pinRead(IOPORT_PORT_00_PIN_05, &P05_Status);
          g_ioport.p_api->pinRead(IOPORT_PORT_00_PIN_06, &P06_Status);



          if (P06_Status == HIGH)
          {
              P60_Status = HIGH;
          }
          else
          {
              P60_Status = LOW;
          }



          if (P05_Status == HIGH)
          {
              blinkCnt++;
              if (blinkCnt > 20)
              {
                  blinkCnt = 0;
                  P62_Status =! P62_Status;
              }
          }

          else
          {
              P62_Status = LOW;
          }
          g_ioport.p_api->pinWrite(IOPORT_PORT_06_PIN_00, P60_Status);
          g_ioport.p_api->pinWrite(IOPORT_PORT_06_PIN_01, P61_Status);
          g_ioport.p_api->pinWrite(IOPORT_PORT_06_PIN_02, P62_Status);
        }
    }   
}

