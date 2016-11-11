/**
 * @author	Agustin Alba Chicar
 * @file	adc.h
 * @brief	This file has the configurations to handle the ADC peripheral
 * @date	September, 2016
 * @version	1.0
 * @todo
 * @bug
 */


#ifndef API_ADC_ADC_H_
#define API_ADC_ADC_H_

/**
 * @note        Includes
 */

//! @note Standard Includes
#include <stdint.h>

//! @note CMSIS Includes
#include "lpc17xx_pinsel.h"
#include "lpc17xx_adc.h"

/**
 * @note        Defines
 */
#ifndef ERR
        #define ERR     ((int32_t)-1)
#endif

#define	ADC_CHANNEL_NUMBER	8

#define ADC_CHANNEL_0_PORT	0
#define ADC_CHANNEL_0_PIN	23
#define ADC_CHANNEL_0_FUNC	1

#define ADC_CHANNEL_1_PORT	0
#define ADC_CHANNEL_1_PIN	24
#define ADC_CHANNEL_1_FUNC	1

#define ADC_CHANNEL_2_PORT	0
#define ADC_CHANNEL_2_PIN	25
#define ADC_CHANNEL_2_FUNC	1

#define ADC_CHANNEL_3_PORT	0
#define ADC_CHANNEL_3_PIN	26
#define ADC_CHANNEL_3_FUNC	1

#define ADC_CHANNEL_4_PORT	1
#define ADC_CHANNEL_4_PIN	30
#define ADC_CHANNEL_4_FUNC	2

#define ADC_CHANNEL_5_PORT	1
#define ADC_CHANNEL_5_PIN	31
#define ADC_CHANNEL_5_FUNC	2

#define ADC_CHANNEL_6_PORT	0
#define ADC_CHANNEL_6_PIN	3
#define ADC_CHANNEL_6_FUNC	2

#define ADC_CHANNEL_7_PORT	0
#define ADC_CHANNEL_7_PIN	2
#define ADC_CHANNEL_7_FUNC	2

/**
 * @note        Tipos de datos, estructuras, typdefs
 */

typedef ADC_CHANNEL_SELECTION adcEChannel;

/**
 * @note        Prototipos de funciones publicas
 */
int32_t adcInit(uint32_t frequency, void (*adcIntHandler)(adcEChannel channelId, uint32_t value));
int32_t adcStart();
int32_t adcStop();
int32_t adcDeinit();
int32_t adcConfigChannel(adcEChannel channelId);
int32_t adcReadChannel(adcEChannel channelId, uint32_t *value);

/**
 * @note        Prototipos de funciones privadas
 */

void ADC_IRQHandler();
/**
 * @note        Variables publicas
 */
#endif /* API_ADC_ADC_H_ */
