// Parametres_Dlg.cpp : implementation file
//

#include "stdafx.h"
#include "Interface_Control_Grue.h"
#include "ParametresDlg.h"
#include "afxdialogex.h"


// CParametres_Dlg dialog

IMPLEMENT_DYNAMIC(CParametres_Dlg, CDialogEx)

CParametres_Dlg::CParametres_Dlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(CParametres_Dlg::IDD, pParent)
{

}

CParametres_Dlg::~CParametres_Dlg()
{
}

void CParametres_Dlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(CParametres_Dlg, CDialogEx)
	ON_BN_CLICKED(IDOK, &CParametres_Dlg::OnBnClickedOk)
END_MESSAGE_MAP()


// CParametres_Dlg message handlers

void CParametres_Dlg::SetParamClass(Parametres *param)
{
	m_param = param;
}

void CParametres_Dlg::OnBnClickedOk()
{
	// TODO: Add your control notification handler code here
	CDialogEx::OnOK();
}
