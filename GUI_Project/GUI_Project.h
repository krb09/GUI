
// GUI_Project.h : main header file for the PROJECT_NAME application
//

#pragma once

#ifndef __AFXWIN_H__
	#error "include 'stdafx.h' before including this file for PCH"
#endif

#include "resource.h"		// main symbols


// CGUIProjectApp:
// See GUI_Project.cpp for the implementation of this class
//

class CGUIProjectApp : public CWinApp
{
public:
	CGUIProjectApp();

// Overrides
public:
	virtual BOOL InitInstance();

// Implementation

	DECLARE_MESSAGE_MAP()
};

extern CGUIProjectApp theApp;
