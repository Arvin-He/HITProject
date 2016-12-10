// ManualDlg.cpp : implementation file
//

#include "stdafx.h"
#include "WJGL.h"
#include "ManualDlg.h"
#include "afxdialogex.h"
#include "dmc3000/inc/LTDMC.h"
#include "global.h"

// CManualDlg dialog

IMPLEMENT_DYNAMIC(CManualDlg, CDialogEx)

CManualDlg::CManualDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(CManualDlg::IDD, pParent)
	, m_stageStep(1000)
{

}

CManualDlg::~CManualDlg()
{
}

void CManualDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_STAGE_STEP_EDIT, m_stageStep);
	DDV_MinMaxInt(pDX, m_stageStep, 0, 100000);
}


BEGIN_MESSAGE_MAP(CManualDlg, CDialogEx)
	ON_COMMAND_EX(IDC_STAGE_XUP_BTN, OnStageMove)
	ON_COMMAND_EX(IDC_STAGE_XDOWN_BTN, OnStageMove)
	ON_COMMAND_EX(IDC_STAGE_YUP_BTN, OnStageMove)
	ON_COMMAND_EX(IDC_STAGE_YDOWN_BTN, OnStageMove)
END_MESSAGE_MAP()


// CManualDlg message handlers
BOOL CManualDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();
	// TODO:  Add extra initialization here
	

	return TRUE;  // return TRUE unless you set the focus to a control
	// EXCEPTION: OCX Property Pages should return FALSE
}

BOOL CManualDlg::OnStageMove(UINT nID)
{
	UpdateData(TRUE);
	switch(nID)
	{
	case IDC_STAGE_XUP_BTN:
		{
			SetMotionParam(0);
			DMC3000_Move(g_nCardNo, 0, TransDistanceToPulse(0, m_stageStep), 1, 0);
		}
		break;
	case  IDC_STAGE_XDOWN_BTN:
		{
			SetMotionParam(0);
			DMC3000_Move(g_nCardNo, 0, TransDistanceToPulse(0, m_stageStep), -1, 0);
		}
		break;
	case IDC_STAGE_YUP_BTN:
		{
			SetMotionParam(1);
			DMC3000_Move(g_nCardNo, 1, TransDistanceToPulse(1, m_stageStep), 1, 0);
		}
		break;
	case  IDC_STAGE_YDOWN_BTN:
		{
			SetMotionParam(1);
			DMC3000_Move(g_nCardNo, 1, TransDistanceToPulse(1, m_stageStep), -1, 0);
		}
		break;
	default:
		break;
	}
	UpdateData(FALSE);
	return TRUE;
}
