// ChatSocket.cpp : 实现文件
//

#include "stdafx.h"
#include "MFCChatServer.h"
#include "ChatSocket.h"
#include "MFCChatServerDlg.h"


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
	TRACE("####Server OnReceive");
	CMFCChatServerDlg *dlg = (CMFCChatServerDlg*)AfxGetApp()->GetMainWnd();
	
	char strRecvBuf[200] = { 0 };
	Receive(strRecvBuf, 200, 0);
	TRACE("###strRecvMsg:%s", strRecvBuf);//输出日记

	//2.显示strRecvBuf
	USES_CONVERSION;
	CString strRecvMsg;

	strRecvMsg = A2W(strRecvBuf);
	CString strShow = _T("客户端：");
	CString strTime;
	dlg->m_tm = CTime::GetCurrentTime();
	strTime = dlg->m_tm.Format("%X ");

	strShow += strTime;
	strShow += strRecvMsg;

	dlg->m_list.AddString(strShow);

	CAsyncSocket::OnReceive(nErrorCode);
}
