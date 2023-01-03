#include "VEML3328_PlatformSpecific.h"

VEML3328_Status VEML3328_PlatformSpecific_Init() {
	// this function must initialize I2C bus driver. It should not generate any 
	// transaction to the VEML3328 device. It is recommended to generate 9 clock  
	// cycles when SDA line is asserted as low and then generate stop sequence.

	return VEML3328_Status_NotImplemented;
}

VEML3328_Status VEML3328_PlatformSpecific_Deinit() {
	// this function must deinitialize I2C bus driver. It should not generate any 
	// transaction to the VEML3328 device.

	return VEML3328_Status_NotImplemented;
}

VEML3328_Status VEML3328_PlatformSpecific_Read(uint8_t registerAddress, uint16_t* value) {
	// this function must generate following on the I2C bus:
	//
	// 1) Generate STRAT condition.
	// 2) Transmit VEML3328_I2C_WRITE_ADDRESS. If you are using platform (library) which 
	//    requires non-shifted 7bit address use VEML3328_I2C_7BIT_ADDRESS constant and 
	//    write direction.
	// 3) Check that device ACKed transaction. Otherwise generate STOP sequence and 
	//    return VEML3328_Status_I2CNack.
	// 4) Transmit registerAddress byte.
	// 5) Check that device ACKed transaction. Otherwise generate STOP sequence and
	//    return VEML3328_Status_I2CNack.
	// 6) Generate REPEATED START sequence
	// 7) Transmit VEML3328_I2C_READ_ADDRESS. If you are using platform (library) which 
	//    requires non-shifted 7bit address use VEML3328_I2C_7BIT_ADDRESS constant and 
	//    read direction.
	// 8) Read two bytes and store them to the value output parameter. Data come from 
	//    the sensor encoded using little-endian. ACK the first byte. Generate NACK 
	//    instead of ACK after receiving second byte.
	// 7) Generate STOP sequence and return VEML3328_Status_Ok.
	//
	// In all steps check for errors like arbitration lost error. Use return code 
	// VEML3328_Status_I2CNack for errors related to NACKing and VEML3328_Status_I2CError 
	// for other I2C errors. 
	//
	// Before returning any status code remember to generate STOP sequence.
	//
	// Prevent using loops which may end up in inifinete loop in case of unpredictable 
	// behaviour of I2C peripheral. Try implement platform specific timeout detection
	// and return VEML3328_Status_I2CTimeout when timeout occur. In case of timeout 
	// also generate STOP sequence and turn platform specific driver to the state that 
	// it can be reused for further communication again. (In the other words any I2C 
	// error should not make library stuck in error-generating state forever).

	return VEML3328_Status_NotImplemented;
}

VEML3328_Status VEML3328_PlatformSpecific_Write(uint8_t registerAddress, uint16_t value) {
	// this function must generate following on the I2C bus:
	//
	// 1) Generate STRAT condition.
	// 2) Transmit VEML3328_I2C_WRITE_ADDRESS. If you are using platform (library) which 
	//    requires non-shifted 7bit address use VEML3328_I2C_7BIT_ADDRESS constant and 
	//    write direction.
	// 3) Check that device ACKed transaction. Otherwise generate STOP sequence and 
	//    return VEML3328_Status_I2CNack.
	// 4) transmit registerAddress byte.
	// 5) check that device ACKed transaction. Otherwise generate STOP sequence and
	//    return VEML3328_Status_I2CNack.
	// 6) transmit value parameter. Send value in little-endian order. After transmiting 
	//    every byte check that device ACKed transaction. Otherwise generate STOP 
	//    sequence and return VEML3328_Status_I2CNack.
	// 7) generate STOP sequence and return VEML3328_Status_Ok.
	//
	// In all steps check for errors like arbitration lost error. Use return code 
	// VEML3328_Status_I2CNack for errors related to NACKing and VEML3328_Status_I2CError 
	// for other I2C errors. 
	//
	// Before returning any status code remember to generate STOP sequence.
	//
	// Prevent using loops which may end up in inifinete loop in case of unpredictable 
	// behaviour of I2C peripheral. Try implement platform specific timeout detection
	// and return VEML3328_Status_I2CTimeout when timeout occur. In case of timeout 
	// also generate STOP sequence and turn platform specific driver to the state that 
	// it can be reused for further communication again. (In the other words any I2C 
	// error should not make library stuck in error-generating state forever).

	return VEML3328_Status_NotImplemented;
}
