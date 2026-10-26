// mw3Dlg.cpp : implementation file
//

#include "stdafx.h"
#include "mw3.h"
#include "mw3Dlg.h"

#include <math.h>
#include <process.h>

#ifdef _DEBUG
#define new DEBUG_NEW
#endif 


// Cmw3Dlg dialog

 long double FF_FUN(double a, long C, double B_ABC);


Cmw3Dlg::Cmw3Dlg(CWnd* pParent /*=NULL*/)
	: CDialog(Cmw3Dlg::IDD, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void Cmw3Dlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_EDIT1, RabPath);
}

BEGIN_MESSAGE_MAP(Cmw3Dlg, CDialog)
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	//}}AFX_MSG_MAP
	ON_BN_CLICKED(IDC_BUTTON1, &Cmw3Dlg::OnBnClickedButton1)
	ON_BN_CLICKED(IDC_BUTTON2, &Cmw3Dlg::OnBnClickedButton2)
END_MESSAGE_MAP()


// Cmw3Dlg message handlers

BOOL Cmw3Dlg::OnInitDialog()
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

void Cmw3Dlg::OnPaint()
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
HCURSOR Cmw3Dlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}


void Cmw3Dlg::OnBnClickedButton1()
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

  int NV, iV;
  double VV[20];



RabPath.GetWindowText(RPath);
FileName = RPath + "\\m3.txt";

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

sprintf(buff2,"\x0d\x0a СРАВНИТЕЛЬНЫЙ АНАЛИЗ ИНФОТЕЛЕКОММУНИКАЦИОННЫХ СИСТЕМ \x0d\x0a\x0d\x0a");
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
  sscanf(c0, "%d", &NV);  //считывание количества скоростей
//  printf("\n количество скоростей NV:      %d", NV);
  sprintf(buff2,"\x0d\x0a количество скоростей NV:      %d", NV);
  f2.Write(buff2,strlen(buff2));
  while(*c0++ != ' ');


  sprintf(buff2,"\x0d\x0a массив скоростей V: \x0d\x0a");
  f2.Write(buff2,strlen(buff2));
  for(i=0; i<NV; i++) {
      while(*c0 == ' ') c0++;
      sscanf(c0, "%le", &VV[i]);  //считывание скорости
      sprintf(buff2," %e  ", VV[i]);
      f2.Write(buff2,strlen(buff2));
      while(*c0++ != ' ');
    }
  sprintf(buff2,"\x0d\x0a \x0d\x0a");
  f2.Write(buff2,strlen(buff2));


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

delete buff;

f1.Close();



sprintf(buff2,"\x0d\x0a\x0d\x0a\x0d\x0a\x0d\x0a шаг 5: \x0d\x0a");
f2.Write(buff2,strlen(buff2));

double Alfa, XX0, XX1;

Alfa = HSarCbr/TauA/VA;

XX0 = sqrt(2./Alfa);
XX1 = 1.1*XX0;
while (fabs((XX0-XX1)/XX0) > 1.E-05) {
       XX0 = XX1;
       XX1 = log(Alfa*XX0+Alfa+1.)/Alfa;
}

sprintf(buff2,"XX1: %lf \x0d\x0a", XX1);
f2.Write(buff2,strlen(buff2));

 long LAopt;

 LAopt = (XX1+1)*HSarCbr;

sprintf(buff2,"\x0d\x0a LAopt: %ld ", LAopt);
f2.Write(buff2,strlen(buff2));


 // цикл по VV
for(iV=0; iV<NV; iV++) {
  V=VV[iV];
  sprintf(buff2,"\x0d\x0a\x0d\x0a\x0d\x0a  Расчет для V = %lf  \x0d\x0a", V);
  f2.Write(buff2,strlen(buff2));
  sprintf(buff2,"_________________________  \x0d\x0a");
  f2.Write(buff2,strlen(buff2));

  sprintf(buff2,"\x0d\x0a шаг 7: \x0d\x0a");
  f2.Write(buff2,strlen(buff2));

  double TettaAmax;
  TettaAmax = ((float)LAopt)*V/((float)LAopt+HATM)/VA;

  sprintf(buff2,"TettaAmax: %lf \x0d\x0a", TettaAmax);
  f2.Write(buff2,strlen(buff2));

  sprintf(buff2,"\x0d\x0a шаг 8 (обращение): \x0d\x0a");
  f2.Write(buff2,strlen(buff2));
  int CC;
  long double FF0, FF1, AA0, AA1, AA2, FF00, AA00;
  double AstAmax;


  if(TettaAmax > 5000.) {
    sprintf(buff2,"Угроза переполнения - вычисления прерываются");
    f2.Write(buff2,strlen(buff2));
    goto CONTINUE;
   }

  CC = (int)TettaAmax;
// B_ABC=0.0001;
  AA0 = 1.5*CC;
  FF0 = FF_FUN(AA0, CC, B_ABC);
  AA1 = 1.01*AA0;
  FF1 = FF_FUN(AA1, CC, B_ABC);

  while(fabs((AA0-AA1)/AA1) > 1.0E-07) {
    AA00 = AA1;
    FF00 = FF1;
    AA1 = AA1+(AA0-AA1)*FF1/(FF1-FF0);
    FF1 = FF_FUN(AA1, CC, B_ABC);
    AA0 = AA00;
    FF0 = FF00;
  }

  FF0=FF1;
  AstAmax = AA1;


  // Проверка
  long double B_ABC_pr, YY;

  B_ABC_pr = 1.;
  YY = 1.;

  for (i=1; i < CC; i++) {
    YY = YY*AstAmax/i;
    B_ABC_pr = B_ABC_pr + YY;
  }

  B_ABC_pr = (YY*AstAmax/CC)/B_ABC_pr;
  YY = fabs((B_ABC-B_ABC_pr)/B_ABC);

  if(YY > 0.05) {
     sprintf(buff2,"/n Не выполнено обращение формулы Эрланга /n");
     f2.Write(buff2,strlen(buff2));
     goto CONTINUE;
  }

  sprintf(buff2,"\x0d\x0a AstAmax = %lf ",AstAmax);
  f2.Write(buff2,strlen(buff2));

 // далее цикл по A
  //шаг 10
  double VAmin, VstE, AcurA, RoC;

  AcurA = AstAmax/10.;
while(AcurA < AstAmax*0.95) {


  VAmin = VA * AcurA;
  VstE = ((float)LAopt-(float)HSarCbr)*V/((float)LAopt+(float)HATM) - VA * AcurA;
  sprintf(buff2,"\x0d\x0a AcurA = %lf, VAmin = %lf, VstE = %lf", AcurA, VAmin, VstE);
  f2.Write(buff2,strlen(buff2));

  // шаг 11
  double A1, G1, R1, HC, Rq, VCAmin;
  int LCAopt;

//  A1 = (HSarAbr + HATM)*VstE/Tc/OmegaC/OmegaC-NN;
  A1 = (NN + VstE/OmegaC) - (NN - VstE/OmegaC)*((float)HSarAbr+(float)HATM)/OmegaC/Tc;
  A1 = A1 - (Tc*VstE - NN*((float)HSarAbr+(float)HATM))/OmegaC/Tc;
  G1 = (NN + VstE/OmegaC)*((float)HSarAbr + (float)HATM);
  R1 = ((float)HSarAbr + (float)HATM)*(Tc*VstE-(float)NN*((float)HSarAbr + (float)HATM));
  LCAopt = (G1+sqrt(G1*G1 + A1*R1))/A1;

//  HC = HSarAbr + HATM;
//  A1 = sqrt(VstE * HC/(Tc*NN*(1-B_ABC)));
//  LCAopt = (int)((A1*Tc*OmegaC-HC)/(A1+1) + HSarAbr);
  sprintf(buff2,"\x0d\x0aLCAopt = %d", LCAopt);
  f2.Write(buff2,strlen(buff2));


  RoC = (Tc-((float)LCAopt-(float)HSarAbr)/OmegaC)*VstE;
  RoC =  (float)NN * ((float)LCAopt+(float)HATM)/RoC;
  RoC = 1. - RoC;
  sprintf(buff2,"\x0d\x0a Ro‘ = %lf", RoC);
  f2.Write(buff2,strlen(buff2));

  VCAmin = ((float)LCAopt-(float)HATM);
  VCAmin = VCAmin/((float)LCAopt+(float)HATM);
  VCAmin = VstE *RoC*(1-P)*VCAmin;
  sprintf(buff2,"\x0d\x0a VCAmin = %lf", VCAmin);
  f2.Write(buff2,strlen(buff2));

  Rq = (VAmin + VCAmin)/V;
  sprintf(buff2,"\x0d\x0a Rq = %lf", Rq);
  f2.Write(buff2,strlen(buff2));

  AcurA = AcurA + AstAmax/10.;

} // конец цикла по AcurA

  CONTINUE: // продолжение после ошибки в цикле по VV
;
} //конец цикла по VV




f2.Close();

spawnlp(_P_WAIT, "notepad.exe", "notepad.exe", FileName, NULL, NULL);


	// TODO: Add your control notification handler code here
//	OnOK();
}


long double FF_FUN(double a, long C, double B_ABC)
{
 int i;
 long double ff, yy;

 if(a==0.) return 1;
 if(C < 2) return -1; // ошибка

 yy = 1.;
 ff = 1.;
 for (i=1; i<C; i++) {
   yy = yy*a/i;
   ff = ff + yy;
  }
 ff = ff + yy*a*(1.-1./B_ABC)/C;

return ff;


}




void Cmw3Dlg::OnBnClickedButton2()
{
	// TODO: Add your control notification handler code here
	OnOK();
}
