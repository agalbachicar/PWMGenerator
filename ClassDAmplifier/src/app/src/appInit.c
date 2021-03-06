/**
 * @author		Agustin Alba Chicar
 * @author		Maximiliano Vega
 * @file		appInit.c
 * @brief		This file configures and initializes the different application parts
 * @date		September, 2016
 * @version		1.0
 * @todo
 * @bug
 */

/**
 * @note Includes
 */
#include "appInit.h"

/**
 * @note Public variables
 */

/**
 * @note Private Variables
 */


/**
 * @note Public functions
 */

int32_t appInitOutputs(){
	PINSEL_CFG_Type pinsel;

	pinsel.Funcnum = 0;
	pinsel.OpenDrain = PINSEL_PINMODE_NORMAL;
	pinsel.Pinmode = PINSEL_PINMODE_TRISTATE;
	pinsel.Portnum = OUTPUT_PORT_A;
	pinsel.Pinnum = OUTPUT_PIN_A;
	PINSEL_ConfigPin(&pinsel);

	pinsel.Funcnum = 0;
	pinsel.OpenDrain = PINSEL_PINMODE_NORMAL;
	pinsel.Pinmode = PINSEL_PINMODE_TRISTATE;
	pinsel.Portnum = OUTPUT_PORT_B;
	pinsel.Pinnum = OUTPUT_PIN_B;
	PINSEL_ConfigPin(&pinsel);

	GPIO_SetDir(OUTPUT_PORT_A, (1 << OUTPUT_PIN_A), 1);
	GPIO_SetDir(OUTPUT_PORT_B, (1 << OUTPUT_PIN_B), 1);
	if(OUTPUT_IS_A){
		GPIO_SetValue(OUTPUT_PORT_A, (1 << OUTPUT_PIN_A));
		GPIO_ClearValue(OUTPUT_PORT_B, (1 << OUTPUT_PIN_B));
	}
	else{
		GPIO_ClearValue(OUTPUT_PORT_A, (1 << OUTPUT_PIN_A));
		GPIO_SetValue(OUTPUT_PORT_B, (1 << OUTPUT_PIN_B));
	}

	return 0;
}

int32_t appInitADC(){
	//Inicializo el ADC
	adcInit(ADC_FREQUENCY, appADCEndOfConversionHandler);
	//Cargo un valor
	adcConfigChannel((adcEChannel) 0);
	//Arranco las mediciones
	adcStart();

	return 0;
}
/**
 * @note Private functions
 */
