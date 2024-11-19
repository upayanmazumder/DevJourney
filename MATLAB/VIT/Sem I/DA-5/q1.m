syms x y z
V = [x, 2*y^2, 3*z^3];
curl_V = curl(V, [x,y,z]);
div_curl_V = divergence(curl_V, [x,y,z]);
disp('Divergence of the curl: ');
disp(div_curl_V);
[X, Y, Z] = meshgrid(-2:0.5:2, -2:0.5:2, -2:0.5:2);
U = X; V = 2*Y.^2; W = 3*Z.^3;
figure;
quiver3(X,Y,Z,U,V,W);
xlabel('X');
ylabel('Y');
zlabel('Z');
title('Vector Field V(x, y, z)');
grid on;