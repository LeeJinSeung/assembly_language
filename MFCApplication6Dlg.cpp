
#include "stdafx.h"
#include "MFCApplication6.h"
#include "MFCApplication6Dlg.h"
#include "afxdialogex.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

bool eflag = true;
bool dflag = false;

int p_count = 0;
wchar_t op_Arr[100];
double num_Arr[100];

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_ABOUTBOX };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);  

protected:
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialogEx(IDD_ABOUTBOX)
{
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialogEx)
END_MESSAGE_MAP()

CMFCApplication6Dlg::CMFCApplication6Dlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(IDD_MFCAPPLICATION6_DIALOG, pParent)
	, m_input(_T(""))
	, m_temp(_T(""))
	, m_op(_T(""))
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CMFCApplication6Dlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT1, m_input);
	DDX_Text(pDX, IDC_EDIT2, m_temp);
	DDX_Text(pDX, IDC_EDIT3, m_op);
}

BEGIN_MESSAGE_MAP(CMFCApplication6Dlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_BUTTON1, &CMFCApplication6Dlg::OnBnClickedButton1)
	ON_BN_CLICKED(IDC_BUTTON2, &CMFCApplication6Dlg::OnBnClickedButton2)
	ON_BN_CLICKED(IDC_BUTTON3, &CMFCApplication6Dlg::OnBnClickedButton3)
	ON_BN_CLICKED(IDC_BUTTON4, &CMFCApplication6Dlg::OnBnClickedButton4)
	ON_BN_CLICKED(IDC_BUTTON5, &CMFCApplication6Dlg::OnBnClickedButton5)
	ON_BN_CLICKED(IDC_BUTTON6, &CMFCApplication6Dlg::OnBnClickedButton6)
	ON_BN_CLICKED(IDC_BUTTON7, &CMFCApplication6Dlg::OnBnClickedButton7)
	ON_BN_CLICKED(IDC_BUTTON8, &CMFCApplication6Dlg::OnBnClickedButton8)
	ON_BN_CLICKED(IDC_BUTTON9, &CMFCApplication6Dlg::OnBnClickedButton9)
	ON_BN_CLICKED(IDC_BUTTON0, &CMFCApplication6Dlg::OnBnClickedButton0)
	ON_BN_CLICKED(IDC_BUTTON_ADD, &CMFCApplication6Dlg::OnBnClickedButtonAdd)
	ON_BN_CLICKED(IDC_BUTTON_EQU, &CMFCApplication6Dlg::OnBnClickedButtonEqu)
	ON_BN_CLICKED(IDC_BUTTON_DOT, &CMFCApplication6Dlg::OnBnClickedButtonDot)
	ON_BN_CLICKED(IDC_BUTTON_C, &CMFCApplication6Dlg::OnBnClickedButtonC)
	ON_BN_CLICKED(IDC_BUTTON_DEL, &CMFCApplication6Dlg::OnBnClickedButtonDel)
	ON_BN_CLICKED(IDC_BUTTON_ROOT, &CMFCApplication6Dlg::OnBnClickedButtonRoot)
	ON_BN_CLICKED(IDC_BUTTON_SQU, &CMFCApplication6Dlg::OnBnClickedButtonSqu)
	ON_BN_CLICKED(IDC_BUTTON_POW, &CMFCApplication6Dlg::OnBnClickedButtonPow)
	ON_BN_CLICKED(IDC_BUTTON_SUB, &CMFCApplication6Dlg::OnBnClickedButtonSub)
	ON_BN_CLICKED(IDC_BUTTON_MUL, &CMFCApplication6Dlg::OnBnClickedButtonMul)
	ON_BN_CLICKED(IDC_BUTTON_DIV, &CMFCApplication6Dlg::OnBnClickedButtonDiv)
	ON_BN_CLICKED(IDC_BUTTON_MOD, &CMFCApplication6Dlg::OnBnClickedButtonMod)
	ON_BN_CLICKED(IDC_BUTTON_LP, &CMFCApplication6Dlg::OnBnClickedButtonLp)
	ON_BN_CLICKED(IDC_BUTTON_RP, &CMFCApplication6Dlg::OnBnClickedButtonRp)
	ON_WM_CTLCOLOR()
	ON_WM_DRAWITEM()
END_MESSAGE_MAP()


BOOL CMFCApplication6Dlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);
	SetBackgroundColor(RGB(255, 215, 0));
	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != NULL)
	{
		BOOL bNameValid;
		CString strAboutMenu;
		bNameValid = strAboutMenu.LoadString(IDS_ABOUTBOX);
		ASSERT(bNameValid);
		if (!strAboutMenu.IsEmpty())
		{
			pSysMenu->AppendMenu(MF_SEPARATOR);
			pSysMenu->AppendMenu(MF_STRING, IDM_ABOUTBOX, strAboutMenu);
		}
	}
	SetIcon(m_hIcon, TRUE);		
	SetIcon(m_hIcon, FALSE);	


	return TRUE; 
}

void CMFCApplication6Dlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	if ((nID & 0xFFF0) == IDM_ABOUTBOX)
	{
		CAboutDlg dlgAbout;
		dlgAbout.DoModal();
	}
	else
	{
		CDialogEx::OnSysCommand(nID, lParam);
	}
}

void CMFCApplication6Dlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); 
		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}
}

HCURSOR CMFCApplication6Dlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}

HBRUSH CMFCApplication6Dlg::OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor)
{
	HBRUSH hbr = CDialogEx::OnCtlColor(pDC, pWnd, nCtlColor);
	return hbr;
}
/*********************************************
	   공학용 계산기 버튼 기능 구현하기
**********************************************/

//숫자버튼 1
void CMFCApplication6Dlg::OnBnClickedButton1()
{
	if (eflag == true)
		m_input = "";
	eflag = false;
	m_input.AppendChar('1');
	UpdateData(false);
}

//숫자버튼 2
void CMFCApplication6Dlg::OnBnClickedButton2()
{
	if (eflag == true)
		m_input = "";
	eflag = false;
	m_input.AppendChar('2');
	UpdateData(false);
}

//숫자버튼 3
void CMFCApplication6Dlg::OnBnClickedButton3()
{
	if (eflag == true)
		m_input = "";
	eflag = false;
	m_input.AppendChar('3');
	UpdateData(false);
}

//숫자버튼 4
void CMFCApplication6Dlg::OnBnClickedButton4()
{
	if (eflag == true)
		m_input = "";
	eflag = false;
	m_input.AppendChar('4');
	UpdateData(false);
}

//숫자버튼 5
void CMFCApplication6Dlg::OnBnClickedButton5()
{
	if (eflag == true)
		m_input = "";
	eflag = false;
	m_input.AppendChar('5');
	UpdateData(false);
}

//숫자버튼 6
void CMFCApplication6Dlg::OnBnClickedButton6()
{
	if (eflag == true)
		m_input = "";
	eflag = false;
	m_input.AppendChar('6');
	UpdateData(false);
}

//숫자버튼 7
void CMFCApplication6Dlg::OnBnClickedButton7()
{
	if (eflag == true)
		m_input = "";
	eflag = false;
	m_input.AppendChar('7');
	UpdateData(false);
}

//숫자버튼 8
void CMFCApplication6Dlg::OnBnClickedButton8()
{
	if (eflag == true)
		m_input = "";
	eflag = false;
	m_input.AppendChar('8');
	UpdateData(false);
}

//숫자버튼 9
void CMFCApplication6Dlg::OnBnClickedButton9()
{
	if (eflag == true)
		m_input = "";
	eflag = false;
	m_input.AppendChar('9');
	UpdateData(false);
}

//숫자버튼 0
void CMFCApplication6Dlg::OnBnClickedButton0()
{
	if (eflag == true)
		m_input = "0";
	eflag = false;
	m_input.AppendChar('0');
	UpdateData(false);
}

//소수점
void CMFCApplication6Dlg::OnBnClickedButtonDot()
{
	if (!dflag)
		m_input.AppendChar('.');
	dflag = true;
	UpdateData(false);
}

// Clear
void CMFCApplication6Dlg::OnBnClickedButtonC()
{
	m_input = "";
	m_op = "";
	m_temp = "";
	eflag = true;
	dflag = false;
	UpdateData(false);
}

// 1글자 지우기
void CMFCApplication6Dlg::OnBnClickedButtonDel()
{
	char buf[100];
	wcstombs(buf, m_input, 100);
	int len = strlen(buf);
	if (len > 0) {
		if (m_input.GetAt(len - 1) == '.') {
			dflag = false;
		}
		m_input.Delete(len - 1, 1);
	}
	UpdateData(false);
}

/***********************************************
         이하 어셈블리어 구현 필수
************************************************/

//왼쪽 괄호
void CMFCApplication6Dlg::OnBnClickedButtonLp()
{
	if (eflag == true)
		m_input = "";
	eflag = false;
	m_input.AppendChar('(');

	char vchar[100];
	wcstombs(vchar, m_temp, 100);

	for (int i = 0; i < 100; ++i) {
		if (vchar[i] == '(')
			vchar[i] = '0';
		else
			break;
	}

	double fval = atof(vchar);	//입력된 실수
	wchar_t op = m_op.GetAt(0);
	


	__asm{
		mov esi, p_count		// p_count를 esi에 넣는다.
		imul esi,8				// esi에 8을 곱한다.
		fld fval				// fval을 st(0)에 넣는다.
		fstp num_Arr[esi]		// st(0)에 있는 값을 num_Arr[esi]에 저장하고 pop을 한다.
		
		mov esi, p_count		// p_count를 esi에 넣는다.
		imul esi, 2				// esi에 2를 곱한다.
		mov ax, op				// ax에 op를 넣는다.(op가 2바이트이기 때문)
		cmp ax,0				// 0과 비교를 한다.(op가 아무것도 없으면 0)
		jne L1					// op가 있다면 L1으로
		mov op_Arr[esi], '+'	// op가 없다면 op_Arr[esi]에 '+'를 넣는다
		jmp L2					// L2로 이동
		L1: mov op_Arr[esi], ax // op가 있는경우이므로 op_Arr[esi]에 ax를 넣는다. 즉 op값이 들어가게 된다.
		L2: 

	}

	m_temp = "";				// num_Arr으로 값을 넣고 m_temp는 초기화
	m_op = "";					// op_Arr으로 값을 넣고 m_op는 초기화
	p_count++;					
	UpdateData(false);
}

//오른쪽 괄호
void CMFCApplication6Dlg::OnBnClickedButtonRp()
{
	if (eflag == true)
		m_input = "";
	eflag = false;
	m_input.AppendChar(')');

	if (m_op != "") {				// m_op에 수식이 있다면 식을 계산을 한다.
		double res = calc();
		char rval[100];
		sprintf(rval, "%lf", res);
		m_input = rval;
	}

	double fval;					// num_Arr에 담긴 값을 가져올 변수
	wchar_t op;						// op_Arr에 담긴 값을 가져올 변수
	p_count--;
	
	__asm{
		mov esi, p_count			// esi에 p_count를 넣는다
		imul esi, 8					// esi에 8을 곱한다
		fld num_Arr[esi]			// num_Arr[esi]를 st(0)에 넣는다.
		fstp fval					// st(0)의 값을 fval에 저장하고 pop한다.

		mov esi, p_count			// esi에 p_count를 넣는다
		imul esi, 2					// esi에 2를 곱한다.
		mov ax, op_Arr[esi]			// ax에 op_Arr[esi]를 넣는다.
		mov op, ax					// op에 ax를 넣는다.

	}
	

	char rval[100];
	sprintf(rval, "%lf", fval);
	m_temp = rval;
	m_op = op;

	UpdateData(false);
}

/*************
1항연산자
**************/
//제곱근
void CMFCApplication6Dlg::OnBnClickedButtonRoot()
{
	char vchar[100];
	wcstombs(vchar, m_input, 100);

	for (int i = 0; i < 100; ++i) {
		if (vchar[i] == '(')
			vchar[i] = '0';
		else
			break;
	}

	double fval = atof(vchar);	//입력된 실수
	double res = 0;				//출력할 결과\



	__asm {
		fld fval				// fval을 st(0)에 넣는다.
		fsqrt					// st(0)의 값에 루트를 씌워서 저장한다.
		fstp res				// st(0)에 있는 값을 res에 저장하고 pop을 한다. 
	}



	char rval[100];
	sprintf(rval, "%lf", res);
	m_input = rval;				//결과 출력

	eflag = true;
	dflag = false;

	UpdateData(false);
}

//2제곱
void CMFCApplication6Dlg::OnBnClickedButtonSqu()
{
	char vchar[100];
	wcstombs(vchar, m_input, 100);

	for (int i = 0; i < 100; ++i) {
		if (vchar[i] == '(')
			vchar[i] = '0';
		else
			break;
	}

	double fval = atof(vchar);	//입력된 실수
	double res = 0;				//출력할 결과


	__asm {
		fld fval				// fval을 st(0)에 넣는다.
		fmul st(0), st(0)		// st(0) * st(0)을 하여 st(0)에 저장한다.
		fstp res				// st(0)에 있는 값을 res에 저장하고 pop을 한다.
	}


	char rval[100];
	sprintf(rval, "%lf", res);
	m_input = rval;				//결과 출력

	eflag = true;
	dflag = false;

	UpdateData(false);
}


/*************
2항연산자
**************/
//덧셈 연산자 입력
void CMFCApplication6Dlg::OnBnClickedButtonAdd()
{
	if (m_op != "") {
		double res = calc();
		char rval[100];
		sprintf(rval, "%lf", res);
		m_temp = rval;
	}
	else m_temp = m_input;
	m_op = '+';
	m_input = "";
	dflag = false;
	UpdateData(false);
}
//뺄셈 연산자 입력
void CMFCApplication6Dlg::OnBnClickedButtonSub()
{
	if (m_op != "") {
		double res = calc();
		char rval[100];
		sprintf(rval, "%lf", res);
		m_temp = rval;
	}
	else m_temp = m_input;
	m_op = '-';
	m_input = "";
	dflag = false;
	UpdateData(false);
}
//곱셈 연산자 입력
void CMFCApplication6Dlg::OnBnClickedButtonMul()
{
	if (m_op != "") {
		double res = calc();
		char rval[100];
		sprintf(rval, "%lf", res);
		m_temp = rval;
	}
	else m_temp = m_input;
	m_op = '*';
	m_input = "";
	dflag = false;
	UpdateData(false);
}
//나눗셈 연산자 입력
void CMFCApplication6Dlg::OnBnClickedButtonDiv()
{
	if (m_op != "") {
		double res = calc();
		char rval[100];
		sprintf(rval, "%lf", res);
		m_temp = rval;
	}
	else m_temp = m_input;
	m_op = '/';
	m_input = "";
	dflag = false;
	UpdateData(false);
}
//Mod 연산자 입력
void CMFCApplication6Dlg::OnBnClickedButtonMod()
{
	if (m_op != "") {
		double res = calc();
		char rval[100];
		sprintf(rval, "%lf", res);
		m_temp = rval;
	}
	else m_temp = m_input;
	m_op = '%';
	m_input = "";
	dflag = false;
	UpdateData(false);
}
//n제곱 연산자 입력
void CMFCApplication6Dlg::OnBnClickedButtonPow()
{
	if (m_op != "") {
		double res = calc();
		char rval[100];
		sprintf(rval, "%lf", res);
		m_temp = rval;
	}
	else m_temp = m_input;
	m_op = '^';
	m_input = "";
	dflag = false;
	UpdateData(false);
}
/**********
계산
***********/
double CMFCApplication6Dlg::calc()
{
	char vchar1[100], vchar2[100];
	wcstombs(vchar1, m_temp, 100);
	wcstombs(vchar2, m_input, 100);
	
	for (int i = 0; i < 100; ++i) {
		if (vchar1[i] == '(')
			vchar1[i] = '0';
		else
			break;
	}
	double fval1 = atof(vchar1);	//m_temp에 입력되어 있는 실수
	double fval2 = atof(vchar2);	//m_input에 입력되어 있는 실수
	double round = 0.4999999;		// 반올림에 사용하는 실수변수(% 계산)
	double inc = 1;
	double res = 0;					//출력할 결과
									//m_op에 입력되어 있는 값에 따라 연산
	switch (m_op.GetAt(0)) {
	case '+':
		//c++
		//res = fval1 + fval2;

		//inline assembly
		__asm {
			fld fval1				// fval1을 st(0)에 넣는다.
			fld fval2				// fval2을 st(0)에 넣는다. st(0)에 있던 fval1은 st(1)로 이동한다.
			fadd					// st(0)이랑 st(1) 값이랑 더해서 st(0)에 값을 저장한다.
			fstp res				// st(0)에 있는 값을 res에 저장하고 pop을 한다.
		}
		break;
	case '-':

		__asm {
			fld fval1				// fval1을 st(0)에 넣는다
			fld fval2				// fval2을 st(0)에 넣는다. st(0)에 있던 fval1은 st(1)로 이동한다.
			fsub					// st(0)이랑 st(1) 값이랑 빼서 st(1)에 값을 저장하고 st(0)는 pop이 되서 st(1)에 있던게 st(0)로 이동한다.
			fstp res				// st(0)에 있는 값을 res에 저장하고 pop을 한다.
		}

		break;
	case '*':

		__asm {
			fld fval1				// fval1을 st(0)에 넣는다
			fld fval2				// fval2을 st(0)에 넣는다. st(0)에 있던 fval1은 st(1)로 이동한다.
			fmul					// st(1) * st(0)를 하고 st(1)에 저장하고 st(0)는 pop 즉 st(0)에 두개의 곱이 저장이 된다.
			fstp res				// st(0)에 있는 값을 res에 저장하고 pop을 한다.
		}

		break;
	case '/':

		__asm {
			fld fval1				// fval1을 st(0)에 넣는다.
			fld fval2				// fval2을 st(0)에 넣는다. st(0)에 있던 fval1은 st(1)로 이동한다.
			fdiv					// st(1) / st(0)를 하고 st(1)에 저장하고 st(0)는 pop 즉 결과값이 st(0)에 저장이 된다.
			fstp res				// st(0)에 있는 값을 res에 저장하고 pop을 한다.
		}

		break;
	case '%':

		__asm {
			fld fval1				// fval1을 st(0)에 넣는다.
			fabs					// st(0)의 값에 절댓값을 취한다.
			fld st(0)				// st(0)를 복사해서 st(0)에 넣는다. 즉 동일한 값이 st(0),st(1)에 들어가 있다.
			fld fval2				// fval2을 st(0)에 넣는다. st(0), st(1)에 있던 값들은 각각 st(1),st(2)로 이동한다.
			fabs					// st(0)의 값에 절댓값을 취한다.
			fdiv					// st(1) / st(0)를 하고 st(1)에 저장하고 st(0)는 pop 즉 결과값이 st(0)에 저장이 된다.
			fld round				// round(반올림을 위해)를 st(0)에 넣는다.
			fsub					// st(1) - st(0)를 하고 st(1)에 저장하고 st(0)는 pop 즉 결과값이 st(0)에 저장이 된다.
			frndint					// st(0)에 있는 값을 반올림한다.
			fld fval2				// fval2을 st(0)에 넣고 st(0),st(1)에 있는 값을 각각 st(1),st(2)로 이동한다.
			fabs					// st(0)에 절댓값을 취한다
			fmul					// st(1) * st(0)를 하고 st(1)에 저장하고 st(0)는 pop 즉 결과값이 st(0)에 저장이 된다.
			fsub					// st(1) - st(0)를 하고 st(1)에 저장하고 st(0)는 pop 즉 결과값이 st(0)에 저장이 된다.
			fld fval1				// fval1을 st(0)에 넣는다.
			fcomip st(0), st(1)     // st(0)와 st(1)의 값을 비교하고 st(0)를 pop한다.
			jae L1					// st(0)값과 st(1)값을 비교하고 st(0)>=st(1)이면 L1으로 점프
			fld res					// st(0)에 0를 넣어준다.
			fcomip st(0),st(1)		// st(0) 즉 0이랑 st(1)의 값을 비교하고 st(0)를 pop한다
			jz L1					// zf=1이면 L1으로 점프
			fld fval2				// st(0)<st(1)일 때 fval2를 st(0)에 넣는다.
			fabs
			fxch					// st(0)와 st(1)를 서로 바꾼다.
			fsub					// st(1) / st(0)를 하고 st(1)에 저장하고 st(0)는 pop 즉 결과값이 st(0)에 저장이 된다.
			L1 :
			fstp res				// st(0)에 있는 값을 res에 저장하고 pop을 한다.
		}

		break;

	case '^':				

		__asm {
			fld fval2				// fval2을 st(0)에 넣는다.
			fld fval1				// fval1을 st(0)에 넣는다. st(0)에 있던 fval1은 st(1)로 이동한다.
			fyl2x					// st(1) * log(st(0))
			fld st(0)				// st(0)의 값을 st(0)에 넣는다. st(0)에 있던 값은 st(1)으로 이동한다.
			fld inc					// inc를 st(0)에 넣는다.
			fscale					// st(1) * 2^floor(st(0))
			fld inc					// st(0)에 inc를 넣는다
			fxch					// st(0)과 st(1)의 값을 바꾼다.
			fyl2x					// st(1) * log(st(0))를 하고 st(1)에 저장하고 st(0)는 pop 즉 결과값이 st(0)에 저장된다.
			fsub					// st(1) - st(0)를 하고 st(1)에 저장하고 st(0)는 pop 즉 결과값이 st(0)에 저장이 된다.
			f2xm1					// 2^st(0)-1를 하고 st(0)에 저장한다. 이때 –1<=st(0)<1일 때만 사용 가능하다.
			fld inc					// st(0) inc를 넣는다.st(0),st(1)이 각각 st(1),st(2)로 이동한다.
			fadd					// st(1) + st(0)를 하고 st(1)에 저장하고 st(0)는 pop 즉 결과값이 st(0)에 저장이 된다.
			fscale					// st(0) * 2^floor(st(1))를 하고 st(0)에 저장한다.
			fstp st(1)				// st(1)에 있는 값을 pop을 한다.(필요없는 값이다.)
			fstp res				// st(0)에 있는 값을 res에 저장하고 pop을 한다.
		}

		break;
	default:
		res = fval2;
		break;
	}
	return res;
}
//등호 버튼
void CMFCApplication6Dlg::OnBnClickedButtonEqu()
{
	for (int i = 0; i < p_count; ++i) {
		OnBnClickedButtonRp();
	}

	double res = calc();
	char rval[100];
	sprintf(rval, "%lf", res);
	m_input = rval;

	m_temp = "";
	m_op = "";
	eflag = true;
	dflag = false;

	UpdateData(false);
}


void setBtnColor(CDC  *dc, RECT rect, COLORREF color) {
	dc->FillSolidRect(&rect, color);
	dc->SetBkColor(color);
}

void CMFCApplication6Dlg::OnDrawItem(int nIDCtl, LPDRAWITEMSTRUCT lpDrawItemStruct)
{
#define green RGB(0,200,0)
#define red RGB(200,0,0)
#define pink RGB(255,153,204)
	CDC dc;
	RECT rect;
	dc.Attach(lpDrawItemStruct->hDC);   
	dc.Draw3dRect(&rect, RGB(255, 255, 255), RGB(0, 0, 0));
	dc.FillSolidRect(&rect, RGB(51, 51, 51));
	rect = lpDrawItemStruct->rcItem;  

	if (nIDCtl == IDC_BUTTON0)
	{
		setBtnColor(&dc, rect, pink);
	}
	if (nIDCtl == IDC_BUTTON1)		
	{
		setBtnColor(&dc, rect, pink);	
	}
	if (nIDCtl == IDC_BUTTON2)
	{
		setBtnColor(&dc, rect, pink);
	}
	if (nIDCtl == IDC_BUTTON3)
	{
		setBtnColor(&dc, rect, pink);
	}
	if (nIDCtl == IDC_BUTTON4)
	{
		setBtnColor(&dc, rect, pink);
	}
	if (nIDCtl == IDC_BUTTON5)
	{
		setBtnColor(&dc, rect, pink);
	}
	if (nIDCtl == IDC_BUTTON6)
	{
		setBtnColor(&dc, rect, pink);
	}
	if (nIDCtl == IDC_BUTTON7)
	{
		setBtnColor(&dc, rect, pink);
	}
	if (nIDCtl == IDC_BUTTON8)
	{
		setBtnColor(&dc, rect, pink);
	}
	if (nIDCtl == IDC_BUTTON9)
	{
		setBtnColor(&dc, rect, pink);
	}
	if (nIDCtl == IDC_BUTTON_EQU)
	{
		setBtnColor(&dc, rect, pink);
	}
	if (nIDCtl == IDC_BUTTON_DOT)
	{
		setBtnColor(&dc, rect, pink);
	}
	if (nIDCtl == IDC_BUTTON_C)
	{
		setBtnColor(&dc, rect, pink);
	}
	if (nIDCtl == IDC_BUTTON_DEL)
	{
		setBtnColor(&dc, rect, pink);
	}

	if (nIDCtl == IDC_BUTTON_ADD)		//덧셈
	{
		setBtnColor(&dc, rect, green);	//구현 완료 : green, 미구현 :red
	}
	if (nIDCtl == IDC_BUTTON_SUB)		//뺄셈
	{
		setBtnColor(&dc, rect, green);
	}
	if (nIDCtl == IDC_BUTTON_MUL)		//곱셈
	{
		setBtnColor(&dc, rect, green);
	}	
	if (nIDCtl == IDC_BUTTON_DIV)		//나눗셈
	{
		setBtnColor(&dc, rect, green);
	}
	if (nIDCtl == IDC_BUTTON_MOD)		//MOD
	{
		setBtnColor(&dc, rect, green);
	}
	if (nIDCtl == IDC_BUTTON_ROOT)		//제곱근
	{
		setBtnColor(&dc, rect, green);
	}
	if (nIDCtl == IDC_BUTTON_SQU)		//2제곱
	{
		setBtnColor(&dc, rect, green);
	}
	if (nIDCtl == IDC_BUTTON_POW)		//n제곱
	{
		setBtnColor(&dc, rect, green);
	}
	if (nIDCtl == IDC_BUTTON_LP)		//왼쪽괄호
	{
		setBtnColor(&dc, rect, green);
	}
	if (nIDCtl == IDC_BUTTON_RP)		//오른쪽괄호
	{
		setBtnColor(&dc, rect, green);
	}
	dc.SetTextColor(RGB(000, 255, 255)); 
	
	UINT state = lpDrawItemStruct->itemState;  //This defines the state of the Push button either pressed or not. 
	if ((state & ODS_SELECTED))
		dc.DrawEdge(&rect, EDGE_SUNKEN, BF_RECT);
	else
		dc.DrawEdge(&rect, EDGE_RAISED, BF_RECT);

	TCHAR buffer[MAX_PATH];           //To store the Caption of the button.
	ZeroMemory(buffer, MAX_PATH);     //Intializing the buffer to zero
	::GetWindowText(lpDrawItemStruct->hwndItem, buffer, MAX_PATH); //Get the Caption of Button Window 

	dc.DrawText(buffer, &rect, DT_CENTER | DT_VCENTER | DT_SINGLELINE);//Redraw the  Caption of Button Window 
	dc.Detach();  // Detach the Button DC
	CDialog::OnDrawItem(nIDCtl, lpDrawItemStruct);

}
