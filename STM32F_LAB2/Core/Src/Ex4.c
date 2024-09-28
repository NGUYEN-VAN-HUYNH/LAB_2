/*
 * Ex4.c
 *
 *  Created on: Sep 28, 2024
 *      Author: Admin
 */

#include "main.h"
#include "Ex4.h"
int timer4_flag = 0;
int timer4_counter = 0;
extern int index_led;
extern const int MAX_LED;
extern int led_buffer [4];
void setTimer4(int duration){
	timer4_counter = duration;
	timer4_flag = 0;
}

void timerRun4(){
	if(timer4_counter > 0){
		timer4_counter --;
		if(timer4_counter <= 0){
			timer4_flag = 1;
		}
	}

}
void init_exercise4(){

}
void exercise4_run(){
	if(index_led <= 3)
	update7SEG(index_led++);
	else
		index_led = 0;
}



