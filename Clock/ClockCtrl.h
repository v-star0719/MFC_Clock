#pragma once


// CClock

class CClock : public CWnd
{
public:
	int m_nHour;
	int m_nMinute;
	int m_nSecond;

public:
	BOOL Create(CRect rect,CWnd* pParentWnd);
private:
	DECLARE_DYNAMIC(CClock)

public:
	CClock();
	virtual ~CClock();
	void SetCurTime();

protected:
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnPaint();
public:
	afx_msg void OnTimer(UINT_PTR nIDEvent);
};


