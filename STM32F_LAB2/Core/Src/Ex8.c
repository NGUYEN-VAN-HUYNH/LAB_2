/*
 * Ex8.c
 *
 *  Created on: Sep 29, 2024
 *      Author: Admin
 */

#include "main.h"
#include "Ex8.h"
int timer8_flag = 0;
int timer8_counter = 0;
extern int index_led;
extern const int MAX_LED;
extern int led_buffer [4];
void setTimer8(int duration){
	timer8_counter = duration;
	timer8_flag = 0;
}

void timerRun8(){
	if(timer8_counter > 0){
		timer8_counter --;
		if(timer8_counter <= 0){
			timer8_flag = 1;
		}
	}

}

extern void update7SEG ( int index );

void init_exercise8(){

}
void exercise8_run(){
	if(index_led <= 3)
	update7SEG(index_led++);
	else
		index_led = 0;
}


