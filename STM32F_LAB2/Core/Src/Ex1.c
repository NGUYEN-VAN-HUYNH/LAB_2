/*
 * Ex1.c
 *
 *  Created on: Sep 27, 2024
 *      Author: Admin
 */

#include "main.h"
#include "Ex1.h"
int timer1_flag = 0;
int timer1_counter = 0;
int led_status = 0;

void setTimer1(int duration){
	timer1_counter = duration;
	timer1_flag = 0;
}

void timerRun(){
	if(timer1_counter > 0){
		timer1_counter --;
		if(timer1_counter <= 0){
			timer1_flag = 1;
		}
	}

}

void display7SEG(int num) {
    // tat led 7 doan
    HAL_GPIO_WritePin(GPIOB, SEG0_Pin, GPIO_PIN_SET);
    HAL_GPIO_WritePin(GPIOB, SEG1_Pin, GPIO_PIN_SET);
    HAL_GPIO_WritePin(GPIOB, SEG2_Pin, GPIO_PIN_SET);
    HAL_GPIO_WritePin(GPIOB, SEG3_Pin, GPIO_PIN_SET);
    HAL_GPIO_WritePin(GPIOB, SEG4_Pin, GPIO_PIN_SET);
    HAL_GPIO_WritePin(GPIOB, SEG5_Pin, GPIO_PIN_SET);
    HAL_GPIO_WritePin(GPIOB, SEG6_Pin, GPIO_PIN_SET);

    // dieu khien led 7 doan
    switch (num) {
        case 0:
            HAL_GPIO_WritePin(GPIOB, SEG0_Pin, GPIO_PIN_RESET);
            HAL_GPIO_WritePin(GPIOB, SEG1_Pin, GPIO_PIN_RESET);
            HAL_GPIO_WritePin(GPIOB, SEG2_Pin, GPIO_PIN_RESET);
            HAL_GPIO_WritePin(GPIOB, SEG3_Pin, GPIO_PIN_RESET);
            HAL_GPIO_WritePin(GPIOB, SEG4_Pin, GPIO_PIN_RESET);
            HAL_GPIO_WritePin(GPIOB, SEG5_Pin, GPIO_PIN_RESET);
            break;
        case 1:
            HAL_GPIO_WritePin(GPIOB, SEG1_Pin, GPIO_PIN_RESET);
            HAL_GPIO_WritePin(GPIOB, SEG2_Pin, GPIO_PIN_RESET);
            break;
        case 2:
            HAL_GPIO_WritePin(GPIOB, SEG0_Pin, GPIO_PIN_RESET);
            HAL_GPIO_WritePin(GPIOB, SEG1_Pin, GPIO_PIN_RESET);
            HAL_GPIO_WritePin(GPIOB, SEG3_Pin, GPIO_PIN_RESET);
            HAL_GPIO_WritePin(GPIOB, SEG4_Pin, GPIO_PIN_RESET);
            HAL_GPIO_WritePin(GPIOB, SEG6_Pin, GPIO_PIN_RESET);
            break;
        case 3:
            HAL_GPIO_WritePin(GPIOB, SEG0_Pin, GPIO_PIN_RESET);
            HAL_GPIO_WritePin(GPIOB, SEG1_Pin, GPIO_PIN_RESET);
            HAL_GPIO_WritePin(GPIOB, SEG2_Pin, GPIO_PIN_RESET);
            HAL_GPIO_WritePin(GPIOB, SEG3_Pin, GPIO_PIN_RESET);
            HAL_GPIO_WritePin(GPIOB, SEG6_Pin, GPIO_PIN_RESET);
            break;
        case 4:
            HAL_GPIO_WritePin(GPIOB, SEG1_Pin, GPIO_PIN_RESET);
            HAL_GPIO_WritePin(GPIOB, SEG2_Pin, GPIO_PIN_RESET);
            HAL_GPIO_WritePin(GPIOB, SEG5_Pin, GPIO_PIN_RESET);
            HAL_GPIO_WritePin(GPIOB, SEG6_Pin, GPIO_PIN_RESET);
            break;
        case 5:
            HAL_GPIO_WritePin(GPIOB, SEG0_Pin, GPIO_PIN_RESET);
            HAL_GPIO_WritePin(GPIOB, SEG2_Pin, GPIO_PIN_RESET);
            HAL_GPIO_WritePin(GPIOB, SEG3_Pin, GPIO_PIN_RESET);
            HAL_GPIO_WritePin(GPIOB, SEG5_Pin, GPIO_PIN_RESET);
            HAL_GPIO_WritePin(GPIOB, SEG6_Pin, GPIO_PIN_RESET);
            break;
        case 6:
            HAL_GPIO_WritePin(GPIOB, SEG0_Pin, GPIO_PIN_RESET);
            HAL_GPIO_WritePin(GPIOB, SEG2_Pin, GPIO_PIN_RESET);
            HAL_GPIO_WritePin(GPIOB, SEG3_Pin, GPIO_PIN_RESET);
            HAL_GPIO_WritePin(GPIOB, SEG4_Pin, GPIO_PIN_RESET);
            HAL_GPIO_WritePin(GPIOB, SEG5_Pin, GPIO_PIN_RESET);
            HAL_GPIO_WritePin(GPIOB, SEG6_Pin, GPIO_PIN_RESET);
            break;
        case 7:
            HAL_GPIO_WritePin(GPIOB, SEG0_Pin, GPIO_PIN_RESET);
            HAL_GPIO_WritePin(GPIOB, SEG1_Pin, GPIO_PIN_RESET);
            HAL_GPIO_WritePin(GPIOB, SEG2_Pin, GPIO_PIN_RESET);
            break;
        case 8:
            HAL_GPIO_WritePin(GPIOB, SEG0_Pin, GPIO_PIN_RESET);
            HAL_GPIO_WritePin(GPIOB, SEG1_Pin, GPIO_PIN_RESET);
            HAL_GPIO_WritePin(GPIOB, SEG2_Pin, GPIO_PIN_RESET);
            HAL_GPIO_WritePin(GPIOB, SEG3_Pin, GPIO_PIN_RESET);
            HAL_GPIO_WritePin(GPIOB, SEG4_Pin, GPIO_PIN_RESET);
            HAL_GPIO_WritePin(GPIOB, SEG5_Pin, GPIO_PIN_RESET);
            HAL_GPIO_WritePin(GPIOB, SEG6_Pin, GPIO_PIN_RESET);
            break;
        case 9:
            HAL_GPIO_WritePin(GPIOB, SEG0_Pin, GPIO_PIN_RESET);
            HAL_GPIO_WritePin(GPIOB, SEG1_Pin, GPIO_PIN_RESET);
            HAL_GPIO_WritePin(GPIOB, SEG2_Pin, GPIO_PIN_RESET);
            HAL_GPIO_WritePin(GPIOB, SEG3_Pin, GPIO_PIN_RESET);
            HAL_GPIO_WritePin(GPIOB, SEG5_Pin, GPIO_PIN_RESET);
            HAL_GPIO_WritePin(GPIOB, SEG6_Pin, GPIO_PIN_RESET);
            break;
        default:
            break; // khong lm gi ca
    }

}

void control_7segment (int led, int num){
	// Tắt cả hai LED
	    HAL_GPIO_WritePin(GPIOA, GPIO_PIN_6, GPIO_PIN_SET);  // EN0 (LED 1)
	    HAL_GPIO_WritePin(GPIOA, GPIO_PIN_7, GPIO_PIN_SET);  // EN1 (LED 2)

	    // Hiển thị số mới
	    display7SEG(num);

	    // Bật LED tương ứng
	    if (led == 0) {
	        HAL_GPIO_WritePin(GPIOA, GPIO_PIN_6, GPIO_PIN_RESET);  // Bật LED 1
	    } else if (led == 1) {
	        HAL_GPIO_WritePin(GPIOA, GPIO_PIN_7, GPIO_PIN_RESET);  // Bật LED 2
	    }
}

