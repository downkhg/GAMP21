
// MFCRPGSTATUSDlg.cpp: 구현 파일
//

#include "pch.h"
#include "framework.h"
#include "MFCRPGSTATUS.h"
#include "MFCRPGSTATUSDlg.h"
#include "afxdialogex.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// 응용 프로그램 정보에 사용되는 CAboutDlg 대화 상자입니다.

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

// 대화 상자 데이터입니다.
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_ABOUTBOX };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 지원입니다.

// 구현입니다.
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


// CMFCRPGSTATUSDlg 대화 상자



CMFCRPGSTATUSDlg::CMFCRPGSTATUSDlg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_MFCRPGSTATUS_DIALOG, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CMFCRPGSTATUSDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_EDIT_NAME, m_editName);
	DDX_Control(pDX, IDC_COMBO_CLASS, m_comboClass);
	DDX_Control(pDX, IDC_EDIT_HP, m_editHP);
	DDX_Control(pDX, IDC_EDIT_MP, m_editMP);
	DDX_Control(pDX, IDC_EDIT_STR, m_editStr);
	DDX_Control(pDX, IDC_EDIT_INT, m_editInt);
	DDX_Control(pDX, IDC_EDIT_DEF, m_editDef);
	DDX_Control(pDX, IDC_STATIC_BONUS, m_staticBonusPoint);
}

BEGIN_MESSAGE_MAP(CMFCRPGSTATUSDlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_NOTIFY(UDN_DELTAPOS, IDC_SPIN1, &CMFCRPGSTATUSDlg::OnDeltaposSpinHP)
	ON_NOTIFY(UDN_DELTAPOS, IDC_SPIN2, &CMFCRPGSTATUSDlg::OnDeltaposSpinMP)
	ON_NOTIFY(UDN_DELTAPOS, IDC_SPIN3, &CMFCRPGSTATUSDlg::OnDeltaposSpinStr)
	ON_NOTIFY(UDN_DELTAPOS, IDC_SPIN4, &CMFCRPGSTATUSDlg::OnDeltaposSpinInt)
	ON_NOTIFY(UDN_DELTAPOS, IDC_SPIN5, &CMFCRPGSTATUSDlg::OnDeltaposSpinDef)
	ON_CBN_SELCHANGE(IDC_COMBO_CLASS, &CMFCRPGSTATUSDlg::OnCbnSelchangeComboClass)
	ON_BN_CLICKED(ID_BUTTON__RESET, &CMFCRPGSTATUSDlg::OnBnClickedButton)
	ON_BN_CLICKED(IDC_BUTTON_RESULT, &CMFCRPGSTATUSDlg::OnBnClickedButtonResult)
END_MESSAGE_MAP()


// CMFCRPGSTATUSDlg 메시지 처리기

BOOL CMFCRPGSTATUSDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// 시스템 메뉴에 "정보..." 메뉴 항목을 추가합니다.

	// IDM_ABOUTBOX는 시스템 명령 범위에 있어야 합니다.
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != nullptr)
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

	// 이 대화 상자의 아이콘을 설정합니다.  응용 프로그램의 주 창이 대화 상자가 아닐 경우에는
	//  프레임워크가 이 작업을 자동으로 수행합니다.
	SetIcon(m_hIcon, TRUE);			// 큰 아이콘을 설정합니다.
	SetIcon(m_hIcon, FALSE);		// 작은 아이콘을 설정합니다.

	// TODO: 여기에 추가 초기화 작업을 추가합니다.
	m_comboClass.AddString(_T("전사"));
	m_comboClass.AddString(_T("궁수"));
	m_comboClass.AddString(_T("마법사"));

	m_pGameManager = new GameManager();
	m_pGameManager->Init();
	m_nHP = m_pGameManager->GetPlayer()->GetStatus().nHP;

	CString strEdit;
	strEdit.Format(_T("%d"), m_nHP);
	m_editHP.SetWindowTextW(strEdit);

	return TRUE;  // 포커스를 컨트롤에 설정하지 않으면 TRUE를 반환합니다.
}

void CMFCRPGSTATUSDlg::OnSysCommand(UINT nID, LPARAM lParam)
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

// 대화 상자에 최소화 단추를 추가할 경우 아이콘을 그리려면
//  아래 코드가 필요합니다.  문서/뷰 모델을 사용하는 MFC 애플리케이션의 경우에는
//  프레임워크에서 이 작업을 자동으로 수행합니다.

void CMFCRPGSTATUSDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // 그리기를 위한 디바이스 컨텍스트입니다.

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// 클라이언트 사각형에서 아이콘을 가운데에 맞춥니다.
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// 아이콘을 그립니다.
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}
}

void CMFCRPGSTATUSDlg::OnDestroy()
{
	m_pGameManager->Release();
	delete m_pGameManager;
}

// 사용자가 최소화된 창을 끄는 동안에 커서가 표시되도록 시스템에서
//  이 함수를 호출합니다.
HCURSOR CMFCRPGSTATUSDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



void CMFCRPGSTATUSDlg::OnDeltaposSpinHP(NMHDR* pNMHDR, LRESULT* pResult)
{
	LPNMUPDOWN pNMUpDown = reinterpret_cast<LPNMUPDOWN>(pNMHDR);

	if (pNMUpDown->iDelta > 0)
	{
		//m_editHP.SetWindowTextW(_T("Down"));
		m_nHP--;
		m_nBonusPoint++;
	}
	else
	{
		//m_editHP.SetWindowTextW(_T("Up"));
		m_nHP++;
		m_nBonusPoint--;
	}

	CString strEdit;
	strEdit.Format(_T("%d"), m_nHP);
	m_editHP.SetWindowTextW(strEdit);
	strEdit.Format(_T("보너스포인트: %d"), m_nBonusPoint);
	m_staticBonusPoint.SetWindowTextW(strEdit);

	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	*pResult = 0;
}


void CMFCRPGSTATUSDlg::OnDeltaposSpinMP(NMHDR* pNMHDR, LRESULT* pResult)
{
	LPNMUPDOWN pNMUpDown = reinterpret_cast<LPNMUPDOWN>(pNMHDR);
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	*pResult = 0;
}


void CMFCRPGSTATUSDlg::OnDeltaposSpinStr(NMHDR* pNMHDR, LRESULT* pResult)
{
	LPNMUPDOWN pNMUpDown = reinterpret_cast<LPNMUPDOWN>(pNMHDR);
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	*pResult = 0;
}


void CMFCRPGSTATUSDlg::OnDeltaposSpinInt(NMHDR* pNMHDR, LRESULT* pResult)
{
	LPNMUPDOWN pNMUpDown = reinterpret_cast<LPNMUPDOWN>(pNMHDR);
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	*pResult = 0;
}


void CMFCRPGSTATUSDlg::OnDeltaposSpinDef(NMHDR* pNMHDR, LRESULT* pResult)
{
	LPNMUPDOWN pNMUpDown = reinterpret_cast<LPNMUPDOWN>(pNMHDR);
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	*pResult = 0;
}


void CMFCRPGSTATUSDlg::OnCbnSelchangeComboClass()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	int nIdx = m_comboClass.GetCurSel();
	m_comboClass.SetCurSel(nIdx);
	CString strMng;
	m_comboClass.GetWindowTextW(m_strClass);
	m_editName.SetWindowTextW(m_strClass);
}


void CMFCRPGSTATUSDlg::OnBnClickedButton()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	
}


void CMFCRPGSTATUSDlg::OnBnClickedButtonResult()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	Player* pPlayer = m_pGameManager->GetPlayer();
	pPlayer->SetStatus(m_nHP, 0, 0, 0, 0);
}
