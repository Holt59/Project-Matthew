%Ce script trop chill sert à créer un bloc S-function à partir d'une
%fonction C !

def = legacy_code('initialize')
% Nom du fichier et du header
def.SourceFiles = {'blocks/led/led.c'};
def.HeaderFiles = {'led.h'};
def.IncPaths = {'blocks\led', '..\paparazzi\include'};
%def.TargetLibFiles = {'ws2_32.lib'};
%def.HostLibFiles = {'-lwsock32'};
%def.TargetLibFiles = {'-lws2_32'};

% Nom de la fonction
def.SFunctionName = 'ex_sfun_led';
% Les entrées sont y1, y2... etc, les entrées sont u1, u2...etc
def.OutputFcnSpec = 'void led(int8 u1, uint8 p1)';

%YOLO
legacy_code('sfcn_cmex_generate', def);
legacy_code('compile', def);

%Genere le block sous simulink
legacy_code('slblock_generate', def);
legacy_code('sfcn_tlc_generate', def);

