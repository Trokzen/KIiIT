// mw1Dlg.h : header file
//

#pragma once
#include "afxwin.h"


// Cmw1Dlg dialog
class Cmw1Dlg : public CDialog
{
// Construction
public:
	Cmw1Dlg(CWnd* pParent = NULL);	// standard constructor

// Dialog Data
	enum { IDD = IDD_MW1_DIALOG };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support


// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	virtual BOOL OnInitDialog();
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedButton1();
public:
	CEdit RabPath;
public:
	afx_msg void OnEnChangeEdit1();
public:
	afx_msg void OnBnClickedButton2();
};
