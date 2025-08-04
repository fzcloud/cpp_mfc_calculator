#pragma once
#include "afxdialogex.h"


// Child2Dlg 对话框

class Child2Dlg : public CDialogEx
{
	DECLARE_DYNAMIC(Child2Dlg)

public:
	Child2Dlg(CWnd* pParent = nullptr);   // 标准构造函数
	virtual ~Child2Dlg();

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_CHILD_2 };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	void AddToEditExp(UINT IDC_Button);
	void AddToEditExp(CString strBtn);
	void AddToEditExp(CString strLeft, CString strRight);
	afx_msg void OnBnClickedButton0();
	afx_msg void OnBnClickedButton1();
	afx_msg void OnBnClickedButton2();
	afx_msg void OnBnClickedButton3();
	afx_msg void OnBnClickedButton4();
	afx_msg void OnBnClickedButton5();
	afx_msg void OnBnClickedButton6();
	afx_msg void OnBnClickedButton7();
	afx_msg void OnBnClickedButton8();
	afx_msg void OnBnClickedButton9();
	afx_msg void OnBnClickedButtonDot();
	afx_msg void OnBnClickedButtonPow();
	afx_msg void OnBnClickedButtonAdd();
	afx_msg void OnBnClickedButtonSub();
	afx_msg void OnBnClickedButtonMul();
	afx_msg void OnBnClickedButtonDiv();
	afx_msg void OnBnClickedButtonMbracket();
	afx_msg void OnBnClickedButtonBracket();
	afx_msg void OnBnClickedButtonComma();
	afx_msg void OnBnClickedButtonSemicolon();
	afx_msg void OnBnClickedButtonDel();
	afx_msg void OnBnClickedButtonCl();
	afx_msg void OnBnClickedButtonTrans();
	afx_msg void OnBnClickedButtonRank();
	afx_msg void OnBnClickedButtonInv();
	afx_msg void OnBnClickedButtonDet();
	afx_msg void OnBnClickedButtonEql();
};
