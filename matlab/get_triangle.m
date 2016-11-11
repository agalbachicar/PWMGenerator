%%
% Autor: Agustin Alba Chicar
% Generador de triangulares
%
% [ time, signal  ] = get_triangle( f_samp, f_triangle, amp, n_samples, simetry )
%
% Funcion que permite obtener un vector de valores de una cuadrada
% de características:
% - Frecuencia: f_sine
% - Amplitud: amp
% - Simetria: simetry
% La señal se la samplea a f_samp frecuencia y se toman n_samples muestras
%
% Devuelve en time el vector temporal generado y en signal los valores de
% la funcion


function [ time, signal ] = get_triangle( f_samp, f_triangle, amp, n_samples, simetry )
    %Obtengo un vector de tiempo
    time = 0 : 1 / f_samp : (n_samples-1) / f_samp;
    %Normalizo el tiempo al valor del periodo de la cuadrada
    time_mod = mod(time, 1 / f_triangle);
    %Obtengo el valor de tiempo normalizado que presenta el pico de la señal
    %con la simetria
    time_simetry = simetry / f_triangle;
    %Genero un vector de salida en 0
    signal = zeros(1, length(time_mod));

    for i = 1 : length(time_mod)
        if(time_mod(i) < time_simetry)
            signal(i) = amp / time_simetry * time_mod(i);
        else
            signal(i) = - amp / (1 / f_triangle - time_simetry) * (time_mod(i) - time_simetry) + amp; 
        end
    end
end