
// ChildView.cpp: CChildView 클래스의 구현
//

#include "stdafx.h"
#include "MFC_menu.h"
#include "ChildView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CChildView

CChildView::CChildView()
{
	m_color = RGB(0, 0, 0);
	m_shape = SHAPE::RECTANGLE;
}

CChildView::~CChildView()
{
}


BEGIN_MESSAGE_MAP(CChildView, CWnd)
	ON_WM_PAINT()
	ON_COMMAND(ID_COLOR_RED, &CChildView::OnColorRed)
	ON_COMMAND(ID_COLOR_GREEN, &CChildView::OnColorGreen)
	ON_COMMAND(ID_COLOR_BLUE, &CChildView::OnColorBlue)
	ON_COMMAND(ID_SHAPE_CIRCLE, &CChildView::OnShapeCircle)
	ON_COMMAND(ID_SHAPE_RECTANGLE, &CChildView::OnShapeRectangle)
	ON_UPDATE_COMMAND_UI(ID_COLOR_RED, &CChildView::OnUpdateColorRed)
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

	CBrush brush(m_color);
	dc.SelectObject(brush);
	
	switch(m_shape)
	{
	case RECTANGLE:
		dc.Rectangle(100, 100, 400, 400);
		break;

	case CIRCLE:
		dc.Ellipse(100, 100, 400, 400);
		break;
	}
}


void CChildView::OnColorRed()
{
	m_color = RGB(255, 0, 0);
	Invalidate();
}

void CChildView::OnColorGreen()
{
	m_color = RGB(0, 255, 0);
	Invalidate();
}

void CChildView::OnColorBlue()
{
	m_color = RGB(0, 0, 255);
	Invalidate();
}


void CChildView::OnShapeCircle()
{
	m_shape = SHAPE::CIRCLE;
	Invalidate();
}


void CChildView::OnShapeRectangle()
{
	m_shape = SHAPE::RECTANGLE;
	Invalidate();
}


void CChildView::OnUpdateColorRed(CCmdUI *pCmdUI)
{
	//pCmdUI->Enable(true); // 버튼 활성화
	//pCmdUI->SetCheck(true); // 체크표시
	//pCmdUI->SetText(_T("빨간색")); // 메뉴이름

	if (m_color == RGB(255, 0, 0))
	{
		pCmdUI->SetCheck(true);
		pCmdUI->Enable(false);
		pCmdUI->SetText(_T("이미 빨간색입니다"));
	}
	else
	{
		pCmdUI->Enable(true);
		pCmdUI->SetCheck(false);
		pCmdUI->SetText(_T("Red"));
	}

}
