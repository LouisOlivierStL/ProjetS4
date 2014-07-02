#pragma once
#include "Parametres.h"

// CParametres_Dlg dialog

class CParametres_Dlg : public CDialogEx
{
	DECLARE_DYNAMIC(CParametres_Dlg)

private:
	Parametres *m_param;
	

public:
	void SetParamClass(Parametres *param);

	CParametres_Dlg(CWnd* pParent = NULL);   // standard constructor
	virtual ~CParametres_Dlg();

// Dialog Data
	enum { IDD = IDD_PARAMETRES_DLG };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedOk();
};
