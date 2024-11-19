surface_area = 64;

syms x y
h = (32 - x * y) / (x + y)
V = x * y * h;

dV_dx = diff(V, x);
dV_dy = diff(V, y);

[sol_x, sol_y] = solve(dV_dx == 0, dV_dy == 0, x > 0, y > 0);

sol_h = (32 - sol_x * sol_y) / (sol_x + sol_y);

fprintf('Optimal Dimensions: \n');
fprintf('Length (x): %.2f cm\n', double(sol_x));
fprintf('Width (y): %.2f cm\n', double(sol_y));
fprintf('Height (h): %.2f cm\n', double(sol_h));

max_volume = double(sol_x * sol_y * sol_h);
fprintf('Maximum Volume: %.2f cm³\n', max_volume)