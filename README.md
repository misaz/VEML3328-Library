# Vishay VEML3328 Color Sesnor C Library

This project contains library for controlling VEML3328 digital light and color sensor from Vishay. Library is written in C and is designed as multiplatform and easily portable.


## Features
- Written in C. Can be used in both C and C++ projects.
- Minimal RAM usage. No dynamic memory allocations.
- Library core depends on stdint.h (for uint8_t, uint16_t, int16_t and uint32_t types) and stddef (for size_t type).
- Support configuring all sensor parameters (digital gain, analog gain, integration time, sensitivity, low power modes and trigger mode).
- Support using both continous and single-shoot mode.
- Support for reading RGB data, clear channel data and infra-red channel data.
- Support reading several options to access channels data for optimizing duration of I2C read transactions.
- Support reading device ID.


## Supporter Platforms

Currently Library is ported to following platforms. Library can be easily ported to any other platform by implementing 4 simple functions in `VEML3328_PlatformSpecific.c` file.

- STM32G0 using HAL driver.

## Getting started
1. Go to Release page and download ZIP file targetting your platform or ZIP targeting Generic platform if your platform is not supported.
1. Unzip downloaded file and copy all files to folder of your project or IDE.
1. (If used Generic variant) implement 4 functions in `VEML3328_PlatformSpecific.c` according to descriptions in comments in these functions.
1. Add `#include "VEML3328.h"` at the begining of your source code file.
1. Allocate `VEML3328_Device` structure. It must live for whole time when sensor is used.
1. Call `VEML3328_Init()` function at the begining of your program.
1. Use functions starting with `VEML3328_` prefix as needed. See examples below showing recommended usage of functions.

## Functions
Library contains following functions (you can find this listing in `VEML3328.h` file):

```
VEML3328_Status VEML3328_Init();
VEML3328_Status VEML3328_Deinit();

VEML3328_Status VEML3328_GetDefaultConfiguration(VEML3328_Configuration* config);
VEML3328_Status VEML3328_GetConfiguration(VEML3328_Configuration* config);
VEML3328_Status VEML3328_SetConfiguration(VEML3328_Configuration* config);

VEML3328_Status VEML3328_TriggerSingleShoot();

VEML3328_Status VEML3328_ReadR(uint16_t* r);
VEML3328_Status VEML3328_ReadG(uint16_t* g);
VEML3328_Status VEML3328_ReadB(uint16_t* b);
VEML3328_Status VEML3328_ReadC(uint16_t* c);
VEML3328_Status VEML3328_ReadIR(uint16_t* ir);
VEML3328_Status VEML3328_ReadRGB(uint16_t* r, uint16_t* g, uint16_t* b);
VEML3328_Status VEML3328_ReadGCIR(uint16_t* g, uint16_t* c, uint16_t* ir);
VEML3328_Status VEML3328_ReadRGBCIR(uint16_t* r, uint16_t* g, uint16_t* b, uint16_t* c, uint16_t* ir);

VEML3328_Status VEML3328_GetDeviceId(uint8_t* deviceId);
```

## Examples

Following snippet show basic usage of the library. By default, sensor is in shutdown mode, so you before using them you need to adjust its configuration. This can be done using `VEML3328_SetConfiguration` function which requires pointer to configuration structure. Configuration structure you can fill manually or you can use `VEML3328_GetDefaultConfiguration` which loads defaults to the structure. For using sensor you need to adjust at least `shutdownMode` parameter but you can adjust whatever parameters you want (digital and analog gain, integration time, disable unused channels, ...).

There is also more complex demo project showing basic color detection: [VEML3328-Experiments](https://github.com/misaz/VEML3328-Experiments/blob/main/Core/Src/main.c) and there is blog describing this project and sensor: [Blog #6 Color Detection](https://community.element14.com/challenges-projects/design-challenges/summer-of-sensors-design-challenge/b/blog/posts/veml3328-last-minute-entry-blog-6-color-detection).

```
int main() {
	VEML3328_Status vemlStatus;
	VEML3328_Configuration vemlConfig;

	vemlStatus = VEML3328_Init();
	// TODO: Check vemlStatus and handle possible errors.

	VEML3328_GetDefaultConfiguration(&vemlConfig);
	vemlConfig.shutdownMode = VEML3328_ShutdownMode_PowerOn;

	// TODO: Update sensor configuration here, if needed.

	vemlStatus = VEML3328_SetConfiguration(&vemlConfig);
	// TODO: Check vemlStatus and handle possible errors.

	while (1) {
		uint16_t r, g, b, c, ir;
		vemlStatus = VEML3328_ReadRGBCIR(&r, &g, &b, &c, &ir);
		// TODO: Check vemlStatus and handle possible errors.

		printf("R: %d\tG: %d\tB: %d\tC: %d\tIR: %d\r\n", r, g, b, c, ir);
	}
}
```