// Child1Dlg.cpp: 实现文件
//

#include "pch.h"
#include "MFCCalculator.h"
#include "afxdialogex.h"
#include "Child1Dlg.h"
#include "Calculator.h"


// Child1Dlg 对话框

IMPLEMENT_DYNAMIC(Child1Dlg, CDialogEx)

Child1Dlg::Child1Dlg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_CHILD_1, pParent)
{

}

Child1Dlg::~Child1Dlg()
{
}

void Child1Dlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(Child1Dlg, CDialogEx)
	ON_BN_CLICKED(IDC_BUTTON_CL, &Child1Dlg::OnBnClickedButtonCl)
	ON_BN_CLICKED(IDC_BUTTON_DEL, &Child1Dlg::OnBnClickedButtonDel)
	ON_BN_CLICKED(IDC_BUTTON_LBRACKET, &Child1Dlg::OnBnClickedButtonLbracket)
	ON_BN_CLICKED(IDC_BUTTON_RBRACKET, &Child1Dlg::OnBnClickedButtonRbracket)
	ON_BN_CLICKED(IDC_BUTTON_ABS, &Child1Dlg::OnBnClickedButtonAbs)
	ON_BN_CLICKED(IDC_BUTTON_POW, &Child1Dlg::OnBnClickedButtonPow)
	ON_BN_CLICKED(IDC_BUTTON_FAC, &Child1Dlg::OnBnClickedButtonFac)
	ON_BN_CLICKED(IDC_BUTTON_DIV, &Child1Dlg::OnBnClickedButtonDiv)
	ON_BN_CLICKED(IDC_BUTTON7, &Child1Dlg::OnBnClickedButton7)
	ON_BN_CLICKED(IDC_BUTTON8, &Child1Dlg::OnBnClickedButton8)
	ON_BN_CLICKED(IDC_BUTTON9, &Child1Dlg::OnBnClickedButton9)
	ON_BN_CLICKED(IDC_BUTTON_MUL, &Child1Dlg::OnBnClickedButtonMul)
	ON_BN_CLICKED(IDC_BUTTON4, &Child1Dlg::OnBnClickedButton4)
	ON_BN_CLICKED(IDC_BUTTON5, &Child1Dlg::OnBnClickedButton5)
	ON_BN_CLICKED(IDC_BUTTON6, &Child1Dlg::OnBnClickedButton6)
	ON_BN_CLICKED(IDC_BUTTON1, &Child1Dlg::OnBnClickedButton1)
	ON_BN_CLICKED(IDC_BUTTON2, &Child1Dlg::OnBnClickedButton2)
	ON_BN_CLICKED(IDC_BUTTON3, &Child1Dlg::OnBnClickedButton3)
	ON_BN_CLICKED(IDC_BUTTON0, &Child1Dlg::OnBnClickedButton0)
	ON_BN_CLICKED(IDC_BUTTON_SUB, &Child1Dlg::OnBnClickedButtonSub)
	ON_BN_CLICKED(IDC_BUTTON_ADD, &Child1Dlg::OnBnClickedButtonAdd)
	ON_BN_CLICKED(IDC_BUTTON_REM, &Child1Dlg::OnBnClickedButtonRem)
	ON_BN_CLICKED(IDC_BUTTON_DOT, &Child1Dlg::OnBnClickedButtonDot)
	ON_BN_CLICKED(IDC_BUTTON_EQL, &Child1Dlg::OnBnClickedButtonEql)
END_MESSAGE_MAP()


// Child1Dlg 消息处理程序

void Child1Dlg::AddToEditExp(UINT IDC_Button)
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

void Child1Dlg::OnBnClickedButtonCl()
{
	// TODO: 在此添加控件通知处理程序代码
	SetDlgItemText(IDC_EDIT1, NULL);
	CString cstr;
	cstr = "0";
	SetDlgItemText(IDC_EDIT1, cstr);
	cstr = "";
	SetDlgItemText(IDC_STATIC, cstr);
}

void Child1Dlg::OnBnClickedButtonDel()
{
	// TODO: 在此添加控件通知处理程序代码
	CString strExp;
	GetDlgItem(IDC_EDIT1)->GetWindowText(strExp);
	strExp = strExp.Left(strExp.GetLength() - 1);
	SetDlgItemText(IDC_EDIT1, strExp);
}

void Child1Dlg::OnBnClickedButtonLbracket()
{
	// TODO: 在此添加控件通知处理程序代码
	AddToEditExp(IDC_BUTTON_LBRACKET);
}

void Child1Dlg::OnBnClickedButtonRbracket()
{
	// TODO: 在此添加控件通知处理程序代码
	AddToEditExp(IDC_BUTTON_RBRACKET);
}

void Child1Dlg::OnBnClickedButtonAbs()
{
	// TODO: 在此添加控件通知处理程序代码
	AddToEditExp(IDC_BUTTON_ABS);
}

void Child1Dlg::OnBnClickedButtonPow()
{
	// TODO: 在此添加控件通知处理程序代码
	AddToEditExp(IDC_BUTTON_POW);
}

void Child1Dlg::OnBnClickedButtonFac()
{
	// TODO: 在此添加控件通知处理程序代码
	AddToEditExp(IDC_BUTTON_FAC);
}

void Child1Dlg::OnBnClickedButtonDiv()
{
	// TODO: 在此添加控件通知处理程序代码
	AddToEditExp(IDC_BUTTON_DIV);
}

void Child1Dlg::OnBnClickedButton7()
{
	// TODO: 在此添加控件通知处理程序代码
	AddToEditExp(IDC_BUTTON7);
}

void Child1Dlg::OnBnClickedButton8()
{
	// TODO: 在此添加控件通知处理程序代码
	AddToEditExp(IDC_BUTTON8);
}

void Child1Dlg::OnBnClickedButton9()
{
	// TODO: 在此添加控件通知处理程序代码
	AddToEditExp(IDC_BUTTON9);
}

void Child1Dlg::OnBnClickedButtonMul()
{
	// TODO: 在此添加控件通知处理程序代码
	AddToEditExp(IDC_BUTTON_MUL);
}

void Child1Dlg::OnBnClickedButton4()
{
	// TODO: 在此添加控件通知处理程序代码
	AddToEditExp(IDC_BUTTON4);
}

void Child1Dlg::OnBnClickedButton5()
{
	// TODO: 在此添加控件通知处理程序代码
	AddToEditExp(IDC_BUTTON5);
}

void Child1Dlg::OnBnClickedButton6()
{
	// TODO: 在此添加控件通知处理程序代码
	AddToEditExp(IDC_BUTTON6);
}

void Child1Dlg::OnBnClickedButton1()
{
	// TODO: 在此添加控件通知处理程序代码
	AddToEditExp(IDC_BUTTON1);
}

void Child1Dlg::OnBnClickedButton2()
{
	// TODO: 在此添加控件通知处理程序代码
	AddToEditExp(IDC_BUTTON2);
}

void Child1Dlg::OnBnClickedButton3()
{
	// TODO: 在此添加控件通知处理程序代码
	AddToEditExp(IDC_BUTTON3);
}

void Child1Dlg::OnBnClickedButton0()
{
	// TODO: 在此添加控件通知处理程序代码
	AddToEditExp(IDC_BUTTON0);
}

void Child1Dlg::OnBnClickedButtonSub()
{
	// TODO: 在此添加控件通知处理程序代码
	AddToEditExp(IDC_BUTTON_SUB);
}

void Child1Dlg::OnBnClickedButtonAdd()
{
	// TODO: 在此添加控件通知处理程序代码
	AddToEditExp(IDC_BUTTON_ADD);
}

void Child1Dlg::OnBnClickedButtonRem()
{
	// TODO: 在此添加控件通知处理程序代码
	CString s1, s2, cs;
	s1 = "1/(";
	s2 = ")";
	GetDlgItemText(IDC_EDIT1, cs);
	SetDlgItemText(IDC_EDIT1, s1 + cs + s2);
}

void Child1Dlg::OnBnClickedButtonDot()
{
	// TODO: 在此添加控件通知处理程序代码
	AddToEditExp(IDC_BUTTON_DOT);
}

void Child1Dlg::OnBnClickedButtonEql()
{
	// TODO: 在此添加控件通知处理程序代码
	CString strExp;
	Calculator cal;
	CString strResult;
	CString strError;
	GetDlgItemText(IDC_EDIT1, strExp);

	if (strExp.Compare(L"") == 0) strExp = "0";

	string infix(CW2A(strExp.GetString())); //cw2a将Unicode转ASCLL
	try
	{
		cal.calculator(infix);
	}
	catch (runtime_error& err)
	{
		strError=CA2W(err.what(),CP_UTF8);
		/*CString strError(err.what());*/
		SetDlgItemText(IDC_STATIC, strError);
		return;
	}
	if (cal.isError == 1) {
		strError = "错误";
		SetDlgItemText(IDC_STATIC, strError);
	}
	
	else {
		std::string resultStr = cal.getResult();
		strResult = CString(resultStr.c_str());
		SetDlgItemText(IDC_STATIC, strResult);
	}
}
