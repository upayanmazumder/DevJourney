syms x
f = (x^2 - 1) / (x^2 - 6*x + 5)
LL = limit(f,x,5,"left")
RL = limit(f,x,5,"right")
L = limit(f,x,5)