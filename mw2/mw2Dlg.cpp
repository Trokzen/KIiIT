// mw2Dlg.cpp : implementation file
//

#include "stdafx.h"
#include "mw2.h"
#include "mw2Dlg.h"

#include <math.h>
#include <process.h>

#ifdef _DEBUG
#define new DEBUG_NEW
#endif 


// Cmw2Dlg dialog




Cmw2Dlg::Cmw2Dlg(CWnd* pParent /*=NULL*/)
	: CDialog(Cmw2Dlg::IDD, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void Cmw2Dlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_EDIT1, RabPath);
}

BEGIN_MESSAGE_MAP(Cmw2Dlg, CDialog)
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	//}}AFX_MSG_MAP
	ON_BN_CLICKED(IDC_BUTTON1, &Cmw2Dlg::OnBnClickedButton1)
	ON_BN_CLICKED(IDC_BUTTON2, &Cmw2Dlg::OnBnClickedButton2)
END_MESSAGE_MAP()


// Cmw2Dlg message handlers

BOOL Cmw2Dlg::OnInitDialog()
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

void Cmw2Dlg::OnPaint()
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
HCURSOR Cmw2Dlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}


void Cmw2Dlg::OnBnClickedButton1()
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


  int NN, HSarVbr, HSarAbr, HATM, HSarCbr;
  double V, AstA, OmegaC, VB, VA, P, DD, Tc, AstB, Tetta, TauA, B_ABC;
  double NuB, Epsilon, DeltaB;

  double AstC, Eps2, DeltaC, VCmin;


RabPath.GetWindowText(RPath);
FileName = RPath + "\\m2.txt";

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

sprintf(buff2,"\x0d\x0a АНАЛИЗ ОДНОРОДНОЙ ГИБРИДНОЙ ИНФОТЕЛЕКОММУНИКАЦИОННОЙ СИСТЕМЫ \x0d\x0a\x0d\x0a");
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
  sscanf(c0, "%d", &HSarCbr);  //считывание HSarCbr
//  printf("\n HSarCbr:      %d", HSarCbr);
  sprintf(buff2,"\x0d\x0a HSarCbr:      %d", HSarCbr);
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
  sscanf(c0, "%lf", &VA);  //считывание vA
  sprintf(buff2,"\x0d\x0a VA:      %f", VA);
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
  sscanf(c0, "%lf", &TauA);  //считывание TauA
  sprintf(buff2,"\x0d\x0a TauA:      %lf", TauA);
  f2.Write(buff2,strlen(buff2));
  while(*c0++ != ' ');

  while(*c0 == ' ') c0++;
  sscanf(c0, "%lf", &B_ABC);  //считывание B_ABC
  sprintf(buff2,"\x0d\x0a B_ABC:      %lf", B_ABC);
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

/*
 // считываем таблицу для определения Z
 int iZ, jZ;   // - размерность таблицы
  while (*c0 == ' ') c0++;
  sscanf(c0, "%d", &iZ);
  while(*c0++ != ' ');
  while(*c0 == ' ') c0++;
  sscanf(c0, "%d", &jZ);
  sprintf(buff2,"\n\n\n Размер таблицы для определения Z: %d x %d", iZ, jZ);
  f2.Write(buff2,strlen(buff2));
  while(*c0++ != ' ');

  double *DDD, *ZZZ;
  int *NNN;
  NNN = new int[sizeof(int)*iZ];
  DDD = new double[sizeof(double)*jZ];
  ZZZ = new double[sizeof(double)*iZ*jZ];
  sprintf(buff2,"\n NNN : \n");
  f2.Write(buff2,strlen(buff2));
  for(i=0; i<iZ; i++) {
        while (*c0 == ' ') c0++;
        sscanf(c0, "%d", NNN+i);
        while(*c0++ != ' ');
        sprintf(buff2,"  %d ", *(NNN+i));
        f2.Write(buff2,strlen(buff2));
   }
  sprintf(buff2,"\n DDD : \n");
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
  sprintf(buff2,"\n ZZZ : \n");
  f2.Write(buff2,strlen(buff2));
  for(j=0; j<jZ; j++) {
    for(i=0; i<iZ; i++) {
        sprintf(buff2,"  %lf ",  *(ZZZ+i+j*iZ));
        f2.Write(buff2,strlen(buff2));
     }
    sprintf(buff2,"\n ");
    f2.Write(buff2,strlen(buff2));
  }
*/
delete buff;

f1.Close();


// шаг 1
//  double ZZ, VBst;
//  int Napr;
//  Napr=1;


    // определяем TettaA
 int MM;
 double BA;

 sprintf(buff2,"\x0d\x0a Шаг 1: \x0d\x0a");
 f2.Write(buff2,strlen(buff2));

 BA=1;
 MM=0;
 while(BA - B_ABC > 0) {
  MM=MM+1;
  BA = AstA*BA/(MM+AstA*BA);

  }

 sprintf(buff2," MM, BA: %d %lf\x0d\x0a", MM, BA);
 f2.Write(buff2,strlen(buff2));


 sprintf(buff2,"\x0d\x0a Шаг 2: \x0d\x0a");
 f2.Write(buff2,strlen(buff2));

 double Alfa, XX0, XX;

 Alfa = ((double)HSarCbr)/TauA/VA;

 XX0 = sqrt(2./Alfa);
 XX = 1.1*XX0;
 while (fabs((XX0-XX)/XX0) > 1.E-05) {
	XX0 = XX;
	XX = log(Alfa*XX0+Alfa+1.)/Alfa;
 }
 sprintf(buff2,"XX: %lf \x0d\x0a", XX);
 f2.Write(buff2,strlen(buff2));
 
 long LAopt;

 LAopt = (XX+1)*HSarCbr;

 sprintf(buff2,"LAopt: %ld \x0d\x0a", LAopt);
 f2.Write(buff2,strlen(buff2));


 V = exp((-(double)LAopt+(double)HSarCbr)/VA/TauA);
 V = VA*TauA*(1.-V);
 V = V*VA*MM/(LAopt+HATM);

 sprintf(buff2,"V: %lf \x0d\x0a", V);
 f2.Write(buff2,strlen(buff2));


 double VstE;

 // Шаг 3
 sprintf(buff2,"\x0d\x0a Шаг 3: \x0d\x0a");
 f2.Write(buff2,strlen(buff2));

VstE = ((double)LAopt-(double)HSarCbr)*V/((double)LAopt-(double)HATM) - VA*AstA*(1.-B_ABC);
if(VstE < 0) {
   sprintf(buff2,"\x0d\x0a  VstE меньше нуля \x0d\x0a");
   f2.Write(buff2,strlen(buff2));
   exit(-1);
}
sprintf(buff2,"VstE: %lf \x0d\x0a", VstE);
f2.Write(buff2,strlen(buff2));

 // Шаг 4
 double GC, RC, AC;
double LCopt1, LCopt2, LCopt;

/* AC = ((double)HSarAbr+(double)HATM)*VstE/OmegaC/OmegaC/Tc;
 AC = AC - NN;
 GC = (NN+VstE/OmegaC)*((double)HSarAbr+(double)HATM);
 RC = ((double)HSarAbr+(double)HATM)*(Tc*VstE-NN*((double)HSarAbr+(double)HATM));
*/
  AC = (NN + VstE/OmegaC) - (NN - VstE/OmegaC)*((float)HSarAbr+(float)HATM)/OmegaC/Tc;
  AC = AC - (Tc*VstE - NN*((float)HSarAbr+(float)HATM))/OmegaC/Tc;
  GC = (NN + VstE/OmegaC)*((float)HSarAbr + (float)HATM);
  RC = ((float)HSarAbr + (float)HATM)*(Tc*VstE-(float)NN*((float)HSarAbr + (float)HATM));

  sprintf(buff2,"\x0d\x0a AC,RC,GC: %lf, %lf, %lf \x0d\x0a", AC, RC, GC);
  f2.Write(buff2,strlen(buff2));


 LCopt1 = (GC+sqrt(GC*GC+AC*RC))/AC;
 LCopt2 = (GC-sqrt(GC*GC+AC*RC))/AC;
 if(LCopt1>LCopt2)
	LCopt=LCopt1;
     else
	LCopt=LCopt2;
 sprintf(buff2,"LCopt1, LCopt2, LCopt : %lf %lf %lf \x0d\x0a", LCopt1, LCopt2,  LCopt);
 f2.Write(buff2,strlen(buff2));

 if(LCopt < 0) {
   sprintf(buff2,"\x0d\x0a LCopt меньше нуля \x0d\x0a");
   f2.Write(buff2,strlen(buff2));
   exit(-1);
 }


 // Шаг 5
 sprintf(buff2,"\x0d\x0a Шаг: \x0d\x0a");
 f2.Write(buff2,strlen(buff2));



 VCmin = VstE*((double)LCopt - (double)HSarAbr)/((double)LCopt + (double)HATM);
 VCmin = VCmin*(1-NN*((double)LCopt + (double)HATM)/VstE/(Tc-((double)LCopt - (double)HSarAbr)/OmegaC));
 sprintf(buff2,"VCmin: %lf \x0d\x0a", VCmin);
 f2.Write(buff2,strlen(buff2));

 while (AstC * 64000. >= VCmin || fabs(AstC*64000. - VCmin) >= Eps2) {
    sprintf(buff2,"\x0d\x0a Шаг 10 -  Пересчет VstE, LCopt, VCmin: \x0d\x0a");
    f2.Write(buff2,strlen(buff2));

	if((AstC * 64000. > VCmin && DeltaC < 0.) || (AstC*64000. < VCmin && DeltaC > 0.))
		DeltaC = -DeltaC/2.;
	V = V +DeltaC;
    sprintf(buff2,"V, DeltaC: %lf %lf \x0d\x0a", V, DeltaC);
    f2.Write(buff2,strlen(buff2));

	VstE = ((double)LAopt-(double)HSarCbr)*V/((double)LAopt-(double)HATM) - VA*AstA;
	if(VstE < 0) {
       sprintf(buff2,"\x0d\x0a VstE меньше нуля \x0d\x0a");
       f2.Write(buff2,strlen(buff2));
	   exit(-1);
	 }
    sprintf(buff2,"VstE: %lf \x0d\x0a", VstE);
    f2.Write(buff2,strlen(buff2));


/*	AC = ((double)HSarAbr+(double)HATM)*VstE/OmegaC/OmegaC/Tc - NN;
	GC = (NN+VstE/OmegaC)*((double)HSarAbr+(double)HATM);
	RC = ((double)HSarAbr+(double)HATM)*(Tc*VstE-NN*((double)HSarAbr+(double)HATM));
*/

  AC = (NN + VstE/OmegaC) - (NN - VstE/OmegaC)*((float)HSarAbr+(float)HATM)/OmegaC/Tc;
  AC = AC - (Tc*VstE - NN*((float)HSarAbr+(float)HATM))/OmegaC/Tc;
  GC = (NN + VstE/OmegaC)*((float)HSarAbr + (float)HATM);
  RC = ((float)HSarAbr + (float)HATM)*(Tc*VstE-(float)NN*((float)HSarAbr + (float)HATM));
  sprintf(buff2,"\x0d\x0a AC,RC,GC: %lf, %lf, %lf \x0d\x0a", AC, RC, GC);
  f2.Write(buff2,strlen(buff2));

	LCopt1 = (GC+sqrt(GC*GC+AC*RC))/AC;
	LCopt2 = (GC-sqrt(GC*GC+AC*RC))/AC;
	if(LCopt1>LCopt2)
		LCopt=LCopt1;
	   else
		LCopt=LCopt2;
    sprintf(buff2,"LCopt1, LCopt2, LCopt : %lf %lf %lf \x0d\x0a", LCopt1, LCopt2,  LCopt);
    f2.Write(buff2,strlen(buff2));

	if(LCopt < 0) {
      sprintf(buff2,"\x0d\x0a LCopt меньше нуля \x0d\x0a");
      f2.Write(buff2,strlen(buff2));
	  exit(-1);
	}

	VCmin = VstE*((double)LCopt - (double)HSarAbr)/((double)LCopt + (double)HATM);
	VCmin = VCmin*(1-NN*((double)LCopt + (double)HATM)/VstE/(Tc-((double)LCopt - (double)HSarAbr)/OmegaC));
    sprintf(buff2,"VCmin: %lf \x0d\x0a", VCmin);
    f2.Write(buff2,strlen(buff2));
 } //конец while


/*
delete NNN;
delete DDD;
delete ZZZ;
*/

f2.Close();

spawnlp(_P_WAIT, "notepad.exe", "notepad.exe", FileName, NULL, NULL);
//spawnlp(_P_WAIT, "winword.exe", "winword.exe", FileName, NULL, NULL);


	// TODO: Add your control notification handler code here
//	OnOK();


}
void Cmw2Dlg::OnBnClickedButton2()
{
	// TODO: Add your control notification handler code here
	OnOK();
}
