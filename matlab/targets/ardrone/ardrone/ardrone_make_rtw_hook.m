function ardrone_make_rtw_hook(hookMethod, modelName, ~, ~, ~, ~)

% Copyright 1996-2011 The MathWorks, Inc.

  switch hookMethod
   case 'error'
    % Called if an error occurs anywhere during the build.  If no error occurs
    % during the build, then this hook will not be called.  Valid arguments
    % at this stage are hookMethod and modelName. This enables cleaning up
    % any static or global data used by this hook file.
    disp(['### Build procedure for model: ''' modelName...
          ''' aborted due to an error.']);
      
   case 'entry'
    % Called at start of code generation process (before anything happens.)
    % Valid arguments at this stage are hookMethod, modelName, and buildArgs.
    i_ardrone_setup(modelName);
    
   case 'before_tlc'
    % Called just prior to invoking TLC Compiler (actual code generation.)
    % Valid arguments at this stage are hookMethod, modelName, and
    % buildArgs
    
   case 'after_tlc'
    % Called just after to invoking TLC Compiler (actual code generation.)
    % Valid arguments at this stage are hookMethod, modelName, and
    % buildArgs
    
    % This check must be done after the model has been compiled otherwise
    % sample time may not be valid
    %i_check_tasking_mode(modelName)

   case 'before_make'
    % Called after code generation is complete, and just prior to kicking
    % off make process (assuming code generation only is not selected.)  All
    % arguments are valid at this stage.
    %i_write_arduino_makefiles;

   case 'after_make'
    % Called after make process is complete. All arguments are valid at 
    % this stage.    
    
    % allow a back door for tests to skip download to hardware
    
    
   case 'exit'
    % Called at the end of the build process.  All arguments are valid at this
    % stage.
    
    disp(['### Successful completion of build ',...
          'procedure for model: ', modelName]);
    if (strcmp(get_param(gcs,'ARDroneUpload'),'on'))
        i_ardrone_upload(get_param(gcs, 'ARDroneIP'), modelName)
    end
      
  end

function i_ardrone_setup(modelName)
    pwd ;

function i_ardrone_upload(ip, modelName)
    disp('### Connecting to drone... ')
    socket = tcpip(ip, 23, 'NetworkRole', 'client')
    fopen(socket)
    disp('### Killing parrot blackbox... ')
    fprintf(socket, 'kill -9 `ps | grep bash | cut -d" " -f 1`')
    fprintf(socket, strcat('kill -9 `ps | grep "', modelName, '" | cut -d" " -f 1`'))
    fprintf(socket, strcat('rm "/data/video/', modelName, '" -f'))
    % UPLOAD... 
    fprintf(socket, strcat('chmod +x "/data/video/', modelName, '"'))
    fprintf(socket, strcat('"/data/video/', modelName, '"'))
    fprintf(socket, 'END')
    fclose(socket)

