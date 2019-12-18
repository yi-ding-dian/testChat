
// MFCChatServerDlg.h : ͷ�ļ�
//

#pragma once
#include "afxwin.h"
#include "ServerSocket.h"
#include "ChatSocket.h"


// CMFCChatServerDlg �Ի���
class CMFCChatServerDlg : public CDialogEx
{
// ����
public:
	CMFCChatServerDlg(CWnd* pParent = NULL);	// ��׼���캯��

// �Ի�������
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_MFCCHATSERVER_DIALOG };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV ֧��


// ʵ��
protected:
	HICON m_hIcon;

	// ���ɵ���Ϣӳ�亯��
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedStartBtn();

	CServerSocket *m_server;
	CChatSocket *m_chat;

	CListBox m_list;
	CTime m_tm;
	afx_msg void OnBnClickedSendBtn();
};
