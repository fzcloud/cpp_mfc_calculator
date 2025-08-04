// CDlgNormal.cpp: 实现文件
//

#include "pch.h"
#include "MFCCalculator.h"
#include "afxdialogex.h"
#include "MFCCalculatorDlg.h"


// CDlgNormal 对话框

IMPLEMENT_DYNAMIC(CDlgNormal, CDialogEx)

CDlgNormal::CDlgNormal(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_CHILD_N, pParent)
{
	parentDlg = GetParent();
}

CDlgNormal::~CDlgNormal()
{
}

void CDlgNormal::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(CDlgNormal, CDialogEx)
	ON_BN_CLICKED(IDC_BUTTON_CL, &CDlgNormal::OnBnClickedButtonCl)
	ON_BN_CLICKED(IDC_BUTTON_DEL, &CDlgNormal::OnBnClickedButtonDel)
	ON_BN_CLICKED(IDC_BUTTON_LBRACKET, &CDlgNormal::OnBnClickedButtonLbracket)
	ON_BN_CLICKED(IDC_BUTTON_RBRACKET, &CDlgNormal::OnBnClickedButtonRbracket)
	ON_BN_CLICKED(IDC_BUTTON_REM, &CDlgNormal::OnBnClickedButtonRem)
	ON_BN_CLICKED(IDC_BUTTON_POW, &CDlgNormal::OnBnClickedButtonPow)
	ON_BN_CLICKED(IDC_BUTTON_FAC, &CDlgNormal::OnBnClickedButtonFac)
	ON_BN_CLICKED(IDC_BUTTON_DIV, &CDlgNormal::OnBnClickedButtonDiv)
	ON_BN_CLICKED(IDC_BUTTON_MUL, &CDlgNormal::OnBnClickedButtonMul)
	ON_BN_CLICKED(IDC_BUTTON_SUB, &CDlgNormal::OnBnClickedButtonSub)
	ON_BN_CLICKED(IDC_BUTTON_ADD, &CDlgNormal::OnBnClickedButtonAdd)
	ON_BN_CLICKED(IDC_BUTTON_DOT, &CDlgNormal::OnBnClickedButtonDot)
	ON_BN_CLICKED(IDC_BUTTON_ABS, &CDlgNormal::OnBnClickedButtonAbs)
	ON_BN_CLICKED(IDC_BUTTON0, &CDlgNormal::OnBnClickedButton0)
	ON_BN_CLICKED(IDC_BUTTON1, &CDlgNormal::OnBnClickedButton1)
	ON_BN_CLICKED(IDC_BUTTON2, &CDlgNormal::OnBnClickedButton2)
	ON_BN_CLICKED(IDC_BUTTON3, &CDlgNormal::OnBnClickedButton3)
	ON_BN_CLICKED(IDC_BUTTON4, &CDlgNormal::OnBnClickedButton4)
	ON_BN_CLICKED(IDC_BUTTON5, &CDlgNormal::OnBnClickedButton5)
	ON_BN_CLICKED(IDC_BUTTON6, &CDlgNormal::OnBnClickedButton6)
	ON_BN_CLICKED(IDC_BUTTON7, &CDlgNormal::OnBnClickedButton7)
	ON_BN_CLICKED(IDC_BUTTON8, &CDlgNormal::OnBnClickedButton8)
	ON_BN_CLICKED(IDC_BUTTON9, &CDlgNormal::OnBnClickedButton9)
	ON_BN_CLICKED(IDC_BUTTON_EQL, &CDlgNormal::OnBnClickedButtonEql)
END_MESSAGE_MAP()


// CDlgNormal 消息处理程序

void CDlgNormal::AddToEditExp(UINT IDC_Button)
{
	CString strBtn;
	CString strExp;
	CString eql;
	eql = "0";
	GetDlgItem(IDC_Button)->GetWindowText(strBtn);
	GetDlgItem(IDC_EDIT1)->GetWindowText(strExp);
	if (strExp.Compare(eql) == 0) strExp = "";
	SetDlgItemText(IDC_EDIT1, strExp + strBtn);
}

void CDlgNormal::OnBnClickedButtonCl()
{
	// TODO: 在此添加控件通知处理程序代码
	SetDlgItemText(IDC_EDIT1, NULL);
	CString cstr;
	cstr = "0";
	SetDlgItemText(IDC_EDIT1, cstr);
	cstr = "";
	SetDlgItemText(IDC_STATIC, cstr);
}

void CDlgNormal::OnBnClickedButtonDel()
{
	// TODO: 在此添加控件通知处理程序代码
	CString strExp;
	GetDlgItem(IDC_EDIT1)->GetWindowText(strExp);
	strExp = strExp.Left(strExp.GetLength() - 1);
	SetDlgItemText(IDC_EDIT1, strExp);
}

void CDlgNormal::OnBnClickedButtonLbracket()
{
	// TODO: 在此添加控件通知处理程序代码
	AddToEditExp(IDC_BUTTON_LBRACKET);
}

void CDlgNormal::OnBnClickedButtonRbracket()
{
	// TODO: 在此添加控件通知处理程序代码
}

void CDlgNormal::OnBnClickedButtonRem()
{
	// TODO: 在此添加控件通知处理程序代码
}

void CDlgNormal::OnBnClickedButtonPow()
{
	// TODO: 在此添加控件通知处理程序代码
}

void CDlgNormal::OnBnClickedButtonFac()
{
	// TODO: 在此添加控件通知处理程序代码
}

void CDlgNormal::OnBnClickedButtonDiv()
{
	// TODO: 在此添加控件通知处理程序代码
}

void CDlgNormal::OnBnClickedButtonMul()
{
	// TODO: 在此添加控件通知处理程序代码
}

void CDlgNormal::OnBnClickedButtonSub()
{
	// TODO: 在此添加控件通知处理程序代码
}

void CDlgNormal::OnBnClickedButtonAdd()
{
	// TODO: 在此添加控件通知处理程序代码
}

void CDlgNormal::OnBnClickedButtonDot()
{
	// TODO: 在此添加控件通知处理程序代码
}

void CDlgNormal::OnBnClickedButtonAbs()
{
	// TODO: 在此添加控件通知处理程序代码
}

void CDlgNormal::OnBnClickedButton0()
{
	// TODO: 在此添加控件通知处理程序代码
}

void CDlgNormal::OnBnClickedButton1()
{
	// TODO: 在此添加控件通知处理程序代码
}

void CDlgNormal::OnBnClickedButton2()
{
	// TODO: 在此添加控件通知处理程序代码
}

void CDlgNormal::OnBnClickedButton3()
{
	// TODO: 在此添加控件通知处理程序代码
}

void CDlgNormal::OnBnClickedButton4()
{
	// TODO: 在此添加控件通知处理程序代码
}

void CDlgNormal::OnBnClickedButton5()
{
	// TODO: 在此添加控件通知处理程序代码
}

void CDlgNormal::OnBnClickedButton6()
{
	// TODO: 在此添加控件通知处理程序代码
}

void CDlgNormal::OnBnClickedButton7()
{
	// TODO: 在此添加控件通知处理程序代码
}

void CDlgNormal::OnBnClickedButton8()
{
	// TODO: 在此添加控件通知处理程序代码
}

void CDlgNormal::OnBnClickedButton9()
{
	// TODO: 在此添加控件通知处理程序代码
}

void CDlgNormal::OnBnClickedButtonEql()
{
	// TODO: 在此添加控件通知处理程序代码
}
