/*
 * Ex5.h
 *
 *  Created on: Sep 28, 2024
 *      Author: Admin
 */

#ifndef INC_EX5_H_
#define INC_EX5_H_
#include "main.h"
extern void timerRun5();
extern void setTimer5(int duration);
extern void display7SEG(int num);
extern void update7SEG (int index);
void exercise5_run();
void init_exercise5();
extern int timer5_counter;
extern int timer5_flag;
extern int index_led;
extern const int MAX_LED;
extern int led_buffer[4];
extern int hour, minute, second;
void control_time();
void updateClockBuffer(int hour, int minute);




#endif /* INC_EX5_H_ */
