
// MFCChatServerDlg.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "MFCChatServer.h"
#include "MFCChatServerDlg.h"
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


// CMFCChatServerDlg �Ի���



CMFCChatServerDlg::CMFCChatServerDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(IDD_MFCCHATSERVER_DIALOG, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CMFCChatServerDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);

	DDX_Control(pDX, IDC_MSG_LIST, m_list);
}

BEGIN_MESSAGE_MAP(CMFCChatServerDlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_START_BTN, &CMFCChatServerDlg::OnBnClickedStartBtn)
	ON_BN_CLICKED(IDC_SEND_BTN, &CMFCChatServerDlg::OnBnClickedSendBtn)
END_MESSAGE_MAP()


// CMFCChatServerDlg ��Ϣ�������

BOOL CMFCChatServerDlg::OnInitDialog()
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
	

	return TRUE;  // ���ǽ��������õ��ؼ������򷵻� TRUE
}

void CMFCChatServerDlg::OnSysCommand(UINT nID, LPARAM lParam)
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

void CMFCChatServerDlg::OnPaint()
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
HCURSOR CMFCChatServerDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



void CMFCChatServerDlg::OnBnClickedStartBtn()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	TRACE("###OnBnClickedStartBtn");
	CString strPort;
	GetDlgItem(IDC_PORT_EDIT)->GetWindowText(strPort);

	// ��CString ת��Ϊ char *
	USES_CONVERSION;
	//����д��LPCTSTR
	LPCSTR szPort = (LPCSTR)T2A(strPort);

	TRACE("szPort:%s", szPort);

	int iPort = _ttoi(strPort);
	//������������Socket����
	m_server = new CServerSocket;
	//����socket
	if (!m_server->Create(iPort))
	{
		TRACE("m_server create error!error code:%d", GetLastError());
		return;
	}
	//�������ӹ���ʱ������OnAccept()
	if (!m_server->Listen())
	{
		TRACE("m_server listen error!error code:%d", GetLastError());
		return;
	}
	CString str;
	m_tm = CTime::GetCurrentTime();
	str = m_tm.Format("%X ");

	str += _T("��������");
	m_list.AddString(str);
	UpdateData(FALSE);
	
}


void CMFCChatServerDlg::OnBnClickedSendBtn()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	//1.��ȡ�༭������
	CString strTmpMsg;
	GetDlgItem(IDC_SEND_EDIT)->GetWindowTextW(strTmpMsg);

	USES_CONVERSION;
	char *szSendBuf = T2A(strTmpMsg);
	//2.���͸��ͻ���
	m_chat->Send(szSendBuf, 200, 0);
	//3.��ʾ���б��
	CString strShow = _T("����ˣ�");
	CString strTime;
	m_tm = CTime::GetCurrentTime();
	strTime = m_tm.Format("%X ");

	strShow += strTime;
	strShow += szSendBuf;

	m_list.AddString(strShow);
	UpdateData(FALSE);
	//��շ��ͱ༭��
	GetDlgItem(IDC_SEND_EDIT)->SetWindowTextW(_T(""));
}
