// ChatSocket.cpp : ʵ���ļ�
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


// CChatSocket ��Ա����


void CChatSocket::OnReceive(int nErrorCode)
{
	// TODO: �ڴ����ר�ô����/����û���
	TRACE("####Server OnReceive");
	CMFCChatServerDlg *dlg = (CMFCChatServerDlg*)AfxGetApp()->GetMainWnd();
	
	char strRecvBuf[200] = { 0 };
	Receive(strRecvBuf, 200, 0);
	TRACE("###strRecvMsg:%s", strRecvBuf);//����ռ�

	//2.��ʾstrRecvBuf
	USES_CONVERSION;
	CString strRecvMsg;

	strRecvMsg = A2W(strRecvBuf);
	CString strShow = _T("�ͻ��ˣ�");
	CString strTime;
	dlg->m_tm = CTime::GetCurrentTime();
	strTime = dlg->m_tm.Format("%X ");

	strShow += strTime;
	strShow += strRecvMsg;

	dlg->m_list.AddString(strShow);

	CAsyncSocket::OnReceive(nErrorCode);
}
