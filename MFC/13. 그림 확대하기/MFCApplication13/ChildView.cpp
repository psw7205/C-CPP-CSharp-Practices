
// ChildView.cpp: CChildView 클래스의 구현
//

#include "stdafx.h"
#include "MFCApplication13.h"
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
	ON_WM_MOUSEMOVE()
	ON_WM_LBUTTONDOWN()
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

	CBitmap bmp;
	bmp.LoadBitmapW(IDB_BITMAP1);
	
	BITMAP bmpInfo;
	bmp.GetBitmap(&bmpInfo);

	CDC memDC;
	memDC.CreateCompatibleDC(&dc);
	memDC.SelectObject(&bmp);

	m_dc.x = bmpInfo.bmWidth;
	m_dc.y = bmpInfo.bmHeight;
	dc.BitBlt(0, 0, m_dc.x, m_dc.y, &memDC, 0, 0, SRCCOPY);

	dc.Rectangle(m_dc.x, 0, m_dc.x + 300, 300);

	dc.SelectStockObject(NULL_BRUSH);

	CPen pen(PS_SOLID, 3, RGB(255, 0, 0));
	dc.SelectObject(pen);
	CRect rect(m_mpt.x, m_mpt.y, m_mpt.x + 100, m_mpt.y + 100);
	dc.Rectangle(rect);

	dc.StretchBlt(m_dc.x, 0, 300, 300, &memDC, m_mpt.x, m_mpt.y, 100, 100, SRCCOPY);
}



void CChildView::OnMouseMove(UINT nFlags, CPoint point)
{
	if (nFlags & MK_LBUTTON)
	{
		CRect r(0, 0, m_dc.x-100, m_dc.y-100);

		if (r.PtInRect(point))
		{
			m_mpt = point;
			ReleaseCapture();
			Invalidate();
		}
	}
	CWnd::OnMouseMove(nFlags, point);
}


void CChildView::OnLButtonDown(UINT nFlags, CPoint point)
{
	CRect r(0, 0, m_dc.x - 100, m_dc.y - 100);

	if (r.PtInRect(point))
		SetCapture();

	CWnd::OnLButtonDown(nFlags, point);
}
