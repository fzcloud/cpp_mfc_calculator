
// MFCCalculatorDlg.h: 头文件
//

#pragma once
#include "Child1Dlg.h"
#include "Child2Dlg.h"


// CMFCCalculatorDlg 对话框
class CMFCCalculatorDlg : public CDialogEx
{
// 构造
public:
	CMFCCalculatorDlg(CWnd* pParent = nullptr);	// 标准构造函数

	void AddToEditExp(UINT IDC_Button);

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_MFCCALCULATOR_DIALOG };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV 支持
	


// 实现
protected:
	CDialog* DlgPtr;

	Child1Dlg child1;
	Child2Dlg child2;

	HICON m_hIcon;

	// 生成的消息映射函数
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
public:
	
	CStatic m_staticbtn;
	afx_msg void OnDlgNormal();
	afx_msg void OnDlgMatrix();
};
