%Ce script sert à créer un bloc S-function à partir d'une fonction C !

def = legacy_code('initialize')
% Nom du fichier et du header
def.SourceFiles = {'baro.cpp'};
def.HeaderFiles = {'baro.h'};
def.IncPaths = {'.',};

%% Pressure

% Nom de la fonction
def.SFunctionName = 'ARDrone_Pressure';
def.Options.language = 'C++';
def.StartFcnSpec = 'Barometer_Initialization()';
def.OutputFcnSpec = 'int32 y1 = Barometer_Get_Pressure()';

%YOLO
legacy_code('sfcn_cmex_generate', def);
legacy_code('compile', def);

%Genere le block sous simulink
legacy_code('slblock_generate', def);
legacy_code('sfcn_tlc_generate', def);
legacy_code('rtwmakecfg_generate', def);


%% Temperature

% Nom de la fonction
def.SFunctionName = 'ARDrone_Temperature';
def.Options.language = 'C++';
def.StartFcnSpec = 'Barometer_Initialization()';
def.OutputFcnSpec = 'int32 y1 = Barometer_Get_Temperature()';

%YOLO
legacy_code('sfcn_cmex_generate', def);
legacy_code('compile', def);

%Genere le block sous simulink
legacy_code('slblock_generate', def);
legacy_code('sfcn_tlc_generate', def);
legacy_code('rtwmakecfg_generate', def);