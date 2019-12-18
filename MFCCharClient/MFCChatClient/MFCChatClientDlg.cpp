
// MFCChatClientDlg.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "MFCChatClient.h"
#include "MFCChatClientDlg.h"
#include "afxdialogex.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// ����Ӧ�ó��򡰹��ڡ��˵���� CAboutDlg �Ի���

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

// �Ի�������
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_ABOUTBOX };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

// ʵ��
protected:
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialogEx(IDD_ABOUTBOX)
{
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialogEx)
END_MESSAGE_MAP()


// CMFCChatClientDlg �Ի���



CMFCChatClientDlg::CMFCChatClientDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(IDD_MFCCHATCLIENT_DIALOG, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CMFCChatClientDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);

	DDX_Control(pDX, IDC_SENDMSG_EDIT, m_input);
	DDX_Control(pDX, IDC_MSG_LIST, m_list);
}

BEGIN_MESSAGE_MAP(CMFCChatClientDlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_CONNECT_BTN, &CMFCChatClientDlg::OnBnClickedConnectBtn)
	ON_BN_CLICKED(IDC_SEND_BTN, &CMFCChatClientDlg::OnBnClickedSendBtn)
END_MESSAGE_MAP()


// CMFCChatClientDlg ��Ϣ�������

BOOL CMFCChatClientDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// ��������...���˵�����ӵ�ϵͳ�˵��С�

	// IDM_ABOUTBOX ������ϵͳ���Χ�ڡ�
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != NULL)
	{
		BOOL bNameValid;
		CString strAboutMenu;
		bNameValid = strAboutMenu.LoadString(IDS_ABOUTBOX);
		ASSERT(bNameValid);
		if (!strAboutMenu.IsEmpty())
		{
			pSysMenu->AppendMenu(MF_SEPARATOR);
			pSysMenu->AppendMenu(MF_STRING, IDM_ABOUTBOX, strAboutMenu);
		}
	}

	// ���ô˶Ի����ͼ�ꡣ  ��Ӧ�ó��������ڲ��ǶԻ���ʱ����ܽ��Զ�
	//  ִ�д˲���
	SetIcon(m_hIcon, TRUE);			// ���ô�ͼ��
	SetIcon(m_hIcon, FALSE);		// ����Сͼ��

	// TODO: �ڴ���Ӷ���ĳ�ʼ������
	GetDlgItem(IDC_PORT_EDIT)->SetWindowText(_T("5000"));//���˿ڳ�ʼ���������ظ�����
	GetDlgItem(IDC_IPADDRESS)->SetWindowText(_T("127.0.0.1"));//��ip��ʼ���������ظ�����
	

	return TRUE;  // ���ǽ��������õ��ؼ������򷵻� TRUE
}

void CMFCChatClientDlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	if ((nID & 0xFFF0) == IDM_ABOUTBOX)
	{
		CAboutDlg dlgAbout;
		dlgAbout.DoModal();
	}
	else
	{
		CDialogEx::OnSysCommand(nID, lParam);
	}
}

// �����Ի��������С����ť������Ҫ����Ĵ���
//  �����Ƹ�ͼ�ꡣ  ����ʹ���ĵ�/��ͼģ�͵� MFC Ӧ�ó���
//  �⽫�ɿ���Զ���ɡ�

void CMFCChatClientDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // ���ڻ��Ƶ��豸������

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// ʹͼ���ڹ����������о���
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// ����ͼ��
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}
}

//���û��϶���С������ʱϵͳ���ô˺���ȡ�ù��
//��ʾ��
HCURSOR CMFCChatClientDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



void CMFCChatClientDlg::OnBnClickedConnectBtn()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	TRACE("###OnBnClickedConnectBtn");
	//��ip��ַ�Ͷ˿��õ�
	CString strPort, strIp;
	//�ӿؼ��л�ȡ����
	GetDlgItem(IDC_PORT_EDIT)->GetWindowText(strPort);
	GetDlgItem(IDC_IPADDRESS)->GetWindowText(strIp);

	//��CString ת��Ϊ char *
	USES_CONVERSION;
	/*
	����д��,���ҿ������죡��
	LPCTSTR szPort = (LPCTSTR)T2A(strPort);
	LPCTSTR szIp = (LPCTSTR)T2A(strIp);
	*/
	LPCSTR szPort = (LPCSTR)T2A(strPort);
	LPCSTR szIp = (LPCSTR)T2A(strIp);
	
	TRACE("szPort:%s\t szIp:%s", szPort, szIp);
	
	int iPort = _ttoi(strIp);

	//����һ��socket����
	m_client = new CMySocket;
	//�����׽��֣�����ݴ�
	if (!m_client->Create())
	{
		TRACE("m_client create error!error code:%d", GetLastError());
		return;
	}
	//			�״�д��szIp---ע�⣡��
	if (m_client->Connect(strIp, iPort) != SOCKET_ERROR)
	{
		//TRACE("m_client Connect error!error code:%d", GetLastError());
		return;
	}

}


void CMFCChatClientDlg::OnBnClickedSendBtn()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	//1.��ȡ�༭������
	CString strTmpMsg;
	GetDlgItem(IDC_SENDMSG_EDIT)->GetWindowText(strTmpMsg);

	USES_CONVERSION;
	char *szSendBuf = T2A(strTmpMsg);
	//2.���͸������

	m_client->Send(szSendBuf, 200, 0);
	//3.��ʾ���б��
	CString strShow = _T("�ң�");
	CString strTime;
	m_tm = CTime::GetCurrentTime();
	strTime = m_tm.Format("%X ");

	strShow += strTime;
	strShow += szSendBuf;

	m_list.AddString(strShow);
	UpdateData(FALSE);
	//��շ��ͱ༭��
	GetDlgItem(IDC_SENDMSG_EDIT)->SetWindowTextW(_T(""));

}
