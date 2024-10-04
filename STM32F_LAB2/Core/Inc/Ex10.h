/*
 * Ex10.h
 *
 *  Created on: Sep 29, 2024
 *      Author: Admin
 */

#ifndef INC_EX10_H_
#define INC_EX10_H_
#include "main.h"
extern const int MAX_LED_MATRIX; // Ma trận LED 8x8
extern int index_led_matrix; // Chỉ số LED đang hiển thị
extern int timer10_counter;
extern int timer10_flag;
extern int shift_index;
void exercise10_run();
void init_exercise10();
void H(int index);
void C(int index);
void M(int index);
void U(int index);
void T(int index);
void timerRun10();
void setTimer10();



#endif /* INC_EX10_H_ */
