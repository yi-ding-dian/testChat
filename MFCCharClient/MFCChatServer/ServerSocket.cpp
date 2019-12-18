// ServerSocket.cpp : 实现文件
//

#include "stdafx.h"
#include "MFCChatServer.h"
#include "ServerSocket.h"
#include "MFCChatServerDlg.h"


// CServerSocket

CServerSocket::CServerSocket()
{
}

CServerSocket::~CServerSocket()
{
}


// CServerSocket 成员函数


void CServerSocket::OnAccept(int nErrorCode)
{
	TRACE("###OnAccept");

	CMFCChatServerDlg *dlg = (CMFCChatServerDlg *)AfxGetApp()->GetMainWnd();
	dlg->m_chat = new CChatSocket;
	Accept(*(dlg->m_chat));

	CString str;
	dlg->m_tm = CTime::GetCurrentTime();
	str = dlg->m_tm.Format("%X ");

	str += _T("与客户端连接成功");
	dlg->m_list.AddString(str);
	dlg->m_list.UpdateData(FALSE);//更新数据

	CAsyncSocket::OnAccept(nErrorCode);
}