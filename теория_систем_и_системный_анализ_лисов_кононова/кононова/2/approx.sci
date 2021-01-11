

function [zr] = GDim1(c, z)
    zr = z(1) - c(1) - c(2) * z(2);
endfunction

function [zr] = GDim2(c, z)
    zr = z(1) - c(1) - c(2) * z(2) - c(3) * z(2) ^ 2
endfunction

function [zr] = GDim3(c, z)
    zr = z(1) - c(1) - c(2) * z(2) - c(3) * z(2) ^ 2 - c(4) * z(2) ^ 3
endfunction

function [zr] = GMy(c, z)
    zr = z(1) - (c(1) * z(2) + c(2)) / (c(3) * z(2) + c(4))
endfunction

//x = [0.8 2.0 3.08 3.91 5.10 5.89 6.99 7.70];
//y = [-20.59 -2.97 3.36 4.93 5.13 4.95 3.33 -3.28];
//c = [0.1;0.1;0.1;0.1];
///z = [y; x];




//function [zr] = GMy(c, z)
//    zr = z(1) - (c(1) * z(2) + c(2)) / (c(3) * z(2) + c(4))
//endfunction

//FMy = (c(1) .* t + c(2)) ./ (c(3) .* t + c(4));


//scf();

x = [5.6 7.2 10.3 13.91];
y = [30.1 20.2 41.4 14.93];
c = [0.1;0.1;0.1;0.1];
t = 5.6:0.01:13.91;
z = [y; x];
clf("clear");
plot(x, y,'r*');
a=gca();
a.grid=[1 1];

[c, S] = datafit(GDim1, z, c);
FDim1 = c(1) + c(2) .* t;
plot2d(t, FDim1, style=[color("blue")]);
scf();
plot(x, y,'r*');
a=gca();
a.grid=[1 1];
[c, S] = datafit(GDim2, z, c);
FDim2 = c(1) + c(2) * t + c(3) * t ^ 2;
plot2d(t, FDim2, style=[color("blue")]);
scf();
plot(x, y,'r*');
a=gca();
a.grid=[1 1];
[c, S] = datafit(GDim3, z, c);
FDim3 = c(1) + c(2) * t + c(3) * t ^ 2 + c(4) * t ^ 3;
plot2d(t, FDim3, style=[color("blue")]);
scf();
plot(x, y,'r*');
a=gca();
a.grid=[1 1];
[c, S] = datafit(GMy, z, c);
FMy = (c(1) .* t + c(2)) ./ (c(3) .* t + c(4));
plot2d(t, FMy, style=[color("blue")]);

