
// ChildView.cpp: CChildView 클래스의 구현
//

#include "stdafx.h"
#include "MFCApplication4.h"
#include "ChildView.h"
#include <cmath>

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
	ON_WM_LBUTTONDOWN()
	ON_WM_LBUTTONUP()
	ON_WM_MOUSEMOVE()
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

	dc.TextOutW(0, 0, _T("16013093 박상우"));

	POSITION pos = m_circle.GetHeadPosition();

	while (pos)
	{
		m_circle.GetNext(pos).draw(&dc);
	}
}



void CChildView::OnLButtonDown(UINT nFlags, CPoint point)
{
	CWnd::OnMButtonDown(nFlags, point);

	m_circle.AddTail(CMyCircle());
	m_circle.GetTail().setPt1(point);

	SetCapture();
}


void CChildView::OnLButtonUp(UINT nFlags, CPoint point)
{
	CWnd::OnMButtonUp(nFlags, point);

	m_circle.GetTail().setPt2(point);
	ReleaseCapture();
	Invalidate();
}


void CChildView::OnMouseMove(UINT nFlags, CPoint point)
{
	CWnd::OnMouseMove(nFlags, point);

	if(nFlags & MK_LBUTTON)
	{
		m_circle.GetTail().setPt2(point);
		Invalidate();
	}
}
