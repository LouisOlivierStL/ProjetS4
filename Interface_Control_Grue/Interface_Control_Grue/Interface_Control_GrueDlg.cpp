
// Interface_Control_GrueDlg.cpp : implementation file
//

#include "stdafx.h"
#include "Interface_Control_Grue.h"
#include "Interface_Control_GrueDlg.h"
#include "afxdialogex.h"
#include <math.h>
#include "ParametresDlg.h"
#include "Parametres.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CAboutDlg dialog used for App About

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

// Dialog Data
	enum { IDD = IDD_ABOUTBOX };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

// Implementation
protected:
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnModifierClicked();
};

CAboutDlg::CAboutDlg() : CDialogEx(CAboutDlg::IDD)
{
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialogEx)
END_MESSAGE_MAP()


// CInterface_Control_Grue_Dlg dialog



CInterface_Control_Grue_Dlg::CInterface_Control_Grue_Dlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(CInterface_Control_Grue_Dlg::IDD, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CInterface_Control_Grue_Dlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_TAB_PARAMETRES, m_tabParam);
	DDX_Control(pDX, IDC_COMBO_XBETA, m_comboXbeta);
	DDX_Control(pDX, IDC_COMBO_YALPHA, m_comboYalpha);
	DDX_Control(pDX, IDC_COMBO_R, m_comboR);
}

BEGIN_MESSAGE_MAP(CInterface_Control_Grue_Dlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_WM_TIMER() // to use timers
	ON_MESSAGE(ERR_WORKER_THREAD, &CInterface_Control_Grue_Dlg::OnErrWorkerThread)
	ON_MESSAGE(POST_CAPTEURS_VALUES, &CInterface_Control_Grue_Dlg::OnPostCapteursValues)
	ON_STN_CLICKED(IDC_BUTTON_STOP, &CInterface_Control_Grue_Dlg::On_ButtonArret_Clicked)
	ON_BN_CLICKED(IDC_BUTTON_START, &CInterface_Control_Grue_Dlg::OnBnClickedButtonStart)
	ON_BN_CLICKED(IDC_BUTTON_RESET, &CInterface_Control_Grue_Dlg::OnBnClickedButtonReset)
	ON_COMMAND(ID_PARAM32771, &CInterface_Control_Grue_Dlg::OnModifierClicked)
	ON_CBN_SELCHANGE(IDC_COMBO_XBETA, &CInterface_Control_Grue_Dlg::OnCbnSelchangeComboXbeta)
	ON_CBN_SELCHANGE(IDC_COMBO_YALPHA, &CInterface_Control_Grue_Dlg::OnCbnSelchangeComboYalpha)
	ON_CBN_SELCHANGE(IDC_COMBO_R, &CInterface_Control_Grue_Dlg::OnCbnSelchangeComboR)
	ON_NOTIFY(TCN_SELCHANGE, IDC_TAB_PARAMETRES, &CInterface_Control_Grue_Dlg::OnTcnSelchangeTabParametres)
	ON_EN_SETFOCUS(IDC_EDIT_XBETA_PARAM1, &CInterface_Control_Grue_Dlg::OnEnSetfocusEditXbetaParam1)
	ON_EN_SETFOCUS(IDC_EDIT_XBETA_PARAM2, &CInterface_Control_Grue_Dlg::OnEnSetfocusEditXbetaParam2)
	ON_EN_SETFOCUS(IDC_EDIT_XBETA_PARAM3, &CInterface_Control_Grue_Dlg::OnEnSetfocusEditXbetaParam3)
	ON_EN_SETFOCUS(IDC_EDIT_XBETA_PARAM4, &CInterface_Control_Grue_Dlg::OnEnSetfocusEditXbetaParam4)
	ON_EN_SETFOCUS(IDC_EDIT_XBETA_PARAM5, &CInterface_Control_Grue_Dlg::OnEnSetfocusEditXbetaParam5)
	ON_EN_SETFOCUS(IDC_EDIT_XBETA_PARAM6, &CInterface_Control_Grue_Dlg::OnEnSetfocusEditXbetaParam6)
	ON_EN_SETFOCUS(IDC_EDIT_XBETA_PARAM7, &CInterface_Control_Grue_Dlg::OnEnSetfocusEditXbetaParam7)
	ON_EN_SETFOCUS(IDC_EDIT_YALPHA_PARAM1, &CInterface_Control_Grue_Dlg::OnEnSetfocusEditYalphaParam1)
	ON_EN_SETFOCUS(IDC_EDIT_YALPHA_PARAM2, &CInterface_Control_Grue_Dlg::OnEnSetfocusEditYalphaParam2)
	ON_EN_SETFOCUS(IDC_EDIT_YALPHA_PARAM3, &CInterface_Control_Grue_Dlg::OnEnSetfocusEditYalphaParam3)
	ON_EN_SETFOCUS(IDC_EDIT_YALPHA_PARAM4, &CInterface_Control_Grue_Dlg::OnEnSetfocusEditYalphaParam4)
	ON_EN_SETFOCUS(IDC_EDIT_YALPHA_PARAM5, &CInterface_Control_Grue_Dlg::OnEnSetfocusEditYalphaParam5)
	ON_EN_SETFOCUS(IDC_EDIT_YALPHA_PARAM6, &CInterface_Control_Grue_Dlg::OnEnSetfocusEditYalphaParam6)
	ON_EN_SETFOCUS(IDC_EDIT_YALPHA_PARAM7, &CInterface_Control_Grue_Dlg::OnEnSetfocusEditYalphaParam7)
	ON_EN_SETFOCUS(IDC_EDIT_R_PARAM1, &CInterface_Control_Grue_Dlg::OnEnSetfocusEditRParam1)
	ON_EN_SETFOCUS(IDC_EDIT_R_PARAM2, &CInterface_Control_Grue_Dlg::OnEnSetfocusEditRParam2)
	ON_EN_SETFOCUS(IDC_EDIT_R_PARAM3, &CInterface_Control_Grue_Dlg::OnEnSetfocusEditRParam3)
	ON_EN_SETFOCUS(IDC_EDIT_R_PARAM4, &CInterface_Control_Grue_Dlg::OnEnSetfocusEditRParam4)
	ON_EN_SETFOCUS(IDC_EDIT_R_PARAM5, &CInterface_Control_Grue_Dlg::OnEnSetfocusEditRParam5)
	ON_EN_SETFOCUS(IDC_EDIT_R_PARAM6, &CInterface_Control_Grue_Dlg::OnEnSetfocusEditRParam6)
	ON_EN_SETFOCUS(IDC_EDIT_R_PARAM7, &CInterface_Control_Grue_Dlg::OnEnSetfocusEditRParam7)
	ON_EN_KILLFOCUS(IDC_EDIT_XBETA_PARAM1, &CInterface_Control_Grue_Dlg::OnEnKillfocusEditXbetaParam1)
	ON_EN_KILLFOCUS(IDC_EDIT_XBETA_PARAM2, &CInterface_Control_Grue_Dlg::OnEnKillfocusEditXbetaParam2)
	ON_EN_KILLFOCUS(IDC_EDIT_XBETA_PARAM3, &CInterface_Control_Grue_Dlg::OnEnKillfocusEditXbetaParam3)
	ON_EN_KILLFOCUS(IDC_EDIT_XBETA_PARAM4, &CInterface_Control_Grue_Dlg::OnEnKillfocusEditXbetaParam4)
	ON_EN_KILLFOCUS(IDC_EDIT_XBETA_PARAM5, &CInterface_Control_Grue_Dlg::OnEnKillfocusEditXbetaParam5)
	ON_EN_KILLFOCUS(IDC_EDIT_XBETA_PARAM6, &CInterface_Control_Grue_Dlg::OnEnKillfocusEditXbetaParam6)
	ON_EN_KILLFOCUS(IDC_EDIT_XBETA_PARAM7, &CInterface_Control_Grue_Dlg::OnEnKillfocusEditXbetaParam7)
	ON_EN_KILLFOCUS(IDC_EDIT_YALPHA_PARAM1, &CInterface_Control_Grue_Dlg::OnEnKillfocusEditYalphaParam1)
	ON_EN_KILLFOCUS(IDC_EDIT_YALPHA_PARAM2, &CInterface_Control_Grue_Dlg::OnEnKillfocusEditYalphaParam2)
	ON_EN_KILLFOCUS(IDC_EDIT_YALPHA_PARAM3, &CInterface_Control_Grue_Dlg::OnEnKillfocusEditYalphaParam3)
	ON_EN_KILLFOCUS(IDC_EDIT_YALPHA_PARAM4, &CInterface_Control_Grue_Dlg::OnEnKillfocusEditYalphaParam4)
	ON_EN_KILLFOCUS(IDC_EDIT_YALPHA_PARAM5, &CInterface_Control_Grue_Dlg::OnEnKillfocusEditYalphaParam5)
	ON_EN_KILLFOCUS(IDC_EDIT_YALPHA_PARAM6, &CInterface_Control_Grue_Dlg::OnEnKillfocusEditYalphaParam6)
	ON_EN_KILLFOCUS(IDC_EDIT_YALPHA_PARAM7, &CInterface_Control_Grue_Dlg::OnEnKillfocusEditYalphaParam7)
	ON_EN_KILLFOCUS(IDC_EDIT_R_PARAM1, &CInterface_Control_Grue_Dlg::OnEnKillfocusEditRParam1)
	ON_EN_KILLFOCUS(IDC_EDIT_R_PARAM2, &CInterface_Control_Grue_Dlg::OnEnKillfocusEditRParam2)
	ON_EN_KILLFOCUS(IDC_EDIT_R_PARAM3, &CInterface_Control_Grue_Dlg::OnEnKillfocusEditRParam3)
	ON_EN_KILLFOCUS(IDC_EDIT_R_PARAM4, &CInterface_Control_Grue_Dlg::OnEnKillfocusEditRParam4)
	ON_EN_KILLFOCUS(IDC_EDIT_R_PARAM5, &CInterface_Control_Grue_Dlg::OnEnKillfocusEditRParam5)
	ON_EN_KILLFOCUS(IDC_EDIT_R_PARAM6, &CInterface_Control_Grue_Dlg::OnEnKillfocusEditRParam6)
	ON_EN_KILLFOCUS(IDC_EDIT_R_PARAM7, &CInterface_Control_Grue_Dlg::OnEnKillfocusEditRParam7)
	ON_BN_CLICKED(IDC_RADIO_TRAJ_LIVE, &CInterface_Control_Grue_Dlg::OnBnClickedRadioTrajLive)
	ON_BN_CLICKED(IDC_RADIO_TRAJ_PREDEF, &CInterface_Control_Grue_Dlg::OnBnClickedRadioTrajPredef)
	ON_EN_SETFOCUS(IDC_EDIT_TRAJ_X, &CInterface_Control_Grue_Dlg::OnEnSetfocusEditTrajX)
	ON_EN_SETFOCUS(IDC_EDIT_TRAJ_Y, &CInterface_Control_Grue_Dlg::OnEnSetfocusEditTrajY)
	ON_EN_SETFOCUS(IDC_EDIT_TRAJ_Z, &CInterface_Control_Grue_Dlg::OnEnSetfocusEditTrajZ)
	ON_EN_KILLFOCUS(IDC_EDIT_TRAJ_X, &CInterface_Control_Grue_Dlg::OnEnKillfocusEditTrajX)
	ON_EN_KILLFOCUS(IDC_EDIT_TRAJ_Y, &CInterface_Control_Grue_Dlg::OnEnKillfocusEditTrajY)
	ON_EN_KILLFOCUS(IDC_EDIT_TRAJ_Z, &CInterface_Control_Grue_Dlg::OnEnKillfocusEditTrajZ)
	ON_BN_CLICKED(IDC_BUTTON_PARCOURIR, &CInterface_Control_Grue_Dlg::OnBnClickedButtonParcourir)
END_MESSAGE_MAP()


// CInterface_Control_Grue_Dlg message handlers

BOOL CInterface_Control_Grue_Dlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// Add "About..." menu item to system menu.

	// IDM_ABOUTBOX must be in the system command range.
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != NULL)
	{
		BOOL bNameValid;
		CString strAboutMenu;
		bNameValid = strAboutMenu.LoadString(IDS_ABOUTBOX);
		ASSERT(bNameValid);
		if (!strAboutMenu.IsEmpty())
		{
			pSysMenu->AppendMenu(MF_SEPARATOR);
			pSysMenu->AppendMenu(MF_STRING, IDM_ABOUTBOX, strAboutMenu);
		}
	}

	// create status bar which will contain the current time and the current log file name and path
	m_STB_StatusBar.CreateEx(this);
	//m_STB_StatusBar.CreateEx(this, SBT_TOOLTIPS);
	m_STB_StatusBar.SetIndicators(g_sIndicators, SIZEOF_INDICATORS);
	RepositionBars(AFX_IDW_CONTROLBAR_FIRST, AFX_IDW_CONTROLBAR_LAST, ID_INDICATOR_TIME);
	m_STB_StatusBar.SetPaneInfo(0, ID_INDICATOR_TIME, SBPS_NORMAL, 105);
	m_STB_StatusBar.SetPaneInfo(1, ID_INDICATOR_LOG, SBPS_STRETCH, 0);

	//SBT_TOOLTIPS

	m_STB_StatusBar.GetStatusBarCtrl().SetBkColor(RGB(0, 0, 0));

	m_strTmp.Format(_T("Statut: "));
	m_STB_StatusBar.SetPaneText(m_STB_StatusBar.CommandToIndex(ID_INDICATOR_LOG), (LPCTSTR)m_strTmp);

	//On commence le timer pour afficher le temps
	StartTimer(TIME_TIMER, TIME_TIMEOUT);

	//Initialisation de la classe Parametres
	m_param = new Parametres(this);

	//TabCtrl initialisation
	m_tabParam.InsertItem(0, _T("Compensateurs"));
	m_tabParam.InsertItem(1, _T("Trajectoire"));

	Compensateurs_Visible(true);

	//Combo xbeta init
	m_comboXbeta.InsertString(0, _T("PID"));
	m_comboXbeta.InsertString(1, _T("TF"));

	m_comboXbeta.SetCurSel(0);

	//Combo yalpha init
	m_comboYalpha.InsertString(0, _T("PID"));
	m_comboYalpha.InsertString(1, _T("TF"));

	m_comboYalpha.SetCurSel(0);

	//Combo r init
	m_comboR.InsertString(0, _T("PID"));
	m_comboR.InsertString(1, _T("TF"));

	m_comboR.SetCurSel(0);

	//Trajectoire init
	((CButton*)GetDlgItem(IDC_RADIO_TRAJ_LIVE))->SetCheck(true);
	Traj_Live_Enabled(true);

	// Set the icon for this dialog.  The framework does this automatically
	//  when the application's main window is not a dialog
	SetIcon(m_hIcon, TRUE);			// Set big icon
	SetIcon(m_hIcon, FALSE);		// Set small icon

	// TODO: Add extra initialization here

	return TRUE;  // return TRUE  unless you set the focus to a control
}

void CInterface_Control_Grue_Dlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	if ((nID & 0xFFF0) == IDM_ABOUTBOX)
	{
		CAboutDlg dlgAbout;
		dlgAbout.DoModal();
	}
	else
	{
		CDialogEx::OnSysCommand(nID, lParam);
	}
}

// If you add a minimize button to your dialog, you will need the code below
//  to draw the icon.  For MFC applications using the document/view model,
//  this is automatically done for you by the framework.

void CInterface_Control_Grue_Dlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // device context for painting

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// Center icon in client rectangle
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// Draw the icon
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}
}

// The system calls this function to obtain the cursor to display while the user drags
//  the minimized window.
HCURSOR CInterface_Control_Grue_Dlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}

void CInterface_Control_Grue_Dlg::OnTimer(UINT_PTR p_pTimer)
{
	switch (p_pTimer)
	{
		//Affiche le temps dans le coin gauche de l'application
		case TIME_TIMER:
		{
			m_STB_StatusBar.SetPaneText(m_STB_StatusBar.CommandToIndex(ID_INDICATOR_TIME), GetTime());
			break;
		}

		//Affiche les valeurs sur l'interface
		case RESTART_WORKER_THREAD_TIMER:
		{
			AfxBeginThread(Calcul_Grue, m_param);
			StopTimer(RESTART_WORKER_THREAD_TIMER);
			break;
		}
	}
}

//Section fonction message
LRESULT CInterface_Control_Grue_Dlg::OnErrWorkerThread(WPARAM wParam, LPARAM lParam)
{
	CString* strTmp = (CString*)lParam;
	Msg_Status(*strTmp);
	StartTimer(RESTART_WORKER_THREAD_TIMER, RESTART_WORKER_THREAD_TIMEOUT);
	return 0;
}

LRESULT CInterface_Control_Grue_Dlg::OnPostCapteursValues(WPARAM wParam, LPARAM lParam)
{
	m_strTmp.Format(_T("%f"), m_param->GetAlpha());
	GetDlgItem(IDC_STATIC_ALPHA_VALEUR)->SetWindowTextW(m_strTmp);
	m_strTmp.Format(_T("%f"), m_param->GetBeta());
	GetDlgItem(IDC_STATIC_BETA_VALEUR)->SetWindowTextW(m_strTmp);
	m_strTmp.Format(_T("%f"), m_param->GetR());
	GetDlgItem(IDC_STATIC_R_VALEUR)->SetWindowTextW(m_strTmp);
	m_strTmp.Format(_T("%f"), m_param->GetYw());
	GetDlgItem(IDC_STATIC_YW_VALEUR)->SetWindowTextW(m_strTmp);
	m_strTmp.Format(_T("%f"), m_param->GetXp());
	GetDlgItem(IDC_STATIC_XP_VALEUR)->SetWindowTextW(m_strTmp);
	m_strTmp.Format(_T("%f"), m_param->GetXc());
	GetDlgItem(IDC_STATIC_X_VALEUR)->SetWindowTextW(m_strTmp);
	m_strTmp.Format(_T("%f"), m_param->GetYc());
	GetDlgItem(IDC_STATIC_Y_VALEUR)->SetWindowTextW(m_strTmp);
	m_strTmp.Format(_T("%f"), m_param->GetZc());
	GetDlgItem(IDC_STATIC_Z_VALEUR)->SetWindowTextW(m_strTmp);

	m_param->SetWait(false);
	return 0;
}


//-----------------------

CString CInterface_Control_Grue_Dlg::GetTime()
{
	m_time = time(0);
	localtime_s(&m_time_now, &m_time);
	m_strTmp.Format(_T("%.02d/%.02d/%.02d %.02d:%.02d:%.02d"), m_time_now.tm_year + 1900, 1 + m_time_now.tm_mon, m_time_now.tm_mday, m_time_now.tm_hour, m_time_now.tm_min, m_time_now.tm_sec);

	return m_strTmp;
}

void CInterface_Control_Grue_Dlg::StartTimer(UINT_PTR p_uiIdEvent, DWORD p_dwTime)
{
	CWnd::SetTimer(p_uiIdEvent, p_dwTime, NULL);
}

void CInterface_Control_Grue_Dlg::StopTimer(UINT_PTR p_uiIdEvent)
{
	CWnd::KillTimer(p_uiIdEvent);
}

void CInterface_Control_Grue_Dlg::On_ButtonArret_Clicked()
{
	GetDlgItem(IDC_BUTTON_STOP)->ModifyStyleEx(0, WS_EX_CLIENTEDGE, SWP_FRAMECHANGED);
	Stop();
	Sleep(200);
	GetDlgItem(IDC_BUTTON_STOP)->ModifyStyleEx(WS_EX_CLIENTEDGE, 0, SWP_FRAMECHANGED);
}

void CInterface_Control_Grue_Dlg::OnBnClickedButtonStart()
{
	Start();
}


void CInterface_Control_Grue_Dlg::OnBnClickedButtonReset()
{

}

void CInterface_Control_Grue_Dlg::OnModifierClicked()
{
	m_pDLG_Parametres = new CParametres_Dlg;
	m_pDLG_Parametres->SetParamClass(m_param);
	
	INT_PTR nResponse = m_pDLG_Parametres->DoModal();

	if (nResponse == IDOK)
	{

	}

	else if (nResponse == IDCANCEL)
	{

	}
}

void CInterface_Control_Grue_Dlg::Start()
{
	m_param->SetCalcul(true);
	AfxBeginThread(Calcul_Grue, m_param);
	m_param->UpdateCraneComp();
	Traj_Disabled(true);

	//Debut du deplacement de la grue
	/*int err = m_param->GetCrane()->Run(CLOSE, RESTART);

	if(err == 0)
	{
		Msg_Status(_T("Grue en déplacement."));
	}

	else if(err == ERR_CTL_MODE)
	{
		Msg_Status(_T("Le paramètre ctlMode est non valide."));
	}

	else if(err == ERR_RUNNING)
	{
		Msg_Status(_T("La grue est déjà en train d’exécuter un déplacement."));
	}

	else if(err == ERR_TRAJ)
	{
		Msg_Status(_T("La trajectoire n’est pas spécifiée ou est non valide."));
	}

	else if(err == ERR_TRAJ_FLAG)
	{
		Msg_Status(_T("Le paramètre trajFlag est non valide."));
	}

	else if(err == ERR_WRITE_DSP)
	{
		Msg_Status(_T("L’envoi de données au DSP a échoué."));
	}*/
}

void CInterface_Control_Grue_Dlg::Stop()
{
	/*int err = m_param->GetCrane()->Stop();

	if(err == ERR_READ_DSP)
	{
		Msg_Status(_T("La réception de données du DSP a échouée."));
	}*/

	m_param->SetCalcul(false);
	Traj_Disabled(false);
}

UINT CInterface_Control_Grue_Dlg::Calcul_Grue(LPVOID obj)
{
	Parametres* param = (Parametres*) obj;
	float sensors[5];
	float xc;
	float yc;
	float zc;

	while(param->GetCalcul())
	{
		if(!param->GetWait())
		{
			//On va chercher la valeur des differents capteurs
			int err = param->GetCrane()->GetSensor(sensors);
			CString* strErr;

			if(err == ERR_NULL_PTR)
			{
				strErr = new CString(_T("Statut: Un pointeur nul a été rencontré lors de l'envoie de la structure des compensateurs."));
				::PostMessage(param->GetDialog()->m_hWnd, ERR_WORKER_THREAD, 0, (LPARAM)strErr);
				return 0;
			}

			else if(err == ERR_READ_DSP)
			{
				strErr = new CString(_T("Statut: La réception de données du DSP a échouée."));
				::PostMessage(param->GetDialog()->m_hWnd, ERR_WORKER_THREAD, 0, (LPARAM)strErr);
				return 0;
			}

			//On assigne la valeur contenu dans l'array au different capteurs dans la classe parametres
			param->SetXp(sensors[0]);
			param->SetYw(sensors[1]);
			param->SetR(sensors[2]);
			param->SetAlpha(sensors[3]);
			param->SetBeta(sensors[4]);

			//Calcul de la position
			xc = sensors[0] + sensors[2]*cos(sensors[3])*sin(sensors[4]);
			yc = sensors[1] + sensors[2]*sin(sensors[3]);
			zc = sensors[2]*cos(sensors[3])*cos(sensors[4]);

			//On assigne la valeur des position calculees aux positions dans la classe parametres
			param->SetXc(xc);
			param->SetYc(yc);
			param->SetZc(zc);

			param->SetWait(true);
			::PostMessageA(param->GetDialog()->m_hWnd, POST_CAPTEURS_VALUES, 0, 0);
		}
	}
	return 0;
}

void CInterface_Control_Grue_Dlg::OnCbnSelchangeComboXbeta()
{
	int sel = m_comboXbeta.GetCurSel();

	if(sel == 0)
	{
		Xbeta_PID_Visible(true);
		m_param->SetXbetaType(PID);
	}

	else if(sel == 1)
	{
		Xbeta_PID_Visible(false);
		m_param->SetXbetaType(TF);
	}
}

void CInterface_Control_Grue_Dlg::Compensateurs_Visible(bool visible)
{
	int sel;

	if(visible)
	{
		sel = m_comboXbeta.GetCurSel();

		if(sel == 0)
		{
			Xbeta_PID_Visible(true);
		}

		else
		{
			Xbeta_PID_Visible(false);
		}

		sel = m_comboYalpha.GetCurSel();

		if(sel == 0)
		{
			Yalpha_PID_Visible(true);
		}

		else
		{
			Yalpha_PID_Visible(false);
		}

		sel = m_comboR.GetCurSel();

		if(sel == 0)
		{
			R_PID_Visible(true);
		}

		else
		{
			R_PID_Visible(false);
		}

		GetDlgItem(IDC_STATIC_XBETA)->ShowWindow(SW_SHOW);
		GetDlgItem(IDC_STATIC_YALPHA)->ShowWindow(SW_SHOW);
		GetDlgItem(IDC_STATIC_R_BOX)->ShowWindow(SW_SHOW);
		GetDlgItem(IDC_COMBO_XBETA)->ShowWindow(SW_SHOW);
		GetDlgItem(IDC_COMBO_YALPHA)->ShowWindow(SW_SHOW);
		GetDlgItem(IDC_COMBO_R)->ShowWindow(SW_SHOW);
		GetDlgItem(IDC_STATIC_XBETA_PARAM1)->ShowWindow(SW_SHOW);
		GetDlgItem(IDC_STATIC_YALPHA_PARAM1)->ShowWindow(SW_SHOW);
		GetDlgItem(IDC_STATIC_R_PARAM1)->ShowWindow(SW_SHOW);
		GetDlgItem(IDC_EDIT_XBETA_PARAM1)->ShowWindow(SW_SHOW);
		GetDlgItem(IDC_EDIT_YALPHA_PARAM1)->ShowWindow(SW_SHOW);
		GetDlgItem(IDC_EDIT_R_PARAM1)->ShowWindow(SW_SHOW);

		GetDlgItem(IDC_STATIC_TRAJECTOIRE)->ShowWindow(SW_HIDE);
		GetDlgItem(IDC_RADIO_TRAJ_LIVE)->ShowWindow(SW_HIDE);
		GetDlgItem(IDC_STATIC_TRAJ_X)->ShowWindow(SW_HIDE);
		GetDlgItem(IDC_STATIC_TRAJ_Y)->ShowWindow(SW_HIDE);
		GetDlgItem(IDC_STATIC_TRAJ_Z)->ShowWindow(SW_HIDE);
		GetDlgItem(IDC_EDIT_TRAJ_X)->ShowWindow(SW_HIDE);
		GetDlgItem(IDC_EDIT_TRAJ_Y)->ShowWindow(SW_HIDE);
		GetDlgItem(IDC_EDIT_TRAJ_Z)->ShowWindow(SW_HIDE);
		GetDlgItem(IDC_RADIO_TRAJ_PREDEF)->ShowWindow(SW_HIDE);
		GetDlgItem(IDC_EDIT_TRAJ_PATH)->ShowWindow(SW_HIDE);
		GetDlgItem(IDC_BUTTON_PARCOURIR)->ShowWindow(SW_HIDE);
	}

	else
	{
		GetDlgItem(IDC_STATIC_XBETA_PARAM2)->ShowWindow(SW_HIDE);
		GetDlgItem(IDC_STATIC_XBETA_PARAM3)->ShowWindow(SW_HIDE);
		GetDlgItem(IDC_STATIC_XBETA_PARAM4)->ShowWindow(SW_HIDE);
		GetDlgItem(IDC_STATIC_XBETA_PARAM5)->ShowWindow(SW_HIDE);
		GetDlgItem(IDC_STATIC_XBETA_PARAM6)->ShowWindow(SW_HIDE);
		GetDlgItem(IDC_STATIC_XBETA_PARAM7)->ShowWindow(SW_HIDE);

		GetDlgItem(IDC_EDIT_XBETA_PARAM2)->ShowWindow(SW_HIDE);
		GetDlgItem(IDC_EDIT_XBETA_PARAM3)->ShowWindow(SW_HIDE);
		GetDlgItem(IDC_EDIT_XBETA_PARAM4)->ShowWindow(SW_HIDE);
		GetDlgItem(IDC_EDIT_XBETA_PARAM5)->ShowWindow(SW_HIDE);
		GetDlgItem(IDC_EDIT_XBETA_PARAM6)->ShowWindow(SW_HIDE);
		GetDlgItem(IDC_EDIT_XBETA_PARAM7)->ShowWindow(SW_HIDE);

		GetDlgItem(IDC_STATIC_YALPHA_PARAM2)->ShowWindow(SW_HIDE);
		GetDlgItem(IDC_STATIC_YALPHA_PARAM3)->ShowWindow(SW_HIDE);
		GetDlgItem(IDC_STATIC_YALPHA_PARAM4)->ShowWindow(SW_HIDE);
		GetDlgItem(IDC_STATIC_YALPHA_PARAM5)->ShowWindow(SW_HIDE);
		GetDlgItem(IDC_STATIC_YALPHA_PARAM6)->ShowWindow(SW_HIDE);
		GetDlgItem(IDC_STATIC_YALPHA_PARAM7)->ShowWindow(SW_HIDE);

		GetDlgItem(IDC_EDIT_YALPHA_PARAM2)->ShowWindow(SW_HIDE);
		GetDlgItem(IDC_EDIT_YALPHA_PARAM3)->ShowWindow(SW_HIDE);
		GetDlgItem(IDC_EDIT_YALPHA_PARAM4)->ShowWindow(SW_HIDE);
		GetDlgItem(IDC_EDIT_YALPHA_PARAM5)->ShowWindow(SW_HIDE);
		GetDlgItem(IDC_EDIT_YALPHA_PARAM6)->ShowWindow(SW_HIDE);
		GetDlgItem(IDC_EDIT_YALPHA_PARAM7)->ShowWindow(SW_HIDE);

		GetDlgItem(IDC_STATIC_R_PARAM2)->ShowWindow(SW_HIDE);
		GetDlgItem(IDC_STATIC_R_PARAM3)->ShowWindow(SW_HIDE);
		GetDlgItem(IDC_STATIC_R_PARAM4)->ShowWindow(SW_HIDE);
		GetDlgItem(IDC_STATIC_R_PARAM5)->ShowWindow(SW_HIDE);
		GetDlgItem(IDC_STATIC_R_PARAM6)->ShowWindow(SW_HIDE);
		GetDlgItem(IDC_STATIC_R_PARAM7)->ShowWindow(SW_HIDE);

		GetDlgItem(IDC_EDIT_R_PARAM2)->ShowWindow(SW_HIDE);
		GetDlgItem(IDC_EDIT_R_PARAM3)->ShowWindow(SW_HIDE);
		GetDlgItem(IDC_EDIT_R_PARAM4)->ShowWindow(SW_HIDE);
		GetDlgItem(IDC_EDIT_R_PARAM5)->ShowWindow(SW_HIDE);
		GetDlgItem(IDC_EDIT_R_PARAM6)->ShowWindow(SW_HIDE);
		GetDlgItem(IDC_EDIT_R_PARAM7)->ShowWindow(SW_HIDE);

		GetDlgItem(IDC_STATIC_XBETA)->ShowWindow(SW_HIDE);
		GetDlgItem(IDC_STATIC_YALPHA)->ShowWindow(SW_HIDE);
		GetDlgItem(IDC_STATIC_R_BOX)->ShowWindow(SW_HIDE);
		GetDlgItem(IDC_COMBO_XBETA)->ShowWindow(SW_HIDE);
		GetDlgItem(IDC_COMBO_YALPHA)->ShowWindow(SW_HIDE);
		GetDlgItem(IDC_COMBO_R)->ShowWindow(SW_HIDE);
		GetDlgItem(IDC_STATIC_XBETA_PARAM1)->ShowWindow(SW_HIDE);
		GetDlgItem(IDC_STATIC_YALPHA_PARAM1)->ShowWindow(SW_HIDE);
		GetDlgItem(IDC_STATIC_R_PARAM1)->ShowWindow(SW_HIDE);
		GetDlgItem(IDC_EDIT_XBETA_PARAM1)->ShowWindow(SW_HIDE);
		GetDlgItem(IDC_EDIT_YALPHA_PARAM1)->ShowWindow(SW_HIDE);
		GetDlgItem(IDC_EDIT_R_PARAM1)->ShowWindow(SW_HIDE);

		GetDlgItem(IDC_STATIC_TRAJECTOIRE)->ShowWindow(SW_SHOW);
		GetDlgItem(IDC_RADIO_TRAJ_LIVE)->ShowWindow(SW_SHOW);
		GetDlgItem(IDC_STATIC_TRAJ_X)->ShowWindow(SW_SHOW);
		GetDlgItem(IDC_STATIC_TRAJ_Y)->ShowWindow(SW_SHOW);
		GetDlgItem(IDC_STATIC_TRAJ_Z)->ShowWindow(SW_SHOW);
		GetDlgItem(IDC_EDIT_TRAJ_X)->ShowWindow(SW_SHOW);
		GetDlgItem(IDC_EDIT_TRAJ_Y)->ShowWindow(SW_SHOW);
		GetDlgItem(IDC_EDIT_TRAJ_Z)->ShowWindow(SW_SHOW);
		GetDlgItem(IDC_RADIO_TRAJ_PREDEF)->ShowWindow(SW_SHOW);
		GetDlgItem(IDC_EDIT_TRAJ_PATH)->ShowWindow(SW_SHOW);
		GetDlgItem(IDC_BUTTON_PARCOURIR)->ShowWindow(SW_SHOW);
	}
}

void CInterface_Control_Grue_Dlg::Xbeta_PID_Visible(bool visible)
{
	if(visible)
	{
		GetDlgItem(IDC_STATIC_XBETA_PARAM2)->ShowWindow(SW_SHOW);
		GetDlgItem(IDC_STATIC_XBETA_PARAM3)->ShowWindow(SW_SHOW);
		GetDlgItem(IDC_STATIC_XBETA_PARAM4)->ShowWindow(SW_SHOW);
		GetDlgItem(IDC_STATIC_XBETA_PARAM5)->ShowWindow(SW_HIDE);
		GetDlgItem(IDC_STATIC_XBETA_PARAM6)->ShowWindow(SW_HIDE);
		GetDlgItem(IDC_STATIC_XBETA_PARAM7)->ShowWindow(SW_HIDE);

		GetDlgItem(IDC_EDIT_XBETA_PARAM2)->ShowWindow(SW_SHOW);
		GetDlgItem(IDC_EDIT_XBETA_PARAM3)->ShowWindow(SW_SHOW);
		GetDlgItem(IDC_EDIT_XBETA_PARAM4)->ShowWindow(SW_SHOW);
		GetDlgItem(IDC_EDIT_XBETA_PARAM5)->ShowWindow(SW_HIDE);
		GetDlgItem(IDC_EDIT_XBETA_PARAM6)->ShowWindow(SW_HIDE);
		GetDlgItem(IDC_EDIT_XBETA_PARAM7)->ShowWindow(SW_HIDE);

		GetDlgItem(IDC_STATIC_XBETA_PARAM2)->SetWindowText(_T("kp :"));
		GetDlgItem(IDC_STATIC_XBETA_PARAM3)->SetWindowText(_T("kd :"));
		GetDlgItem(IDC_STATIC_XBETA_PARAM4)->SetWindowText(_T("ki :"));
	}

	else
	{
		GetDlgItem(IDC_STATIC_XBETA_PARAM2)->ShowWindow(SW_SHOW);
		GetDlgItem(IDC_STATIC_XBETA_PARAM3)->ShowWindow(SW_SHOW);
		GetDlgItem(IDC_STATIC_XBETA_PARAM4)->ShowWindow(SW_SHOW);
		GetDlgItem(IDC_STATIC_XBETA_PARAM5)->ShowWindow(SW_SHOW);
		GetDlgItem(IDC_STATIC_XBETA_PARAM6)->ShowWindow(SW_SHOW);
		GetDlgItem(IDC_STATIC_XBETA_PARAM7)->ShowWindow(SW_SHOW);

		GetDlgItem(IDC_EDIT_XBETA_PARAM2)->ShowWindow(SW_SHOW);
		GetDlgItem(IDC_EDIT_XBETA_PARAM3)->ShowWindow(SW_SHOW);
		GetDlgItem(IDC_EDIT_XBETA_PARAM4)->ShowWindow(SW_SHOW);
		GetDlgItem(IDC_EDIT_XBETA_PARAM5)->ShowWindow(SW_SHOW);
		GetDlgItem(IDC_EDIT_XBETA_PARAM6)->ShowWindow(SW_SHOW);
		GetDlgItem(IDC_EDIT_XBETA_PARAM7)->ShowWindow(SW_SHOW);

		GetDlgItem(IDC_STATIC_XBETA_PARAM2)->SetWindowText(_T("b0 :"));
		GetDlgItem(IDC_STATIC_XBETA_PARAM3)->SetWindowText(_T("b1 :"));
		GetDlgItem(IDC_STATIC_XBETA_PARAM4)->SetWindowText(_T("b2 :"));
	}
}

void CInterface_Control_Grue_Dlg::Yalpha_PID_Visible(bool visible)
{
	if(visible)
	{
		GetDlgItem(IDC_STATIC_YALPHA_PARAM2)->ShowWindow(SW_SHOW);
		GetDlgItem(IDC_STATIC_YALPHA_PARAM3)->ShowWindow(SW_SHOW);
		GetDlgItem(IDC_STATIC_YALPHA_PARAM4)->ShowWindow(SW_SHOW);
		GetDlgItem(IDC_STATIC_YALPHA_PARAM5)->ShowWindow(SW_HIDE);
		GetDlgItem(IDC_STATIC_YALPHA_PARAM6)->ShowWindow(SW_HIDE);
		GetDlgItem(IDC_STATIC_YALPHA_PARAM7)->ShowWindow(SW_HIDE);

		GetDlgItem(IDC_EDIT_YALPHA_PARAM2)->ShowWindow(SW_SHOW);
		GetDlgItem(IDC_EDIT_YALPHA_PARAM3)->ShowWindow(SW_SHOW);
		GetDlgItem(IDC_EDIT_YALPHA_PARAM4)->ShowWindow(SW_SHOW);
		GetDlgItem(IDC_EDIT_YALPHA_PARAM5)->ShowWindow(SW_HIDE);
		GetDlgItem(IDC_EDIT_YALPHA_PARAM6)->ShowWindow(SW_HIDE);
		GetDlgItem(IDC_EDIT_YALPHA_PARAM7)->ShowWindow(SW_HIDE);

		GetDlgItem(IDC_STATIC_YALPHA_PARAM2)->SetWindowText(_T("kp :"));
		GetDlgItem(IDC_STATIC_YALPHA_PARAM3)->SetWindowText(_T("kd :"));
		GetDlgItem(IDC_STATIC_YALPHA_PARAM4)->SetWindowText(_T("ki :"));
	}

	else
	{
		GetDlgItem(IDC_STATIC_YALPHA_PARAM2)->ShowWindow(SW_SHOW);
		GetDlgItem(IDC_STATIC_YALPHA_PARAM3)->ShowWindow(SW_SHOW);
		GetDlgItem(IDC_STATIC_YALPHA_PARAM4)->ShowWindow(SW_SHOW);
		GetDlgItem(IDC_STATIC_YALPHA_PARAM5)->ShowWindow(SW_SHOW);
		GetDlgItem(IDC_STATIC_YALPHA_PARAM6)->ShowWindow(SW_SHOW);
		GetDlgItem(IDC_STATIC_YALPHA_PARAM7)->ShowWindow(SW_SHOW);

		GetDlgItem(IDC_EDIT_YALPHA_PARAM2)->ShowWindow(SW_SHOW);
		GetDlgItem(IDC_EDIT_YALPHA_PARAM3)->ShowWindow(SW_SHOW);
		GetDlgItem(IDC_EDIT_YALPHA_PARAM4)->ShowWindow(SW_SHOW);
		GetDlgItem(IDC_EDIT_YALPHA_PARAM5)->ShowWindow(SW_SHOW);
		GetDlgItem(IDC_EDIT_YALPHA_PARAM6)->ShowWindow(SW_SHOW);
		GetDlgItem(IDC_EDIT_YALPHA_PARAM7)->ShowWindow(SW_SHOW);

		GetDlgItem(IDC_STATIC_YALPHA_PARAM2)->SetWindowText(_T("b0 :"));
		GetDlgItem(IDC_STATIC_YALPHA_PARAM3)->SetWindowText(_T("b1 :"));
		GetDlgItem(IDC_STATIC_YALPHA_PARAM4)->SetWindowText(_T("b2 :"));
	}
}

void CInterface_Control_Grue_Dlg::R_PID_Visible(bool visible)
{
	if(visible)
	{
		GetDlgItem(IDC_STATIC_R_PARAM2)->ShowWindow(SW_SHOW);
		GetDlgItem(IDC_STATIC_R_PARAM3)->ShowWindow(SW_SHOW);
		GetDlgItem(IDC_STATIC_R_PARAM4)->ShowWindow(SW_SHOW);
		GetDlgItem(IDC_STATIC_R_PARAM5)->ShowWindow(SW_HIDE);
		GetDlgItem(IDC_STATIC_R_PARAM6)->ShowWindow(SW_HIDE);
		GetDlgItem(IDC_STATIC_R_PARAM7)->ShowWindow(SW_HIDE);

		GetDlgItem(IDC_EDIT_R_PARAM2)->ShowWindow(SW_SHOW);
		GetDlgItem(IDC_EDIT_R_PARAM3)->ShowWindow(SW_SHOW);
		GetDlgItem(IDC_EDIT_R_PARAM4)->ShowWindow(SW_SHOW);
		GetDlgItem(IDC_EDIT_R_PARAM5)->ShowWindow(SW_HIDE);
		GetDlgItem(IDC_EDIT_R_PARAM6)->ShowWindow(SW_HIDE);
		GetDlgItem(IDC_EDIT_R_PARAM7)->ShowWindow(SW_HIDE);

		GetDlgItem(IDC_STATIC_R_PARAM2)->SetWindowText(_T("kp :"));
		GetDlgItem(IDC_STATIC_R_PARAM3)->SetWindowText(_T("kd :"));
		GetDlgItem(IDC_STATIC_R_PARAM4)->SetWindowText(_T("ki :"));
	}

	else
	{
		GetDlgItem(IDC_STATIC_R_PARAM2)->ShowWindow(SW_SHOW);
		GetDlgItem(IDC_STATIC_R_PARAM3)->ShowWindow(SW_SHOW);
		GetDlgItem(IDC_STATIC_R_PARAM4)->ShowWindow(SW_SHOW);
		GetDlgItem(IDC_STATIC_R_PARAM5)->ShowWindow(SW_SHOW);
		GetDlgItem(IDC_STATIC_R_PARAM6)->ShowWindow(SW_SHOW);
		GetDlgItem(IDC_STATIC_R_PARAM7)->ShowWindow(SW_SHOW);

		GetDlgItem(IDC_EDIT_R_PARAM2)->ShowWindow(SW_SHOW);
		GetDlgItem(IDC_EDIT_R_PARAM3)->ShowWindow(SW_SHOW);
		GetDlgItem(IDC_EDIT_R_PARAM4)->ShowWindow(SW_SHOW);
		GetDlgItem(IDC_EDIT_R_PARAM5)->ShowWindow(SW_SHOW);
		GetDlgItem(IDC_EDIT_R_PARAM6)->ShowWindow(SW_SHOW);
		GetDlgItem(IDC_EDIT_R_PARAM7)->ShowWindow(SW_SHOW);

		GetDlgItem(IDC_STATIC_R_PARAM2)->SetWindowText(_T("b0 :"));
		GetDlgItem(IDC_STATIC_R_PARAM3)->SetWindowText(_T("b1 :"));
		GetDlgItem(IDC_STATIC_R_PARAM4)->SetWindowText(_T("b2 :"));
	}
}

void CInterface_Control_Grue_Dlg::OnCbnSelchangeComboYalpha()
{
	int sel = m_comboYalpha.GetCurSel();

	if(sel == 0)
	{
		Yalpha_PID_Visible(true);
		m_param->SetYalphaType(PID);
	}

	else if(sel == 1)
	{
		Yalpha_PID_Visible(false);
		m_param->SetYalphaType(TF);
	}
}


void CInterface_Control_Grue_Dlg::OnCbnSelchangeComboR()
{
	int sel = m_comboR.GetCurSel();

	if(sel == 0)
	{
		R_PID_Visible(true);
		m_param->SetRType(PID);
	}

	else if(sel == 1)
	{
		R_PID_Visible(false);
		m_param->SetRType(TF);
	}
}


void CInterface_Control_Grue_Dlg::OnTcnSelchangeTabParametres(NMHDR *pNMHDR, LRESULT *pResult)
{
	*pResult = 0;
	int sel = m_tabParam.GetCurSel();

	if(sel == 0)
	{
		Compensateurs_Visible(true);
	}

	else if(sel == 1)
	{
		Compensateurs_Visible(false);
	}
}

//Longue serie de fonction pour les mises a jour des parametres
void CInterface_Control_Grue_Dlg::OnEnSetfocusEditXbetaParam1()
{
	GetDlgItem(IDC_EDIT_XBETA_PARAM1)->GetWindowTextW(m_strTmpComp);
}


void CInterface_Control_Grue_Dlg::OnEnSetfocusEditXbetaParam2()
{
	GetDlgItem(IDC_EDIT_XBETA_PARAM2)->GetWindowTextW(m_strTmpComp);
}


void CInterface_Control_Grue_Dlg::OnEnSetfocusEditXbetaParam3()
{
	GetDlgItem(IDC_EDIT_XBETA_PARAM3)->GetWindowTextW(m_strTmpComp);
}


void CInterface_Control_Grue_Dlg::OnEnSetfocusEditXbetaParam4()
{
	GetDlgItem(IDC_EDIT_XBETA_PARAM4)->GetWindowTextW(m_strTmpComp);
}


void CInterface_Control_Grue_Dlg::OnEnSetfocusEditXbetaParam5()
{
	GetDlgItem(IDC_EDIT_XBETA_PARAM5)->GetWindowTextW(m_strTmpComp);
}


void CInterface_Control_Grue_Dlg::OnEnSetfocusEditXbetaParam6()
{
	GetDlgItem(IDC_EDIT_XBETA_PARAM6)->GetWindowTextW(m_strTmpComp);
}


void CInterface_Control_Grue_Dlg::OnEnSetfocusEditXbetaParam7()
{
	GetDlgItem(IDC_EDIT_XBETA_PARAM7)->GetWindowTextW(m_strTmpComp);
}


void CInterface_Control_Grue_Dlg::OnEnSetfocusEditYalphaParam1()
{
	GetDlgItem(IDC_EDIT_YALPHA_PARAM1)->GetWindowTextW(m_strTmpComp);
}


void CInterface_Control_Grue_Dlg::OnEnSetfocusEditYalphaParam2()
{
	GetDlgItem(IDC_EDIT_YALPHA_PARAM2)->GetWindowTextW(m_strTmpComp);
}


void CInterface_Control_Grue_Dlg::OnEnSetfocusEditYalphaParam3()
{
	GetDlgItem(IDC_EDIT_YALPHA_PARAM3)->GetWindowTextW(m_strTmpComp);
}


void CInterface_Control_Grue_Dlg::OnEnSetfocusEditYalphaParam4()
{
	GetDlgItem(IDC_EDIT_YALPHA_PARAM4)->GetWindowTextW(m_strTmpComp);
}


void CInterface_Control_Grue_Dlg::OnEnSetfocusEditYalphaParam5()
{
	GetDlgItem(IDC_EDIT_YALPHA_PARAM5)->GetWindowTextW(m_strTmpComp);
}


void CInterface_Control_Grue_Dlg::OnEnSetfocusEditYalphaParam6()
{
	GetDlgItem(IDC_EDIT_YALPHA_PARAM6)->GetWindowTextW(m_strTmpComp);
}


void CInterface_Control_Grue_Dlg::OnEnSetfocusEditYalphaParam7()
{
	GetDlgItem(IDC_EDIT_YALPHA_PARAM7)->GetWindowTextW(m_strTmpComp);
}


void CInterface_Control_Grue_Dlg::OnEnSetfocusEditRParam1()
{
	GetDlgItem(IDC_EDIT_R_PARAM1)->GetWindowTextW(m_strTmpComp);
}


void CInterface_Control_Grue_Dlg::OnEnSetfocusEditRParam2()
{
	GetDlgItem(IDC_EDIT_R_PARAM2)->GetWindowTextW(m_strTmpComp);
}


void CInterface_Control_Grue_Dlg::OnEnSetfocusEditRParam3()
{
	GetDlgItem(IDC_EDIT_R_PARAM3)->GetWindowTextW(m_strTmpComp);
}


void CInterface_Control_Grue_Dlg::OnEnSetfocusEditRParam4()
{
	GetDlgItem(IDC_EDIT_R_PARAM4)->GetWindowTextW(m_strTmpComp);
}


void CInterface_Control_Grue_Dlg::OnEnSetfocusEditRParam5()
{
	GetDlgItem(IDC_EDIT_R_PARAM5)->GetWindowTextW(m_strTmpComp);
}


void CInterface_Control_Grue_Dlg::OnEnSetfocusEditRParam6()
{
	GetDlgItem(IDC_EDIT_R_PARAM6)->GetWindowTextW(m_strTmpComp);
}


void CInterface_Control_Grue_Dlg::OnEnSetfocusEditRParam7()
{
	GetDlgItem(IDC_EDIT_R_PARAM7)->GetWindowTextW(m_strTmpComp);
}


void CInterface_Control_Grue_Dlg::OnEnKillfocusEditXbetaParam1()
{
	CString value;
	GetDlgItem(IDC_EDIT_XBETA_PARAM1)->GetWindowTextW(value);

	if(value != m_strTmpComp)
	{
		m_param->SetKb(_wtof(value));
	}
}


void CInterface_Control_Grue_Dlg::OnEnKillfocusEditXbetaParam2()
{
	CString value;
	GetDlgItem(IDC_EDIT_XBETA_PARAM2)->GetWindowTextW(value);

	if(value != m_strTmpComp)
	{
		int sel = m_comboXbeta.GetCurSel();

		if(sel == 0)
		{
			m_param->SetXbetaKp(_wtof(value));
		}

		else if(sel == 1)
		{
			m_param->SetXbetaA0(_wtof(value));
		}
	}
}


void CInterface_Control_Grue_Dlg::OnEnKillfocusEditXbetaParam3()
{
	CString value;
	GetDlgItem(IDC_EDIT_XBETA_PARAM3)->GetWindowTextW(value);

	if(value != m_strTmpComp)
	{
		int sel = m_comboXbeta.GetCurSel();

		if(sel == 0)
		{
			m_param->SetXbetaKd(_wtof(value));
		}

		else if(sel == 1)
		{
			m_param->SetXbetaA1(_wtof(value));
		}
	}
}


void CInterface_Control_Grue_Dlg::OnEnKillfocusEditXbetaParam4()
{
	CString value;
	GetDlgItem(IDC_EDIT_XBETA_PARAM4)->GetWindowTextW(value);

	if(value != m_strTmpComp)
	{
		int sel = m_comboXbeta.GetCurSel();

		if(sel == 0)
		{
			m_param->SetXbetaKi(_wtof(value));
		}

		else if(sel == 1)
		{
			m_param->SetXbetaA2(_wtof(value));
		}
	}
}


void CInterface_Control_Grue_Dlg::OnEnKillfocusEditXbetaParam5()
{
	CString value;
	GetDlgItem(IDC_EDIT_XBETA_PARAM5)->GetWindowTextW(value);

	if(value != m_strTmpComp)
	{
		m_param->SetXbetaB0(_wtof(value));
	}
}


void CInterface_Control_Grue_Dlg::OnEnKillfocusEditXbetaParam6()
{
	CString value;
	GetDlgItem(IDC_EDIT_XBETA_PARAM6)->GetWindowTextW(value);

	if(value != m_strTmpComp)
	{
		m_param->SetXbetaB1(_wtof(value));
	}
}


void CInterface_Control_Grue_Dlg::OnEnKillfocusEditXbetaParam7()
{
	CString value;
	GetDlgItem(IDC_EDIT_XBETA_PARAM7)->GetWindowTextW(value);

	if(value != m_strTmpComp)
	{
		m_param->SetXbetaB2(_wtof(value));
	}
}


void CInterface_Control_Grue_Dlg::OnEnKillfocusEditYalphaParam1()
{
	CString value;
	GetDlgItem(IDC_EDIT_YALPHA_PARAM1)->GetWindowTextW(value);

	if(value != m_strTmpComp)
	{
		m_param->SetKa(_wtof(value));
	}
}


void CInterface_Control_Grue_Dlg::OnEnKillfocusEditYalphaParam2()
{
	CString value;
	GetDlgItem(IDC_EDIT_YALPHA_PARAM2)->GetWindowTextW(value);

	if(value != m_strTmpComp)
	{
		int sel = m_comboYalpha.GetCurSel();

		if(sel == 0)
		{
			m_param->SetYalphaKp(_wtof(value));
		}

		else if(sel == 1)
		{
			m_param->SetYalphaA0(_wtof(value));
		}
	}
}


void CInterface_Control_Grue_Dlg::OnEnKillfocusEditYalphaParam3()
{
	CString value;
	GetDlgItem(IDC_EDIT_YALPHA_PARAM3)->GetWindowTextW(value);

	if(value != m_strTmpComp)
	{
		int sel = m_comboYalpha.GetCurSel();

		if(sel == 0)
		{
			m_param->SetYalphaKd(_wtof(value));
		}

		else if(sel == 1)
		{
			m_param->SetYalphaA1(_wtof(value));
		}
	}
}


void CInterface_Control_Grue_Dlg::OnEnKillfocusEditYalphaParam4()
{
	CString value;
	GetDlgItem(IDC_EDIT_YALPHA_PARAM4)->GetWindowTextW(value);

	if(value != m_strTmpComp)
	{
		int sel = m_comboYalpha.GetCurSel();

		if(sel == 0)
		{
			m_param->SetYalphaKi(_wtof(value));
		}

		else if(sel == 1)
		{
			m_param->SetYalphaA2(_wtof(value));
		}
	}
}


void CInterface_Control_Grue_Dlg::OnEnKillfocusEditYalphaParam5()
{
	CString value;
	GetDlgItem(IDC_EDIT_YALPHA_PARAM5)->GetWindowTextW(value);

	if(value != m_strTmpComp)
	{
		m_param->SetYalphaB0(_wtof(value));
	}
}


void CInterface_Control_Grue_Dlg::OnEnKillfocusEditYalphaParam6()
{
	CString value;
	GetDlgItem(IDC_EDIT_YALPHA_PARAM6)->GetWindowTextW(value);

	if(value != m_strTmpComp)
	{
		m_param->SetYalphaB1(_wtof(value));
	}
}


void CInterface_Control_Grue_Dlg::OnEnKillfocusEditYalphaParam7()
{
	CString value;
	GetDlgItem(IDC_EDIT_YALPHA_PARAM7)->GetWindowTextW(value);

	if(value != m_strTmpComp)
	{
		m_param->SetYalphaB2(_wtof(value));
	}
}


void CInterface_Control_Grue_Dlg::OnEnKillfocusEditRParam1()
{
	//Fait rien pour l'instant car je ne sais pas si on a besoin du champ
}



void CInterface_Control_Grue_Dlg::OnEnKillfocusEditRParam2()
{
	CString value;
	GetDlgItem(IDC_EDIT_R_PARAM2)->GetWindowTextW(value);

	if(value != m_strTmpComp)
	{
		int sel = m_comboR.GetCurSel();

		if(sel == 0)
		{
			m_param->SetR_Kp(_wtof(value));
		}

		else if(sel == 1)
		{
			m_param->SetR_A0(_wtof(value));
		}
	}
}


void CInterface_Control_Grue_Dlg::OnEnKillfocusEditRParam3()
{
	CString value;
	GetDlgItem(IDC_EDIT_R_PARAM3)->GetWindowTextW(value);

	if(value != m_strTmpComp)
	{
		int sel = m_comboR.GetCurSel();

		if(sel == 0)
		{
			m_param->SetR_Kd(_wtof(value));
		}

		else if(sel == 1)
		{
			m_param->SetR_A1(_wtof(value));
		}
	}
}


void CInterface_Control_Grue_Dlg::OnEnKillfocusEditRParam4()
{
	CString value;
	GetDlgItem(IDC_EDIT_R_PARAM4)->GetWindowTextW(value);

	if(value != m_strTmpComp)
	{
		int sel = m_comboR.GetCurSel();

		if(sel == 0)
		{
			m_param->SetR_Ki(_wtof(value));
		}

		else if(sel == 1)
		{
			m_param->SetR_A2(_wtof(value));
		}
	}
}


void CInterface_Control_Grue_Dlg::OnEnKillfocusEditRParam5()
{
	CString value;
	GetDlgItem(IDC_EDIT_R_PARAM5)->GetWindowTextW(value);

	if(value != m_strTmpComp)
	{
		m_param->SetR_B0(_wtof(value));
	}
}


void CInterface_Control_Grue_Dlg::OnEnKillfocusEditRParam6()
{
	CString value;
	GetDlgItem(IDC_EDIT_R_PARAM6)->GetWindowTextW(value);

	if(value != m_strTmpComp)
	{
		m_param->SetR_B1(_wtof(value));
	}
}


void CInterface_Control_Grue_Dlg::OnEnKillfocusEditRParam7()
{
	CString value;
	GetDlgItem(IDC_EDIT_R_PARAM7)->GetWindowTextW(value);

	if(value != m_strTmpComp)
	{
		m_param->SetR_B2(_wtof(value));
	}
}

void CInterface_Control_Grue_Dlg::Traj_Live_Enabled(bool enabled)
{
	if(enabled)
	{
		GetDlgItem(IDC_STATIC_TRAJ_X)->EnableWindow(true);
		GetDlgItem(IDC_STATIC_TRAJ_Y)->EnableWindow(true);
		GetDlgItem(IDC_STATIC_TRAJ_Z)->EnableWindow(true);
		GetDlgItem(IDC_EDIT_TRAJ_X)->EnableWindow(true);
		GetDlgItem(IDC_EDIT_TRAJ_Y)->EnableWindow(true);
		GetDlgItem(IDC_EDIT_TRAJ_Z)->EnableWindow(true);

		GetDlgItem(IDC_EDIT_TRAJ_PATH)->EnableWindow(false);
		GetDlgItem(IDC_BUTTON_PARCOURIR)->EnableWindow(false);
	}

	else
	{
		GetDlgItem(IDC_STATIC_TRAJ_X)->EnableWindow(false);
		GetDlgItem(IDC_STATIC_TRAJ_Y)->EnableWindow(false);
		GetDlgItem(IDC_STATIC_TRAJ_Z)->EnableWindow(false);
		GetDlgItem(IDC_EDIT_TRAJ_X)->EnableWindow(false);
		GetDlgItem(IDC_EDIT_TRAJ_Y)->EnableWindow(false);
		GetDlgItem(IDC_EDIT_TRAJ_Z)->EnableWindow(false);

		GetDlgItem(IDC_EDIT_TRAJ_PATH)->EnableWindow(true);
		GetDlgItem(IDC_BUTTON_PARCOURIR)->EnableWindow(true);
	}
}

void CInterface_Control_Grue_Dlg::Traj_Disabled(bool disabled)
{
	if(disabled)
	{
		GetDlgItem(IDC_RADIO_TRAJ_LIVE)->EnableWindow(false);
		GetDlgItem(IDC_RADIO_TRAJ_PREDEF)->EnableWindow(false);

		GetDlgItem(IDC_STATIC_TRAJ_X)->EnableWindow(false);
		GetDlgItem(IDC_STATIC_TRAJ_Y)->EnableWindow(false);
		GetDlgItem(IDC_STATIC_TRAJ_Z)->EnableWindow(false);
		GetDlgItem(IDC_EDIT_TRAJ_X)->EnableWindow(false);
		GetDlgItem(IDC_EDIT_TRAJ_Y)->EnableWindow(false);
		GetDlgItem(IDC_EDIT_TRAJ_Z)->EnableWindow(false);

		GetDlgItem(IDC_EDIT_TRAJ_PATH)->EnableWindow(false);
		GetDlgItem(IDC_BUTTON_PARCOURIR)->EnableWindow(false);
	}

	else
	{
		GetDlgItem(IDC_RADIO_TRAJ_LIVE)->EnableWindow(true);
		GetDlgItem(IDC_RADIO_TRAJ_PREDEF)->EnableWindow(true);

		if(((CButton*)GetDlgItem(IDC_RADIO_TRAJ_LIVE))->GetCheck() == BST_CHECKED)
		{
			Traj_Live_Enabled(true);
		}

		else if(((CButton*)GetDlgItem(IDC_RADIO_TRAJ_PREDEF))->GetCheck() == BST_CHECKED)
		{
			Traj_Live_Enabled(false);
		}
	}
}

void CInterface_Control_Grue_Dlg::OnBnClickedRadioTrajLive()
{
	((CButton*)GetDlgItem(IDC_RADIO_TRAJ_PREDEF))->SetCheck(false);
	Traj_Live_Enabled(true);
}


void CInterface_Control_Grue_Dlg::OnBnClickedRadioTrajPredef()
{
	((CButton*)GetDlgItem(IDC_RADIO_TRAJ_LIVE))->SetCheck(false);
	Traj_Live_Enabled(false);
}


void CInterface_Control_Grue_Dlg::OnEnSetfocusEditTrajX()
{
	GetDlgItem(IDC_EDIT_TRAJ_X)->GetWindowTextW(m_strTmpComp);
}


void CInterface_Control_Grue_Dlg::OnEnSetfocusEditTrajY()
{
	GetDlgItem(IDC_EDIT_TRAJ_Y)->GetWindowTextW(m_strTmpComp);
}


void CInterface_Control_Grue_Dlg::OnEnSetfocusEditTrajZ()
{
	GetDlgItem(IDC_EDIT_TRAJ_Z)->GetWindowTextW(m_strTmpComp);
}


void CInterface_Control_Grue_Dlg::OnEnKillfocusEditTrajX()
{
	CString value;
	GetDlgItem(IDC_EDIT_TRAJ_X)->GetWindowTextW(value);

	if(value != m_strTmpComp)
	{
		m_param->SetTrajX(_wtof(value));
	}
}


void CInterface_Control_Grue_Dlg::OnEnKillfocusEditTrajY()
{
	CString value;
	GetDlgItem(IDC_EDIT_TRAJ_Y)->GetWindowTextW(value);

	if(value != m_strTmpComp)
	{
		m_param->SetTrajY(_wtof(value));
	}
}


void CInterface_Control_Grue_Dlg::OnEnKillfocusEditTrajZ()
{
	CString value;
	GetDlgItem(IDC_EDIT_TRAJ_Y)->GetWindowTextW(value);

	if(value != m_strTmpComp)
	{
		m_param->SetTrajY(_wtof(value));
	}
}


void CInterface_Control_Grue_Dlg::OnBnClickedButtonParcourir()
{
	CFileDialog fileBrw(TRUE, NULL, m_param->GetTrajPath(), OFN_READONLY|OFN_FILEMUSTEXIST, _T("BIN Files (*.bin)|*.bin||"), this);

	if(fileBrw.DoModal() == IDOK)
	{
      GetDlgItem(IDC_EDIT_TRAJ_PATH)->SetWindowText(fileBrw.GetPathName());
	  m_param->SetTrajPath(fileBrw.GetPathName());
    }
}

void CInterface_Control_Grue_Dlg::Msg_Status(CString msg)
{
	m_STB_StatusBar.SetPaneText(m_STB_StatusBar.CommandToIndex(ID_INDICATOR_LOG), (LPCTSTR)msg);
}