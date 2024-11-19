syms x y z
V = [x, 2*y^2, 3*z^2];
div_curl_V = divergence(curl(V, [x, y, z]), [x, y, z]);
disp(simplify(div_curl_V));
[x, y, z] = meshgrid(-2:1:2);
quiver3(x, y, z, x, 2*y.^2, 3*z.^2);
xlabel( 'x'); ylabel ('y' ); zlabel('z ' ); title('Vector Field V'); 