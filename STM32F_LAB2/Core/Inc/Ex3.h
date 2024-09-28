/*
 * Ex3.h
 *
 *  Created on: Sep 28, 2024
 *      Author: Admin
 */

#ifndef INC_EX3_H_
#define INC_EX3_H_
extern void timerRun3();
extern void setTimer3(int duration);
extern void display7SEG(int num);
void update7SEG (int index);
void exercise3_run();
void init_exercise3();
extern int timer3_counter;
extern int timer3_flag;
extern int index_led;
extern const int MAX_LED;
extern int led_buffer [4];


#endif /* INC_EX3_H_ */
