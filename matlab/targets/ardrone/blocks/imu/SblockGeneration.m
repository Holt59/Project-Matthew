%Ce script sert à créer un bloc S-function à partir d'une fonction C !

def = legacy_code('initialize')
% Nom du fichier et du header
def.SourceFiles = {'imu.cpp'};
def.HeaderFiles = {'imu.h'};
def.IncPaths = {'.',};

% Nom de la fonction
def.SFunctionName = 'ARDrone_IMU_Acc_Z';
% Les sorties sont y1, y2... etc, 
% les entrées sont u1, u2...etc
% les paramètres sont p1, p2 ...
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
