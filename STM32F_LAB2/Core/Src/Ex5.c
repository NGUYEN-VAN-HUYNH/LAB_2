/*
 * Ex5.c
 *
 *  Created on: Sep 28, 2024
 *      Author: Admin
 */

#include "main.h"
#include "Ex5.h"
int timer5_flag = 0;
int timer5_counter = 0;
extern int index_led;
extern const int MAX_LED;
extern int led_buffer[4];
int hour = 15 , minute = 8 , second = 50;
void setTimer5(int duration){
	timer5_counter = duration;
	timer5_flag = 0;
}

void timerRun5(){
	if(timer5_counter > 0){
		timer5_counter --;
		if(timer5_counter <= 0){
			timer5_flag = 1;
		}
	}

}

void updateClockBuffer(int hour, int minute) {
    // Update the hour display
    led_buffer[0] = hour / 10;  // Tens digit of the hour
    led_buffer[1] = hour % 10;  // Units digit of the hour

    // Update the minute display
    led_buffer[2] = minute / 10;  // Tens digit of the minute
    led_buffer[3] = minute % 10;  // Units digit of the minute
}



void control_time(){
	 second ++;
	 if ( second >= 60) {
	 second = 0;
	 minute ++;
	 }
	 if( minute >= 60) {
	 minute = 0;
	 hour ++;
	 }
	 if( hour >=24) {
	 hour = 0;
	 }
	 updateClockBuffer(hour, minute) ;
 }

void init_exercise5(){

}
void exercise5_run(){
	HAL_GPIO_TogglePin(LED_RED_GPIO_Port, LED_RED_Pin);
	control_time();
	//Update the current 7-segment display
//	display7SEG(led_buffer[index_led]);
//
//	//Move to the next LED in the sequence
//	index_led = (index_led + 1) % MAX_LED; // Cycle through 0, 1, 2, 3 for the 4 LEDs
  // Enable the current 7-segment display and show the corresponding digit
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

