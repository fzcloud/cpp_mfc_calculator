// Child2Dlg.cpp: 实现文件
//

#include "pch.h"
#include "MFCCalculator.h"
#include "afxdialogex.h"
#include "Child2Dlg.h"
#include "Calculator.h"


// Child2Dlg 对话框

IMPLEMENT_DYNAMIC(Child2Dlg, CDialogEx)

Child2Dlg::Child2Dlg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_CHILD_2, pParent)
{

}

Child2Dlg::~Child2Dlg()
{
}

void Child2Dlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(Child2Dlg, CDialogEx)
	ON_BN_CLICKED(IDC_BUTTON0, &Child2Dlg::OnBnClickedButton0)
	ON_BN_CLICKED(IDC_BUTTON1, &Child2Dlg::OnBnClickedButton1)
	ON_BN_CLICKED(IDC_BUTTON2, &Child2Dlg::OnBnClickedButton2)
	ON_BN_CLICKED(IDC_BUTTON3, &Child2Dlg::OnBnClickedButton3)
	ON_BN_CLICKED(IDC_BUTTON4, &Child2Dlg::OnBnClickedButton4)
	ON_BN_CLICKED(IDC_BUTTON5, &Child2Dlg::OnBnClickedButton5)
	ON_BN_CLICKED(IDC_BUTTON6, &Child2Dlg::OnBnClickedButton6)
	ON_BN_CLICKED(IDC_BUTTON7, &Child2Dlg::OnBnClickedButton7)
	ON_BN_CLICKED(IDC_BUTTON8, &Child2Dlg::OnBnClickedButton8)
	ON_BN_CLICKED(IDC_BUTTON9, &Child2Dlg::OnBnClickedButton9)
	ON_BN_CLICKED(IDC_BUTTON_DOT, &Child2Dlg::OnBnClickedButtonDot)
	ON_BN_CLICKED(IDC_BUTTON_POW, &Child2Dlg::OnBnClickedButtonPow)
	ON_BN_CLICKED(IDC_BUTTON_ADD, &Child2Dlg::OnBnClickedButtonAdd)
	ON_BN_CLICKED(IDC_BUTTON_SUB, &Child2Dlg::OnBnClickedButtonSub)
	ON_BN_CLICKED(IDC_BUTTON_MUL, &Child2Dlg::OnBnClickedButtonMul)
	ON_BN_CLICKED(IDC_BUTTON_DIV, &Child2Dlg::OnBnClickedButtonDiv)
	ON_BN_CLICKED(IDC_BUTTON_MBRACKET, &Child2Dlg::OnBnClickedButtonMbracket)
	ON_BN_CLICKED(IDC_BUTTON_BRACKET, &Child2Dlg::OnBnClickedButtonBracket)
	ON_BN_CLICKED(IDC_BUTTON_COMMA, &Child2Dlg::OnBnClickedButtonComma)
	ON_BN_CLICKED(IDC_BUTTON_SEMICOLON, &Child2Dlg::OnBnClickedButtonSemicolon)
	ON_BN_CLICKED(IDC_BUTTON_DEL, &Child2Dlg::OnBnClickedButtonDel)
	ON_BN_CLICKED(IDC_BUTTON_CL, &Child2Dlg::OnBnClickedButtonCl)
	ON_BN_CLICKED(IDC_BUTTON_TRANS, &Child2Dlg::OnBnClickedButtonTrans)
	ON_BN_CLICKED(IDC_BUTTON_RANK, &Child2Dlg::OnBnClickedButtonRank)
	ON_BN_CLICKED(IDC_BUTTON_INV, &Child2Dlg::OnBnClickedButtonInv)
	ON_BN_CLICKED(IDC_BUTTON_DET, &Child2Dlg::OnBnClickedButtonDet)
	ON_BN_CLICKED(IDC_BUTTON_EQL, &Child2Dlg::OnBnClickedButtonEql)
END_MESSAGE_MAP()


// Child2Dlg 消息处理程序

void Child2Dlg::AddToEditExp(UINT IDC_Button)
{
	CString strBtn;
	CString strExp;
	CString lword;
	CString rword;
	
	GetDlgItem(IDC_Button)->GetWindowText(strBtn);
	GetDlgItem(IDC_EDIT1)->GetWindowText(strExp);

	CEdit* pEdit = (CEdit*)GetDlgItem(IDC_EDIT1);
	CPoint cursor;
	cursor=pEdit->GetCaretPos();
	DWORD curPos = pEdit->CharFromPos(cursor);
	int ncolumn = LOWORD(curPos);

	lword=strExp.Left(ncolumn);
	rword = strExp.Mid(ncolumn);
	SetDlgItemText(IDC_EDIT1, lword + strBtn + rword);
}

void Child2Dlg::AddToEditExp(CString strBtn)
{
	CString strExp;
	CString lword;
	CString rword;

	GetDlgItem(IDC_EDIT1)->GetWindowText(strExp);

	CEdit* pEdit = (CEdit*)GetDlgItem(IDC_EDIT1);
	CPoint cursor;
	cursor = pEdit->GetCaretPos();
	DWORD curPos = pEdit->CharFromPos(cursor);
	int ncolumn = LOWORD(curPos);

	lword = strExp.Left(ncolumn);
	rword = strExp.Mid(ncolumn);
	SetDlgItemText(IDC_EDIT1, lword + strBtn + rword);
}

//void Child2Dlg::AddToEditExp(CString strLeft, CString strRight)
//{
//	CString strExp;
//	CString eql;
//	eql = "";
//	GetDlgItem(IDC_EDIT1)->GetWindowText(strExp);
//	if (strExp.Compare(eql) == 0) strExp = "0";
//	SetDlgItemText(IDC_EDIT1, strLeft + strExp + strRight);
//}

void Child2Dlg::OnBnClickedButton0()
{
	// TODO: 在此添加控件通知处理程序代码
	AddToEditExp(IDC_BUTTON0);
}

void Child2Dlg::OnBnClickedButton1()
{
	// TODO: 在此添加控件通知处理程序代码
	AddToEditExp(IDC_BUTTON1);
}

void Child2Dlg::OnBnClickedButton2()
{
	// TODO: 在此添加控件通知处理程序代码
	AddToEditExp(IDC_BUTTON2);
}

void Child2Dlg::OnBnClickedButton3()
{
	// TODO: 在此添加控件通知处理程序代码
	AddToEditExp(IDC_BUTTON3);
}

void Child2Dlg::OnBnClickedButton4()
{
	// TODO: 在此添加控件通知处理程序代码
	AddToEditExp(IDC_BUTTON4);
}

void Child2Dlg::OnBnClickedButton5()
{
	// TODO: 在此添加控件通知处理程序代码
	AddToEditExp(IDC_BUTTON5);
}

void Child2Dlg::OnBnClickedButton6()
{
	// TODO: 在此添加控件通知处理程序代码
	AddToEditExp(IDC_BUTTON6);
}

void Child2Dlg::OnBnClickedButton7()
{
	// TODO: 在此添加控件通知处理程序代码
	AddToEditExp(IDC_BUTTON7);
}

void Child2Dlg::OnBnClickedButton8()
{
	// TODO: 在此添加控件通知处理程序代码
	AddToEditExp(IDC_BUTTON8);
}

void Child2Dlg::OnBnClickedButton9()
{
	// TODO: 在此添加控件通知处理程序代码
	AddToEditExp(IDC_BUTTON9);
}

void Child2Dlg::OnBnClickedButtonDot()
{
	// TODO: 在此添加控件通知处理程序代码
	AddToEditExp(IDC_BUTTON_DOT);
}

void Child2Dlg::OnBnClickedButtonPow()
{
	// TODO: 在此添加控件通知处理程序代码
	AddToEditExp(IDC_BUTTON_POW);
}

void Child2Dlg::OnBnClickedButtonAdd()
{
	// TODO: 在此添加控件通知处理程序代码
	AddToEditExp(IDC_BUTTON_ADD);
}

void Child2Dlg::OnBnClickedButtonSub()
{
	// TODO: 在此添加控件通知处理程序代码
	AddToEditExp(IDC_BUTTON_SUB);
}

void Child2Dlg::OnBnClickedButtonMul()
{
	// TODO: 在此添加控件通知处理程序代码
	AddToEditExp(IDC_BUTTON_MUL);
}

void Child2Dlg::OnBnClickedButtonDiv()
{
	// TODO: 在此添加控件通知处理程序代码
	AddToEditExp(IDC_BUTTON_DIV);
}

void Child2Dlg::OnBnClickedButtonMbracket()
{
	// TODO: 在此添加控件通知处理程序代码
	AddToEditExp(L"[]");
}

void Child2Dlg::OnBnClickedButtonBracket()
{
	// TODO: 在此添加控件通知处理程序代码
	AddToEditExp(L"()");
}

void Child2Dlg::OnBnClickedButtonComma()
{
	// TODO: 在此添加控件通知处理程序代码
	AddToEditExp(IDC_BUTTON_COMMA);
}

void Child2Dlg::OnBnClickedButtonSemicolon()
{
	// TODO: 在此添加控件通知处理程序代码
	AddToEditExp(IDC_BUTTON_SEMICOLON);
}

void Child2Dlg::OnBnClickedButtonDel()
{
	// TODO: 在此添加控件通知处理程序代码

	CString strExp;
	CString lword;
	CString rword;

	GetDlgItem(IDC_EDIT1)->GetWindowText(strExp);

	CEdit* pEdit = (CEdit*)GetDlgItem(IDC_EDIT1);
	CPoint cursor;
	cursor = pEdit->GetCaretPos();
	DWORD curPos = pEdit->CharFromPos(cursor);
	int ncolumn = LOWORD(curPos);

	lword = strExp.Left(ncolumn);
	rword = strExp.Mid(ncolumn);

	lword = lword.Left(lword.GetLength() - 1);
	SetDlgItemText(IDC_EDIT1, lword + rword);
}

void Child2Dlg::OnBnClickedButtonCl()
{
	// TODO: 在此添加控件通知处理程序代码
	SetDlgItemText(IDC_EDIT1, NULL);
	CString cstr;
	cstr = "";
	SetDlgItemText(IDC_EDIT1, cstr);
	cstr = "";
	SetDlgItemText(IDC_STATIC, cstr);
}

void Child2Dlg::OnBnClickedButtonTrans()
{
	// TODO: 在此添加控件通知处理程序代码
	AddToEditExp(L"trans()");
}

void Child2Dlg::OnBnClickedButtonRank()
{
	// TODO: 在此添加控件通知处理程序代码
	AddToEditExp(L"rank()");
}

void Child2Dlg::OnBnClickedButtonInv()
{
	// TODO: 在此添加控件通知处理程序代码
	AddToEditExp(L"inv()");
}

void Child2Dlg::OnBnClickedButtonDet()
{
	// TODO: 在此添加控件通知处理程序代码
	AddToEditExp(L"det()");
}

void Child2Dlg::OnBnClickedButtonEql()
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
		strError = CA2W(err.what(), CP_UTF8);
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

		if(strResult.Left(1).Compare(L"|")==0|| strResult.Left(1).Compare(L"[")==0)
		MessageBox(strResult,L"结果",MB_OK);
		else
		SetDlgItemText(IDC_STATIC, strResult);
	}
}
