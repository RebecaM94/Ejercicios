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
#define KCONST (32)

#define LOW 1
#define HIGH 0

ioport_level_t P06_Status;

ioport_level_t P60_Status;
ioport_level_t P62_Status;

int adcData;
int PreviousData = 0;
int adcDataFiltered = 0;
int percentage = 50;
bool PWMstatus = false;
int blinkCnt = 0;


/************************************************************************
 Name:        hal_entry
 Description: Main thread
************************************************************************/
void hal_entry(void)
{
    g_adc0.p_api->open(g_adc0.p_ctrl, g_adc0.p_cfg); //abrir puerto
    g_adc0.p_api->scanCfg(g_adc0.p_ctrl, g_adc0.p_channel_cfg); //configurar adc
    g_adc0.p_api->scanStart(g_adc0.p_ctrl);

    g_timer1.p_api->open(g_timer1.p_ctrl, g_timer1.p_cfg);
    g_timer1.p_api->start(g_timer1.p_ctrl);

    while(1)
    {
        if (true == PWMstatus)
            {
                g_timer1.p_api->open(g_timer1.p_ctrl, g_timer1.p_cfg);
                g_timer1.p_api->start(g_timer1.p_ctrl);
                P60_Status = HIGH;
            }
            else
            {
                g_timer1.p_api->stop(g_timer1.p_ctrl);
                g_timer1.p_api->close(g_timer1.p_ctrl);
                P60_Status =  LOW;
            }
        if (HIGH == P06_Status)
        {
            PWMstatus =! PWMstatus;
        }
        if (blinkCnt > 50)
        {
        blinkCnt = 0;
        P62_Status =! P62_Status;
        }
        blinkCnt++;
        g_adc0.p_api->read(g_adc0.p_ctrl, ADC_REG_CHANNEL_0, &adcData);
        adcDataFiltered = (adcData+((KCONST-1)*PreviousData))/KCONST;
        PreviousData = adcData;
        percentage = adcData*100/255;
        g_timer1.p_api->dutyCycleSet(g_timer1.p_ctrl, percentage, TIMER_PWM_UNIT_PERCENT, 1);
        g_ioport.p_api->pinWrite(IOPORT_PORT_06_PIN_00, P60_Status);
    }
}


