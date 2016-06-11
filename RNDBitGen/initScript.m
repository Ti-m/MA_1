%initScript.m
%Initialization script for 'RNDBitGen.slx'. This script has to be run
%before using the model. When openning the model, the script is run
%automatically.
format shortEng

sysgenSystemPeriod=4e-9; %geht auch, aber alle delays verschieben sich
assignin('base', 'sysgenSystemPeriod', sysgenSystemPeriod);
Tb = 20e-9;
assignin('base', 'Tb', Tb);

