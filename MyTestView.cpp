
// MyTestView.cpp: CMyTestView 类的实现
//

#include "stdafx.h"
// SHARED_HANDLERS 可以在实现预览、缩略图和搜索筛选器句柄的
// ATL 项目中进行定义，并允许与该项目共享文档代码。
#ifndef SHARED_HANDLERS
#include "MyTest.h"
#endif

#include "MyTestDoc.h"
#include "MyTestView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

#include"MyDlg.h"
#include "WHT.h"
// CMyTestView

IMPLEMENT_DYNCREATE(CMyTestView, CView)

BEGIN_MESSAGE_MAP(CMyTestView, CView)
	ON_WM_CONTEXTMENU()
	ON_WM_RBUTTONUP()
	ON_WM_NCLBUTTONDOWN()
	ON_WM_NCLBUTTONUP()
	ON_WM_MOUSEMOVE()
	ON_WM_RBUTTONDOWN()
	ON_WM_LBUTTONDOWN()
	ON_COMMAND(ID_CHOOSE_COLOR, &CMyTestView::OnChooseColor)
	ON_COMMAND(H_AND_W, &CMyTestView::OnAndW)
END_MESSAGE_MAP()

// CMyTestView 构造/析构

CMyTestView::CMyTestView()
{
	// TODO: 在此处添加构造代码
	draw = new MyDraw();
	list = new CObArray();
	OK = false;
	tmp = nullptr;
	list = new CObArray();
	dlg = new MyDlg();
	wht = new WHT();
}

CMyTestView::~CMyTestView()
{
}

BOOL CMyTestView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: 在此处通过修改
	//  CREATESTRUCT cs 来修改窗口类或样式

	return CView::PreCreateWindow(cs);
}

// CMyTestView 绘图

void CMyTestView::OnDraw(CDC* /*pDC*/)
{
	CMyTestDoc* pDoc = GetDocument();

	ASSERT_VALID(pDoc);
	// TODO: 在此处为本机数据添加绘制代码
	for (int i = 0; i < draw->map.GetSize(); i++)
	{
		CObArray* list = (CObArray*)draw->map.GetAt(i);
		for (int j = 1; j < list->GetSize(); j++)
		{
			draw->BresenhamLine((CPoint*)list->GetAt(j - 1), (CPoint*)list->GetAt(j), this->GetDC(), RGB);
		}
		if (list->GetSize())
			draw->BresenhamLine((CPoint*)list->GetAt(0), (CPoint*)list->GetAt(list->GetSize() - 1), this->GetDC(), RGB);
	}
	draw->ReFill(this->GetDC());
}

void CMyTestView::OnRButtonUp(UINT /* nFlags */, CPoint point)
{
	//ClientToScreen(&point);
	//OnContextMenu(this, point);
}

void CMyTestView::OnContextMenu(CWnd* /* pWnd */, CPoint point)
{
#ifndef SHARED_HANDLERS
	theApp.GetContextMenuManager()->ShowPopupMenu(IDR_POPUP_EDIT, point.x, point.y, this, TRUE);
#endif
}


// CMyTestView 诊断

#ifdef _DEBUG
void CMyTestView::AssertValid() const
{
	CView::AssertValid();
}

void CMyTestView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CMyTestDoc* CMyTestView::GetDocument() const // 非调试版本是内联的
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CMyTestDoc)));
	return (CMyTestDoc*)m_pDocument;
}
#endif //_DEBUG


// CMyTestView 消息处理程序







void CMyTestView::OnMouseMove(UINT nFlags, CPoint point)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值
	CDC*dc = this->GetDC();
	CView::OnMouseMove(nFlags, point);
	if (OK)
	{
		dc->SetROP2(R2_NOT);
		if (tmp)
			draw->BresenhamLine(draw->tmp, tmp, dc, RGB);
		tmp = new CPoint(point);
		draw->BresenhamLine(draw->tmp, &point, dc, RGB);

	}
}


void CMyTestView::OnRButtonDown(UINT nFlags, CPoint point)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值

	CView::OnRButtonDown(nFlags, point);
	draw->BresenhamLine(draw->tmp, &point, this->GetDC(), RGB);
	if (draw->min&&draw->max)
	{
		point.x < draw->min->x ? draw->min->x = point.x : 1;
		point.y < draw->min->y ? draw->min->y = point.y : 1;
		point.x > draw->max->x ? draw->max->x = point.x : 1;
		point.y > draw->max->y ? draw->max->y = point.y : 1;
	}
	draw->tmp = new CPoint(point);
	list->Add((CObject*)draw->tmp);
	CObArray* temp = new CObArray();
	temp->Copy(*list);
	draw->map.Add(temp);
	draw->BresenhamLine(draw->st, &point, this->GetDC(), RGB);
	OK = false;
	draw->st = draw->tmp = nullptr;
	tmp = nullptr;
	OK = false;
	draw->FillRect(this->GetDC(), list);
	list->RemoveAll();
}


void CMyTestView::OnLButtonDown(UINT nFlags, CPoint point)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值
	CView::OnRButtonDown(nFlags, point);
	if (!draw->st)
	{
		OK = true;
		draw->st = new CPoint(point);
		draw->min = new CPoint(point);
		draw->max = new CPoint(point);
	}
	if (tmp)
		draw->BresenhamLine(draw->tmp, &point, this->GetDC(), RGB);
	draw->tmp = new CPoint(point);
	list->Add((CObject*)draw->tmp);
	CClientDC* dc = new CClientDC(this);
	point.x < draw->min->x ? draw->min->x = point.x : 1;
	point.y < draw->min->y ? draw->min->y = point.y : 1;
	point.x > draw->max->x ? draw->max->x = point.x : 1;
	point.y > draw->max->y ? draw->max->y = point.y : 1;
}


void CMyTestView::OnChooseColor()
{


	// TODO: 在此添加命令处理程序代码
	dlg->DoModal();
	RGB = dlg->getRGB();
	this->RedrawWindow();


}


void CMyTestView::OnAndW()
{
	// TODO: 在此添加命令处理程序代码
	wht->DoModal();
	draw->h = wht->GET_H();
	draw->w = wht->GET_W();
	draw->t = wht->GET_T();
	this->RedrawWindow();
}
