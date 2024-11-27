% Configuration script.
% 
% This script configures some simulation settings to make them suitable
% for code generation and use with PySimlink.
%
% See https://lharri73.github.io/PySimlink/src/quickstart.html for
% additional details.

model = 'WT_pitch_actuator_no_sat';
load_system(model);
configs = getActiveConfigSet(model);
mustProp=false;
if isa(configs, 'Simulink.ConfigSetRef')
    configs = eval(configs.SourceName);
    mustProp=true;
end

set_param(configs, 'ConcurrentTasks', 'off');
set_param(configs, 'EnableMultiTasking', 'off');
set_param(configs, 'SystemTargetFile', 'grt.tlc');
set_param(configs, 'GenerateMakefile', 'off');
set_param(configs, 'GenCodeOnly', 'on');
set_param(configs, 'PackageGeneratedCodeAndArtifacts', 'on');
set_param(configs, 'RTWCAPIParams', 'on');
set_param(configs, 'RTWCAPISignals', 'on');
set_param(configs, 'RTWCAPIRootIO', 'on');
set_param(configs, 'RTWCAPIStates', 'on');
set_param(configs, 'GRTInterface', 'off');
set_param(configs, 'CombineOutputUpdateFcns', 'on');

if mustProp
    Simulink.BlockDiagram.propagateConfigSet(model);
end
slbuild(model);