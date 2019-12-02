// ChatSocket.cpp : 实现文件
//

#include "stdafx.h"
#include "MFCChatServer.h"
#include "ChatSocket.h"


// CChatSocket

CChatSocket::CChatSocket()
{
}

CChatSocket::~CChatSocket()
{
}


// CChatSocket 成员函数


void CChatSocket::OnReceive(int nErrorCode)
{
	// TODO: 在此添加专用代码和/或调用基类

	CAsyncSocket::OnReceive(nErrorCode);
}
