lineWidth = 2

a1 = 20
a2 = -10
b1 = -5
b2 = -80
q1 = 1
q2 = 1
m = 2

//Функция, описывающая систему дифференциальных уравнений
function dx=variant10(t,x)
dx = zeros(2,1); // нулевой вектор-столбец размерности 2
dx(1) = a1 / (b1 + x(2)^m) - q1 * x(1);
dx(2) = a2 / (b2 + x(1)^m) - q2 * x(2);
endfunction

x0=[0;0];
t0=0;
t=0:0.001:10;

a1 = 20
a2 = -10
x=ode(x0,t0,t,variant10);

a=gca();
a.grid=[1 1];
plot(t,x,'LineWidth',lineWidth)

//построение фазового рисунка
scf();
a=gca();
a.grid=[1 1];
//plot(x(1,:),x(2,:),'LineWidth',lineWidth)

x0=[8;0];
t0=1;
t=1:0.1:10000;
x=ode(x0,t0,t,variant10);
plot(x(1,:),x(2,:),'LineWidth',lineWidth)

//формирует особую точку
x0=[8;4];
t0=1;
t=1:0.001:1000;
x=ode(x0,t0,t,variant10);
plot(x(1,:),x(2,:),'LineWidth',lineWidth)

x0=[1;2];
t0=1;
t=1:0.1:10000;
x=ode(x0,t0,t,variant10);
plot(x(1,:),x(2,:),'LineWidth',lineWidth)

x0=[-8.5;0];
t0=1;
t=1:0.1:100;
x=ode(x0,t0,t,variant10);
plot(x(1,:),x(2,:),'LineWidth',lineWidth)

//формирует особую точку
x0=[-9.5;-2.2];
t0=1;
t=1:0.5:5;
x=ode(x0,t0,t,variant10);
plot(x(1,:),x(2,:),'LineWidth',lineWidth)

x0=[3;-2];
t0=1;
t=1:0.1:5;
x=ode(x0,t0,t,variant10);
plot(x(1,:),x(2,:),'LineWidth',lineWidth)

x0=[-5;-2];
t0=1;
t=1:0.1:100;
x=ode(x0,t0,t,variant10);
plot(x(1,:),x(2,:),'LineWidth',lineWidth)

x0=[-5;2];
t0=1;
t=1:0.1:100;
x=ode(x0,t0,t,variant10);
plot(x(1,:),x(2,:),'LineWidth',lineWidth)
