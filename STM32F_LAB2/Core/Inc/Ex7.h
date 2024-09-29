/*
 * Ex7.h
 *
 *  Created on: Sep 29, 2024
 *      Author: Admin
 */

#ifndef INC_EX7_H_
#define INC_EX7_H_
#include "main.h"
extern void timerRun7();
extern void setTimer7(int duration);
extern void display7SEG(int num);
extern void update7SEG (int index);
void exercise7_run();
void init_exercise7();
extern int timer7_counter;
extern int timer7_flag;
extern int index_led;
extern const int MAX_LED;
extern int led_buffer[4];
extern int hour, minute, second;
extern void control_time();
extern void updateClockBuffer(int hour, int minute);

#endif /* INC_EX7_H_ */
