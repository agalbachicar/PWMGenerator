/**
 * @author	Agustin Alba Chicar
 * @author	Maximiliano Vega
 * @file	appInit.h
 * @brief	This file has the API to configure and initialize different project modules
 * @date	September, 2016
 * @version	1.0
 * @todo
 * @bug
 */
#ifndef APP_INC_APPINIT_H_
#define APP_INC_APPINIT_H_
/**
 * @note        Includes
 */

//! @note Standard Includes
#include <stdint.h>

//! @note CMSIS Includes

//! @note API Includes
#include "appConfig.h"
#include "appHandlers.h"
#include "lpc17xx_gpio.h"
/**
 * @note        Defines
 */
#ifndef ERR
        #define ERR     ((int32_t)-1)
#endif

/**
 * @note        Tipos de datos, estructuras, typdefs
 */


/**
 * @note        Prototipos de funciones publicas
 */

int32_t appInitOutputs();
int32_t appInitADC();
/**
 * @note        Prototipos de funciones privadas
 */

/**
 * @note        Variables publicas
 */


#endif /* APP_INC_APPINIT_H_ */
