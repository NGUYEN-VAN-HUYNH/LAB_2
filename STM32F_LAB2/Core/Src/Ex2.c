/*
 * Ex2.c
 *
 *  Created on: Sep 27, 2024
 *      Author: Admin
 */
#include "main.h"
#include "Ex2.h"
int timer2_flag = 0;
int timer2_counter = 0;
extern int led_status;
void setTimer2(int duration){
	timer2_counter = duration;
	timer2_flag = 0;
}

void timerRun2(){
	if(timer2_counter > 0){
		timer2_counter --;
		if(timer2_counter <= 0){
			timer2_flag = 1;
		}
	}

}
void control_4_7segment (){
	HAL_GPIO_TogglePin(LED_RED_GPIO_Port, LED_RED_Pin);
	switch (led_status){
	case 0 :
		HAL_GPIO_WritePin(EN1_GPIO_Port, EN1_Pin, GPIO_PIN_SET);
		HAL_GPIO_WritePin(EN2_GPIO_Port, EN2_Pin, GPIO_PIN_SET);
		HAL_GPIO_WritePin(EN3_GPIO_Port, EN3_Pin, GPIO_PIN_SET);
		led_status = 1;
		display7SEG(1);
		HAL_GPIO_WritePin(EN0_GPIO_Port, EN0_Pin, GPIO_PIN_RESET);
		break;
	case 1 :
		HAL_GPIO_WritePin(EN0_GPIO_Port, EN0_Pin, GPIO_PIN_SET);
		HAL_GPIO_WritePin(EN2_GPIO_Port, EN2_Pin, GPIO_PIN_SET);
		HAL_GPIO_WritePin(EN3_GPIO_Port, EN3_Pin, GPIO_PIN_SET);
		led_status = 2;
		display7SEG(2);
		HAL_GPIO_WritePin(EN1_GPIO_Port, EN1_Pin, GPIO_PIN_RESET);
		break;
	case 2 :
		HAL_GPIO_WritePin(EN0_GPIO_Port, EN0_Pin, GPIO_PIN_SET);
		HAL_GPIO_WritePin(EN1_GPIO_Port, EN1_Pin, GPIO_PIN_SET);
		HAL_GPIO_WritePin(EN3_GPIO_Port, EN3_Pin, GPIO_PIN_SET);
		led_status = 3;
		display7SEG(3);
		HAL_GPIO_WritePin(EN2_GPIO_Port, EN2_Pin, GPIO_PIN_RESET);
		break;
	case 3 :
		HAL_GPIO_WritePin(EN0_GPIO_Port, EN0_Pin, GPIO_PIN_SET);
		HAL_GPIO_WritePin(EN1_GPIO_Port, EN1_Pin, GPIO_PIN_SET);
		HAL_GPIO_WritePin(EN2_GPIO_Port, EN2_Pin, GPIO_PIN_SET);
		led_status = 0;
		display7SEG(0);
		HAL_GPIO_WritePin(EN3_GPIO_Port, EN3_Pin, GPIO_PIN_RESET);
		break;
	default :
		break;
	}
}
void init_exercise2(){

}
void exercise2_run(){
	control_4_7segment();
}




