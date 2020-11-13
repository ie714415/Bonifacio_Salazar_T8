/*
 * BMI160.h
 *
 */

#ifndef WM8731_H_
#define WM8731_H_

#include "freertos_i2c.h"
#include "fsl_clock.h"
#include "fsl_port.h"
#include "stdint.h"
#include "FreeRTOS.h"
#include "semphr.h"
#include "task.h"

/*bmi160 registers*/
#define WM8731_SLAVE_ADDRESS		0x1A//0x1A /*If csb on 0*/


#define WM8731_LEFT_LINE_IN			0x00
#define WM8731_RIGHT_LINE_IN		0x01
#define WM8731_LEFT_HEADPHONE_OUT	0x02
#define WM8731_RIGHT_HEADPHONE_OUT  0x03
#define WM8731_ANALOGUE_AUDIO		0x04
#define WM8731_INTERFACE_FORMAT     0x07
#define WM8731_SAMPLING_CONTROL     0x08
#define WM8731_DIGITAL_PATH
#define WM8731_POWER_DOWN_REGISTER	0x0C
#define WM8731_RESET_REGISTER	    0x0F
#define WM8731_CODEC_ENABLE			0x12




freertos_i2c_flag_t wm8731_init(void);
uint8_t wm8731_play_audio(void);



#endif /* WM8731_H_ */
