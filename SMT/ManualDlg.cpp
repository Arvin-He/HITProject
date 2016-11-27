// ManualDlg.cpp : implementation file
//

#include "stdafx.h"
#include "SMT.h"
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
		DMC3000_Move(0, 0, TransDistanceToPulse(0, m_stageStep), 1, 0);
		break;
	case  IDC_STAGE_XDOWN_BTN:
		DMC3000_Move(0, 0, TransDistanceToPulse(1, m_stageStep), -1, 0);
		break;
	case IDC_STAGE_YUP_BTN:
		DMC3000_Move(0, 1, TransDistanceToPulse(2, m_stageStep), 1, 0);
		break;
	case  IDC_STAGE_YDOWN_BTN:
		DMC3000_Move(0, 1, TransDistanceToPulse(3, m_stageStep), -1, 0);
		break;
	default:
		break;
	}
	UpdateData(FALSE);
	return TRUE;
}

// ��װdmc�˶�����:����, ���, ������, �˶�����, �˶�ģʽ
void CManualDlg::DMC3000_Move(int nCardNo, int nAxisIndex, int nPulse, int nDirection, int nMoveMode)
{
	if (dmc_check_done(nCardNo, nAxisIndex) == 0) //�Ѿ����˶���
		return; 
	// ���õ����˶��ٶ�����, m_nSpeedMin
	dmc_set_profile(nCardNo, nAxisIndex, 100, 1000, 0.02, 0.02, 100);
	//�趨S��ʱ��
	dmc_set_s_profile(nCardNo, nAxisIndex, 0, 0.2); //S ��ʱ�䣬��λ��s����Χ��0~0.5 s
	//�㶯(λ��ģʽ)
	dmc_pmove(nCardNo, nAxisIndex, nPulse*nDirection, nMoveMode);  //����0��ʾ����˶�
}