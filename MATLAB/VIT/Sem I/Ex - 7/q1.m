syms x y z L
f(x,y) =  x^2 + y^2;
g(x,y) = x+y-10;
F = f+L*g;
Fx = diff(F,x);Fy = diff(F,y);
S = solve(g,Fx,Fy,'Real',true);
St_pts = [S.x,S.y];
St_pts = double(St_pts)
Fun_Val = f(S.x,S.y);
Fun_Val = double(Fun_Val)
x = linspace(min(S.x) - 3,max(S.x)+3,20);x=double(x);
y = linspace(min(S.y) - 3,max(S.y)+3,20);Y=double(y);
[x y] = meshgrid(x,y);
z = f(x,y); z= double(z);
surf(x,y,z); hold on;
xlabel('x');ylabel('y');zlabel('z')
gv = fimplicit(g,'b');
hold on;
xv = get(gv,'XData');
yv = get(gv,'YData');
fv = f(xv,yv);fv = double(fv)
plot3(xv,yv,fv,'-r');