﻿
// MFCApplication6Dlg.cpp: 구현 파일
//

#include "stdafx.h"
#include "MFCApplication6.h"
#include "MFCApplication6Dlg.h"
#include "afxdialogex.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CMFCApplication6Dlg 대화 상자



CMFCApplication6Dlg::CMFCApplication6Dlg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_MFCAPPLICATION6_DIALOG, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CMFCApplication6Dlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CMFCApplication6Dlg, CDialogEx)
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_SLECT_BTN, &CMFCApplication6Dlg::OnBnClickedSlectBtn)
	ON_WM_SIZE()
END_MESSAGE_MAP()


// CMFCApplication6Dlg 메시지 처리기

BOOL CMFCApplication6Dlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// 이 대화 상자의 아이콘을 설정합니다.  응용 프로그램의 주 창이 대화 상자가 아닐 경우에는
	//  프레임워크가 이 작업을 자동으로 수행합니다.
	SetIcon(m_hIcon, TRUE);			// 큰 아이콘을 설정합니다.
	SetIcon(m_hIcon, FALSE);		// 작은 아이콘을 설정합니다.

	// TODO: 여기에 추가 초기화 작업을 추가합니다.

	return TRUE;  // 포커스를 컨트롤에 설정하지 않으면 TRUE를 반환합니다.
}

// 대화 상자에 최소화 단추를 추가할 경우 아이콘을 그리려면
//  아래 코드가 필요합니다.  문서/뷰 모델을 사용하는 MFC 응용 프로그램의 경우에는
//  프레임워크에서 이 작업을 자동으로 수행합니다.

void CMFCApplication6Dlg::OnPaint()
{
	CPaintDC dc(this); // 그리기를 위한 디바이스 컨텍스트입니다.

	if (IsIconic())
	{
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
		if (image.IsNull() == 0) {
			dc.SetStretchBltMode(COLORONCOLOR);
			image.Draw(dc, m_rect);
		}

		// CDialogEx::OnPaint();
	}
}

// 사용자가 최소화된 창을 끄는 동안에 커서가 표시되도록 시스템에서
//  이 함수를 호출합니다.
HCURSOR CMFCApplication6Dlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}

void CMFCApplication6Dlg::OnBnClickedSlectBtn()
{
	wchar_t name_filter[] = L"모든 파일(*.*)|*.*|Jpeg 파일(*.jpg)|*.jpg|PNG 파일(*.png)|*.png||";
	CFileDialog ins_dlg(TRUE, L"jpg", L"*.jpg", OFN_HIDEREADONLY | OFN_NOCHANGEDIR, name_filter);
	ins_dlg.m_ofn.nFilterIndex = 2;

	if (IDOK == ins_dlg.DoModal()) {
		GetClientRect(m_rect);
		if (!image.IsNull()) {
			image.Destroy();
		}
		image.Load(ins_dlg.GetPathName());
		Invalidate(FALSE);
	}
}


void CMFCApplication6Dlg::OnSize(UINT nType, int cx, int cy)
{
	CDialogEx::OnSize(nType, cx, cy);

	//GetClientRect(m_rect);
	m_rect.right = cx;
	m_rect.bottom = cy;

	Invalidate(FALSE);
}
