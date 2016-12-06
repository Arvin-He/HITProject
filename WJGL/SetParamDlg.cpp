// SetParamDlg.cpp : implementation file
//

#include "stdafx.h"
#include "WJGL.h"
#include "SetParamDlg.h"
#include "afxdialogex.h"
#include "global.h"

// CSetParamDlg dialog

IMPLEMENT_DYNAMIC(CSetParamDlg, CDialogEx)

CSetParamDlg::CSetParamDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(CSetParamDlg::IDD, pParent)
{

}

CSetParamDlg::~CSetParamDlg()
{
}

void CSetParamDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(CSetParamDlg, CDialogEx)
	ON_BN_CLICKED(IDC_MODIFY_MOTION_PARAM_BTN, &CSetParamDlg::OnBnClickedModifyMotionParamBtn)
	ON_BN_CLICKED(IDC_APPLY_MOTION_PARAM_BTN, &CSetParamDlg::OnBnClickedApplyMotionParamBtn)
END_MESSAGE_MAP()


// CSetParamDlg message handlers


BOOL CSetParamDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// TODO:  Add extra initialization here
	InitMotionParam();
	return TRUE;  // return TRUE unless you set the focus to a control
	// EXCEPTION: OCX Property Pages should return FALSE
}

void CSetParamDlg::InitMotionParam()
{
	CString str("");
	str.Format("%d", g_stageXAxisParamStruct.nStartSpeed);
	SetDlgItemText(IDC_STAGE_START_SPEED_X, str);
	str.Format("%d", g_stageXAxisParamStruct.nRunSpeed);
	SetDlgItemText(IDC_STAGE_RUN_SPEED_X, str);
	str.Format("%d", g_stageXAxisParamStruct.nEndSpeed);
	SetDlgItemText(IDC_STAGE_END_SPEED_X, str);
	str.Format("%.3f", g_stageXAxisParamStruct.nAccelerateTime);
	SetDlgItemText(IDC_STAGE_ACC_TIME_X, str);
	str.Format("%.3f", g_stageXAxisParamStruct.nDecelerateTime);
	SetDlgItemText(IDC_STAGE_DEC_TIME_X, str);
	str.Format("%.3f", g_stageXAxisParamStruct.nSDecelerateTime);
	SetDlgItemText(IDC_STAGE_S_TIME_X, str);

	str.Format("%d", g_stageYAxisParamStruct.nStartSpeed);
	SetDlgItemText(IDC_STAGE_START_SPEED_Y, str);
	str.Format("%d", g_stageYAxisParamStruct.nRunSpeed);
	SetDlgItemText(IDC_STAGE_RUN_SPEED_Y, str);
	str.Format("%d", g_stageYAxisParamStruct.nEndSpeed);
	SetDlgItemText(IDC_STAGE_END_SPEED_Y, str);
	str.Format("%.3f", g_stageYAxisParamStruct.nAccelerateTime);
	SetDlgItemText(IDC_STAGE_ACC_TIME_Y, str);
	str.Format("%.3f", g_stageYAxisParamStruct.nDecelerateTime);
	SetDlgItemText(IDC_STAGE_DEC_TIME_Y, str);
	str.Format("%.3f", g_stageYAxisParamStruct.nSDecelerateTime);
	SetDlgItemText(IDC_STAGE_S_TIME_Y, str);
}

void CSetParamDlg::SetMotionParamModifiable(int nID, BOOL modifiable)
{
	CEdit* pEdit = (CEdit*)GetDlgItem(nID);
	pEdit-> SetReadOnly(modifiable);
}

void CSetParamDlg::OnBnClickedModifyMotionParamBtn()
{
	// TODO: Add your control notification handler code here
	UpdateData(TRUE);
	SetMotionParamModifiable(IDC_STAGE_START_SPEED_X, FALSE);
	SetMotionParamModifiable(IDC_STAGE_START_SPEED_Y,FALSE);
	SetMotionParamModifiable(IDC_STAGE_RUN_SPEED_X, FALSE);
	SetMotionParamModifiable(IDC_STAGE_RUN_SPEED_Y, FALSE);
	SetMotionParamModifiable(IDC_STAGE_END_SPEED_X, FALSE);
	SetMotionParamModifiable(IDC_STAGE_END_SPEED_Y, FALSE);
	SetMotionParamModifiable(IDC_STAGE_ACC_TIME_X, FALSE);
	SetMotionParamModifiable(IDC_STAGE_ACC_TIME_Y, FALSE);
	SetMotionParamModifiable(IDC_STAGE_DEC_TIME_X, FALSE);
	SetMotionParamModifiable(IDC_STAGE_DEC_TIME_Y, FALSE);
	SetMotionParamModifiable(IDC_STAGE_S_TIME_X, FALSE);
	SetMotionParamModifiable(IDC_STAGE_S_TIME_Y, FALSE);
	UpdateData(FALSE);

}

void CSetParamDlg::OnBnClickedApplyMotionParamBtn()
{
	// TODO: Add your control notification handler code here
	CString tempText="";
	//char tempText[20];
	g_stageXAxisParamStruct.nStartSpeed = GetDlgItemInt(IDC_STAGE_START_SPEED_X);
	g_stageXAxisParamStruct.nRunSpeed = GetDlgItemInt(IDC_STAGE_RUN_SPEED_X);
	g_stageXAxisParamStruct.nEndSpeed = GetDlgItemInt(IDC_STAGE_END_SPEED_X);
	GetDlgItem(IDC_STAGE_ACC_TIME_X)->GetWindowText(tempText);
	g_stageXAxisParamStruct.nAccelerateTime = atof(tempText);
	GetDlgItem(IDC_STAGE_DEC_TIME_X)->GetWindowText(tempText);
	g_stageXAxisParamStruct.nDecelerateTime = atof(tempText);
	GetDlgItem(IDC_STAGE_S_TIME_X)->GetWindowText(tempText);
	g_stageXAxisParamStruct.nSDecelerateTime = atof(tempText);

	g_stageYAxisParamStruct.nStartSpeed = GetDlgItemInt(IDC_STAGE_START_SPEED_Y);
	g_stageYAxisParamStruct.nRunSpeed = GetDlgItemInt(IDC_STAGE_RUN_SPEED_Y);
	g_stageYAxisParamStruct.nEndSpeed = GetDlgItemInt(IDC_STAGE_END_SPEED_Y);
	GetDlgItem(IDC_STAGE_ACC_TIME_Y)->GetWindowText(tempText);
	g_stageYAxisParamStruct.nAccelerateTime = atof(tempText);
	GetDlgItem(IDC_STAGE_DEC_TIME_Y)->GetWindowText(tempText);
	g_stageYAxisParamStruct.nDecelerateTime = atof(tempText);
	GetDlgItem(IDC_STAGE_S_TIME_Y)->GetWindowText(tempText);
	g_stageYAxisParamStruct.nSDecelerateTime = atof(tempText);
	UpdateData(TRUE);
	SetMotionParamModifiable(IDC_STAGE_START_SPEED_X, TRUE);
	SetMotionParamModifiable(IDC_STAGE_START_SPEED_Y,TRUE);
	SetMotionParamModifiable(IDC_STAGE_RUN_SPEED_X, TRUE);
	SetMotionParamModifiable(IDC_STAGE_RUN_SPEED_Y, TRUE);
	SetMotionParamModifiable(IDC_STAGE_END_SPEED_X, TRUE);
	SetMotionParamModifiable(IDC_STAGE_END_SPEED_Y, TRUE);
	SetMotionParamModifiable(IDC_STAGE_ACC_TIME_X, TRUE);
	SetMotionParamModifiable(IDC_STAGE_ACC_TIME_Y, TRUE);
	SetMotionParamModifiable(IDC_STAGE_DEC_TIME_X, TRUE);
	SetMotionParamModifiable(IDC_STAGE_DEC_TIME_Y, TRUE);
	SetMotionParamModifiable(IDC_STAGE_S_TIME_X, TRUE);
	SetMotionParamModifiable(IDC_STAGE_S_TIME_Y, TRUE);
	UpdateData(FALSE);
}