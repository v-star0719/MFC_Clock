// Clock.h : main header file for the Clock application
//
#pragma once

#ifndef __AFXWIN_H__
	#error "include 'stdafx.h' before including this file for PCH"
#endif

#include "resource.h"       // main symbols


// CClockApp:
// See Clock.cpp for the implementation of this class
//

class CClockApp : public CWinApp
{
public:
	CClockApp();


// Overrides
public:
	virtual BOOL InitInstance();

// Implementation

public:
	afx_msg void OnAppAbout();
	DECLARE_MESSAGE_MAP()
};

extern CClockApp theApp;