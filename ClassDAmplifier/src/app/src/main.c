/**
 * @author		Agustin Alba Chicar
 * @author		Maximiliano Vega
 * @file		main.c
 * @brief		This is the main file which initializes the peripherals and then it leaves the control to the FreeRTOS OS
 * @date		September, 2016
 * @version		1.0
 * @todo
 * @bug
 */

/**
 * @note Includes
 */
#include "appConfig.h"
#include "appInit.h"
#include "appHandlers.h"

/**
 * @note Public variables
 */

/**
 * @note Variables privadas
 */


/**
 * @note Funciones publicas
 */
const uint32_t triangleWave[MODULATION_SAMPLES] = {0, 2047, 4095, 2047, 0};

int main( void ){
	appInitOutputs();
	appInitADC();

	while(1);

	return 1;
}

