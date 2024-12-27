
// GlimTestDlg.cpp: 구현 파일
//

#include "pch.h"
#include "framework.h"
#include "GlimTest.h"
#include "GlimTestDlg.h"
#include "afxdialogex.h"


#ifdef _DEBUG
#define new DEBUG_NEW
#endif

// 응용 프로그램 정보에 사용되는 CAboutDlg 대화 상자입니다.
#pragma comment(linker, "/entry:WinMainCRTStartup /subsystem:console")

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


// CGlimTestDlg 대화 상자



CGlimTestDlg::CGlimTestDlg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_GLIMTEST_DIALOG, pParent)

	, m_stX(0)
	, m_stY(0)
	, m_edX(0)
	, m_edY(0)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CGlimTestDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);

	DDX_Text(pDX, IDC_EDIT_STX, m_stX);
	DDX_Text(pDX, IDC_EDIT_STY, m_stY);
	DDX_Text(pDX, IDC_EDIT_ENDX, m_edX);
	DDX_Text(pDX, IDC_EDIT_ENDY, m_edY);
}

BEGIN_MESSAGE_MAP(CGlimTestDlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_WM_DESTROY()
	ON_BN_CLICKED(IDC_BTN_DRAW, &CGlimTestDlg::OnBnClickedBtnDraw)
	ON_BN_CLICKED(IDC_BTN_ACTION, &CGlimTestDlg::OnBnClickedBtnAction)
	ON_BN_CLICKED(IDC_BTN_OPEN, &CGlimTestDlg::OnBnClickedBtnOpen)
END_MESSAGE_MAP()


// CGlimTestDlg 메시지 처리기

#define WINWIDTH 1000
#define WINHEIGHT 600

BOOL CGlimTestDlg::OnInitDialog()
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
	MoveWindow(0, 0, WINWIDTH, WINHEIGHT);

	m_pDlgImage = new CDlgImage;
	m_pDlgImage->Create(IDD_CDlgImage, this);
	m_pDlgImage->ShowWindow(SW_SHOW);

	return TRUE;  // 포커스를 컨트롤에 설정하지 않으면 TRUE를 반환합니다.
}

void CGlimTestDlg::OnSysCommand(UINT nID, LPARAM lParam)
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

void CGlimTestDlg::OnPaint()
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

// 사용자가 최소화된 창을 끄는 동안에 커서가 표시되도록 시스템에서
//  이 함수를 호출합니다.
HCURSOR CGlimTestDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



void CGlimTestDlg::OnDestroy()
{
	CDialogEx::OnDestroy();

	// TODO: 여기에 메시지 처리기 코드를 추가합니다.
	if (m_pDlgImage) delete m_pDlgImage;
}

#include <iostream>
using namespace std;
#define MAX_RADIUS 100
void CGlimTestDlg::OnBnClickedBtnDraw()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	unsigned char* fm = (unsigned char*)m_pDlgImage->m_Image.GetBits();
	int nWidth = m_pDlgImage->m_Image.GetWidth();
	int nHeight = m_pDlgImage->m_Image.GetHeight();
	int nPitch = m_pDlgImage->m_Image.GetPitch();
	
	UpdateData(true);

	if (0 <= m_stX < nWidth && 0 <= m_stY < nHeight) {
		m_pDlgImage->m_nx1 = m_stX;
		m_pDlgImage->m_ny1 = m_stY;
		m_pDlgImage->isDrawBTN = true;
	}

	m_pDlgImage->Invalidate();
	
	UpdateData(false);

}



void CGlimTestDlg::OnBnClickedBtnAction()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	//m_pDlgImage->SttX = m_stX;
	//m_pDlgImage->SttY = m_stY;
	//m_pDlgImage->EndX = m_edX;
	//m_pDlgImage->EndY = m_edY;

	m_pDlgImage->m_Image.Save(_T(".\\image\\test.bmp"));

}


void CGlimTestDlg::OnBnClickedBtnOpen()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.

	m_pDlgImage->m_Image.Load(_T(".\\image\\test.bmp"));
	m_pDlgImage->Invalidate();
}

//void CGlimTestDlg::moveCircle()
//{
//	unsigned char* fm = (unsigned char*)m_pDlgImage->m_Image.GetBits();
//	int nWidth = m_pDlgImage->m_Image.GetWidth();
//	int nHeight = m_pDlgImage->m_Image.GetHeight();
//	int nPitch = m_pDlgImage->m_Image.GetPitch();
//
//	int nRadius = rand() % MAX_RADIUS + 10; //너무 안 보일 경우를 대비해서 +10
//	
//	for (int j = m_stY; j < m_edY; j++) {
//		for (int i = m_stX; j < m_edX; i++) {
//			drawCircle(fm, i, j, nRadius, 0xff);
//		}
//	}
//	m_stX++;
//	m_stY++;
//}
//
//void CGlimTestDlg::drawCircle(unsigned char* fm, int x, int y, int nRadius, int color)
//{
//	int nPitch = m_pDlgImage->m_Image.GetPitch();
//
//	for (int j = y; j < y+nRadius; j++) {
//		for (int i = x; j < x+nRadius; i++) {
//			fm[j * nPitch + i] = color;
//		}
//	}
//}
