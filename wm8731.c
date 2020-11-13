#include <wm8731.h>

#define I2C_SCL		2U
#define I2C_SDA		3U
#define BAUD_RATE	100000
#define I2C_DELAY	100//(ms)

/*Global declaratios*/
static freertos_i2c_config_t WM8731_i2c_config;

freertos_i2c_flag_t wm8731_init(void)
{
	freertos_i2c_flag_t wm8731_sucess = freertos_i2c_fail;
	/*Start port and freertos i2c inicialization */
	WM8731_i2c_config.baudrate = BAUD_RATE;
	WM8731_i2c_config.i2c_number = 	freertos_i2c0;
	WM8731_i2c_config.port = freertos_i2c_portB;
	WM8731_i2c_config.scl_pin = I2C_SCL;
	WM8731_i2c_config.sda_pin = I2C_SDA;
	WM8731_i2c_config.pin_mux = kPORT_MuxAlt2;

	/*Init configuration for freertos i2c*/
	wm8731_sucess = freertos_i2c_init(WM8731_i2c_config);
	vTaskDelay(pdMS_TO_TICKS(10));

	if(freertos_i2c_sucess == wm8731_sucess)
	{
		wm8731_sucess = freertos_i2c_fail;

		/*Initial configuration of bmi160*/
		uint8_t data[2] = {WM8731_POWER_DOWN_REGISTER, 0x00};
		/*Acc config*/
		wm8731_sucess = freertos_i2c_transmit(WM8731_i2c_config.i2c_number, data , 2, WM8731_SLAVE_ADDRESS);
		vTaskDelay(pdMS_TO_TICKS(I2C_DELAY));

		data[0] = WM8731_LEFT_LINE_IN;
		data[1] = 23;
		wm8731_sucess = freertos_i2c_transmit(WM8731_i2c_config.i2c_number, data , 2, WM8731_SLAVE_ADDRESS);
		vTaskDelay(pdMS_TO_TICKS(I2C_DELAY));

		data[0] = WM8731_RIGHT_LINE_IN;
		data[1] = 23;
		wm8731_sucess = freertos_i2c_transmit(WM8731_i2c_config.i2c_number, data , 2, WM8731_SLAVE_ADDRESS);
		vTaskDelay(pdMS_TO_TICKS(I2C_DELAY));


		data[0] = WM8731_ANALOGUE_AUDIO;
		data[1] = 0x05;
		wm8731_sucess = freertos_i2c_transmit(WM8731_i2c_config.i2c_number, data , 2, WM8731_SLAVE_ADDRESS);
		vTaskDelay(pdMS_TO_TICKS(I2C_DELAY));

		data[0] = WM8731_ANALOGUE_AUDIO;
		data[1] = 0x01;
		wm8731_sucess = freertos_i2c_transmit(WM8731_i2c_config.i2c_number, data , 2, WM8731_SLAVE_ADDRESS);
		vTaskDelay(pdMS_TO_TICKS(I2C_DELAY));


	}
	return wm8731_sucess;
}


uint8_t wm8731_play_audio(void)
{
	return 0;
}


