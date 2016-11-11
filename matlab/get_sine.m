%%
% get_ sine.m
% Autor: Agustin Alba Chicar
%
% [ output ] = get_sine( f_samp, f_sine, amp, n_samples, phase )
% Funcion que permite obtener un vector de valores de una senoidal
% de características:
% - Frecuencia: f_sine
% - Amplitud: amp
% - Fase: phase
% La señal se la samplea a f_samp frecuencia y se toman n_samples muestras
%
% Devuelve en output las muestras
%

function [time, signal] = get_sine( f_samp, f_sine, amp, n_samples, phase )
    %Obtengo el vector temporal
    angle = 0: 1/f_samp: (n_samples-1) / f_samp;
    time = angle;
    %Lo normalizo a la velocidad angular de la onda
    angle = angle * 2 * pi * f_sine;
    %Genero la salida a partir del angulo mas la fase
    signal = amp * sin(angle + phase);
end
