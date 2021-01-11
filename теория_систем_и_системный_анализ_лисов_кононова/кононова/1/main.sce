function y = func(x)
   y = 1 ./ x - %pi * cos(%pi .* x);
endfunction;

clf("clear");

x = 0.1:0.1:10;
y = func(x);
//plot2d(x, y, style=[color("blue")], leg="1 ./ x - %pi * cos(%pi .* x)");
//a=gca();
//a.grid=[1 1];
//[x_by_fsolve, v, info] = fsolve(1.5, func, 0.001);


//val = func(0.34)
