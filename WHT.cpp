// WHT.cpp : implementation file
//

#include "stdafx.h"
#include "MyTest.h"
#include "WHT.h"
#include "afxdialogex.h"


// WHT dialog

IMPLEMENT_DYNAMIC(WHT, CDialogEx)

WHT::WHT(CWnd* pParent /*=NULL*/)
	: CDialogEx(IDD_DIALOG2, pParent)
	, h(10)
	, t(1)
	, w(5)
{

}

WHT::~WHT()
{
}

void WHT::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, H, h);
	DDV_MinMaxInt(pDX, h, 10, 50);
	DDX_Text(pDX, T, t);
	DDV_MinMaxInt(pDX, t, 1, 10);
	DDX_Text(pDX, W, w);
	DDV_MinMaxInt(pDX, w, 5, 30);
}

int WHT::GET_H()
{
	return h;
}
int WHT::GET_W()
{
	return w;
}
int WHT::GET_T()
{
	return t;
}


BEGIN_MESSAGE_MAP(WHT, CDialogEx)
END_MESSAGE_MAP()


// WHT message handlers
