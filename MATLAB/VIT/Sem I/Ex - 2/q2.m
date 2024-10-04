syms f(x)
f(x) = piecewise(-2<=x<=-1,-x-2,-1<x<=1,x,1<x<=2,-x+2);
fplot(f(x), [-2,-1], 'b', 'LineWidth',2);
grid on;hold on
fplot(f(x), [-0.999,1], 'b', 'LineWidth',2);
fplot(f(x), [1.001,2], 'b', 'LineWidth',2);
plot(-1,f(-1),'bo','MarkerFaceColor', 'w', 'MarkerSize', 10);
plot(1,f(1),'bo', 'MarkerFaceColor', 'w','MarkerSize',10);
axis equal;axis([-2 2 -2 2]);
xlabel('x');ylabel('y')