#pragma once
#include "afxwin.h"


// CManualDlg dialog

class CManualDlg : public CDialogEx
{
	DECLARE_DYNAMIC(CManualDlg)

public:
	CManualDlg(CWnd* pParent = NULL);   // standard constructor
	virtual ~CManualDlg();
	BOOL OnStageMove(UINT nID);
	void DMC3000_Move(int nCardNo, int nAxisIndex, int nPulse, int nDirection, int nMoveMode);

// Dialog Data
	enum { IDD = IDD_MANUAL };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

	DECLARE_MESSAGE_MAP()
public:
	virtual BOOL OnInitDialog();
	int m_stageStep;
};
