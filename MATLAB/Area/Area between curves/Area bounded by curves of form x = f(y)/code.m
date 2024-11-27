clear
clc
syms y
f = input("Enter right curve f(y): ");
g = input("Enter left curve f(y): ");
L = input("Enter limits of integration: [a,b]: ");
a = L(1);b = L(2);
Area = int(f-g,y,a,b);
disp(Area);
y1 = linspace(a,b,20);x1 = subs(f,y,y1);
y2 = y1;x2 = subs(g,y,y2);
plot(x1,y1);hold on;plot(x2,y2);hold off;
xlabel('x-axis');ylabel('y-axis');
legend('f(x)','g(x)');grid on;