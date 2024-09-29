/*
 * Ex9.c
 *
 *  Created on: Sep 29, 2024
 *      Author: Admin
 */

#include "main.h"
#include "Ex9.h"

const int MAX_LED_MATRIX = 8; // Ma trận LED 8x8
int index_led_matrix = 0; // Chỉ số LED đang hiển thị
int timer9_counter = 0;
int timer9_flag = 0;
uint8_t matrix_buffer[8] = {
    0x18,  // Hàng 0: 00111100 -> Bật LED ở cột 2,3,4,5 (hiển thị phần ngang của chữ "A")
    0x3C,  // Hàng 1: 01100110 -> Bật LED ở cột 1,2,5,6 (hiển thị phần cạnh của chữ "A")
    0x66,  // Hàng 2: 01100110 -> Bật LED ở cột 1,2,5,6
    0x66,  // Hàng 3: 01111110 -> Bật LED ở cột 1,2,3,4,5,6 (thanh ngang giữa chữ "A")
    0x7E,  // Hàng 4: 01100110 -> Bật LED ở cột 1,2,5,6
    0x7E,  // Hàng 5: 01100110 -> Bật LED ở cột 1,2,5,6
    0x66,  // Hàng 6: 01100110 -> Bật LED ở cột 1,2,5,6
    0x66   // Hàng 7: 01100110 -> Bật LED ở cột 1,2,5,6
};

void setTimer9(int duration){
	timer9_counter = duration;
	timer9_flag = 0;
}

void timerRun9(){
	if(timer9_counter > 0){
		timer9_counter --;
		if(timer9_counter <= 0){
			timer9_flag = 1;
		}
	}

}
void updateLEDMatrix(int index) {
    	HAL_GPIO_WritePin(GPIOB, GPIO_PIN_All, GPIO_PIN_SET);
    // Gửi dữ liệu đến các hàng (ROW0 -> ROW7) thông qua cổng B
   // GPIOB->ODR = (matrix_buffer[index] << 8);  // Dữ liệu hàng xuất ra từ PB8 tới PB15 (điều khiển hàng)

    // Kích hoạt cột tương ứng (ENM0 -> ENM7)
    switch (index) {
        case 0:
			HAL_GPIO_WritePin(ENM0_GPIO_Port, ENM0_Pin, GPIO_PIN_SET);
			HAL_GPIO_WritePin(ENM1_GPIO_Port, ENM1_Pin, GPIO_PIN_SET);
			HAL_GPIO_WritePin(ENM2_GPIO_Port, ENM2_Pin, GPIO_PIN_SET);
			HAL_GPIO_WritePin(ENM3_GPIO_Port, ENM3_Pin, GPIO_PIN_RESET);
			HAL_GPIO_WritePin(ENM4_GPIO_Port, ENM4_Pin, GPIO_PIN_RESET);
			HAL_GPIO_WritePin(ENM5_GPIO_Port, ENM5_Pin, GPIO_PIN_SET);
			HAL_GPIO_WritePin(ENM6_GPIO_Port, ENM6_Pin, GPIO_PIN_SET);
			HAL_GPIO_WritePin(ENM7_GPIO_Port, ENM7_Pin, GPIO_PIN_SET);
        	HAL_GPIO_WritePin(ROW0_GPIO_Port, ROW0_Pin, GPIO_PIN_RESET);
        	break;
        case 1:
			HAL_GPIO_WritePin(ENM0_GPIO_Port, ENM0_Pin, GPIO_PIN_SET);
			HAL_GPIO_WritePin(ENM1_GPIO_Port, ENM1_Pin, GPIO_PIN_SET);
			HAL_GPIO_WritePin(ENM2_GPIO_Port, ENM2_Pin, GPIO_PIN_RESET);
			HAL_GPIO_WritePin(ENM3_GPIO_Port, ENM3_Pin, GPIO_PIN_RESET);
			HAL_GPIO_WritePin(ENM4_GPIO_Port, ENM4_Pin, GPIO_PIN_RESET);
			HAL_GPIO_WritePin(ENM5_GPIO_Port, ENM5_Pin, GPIO_PIN_RESET);
			HAL_GPIO_WritePin(ENM6_GPIO_Port, ENM6_Pin, GPIO_PIN_SET);
			HAL_GPIO_WritePin(ENM7_GPIO_Port, ENM7_Pin, GPIO_PIN_SET);
        	HAL_GPIO_WritePin(ROW1_GPIO_Port, ROW1_Pin, GPIO_PIN_RESET);
        	break;
        case 2:
			HAL_GPIO_WritePin(ENM0_GPIO_Port, ENM0_Pin, GPIO_PIN_SET);
			HAL_GPIO_WritePin(ENM1_GPIO_Port, ENM1_Pin, GPIO_PIN_RESET);
			HAL_GPIO_WritePin(ENM2_GPIO_Port, ENM2_Pin, GPIO_PIN_RESET);
			HAL_GPIO_WritePin(ENM3_GPIO_Port, ENM3_Pin, GPIO_PIN_SET);
			HAL_GPIO_WritePin(ENM4_GPIO_Port, ENM4_Pin, GPIO_PIN_SET);
			HAL_GPIO_WritePin(ENM5_GPIO_Port, ENM5_Pin, GPIO_PIN_RESET);
			HAL_GPIO_WritePin(ENM6_GPIO_Port, ENM6_Pin, GPIO_PIN_RESET);
			HAL_GPIO_WritePin(ENM7_GPIO_Port, ENM7_Pin, GPIO_PIN_SET);
        	HAL_GPIO_WritePin(ROW2_GPIO_Port, ROW2_Pin, GPIO_PIN_RESET);
        	break;
        case 3:
			HAL_GPIO_WritePin(ENM0_GPIO_Port, ENM0_Pin, GPIO_PIN_SET);
			HAL_GPIO_WritePin(ENM1_GPIO_Port, ENM1_Pin, GPIO_PIN_RESET);
			HAL_GPIO_WritePin(ENM2_GPIO_Port, ENM2_Pin, GPIO_PIN_RESET);
			HAL_GPIO_WritePin(ENM3_GPIO_Port, ENM3_Pin, GPIO_PIN_SET);
			HAL_GPIO_WritePin(ENM4_GPIO_Port, ENM4_Pin, GPIO_PIN_SET);
			HAL_GPIO_WritePin(ENM5_GPIO_Port, ENM5_Pin, GPIO_PIN_RESET);
			HAL_GPIO_WritePin(ENM6_GPIO_Port, ENM6_Pin, GPIO_PIN_RESET);
			HAL_GPIO_WritePin(ENM7_GPIO_Port, ENM7_Pin, GPIO_PIN_SET);
        	HAL_GPIO_WritePin(ROW3_GPIO_Port, ROW3_Pin, GPIO_PIN_RESET);
        	break;
        case 4:
			HAL_GPIO_WritePin(ENM0_GPIO_Port, ENM0_Pin, GPIO_PIN_SET);
			HAL_GPIO_WritePin(ENM1_GPIO_Port, ENM1_Pin, GPIO_PIN_RESET);
			HAL_GPIO_WritePin(ENM2_GPIO_Port, ENM2_Pin, GPIO_PIN_RESET);
			HAL_GPIO_WritePin(ENM3_GPIO_Port, ENM3_Pin, GPIO_PIN_RESET);
			HAL_GPIO_WritePin(ENM4_GPIO_Port, ENM4_Pin, GPIO_PIN_RESET);
			HAL_GPIO_WritePin(ENM5_GPIO_Port, ENM5_Pin, GPIO_PIN_RESET);
			HAL_GPIO_WritePin(ENM6_GPIO_Port, ENM6_Pin, GPIO_PIN_RESET);
			HAL_GPIO_WritePin(ENM7_GPIO_Port, ENM7_Pin, GPIO_PIN_SET);
        	HAL_GPIO_WritePin(ROW4_GPIO_Port, ROW4_Pin, GPIO_PIN_RESET);
        	break;
        case 5:
			HAL_GPIO_WritePin(ENM0_GPIO_Port, ENM0_Pin, GPIO_PIN_SET);
			HAL_GPIO_WritePin(ENM1_GPIO_Port, ENM1_Pin, GPIO_PIN_RESET);
			HAL_GPIO_WritePin(ENM2_GPIO_Port, ENM2_Pin, GPIO_PIN_RESET);
			HAL_GPIO_WritePin(ENM3_GPIO_Port, ENM3_Pin, GPIO_PIN_RESET);
			HAL_GPIO_WritePin(ENM4_GPIO_Port, ENM4_Pin, GPIO_PIN_RESET);
			HAL_GPIO_WritePin(ENM5_GPIO_Port, ENM5_Pin, GPIO_PIN_RESET);
			HAL_GPIO_WritePin(ENM6_GPIO_Port, ENM6_Pin, GPIO_PIN_RESET);
			HAL_GPIO_WritePin(ENM7_GPIO_Port, ENM7_Pin, GPIO_PIN_SET);
        	HAL_GPIO_WritePin(ROW5_GPIO_Port, ROW5_Pin, GPIO_PIN_RESET);
        	break;
        case 6:
			HAL_GPIO_WritePin(ENM0_GPIO_Port, ENM0_Pin, GPIO_PIN_SET);
			HAL_GPIO_WritePin(ENM1_GPIO_Port, ENM1_Pin, GPIO_PIN_RESET);
			HAL_GPIO_WritePin(ENM2_GPIO_Port, ENM2_Pin, GPIO_PIN_RESET);
			HAL_GPIO_WritePin(ENM3_GPIO_Port, ENM3_Pin, GPIO_PIN_SET);
			HAL_GPIO_WritePin(ENM4_GPIO_Port, ENM4_Pin, GPIO_PIN_SET);
			HAL_GPIO_WritePin(ENM5_GPIO_Port, ENM5_Pin, GPIO_PIN_RESET);
			HAL_GPIO_WritePin(ENM6_GPIO_Port, ENM6_Pin, GPIO_PIN_RESET);
			HAL_GPIO_WritePin(ENM7_GPIO_Port, ENM7_Pin, GPIO_PIN_SET);
        	HAL_GPIO_WritePin(ROW6_GPIO_Port, ROW6_Pin, GPIO_PIN_RESET);
        	break;
        case 7:
			HAL_GPIO_WritePin(ENM0_GPIO_Port, ENM0_Pin, GPIO_PIN_SET);
			HAL_GPIO_WritePin(ENM1_GPIO_Port, ENM1_Pin, GPIO_PIN_RESET);
			HAL_GPIO_WritePin(ENM2_GPIO_Port, ENM2_Pin, GPIO_PIN_RESET);
			HAL_GPIO_WritePin(ENM3_GPIO_Port, ENM3_Pin, GPIO_PIN_SET);
			HAL_GPIO_WritePin(ENM4_GPIO_Port, ENM4_Pin, GPIO_PIN_SET);
			HAL_GPIO_WritePin(ENM5_GPIO_Port, ENM5_Pin, GPIO_PIN_RESET);
			HAL_GPIO_WritePin(ENM6_GPIO_Port, ENM6_Pin, GPIO_PIN_RESET);
			HAL_GPIO_WritePin(ENM7_GPIO_Port, ENM7_Pin, GPIO_PIN_SET);
        	HAL_GPIO_WritePin(ROW7_GPIO_Port, ROW7_Pin, GPIO_PIN_RESET);
        	break;
    }
}

// Khởi tạo bài tập 9
void init_exercise9() {
    // Khởi tạo cho bài tập (nếu cần thiết)
}

// Hàm chạy bài tập 9
void exercise9_run() {
    // Gọi hàm updateLEDMatrix để cập nhật hàng tương ứng trong ma trận LED
    updateLEDMatrix(index_led_matrix);

    // Di chuyển đến hàng tiếp theo
    index_led_matrix = (index_led_matrix + 1) % MAX_LED_MATRIX;  // Lặp lại từ 0 sau khi quét hết 8 hàng
}



