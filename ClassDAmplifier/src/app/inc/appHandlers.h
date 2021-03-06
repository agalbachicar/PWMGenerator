/**
 * @author	Agustin Alba Chicar
 * @author	Maximiliano Vega
 * @file	appHandlers.h
 * @brief	This file has the API to handler drivers and application interruptions
 * @date	September, 2016
 * @version	1.0
 * @todo
 * @bug
 */
#ifndef APP_INC_APPHANDLERS_H_
#define APP_INC_APPHANDLERS_H_

/**
 * @note        Includes
 */

//! @note Standard Includes
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
//! @note CMSIS Includes

//! @note API Includes
#include "appConfig.h"


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
void appADCEndOfConversionHandler(adcEChannel channelId, uint32_t value);

/**
 * @note        Prototipos de funciones privadas
 */

/**
 * @note        Variables publicas
 */


#endif /* APP_INC_APPHANDLERS_H_ */
