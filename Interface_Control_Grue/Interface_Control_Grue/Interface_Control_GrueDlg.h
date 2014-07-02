
// Interface_Control_GrueDlg.h : header file
//

#pragma once

//#include "ParametresDlg.h"
//#include "Parametres.h"
#include "resource.h"
#include "afxcmn.h"
#include "afxwin.h"

#define SIZEOF_INDICATORS 2
#define ID_INDICATOR_TIME 1
#define ID_INDICATOR_LOG 2

//Variable global pour les timers
#define TIME_TIMER WM_USER+205
#define TIME_TIMEOUT 1000

#define RESTART_WORKER_THREAD_TIMER WM_USER+206
#define RESTART_WORKER_THREAD_TIMEOUT 10000

//Msg variable
#define ERR_WORKER_THREAD WM_USER+400
#define POST_CAPTEURS_VALUES WM_USER+401

static UINT BASED_CODE g_sIndicators[SIZEOF_INDICATORS] = { ID_INDICATOR_TIME, ID_INDICATOR_LOG };

class Parametres;
class CParametres_Dlg;

// CInterface_Control_Grue_Dlg dialog
class CInterface_Control_Grue_Dlg : public CDialogEx
{
// Construction
public:
	CInterface_Control_Grue_Dlg(CWnd* pParent = NULL);	// standard constructor

// Dialog Data
	enum { IDD = IDD_INTERFACE_CONTROL_GRUE_DIALOG };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support

private:
	CStatusBar m_STB_StatusBar;		//StatusBar
	CString m_strTmp;		//Variable string bidon
	char m_cTmp[500];		//Variable char bidon
	CString m_strTmpComp;	//Variable permettant de faire un doublecheck sur la valeur entre pour les compensateur

	//Variable pour le temps
	time_t m_time;
	struct tm m_time_now;

	CParametres_Dlg *m_pDLG_Parametres;
	Parametres *m_param;

	//Capteurs_Thread *m_capThread;

// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void On_ButtonArret_Clicked();
	afx_msg void OnBnClickedButtonStart();
	afx_msg void OnBnClickedButtonReset();
	afx_msg void OnModifierClicked();
	CTabCtrl m_tabParam;
	CComboBox m_comboXbeta;
	afx_msg void OnCbnSelchangeComboXbeta();
	afx_msg void OnCbnSelchangeComboYalpha();
	afx_msg void OnCbnSelchangeComboR();
	CComboBox m_comboYalpha;
	CComboBox m_comboR;
	afx_msg void OnTcnSelchangeTabParametres(NMHDR *pNMHDR, LRESULT *pResult);
	afx_msg void OnEnSetfocusEditXbetaParam1();
	afx_msg void OnEnSetfocusEditXbetaParam2();
	afx_msg void OnEnSetfocusEditXbetaParam3();
	afx_msg void OnEnSetfocusEditXbetaParam4();
	afx_msg void OnEnSetfocusEditXbetaParam5();
	afx_msg void OnEnSetfocusEditXbetaParam6();
	afx_msg void OnEnSetfocusEditXbetaParam7();
	afx_msg void OnEnSetfocusEditYalphaParam1();
	afx_msg void OnEnSetfocusEditYalphaParam2();
	afx_msg void OnEnSetfocusEditYalphaParam3();
	afx_msg void OnEnSetfocusEditYalphaParam4();
	afx_msg void OnEnSetfocusEditYalphaParam5();
	afx_msg void OnEnSetfocusEditYalphaParam6();
	afx_msg void OnEnSetfocusEditYalphaParam7();
	afx_msg void OnEnSetfocusEditRParam1();
	afx_msg void OnEnSetfocusEditRParam2();
	afx_msg void OnEnSetfocusEditRParam3();
	afx_msg void OnEnSetfocusEditRParam4();
	afx_msg void OnEnSetfocusEditRParam5();
	afx_msg void OnEnSetfocusEditRParam6();
	afx_msg void OnEnSetfocusEditRParam7();
	afx_msg void OnEnKillfocusEditXbetaParam1();
	afx_msg void OnEnKillfocusEditXbetaParam2();
	afx_msg void OnEnKillfocusEditXbetaParam3();
	afx_msg void OnEnKillfocusEditXbetaParam4();
	afx_msg void OnEnKillfocusEditXbetaParam5();
	afx_msg void OnEnKillfocusEditXbetaParam6();
	afx_msg void OnEnKillfocusEditXbetaParam7();
	afx_msg void OnEnKillfocusEditYalphaParam1();
	afx_msg void OnEnKillfocusEditYalphaParam2();
	afx_msg void OnEnKillfocusEditYalphaParam3();
	afx_msg void OnEnKillfocusEditYalphaParam4();
	afx_msg void OnEnKillfocusEditYalphaParam5();
	afx_msg void OnEnKillfocusEditYalphaParam6();
	afx_msg void OnEnKillfocusEditYalphaParam7();
	afx_msg void OnEnKillfocusEditRParam1();
	afx_msg void OnEnKillfocusEditRParam2();
	afx_msg void OnEnKillfocusEditRParam3();
	afx_msg void OnEnKillfocusEditRParam4();
	afx_msg void OnEnKillfocusEditRParam5();
	afx_msg void OnEnKillfocusEditRParam6();
	afx_msg void OnEnKillfocusEditRParam7();
	afx_msg void OnBnClickedRadioTrajLive();
	afx_msg void OnBnClickedRadioTrajPredef();
	afx_msg void OnEnSetfocusEditTrajX();
	afx_msg void OnEnSetfocusEditTrajY();
	afx_msg void OnEnSetfocusEditTrajZ();
	afx_msg void OnEnKillfocusEditTrajX();
	afx_msg void OnEnKillfocusEditTrajY();
	afx_msg void OnEnKillfocusEditTrajZ();
	afx_msg void OnBnClickedButtonParcourir();

	//Fonction message user
	afx_msg LRESULT OnErrWorkerThread(WPARAM, LPARAM);
	afx_msg LRESULT OnPostCapteursValues(WPARAM, LPARAM);

	void OnTimer(UINT_PTR p_pTimer);	//Fonction qui est appelee a chaque fois qu'un timer se termine
	void StartTimer(UINT_PTR p_uiIdEvent, DWORD p_dwTime); //Commence un timer
	void StopTimer(UINT_PTR p_uiIdEvent);	//Arrete un timer
	
	CString GetTime();
	void Start();
	void Stop();

	static UINT Calcul_Grue(LPVOID obj);

	//Fonctions d'affichage
	void Compensateurs_Visible(bool visible);

	void Xbeta_PID_Visible(bool visible);
	void Yalpha_PID_Visible(bool visible);
	void R_PID_Visible(bool visible);

	void Traj_Live_Enabled(bool enabled);
	void Traj_Disabled(bool disabled);

	//Fonction permettant d'ecrire un msg dans la barre de statut
	void Msg_Status(CString msg);
};

//UINT test(LPVOID pParam);