
// MFCChatServer.h : PROJECT_NAME Ӧ�ó������ͷ�ļ�
//

#pragma once

#ifndef __AFXWIN_H__
	#error "�ڰ������ļ�֮ǰ������stdafx.h�������� PCH �ļ�"
#endif

#include "resource.h"		// ������


// CMFCChatServerApp: 
// �йش����ʵ�֣������ MFCChatServer.cpp
//

class CMFCChatServerApp : public CWinApp
{
public:
	CMFCChatServerApp();

// ��д
public:
	virtual BOOL InitInstance();

// ʵ��

	DECLARE_MESSAGE_MAP()
};

extern CMFCChatServerApp theApp;