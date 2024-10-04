[x,y] = meshgrid(-2:.2:2);
f = x.*exp(-x.^2-y.^2);
surf(x,y,f)