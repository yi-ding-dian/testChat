// ChatSocket.cpp : ʵ���ļ�
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


// CChatSocket ��Ա����


void CChatSocket::OnReceive(int nErrorCode)
{
	// TODO: �ڴ����ר�ô����/����û���

	CAsyncSocket::OnReceive(nErrorCode);
}
