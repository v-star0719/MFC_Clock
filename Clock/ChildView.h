// ChildView.h : interface of the CChildView class
//
#include "ClockCtrl.h"

#pragma once


// CChildView window

class CChildView : public CWnd
{
public:
	CClock m_clock;
// Construction
public:
	CChildView();

// Attributes
public:

// Operations
public:

// Overrides
	protected:
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);

// Implementation
public:
	virtual ~CChildView();

	// Generated message map functions
protected:
	afx_msg void OnPaint();
	DECLARE_MESSAGE_MAP()
public:
	afx_msg int OnCreate(LPCREATESTRUCT lpCreateStruct);
public:
	afx_msg void OnTimer(UINT_PTR nIDEvent);
};

