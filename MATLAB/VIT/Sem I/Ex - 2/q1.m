syms x
f(x) = sin(x)
fplot(f(x),[-2*pi,2*pi])
grid on
title('sin(x)')
xlabel('x');
ylabel('y')