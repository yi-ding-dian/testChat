
// MFCChatClient.h : PROJECT_NAME Ӧ�ó������ͷ�ļ�
//

#pragma once

#ifndef __AFXWIN_H__
	#error "�ڰ������ļ�֮ǰ������stdafx.h�������� PCH �ļ�"
#endif

#include "resource.h"		// ������


// CMFCChatClientApp: 
// �йش����ʵ�֣������ MFCChatClient.cpp
//

class CMFCChatClientApp : public CWinApp
{
public:
	CMFCChatClientApp();

// ��д
public:
	virtual BOOL InitInstance();

// ʵ��

	DECLARE_MESSAGE_MAP()
};

extern CMFCChatClientApp theApp;