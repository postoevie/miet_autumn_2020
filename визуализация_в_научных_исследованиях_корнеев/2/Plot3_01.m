 
%����������� 3D-�����, �������� � ��������������� ����


clc   %clears all  from the Command Window
clear %removes all variables from the workspace (memory) 


t = 0:pi/50:10*pi;
x = sin(t);
y = cos(t);
z = t;

%������� plot3 ������ 3D-����� �� �������� ������
%������ �������� �� ��������� � ��� !!!
%������� plot3 ���������� ���������� hPlot3 ������������ ������� line
hPlot3 = plot3(x,y,z);
pause

%������� set ������������� ����� �������� ������� line
set(hPlot3,'Color',[0.0 1.0 1.0],'LineWidth', 7);
pause
%������ ����� � ������� ������������ ����
grid on
pause

%������������� ����� �� ��� 'x' ������� ���� ���������
xlabel('x')
%������������� ����� �� ��� 'y' ������� ���� ���������
ylabel('y')
%������������� ����� �� ��� 'z' ������� ���� ���������
%���������� ���������� hZlable ������������ ������� zlable
hZlable = zlabel('z');
pause
%������� set ������������� ����� �������� ������� zlable
set(hZlable,'Color',[1.0 0.5 0.0],'FontSize',[24]);





