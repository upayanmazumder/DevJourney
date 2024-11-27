clear
clc
syms x
f = input('Enter curve f(x): ');
L = input('Enter limits [a,b]: ');
a = L(1);b=L(2);
Area = int(abs(f),x,a,b);
disp("The area is: ")
disp(Area)
x1 = linspace(a,b,20);y1 = subs(f,x,x1);
plot(x1,y1);
xlabel('x-axis');ylabel('y-label');
legend('f(x)');grid on;