
// MyTestView.h: CMyTestView 类的接口
//

#pragma once
#include "MyDraw.h"
#include "MyDlg.h"
#include "WHT.h"
class CMyTestView : public CView
{
protected: // 仅从序列化创建
	CMyTestView();
	DECLARE_DYNCREATE(CMyTestView)
	MyDraw* draw;
	bool OK;
	CPoint* tmp;
	CObArray* list;
	MyDlg* dlg;
	WHT* wht;
	int RGB;
// 特性
public:
	CMyTestDoc* GetDocument() const;

// 操作
public:

// 重写
public:
	virtual void OnDraw(CDC* pDC);  // 重写以绘制该视图
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:

// 实现
public:
	virtual ~CMyTestView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// 生成的消息映射函数
protected:
	afx_msg void OnFilePrintPreview();
	afx_msg void OnRButtonUp(UINT nFlags, CPoint point);
	afx_msg void OnContextMenu(CWnd* pWnd, CPoint point);
	DECLARE_MESSAGE_MAP()
public:

	afx_msg void OnMouseMove(UINT nFlags, CPoint point);
	afx_msg void OnRButtonDown(UINT nFlags, CPoint point);
	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
	afx_msg void OnChooseColor();
	afx_msg void OnAndW();
};

#ifndef _DEBUG  // MyTestView.cpp 中的调试版本
inline CMyTestDoc* CMyTestView::GetDocument() const
   { return reinterpret_cast<CMyTestDoc*>(m_pDocument); }
#endif

