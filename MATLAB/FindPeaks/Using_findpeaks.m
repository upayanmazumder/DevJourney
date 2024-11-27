clear
clc
syms x
f(x)=sin(abs(x));
I=[-2*pi,2*pi];
f1(x)=-f(x);
a=I(1);b=I(2);
t=linspace(a,b,10000); %Discretizing the interval I
g=double(f(t)); %Finding the values of f(x) at t values
[lmax_f,loc]=findpeaks(g);
lmax_x=round(t(loc),4);
h=double(f1(t));
[lmin_f,loc]=findpeaks(h);
lmin_x=round(t(loc),4);
disp('Local maximum occur at x=')
disp(lmax_x)
disp('The Local Maximum value(s) of the function are ')
disp(double(f(lmax_x)))
disp('Local minimum occur at x=')
disp(lmin_x)
disp('The Local Minimum value(s) of the function are ')
disp(double(f(lmin_x)))
plot(t,f(t));hold on; %Plotting the function
plot(lmax_x,double(f(lmax_x)),'or');%Pointing the localmaxima on the curve of f(x)
plot(lmin_x,double(f(lmin_x)),'*g');%Pointing the local minima on the curve of f(x)
hold off