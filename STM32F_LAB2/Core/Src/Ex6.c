/*
 * Ex6.c
 *
 *  Created on: Sep 28, 2024
 *      Author: Admin
 */
#include "Ex6.h"
#include "main.h"
int timer0_counter = 0;
int timer0_flag = 0;
int TIME_CYCLE = 10;
void setTimer0(int duration){
	timer0_counter = duration;
	timer0_flag = 0;
}
void timerRun0 (){
	if (timer0_counter > 0){
		timer0_counter --;
		if (timer0_counter <= 0){
			timer0_flag = 1;
		}
	}
}
void exercise6_run(){
	HAL_GPIO_TogglePin(LED_RED_GPIO_Port, LED_RED_Pin);
}
void init_exercise6(){

}





