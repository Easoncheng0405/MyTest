#pragma once


// WHT dialog

class WHT : public CDialogEx
{
	DECLARE_DYNAMIC(WHT)

public:
	WHT(CWnd* pParent = NULL);   // standard constructor
	virtual ~WHT();

	// Dialog Data
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DIALOG2 };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

	DECLARE_MESSAGE_MAP()
public:
	int h;
	int t;
	int w;
	int GET_H();
	int GET_W();
	int GET_T();
};
