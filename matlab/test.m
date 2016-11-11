clear all;
close all;
clc;

format long g;

f_sampling = 200000;
f_mod = 50000;
f_in = 1000;
N = 256;
A_mod = 4095;
A_in = 1000;

z = [-1 -1];
p = [0.780509037900359+1j*0.179324230971219 0.780509037900359-1j*0.179324230971219];
b = [1 2 1];
a = [1.000000000000000   1.561018075800718   0.641351538057563];

%Genero la señal de modulacion
[t, x_mod] = get_triangle(f_sampling, f_mod, A_mod, N, 0.5);
%Genero la señal de entrada
[t, x_in] = get_sine(f_sampling, f_in, A_in, N, 0);
%Genero el vector de frecuecia
f = 0:f_sampling/N:f_sampling*(N-1)/(2*N);

%Monto en nivel de continua la señal de entrada
x_in = floor(A_mod/2) + x_in;
%Genero el PWM
y = A_mod .* (x_in < x_mod);


y_filter = filter(b, a, y);

%Calculo los espectros
X_in = abs(fft(x_in));
X_in = 1/max(X_in).* X_in;

Y = abs(fft(y));
Y = 1/max(Y) .* Y;


figure;
stem(t, x_mod, 'b')
hold on;
stem(t, x_in, 'r');
stem(t, y, 'g');
grid;
hold off;
legend('Señal de modulacion', 'Señal de entrada');
title('Señal de control y señal de entrada');

figure;
plot(t, x_mod, 'b')
hold on;
plot(t, x_in, 'r');
plot(t, y, 'g');
grid;
hold off;
legend('Señal de modulacion', 'Señal de entrada', 'Señal de salida');
title('Señal de control y señal de entrada');

figure;
plot(t, y, 'b');
hold on;
plot(t, y_filter, 'r');
grid;
legend('Señal de salida', 'Señal de salida filtrada');
title('Señales de salida');

figure;
plot(f, 20*log10(Y(1:end/2)), 'b');
hold on;
plot(f, 20*log10(X_in(1:end/2)), 'r');
grid;
legend('Espectro de salida', 'Espectro de entrada');
title('Espectros');



print_vector('x_mod',x_mod);
print_vector('x_in',x_in);
