#include "VEML3328_PlatformSpecific.h"
#include "stm32g0xx_hal.h"

#include <stdint.h>

extern I2C_HandleTypeDef VEML3328_I2C_HAL_DRIVER_HANDLE;

VEML3328_Status VEML3328_PlatformSpecific_Init() {
	HAL_StatusTypeDef status;

	status = HAL_I2C_Init(&VEML3328_I2C_HAL_DRIVER_HANDLE);
	if (status) {
		return VEML3328_Status_I2CError;
	}

	return VEML3328_Status_Ok;
}

VEML3328_Status VEML3328_PlatformSpecific_Deinit() {
	HAL_StatusTypeDef status;

	status = HAL_I2C_DeInit(&VEML3328_I2C_HAL_DRIVER_HANDLE);
	if (status) {
		return VEML3328_Status_I2CError;
	}

	return VEML3328_Status_Ok;
}

VEML3328_Status VEML3328_PlatformSpecific_Read(uint8_t registerAddress, uint16_t* value) {
	HAL_StatusTypeDef status;

	status = HAL_I2C_Mem_Read(&VEML3328_I2C_HAL_DRIVER_HANDLE, VEML3328_I2C_7BIT_ADDRESS << 1, registerAddress, sizeof(registerAddress), (uint8_t*)value, sizeof(*value), 100);
	if (status) {
		return VEML3328_Status_I2CError;
	}

	return VEML3328_Status_Ok;
}

VEML3328_Status VEML3328_PlatformSpecific_Write(uint8_t registerAddress, uint16_t value) {
	HAL_StatusTypeDef status;

	status = HAL_I2C_Mem_Write(&VEML3328_I2C_HAL_DRIVER_HANDLE, VEML3328_I2C_7BIT_ADDRESS << 1, registerAddress, sizeof(registerAddress), (uint8_t*)&value, sizeof(value), 100);
	if (status) {
		return VEML3328_Status_I2CError;
	}

	return VEML3328_Status_Ok;
}
