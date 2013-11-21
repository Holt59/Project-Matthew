%Ce script trop chill sert à créer un bloc S-function à partir d'une
%fonction C !

def = legacy_code('initialize')
% Nom du fichier et du header
def.SourceFiles = {'../src/proto/led.c'};
def.HeaderFiles = {'led.h'};
def.IncPaths = {'../src/proto',};

% Nom de la fonction
def.SFunctionName = 'AR_Drone_LED';
% Les entrées sont y1, y2... etc, les entr�es sont u1, u2...etc
def.OutputFcnSpec = 'void led(int32 u1, uint8 p1)';

%YOLO
legacy_code('sfcn_cmex_generate', def);
legacy_code('compile', def);

%Genere le block sous simulink
legacy_code('slblock_generate', def);
legacy_code('sfcn_tlc_generate', def);

