%Ce script trop chill sert à créer un bloc S-function à partir d'une
%fonction C !

def = legacy_code('initialize')
% Nom du fichier et du header
def.SourceFiles = {'print2file.c'};
def.HeaderFiles = {'print2file.h'};
%def.TargetLibFiles = {'ws2_32.lib'};
%def.HostLibFiles = {'-lwsock32'};
%def.TargetLibFiles = {'-lws2_32'};

% Nom de la fonction
def.SFunctionName = 'ex_sfun_print2file';
% Les entrées sont y1, y2... etc, les entrées sont u1, u2...etc
def.OutputFcnSpec = 'void print2function(int16 u1)';

%YOLO
legacy_code('sfcn_cmex_generate', def);
legacy_code('compile', def);

%Genere le block sous simulink
legacy_code('slblock_generate', def);
legacy_code('sfcn_tlc_generate', def);

