t = linspace(0,2*pi,500);
x = cos(t);
y = sin(t);
z = sin(5*t);
comet3(x,y,z);
plot3(x,y,z);
xlabel('x-axis');
ylabel('y-axis');
zlabel('z-axis');
title('3D Curve')