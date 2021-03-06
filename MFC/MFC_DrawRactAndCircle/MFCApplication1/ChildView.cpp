
// ChildView.cpp: CChildView 클래스의 구현
//

#include "stdafx.h"
#include "MFCApplication1.h"
#include "ChildView.h"
#include "CMyRect.h"
#include "CMyCIrcle.h"

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
	ON_WM_RBUTTONDOWN()
	ON_WM_RBUTTONUP()
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
	
	/*
	CMyRect rect;
	CMyCircle circle;

	rect.m_pt1 = CPoint(100, 100);
	rect.m_pt2 = CPoint(200, 200);
	circle.m_ct = CPoint(300, 300);
	circle.m_r = 100;

	rect.draw(&dc);
	circle.draw(&dc);
	*/

	POSITION pos = m_shapes.GetHeadPosition();

	while (pos != NULL)
	{
		/*
		CMyShape* pShape = m_shapes.GetNext(pos);
		pShape->draw(&dc);
		*/
		m_shapes.GetNext(pos)->draw(&dc);
	}

}

void CChildView::OnLButtonDown(UINT nFlags, CPoint point)
{
	CWnd::OnLButtonDown(nFlags, point);

	m_shapes.AddTail(new CMyRect());
	m_shapes.GetTail()->setPt1(point);
	SetCapture();

	/*
	m_shapes[m_NumShapes] = new CMyRect(); // 이 함수가 끝나도 데이터가 남아있어야 하기에 동적할당함
	m_shapes[m_NumShapes]->setPt1(point);
	m_NumShapes++;
	SetCapture();
	*/
}


void CChildView::OnLButtonUp(UINT nFlags, CPoint point)
{
	CWnd::OnLButtonUp(nFlags, point);

	m_shapes.GetTail()->setPt2(point);
	ReleaseCapture();
	Invalidate();

	/*
	m_shapes[m_NumShapes - 1]->setPt2(point);
	ReleaseCapture();
	Invalidate();
	*/
}


void CChildView::OnRButtonDown(UINT nFlags, CPoint point)
{
	CWnd::OnRButtonDown(nFlags, point);

	m_shapes.AddTail(new CMyCircle());
	m_shapes.GetTail()->setPt1(point);
	SetCapture();

	/*
	m_shapes[m_NumShapes] = new CMyCircle();
	m_shapes[m_NumShapes]->setPt1(point);
	m_NumShapes++;
	SetCapture();
	*/
}


void CChildView::OnRButtonUp(UINT nFlags, CPoint point)
{
	CWnd::OnRButtonUp(nFlags, point);
	
	m_shapes.GetTail()->setPt2(point);
	ReleaseCapture();
	Invalidate();

	/*
	m_shapes[m_NumShapes - 1]->setPt2(point);
	ReleaseCapture();
	Invalidate();
	*/
}


void CChildView::OnMouseMove(UINT nFlags, CPoint point)
{
	CWnd::OnMouseMove(nFlags, point);

	if ((nFlags & MK_LBUTTON) || (nFlags & MK_RBUTTON))
	{
		m_shapes.GetTail()->setPt2(point);
		//m_shapes[m_NumShapes - 1]->setPt2(point);
		Invalidate();
	}
}
