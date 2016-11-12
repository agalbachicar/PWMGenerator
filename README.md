# Amplificador de audio Clase D

## Descripción

Este proyecto consiste en un trabajo de Electronica de Potencia de la carrera de Ingeniería Electronica en UTN FRBA.

Los integrantes de este proyecto son:

1. Agustin Alba Chicar
2. Kuo Yao Ming
3. Matias Araujo
4. Pablo Bronzone

El amplificador consiste en básicamente 2 etapas:

1. Generador de PWM
2. Etapa de potencia

## Estructura del repositorio

Este repositorio contiene la siguiente estructura:

1. ClassDAmplifier --> Codigo del LPC1769 que permite hacer un PWM a partir de una señal adquirida via el ADC.
2. datasheets --> Hojas de dato y notas de aplicacion tomadas como base para el diseño.
3. matlab --> Simulaciones del generador PWM y analisis de señales.
4. simulations --> Modelos de LTSpice del filtro antialias y etapa de salida.

## Generador PWM

Con el microcontrolador se realizo un generador PWM de salida complementaria donde aprovechando la configuracion del ADC de medicion automatica y con los valores de la señal de modulacion cargada previamente, se realiza la comparacion de las señales y se binariza para generar el PWM. La salida se transfiere a dos pines de salida y allí se consiguen los valores para inyectar en el puerto. 

La señal de audio es sampleada a 200KHz, la señal de control a la misma frecuencia y tiene 50KHz. La frecuencia de corte del filtro de audio ronda los 4KHz.

## Etapa de potencia

La etapa de potencia es un medio puente con transistores mosfet del tipo P y N. Ambos, poseen una etapa de pre-excitación de gates con un par de transistores TBJ en configuración totem pole. Previo a los excitadores se colocaron transistores TBJ en pull-down para lograr adaptar los niveles de tensión de la etapa de salida con el de la señal PWM.


