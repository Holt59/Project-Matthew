function ardrone_select_callback_handler(hDlg, hSrc)

% Copyright 2009-2010 The MathWorks, Inc.

% The target is model reference compliant
slConfigUISetVal(hDlg, hSrc, 'ModelReferenceCompliant', 'on');
slConfigUISetEnabled(hDlg, hSrc, 'ModelReferenceCompliant', false);

% Hardware being used is the production hardware
slConfigUISetVal(hDlg, hSrc, 'ProdEqTarget', 'on');

% Setup the hardware configuration
slConfigUISetVal(hDlg, hSrc, 'ProdHWDeviceType', 'Atmel->AVR');
        
% Set the target language to C and disable modification
slConfigUISetVal(hDlg, hSrc, 'TargetLang', 'C');
slConfigUISetEnabled(hDlg, hSrc, 'TargetLang', 0);

% Set the TargetLibSuffix
slConfigUISetVal(hDlg, hSrc, 'TargetLibSuffix', '.a');        

% For real-time builds, we must generate ert_main.c
slConfigUISetVal(hDlg, hSrc, 'ERTCustomFileTemplate', 'ardrone_file_process.tlc');
