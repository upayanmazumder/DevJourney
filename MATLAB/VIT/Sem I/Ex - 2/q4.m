theta = linspace(0,2*pi,200);
r = 3 * cos(theta/2).^2+theta;
polar(theta,r)