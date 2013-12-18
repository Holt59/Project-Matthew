%Ce script sert à créer un bloc S-function à partir d'une fonction C !

def = legacy_code('initialize')
% Nom du fichier et du header
def.SourceFiles = {'motor.cpp'};
def.HeaderFiles = {'motor.h'};
def.IncPaths = {'.',};

% Nom de la fonction
def.SFunctionName = 'ARDrone_Motor';
% Les sorties sont y1, y2... etc, 
% les entrées sont u1, u2...etc
% les paramètres sont p1, p2 ...
def.Options.language = 'C++';
def.StartFcnSpec = 'Motor_Initialization()';
def.OutputFcnSpec = 'void Motor_Set(single u1, uint8 p1)';

%YOLO
legacy_code('sfcn_cmex_generate', def);
legacy_code('compile', def);

%Genere le block sous simulink
legacy_code('slblock_generate', def);
legacy_code('sfcn_tlc_generate', def);
legacy_code('rtwmakecfg_generate', def);
