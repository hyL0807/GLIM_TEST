#pragma once
#include "afxdialogex.h"


// CDlgImage 대화 상자

class CDlgImage : public CDialogEx
{
	DECLARE_DYNAMIC(CDlgImage)

public:
	CDlgImage(CWnd* pParent = nullptr);   // 표준 생성자입니다.
	virtual ~CDlgImage();

	CImage m_Image;
	CWnd* m_pParent;

// 대화 상자 데이터입니다.
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_CDlgImage };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 지원입니다.

	DECLARE_MESSAGE_MAP()
public:
	virtual BOOL OnInitDialog();
	afx_msg void OnPaint();

	void initImage();
	void drawCircle(CDC* pDC);
	int m_nx1;
	int m_ny1;

	bool isDrawBTN = false;
	bool isActionBTN = false;

	bool isInCircle(int i, int j, int m_nx1, int m_ny1, int m_radius);

	//void moveCircle(CDC* pDC);

	//static int SttX;
	//static int SttY;
	//int EndX;
	//int EndY;

	//bool validImgPos(int x, int y);
};
