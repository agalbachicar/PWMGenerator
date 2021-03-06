/**
 * @author		Agustin Alba Chicar
 * @author		Maximiliano Vega
 * @file		appHandlers.c
 * @brief		This file has the API to handler drivers and application interruptions
 * @date		September, 2016
 * @version		1.0
 * @todo
 * @bug
 */

/**
 * @note Includes
 */
#include "appHandlers.h"

/**
 * @note Public variables
 */

/**
 * @note Private Variables
 */


/**
 * @note Public functions
 */

void appADCEndOfConversionHandler(adcEChannel channelId, uint32_t value){
	static uint32_t i = 0;

	if(channelId != ADC_CHANNEL_ID){
		return;
	}

	if(value < triangleWave[i]){
		LPC_GPIO0->FIOSET = (1 << OUTPUT_PIN_A);
		LPC_GPIO0->FIOCLR = (1 << OUTPUT_PIN_B);
	}
	else{
		LPC_GPIO0->FIOSET = (1 << OUTPUT_PIN_B);
		LPC_GPIO0->FIOCLR = (1 << OUTPUT_PIN_A);
	}

	DEBUG_2_ARG("%d - %d", value, triangleWave[i]);
	i++;
	if(i >= MODULATION_SAMPLES){
		i = 0;
	}

	//printf("%d: %d\n", channelId, value);
}
/**
 * @note Private functions
 */
