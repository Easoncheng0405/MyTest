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
	// TODO:  ����ÿؼ��� RICHEDIT �ؼ���������
	// ���ʹ�֪ͨ��������д CDialogEx::OnInitDialog()
	// ���������� CRichEditCtrl().SetEventMask()��
	// ͬʱ�� ENM_CHANGE ��־�������㵽�����С�

	// TODO:  �ڴ���ӿؼ�֪ͨ����������
}


void MyDlg::OnEnChangeB()
{
	// TODO:  ����ÿؼ��� RICHEDIT �ؼ���������
	// ���ʹ�֪ͨ��������д CDialogEx::OnInitDialog()
	// ���������� CRichEditCtrl().SetEventMask()��
	// ͬʱ�� ENM_CHANGE ��־�������㵽�����С�

	// TODO:  �ڴ���ӿؼ�֪ͨ����������
}

int MyDlg::getRGB()
{
	return RGB(r, g, b);
}


