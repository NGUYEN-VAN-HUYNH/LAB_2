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
extern void control_time();
extern void updateClockBuffer(int hour, int minute);
void init_exercise8(){

}
void exercise8_run(){
	HAL_GPIO_TogglePin(LED_RED_GPIO_Port, LED_RED_Pin);
		//control_time();
	      switch(index_led) {
	          case 0:
	              HAL_GPIO_WritePin(EN0_GPIO_Port, EN0_Pin, GPIO_PIN_RESET);  // Enable LED 0
	              HAL_GPIO_WritePin(EN1_GPIO_Port, EN1_Pin, GPIO_PIN_SET);
	              HAL_GPIO_WritePin(EN2_GPIO_Port, EN2_Pin, GPIO_PIN_SET);
	              HAL_GPIO_WritePin(EN3_GPIO_Port, EN3_Pin, GPIO_PIN_SET);
	              display7SEG(led_buffer[0]);  // Display tens digit of the hour
	              break;
	          case 1:
	              HAL_GPIO_WritePin(EN0_GPIO_Port, EN0_Pin, GPIO_PIN_SET);
	              HAL_GPIO_WritePin(EN1_GPIO_Port, EN1_Pin, GPIO_PIN_RESET); // Enable LED 1
	              HAL_GPIO_WritePin(EN2_GPIO_Port, EN2_Pin, GPIO_PIN_SET);
	              HAL_GPIO_WritePin(EN3_GPIO_Port, EN3_Pin, GPIO_PIN_SET);
	              display7SEG(led_buffer[1]);  // Display units digit of the hour
	              break;
	          case 2:
				  HAL_GPIO_WritePin(EN0_GPIO_Port, EN0_Pin, GPIO_PIN_SET);
				  HAL_GPIO_WritePin(EN1_GPIO_Port, EN1_Pin, GPIO_PIN_SET);
				  HAL_GPIO_WritePin(EN2_GPIO_Port, EN2_Pin, GPIO_PIN_RESET); // Enable LED 2
				  HAL_GPIO_WritePin(EN3_GPIO_Port, EN3_Pin, GPIO_PIN_SET);
				  display7SEG(led_buffer[2]);  // Display tens digit of the minute
	              break;
	          case 3:
				 HAL_GPIO_WritePin(EN0_GPIO_Port, EN0_Pin, GPIO_PIN_SET);
				 HAL_GPIO_WritePin(EN1_GPIO_Port, EN1_Pin, GPIO_PIN_SET);
				 HAL_GPIO_WritePin(EN2_GPIO_Port, EN2_Pin, GPIO_PIN_SET);
				 HAL_GPIO_WritePin(EN3_GPIO_Port, EN3_Pin, GPIO_PIN_RESET); // Enable LED 3
	             display7SEG(led_buffer[3]);  // Display units digit of the minute
	              break;
	      }

	      // Move to the next LED in the sequence (cycle through 0, 1, 2, 3)
	      index_led = (index_led + 1) % MAX_LED;
}


