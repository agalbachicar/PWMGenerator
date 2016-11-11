/**
 * @author		Agustin Alba Chicar
 * @file		adc.c
 * @brief		This gile configures the adc peripheral and uses it
 * @date		September, 2016
 * @version		1.0
 * @todo
 * @bug
 */

/**
 * @note Includes
 */
#include "adc.h"

/**
 * @note Public variables
 */


/**
 * @note Private variables
 */
static uint8_t adcChannelEnabelState[ADC_CHANNEL_NUMBER];

void (*adcCallback)(adcEChannel channelId, uint32_t value);
/**
 * @note Public functions
 */

int32_t adcInit(uint32_t frequency, void (*adcIntHandler)(adcEChannel channelId, uint32_t value)){
	uint8_t i;
	//Flagueo todos los canales a estado desactivado
	for(i = 0; i < ADC_CHANNEL_NUMBER; i++){
		adcChannelEnabelState[i] = 0;
	}
	//Inicio el modulo del periferico
	ADC_Init(LPC_ADC, frequency);

	adcCallback = adcIntHandler;
	return 0;
}

int32_t adcStart(){
	//Habilito las interrupciones globales
	NVIC_EnableIRQ(ADC_IRQn);
	//Habilito el modo BURST para que haga conversiones de los canales continuamente
	ADC_BurstCmd(LPC_ADC, ENABLE);
	//Arranco la conversion
	ADC_StartCmd(LPC_ADC, ADC_START_CONTINUOUS);

	return 0;
}

int32_t adcStop(){
	//Habilito las interrupciones globales
	NVIC_DisableIRQ(ADC_IRQn);
	//Apago el ADC
	ADC_PowerdownCmd(LPC_ADC, DISABLE);
	//Apago el ADC
	ADC_DeInit(LPC_ADC);

	return 0;
}


int32_t adcConfigChannel(adcEChannel channelId){
	PINSEL_CFG_Type pinConfig;

	//Cargo la configuracion del pin y los flags de interrupcion del canal
	pinConfig.OpenDrain = PINSEL_PINMODE_NORMAL;
	pinConfig.Pinmode = PINSEL_PINMODE_TRISTATE;

	switch(channelId){
		case ADC_CHANNEL_0:
			pinConfig.Portnum = ADC_CHANNEL_0_PORT;
			pinConfig.Pinnum = ADC_CHANNEL_0_PIN;
			pinConfig.Funcnum = ADC_CHANNEL_0_FUNC;

			ADC_IntConfig(LPC_ADC, ADC_ADINTEN0, ENABLE);
			break;
		case ADC_CHANNEL_1:
			pinConfig.Portnum = ADC_CHANNEL_1_PORT;
			pinConfig.Pinnum = ADC_CHANNEL_1_PIN;
			pinConfig.Funcnum = ADC_CHANNEL_1_FUNC;

			ADC_IntConfig(LPC_ADC, ADC_ADINTEN1, ENABLE);
			break;
		case ADC_CHANNEL_2:
			pinConfig.Portnum = ADC_CHANNEL_2_PORT;
			pinConfig.Pinnum = ADC_CHANNEL_2_PIN;
			pinConfig.Funcnum = ADC_CHANNEL_2_FUNC;

			ADC_IntConfig(LPC_ADC, ADC_ADINTEN2, ENABLE);
			break;
		case ADC_CHANNEL_3:
			pinConfig.Portnum = ADC_CHANNEL_3_PORT;
			pinConfig.Pinnum = ADC_CHANNEL_3_PIN;
			pinConfig.Funcnum = ADC_CHANNEL_3_FUNC;

			ADC_IntConfig(LPC_ADC, ADC_ADINTEN3, ENABLE);
			break;
		case ADC_CHANNEL_4:
			pinConfig.Portnum = ADC_CHANNEL_4_PORT;
			pinConfig.Pinnum = ADC_CHANNEL_4_PIN;
			pinConfig.Funcnum = ADC_CHANNEL_4_FUNC;

			ADC_IntConfig(LPC_ADC, ADC_ADINTEN4, ENABLE);
			break;
		case ADC_CHANNEL_5:
			pinConfig.Portnum = ADC_CHANNEL_5_PORT;
			pinConfig.Pinnum = ADC_CHANNEL_5_PIN;
			pinConfig.Funcnum = ADC_CHANNEL_5_FUNC;

			ADC_IntConfig(LPC_ADC, ADC_ADINTEN5, ENABLE);
			break;
		case ADC_CHANNEL_6:
			pinConfig.Portnum = ADC_CHANNEL_6_PORT;
			pinConfig.Pinnum = ADC_CHANNEL_6_PIN;
			pinConfig.Funcnum = ADC_CHANNEL_6_FUNC;

			ADC_IntConfig(LPC_ADC, ADC_ADINTEN6, ENABLE);
			break;
		case ADC_CHANNEL_7:
			pinConfig.Portnum = ADC_CHANNEL_7_PORT;
			pinConfig.Pinnum = ADC_CHANNEL_7_PIN;
			pinConfig.Funcnum = ADC_CHANNEL_7_FUNC;

			ADC_IntConfig(LPC_ADC, ADC_ADINTEN7, ENABLE);
			break;
		default:
			return ERR;
			break;
	}
	PINSEL_ConfigPin(&pinConfig);
	//Cargo la configuracion del canal
	ADC_ChannelCmd(LPC_ADC, channelId, ENABLE);
	//Activo el flag del canal
	adcChannelEnabelState[channelId] = 1;
	return 0;
}

int32_t adcReadChannel(adcEChannel channelId, uint32_t *value){
	//Leo el canal
	*value = ADC_ChannelGetData(LPC_ADC, channelId);
	return 0;
}

/**
 * @note Funciones privadas
 */

void ADC_IRQHandler(){
	uint8_t i;
	//Flagueo todos los canales a estado desactivado
	for(i = 0; i < ADC_CHANNEL_NUMBER; i++){
		//Evaluo si el canal estaba activado
		if(adcChannelEnabelState[i] == 1){
			//Evaluo si tengo callback de conversion
			if(adcCallback != NULL){
				//Analizo el estado
				if(ADC_ChannelGetStatus(LPC_ADC, i, ADC_DATA_DONE) == SET){
					//Emito el callback y leo el canal
					adcCallback((adcEChannel)i, ADC_ChannelGetData(LPC_ADC, i));
				}
			}
		}
	}

}
