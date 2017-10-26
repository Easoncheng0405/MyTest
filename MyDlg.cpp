// MyDlg.cpp : implementation file
//

#include "stdafx.h"
#include "MyTest.h"
#include "MyDlg.h"
#include "afxdialogex.h"
#include<string>

// MyDlg dialog

IMPLEMENT_DYNAMIC(MyDlg, CDialogEx)

MyDlg::MyDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(IDD_DIALOG1, pParent)
	, r(0)
	, b(0)
	, g(0)
{

}

MyDlg::~MyDlg()
{
}

void MyDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	CString cr, cg, cb;
	DDX_Text(pDX, R, r);
	DDX_Text(pDX, B, b);
	DDX_Text(pDX, G, g);
	DDV_MinMaxInt(pDX, g, 0, 255);
	DDV_MinMaxInt(pDX, b, 0, 255);
	DDV_MinMaxInt(pDX, r, 0, 255);
}


BEGIN_MESSAGE_MAP(MyDlg, CDialogEx)

	ON_EN_CHANGE(R, &MyDlg::OnEnChangeR)
	ON_EN_CHANGE(G, &MyDlg::OnEnChangeG)
	ON_EN_CHANGE(B, &MyDlg::OnEnChangeB)
END_MESSAGE_MAP()


// MyDlg message handlers





void MyDlg::OnEnChangeR()
{

}


void MyDlg::OnEnChangeG()
{
	// TODO:  如果该控件是 RICHEDIT 控件，它将不
	// 发送此通知，除非重写 CDialogEx::OnInitDialog()
	// 函数并调用 CRichEditCtrl().SetEventMask()，
	// 同时将 ENM_CHANGE 标志“或”运算到掩码中。

	// TODO:  在此添加控件通知处理程序代码
}


void MyDlg::OnEnChangeB()
{
	// TODO:  如果该控件是 RICHEDIT 控件，它将不
	// 发送此通知，除非重写 CDialogEx::OnInitDialog()
	// 函数并调用 CRichEditCtrl().SetEventMask()，
	// 同时将 ENM_CHANGE 标志“或”运算到掩码中。

	// TODO:  在此添加控件通知处理程序代码
}

int MyDlg::getRGB()
{
	return RGB(r, g, b);
}


