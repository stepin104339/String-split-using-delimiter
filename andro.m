 acce = xlsread('C:\Users\Training\Desktop\MBD LEARNING\matlab learn\sample.csv','','A2:C30')
 gacc = xlsread('C:\Users\Training\Desktop\MBD LEARNING\matlab learn\sample.csv','','D2:F30')
 
 a_vs_g=[acce gacc]
 
 data = a_vs_g;

stepdata = table;

stepdata.ACCELEROMETERXms = data(:,1);
stepdata.ACCELEROMETERYms = data(:,2);
stepdata.ACCELEROMETERZms = data(:,3);
stepdata.GRAVITYXms = data(:,4);
stepdata.GRAVITYYms = data(:,5);
stepdata.GRAVITYZms = data(:,6);
clearvars data a_vs_g acce gacc R;

ax=stepdata.ACCELEROMETERXms;
ay=stepdata.ACCELEROMETERYms;
az=stepdata.ACCELEROMETERZms;
gx=stepdata.GRAVITYXms;
gy=stepdata.GRAVITYYms;
gz=stepdata.GRAVITYZms;


% Changes in Acceleration Sensors will indicate steps
disp('Walking ')
Amag = sqrt(sum(ax.^2 + ay.^2 + az.^2, 4));
disp(Amag);
% Plot magnitude
subplot(3,1,1);
stem(Amag);
xlabel('Time (s)');
ylabel('Acceleration (m/s^2)');
title('ACCE XYZ')


disp('Accerelation due to gravity ')
Gmag = sqrt(sum(gx.^2 + gy.^2 + gz.^2, 4));
disp(Gmag);
gavg=mean(Gmag)
fprintf("the avg acccerelation due to gravity is",gavg)

% Plot magnitude
subplot(3,1,2);
stem(Gmag);
xlabel('Time (s)');
ylabel('Acceleration due to gravity (m/s^2)');
title('GRAV XYZ')
% Remove effects of gravity
magNoGrav = Amag - mean(Amag);
subplot(3,1,3);
stem(magNoGrav);
xlabel('Time (s)');
ylabel('Acceleration (m/s^2)');
title('No Gravity')
% Absolute magnitude

% steo counting
THR = 2;
n = 1;
peaks = [1000];
peaksi = [1000];
minMag = std(Amag);
for k = 2:length(Amag)-1
 if (Amag(k) > minMag) && ... 
 (Amag(k) > THR*amag(k-1)) && ... 
 (Amag(k) > THR*amag(k+1))

 peaks(n) = Amag(k);
 %%peaksi(n) = t(k);
 n = n + 1;
 end
end
if isempty(peaks)
 disp('No Steps')
 return
end
nSteps = length(peaks);
disp('Number of Steps:')
disp(nSteps)
% Plot markers at peaks
hold on;
plot(peaksi, peaks, 'r', 'Marker', 'v', 'LineStyle', 'none');
hold off;
 
