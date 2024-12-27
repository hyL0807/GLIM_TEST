// CDlgImage.cpp: 구현 파일
//

#include "pch.h"
#include "GlimTest.h"
#include "afxdialogex.h"
#include "CDlgImage.h"
#include "GlimTestDlg.h"


// CDlgImage 대화 상자

IMPLEMENT_DYNAMIC(CDlgImage, CDialogEx)

CDlgImage::CDlgImage(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_CDlgImage, pParent)
{
	m_pParent = pParent;
}

CDlgImage::~CDlgImage()
{
}

void CDlgImage::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(CDlgImage, CDialogEx)
	ON_WM_PAINT()
END_MESSAGE_MAP()


// CDlgImage 메시지 처리기

#define DLGWIDTH 640
#define DLGHEIGHT 480
BOOL CDlgImage::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// TODO:  여기에 추가 초기화 작업을 추가합니다.

	MoveWindow(0, 0, DLGWIDTH, DLGHEIGHT);
	initImage();

	return TRUE;  // return TRUE unless you set the focus to a control
	// 예외: OCX 속성 페이지는 FALSE를 반환해야 합니다.
}


void CDlgImage::OnPaint()
{
	CPaintDC dc(this); // device context for painting
	// TODO: 여기에 메시지 처리기 코드를 추가합니다.
	// 그리기 메시지에 대해서는 CDialogEx::OnPaint()을(를) 호출하지 마십시오.

	if (m_Image) {
		m_Image.Draw(dc, 0, 0);
	}

	if (isDrawBTN) {
		drawCircle(&dc);
	}

	//if (isActionBTN) {
	//	moveCircle(&dc);
	//}
	//
}

void CDlgImage::initImage()
{
	int nWidth = 640;
	int nHeight = 480;
	int nBpp = 8;

	m_Image.Create(nWidth, -nHeight, nBpp);
	if (nBpp == 8) {
		static RGBQUAD rgb[256];
		for (int i = 0; i < 256; i++) {
			rgb[i].rgbRed = rgb[i].rgbGreen = rgb[i].rgbBlue = i;
		}
		m_Image.SetColorTable(0, 256, rgb);
	}

	int nPitch = m_Image.GetPitch();
	unsigned char* fm = (unsigned char*)m_Image.GetBits();

	memset(fm, 0, nWidth * nHeight);

}

#define MAX_RADIUS 100
void CDlgImage::drawCircle(CDC* pDC)
{
	
	int m_radius = rand() % MAX_RADIUS + 10; //너무 안 보일 경우를 대비해서 +10
	int m_left = m_nx1 - m_radius;
	int m_top = m_ny1 - m_radius;
	int m_right = m_nx1 + m_radius;
	int m_bottom = m_ny1 + m_radius;

	int nPitch = m_Image.GetPitch();
	unsigned char* fm = (unsigned char*)m_Image.GetBits();

	CRect rect(m_left, m_top, m_right, m_bottom);
	pDC->Ellipse(rect);

	for (int j = m_top; j < m_bottom; j++) {
		for (int i = m_left; i < m_right; i++) {
			if (isInCircle(i,j,m_nx1,m_ny1,m_radius))
				fm[j * nPitch + i] = 0;
		}
	}

}

bool CDlgImage::isInCircle(int i, int j, int m_nx1, int m_ny1, int m_radius)
{
	bool bRet = false;

	double dX = i - m_nx1;
	double dY = j - m_ny1;
	double dDist = dX * dX + dY * dY;

	if (dDist < m_radius * m_radius) {
		bRet = true;
	}


	return bRet;
}

//void CDlgImage::moveCircle(CDC* pDC)
//{
//	unsigned char* fm = (unsigned char*)m_Image.GetBits();
//	int nPitch = m_Image.GetPitch();
//
//	while (validImgPos(SttX, SttY)) {
//		for (int j = SttY; j < EndY; j++) {
//			for (int i = SttX; i < EndX; i++) {
//					fm[j * nPitch + i] = 0xff;
//			}	
//		}
//		SttX++;
//		SttY++;
//	}
//	
//}
//
//bool CDlgImage::validImgPos(int x, int y)
//{
//	CRect rect(SttX, SttY, EndX, EndY);
//	
//	return rect.PtInRect(CPoint(x, y));
//}