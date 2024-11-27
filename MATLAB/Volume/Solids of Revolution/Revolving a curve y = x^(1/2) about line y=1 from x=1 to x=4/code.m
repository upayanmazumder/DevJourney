% Evaluation of Volume of solid of revolution
clear
clc
syms x
f(x)=sqrt(x); % Given function
yr=1; % Axis of revolution y=yr
I=[0,4]; % Interval of integration
a=I(1);b=I(2);
vol=pi*int((f(x)-yr)^2,a,b);
disp('Volume of solid of revolution is: ');
disp(vol); % Visualization of solid of revolution
fx=matlabFunction(f);
xv = linspace(a,b,101); % Creates 101 points from a to b
[X,Y,Z] = cylinder(fx(xv)-yr);
Z = a+Z.*(b-a); % Extending the default unit height of the
% cylinder profile to the interval of integration
surf(Z,Y+yr,X) % Plotting the solid of revolution about y=yr
hold on;
plot([a b],[yr yr],'-r','LineWidth',2); % Plotting the line y=yr
view(22,11); % 3-D graph viewpoint specification
xlabel('X-axis');ylabel('Y-axis');zlabel('Z-axis');