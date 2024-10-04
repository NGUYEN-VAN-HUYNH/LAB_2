/*
 * Ex3.c
 *
 *  Created on: Sep 28, 2024
 *      Author: Admin
 */


#include "main.h"
#include "Ex3.h"
int timer3_flag = 0;
int timer3_counter = 0;
int index_led = 0;
const int MAX_LED = 4;
int led_buffer [4] = {1 , 5 , 0 , 8};
void setTimer3(int duration){
	timer3_counter = duration;
	timer3_flag = 0;
}

void timerRun3(){
	if(timer3_counter > 0){
		timer3_counter --;
		if(timer3_counter <= 0){
			timer3_flag = 1;
		}
	}

}


void update7SEG ( int index ) {
	HAL_GPIO_TogglePin(LED_RED_GPIO_Port, LED_RED_Pin);
switch ( index ) {
	case 0:
	// Display the first 7 SEG with led_buffer [0]
		HAL_GPIO_WritePin(EN1_GPIO_Port, EN1_Pin, GPIO_PIN_SET);
		HAL_GPIO_WritePin(EN2_GPIO_Port, EN2_Pin, GPIO_PIN_SET);
		HAL_GPIO_WritePin(EN3_GPIO_Port, EN3_Pin, GPIO_PIN_SET);
		index = led_buffer[0];
		display7SEG(1);
		HAL_GPIO_WritePin(EN0_GPIO_Port, EN0_Pin, GPIO_PIN_RESET);
	break ;
	case 1:
	// Display the second 7 SEG with led_buffer [1]
		HAL_GPIO_WritePin(EN0_GPIO_Port, EN0_Pin, GPIO_PIN_SET);
		HAL_GPIO_WritePin(EN2_GPIO_Port, EN2_Pin, GPIO_PIN_SET);
		HAL_GPIO_WritePin(EN3_GPIO_Port, EN3_Pin, GPIO_PIN_SET);
		index = led_buffer[1];
		display7SEG(2);
		HAL_GPIO_WritePin(EN1_GPIO_Port, EN1_Pin, GPIO_PIN_RESET);
	break ;
	case 2:
	// Display the third 7 SEG with led_buffer [2]
		HAL_GPIO_WritePin(EN0_GPIO_Port, EN0_Pin, GPIO_PIN_SET);
		HAL_GPIO_WritePin(EN1_GPIO_Port, EN1_Pin, GPIO_PIN_SET);
		HAL_GPIO_WritePin(EN3_GPIO_Port, EN3_Pin, GPIO_PIN_SET);
		display7SEG(3);
		index = led_buffer[2];
		HAL_GPIO_WritePin(EN2_GPIO_Port, EN2_Pin, GPIO_PIN_RESET);
	break ;
	case 3:
	// Display the forth 7 SEG with led_buffer [3]
		HAL_GPIO_WritePin(EN0_GPIO_Port, EN0_Pin, GPIO_PIN_SET);
		HAL_GPIO_WritePin(EN1_GPIO_Port, EN1_Pin, GPIO_PIN_SET);
		HAL_GPIO_WritePin(EN2_GPIO_Port, EN2_Pin, GPIO_PIN_SET);
		index = led_buffer[3]; // bat dau lai led 1
		display7SEG(0);
		HAL_GPIO_WritePin(EN3_GPIO_Port, EN3_Pin, GPIO_PIN_RESET);
	break ;
	default :
	break ;
	}
 }

void init_exercise3(){

}
void exercise3_run(){
	if(index_led <= 3)
	update7SEG(index_led++);
	else
		index_led = 0;
}



