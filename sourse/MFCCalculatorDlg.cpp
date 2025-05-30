
// MFCCalculatorDlg.cpp: 实现文件
//

#include "pch.h"
#include "framework.h"
#include "MFCCalculator.h"
#include "MFCCalculatorDlg.h"
#include "afxdialogex.h"
#include "Calculator.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// 用于应用程序“关于”菜单项的 CAboutDlg 对话框

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_ABOUTBOX };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

// 实现
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


// CMFCCalculatorDlg 对话框



CMFCCalculatorDlg::CMFCCalculatorDlg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_MFCCALCULATOR_DIALOG, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CMFCCalculatorDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CMFCCalculatorDlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	
	ON_BN_CLICKED(IDC_BUTTON1, &CMFCCalculatorDlg::OnBnClickedButton1)
	ON_BN_CLICKED(IDC_BUTTON2, &CMFCCalculatorDlg::OnBnClickedButton2)
	ON_BN_CLICKED(IDC_BUTTON3, &CMFCCalculatorDlg::OnBnClickedButton3)
	ON_BN_CLICKED(IDC_BUTTON4, &CMFCCalculatorDlg::OnBnClickedButton4)
	ON_BN_CLICKED(IDC_BUTTON5, &CMFCCalculatorDlg::OnBnClickedButton5)
	ON_BN_CLICKED(IDC_BUTTON6, &CMFCCalculatorDlg::OnBnClickedButton6)
	ON_BN_CLICKED(IDC_BUTTON7, &CMFCCalculatorDlg::OnBnClickedButton7)
	ON_BN_CLICKED(IDC_BUTTON8, &CMFCCalculatorDlg::OnBnClickedButton8)
	ON_BN_CLICKED(IDC_BUTTON9, &CMFCCalculatorDlg::OnBnClickedButton9)
	ON_BN_CLICKED(IDC_BUTTON0, &CMFCCalculatorDlg::OnBnClickedButton0)
	ON_BN_CLICKED(IDC_BUTTON_FAC, &CMFCCalculatorDlg::OnBnClickedButtonFac)
	ON_BN_CLICKED(IDC_BUTTON_DOT, &CMFCCalculatorDlg::OnBnClickedButtonDot)
	ON_BN_CLICKED(IDC_BUTTON_ADD, &CMFCCalculatorDlg::OnBnClickedButtonAdd)
	ON_BN_CLICKED(IDC_BUTTON_SUB, &CMFCCalculatorDlg::OnBnClickedButtonSub)
	ON_BN_CLICKED(IDC_BUTTON_MUL, &CMFCCalculatorDlg::OnBnClickedButtonMul)
	ON_BN_CLICKED(IDC_BUTTON_DIV, &CMFCCalculatorDlg::OnBnClickedButtonDiv)
	ON_BN_CLICKED(IDC_BUTTON_LBRACKET, &CMFCCalculatorDlg::OnBnClickedButtonLbracket)
	ON_BN_CLICKED(IDC_BUTTON_RBRACKET, &CMFCCalculatorDlg::OnBnClickedButtonRbracket)
	ON_BN_CLICKED(IDC_BUTTON_POW, &CMFCCalculatorDlg::OnBnClickedButtonPow)
	ON_BN_CLICKED(IDC_BUTTON_ABS, &CMFCCalculatorDlg::OnBnClickedButtonAbs)
	ON_BN_CLICKED(IDC_BUTTON_CL, &CMFCCalculatorDlg::OnBnClickedButtonCl)
	ON_BN_CLICKED(IDC_BUTTON_DEL, &CMFCCalculatorDlg::OnBnClickedButtonDel)
	ON_BN_CLICKED(IDC_BUTTON_REM, &CMFCCalculatorDlg::OnBnClickedButtonRem)
	ON_BN_CLICKED(IDC_BUTTON_EQL, &CMFCCalculatorDlg::OnBnClickedButtonEql)
END_MESSAGE_MAP()


// CMFCCalculatorDlg 消息处理程序

BOOL CMFCCalculatorDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// 将“关于...”菜单项添加到系统菜单中。

	// IDM_ABOUTBOX 必须在系统命令范围内。
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != nullptr)
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

	// 设置此对话框的图标。  当应用程序主窗口不是对话框时，框架将自动
	//  执行此操作
	SetIcon(m_hIcon, TRUE);			// 设置大图标
	SetIcon(m_hIcon, FALSE);		// 设置小图标

	// TODO: 在此添加额外的初始化代码

	return TRUE;  // 除非将焦点设置到控件，否则返回 TRUE
}

void CMFCCalculatorDlg::OnSysCommand(UINT nID, LPARAM lParam)
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

// 如果向对话框添加最小化按钮，则需要下面的代码
//  来绘制该图标。  对于使用文档/视图模型的 MFC 应用程序，
//  这将由框架自动完成。

void CMFCCalculatorDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // 用于绘制的设备上下文

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// 使图标在工作区矩形中居中
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// 绘制图标
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}
}

//当用户拖动最小化窗口时系统调用此函数取得光标
//显示。
HCURSOR CMFCCalculatorDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}

void CMFCCalculatorDlg::AddToEditExp(UINT IDC_Button)
{
	CString strBtn;
	CString strExp;
	CString eql ;
	eql = "0";
	GetDlgItem(IDC_Button)->GetWindowText(strBtn);
	GetDlgItem(IDC_EDIT1)->GetWindowText(strExp);
	if (strExp.Compare(eql) == 0) strExp = "";
	SetDlgItemText(IDC_EDIT1, strExp + strBtn);
}



void CMFCCalculatorDlg::OnBnClickedButton1()
{
	// TODO: 在此添加控件通知处理程序代码
	AddToEditExp(IDC_BUTTON1);
}


void CMFCCalculatorDlg::OnBnClickedButton2()
{
	// TODO: 在此添加控件通知处理程序代码

	AddToEditExp(IDC_BUTTON2);
}


void CMFCCalculatorDlg::OnBnClickedButton3()
{
	// TODO: 在此添加控件通知处理程序代码
	AddToEditExp(IDC_BUTTON3);
}


void CMFCCalculatorDlg::OnBnClickedButton4()
{
	// TODO: 在此添加控件通知处理程序代码
	AddToEditExp(IDC_BUTTON4);
}


void CMFCCalculatorDlg::OnBnClickedButton5()
{
	// TODO: 在此添加控件通知处理程序代码
	AddToEditExp(IDC_BUTTON5);
}


void CMFCCalculatorDlg::OnBnClickedButton6()
{
	// TODO: 在此添加控件通知处理程序代码
	AddToEditExp(IDC_BUTTON6);
}


void CMFCCalculatorDlg::OnBnClickedButton7()
{
	// TODO: 在此添加控件通知处理程序代码
	AddToEditExp(IDC_BUTTON7);
}


void CMFCCalculatorDlg::OnBnClickedButton8()
{
	// TODO: 在此添加控件通知处理程序代码
	AddToEditExp(IDC_BUTTON8);
}


void CMFCCalculatorDlg::OnBnClickedButton9()
{
	// TODO: 在此添加控件通知处理程序代码
	AddToEditExp(IDC_BUTTON9);
}


void CMFCCalculatorDlg::OnBnClickedButton0()
{
	// TODO: 在此添加控件通知处理程序代码
	AddToEditExp(IDC_BUTTON0);
}


void CMFCCalculatorDlg::OnBnClickedButtonFac()
{
	// TODO: 在此添加控件通知处理程序代码
	AddToEditExp(IDC_BUTTON_FAC);
}


void CMFCCalculatorDlg::OnBnClickedButtonDot()
{
	// TODO: 在此添加控件通知处理程序代码
	AddToEditExp(IDC_BUTTON_DOT);
}


void CMFCCalculatorDlg::OnBnClickedButtonAdd()
{
	// TODO: 在此添加控件通知处理程序代码
	AddToEditExp(IDC_BUTTON_ADD);
}


void CMFCCalculatorDlg::OnBnClickedButtonSub()
{
	// TODO: 在此添加控件通知处理程序代码
	AddToEditExp(IDC_BUTTON_SUB);
}


void CMFCCalculatorDlg::OnBnClickedButtonMul()
{
	// TODO: 在此添加控件通知处理程序代码
	AddToEditExp(IDC_BUTTON_MUL);
}


void CMFCCalculatorDlg::OnBnClickedButtonDiv()
{
	// TODO: 在此添加控件通知处理程序代码
	AddToEditExp(IDC_BUTTON_DIV);
}


void CMFCCalculatorDlg::OnBnClickedButtonLbracket()
{
	// TODO: 在此添加控件通知处理程序代码
	AddToEditExp(IDC_BUTTON_LBRACKET);
}


void CMFCCalculatorDlg::OnBnClickedButtonRbracket()
{
	// TODO: 在此添加控件通知处理程序代码
	AddToEditExp(IDC_BUTTON_RBRACKET);
}


void CMFCCalculatorDlg::OnBnClickedButtonPow()
{
	// TODO: 在此添加控件通知处理程序代码
	AddToEditExp(IDC_BUTTON_POW);
}


void CMFCCalculatorDlg::OnBnClickedButtonAbs()
{
	// TODO: 在此添加控件通知处理程序代码
	AddToEditExp(IDC_BUTTON_ABS);
}


void CMFCCalculatorDlg::OnBnClickedButtonCl()
{
	// TODO: 在此添加控件通知处理程序代码
	SetDlgItemText(IDC_EDIT1, NULL);
	CString cstr;
	cstr = "0";
	SetDlgItemText(IDC_EDIT1, cstr);
	cstr = "";
	SetDlgItemText(IDC_STATIC, cstr);
}


void CMFCCalculatorDlg::OnBnClickedButtonDel()
{
	// TODO: 在此添加控件通知处理程序代码
	CString strExp;
	GetDlgItem(IDC_EDIT1)->GetWindowText(strExp);
	strExp = strExp.Left(strExp.GetLength() - 1);
	SetDlgItemText(IDC_EDIT1, strExp);
}

void CMFCCalculatorDlg::OnBnClickedButtonRem()
{
	// TODO: 在此添加控件通知处理程序代码
	CString s1, s2, cs;
	s1 = "1/(";
	s2 = ")";
	GetDlgItemText(IDC_EDIT1, cs);
	SetDlgItemText(IDC_EDIT1, s1 + cs + s2);
}


void CMFCCalculatorDlg::OnBnClickedButtonEql()
{
	// TODO: 在此添加控件通知处理程序代码
	CString strExp;
	Calculator cal;
	CString strResult;
	CString strError;
	GetDlgItemText(IDC_EDIT1, strExp);
	string infix(CW2A(strExp.GetString())); //cw2a将Unicode转ASCLL
	cal.calculator(infix);
	if (cal.isError==1) {
		strError = "错误";
		SetDlgItemText(IDC_STATIC, strError);
	}
	else if (cal.isError == -1)
	{
		strError = "数据溢出";
		SetDlgItemText(IDC_STATIC, strError);

	}
	else {
		strResult.Format(_T("%g"), cal.getResult());
		SetDlgItemText(IDC_STATIC, strResult);
	}
}
