%Ce script sert à créer un bloc S-function à partir d'une fonction C !

def = legacy_code('initialize')
% Nom du fichier et du header
def.SourceFiles = {'height.cpp'};
def.HeaderFiles = {'height.h'};
def.IncPaths = {'.'};

% Nom de la fonction
def.SFunctionName = 'ARDrone_Height';
% Les sorties sont y1, y2... etc, 
% les entrées sont u1, u2...etc
% les paramètres sont p1, p2 ...
def.Options.language = 'C++';
def.StartFcnSpec = 'void Height_Initialization(void)';
def.OutputFcnSpec = 'int16 y1 = Height_Get ()';

%YOLO
legacy_code('sfcn_cmex_generate', def);
legacy_code('compile', def);

%Genere le block sous simulink
legacy_code('slblock_generate', def);
legacy_code('sfcn_tlc_generate', def);
legacy_code('rtwmakecfg_generate', def);
