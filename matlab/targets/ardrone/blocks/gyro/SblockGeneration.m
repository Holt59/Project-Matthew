%Ce script sert à créer un bloc S-function à partir d'une fonction C !

def = legacy_code('initialize')
% Nom du fichier et du header
def.SourceFiles = {'gyro.cpp'};
def.HeaderFiles = {'gyro.h'};
def.IncPaths = {'.',};

%% X
% Nom de la fonction
def.SFunctionName = 'ARDrone_Gyro_X';
def.Options.language = 'C++';
def.StartFcnSpec = 'Gyro_Initialization()';
def.OutputFcnSpec = 'single y1 = Gyro_Get_X()';

%YOLO
legacy_code('sfcn_cmex_generate', def);
legacy_code('compile', def);

%Genere le block sous simulink
legacy_code('slblock_generate', def);
legacy_code('sfcn_tlc_generate', def);
legacy_code('rtwmakecfg_generate', def);

%% Y
% Nom de la fonction
def.SFunctionName = 'ARDrone_Gyro_Y';
def.Options.language = 'C++';
def.StartFcnSpec = 'Gyro_Initialization()';
def.OutputFcnSpec = 'single y1 = Gyro_Get_Y()';

%YOLO
legacy_code('sfcn_cmex_generate', def);
legacy_code('compile', def);

%Genere le block sous simulink
legacy_code('slblock_generate', def);
legacy_code('sfcn_tlc_generate', def);
legacy_code('rtwmakecfg_generate', def);

%% Z
% Nom de la fonction
def.SFunctionName = 'ARDrone_Gyro_Z';
def.Options.language = 'C++';
def.StartFcnSpec = 'Gyro_Initialization()';
def.OutputFcnSpec = 'single y1 = Gyro_Get_Z()';

%YOLO
legacy_code('sfcn_cmex_generate', def);
legacy_code('compile', def);

%Genere le block sous simulink
legacy_code('slblock_generate', def);
legacy_code('sfcn_tlc_generate', def);
legacy_code('rtwmakecfg_generate', def);