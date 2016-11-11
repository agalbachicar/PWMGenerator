%%
% get_ sine.m
% Autor: Agustin Alba Chicar
%
% [] = print_vector(v)
%

function [] = print_vector(name, v)
    disp(strrep([name '=[' sprintf(' %d,\n', v) ']'], ',)', ')'))
end