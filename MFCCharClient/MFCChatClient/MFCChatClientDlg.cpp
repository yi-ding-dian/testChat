
// MFCChatClientDlg.cpp : 实现文件
//

#include "stdafx.h"
#include "MFCChatClient.h"
#include "MFCChatClientDlg.h"
#include "afxdialogex.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// 用于应用程序“关于”菜单项的 CAboutDlg 对话框

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_ABOUTBOX };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

// 实现
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


// CMFCChatClientDlg 对话框



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


// CMFCChatClientDlg 消息处理程序

BOOL CMFCChatClientDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// 将“关于...”菜单项添加到系统菜单中。

	// IDM_ABOUTBOX 必须在系统命令范围内。
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

	// 设置此对话框的图标。  当应用程序主窗口不是对话框时，框架将自动
	//  执行此操作
	SetIcon(m_hIcon, TRUE);			// 设置大图标
	SetIcon(m_hIcon, FALSE);		// 设置小图标

	// TODO: 在此添加额外的初始化代码
	GetDlgItem(IDC_PORT_EDIT)->SetWindowText(_T("5000"));//将端口初始化，不用重复输入
	GetDlgItem(IDC_IPADDRESS)->SetWindowText(_T("127.0.0.1"));//将ip初始化，不用重复输入
	

	return TRUE;  // 除非将焦点设置到控件，否则返回 TRUE
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

// 如果向对话框添加最小化按钮，则需要下面的代码
//  来绘制该图标。  对于使用文档/视图模型的 MFC 应用程序，
//  这将由框架自动完成。

void CMFCChatClientDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // 用于绘制的设备上下文

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// 使图标在工作区矩形中居中
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// 绘制图标
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}
}

//当用户拖动最小化窗口时系统调用此函数取得光标
//显示。
HCURSOR CMFCChatClientDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



void CMFCChatClientDlg::OnBnClickedConnectBtn()
{
	// TODO: 在此添加控件通知处理程序代码
	TRACE("###OnBnClickedConnectBtn");
	//把ip地址和端口拿到
	CString strPort, strIp;
	//从控件中获取内容
	GetDlgItem(IDC_PORT_EDIT)->GetWindowText(strPort);
	GetDlgItem(IDC_IPADDRESS)->GetWindowText(strIp);

	//从CString 转化为 char *
	USES_CONVERSION;
	/*
	错误写法,让我卡了两天！！
	LPCTSTR szPort = (LPCTSTR)T2A(strPort);
	LPCTSTR szIp = (LPCTSTR)T2A(strIp);
	*/
	LPCSTR szPort = (LPCSTR)T2A(strPort);
	LPCSTR szIp = (LPCSTR)T2A(strIp);
	
	TRACE("szPort:%s\t szIp:%s", szPort, szIp);
	
	int iPort = _ttoi(strIp);

	//创建一个socket对象
	m_client = new CMySocket;
	//创建套接字，添加容错
	if (!m_client->Create())
	{
		TRACE("m_client create error!error code:%d", GetLastError());
		return;
	}
	//			易错写成szIp---注意！！
	if (m_client->Connect(strIp, iPort) != SOCKET_ERROR)
	{
		//TRACE("m_client Connect error!error code:%d", GetLastError());
		return;
	}

}


void CMFCChatClientDlg::OnBnClickedSendBtn()
{
	// TODO: 在此添加控件通知处理程序代码
	//1.获取编辑框内容
	CString strTmpMsg;
	GetDlgItem(IDC_SENDMSG_EDIT)->GetWindowText(strTmpMsg);

	USES_CONVERSION;
	char *szSendBuf = T2A(strTmpMsg);
	//2.发送给服务端

	m_client->Send(szSendBuf, 200, 0);
	//3.显示到列表框
	CString strShow = _T("我：");
	CString strTime;
	m_tm = CTime::GetCurrentTime();
	strTime = m_tm.Format("%X ");

	strShow += strTime;
	strShow += szSendBuf;

	m_list.AddString(strShow);
	UpdateData(FALSE);
	//清空发送编辑框
	GetDlgItem(IDC_SENDMSG_EDIT)->SetWindowTextW(_T(""));

}
