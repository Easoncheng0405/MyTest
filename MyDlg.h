#pragma once


// MyDlg dialog

class MyDlg : public CDialogEx
{
	DECLARE_DYNAMIC(MyDlg)

public:
	MyDlg(CWnd* pParent = NULL);   // standard constructor
	virtual ~MyDlg();

	// Dialog Data
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DIALOG1 };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnEnChangeR();
	afx_msg void OnEnChangeG();
	afx_msg void OnEnChangeB();
	int r;
	int b;
	int g;
	int getRGB();
};
