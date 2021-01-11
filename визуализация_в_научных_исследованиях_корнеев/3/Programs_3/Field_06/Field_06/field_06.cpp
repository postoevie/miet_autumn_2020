
//Z-�����,    ����������� �������������


//������ ������� ����� ����������������� ����
//��������� �����, ������� � ��������� ���������
//������� ���������� � Z-������, �������� Z-�����
//����� ���������� Z-������ ���������������� �� ���������
//�� ������� ����� ���������� ������
//����� �������� � ������ ������������ ��� � ���
//����� ����� ���������� ������� ����� ���������� �� �����
 


#include <windows.h>
#include <windowsx.h>
#include <math.h>
#include <stdio.h>
#include <tchar.h>




//��������� ����� �������� ������� ���������
struct ANGLS {
	double fi, teta;
};

//��������� 3D-�����
struct POINT3 {
	double x, y, z;
};

//��������� ����� � ���������� ���������
struct CORD {
	int x, y;
};

//��������� �������
LRESULT CALLBACK WndProc(HWND, UINT, WPARAM, LPARAM);
void LineCreate();
void LineDestroy();
void LinePicture(HWND,int);
//void LinePaint1(HWND);
void LineLButtonDown(HWND,int,int);
void LineMouseMove(HWND,int,int);
void DrawBox(HWND, HDC, ANGLS);
void LineLButtonUp(HWND);
void PointCorns();
void arrowVector(HDC hdc, int x1, int y1, int x2, int y2,double ze, COLORREF rgb);
void LineField(HDC hdc,POINT3 PointB,COLORREF);
double ZPalet(double z);
void ZbufLineWidth(HDC hdc, int x1, int y1, int x2, int y2,
				   double ze1, double ze2, int w, COLORREF rgb);
//void ZbufParallelogram(HDC,int,int,double,int,int,double,
//					   int,int,double,int,int,double,COLORREF);
void ZbufPoligon(HDC,CORD*,double*, COLORREF);
		


//������� �������
int WINAPI WinMain(HINSTANCE hInstance,      
				   HINSTANCE hPrevInstance,
				   LPSTR     lpCmdParam, 
				   int       nCmdShow)     
{

	WCHAR cname[] = L"Class";                 // ��� ������ ���� 
	WCHAR title[] = L"Korneev V.        "     // ��������� ����
			L"   Vector-Field,       "
			L"   rotation  by  mouse  and  keyboard (arrows)";

	
	
	//����������� ������ ���� ����������
	//------------------------------------------------------------------------
	WNDCLASS wc;  // ��������� ��� ����������� ������ ���� ����������

	wc.style          = 0; 
	wc.lpfnWndProc    = (WNDPROC)WndProc;         //����� ������� ����
	wc.cbClsExtra     = 0;       
	wc.cbWndExtra     = 0;       
	wc.hInstance      = hInstance;       //������������� ����������
	wc.hIcon          = LoadIcon(hInstance, (LPCTSTR)IDI_APPLICATION); 
	wc.hCursor		  = LoadCursor(NULL, IDC_ARROW);  
	wc.hbrBackground  = (HBRUSH)GetStockObject(GRAY_BRUSH);   
	wc.lpszMenuName   = 0;       
	wc.lpszClassName  = cname;      

	if(!RegisterClass(&wc))  //����������� ������ ���� ����������
		return 0;


	//�������� ���� ����������
	//------------------------------------------------------------------------
	 HWND hWnd;       // ������������� ���� ����������

	 hWnd = CreateWindow(cname,
						 title,
						 WS_OVERLAPPEDWINDOW,
						 100, 
						 30, 
						 700, 
						 700, 
						 NULL,         //������������� ����-��������     
						 NULL,          //������������� ����
						 hInstance,     //������������� ����������
						 NULL);         

	if(!hWnd)
		return 0;



	// ������ ����. ��� ����� ����� ������� ShowWindow,
    // ��������  ����, �������� ������� UpdateWindows,
    // ���������� ��������� WM_PAINT � ������� ����
 	//--------------------------------------------------------------------------
	ShowWindow(hWnd,nCmdShow);
	UpdateWindow(hWnd); 

	MSG msg;    // ��������� ��� ������ � �����������

	// ��������� ���� ��������� ���������
	//-------------------------------------------------------------------------
  
	while(GetMessage(&msg,NULL,0,0)) 
	{
		TranslateMessage(&msg);
		DispatchMessage(&msg);
	}

	return 0;


}

/*

//������� �������
int PASCAL WinMain(HINSTANCE hInst,
						 HINSTANCE hPrevInstance,
						 LPSTR     lpszCmdParam,
						 int       nCmdShow)
{
	MSG msg;

	if(!RegisterApp(hInst))  //����������� ����������
		return FALSE;

	if(!CreateApp(hInst,nCmdShow))  //�������� ���� ����������
		return FALSE;

	while(GetMessage(&msg,NULL,0,0))   //���� ��������� ���������
	{
		TranslateMessage(&msg);
		DispatchMessage(&msg);
	}

	return msg.wParam;
}

//����������� ������ ����
BOOL RegisterApp(HINSTANCE hInst)
{
	WNDCLASS wc;

	wc.style         = CS_HREDRAW | CS_VREDRAW;
	wc.lpfnWndProc   = WndProc;
	wc.cbClsExtra    = 0;
	wc.cbWndExtra    = 0;
	wc.hInstance     = hInst;
	wc.hIcon         = LoadIcon(NULL, IDI_APPLICATION);
	wc.hCursor		  = LoadCursor(NULL, IDC_ARROW);
	wc.hbrBackground = GetStockBrush(LTGRAY_BRUSH);
	wc.lpszMenuName  = "APP_MENU";
	wc.lpszClassName = szClassName;

	return RegisterClass(&wc);
}



//�������� ����
HWND CreateApp(HINSTANCE hInstance, int nCmdShow)
{
	 HWND hwnd;

	 hwnd = CreateWindow(szClassName,
									 szWindowTitle,
									 WS_OVERLAPPEDWINDOW,
									 CW_USEDEFAULT, 
									 CW_USEDEFAULT, 
									 CW_USEDEFAULT, 
									 CW_USEDEFAULT, 
									 NULL,
									 NULL,
									 hInstance,
									 NULL);

	if(hwnd == NULL)
		return hwnd;

	ShowWindow(hwnd,nCmdShow);
	UpdateWindow(hwnd);

	return hwnd;
}

*/

//���� �������� ������� ��������
ANGLS angl,anglOld;


//������� ��������� ��������� (������� ����) 
LRESULT CALLBACK  WndProc(HWND hwnd, UINT msg,
											WPARAM wParam, LPARAM lParam)
{

	int x,y;
	switch(msg)
	{
		case WM_CREATE:
			LineCreate();
			break;

		case WM_PAINT:
//			InvalidateRect(hwnd,NULL,TRUE);
			LinePicture(hwnd,1);
			break;

		case WM_SIZE:
			InvalidateRect(hwnd,NULL,TRUE);
			break;

		case WM_LBUTTONDOWN:
			x = LOWORD(lParam);
			y = HIWORD(lParam);
			LineLButtonDown(hwnd,x,y);
			break;

		case WM_LBUTTONUP:
			LineLButtonUp(hwnd);
			LinePicture(hwnd,2);
			break;


		case WM_MOUSEMOVE:
			x = LOWORD(lParam);
			y = HIWORD(lParam);
			LineMouseMove( hwnd,x,y);
			break;

		case WM_KEYDOWN:
			switch(wParam)
			{
				case VK_LEFT:
					angl.fi += 10;
					LinePicture(hwnd,2);
					break;

				case VK_RIGHT:
					angl.fi -= 10;
					LinePicture(hwnd,2);
					break;

				case VK_UP:
					angl.teta += 10;
					LinePicture(hwnd,2);
					break;

				case VK_DOWN:
					angl.teta -= 10;
					LinePicture(hwnd,2);
					break;
			}
			break;

		case WM_DESTROY:
			LineDestroy();
			break;

		default:
			return DefWindowProc(hwnd,msg,wParam,lParam);
	}

	return 0L;
}


double const M_PI = 3.141592654;

//��������� �������� � ������
struct TDATA {
	BOOL ButtonDown;
	BOOL Drawing;
};

TDATA Dat;



CORD cor,corOld;

//������� ����, ���������� � ��������� �������� ���������
POINT3 Point[8];
//��������� ����� ����� ����
POINT3 PointB[72];

//��������� 3D-�������
struct VECTORS {
	double x, y, z;
	double dx, dy, dz;
};


//��������� ������� ���������� ����
struct VECMAG {
	double hx, hy, hz;
};


//��������� ��� ���� ������ ������ RGB
struct ColorS{
	unsigned char R, G, B;
};

//��������� Z-������
struct ZbuffS{
	double z; //������� ������ ��� ������� �������
    ColorS c; //��� ����� RGB ��� ������� �������
};

ZbuffS *zb;


//����� �������� � ���� ������
unsigned long Np, Mp, NM;


//������� ��������� ���������
double Px[4], Py[4], Pz[4];

//������� ���� ������ � ������� ����������� � � ��������
double xe1, xe2, ye1, ye2;
int    ne1, ne2, me1, me2;

//����� ������������ ���� (� ������� �����������)
double xmax, ymax, zmax;

//������� ��������� ���������
double ax, ay;


//������ ��������� ��������� � ������ ������ ����������
void LineCreate()
{

//������� ���� ������ � ������� �����������
	xe1 = -2;  xe2 = 2; ye1 = -2; ye2 = 2;

//����� ������������ ���� (� ������� �����������)(������� ����)
	xmax=2.2, ymax=2.2, zmax=2.2;

//������ ������� ����, ���������� � ��������� �������� ���������
	PointCorns();


//������� ��������� ���������
	ax = xmax/2, ay = ymax/2;


//������ ������� ��������� ���������
	Px[0] =   ax;  Py[0] =   ay;  Pz[0] =  0.0;
	Px[1] =  -ax;  Py[1] =   ay;  Pz[1] =  0.0;
	Px[2] =  -ax;  Py[2] =  -ay;  Pz[2] =  0.0;
	Px[3] =   ax;  Py[3] =  -ay;  Pz[3] =  0.0;


//������ ��������� ����� ����� ����
	int i, j, k, N = 6 ,  M = 6;
	double x, y, dx = 2*ax/(N-1), dy = 2*ay/(M-1);
	double d = 0.1;

	for( i=0; i<N; i++)
	{
		x = -ax + dx*i;
		for(j=0; j<M; j++)
		{
			y = -ay + dy*j;
			k = j + 6*i;
			PointB[k].x = x;
			PointB[k].y = y;
			PointB[k].z = d;

			PointB[k+36].x = x;
			PointB[k+36].y = y;
			PointB[k+36].z = -d;
		}
	}


//��������� �������� ����� �������� ������� ���������
	angl.fi = 30; angl.teta = 60;
}


//������ ������� ����, ���������� � ��������� �������� ���������
void	PointCorns()
{
	Point[0].x =  xmax; Point[0].y =  ymax; Point[0].z = -zmax;
	Point[1].x = -xmax; Point[1].y =  ymax; Point[1].z = -zmax;
	Point[2].x = -xmax; Point[2].y = -ymax; Point[2].z = -zmax;
	Point[3].x =  xmax; Point[3].y = -ymax; Point[3].z = -zmax;
	Point[4].x =  xmax; Point[4].y =  ymax; Point[4].z = zmax;
	Point[5].x = -xmax; Point[5].y =  ymax; Point[5].z = zmax;
	Point[6].x = -xmax; Point[6].y = -ymax; Point[6].z = zmax;
	Point[7].x =  xmax; Point[7].y = -ymax; Point[7].z = zmax;
}


//��������� ��������� ���� (hx,hy,hz) � �������� ����� ������������ (x,y,z)
VECMAG magn(double x, double y, double z)
{
	VECMAG mag;
	double s11, s12, s21, s22;
	double u1, u2, v1, v2;

	u1 = x - ax; u2 = x + ax;
	v1 = y - ay; v2 = y + ay;

	s11 = sqrt(u1*u1 + v1*v1 + z*z);
	s12 = sqrt(u1*u1 + v2*v2 + z*z);
	s21 = sqrt(u2*u2 + v1*v1 + z*z);
	s22 = sqrt(u2*u2 + v2*v2 + z*z);


	mag.hx =
			 log(((v1 + s21)/(v1 + s11))*((v2 + s12)/(v2 + s22)));
	mag.hy =
			 log(((u1 + s12)/(u1 + s11))*((u2 + s21)/(u2 + s22)));
	mag.hz =
			 atan((u2*v2)/(z*s22)) - atan((u1*v2)/(z*s12)) -
			 atan((u2*v1)/(z*s21)) + atan((u1*v1)/(z*s11));

	return mag;
}


//��������� ���� ����������
void LineDestroy()
{
	PostQuitMessage(0);   
}


//��������� ������������ ��������������
double dCentral = 4, cCentral = 3; 



//������� ������������ �������� ������� ���������
double sf,cf,st,ct;

//������� �� ������� ������� ��������� � �������
//����������� ��������������
inline double Xe(double x,double y,double z)
{
	double u =(dCentral + cCentral -(st*cf*x+st*sf*y+ct*z))/cCentral; 
	return (-sf*x+cf*y)/u;
}

//������� �� ������� ������� ��������� � �������
// ����������� ��������������
inline double Ye(double x,double y,double z)
{
	double u =(dCentral + cCentral -(st*cf*x+st*sf*y+ct*z))/cCentral; 
	return (-ct*cf*x-ct*sf*y+st*z)/u;
}

//������� �� ������� ������� ��������� � �������
inline double Ze(double x,double y,double z)
{
	return st*cf*x+st*sf*y+ct*z - dCentral;
}




//������� �� ������� ��������� � �������� ����������� 
//������� �� ��������� x � ������� n
inline int xn(double x)
{
	return (int)((x - xe1)/(xe2 - xe1)*(ne2 - ne1)) + ne1;
}

//������� �� ��������� y � ������� m
inline int ym(double y)
{
	return (int)((y - ye1)/(ye2 - ye1)*(me2 - me1)) + me1;
}


//"������" 2D ������-�������
//� ������� ������� ���������� � Z-�������
void arrowVector(HDC hdc, int x1, int y1, int x2, int y2,double ze, COLORREF rgb)
{

	int k = 5; //������� ������� � ��������
	double d = sqrt((double)((x2-x1)*(x2-x1) + (y2-y1)*(y2-y1)));
	double ax = (x1-x2)/d, ay = (y1-y2)/d; 
	int x3, y3, x4, y4, x0, y0;
	
	x0 = int(k*ax) + x2;
	y0 = int(k*ay) + y2;
	x3 = -int(k*ay) + x0;
	y3 = int(k*ax) + y0;
	x4 = int(k*ay) + x0;
	y4 = -int(k*ax) + y0;

	
	ZbufLineWidth(hdc,x3,y3,x2,y2,ze,ze,2,rgb);	
	ZbufLineWidth(hdc,x2,y2,x4,y4,ze,ze,2,rgb);
}


//"������" ���� ����� ���� �� ��������� ����� PointB 
//� ������� ������� ���������� � Z-�������
void LineField(HDC hdc,POINT3 PointB,COLORREF rgb)
{

	VECTORS vect;	
	vect.x = PointB.x;
	vect.y = PointB.y;
	vect.z = PointB.z;
	
	//������� ���������� ������������ �����
	double xe, ye, ze1, ze2;
	//���������� ��������
	int x1,y1,x2,y2;

	double dt = 0.1; //����� ���� �� ����� ����
	double x, y, z, Hx, Hy, Hz, Ha;
	int k = 0;

	VECMAG mag;
	double xt1,yt1,zt1,xt2,yt2,zt2;
	do
	{
		x = vect.x;
		y = vect.y;
		z = vect.z;

		mag = magn(x,y,z);

		Hx = mag.hx;
		Hy = mag.hy;
		Hz = mag.hz;

		Ha = sqrt(Hx*Hx + Hy*Hy + Hz*Hz);
		vect.dx = Hx/Ha;
		vect.dy = Hy/Ha;
		vect.dz = Hz/Ha;

		xt1 = vect.x; yt1 = vect.y; zt1 = vect.z;
		xt2 = xt1 + vect.dx*dt;
		yt2 = yt1 + vect.dy*dt;
		zt2 = zt1 + vect.dz*dt;

		xe=Xe(xt1,yt1,zt1);
		ye=Ye(xt1,yt1,zt1);
		ze1=Ze(xt1,yt1,zt1);
		x1=xn(xe);
		y1=ym(ye);

		xe=Xe(xt2,yt2,zt2);
		ye=Ye(xt2,yt2,zt2);
		ze2=Ze(xt2,yt2,zt2);
		x2=xn(xe);
		y2=ym(ye);

		//"������" ������� ����� ���� 
		ZbufLineWidth(hdc,x1,y1,x2,y2,ze1,ze2,3,rgb);

		vect.x = xt2;
		vect.y = yt2;
		vect.z = zt2;

		//����� 10-� ����� �� ���� ���� "������" �������
		k++;
		if(k == 10)
		{
			arrowVector(hdc,x1,y1,x2,y2,ze2,RGB(0,0,255));
			k = 0;
		}

	//���������� �������� ����� ���� �� ������� ����
	}while((x>-xmax)&&(x<xmax)&&(y>-ymax)&&(y<ymax)&&(z>-zmax)&&(z<zmax));
}



//������ ������� ����������
void LinePicture(HWND hwnd, int Context)
{
//�������� ������ �������� ���������� ��� ������
//---------------------------------------------
	HDC hdcWin;
	PAINTSTRUCT ps;
	//�������� ������� ���������� ��� ������
	if(Context == 1)
		hdcWin = BeginPaint(hwnd, &ps);
	else
		hdcWin = GetDC(hwnd);
//-----------------------------------------------


//��������� ������� ���� ������ � ��������� ���������� ������� ����
//--------------------------------------------------------------------
	RECT rct;
	GetClientRect(hwnd,&rct);

	ne1 = rct.left+50; ne2 = rct.right -50;
	me1 = rct.bottom -50; me2 = rct.top + 50;
//------------------------------------------------------------------

//������� �������� ������
//------------------------------------------------------------
	HDC hdc = CreateCompatibleDC(hdcWin); //������� ��������
                     //������ �������� � ���������� ������

   //������ ���� ������� ��� ������ - ������� ������� ����� � ��������
   // ��� � ������. � ������ ����� �������� �� ������� �����
	HBITMAP hBitmap, hBitmapOld;
	hBitmap = CreateCompatibleBitmap(hdcWin, ne2, me1); //�������
               //������� ����� ���������� � ���������� ������
	hBitmapOld = (HBITMAP)SelectObject(hdc, hBitmap); //��������
                // ������� ����� � �������� ������
//--------------------------------------------------------------
	

//������ �������� ����� � ������� ����� ���� ������
//--------------------------------------------------------	
	//�������� ������������� ������� ��� ������ ����� ��������
	HRGN hrgn2 = CreateRectRgn(ne1,me2-30,ne2,me1);

	//�������� ���������� ������� ����� ������
	HBRUSH hBrush2 = CreateSolidBrush(RGB(0x80,0x80,0x80));
	HBRUSH hBrushOld = (HBRUSH)SelectObject(hdc,hBrush2); 
    FillRgn(hdc,hrgn2,hBrush2);

	SelectObject(hdc,hBrushOld);   
	DeleteObject(hBrush2);         
	DeleteObject(hrgn2);         

	
	//���������� ������� ������������� �������� ������� ���������
	sf=sin(M_PI*angl.fi/180);
	cf=cos(M_PI*angl.fi/180);
	st=sin(M_PI*angl.teta/180);
	ct=cos(M_PI*angl.teta/180);


	//���������� �� ����� �������� ������� ���������
	TCHAR ss[20];
	SetBkColor(hdc,RGB(0xC0,0xC0,0xC0));
	SetTextColor(hdc,RGB(0,0,0x80));
	swprintf_s(ss,20,L"fi = %4.0lf",angl.fi);
	TextOut(hdc,(ne1+ne2)/2-80,me2-25,ss,9);
	swprintf_s(ss,20,L"teta = %4.0lf",angl.teta);
	TextOut(hdc,(ne1+ne2)/2+20,me2-25,ss,11);
//------------------------------------------------

	
	


//��������� ������ ��� Z-����� � ��������� ��� ����������
//-------------------------------------------------------------
	//��������� ����� �������� � ����  ������
	Np = ne2-ne1 + 1, Mp = me1-me2 +1, NM = Np*Mp;

	//�������� ������ ��� Z-����� ��� ������� �������
	zb = new ZbuffS [NM];

	//��������� ���������� z-������ ��� ������� �������
	for ( long unsigned p=0; p<NM; p++)
	{
   		zb[p].z = -1000;
   		zb[p].c.R = 0xC0; zb[p].c.G = 0xC0; zb[p].c.B = 0xC0;
	}
//-----------------------------------------------------------

	

//"������" ��������� ��������� �������� ������ �������� Z-�����	
//-----------------------------------------------------------------------
	//������� ���������� ������������ �����
	double xt1,yt1,zt1;
	//������� ���������� ������������ �����
	double xe,ye,ze1;
	//���������� ���������� ������������ �����
	int x1,y1;

	//���������� ���������� 4-� ����� ���������
	int xp[4], yp[4];
	//������� z-���������� 4-� ����� ���������
	double ze[4];
CORD P[4];
	for(int n=0; n<4; n++)
	{
		xt1 = Px[n]; yt1 = Py[n]; zt1 = Pz[n];
		xe=Xe(xt1,yt1,zt1);
		ye=Ye(xt1,yt1,zt1);
		ze1=Ze(xt1,yt1,zt1);
		x1=xn(xe);
		y1=ym(ye);
		xp[n] = x1; yp[n] = y1; ze[n] = ze1;
		P[n].x = x1; P[n].y = y1;
	}	
//	ZbufParallelogram(hdc,xp[0],yp[0],ze[0],xp[1],yp[1],ze[1],
//		xp[2],yp[2],ze[2],xp[3],yp[3],ze[3],RGB(255,255,0));

	ZbufPoligon(hdc,P,ze,RGB(255,255,0));

//------------------------------------------------------------------

	

//"������" ����� ���� �������� Z-�����
//----------------------------------------------------------------
	for(int i=0; i<36; i++)
	{
		LineField(hdc,PointB[i],RGB(255,0,0));
		
	}
	for(int i=36; i<72; i++)
	{
		LineField(hdc,PointB[i],RGB(0,0,255));
		
	}
//-----------------------------------------------------------------------


//������� ���������� Z-������ � �������� ������
//--------------------------------------------------------------------
	//��������� �� ���� �������� ���� ������
	for (unsigned long ij=0; ij<NM; ij++)
	{
   		x1 = ne1 + ij%Np;
		y1 = me2 + ij/Np;
		SetPixel(hdc,x1,y1,RGB(zb[ij].c.R,zb[ij].c.G,zb[ij].c.B));

	}

	delete [] zb; //������� ������ ��� Z-�������
//-------------------------------------------------------------



//������ ����������� ���
//------------------------------------------------------------------------

	HPEN hPen = CreatePen(PS_SOLID,1,RGB(0,255,255));
	HPEN hPenOld = (HPEN)SelectObject(hdc,hPen);    
	
	int x2,y2;

//��� Ox
	xe=Xe(-xmax/3,0,0);
	ye=Ye(-xmax/3,0,0);
	x1=xn(xe);
	y1=ym(ye);
	xe=Xe(xmax,0,0);
	ye=Ye(xmax,0,0);
	x2=xn(xe);
	y2=ym(ye);
	
	MoveToEx(hdc,x1,y1,NULL);
	LineTo(hdc,x2,y2);

	SetBkColor(hdc,RGB(0xC0,0xC0,0xC0));
	SetTextColor(hdc,RGB(120,120,120));
	TextOut(hdc,x2, y2, _T("X"),1);

//��� Oy
	xe=Xe(0,-ymax/3,0);
	ye=Ye(0,-ymax/3,0);
	x1=xn(xe);
	y1=ym(ye);
	xe=Xe(0,ymax,0);
	ye=Ye(0,ymax,0);
	x2=xn(xe);
	y2=ym(ye);
	
	MoveToEx(hdc,x1,y1,NULL);
	LineTo(hdc,x2,y2);

	SetBkColor(hdc,RGB(0xC0,0xC0,0xC0));
	SetTextColor(hdc,RGB(120,120,120));
	TextOut(hdc,x2, y2, _T("Y"),1);

//��� Oz
	xe=Xe(0,0,0);
	ye=Ye(0,0,-zmax/3);
	x1=xn(xe);
	y1=ym(ye);
	xe=Xe(0,0,0);
	ye=Ye(0,0,zmax);
	x2=xn(xe);
	y2=ym(ye);

	MoveToEx(hdc,x1,y1,NULL);
	LineTo(hdc,x2,y2);

	SetBkColor(hdc,RGB(0xC0,0xC0,0xC0));
	SetTextColor(hdc,RGB(120,120,120));
	TextOut(hdc,x2, y2, _T("Z"),1);


	SelectObject(hdc,hPenOld); 
	DeleteObject(hPen);        
//-----------------------------------------------------------------------------


//������ ���
//----------------------------------------------------------------------
	hPen = CreatePen(PS_SOLID,1,RGB(160,160,160));
	hPenOld = (HPEN)SelectObject(hdc,hPen);    

	DrawBox(hwnd, hdc, angl);

	SelectObject(hdc,hPenOld); 
	DeleteObject(hPen);        
//------------------------------------------------------------------------


//�������� �������� ������ � �������� ������
//-----------------------------------------------------------------------	
	BitBlt(hdcWin,ne1,me2-30,ne2,me1,hdc,ne1,me2-30,SRCCOPY); 
//----------------------------------------------------------------------


//��������� ������ � ����������� � �������
//-------------------------------------------------------------------
	SelectObject(hdc, hBitmapOld); //�������������� �������� ������
	DeleteObject(hBitmap); //������� ������� �����
	DeleteDC(hdc);  //  ����������� �������� ������

	//����������� �������� ������
	if(Context == 1)
		EndPaint(hwnd, &ps);
	else
		ReleaseDC(hwnd, hdcWin);   
}




//������������ ������� ����� ������� �����
void LineLButtonDown(HWND hwnd, int x, int y)
{
	Dat.ButtonDown = TRUE;
	Dat.Drawing = FALSE;
	
	anglOld.fi = angl.fi;
	anglOld.teta = angl.teta;
	corOld.x = x;
	corOld.y = y;
	
//��� ������� ������� ���� ���������� ��� ����� ������
	HDC PaintDC = GetDC(hwnd);
	HPEN hPen, hPenOld;
	hPen = CreatePen(PS_SOLID,1,RGB(0,0,255));
	hPenOld = SelectPen(PaintDC,hPen);   

	SetROP2(PaintDC, R2_NOTXORPEN);
		
	DrawBox(hwnd, PaintDC, anglOld);

	SelectPen(PaintDC,hPenOld);  
	DeletePen(hPen);           

	ReleaseDC(hwnd, PaintDC);
}


//������������ ���������� ����� ������� �����
void LineLButtonUp(HWND hwnd)
{
	if(Dat.ButtonDown && Dat.Drawing)
		Dat.Drawing = FALSE;

	Dat.ButtonDown = FALSE;
}


//������������ �������� ���� ��� ������� ����� �������
void LineMouseMove(HWND hwnd,int x, int y)
{

	if(Dat.ButtonDown)
	{
		Dat.Drawing = TRUE;

		HDC PaintDC = GetDC(hwnd);
		
		//�������������� ��� � ����� ��������� � ������ NOTXOR
		HPEN hPen, hPenOld;
		hPen = CreatePen(PS_SOLID,1,RGB(0,0,255));
		hPenOld = SelectPen(PaintDC,hPen);  

		SetROP2(PaintDC, R2_NOTXORPEN);
		
		DrawBox(hwnd, PaintDC, anglOld);

		angl.fi += corOld.x-x;
		angl.teta += corOld.y-y;
		
		corOld.x = x; corOld.y = y;

		anglOld.fi   = angl.fi;
		anglOld.teta   = angl.teta;

		DrawBox(hwnd, PaintDC, anglOld);

		SelectPen(PaintDC,hPenOld);   
		DeletePen(hPen);           


		//���������� �� ����� �������� ����
		TCHAR ss[20];
		SetBkColor(PaintDC,RGB(0xC0,0xC0,0xC0));
		SetTextColor(PaintDC,RGB(0,0,0x80));
		swprintf_s(ss,20,L"fi = %4.0lf",angl.fi);
		TextOut(PaintDC,(ne1+ne2)/2-80,me2-25,ss,9);
		swprintf_s(ss,20,L"teta = %4.0lf",angl.teta);
		TextOut(PaintDC,(ne1+ne2)/2+20,me2-25,ss,11);

		ReleaseDC(hwnd, PaintDC);
	}

}


//������ ���, ��������� � ��������� �������� ���������
void DrawBox(HWND hwnd, HDC hdc, ANGLS an)
{
	sf=sin(M_PI*an.fi/180);
	cf=cos(M_PI*an.fi/180);
	st=sin(M_PI*an.teta/180);
	ct=cos(M_PI*an.teta/180);

	double xe, ye;
	int x1,y1,x2,y2;
	double xt1,yt1,zt1,xt2,yt2,zt2;
	int j;

	for(int i=0; i<4; i++)
	{
		j = i + 1;
		if(j==4)
			j = 0;
		xt1 = Point[i].x; yt1 = Point[i].y; zt1 = Point[i].z;
		xt2 = Point[j].x; yt2 = Point[j].y; zt2 = Point[j].z;

		xe=Xe(xt1,yt1,zt1);
		ye=Ye(xt1,yt1,zt1);
		x1=xn(xe);
		y1=ym(ye);

		xe=Xe(xt2,yt2,zt2);
		ye=Ye(xt2,yt2,zt2);
		x2=xn(xe);
		y2=ym(ye);

		MoveToEx(hdc,x1,y1,NULL);
		LineTo(hdc,x2,y2);
	}



	for(int i=4; i<8; i++)
	{
		j = i + 1;
		if(j==8)
			j = 4;
		xt1 = Point[i].x; yt1 = Point[i].y; zt1 = Point[i].z;
		xt2 = Point[j].x; yt2 = Point[j].y; zt2 = Point[j].z;

		xe=Xe(xt1,yt1,zt1);
		ye=Ye(xt1,yt1,zt1);
		x1=xn(xe);
		y1=ym(ye);

		xe=Xe(xt2,yt2,zt2);
		ye=Ye(xt2,yt2,zt2);
		x2=xn(xe);
		y2=ym(ye);

		MoveToEx(hdc,x1,y1,NULL);
		LineTo(hdc,x2,y2);
	}

	for(int i=0; i<4; i++)
	{
		xt1 =   Point[i].x; yt1 =   Point[i].y; zt1 =   Point[i].z;
		xt2 = Point[i+4].x; yt2 = Point[i+4].y; zt2 = Point[i+4].z;

		xe=Xe(xt1,yt1,zt1);
		ye=Ye(xt1,yt1,zt1);
		x1=xn(xe);
		y1=ym(ye);

		xe=Xe(xt2,yt2,zt2);
		ye=Ye(xt2,yt2,zt2);
		x2=xn(xe);
		y2=ym(ye);

		MoveToEx(hdc,x1,y1,NULL);
		LineTo(hdc,x2,y2);
	}


	for(int i=0; i<2; i++)
	{
		xt1 =   Point[i].x; yt1 =   Point[i].y; zt1 =   Point[i].z;
		xt2 = Point[i+2].x; yt2 = Point[i+2].y; zt2 = Point[i+2].z;

		xe=Xe(xt1,yt1,zt1);
		ye=Ye(xt1,yt1,zt1);
		x1=xn(xe);
		y1=ym(ye);

		xe=Xe(xt2,yt2,zt2);
		ye=Ye(xt2,yt2,zt2);
		x2=xn(xe);
		y2=ym(ye);

		MoveToEx(hdc,x1,y1,NULL);
		LineTo(hdc,x2,y2);
	}


}



//������� ��� �������� �������, ������� ��������� ������ � ����� Z-������  
double ZPalet(double z)
{
	double a,b,f;
	a = -2.0*xmax - dCentral;
	b = 0.5*xmax - dCentral;

	if(z < a)
		f = 0;
	if( (z >= a) && (z <= b))
		f = (z - a)/(b-a);
	if(z > b)
		f = 1;
	return f;
}

//"������" ����� �� ��������, ������ rgb, �������� Z-����� zb 
//x1,y12,x2,y2 - ���������� ����� � ���������� ���������
//ze1, ze2 - z-���������� ������ ����� � ������� ������� ���������
//�� ���� rgb ������������� ������� ZPalet, ������� ��������� ������ � ����� Z-������  
void ZbufLine(HDC hdc, int x1, int y1, int x2, int y2,
			  double ze1, double ze2, COLORREF rgb)
{
	int dx = abs(x2 - x1);
	int dy = abs(y2 - y1);
	int sx = x2 >= x1 ? 1 : -1;
	int sy = y2 >= y1 ? 1 : -1;
    unsigned long p;
    double zz;

	unsigned char r,g,b;


	if(dy <= dx)
	{

		int d = (dy << 1) - dx;
		int d1 = dy << 1;
		int d2 = (dy - dx) << 1;

		if((x1 >= ne1)&&(x1 <= ne2)&&(y1 >= me2)&&(y1 <= me1))
		{
			p = (x1 - ne1) +(y1 - me2)*Np;
			zz = ze1;
			if(zb[p].z < zz)
			{
				zb[p].z = zz;
				r = unsigned char(rgb);
				g = unsigned char(rgb>>8);
				b = unsigned char(rgb>>16);
				zb[p].c.R = unsigned char(r*ZPalet(zz));
				zb[p].c.G = unsigned char(g*ZPalet(zz));
				zb[p].c.B = unsigned char(b*ZPalet(zz));
			}
		}

		for(int x = x1 + sx, y = y1, i = 1; i <= dx; i++, x += sx)
		{
			if(d > 0)
			{
				d += d2;
				y += sy;
			}
			else
				d += d1;

			if((x >= ne1)&&(x <= ne2)&&(y >= me2)&&(y <= me1))
			{
				p = (x - ne1) +(y - me2)*Np;
				zz = ze1 + (ze2 - ze1)*(x - x1)/(x2 - x1);
			if(zb[p].z < zz)
			{
				zb[p].z = zz;
				r = (unsigned char) rgb;
				g = (unsigned char) (rgb>>8);
				b = (unsigned char) (rgb>>16);
				zb[p].c.R = unsigned char(r*ZPalet(zz));
				zb[p].c.G = unsigned char(g*ZPalet(zz));
				zb[p].c.B = unsigned char(b*ZPalet(zz));
			}
			}
		}
	}
	else
	{

		int d = (dx << 1) - dy;
		int d1 = dx << 1;
		int d2 = (dx - dy) << 1;

		if((x1 >= ne1)&&(x1 <= ne2)&&(y1 >= me2)&&(y1 <= me1))
		{
			p = (x1 - ne1) +(y1 - me2)*Np;
			zz = ze1;
			if(zb[p].z < zz)
			{
				zb[p].z = zz;
				r = (unsigned char) rgb;
				g = (unsigned char) (rgb>>8);
				b = (unsigned char) (rgb>>16);
				zb[p].c.R = unsigned char(r*ZPalet(zz));
				zb[p].c.G = unsigned char(g*ZPalet(zz));
				zb[p].c.B = unsigned char(b*ZPalet(zz));
			}
		}
		for(int x = x1, y = y1 + sy, i = 1; i <= dy; i++, y += sy)
		{
			if(d > 0)
			{
				d += d2;
				x += sx;
			}
			else
				d += d1;
		
			if((x >= ne1)&&(x <= ne2)&&(y >= me2)&&(y <= me1))
			{
				p = (x - ne1) +(y - me2)*Np;
				zz = ze1 + (ze2 - ze1)*(y - y1)/(y2 - y1);
			if(zb[p].z < zz)
			{
				zb[p].z = zz;
				r = (unsigned char) rgb;
				g = (unsigned char) (rgb>>8);
				b = (unsigned char) (rgb>>16);
				zb[p].c.R = unsigned char(r*ZPalet(zz));
				zb[p].c.G = unsigned char(g*ZPalet(zz));
				zb[p].c.B = unsigned char(b*ZPalet(zz));
			}
			}
		
		}
	}
}


//"������" ����� �������� w - ��������, ������ rgb, �������� Z-�����
//x1,y12,x2,y2 - ���������� ����� � ���������� ���������
//ze1, ze2 - z-���������� ������ ����� � ������� ������� ���������
void ZbufLineWidth(HDC hdc, int x1, int y1, int x2, int y2,
				   double ze1, double ze2, int w, COLORREF rgb)
{
	
	int n,m;
	if(w == 1)
	{
		ZbufLine(hdc,x1,y1,x2,y2,ze1,ze2,rgb);
	}
	else
	{
		int dx = abs(x2 - x1);
		int dy = abs(y2 - y1);
		if(dx >= dy)
		{
			m = w/2;
			if(w%2 == 0)
				n = -m +1;
			else
				n = -m;
			for(int i = n; i <= m; i++)
				ZbufLine(hdc,x1,y1+i,x2,y2+i,ze1,ze2,rgb);
		}
		else
		{
			m = w/2;
			if(w%2 == 0)
				n = -m +1;
			else
				n = -m;
			for(int i = n; i <= m; i++)
				ZbufLine(hdc,x1+i,y1,x2+i,y2,ze1,ze2,rgb);
		}
	}


}


/*

//"������" �������������, ������ rgb, �������� Z-�����
//x1,y12,x2,y2,x3,y3,x4,y4 - ���������� ������ � ���������� ���������
//ze1,ze2,ze3,ze4 - z-���������� ������ � ������� ������� ���������
void ZbufParallelogram(HDC hdc,int x1,int y1,double ze1,
					   int x2,int y2,double ze2,
					   int x3,int y3,double ze3,
					   int x4,int y4,double ze4,COLORREF rgb)
{

	double zz,zzb;

	int dx = abs(x2 - x1);
	int dy = abs(y2 - y1);
	int sx = x2 >= x1 ? 1 : -1;
	int sy = y2 >= y1 ? 1 : -1;


	if(dy <= dx)
	{

		int d = (dy << 1) - dx;
		int d1 = dy << 1;
		int d2 = (dy - dx) << 1;

		ZbufLine(hdc,x1,y1,x4,y4,ze1,ze4,rgb);
		for(int x = x1 + sx, y = y1, xb = x4 + sx, yb = y4, i = 1;
			i <= dx; i++, x += sx, xb += sx)
		{
			if(d > 0)
			{
				d += d2;
				y += sy;
				yb += sy;
			}
			else
				d += d1;

			zz = ze1 + (ze2 - ze1)*(x - x1)/(x2 - x1);
			zzb = ze4 + (ze3 - ze4)*(xb - x4)/(x3 - x4);
			ZbufLineWidth(hdc,x,y,xb,yb,zz,zzb,2,rgb);
		}
	}
	else
	{

		int d = (dx << 1) - dy;
		int d1 = dx << 1;
		int d2 = (dx - dy) << 1;

		for(int x = x1, y = y1 + sy, xb = x4, yb = y4 + sy, i = 1;
		i <= dy; i++, y += sy, yb += sy)
		{
			if(d > 0)
			{
				d += d2;
				x += sx;
				xb += sx;
			}
			else
				d += d1;
		
			zz = ze1 + (ze2 - ze1)*(y - y1)/(y2 - y1);
			zzb = ze4 + (ze3 - ze4)*(yb - y4)/(y3 - y4);
			ZbufLineWidth(hdc,x,y,xb,yb,zz,zzb,2,rgb);
		
		}
	}
}
*/


//"������" �������� 4-�������, ������ rgb, �������� Z-�����
//P[4] - ���������� ������ � ���������� ���������
//Ze[4] - z-���������� ������ � ������� ������� ���������
void ZbufPoligon(HDC hdc,CORD* P,double* Ze, COLORREF rgb)
{
	int i,j;
	int x1,y1,x2,y2,xl,xr, x, y;
	double ze1,ze2,zel,zer;
	int xc[2];
	double zc[2], zz;
	unsigned long p;
	unsigned char r,g,b;

	int ymin = 100000, ymax = 0;
	for( i=0; i<4; i++)
	{
		if(P[i].y <= ymin) ymin = P[i].y;
		if(P[i].y >= ymax) ymax = P[i].y;
	}
	

	for( y = ymin + 1; y < ymax; y++)
	{
		
		int k = 0;
		for( i =0; i < 4; i++)
		{
				j = i + 1;
			if(j == 4)
				j = 0;
			
			x1 = P[i].x; y1 = P[i].y; ze1 = Ze[i];
			x2 = P[j].x; y2 = P[j].y; ze2 = Ze[j];



			if(((y > y1)&&(y <= y2))||((y >= y2)&&(y < y1)))
			{
				xc[k] = x1 + int(double(x2-x1)/double(y2-y1)*double(y-y1));
				
				zc[k++] = ze1 + (ze2 - ze1)*(y - y1)/(y2 - y1);
			}
		
			
		}
	
		if(xc[0] < xc[1])
		{
			xl = xc[0]; xr = xc[1]; zel = zc[0]; zer = zc[1];
		}
		else
		{
			xl = xc[1]; xr = xc[0]; zel = zc[1]; zer = zc[0];
		}
	
		for( x = xl; x <= xr; x++)
		{
		//	SetPixel(hdc,x,y,rgb);

  
			if((x >= ne1)&&(x <= ne2)&&(y >= me2)&&(y <= me1))
			{
				p = (x - ne1) +(y - me2)*Np;
				zz = zel + (zer - zel)*(x - xl)/(xr - xl);
			if(zb[p].z < zz)
			{
				zb[p].z = zz;
				r = (unsigned char) rgb;
				g = (unsigned char) (rgb>>8);
				b = (unsigned char) (rgb>>16);
				zb[p].c.R = unsigned char(r*ZPalet(zz));
				zb[p].c.G = unsigned char(g*ZPalet(zz));
				zb[p].c.B = unsigned char(b*ZPalet(zz));
			}
			}
		}


	}


}










