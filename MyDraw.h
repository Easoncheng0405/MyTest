#pragma once
class MyDraw
{
public:
	MyDraw();
	~MyDraw();
	void BresenhamLine(CPoint* st, CPoint* ed, CDC* dc, int RGB);
	void DrawNum(CPoint* st, CDC* dc, int RGB, CObArray* l);
	void FillRect(CDC* dc, CObArray* l);
	bool In(int x, int y, CObArray* l);
	void SetPixel(CDC* dc, int x, int y, int RGB, CObArray* l);
	void ReFill(CDC* dc);
public:
	CObArray map;
	CPoint* st, *tmp;
	CPoint* min, *max;
	int w, h;//×Ö·û¿í¸ß
	int t;//×Ö·û¼ä¾à
};
