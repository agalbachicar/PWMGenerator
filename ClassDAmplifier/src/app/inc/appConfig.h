/**
 * @file	appConfig.h
 * @author	Agustin Alba Chicar
 * @author	Maximiliano Vega
 * @date	September, 2016
 * @brief	This file configures the project application general behaviour
 */
#ifndef	APP_CONFIG_H
#define	APP_CONFIG_H

//!	@note	Includes

//Standard Includes
#include "stdint.h"

//API Includes
#include "timer.h"
#include "adc.h"

//!	@note	Defines


#define	DEBUG_MODE	0

#define	OUTPUT_PORT_A	0
#define	OUTPUT_PIN_A	0
#define	OUTPUT_PORT_B	0
#define	OUTPUT_PIN_B	1
#define	OUTPUT_IS_A		0
#define OUTPUT_IS_B		(~OUTPUT_IS_A)

#define	ADC_CHANNEL_ID	0
/**
 * @def	ADC_FREQUENCY
 * @brief	The peripheral sampling rate
 */
#define	ADC_FREQUENCY			13000000

#define	MODULATION_SAMPLES	5

//!	@note	Variables globales
extern const uint32_t triangleWave[MODULATION_SAMPLES];

#include "appDebug.h"

#endif
