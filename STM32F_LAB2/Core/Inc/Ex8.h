/*
 * Ex8.h
 *
 *  Created on: Sep 29, 2024
 *      Author: Admin
 */

#ifndef INC_EX8_H_
#define INC_EX8_H_
#include "main.h"
extern void timerRun8();
extern void setTimer8(int duration);
extern void display7SEG(int num);
extern void update7SEG (int index);
void exercise8_run();
void init_exercise8();
extern int timer8_counter;
extern int timer8_flag;
extern int index_led;
extern const int MAX_LED;
extern int led_buffer [4];
extern int index_led;
extern const int MAX_LED;
extern int hour, minute, second;
extern void control_time();
extern void updateClockBuffer(int hour, int minute);
#endif /* INC_EX8_H_ */
