
// MFChatServer.h : PROJECT_NAME Ӧ�ó������ͷ�ļ�
//

#pragma once

#ifndef __AFXWIN_H__
	#error "�ڰ������ļ�֮ǰ������stdafx.h�������� PCH �ļ�"
#endif

#include "resource.h"		// ������


// CMFChatServerApp: 
// �йش����ʵ�֣������ MFChatServer.cpp
//

class CMFChatServerApp : public CWinApp
{
public:
	CMFChatServerApp();

// ��д
public:
	virtual BOOL InitInstance();

// ʵ��

	DECLARE_MESSAGE_MAP()
};

extern CMFChatServerApp theApp;