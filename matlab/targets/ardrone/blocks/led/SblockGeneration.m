%Ce script sert à créer un bloc S-function à partir d'une fonction C !

def = legacy_code('initialize')
% Nom du fichier et du header
def.SourceFiles = {'led.cpp'};
def.HeaderFiles = {'led.h'};
def.IncPaths = {'.',};

% Nom de la fonction
def.SFunctionName = 'ARDrone_LED';
% Les sorties sont y1, y2... etc, 
% les entrées sont u1, u2...etc
% les paramètres sont p1, p2 ...
def.Options.language = 'C++';
def.StartFcnSpec = 'LED_Initialization()';
def.OutputFcnSpec = 'void LED_Set(int8 u1, uint8 p1)';

%YOLO
legacy_code('sfcn_cmex_generate', def);
legacy_code('compile', def);

%Genere le block sous simulinktimerID