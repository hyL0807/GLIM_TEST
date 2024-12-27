
// GlimTestDlg.h: 헤더 파일
//
#include "CDlgImage.h"
#pragma once


// CGlimTestDlg 대화 상자
class CGlimTestDlg : public CDialogEx
{
// 생성입니다.
public:
	CGlimTestDlg(CWnd* pParent = nullptr);	// 표준 생성자입니다.

	CDlgImage* m_pDlgImage;

// 대화 상자 데이터입니다.
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_GLIMTEST_DIALOG };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV 지원입니다.


// 구현입니다.
protected:
	HICON m_hIcon;

	// 생성된 메시지 맵 함수
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnDestroy();
	afx_msg void OnBnClickedBtnDraw();
	int m_stX;
	int m_stY;
	int m_edX;
	int m_edY;
	afx_msg void OnBnClickedBtnAction();
	afx_msg void OnBnClickedBtnOpen();

	/*void moveCircle();
	void drawCircle(unsigned char* fm, int i, int j, int nRadius, int color);*/
};
