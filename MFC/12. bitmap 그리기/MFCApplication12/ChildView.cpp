
// ChildView.cpp: CChildView 클래스의 구현
//

#include "stdafx.h"
#include "MFCApplication12.h"
#include "ChildView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CChildView

CChildView::CChildView()
{
}

CChildView::~CChildView()
{
}


BEGIN_MESSAGE_MAP(CChildView, CWnd)
	ON_WM_PAINT()
END_MESSAGE_MAP()



// CChildView 메시지 처리기

BOOL CChildView::PreCreateWindow(CREATESTRUCT& cs) 
{
	if (!CWnd::PreCreateWindow(cs))
		return FALSE;

	cs.dwExStyle |= WS_EX_CLIENTEDGE;
	cs.style &= ~WS_BORDER;
	cs.lpszClass = AfxRegisterWndClass(CS_HREDRAW|CS_VREDRAW|CS_DBLCLKS, 
		::LoadCursor(nullptr, IDC_ARROW), reinterpret_cast<HBRUSH>(COLOR_WINDOW+1), nullptr);

	return TRUE;
}

void CChildView::OnPaint() 
{
	CPaintDC dc(this);

	CBitmap bit;
	bit.LoadBitmapW(IDB_BITMAP1);

	BITMAP bitinfo;
	bit.GetBitmap(&bitinfo);

	CDC memDC;
	memDC.CreateCompatibleDC(&dc);
	memDC.SelectObject(&bit);

	CRect clientRect;
	GetClientRect(&clientRect);

	CPoint c = clientRect.CenterPoint();

	int w = clientRect.Width();
	int h = clientRect.Height();
	
	int rw, rh;

	double bmpRate = bitinfo.bmWidth / (double)bitinfo.bmHeight;
	double clientRate = w / (double)h;

	if (bmpRate < clientRate)
	{
		rh = h;
		rw = h * bmpRate;
	}
	else
	{
		rw = w;
		rh = w / bmpRate;
	}

	CRect rect;
	rect.SetRect(c.x - rw / 2, c.y - rh / 2, c.x + rw / 2, c.y + rh / 2);
	
	dc.StretchBlt(c.x - rw / 2, c.y - rh / 2, rw, rh, &memDC, 0, 0, bitinfo.bmWidth, bitinfo.bmHeight, SRCCOPY);
}

