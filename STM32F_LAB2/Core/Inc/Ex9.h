/*
 * Ex9.h
 *
 *  Created on: Sep 29, 2024
 *      Author: Admin
 */

#ifndef INC_EX9_H_
#define INC_EX9_H_
#include "main.h"
extern const int MAX_LED_MATRIX; // Ma trận LED 8x8
extern int index_led_matrix; // Chỉ số LED đang hiển thị
extern uint8_t matrix_buffer[8];
extern int timer9_counter;
extern int timer9_flag;
void updateLEDMatrix(int index);
void init_exercise9();
void exercise9_run();
void setTimer9(int duration);
void timerRun9();
#endif /* INC_EX9_H_ */
