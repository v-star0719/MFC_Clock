// Clock_.cpp : implementation file
//

#include "stdafx.h"
#include "Clock.h"
#include "ClockCtrl.h"
#include "cmath"

#define PI_ (3.1415926/180)

// CClock

IMPLEMENT_DYNAMIC(CClock, CWnd)

CClock::CClock()
{
	/*CTime time=CTime::GetCurrentTime();
	m_nHour=time.GetHour();
	m_nMinute=time.GetMinute();
	m_nSecond=time.GetSecond();*/
	
	/*m_nHour=0;
	m_nMinute=0;
	m_nSecond=0;*/

	SetCurTime();
}

CClock::~CClock()
{
}


BEGIN_MESSAGE_MAP(CClock, CWnd)
	ON_WM_PAINT()
	ON_WM_TIMER()
END_MESSAGE_MAP()



// CClock message handlers



void CClock::OnPaint()
{
	static int f=1;
	if(f)
	{
		f=0;
		SetTimer(1,1000,NULL);
	}
	CPaintDC dc(this); // device context for painting
	// TODO: Add your message handler code here
	// Do not call CWnd::OnPaint() for painting messages
	CString str;
	str.Format(_T("%.2d:%.2d:%.2d"),m_nHour,m_nMinute,m_nSecond);
	dc.TextOutW(5,5,str);
	CRect rectClient;
	GetClientRect(rectClient);
	
	CRect rectClock;//时钟的所在区域
	int w=rectClient.Width();
	int h=rectClient.Height();
	int sz=0;//时钟所在正方形的边长
	if(w>h) sz=h;//取较小的值
	else sz=w;
	rectClock.top=(h-sz)>>1;
	rectClock.left=(w-sz)>>1;
	rectClock.bottom=rectClock.top+sz;
	rectClock.right=rectClock.left+sz;
	
	CPen pen(PS_SOLID,3,RGB(0,0,0));
	CPen penArrow(PS_SOLID,1,RGB(0,0,0));
	CPen penDot(PS_SOLID,10,RGB(0,0,0));
	CPen* pOldPen=dc.SelectObject(&pen);
	dc.Ellipse(rectClock);
	
	int nOx=w>>1;
	int nOy=h>>1;
	int nPx=0;
	int nPy=0;
	double dL=0;//内圆半径
	int nAlpha;
	
	//时钟上的刻度
	dc.SelectObject(penArrow);
	for(int i=0;i<360;i+=6)
	{
		double dL1=(double)sz/2;
		double dL2=(double)sz*0.9/2;
		CPoint pt1;
		pt1.x=int(nOx+cos(i*PI_)*dL1);
		pt1.y=int(nOy-sin(i*PI_)*dL1);
		CPoint pt2;
		pt2.x=int(nOx+cos(i*PI_)*dL2);
		pt2.y=int(nOy-sin(i*PI_)*dL2);
		dc.MoveTo(pt1);
		dc.LineTo(pt2);
	}
	dc.SelectObject(pen);
	for(int i=0;i<360;i+=30)
	{
		double dL1=(double)sz/2;
		double dL2=(double)sz*0.8/2;
		CPoint pt1;
		pt1.x=int(nOx+cos(i*PI_)*dL1);
		pt1.y=int(nOy-sin(i*PI_)*dL1);
		CPoint pt2;
		pt2.x=int(nOx+cos(i*PI_)*dL2);
		pt2.y=int(nOy-sin(i*PI_)*dL2);
		dc.MoveTo(pt1);
		dc.LineTo(pt2);
	}
	//-------------------------------
	
	//点
	dc.SelectObject(&penDot);
	dc.MoveTo(w/2,h/2);
	dc.LineTo(w/2,h/2);
	//-------------------------------------
	
	//时针
	dc.SelectObject(pen);
	dL=int((double)sz*0.7/2);
	if(m_nHour>12)
		nAlpha=(90-(m_nHour-12)*30-m_nMinute/2);//60分钟走30度
	else
		nAlpha=(90-m_nHour*30-m_nMinute/2);//60分钟走30度
	if(nAlpha>360) nAlpha-=360;
	nPx=int(nOx+cos(nAlpha*PI_)*dL);
	nPy=int(nOy-sin(nAlpha*PI_)*dL);
	dc.MoveTo(nOx,nOy);
	dc.LineTo(nPx,nPy);
	//---------------------------------------
	//分针
	dL=int((double)sz*0.8/2);
	nAlpha=(90-m_nMinute*6-m_nSecond*6/60);//60秒钟走5度
	if(nAlpha>360) nAlpha-=360;
	nPx=int(nOx+cos(nAlpha*PI_)*dL);
	nPy=int(nOy-sin(nAlpha*PI_)*dL);
	dc.MoveTo(nOx,nOy);
	dc.LineTo(nPx,nPy);
	//---------------------------------------
	//秒针
	dc.SelectObject(penArrow);
	dL=int((double)sz*0.9/2);
	nAlpha=(90-m_nSecond*6);//1秒钟走6度
	if(nAlpha>360) nAlpha-=360;
	nPx=int(nOx+cos(nAlpha*PI_)*dL);
	nPy=int(nOy-sin(nAlpha*PI_)*dL);
	dc.MoveTo(nOx,nOy);
	dc.LineTo(nPx,nPy);
	//---------------------------------------
	
	dc.SelectObject(pOldPen);
}
BOOL CClock::Create(CRect rect,CWnd* pParentWnd)
{
	return CWnd::Create(NULL,NULL,WS_CHILD|WS_BORDER|WS_VISIBLE,rect,pParentWnd,0);
}
void CClock::OnTimer(UINT_PTR nIDEvent)
{
	// TODO: Add your message handler code here and/or call default
	/*m_nSecond++;
	if(m_nSecond>=60)
	{
		m_nSecond=0;
		m_nMinute++;
		if(m_nMinute>=60)
		{
			m_nMinute=0;
			m_nHour++;
			if(m_nHour>=24)
				m_nHour=0;
		}
	}*/
	SetCurTime();
	Invalidate();
	CWnd::OnTimer(nIDEvent);
}

void CClock::SetCurTime()
{
	CTime time=CTime::GetCurrentTime();
	m_nHour=time.GetHour();
	m_nMinute=time.GetMinute();
	m_nSecond=time.GetSecond();
}
