// mw2Dlg.h : header file
//

#pragma once
#include "afxwin.h"


// Cmw2Dlg dialog
class Cmw2Dlg : public CDialog
{
// Construction
public:
	Cmw2Dlg(CWnd* pParent = NULL);	// standard constructor

// Dialog Data
	enum { IDD = IDD_MW2_DIALOG };

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
