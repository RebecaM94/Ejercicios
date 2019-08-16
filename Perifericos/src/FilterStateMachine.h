/*
 * FilterStateMachine.h
 *
 *  Created on: Aug 16, 2019
 *      Author: rmend
 */

#ifndef FILTERSTATEMACHINE_H_
#define FILTERSTATEMACHINE_H_
#define LOW 1
#define HIGH 0

typedef struct FilterBtnParamters
{
    bool Trigger;
    int state;
    int Cnt;
}filterbtnParameters_t;

void FilterStateMachine(ioport_level_t btnstate, filterbtnParameters_t* filterBtnParameters);
void InitFilterBtnParameters (filterbtnParameters_t* filterBtnParameters);

#endif /* FILTERSTATEMACHINE_H_ */