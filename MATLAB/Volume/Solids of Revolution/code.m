clear 
clc
syms x 
f(x)=input('Enter the function f(x): ');
yr = input('Enter the function yr: ');
I = input('Enter the limits of integration for x [a,b]: ');
a = I(1);b=I(2);
vol = pi*int((f(x)-yr)^2,a,b);
disp('Volume of solid of revolution is: ');
disp(vol);
fx=matlabFunction(f);
xv = linspace(a,b,101);
[X,Y,Z] = cylinder(fx(xv)-yr);
Z = a+Z.*(b-a);
surf(Z,Y+yr,X)
hold on;
plot([a b],[yr yr],'-r','LineWidth',2);
view(22,11);
xlabel('X-axis');ylabel('Y-axis')