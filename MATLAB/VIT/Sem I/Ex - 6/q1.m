syms x
f(x) = sqrt(x);
yr = 1;
I = [0,4];
a=I(1);b=I(2);
vol=pi*int((f(x)-yr)^2,a,b);
disp('Volume of solid of revolution is: ');
disp(vol);
fx = matlabFunction(f);
xv = linspace(a,b,10);
[x,y,z] = cylinder(fx(xv) - yr);
z = a +z.*(b-a);
surf(z,y+yr,x)
hold on;
plot([a b], [yr yr], '-r','LineWidth',2);
view(22,11);
xlabel('x-axis');ylabel('y-label');zlabel('z-label');