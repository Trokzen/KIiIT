// mw1Dlg.cpp : implementation file
//

#include "stdafx.h"
#include "mw1.h"
#include "mw1Dlg.h"

#include <math.h>
#include <process.h>

#ifdef _DEBUG
#define new DEBUG_NEW
#endif 


// Cmw1Dlg dialog




Cmw1Dlg::Cmw1Dlg(CWnd* pParent /*=NULL*/)
	: CDialog(Cmw1Dlg::IDD, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void Cmw1Dlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_EDIT1, RabPath);
}

BEGIN_MESSAGE_MAP(Cmw1Dlg, CDialog)
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	//}}AFX_MSG_MAP
	ON_BN_CLICKED(IDC_BUTTON1, &Cmw1Dlg::OnBnClickedButton1)
	ON_BN_CLICKED(IDC_BUTTON2, &Cmw1Dlg::OnBnClickedButton2)
END_MESSAGE_MAP()


// Cmw1Dlg message handlers

BOOL Cmw1Dlg::OnInitDialog()
{
	CDialog::OnInitDialog();

	RabPath.SetWindowText("c:\\wrem");


	// Set the icon for this dialog.  The framework does this automatically
	//  when the application's main window is not a dialog
	SetIcon(m_hIcon, TRUE);			// Set big icon
	SetIcon(m_hIcon, FALSE);		// Set small icon

	// TODO: Add extra initialization here

	return TRUE;  // return TRUE  unless you set the focus to a control
}

// If you add a minimize button to your dialog, you will need the code below
//  to draw the icon.  For MFC applications using the document/view model,
//  this is automatically done for you by the framework.

void Cmw1Dlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // device context for painting

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// Center icon in client rectangle
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// Draw the icon
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialog::OnPaint();
	}
}

// The system calls this function to obtain the cursor to display while the user drags
//  the minimized window.
HCURSOR Cmw1Dlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}


void Cmw1Dlg::OnBnClickedButton1()
{

CFile f1, f2;
CString RPath;
CString FileName;

CWaitCursor wait; 
wait.Restore( );
// destructor automatically removes the wait cursor


  long fl;
  char *buff, *c0, *c1;
  int i, j, i0, j0;

  char buff2[200];


  int NN, HSarVbr, HSarAbr, HATM;
  double V, AstA, OmegaC, VB, P, DD, Tc, AstB, Tetta;
  double NuB, Epsilon, DeltaB;

  double AstC, Eps2, DeltaC, VCmin;


RabPath.GetWindowText(RPath);
FileName = RPath + "\\m1.txt";

if(!f1.Open(FileName , CFile::modeRead)) {
	MessageBox("Не найден исходный файл", "Ошибка");
	OnOK();
	exit(-1);
}

FileName = RPath + "\\result.txt";

if(!f2.Open(FileName , CFile::modeCreate | CFile::modeWrite)) {
	MessageBox("Ошибка создания файла результатов", "Ошибка");
	OnOK();
	exit(-1);
}

sprintf(buff2,"\x0d\x0a CИНТЕЗ ОДНОРОДНОЙ ПАКЕТНОЙ ИНФОТЕЛЕКОММУНИКАЦИОННОЙ СИСТЕМЫ \x0d\x0a\x0d\x0a");
f2.Write(buff2,strlen(buff2));



fl = (int) f1.GetLength();
buff = new char[fl+1];

  c0=buff;
  c1=buff;



f1.Read(buff, fl);


// пропускаем ненужные символы
  for(i=0; i<fl; i++)
	if(((*c0)>='0' && (*c0)<='9')||(*c0=='E')||(*c0=='-')||(*c0=='.')||(*c0==' '))
		*c1++=*c0++;
	    else  {
	      if((*c0)=='\n')
		*c1++=' ';
	      c0++;
	    }

  *c0++=' ';


  c0=buff;


  while(*c0 == ' ') c0++;
  sscanf((const char *)c0, "%d", &HSarVbr);  //считывание HSarVbr
//  printf("\n HSarVbr:      %d", HSarVbr);
  sprintf(buff2,"\x0d\x0a HSarVbr:      %d", HSarVbr);
  f2.Write(buff2,strlen(buff2));
  while(*c0++ != ' ');

  while(*c0 == ' ') c0++;
  sscanf(c0, "%d", &HSarAbr);  //считывание HSarAbr
//  printf("\n HSarAbr:      %d", HSarAbr);
  sprintf(buff2,"\x0d\x0a HSarAbr:      %d", HSarAbr);
  f2.Write(buff2,strlen(buff2));
  while(*c0++ != ' ');

  while(*c0 == ' ') c0++;
  sscanf(c0, "%d", &HATM);  //считывание HATM
//  printf("\n HATM:      %d", HATM);
  sprintf(buff2,"\x0d\x0a HATM:      %d", HATM);
  f2.Write(buff2,strlen(buff2));
  while(*c0++ != ' ');


  while(*c0 == ' ') c0++;
  sscanf(c0, "%le", &V);  //считывание скорости
//  printf("\n скорость V:      %e", V);
  sprintf(buff2,"\x0d\x0a скорость V:      %e", V);
  f2.Write(buff2,strlen(buff2));
  while(*c0++ != ' ');

  while(*c0 == ' ') c0++;
  sscanf(c0, "%lf", &AstA);  //считывание AstA
//  printf("\n AstA:      %f", AstA);
  sprintf(buff2,"\x0d\x0a AstA:      %f", AstA);
  f2.Write(buff2,strlen(buff2));
  while(*c0++ != ' ');

  while(*c0 == ' ') c0++;
  sscanf(c0, "%lf", &OmegaC);  //считывание OmegaC
//  printf("\n OmegaC:      %f", OmegaC);
  sprintf(buff2,"\x0d\x0a OmegaC:      %f", OmegaC);
  f2.Write(buff2,strlen(buff2));
  while(*c0++ != ' ');


  while(*c0 == ' ') c0++;
  sscanf(c0, "%lf", &VB);  //считывание vB
  sprintf(buff2,"\x0d\x0a VB:      %f", VB);
  f2.Write(buff2,strlen(buff2));
  while(*c0++ != ' ');


  while(*c0 == ' ') c0++;
  sscanf(c0, "%le", &P);  //считывание P
  sprintf(buff2,"\x0d\x0a P:      %e", P);
  f2.Write(buff2,strlen(buff2));
  while(*c0++ != ' ');


  while(*c0 == ' ') c0++;
  sscanf(c0, "%d", &NN);  //считывание NN
  sprintf(buff2,"\x0d\x0a NN:      %d", NN);
  f2.Write(buff2,strlen(buff2));
  while(*c0++ != ' ');

  while(*c0 == ' ') c0++;
  sscanf(c0, "%lf", &DD);  //считывание D
  sprintf(buff2,"\x0d\x0a DD:      %f", DD);
  f2.Write(buff2,strlen(buff2));
  while(*c0++ != ' ');

  while(*c0 == ' ') c0++;
  sscanf(c0, "%lf", &Tc);  //считывание Tc
  sprintf(buff2,"\x0d\x0a Tc:      %f", Tc);
  f2.Write(buff2,strlen(buff2));
  while(*c0++ != ' ');

  while(*c0 == ' ') c0++;
  sscanf(c0, "%lf", &AstB);  //считывание AstB
  sprintf(buff2,"\x0d\x0a AstB:      %f", AstB);
  f2.Write(buff2,strlen(buff2));
  while(*c0++ != ' ');

  while(*c0 == ' ') c0++;
  sscanf(c0, "%lf", &Tetta);  //считывание Tetta
  sprintf(buff2,"\x0d\x0a Tetta:      %f", Tetta);
  f2.Write(buff2,strlen(buff2));
  while(*c0++ != ' ');

  while(*c0 == ' ') c0++;
  sscanf(c0, "%lf", &NuB);  //считывание nuB
  sprintf(buff2,"\x0d\x0a NuB:      %f", NuB);
  f2.Write(buff2,strlen(buff2));
  while(*c0++ != ' ');

  while(*c0 == ' ') c0++;
  sscanf(c0, "%le", &Epsilon);  //считывание Epsilon
  sprintf(buff2,"\x0d\x0a Epsilon:      %le", Epsilon);
  f2.Write(buff2,strlen(buff2));
  while(*c0++ != ' ');

  while(*c0 == ' ') c0++;
  sscanf(c0, "%lf", &DeltaB);  //считывание DeltaB
  sprintf(buff2,"\x0d\x0a DeltaB:      %lf", DeltaB);
  f2.Write(buff2,strlen(buff2));
  while(*c0++ != ' ');

  while(*c0 == ' ') c0++;
  sscanf(c0, "%lf", &AstC);  //считывание AstC
  sprintf(buff2,"\x0d\x0a AstC:      %lf", AstC);
  f2.Write(buff2,strlen(buff2));
  while(*c0++ != ' ');

  while(*c0 == ' ') c0++;
  sscanf(c0, "%le", &Eps2);  //считывание Eps2
  sprintf(buff2,"\x0d\x0a Eps2:      %le", Eps2);
  f2.Write(buff2,strlen(buff2));
  while(*c0++ != ' ');

  while(*c0 == ' ') c0++;
  sscanf(c0, "%lf", &DeltaC);  //считывание DeltaC
  sprintf(buff2,"\x0d\x0a DeltaC:      %lf", DeltaC);
  f2.Write(buff2,strlen(buff2));
  while(*c0++ != ' ');


 // считываем таблицу для определения Z
 int iZ, jZ;   // - размерность таблицы
  while (*c0 == ' ') c0++;
  sscanf(c0, "%d", &iZ);
  while(*c0++ != ' ');
  while(*c0 == ' ') c0++;
  sscanf(c0, "%d", &jZ);
  sprintf(buff2,"\x0d\x0a\x0d\x0a\x0d\x0a Размер таблицы для определения Z: %d x %d", iZ, jZ);
  f2.Write(buff2,strlen(buff2));
  while(*c0++ != ' ');

  double *DDD, *ZZZ;
  int *NNN;
  NNN = new int[sizeof(int)*iZ];
  DDD = new double[sizeof(double)*jZ];
  ZZZ = new double[sizeof(double)*iZ*jZ];
  sprintf(buff2,"\x0d\x0a NNN : \x0d\x0a");
  f2.Write(buff2,strlen(buff2));
  for(i=0; i<iZ; i++) {
        while (*c0 == ' ') c0++;
        sscanf(c0, "%d", NNN+i);
        while(*c0++ != ' ');
        sprintf(buff2,"  %d ", *(NNN+i));
        f2.Write(buff2,strlen(buff2));
   }
  sprintf(buff2,"\x0d\x0a DDD : \x0d\x0a");
  f2.Write(buff2,strlen(buff2));
  for(i=0; i<jZ; i++) {
        while (*c0 == ' ') c0++;
        sscanf(c0, "%lf", DDD+i);
        while(*c0++ != ' ');
        sprintf(buff2,"  %lf ", *(DDD+i));
        f2.Write(buff2,strlen(buff2));
   }
  for(j=0; j<jZ; j++)
    for(i=0; i<iZ; i++) {
        while (*c0 == ' ') c0++;
        sscanf(c0, "%lf", ZZZ+i+j*iZ);
        while(*c0++ != ' ');
  }
  sprintf(buff2,"\x0d\x0a ZZZ : \x0d\x0a");
  f2.Write(buff2,strlen(buff2));
  for(j=0; j<jZ; j++) {
    for(i=0; i<iZ; i++) {
        sprintf(buff2,"  %lf ",  *(ZZZ+i+j*iZ));
        f2.Write(buff2,strlen(buff2));
     }
    sprintf(buff2,"\x0d\x0a ");
    f2.Write(buff2,strlen(buff2));
  }

delete buff;

f1.Close();


// шаг 1
  double ZZ, VBst;


 sprintf(buff2,"\x0d\x0a шаг 1: \x0d\x0a");
 f2.Write(buff2,strlen(buff2));
    // определяем ZZ по таблице
 i0=-1;
 j0=-1;
 for(i=0; i<iZ; i++)
       if(*(NNN+i) == NN) {
          i0=i;
          break;
   }

 for(i=0; i<jZ; i++)
       if(*(DDD+i) == DD) {
          j0=i;
          break;
   }
 if(i0==-1||j0==-1){
   sprintf(buff2,"\x0d\x0a\x0d\x0a Не определено Z по таблице\x0d\x0a\x0d\x0a");
   f2.Write(buff2,strlen(buff2));
   exit(-1);
   }
 ZZ = *(ZZZ+i0+j0*iZ);
 sprintf(buff2,"Z по таблице: %lf \x0d\x0a", ZZ);
 f2.Write(buff2,strlen(buff2));
 VBst=NuB*ZZ*VB*AstB;
 sprintf(buff2,"VBst: %lf \x0d\x0a", VBst);
 f2.Write(buff2,strlen(buff2));


 double RoBmax = -0.5, Alfa1;
 double LBopt, LCopt, LCopt1, LCopt2;
 double RoB = 0.;
 double VBstMin;

 double TCpac;

 while(abs(RoB-RoBmax) >= Epsilon) {
    while (RoBmax <= 0 || RoBmax > 1.0) {
   //шаг 2
    sprintf(buff2,"\x0d\x0a Шаг 2: \x0d\x0a");
    f2.Write(buff2,strlen(buff2));
	Alfa1 = sqrt((HSarVbr+HATM)*V/ZZ/Tetta);
	LBopt = ((Tetta*VB + HSarVbr)*Alfa1 - HATM*VB)/(Alfa1+VB);
    sprintf(buff2,"DeltaB, Alfa1, LBopt: %lf %lf %lf \x0d\x0a", DeltaB, Alfa1, LBopt);
    f2.Write(buff2,strlen(buff2));
	RoBmax = 1.-ZZ*((double)LBopt+(double)HATM)*VB/(VB*Tetta-((double)LBopt-(double)HSarVbr))/V;
    sprintf(buff2,"Alfa1, LBopt, RoBmax: %lf %lf %lf \x0d\x0a", Alfa1, LBopt, RoBmax);
    f2.Write(buff2,strlen(buff2));
   //шаг 3
    sprintf(buff2,"\x0d\x0a Шаг 3: \x0d\x0a");
    f2.Write(buff2,strlen(buff2));
	if (RoBmax <= 0 || RoBmax > 1.0 || LBopt <= HSarVbr)
			V=V+DeltaB;
     }


   //шаг 4
    RoB = ((double)LBopt - (double)HSarVbr)*VB*AstB*NuB/((double)LBopt + (double)HATM)/V;
    sprintf(buff2,"\x0d\x0a Шаг 4: \x0d\x0a");
    f2.Write(buff2,strlen(buff2));
    sprintf(buff2,"RoB : %lf ", RoB);
    f2.Write(buff2,strlen(buff2));

   //шаг 5
    if (fabs(RoB-RoBmax) < Epsilon)  {
	VBstMin = V*(LBopt-HSarVbr)/(LBopt+HATM)*P*(1-ZZ*(LBopt+HATM)*VB/(VB*Tetta-(LBopt-HSarVbr))/V);
    sprintf(buff2,"\x0d\x0a Шаг 5: \x0d\x0a");
    f2.Write(buff2,strlen(buff2));
    sprintf(buff2,"VBstMin : %lf ", VBstMin);
    f2.Write(buff2,strlen(buff2));
	break;
     }

   //шаг 6
    if ((RoB<RoBmax && DeltaB>0) || (RoB>RoBmax && DeltaB<0))
	DeltaB = -DeltaB/2;
    V = V+DeltaB;
    sprintf(buff2,"\x0d\x0a Шаг 6: \x0d\x0a");
    f2.Write(buff2,strlen(buff2));
    sprintf(buff2,"V : %lf ", V);
    f2.Write(buff2,strlen(buff2));
    RoB = 0;
    RoBmax = -0.5;

 }


   //шаг 7
 double A3, Q3, C3, x;

 RoB = 0.95*RoB;

CONTINUE1:
 A3 = (NN+(1-RoB)*V/OmegaC) - (NN+(1-RoB)*V/OmegaC)*((double)HATM+(double)HSarAbr)/OmegaC/Tc;
 A3 = A3-(Tc*V*(1-RoB)-NN*(((double)LBopt)+((double)HATM))*RoB/(1-RoB)-NN*(((double)HSarAbr) + ((double)HATM)))/OmegaC/Tc;
 Q3 = (NN+(1-RoB)*V/OmegaC)*((double)HATM);
 C3 = (Tc*V*(1-RoB)-NN*(((double)LBopt)+((double)HATM))*RoB/(1-RoB)-NN*(((double)HATM) + ((double)HSarAbr)))*HATM;
 sprintf(buff2,"\x0d\x0a V, DeltaC, A3, Q3, C3: %lf %lf %lf %lf %lf \x0d\x0a", V, DeltaC, A3, Q3, C3);
 f2.Write(buff2,strlen(buff2));

 x = Q3*Q3+A3*C3;
 LCopt1 = (-Q3+sqrt(Q3*Q3+A3*C3))/A3 + HSarAbr;
 LCopt2 = (-Q3-sqrt(Q3*Q3+A3*C3))/A3 + HSarAbr;

 sprintf(buff2,"\x0d\x0a Шаг 7: \x0d\x0a");
 f2.Write(buff2,strlen(buff2));


  if(LCopt1 > LCopt2)
	LCopt = LCopt1;
      else
	LCopt = LCopt2;
 sprintf(buff2,"LCopt1, LCopt2, LCopt: %lf %lf lf ", LCopt1, LCopt2, LCopt);
 f2.Write(buff2,strlen(buff2));

  if (LCopt <=0 ) {
     V = V + 1000;
     goto CONTINUE1;
    }


 sprintf(buff2,"\x0d\x0a Шаг 9: \x0d\x0a");
 f2.Write(buff2,strlen(buff2));
 VCmin = V*(((double)LCopt) - ((double)HSarAbr))/(((double)LCopt)+((double)HATM));
// VCmin = VCmin*(1. - RoBmax - (((double)LCopt)+((double)HATM))*NN/(Tc - (((double)LCopt) - ((double)HSarAbr))/OmegaC)/(1.-RoBmax)/V);
 VCmin = VCmin*(1. - RoB - (((double)LCopt)+((double)HATM))*NN/(Tc - (((double)LCopt) - ((double)HSarAbr))/OmegaC)/(1.-RoB)/V);
 sprintf(buff2,"VCmin: %lf ", VCmin);
 f2.Write(buff2,strlen(buff2));

 while (AstC * 64000. >= VCmin || fabs(AstC*64000. - VCmin) >= Eps2) {
    sprintf(buff2,"\x0d\x0a Шаг 10 -  Пересчет LBopt, RoB, LCopt, VCmin: \x0d\x0a");
    f2.Write(buff2,strlen(buff2));
	if((AstC * 64000. > VCmin && DeltaC < 0.) || (AstC*64000. < VCmin && DeltaC > 0.))
		DeltaC = -DeltaC/2.;
	V = V +DeltaC;
	Alfa1 = sqrt((HSarVbr+HATM)*V/ZZ/Tetta);
	LBopt = ((Tetta*VB + HSarVbr)*Alfa1 - HATM*VB)/(Alfa1+VB);
	RoB = ((double)LBopt - (double)HSarVbr)*VB*AstB*NuB/((double)LBopt + (double)HATM)/V;
 RoB = 0.95*RoB;
	A3 = (NN+(1-RoB)*V/OmegaC) - (NN+(1-RoB)*V/OmegaC)*((double)HATM+(double)HSarAbr)/OmegaC/Tc;
	A3 = A3-(Tc*V*(1-RoB)-NN*(((double)LBopt)+((double)HATM))*RoB/(1-RoB)-NN*(((double)HSarAbr) + ((double)HATM)))/OmegaC/Tc;
	Q3 = (NN+(1-RoB)*V/OmegaC)*((double)HATM);
	C3 = (Tc*V*(1-RoB)-NN*(((double)LBopt)+((double)HATM))*RoB/(1-RoB)-NN*(((double)HATM) + ((double)HSarAbr)))*HATM;
    sprintf(buff2,"Alfa1, LBopt, RoB: %lf %lf %lf \x0d\x0a", Alfa1, LBopt, RoB);
    f2.Write(buff2,strlen(buff2));
    sprintf(buff2,"\x0d\x0a V, DeltaC, A3, Q3, C3: %lf %lf %lf %lf %lf \x0d\x0a", V, DeltaC, A3, Q3, C3);
    f2.Write(buff2,strlen(buff2));

	x = Q3*Q3+A3*C3;
	LCopt1 = (-Q3+sqrt(Q3*Q3+A3*C3))/A3 + HSarAbr;
	LCopt2 = (-Q3-sqrt(Q3*Q3+A3*C3))/A3 + HSarAbr;
	if(LCopt1 > LCopt2)
		LCopt = LCopt1;
	    else
		LCopt = LCopt2;
	VCmin = V*(((double)LCopt) - ((double)HSarAbr))/(((double)LCopt)+((double)HATM));
	VCmin = VCmin*(1. - RoB - (((double)LCopt)+((double)HATM))*NN/(Tc - (((double)LCopt) - ((double)HSarAbr))/OmegaC)/(1.-RoB)/V);
    sprintf(buff2,"\x0d\x0a V LBopt, RoB, LCopt, VCmin:  %lf %lf %lf %lf %lf\x0d\x0a",V, LBopt, RoB, LCopt, VCmin);
    f2.Write(buff2,strlen(buff2));


	double RPG;

	RPG = (VB*(1-DD) + VCmin*(1-DD))/V;

    sprintf(buff2,"\x0d\x0a RPG:  %lf \x0d\x0a", RPG);
    f2.Write(buff2,strlen(buff2));


  }ss




delete NNN;
delete DDD;
delete ZZZ;

f2.Close();

spawnlp(_P_WAIT, "notepad.exe", "notepad.exe", FileName, NULL, NULL);


	// TODO: Add your control notification handler code here
//	OnOK();


}
void Cmw1Dlg::OnBnClickedButton2()
{
	// TODO: Add your control notification handler code here
	OnOK();
}
