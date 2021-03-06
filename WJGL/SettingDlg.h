#pragma once


// CSettingDlg dialog

class CSettingDlg : public CDialogEx
{
	DECLARE_DYNAMIC(CSettingDlg)

public:
	CSettingDlg(CWnd* pParent = NULL);   // standard constructor
	virtual ~CSettingDlg();
	void SetSoftLimitReadOnly(int nID, BOOL modifiable);
	void SetSoftLimit();
	void GetSoftLimit();

// Dialog Data
	enum { IDD = IDD_SETTING_SOFTLIMIT_DIALOG };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	DECLARE_MESSAGE_MAP()

public:
	afx_msg void OnClickedModifySoftlimitBtn();
	afx_msg void OnClickedApplySoftlimitBtn();
	virtual BOOL OnInitDialog();
};
