
// MFCCharClient.h : PROJECT_NAME Ӧ�ó������ͷ�ļ�
//

#pragma once

#ifndef __AFXWIN_H__
	#error "�ڰ������ļ�֮ǰ������stdafx.h�������� PCH �ļ�"
#endif

#include "resource.h"		// ������


// CMFCCharClientApp: 
// �йش����ʵ�֣������ MFCCharClient.cpp
//

class CMFCCharClientApp : public CWinApp
{
public:
	CMFCCharClientApp();

// ��д
public:
	virtual BOOL InitInstance();

// ʵ��

	DECLARE_MESSAGE_MAP()
};

extern CMFCCharClientApp theApp;