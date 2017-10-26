#include "stdafx.h"
#include "MyDraw.h"
#include <stack>

MyDraw::MyDraw()
{
	st = tmp = nullptr;
	h = 10, w = 5;//高宽
	t = 1;//字符间距
	max = min = nullptr;
}


MyDraw::~MyDraw()
{

}

void MyDraw::BresenhamLine(CPoint* st, CPoint* ed, CDC* dc, int RGB)
{
	if (!st || !ed)
		return;
	int x, y, dx, dy, p;
	int xmin, xmax, ymin, ymax, lx, ly, deltax, deltay;
	dx = ed->x - st->x, dy = ed->y - st->y;
	st->x < ed->x ? (xmin = st->x, xmax = ed->x) : (xmin = ed->x, xmax = st->x);
	st->y < ed->y ? (ymin = st->y, ymax = ed->y) : (ymin = ed->y, ymax = st->y);
	lx = xmax - xmin, ly = ymax - ymin;
	deltax = (dx == 0) ? 0 : ((dx > 0) ? 1 : -1);
	deltay = (dy == 0) ? 0 : ((dy > 0) ? 1 : -1);
	x = st->x, y = st->y;
	if (lx > ly)
	{
		p = 2 * dy - dx;
		for (; x != ed->x; x += deltax)
		{
			dc->SetPixel(x, y, RGB);
			if (p >= 0)
			{
				y += deltay;
				p += 2 * (ly - lx);
			}
			else
			{
				p += 2 * ly;
			}
		}
	}
	else
	{
		p = 2 * dx - dy;
		for (; y != ed->y; y += deltay)
		{
			dc->SetPixel(x, y, RGB);
			if (p >= 0)
			{
				x += deltax;
				p += 2 * (lx - ly);
			}
			else
			{
				p += 2 * lx;
			}
		}
	}
}


void MyDraw::DrawNum(CPoint*st, CDC* dc, int RGB, CObArray* l)
{
	if (h < 5 || w < 5 || t < 0)//高宽小与5或间距小于退出
		return;
	//0
	for (int i = 0; i < w; i++)
	{
		SetPixel(dc, i + st->x, st->y, RGB, l);
		SetPixel(dc, i + st->x, st->y + 1, RGB, l);
		SetPixel(dc, i + st->x, st->y + h - 1, RGB, l);
		SetPixel(dc, i + st->x, st->y + h, RGB, l);
	}
	for (int i = 0; i < h; i++)
	{
		SetPixel(dc, st->x, i + st->y, RGB, l);
		SetPixel(dc, st->x + w, i + st->y, RGB, l);
		SetPixel(dc, st->x + 1, i + st->y, RGB, l);
		SetPixel(dc, st->x + w - 1, i + st->y, RGB, l);
	}
	//7
	for (int i = 0; i < w; i++)
	{
		SetPixel(dc, i + st->x + w + t, st->y, RGB, l);
		SetPixel(dc, i + st->x + w + t, st->y + 1, RGB, l);
	}
	for (int i = 0; i < h; i++)
	{
		SetPixel(dc, st->x + 2 * w + t - 1, i + st->y, RGB, l);
		SetPixel(dc, st->x + 2 * w + t, i + st->y, RGB, l);
	}
	//1
	for (int i = 0; i < h; i++)
	{
		SetPixel(dc, st->x + 3 * w + 2 * t - 1, i + st->y, RGB, l);
		SetPixel(dc, st->x + 3 * w + 2 * t, i + st->y, RGB, l);
	}
	//0
	for (int i = 0; i < w; i++)
	{
		SetPixel(dc, i + st->x + 3 * w + 3 * t, st->y, RGB, l);
		SetPixel(dc, i + st->x + 3 * w + 3 * t, st->y + 1, RGB, l);
		SetPixel(dc, i + st->x + 3 * w + 3 * t, st->y + h - 1, RGB, l);
		SetPixel(dc, i + st->x + 3 * w + 3 * t, st->y + h, RGB, l);
	}
	for (int i = 0; i < h; i++)
	{
		SetPixel(dc, st->x + 3 * w + 3 * t, i + st->y, RGB, l);
		SetPixel(dc, st->x + 4 * w + 3 * t, i + st->y, RGB, l);
		SetPixel(dc, st->x + 3 * w + 3 * t - 1, i + st->y, RGB, l);
		SetPixel(dc, st->x + 4 * w + 3 * t - 1, i + st->y, RGB, l);
	}
}

void MyDraw::FillRect(CDC* dc, CObArray* l)
{
	CPoint* rmax = nullptr, *rmin = nullptr;
	for (int j = 0; j < l->GetSize(); j++)
	{
		if (j == 0)
		{
			rmax = new CPoint(((CPoint*)l->GetAt(0))->x, ((CPoint*)l->GetAt(0))->y);
			rmin = new CPoint(((CPoint*)l->GetAt(0))->x, ((CPoint*)l->GetAt(0))->y);
		}
		CPoint* t = (CPoint*)l->GetAt(j);
		rmax->x < t->x ? rmax->x = t->x : 1;
		rmax->y < t->y ? rmax->y = t->y : 1;
		rmin->x > t->x ? rmin->x = t->x : 1;
		rmin->y > t->y ? rmin->y = t->y : 1;
	}
	if (rmax&&rmin)
	{
		int r = (rmax->y - rmin->y) / (h + t * 2) + 1;
		int c = (rmax->x - rmin->x) / (4 * w + 5 * t) + 1;
		CPoint* st = new CPoint(rmin->x, rmin->y);
		for (int i = 0; i < r; i++)
		{
			st->x = rmin->x;
			for (int j = 0; j < c; j++)
			{
				DrawNum(st, dc, RGB(255, 0, 0), l);
				st->x += (4 * w + 5 * t);
			}
			st->y += (h + t * 2);
		}
	}
}

bool MyDraw::In(int x, int y, CObArray* l)
{
	int i, j;
	bool c = false;
	int size = l->GetSize();
	for (i = 0, j = size - 1; i < size; j = i++) {
		CPoint* p = (CPoint*)l->GetAt(i);
		CPoint* q = (CPoint*)l->GetAt(j);
		if (((p->y > y) != (q->y > y)) && (x < (q->x - p->x) * (y - p->y) / (q->y - p->y) + p->x))
			c = !c;
	}
	return c;
}

void MyDraw::SetPixel(CDC* dc, int x, int y, int RGB, CObArray* l)
{
	if (In(x, y, l))
		dc->SetPixel(x, y, RGB);
}

void MyDraw::ReFill(CDC * dc)
{
	for (int i = 0; i < map.GetSize(); i++)
		FillRect(dc, (CObArray*)map.GetAt(i));
}



