 
%��������� ������������ � 3D-�������


clc   %clears all  from the Command Window
clear %removes all variables from the workspace (memory) 


x = -2:0.1:2;
y = -1:0.1:1;

%���������� ������� u � v � ��������������� ������� X � Y   
[X,Y] = meshgrid(x,y);
Z = exp(-X.^2 - Y.^2);


%������� plot3 ������ ������ 3D-����� �� �������� ������
%������ �������� �� ��������� � ��� !!!
%������� plot3 ���������� ������ ������������ hPlot3 ������������ ������� line
hPlot3 = plot3(X,Y,Z);
title('plot3');
pause

%������� set ������������� ����� �������� ������� line
set(hPlot3,'Color',[1.0 0.0 0.0],'LineWidth', 2);
title('plot3');
pause

%������� set ������������� ��� ����� � �������� 5-10 ����� �������� ������� line
set(hPlot3(5:10),'Color',[0.0 1.0 0.0],'LineWidth', 3);
title('plot3');
pause

%������ ����� � ������� ������������ ����
grid on
title('plot3');
pause

%������������� ����� �� ��� 'x' ������� ���� ���������
xlabel('x')
%������������� ����� �� ��� 'y' ������� ���� ���������
ylabel('y')
%������������� ����� �� ��� 'z' ������� ���� ���������
zlabel('z')
title('plot3');
pause

%������� mesh ������ ����������� ���� mesh �� �������� ������
%������ �������� �� ��������� � ��� !!!
%������� mesh ���������� ���������� hMesh ������������ ������� mesh
hMesh = mesh(X,Y,Z);
title('mesh');
pause

%������� set ������������� ����� �������� ������� mesh
set(hMesh,'LineWidth',2.0);
title('mesh');
pause

%������������ ��������� ����� �����������
hidden off
title('mesh hidden off');
pause

%������������ ��������� ����� �����������
hidden on
title('mesh hidden on');
pause

%������� surf ������ ����������� ���� surf �� �������� ������
surf(X,Y,Z);
title('surf');
pause


%������� surfl ������ ����������� ���� surfl �� �������� ������
surfl(X,Y,Z);
title('surfl');
pause

%�������� ������� ���� autumn
colormap(autumn)
title('autumn');
pause

%�������� ������� ���� colorcube
colormap(colorcube)
title('colorcube');
pause

%�������� ������� ���� cool
colormap(cool)
title('cool');
pause

%�������� ������� ���� flag
colormap(flag)
title('flag');
pause


%�������� ������� ���� gray
colormap(gray)
title('gray');
pause

%�������� ������� ���� hot
colormap(hot)
title('hot');
pause

%�������� ������� ���� hsv
colormap(hsv)
title('hsv');
pause

%�������� ������� ���� jet
colormap(jet)
title('jet');
pause

%�������� ������� ���� lines
colormap(lines)
title('lines');
pause

%�������� ������� ���� pink
colormap(pink)
title('pink');
pause

%�������� ������� ���� prism
colormap(prism)
title('prism');
pause

%�������� ������� ���� spring
colormap(spring)
title('spring');
pause

%�������� ������� ���� summer
colormap(summer)
title('summer');
pause


%�������� ������� ���� white
colormap(white)
title('white');
pause


%�������� ������� ���� winter
colormap(winter)
title('winter');
pause


%�������� ������� ���� copper
colormap(copper)
title('copper');
pause

%������ ����� ���� �� �����������
shading interp








