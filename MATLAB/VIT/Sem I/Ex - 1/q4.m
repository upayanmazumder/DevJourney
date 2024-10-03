syms h x y
f(x) = 4*x - x^2;
a=1;
Df=limit((f(x+h)-f(x))/h,h,0)
m=limit((f(x)-f(a))/(x-1),x,a)
m=limit((f(a+h)-f(1))/h,h,0)
g=f(a)+m*(x-a)
Tangent_line=y==g