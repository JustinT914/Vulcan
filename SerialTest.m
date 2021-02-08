clear all;
close all;
clc;

i = 0;
SREF = '1';

device = serialport("COM3",115200);
configureTerminator(device,"LF")

writeline(device,SREF);

while(i<10)
   readline(device)
   pause(1/2);
   i=i+1;
end