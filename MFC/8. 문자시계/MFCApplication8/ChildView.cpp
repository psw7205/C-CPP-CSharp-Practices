
// ChildView.cpp: CChildView 클래스의 구현
//

#include "stdafx.h"
#include "MFCApplication8.h"
#include "ChildView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CChildView

CChildView::CChildView()
{
	m_time = 0;
	m_hour = 0;
	m_min = 0;
	m_sec = 0;

}

CChildView::~CChildView()
{
}


BEGIN_MESSAGE_MAP(CChildView, CWnd)
	ON_WM_PAINT()
	ON_WM_CREATE()
	ON_WM_TIMER()
	ON_COMMAND(ID_BUTTON_H, &CChildView::OnButtonH)
	ON_COMMAND(ID_BUTTON_M, &CChildView::OnButtonM)
	ON_COMMAND(ID_BUTTON_S, &CChildView::OnButtonS)
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

	CFont f;
	f.CreatePointFont(1000, _T("Malgun Gothic"));
	dc.SelectObject(f);

	m_sec = m_time % 60;
	m_min = m_time / 60 % 60;
	m_hour = m_time / 60 / 60 % 60;

	CString str;
	str.Format(_T("%02d : %02d : %02d"), m_hour, m_min, m_sec);
	dc.TextOutW(20, 20, str);
}



int CChildView::OnCreate(LPCREATESTRUCT lpCreateStruct)
{
	if (CWnd::OnCreate(lpCreateStruct) == -1)
		return -1;

	SetTimer(0, 1000, NULL);

	return 0;
}


void CChildView::OnTimer(UINT_PTR nIDEvent)
{
	if (nIDEvent == 0)
	{
		m_time++;
		Invalidate();
	}

	CWnd::OnTimer(nIDEvent);
}


void CChildView::OnButtonH()
{
	m_time += 60*60;
	Invalidate();
}


void CChildView::OnButtonM()
{
	m_time += 60;
	Invalidate();
}


void CChildView::OnButtonS()
{
	m_time++;
	Invalidate();
}
