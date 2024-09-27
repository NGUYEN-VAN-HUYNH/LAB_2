/*
 * Ex1.h
 *
 *  Created on: Sep 27, 2024
 *      Author: Admin
 */

#ifndef INC_EX1_H_
#define INC_EX1_H_
#include "main.h"

void timerRun();
void setTimer1(int duration);
void display7SEG(int num);
void control_7segment ();
void exercise1_run();
void init_exercise1();
extern int timer1_counter;
extern int timer1_flag;
extern int led_status;

#endif /* INC_EX1_H_ */
