%Ce script sert à créer un bloc S-function à partir d'une fonction C !

def = legacy_code('initialize')
% Nom du fichier et du header
def.SourceFiles = {'ahrs.cpp'};
def.HeaderFiles = {'ahrs.h'};
def.IncPaths = {'.',};

%% Pitch

% Nom de la fonction
def.SFunctionName = 'ARDrone_Pitch';
def.Options.language = 'C++';
def.StartFcnSpec = 'Ahrs_Initialization()';
def.OutputFcnSpec = 'single y1 = Ahrs_Get_Pitch()';

%YOLO
legacy_code('sfcn_cmex_generate', def);
legacy_code('compile', def);

%Genere le block sous simulink
legacy_code('slblock_generate', def);
legacy_code('sfcn_tlc_generate', def);
legacy_code('rtwmakecfg_generate', def);

%% Roll

% Nom de la fonction
def.SFunctionName = 'ARDrone_Roll';
def.Options.language = 'C++';
def.StartFcnSpec = 'Ahrs_Initialization()';
def.OutputFcnSpec = 'single y1 = Ahrs_Get_Roll()';

%YOLO
legacy_code('sfcn_cmex_generate', def);
legacy_code('compile', def);

%Genere le block sous simulink
legacy_code('slblock_generate', def);
legacy_code('sfcn_tlc_generate', def);
legacy_code('rtwmakecfg_generate', def);

%% Pitch

% Nom de la fonction
def.SFunctionName = 'ARDrone_Yaw';
def.Options.language = 'C++';
def.StartFcnSpec = 'Ahrs_Initialization()';
def.OutputFcnSpec = 'single y1 = Ahrs_Get_Yaw()';

%YOLO
legacy_code('sfcn_cmex_generate', def);
legacy_code('compile', def);

%Genere le block sous simulink
legacy_code('slblock_generate', def);
legacy_code('sfcn_tlc_generate', def);
legacy_code('rtwmakecfg_generate', def);
