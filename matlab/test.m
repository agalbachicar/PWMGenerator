clear all;
close all;
clc;

format long g;

f_sampling = 200000;
f_mod = 50000;
f_in = 4000;
N = 256;
A_mod = 4095;
A_in = 1000;

z = [-1 -1];
p = [0.780509037900359+1j*0.179324230971219 0.780509037900359-1j*0.179324230971219];
b = [1 2 1];
a = [1.000000000000000   1.561018075800718   0.641351538057563];

[t, x_mod] = get_triangle(f_sampling, f_mod, A_mod, N, 0.5);
[t, x_in] = get_sine(f_sampling, f_in, A_in, N, 0);

x_in = floor(A_mod/2) + x_in;

y = A_mod .* (x_in < x_mod);
y_filter = filter(b, a, y);

X_in = fft(x_in);
Y_filter = fft(y_filter);


figure;
stem(t, x_mod, 'b')
hold on;
stem(t, x_in, 'r');
stem(t, y, 'g');
grid;
hold off;
title('Señal de control y señal de entrada');

figure;
plot(t, x_mod, 'b')
hold on;
plot(t, x_in, 'r');
plot(t, y, 'g');
grid;
hold off;
title('Señal de control y señal de entrada');

figure;
plot(t, y, 'b');
hold on;
plot(t, y_filter, 'r');
grid;


figure;
plot(20*log10(abs(Y_filter(1:end/2))), 'b');
hold on;
plot(20*log10(abs(X_in(1:end/2))), 'r');
grid;


print_vector('x_mod',x_mod);
