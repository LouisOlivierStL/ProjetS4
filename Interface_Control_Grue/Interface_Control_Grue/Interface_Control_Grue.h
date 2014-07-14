
// Interface_Control_Grue.h : main header file for the PROJECT_NAME application
//

#pragma once

#ifndef __AFXWIN_H__
	#error "include 'stdafx.h' before including this file for PCH"
#endif

#include "resource.h"		// main symbols


// CInterface_Control_GrueApp:
// See Interface_Control_Grue.cpp for the implementation of this class
//

class CInterface_Control_GrueApp : public CWinApp
{
public:
	CInterface_Control_GrueApp();

// Overrides
public:
	virtual BOOL InitInstance();

// Implementation

	DECLARE_MESSAGE_MAP()
};

extern CInterface_Control_GrueApp theApp;