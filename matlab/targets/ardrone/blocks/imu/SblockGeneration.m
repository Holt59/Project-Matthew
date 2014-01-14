%Ce script sert à créer un bloc S-function à partir d'une fonction C !

def = legacy_code('initialize')
% Nom du fichier et du header
def.SourceFiles = {'imu.cpp'};
def.HeaderFiles = {'imu.h'};
def.IncPaths = {'.',};

% Nom de la fonction
def.SFunctionName = 'ARDrone_IMU_Acc_Z';
def.Options.language = 'C++';
def.StartFcnSpec = 'IMU_Initialization()';
def.OutputFcnSpec = 'int16 y1 = IMU_Get_Acceleration_Z()';

%YOLO
legacy_code('sfcn_cmex_generate', def);
legacy_code('compile', def);

%Genere le block sous simulink
legacy_code('slblock_generate', def);
legacy_code('sfcn_tlc_generate', def);
legacy_code('rtwmakecfg_generate', def);

% Nom de la fonction
def.SFunctionName = 'ARDrone_IMU_Acc_X';
def.Options.language = 'C++';
def.StartFcnSpec = 'IMU_Initialization()';
def.OutputFcnSpec = 'int16 y1 = IMU_Get_Acceleration_X()';

%YOLO
legacy_code('sfcn_cmex_generate', def);
legacy_code('compile', def);

%Genere le block sous simulink
legacy_code('slblock_generate', def);
legacy_code('sfcn_tlc_generate', def);
legacy_code('rtwmakecfg_generate', def);

% Nom de la fonction
def.SFunctionName = 'ARDrone_IMU_Acc_Y';
def.Options.language = 'C++';
def.StartFcnSpec = 'IMU_Initialization()';
def.OutputFcnSpec = 'int16 y1 = IMU_Get_Acceleration_Y()';

%YOLO
legacy_code('sfcn_cmex_generate', def);
legacy_code('compile', def);

%Genere le block sous simulink
legacy_code('slblock_generate', def);
legacy_code('sfcn_tlc_generate', def);
legacy_code('rtwmakecfg_generate', def);
