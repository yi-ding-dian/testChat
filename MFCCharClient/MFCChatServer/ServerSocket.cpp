// ServerSocket.cpp : ʵ���ļ�
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


// CServerSocket ��Ա����


void CServerSocket::OnAccept(int nErrorCode)
{
	TRACE("###CServerSocket::OnAccept");

	CMFCChatServerDlg *dlg = (CMFCChatServerDlg *)AfxGetApp()->GetMainWnd();
	dlg->m_chat = new CChatSocket;
	Accept(*dlg->m_chat);

	CString str;
	dlg->m_tm = CTime::GetCurrentTime();
	dlg->m_tm.Format("%X ");

	str += _T("��ͻ������ӳɹ�");
	dlg->m_list.AddString(str);
	dlg->m_list.UpdateData(FALSE);//��������

}