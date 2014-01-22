%Ce script sert à créer un bloc S-function à partir d'une fonction C !

def = legacy_code('initialize')
% Nom du fichier et du header
def.SourceFiles = {'udp_multi.cpp'};
def.HeaderFiles = {'udp_multi.h'};
def.IncPaths = {'.',};

%% Emission

% Nom de la fonction
def.SFunctionName = 'UDPM_Send_Int32';
def.Options.language = 'C++';
def.StartFcnSpec = 'udp_emission_init(int32 p1)';
def.OutputFcnSpec = 'udp_send_int32(int32 u1, int8 p2)';
def.TerminateFcnSpec = 'udp_emission_terminate()';

%YOLO
legacy_code('sfcn_cmex_generate', def);
legacy_code('compile', def);

%Genere le block sous simulink
legacy_code('slblock_generate', def);
legacy_code('sfcn_tlc_generate', def);
legacy_code('rtwmakecfg_generate', def);

%% Reception

% Nom de la fonction
def.SFunctionName = 'UDPM_Receive_Int32';
def.Options.language = 'C++';
def.StartFcnSpec = 'udp_reception_init(int32 p1)';
def.OutputFcnSpec = 'int32 y1 = udp_recv_int32(int8 p2)';
def.TerminateFcnSpec = 'udp_reception_terminate(void)';

%YOLO
legacy_code('sfcn_cmex_generate', def);
legacy_code('compile', def);

%Genere le block sous simulink
legacy_code('slblock_generate', def);
legacy_code('sfcn_tlc_generate', def);
legacy_code('rtwmakecfg_generate', def);

