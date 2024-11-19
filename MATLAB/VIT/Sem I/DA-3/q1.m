syms x y z L
f(x,y,z)=x*y*z;
g(x,y,z)=2*(x*y+y*z+z*x)-64;
F=f+L*g;
Fx=diff(F,x);Fy=diff(F,y);Fz=diff(F,z);
S=solve(g,Fx,Fy,Fz,'Real',true);
St_pts=[S.x,S.y,S.z];
St_pts=double(St_pts);
Fun_Val=f(S.x,S.y,S.z);
Fun_Val=double(Fun_Val) 