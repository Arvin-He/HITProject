// SettingDlg.cpp : implementation file
//

#include "stdafx.h"
#include "WJGL.h"
#include "SettingDlg.h"
#include "afxdialogex.h"
#include "dmc3000/inc/LTDMC.h"
#include "global.h"

// CSettingDlg dialog

IMPLEMENT_DYNAMIC(CSettingDlg, CDialogEx)

CSettingDlg::CSettingDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(CSettingDlg::IDD, pParent)
{

}

CSettingDlg::~CSettingDlg()
{
}

void CSettingDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(CSettingDlg, CDialogEx)
	ON_BN_CLICKED(IDC_MODIFY_SOFTLIMIT_BTN, &CSettingDlg::OnClickedModifySoftlimitBtn)
	ON_BN_CLICKED(IDC_APPLY_SOFTLIMIT_BTN, &CSettingDlg::OnClickedApplySoftlimitBtn)
END_MESSAGE_MAP()



void CSettingDlg::OnClickedModifySoftlimitBtn()
{
	// TODO: Add your control notification handler code here
	 UpdateData(TRUE);
	 SetSoftLimitReadOnly(IDC_STAGE_EL_UP_X_EDIT, FALSE);
	 SetSoftLimitReadOnly(IDC_STAGE_EL_DOWN_X_EDIT,FALSE);
	 SetSoftLimitReadOnly(IDC_STAGE_EL_UP_Y_EDIT, FALSE);
	 SetSoftLimitReadOnly(IDC_STAGE_EL_DOWN_Y_EDIT, FALSE);
	 UpdateData(FALSE);
}

void CSettingDlg::SetSoftLimitReadOnly(int nID, BOOL modifiable)
{
	CEdit* pEdit = (CEdit*)GetDlgItem(nID);
	pEdit-> SetReadOnly(modifiable);
}

void CSettingDlg::OnClickedApplySoftlimitBtn()
{
	// TODO: Add your control notification handler code here
	UpdateData(TRUE);
	g_softLimitParamStruct.nStageELUpX = GetDlgItemInt(IDC_STAGE_EL_UP_X_EDIT);
	g_softLimitParamStruct.nStageELDownX = GetDlgItemInt(IDC_STAGE_X_EL_DOWN);
	g_softLimitParamStruct.nStageELUpY = GetDlgItemInt(IDC_STAGE_EL_UP_Y_EDIT);
	g_softLimitParamStruct.nStageELDownY = GetDlgItemInt(IDC_STAGE_Y_EL_DOWN);
	SetSoftLimit();
	SetSoftLimitReadOnly(IDC_STAGE_EL_UP_X_EDIT, TRUE);
	SetSoftLimitReadOnly(IDC_STAGE_EL_DOWN_X_EDIT, TRUE);
	SetSoftLimitReadOnly(IDC_STAGE_EL_UP_Y_EDIT, TRUE);
	SetSoftLimitReadOnly(IDC_STAGE_EL_DOWN_Y_EDIT, TRUE);
	UpdateData(FALSE);
}


BOOL CSettingDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();
	// TODO:  Add extra initialization here
	SetDlgItemInt(IDC_STAGE_EL_UP_X_EDIT, g_softLimitParamStruct.nStageELUpX);
	SetDlgItemInt(IDC_STAGE_EL_DOWN_X_EDIT, g_softLimitParamStruct.nStageELDownX);
	SetDlgItemInt(IDC_STAGE_EL_UP_Y_EDIT, g_softLimitParamStruct.nStageELUpY);
	SetDlgItemInt(IDC_STAGE_EL_DOWN_Y_EDIT, g_softLimitParamStruct.nStageELDownY);
	return TRUE;  // return TRUE unless you set the focus to a control
	// EXCEPTION: OCX Property Pages should return FALSE
}


void CSettingDlg::SetSoftLimit()
{
	dmc_set_softlimit(g_nCardNo, 0, 1, 1, 0, g_softLimitParamStruct.nStageELDownX, g_softLimitParamStruct.nStageELUpX);
	dmc_set_softlimit(g_nCardNo, 1, 1, 1, 0, g_softLimitParamStruct.nStageELDownY, g_softLimitParamStruct.nStageELUpY);
}

void CSettingDlg::GetSoftLimit()
{
// 	dmc_get_softlimit(g_nCardNo, 0, 1, 1, 0, g_softLimitParamStruct.nStageELDownX, g_softLimitParamStruct.nStageELUpX);
// 	dmc_get_softlimit(g_nCardNo, 1, 1, 1, 0, g_softLimitParamStruct.nStageELDownY, g_softLimitParamStruct.nStageELUpY);
}