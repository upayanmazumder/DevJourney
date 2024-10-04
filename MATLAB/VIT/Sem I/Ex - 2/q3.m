x = linspace(-2,4,20);
y = 3*x.^3 - 26*x + 10;
dy = 9*x.^2 - 26;
ddy = 18*x;
plot(x,y,x,dy,x,ddy);
legend('y','first derivative','second derivative')