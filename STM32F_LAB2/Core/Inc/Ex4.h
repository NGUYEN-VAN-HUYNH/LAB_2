/*
 * Ex4.h
 *
 *  Created on: Sep 28, 2024
 *      Author: Admin
 */

#ifndef INC_EX4_H_
#define INC_EX4_H_
#include "main.h"
extern void timerRun4();
extern void setTimer4(int duration);
extern void display7SEG(int num);
extern void update7SEG (int index);
void exercise4_run();
void init_exercise4();
extern int timer4_counter;
extern int timer4_flag;
extern int index_led;
extern const int MAX_LED;
extern int led_buffer [4];




#endif /* INC_EX4_H_ */
