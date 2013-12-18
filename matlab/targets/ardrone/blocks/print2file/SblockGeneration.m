%Ce script sert à créer un bloc S-function à partir d'une fonction C !

def = legacy_code('initialize')
% Nom du fichier et du header
def.SourceFiles = {'print2file.c'};
def.HeaderFiles = {'print2file.h'};
def.IncPaths = {'.',};

% Nom de la fonction
def.SFunctionName = 'ARDrone_PRINT2FILE';
% Les sorties sont y1, y2... etc, 
% les entrées sont u1, u2...etc
% les paramètres sont p1, p2 ...
def.StartFcnSpec = 'print2fileInit(uint8 p1[])';
def.OutputFcnSpec = 'void print2file(int32 u1)';
%def.StopFcnSpec = 'print2fileInitClose()';

%YOLO
legacy_code('sfcn_cmex_generate', def);
legacy_code('compile', def);

%Genere le block sous simulink
legacy_code('slblock_generate', def);
legacy_code('sfcn_tlc_generate', def);
legacy_code('rtwmakecfg_generate', def);
