
// Interface_Control_GrueDlg.cpp : implementation file
//

#include "stdafx.h"
#include "Interface_Control_Grue.h"
#include "Interface_Control_GrueDlg.h"
#include "afxdialogex.h"
#include <math.h>
#include "ParametresDlg.h"
#include "Parametres.h"
#include "CFileINI.h"

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
	DDX_Control(pDX, IDC_COMBO_TRAJ_MODE, m_comboTraj);
	DDX_Control(pDX, IDC_BUTTON_STOP, m_buttonStop);
}

BEGIN_MESSAGE_MAP(CInterface_Control_Grue_Dlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_WM_TIMER() // to use timers
	ON_MESSAGE(ERR_WORKER_THREAD, &CInterface_Control_Grue_Dlg::OnErrWorkerThread)
	ON_MESSAGE(POST_CAPTEURS_VALUES, &CInterface_Control_Grue_Dlg::OnPostCapteursValues)
	ON_MESSAGE(CRANE_WAIT_DONE, &CInterface_Control_Grue_Dlg::OnCraneWaitDone)
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
	ON_CBN_SELCHANGE(IDC_COMBO_TRAJ_MODE, &CInterface_Control_Grue_Dlg::OnCbnSelchangeComboTrajMode)
	ON_BN_CLICKED(IDC_BUTTON_SAUVEGARDER, &CInterface_Control_Grue_Dlg::OnBnClickedButtonSauvegarder)
	ON_BN_CLICKED(IDC_BUTTON_RESTAURER, &CInterface_Control_Grue_Dlg::OnBnClickedButtonRestaurer)
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

	//Combo traj init
	m_comboTraj.InsertString(0, _T("Arret"));
	m_comboTraj.InsertString(1, _T("Boucle"));
	m_comboTraj.InsertString(2, _T("Maintient"));

	m_comboTraj.SetCurSel(0);

	//Trajectoire init
	((CButton*)GetDlgItem(IDC_RADIO_TRAJ_LIVE))->SetCheck(true);
	Traj_Live_Enabled(true);

	//On regarde si le fichier .ini existe
	m_iniFile = new CFileINI(NULL);

	if(INIExists())
	{
		LoadINI();
		ShowAllParam();
	}

	//On load les images pour le bouton stop
	bmpStop.LoadBitmapW(IDB_BITMAP_STOP1);
	bmpStopEnfonce.LoadBitmapW(IDB_BITMAP_STOP2);
	m_buttonStop.SetBitmap(bmpStop);

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
	Stop();

	if(m_buttonStop.GetBitmap() == bmpStop)
	{
		m_buttonStop.SetBitmap(bmpStopEnfonce);
		//m_param->Stop();
		GetDlgItem(IDC_BUTTON_RESET)->EnableWindow(false);
		GetDlgItem(IDC_BUTTON_START)->EnableWindow(false);
	}

	else if(m_buttonStop.GetBitmap() == bmpStopEnfonce)
	{
		m_buttonStop.SetBitmap(bmpStop);

		m_param->Reset();
		m_param->Wait(STOP, true);

		GetDlgItem(IDC_BUTTON_RESET)->EnableWindow(true);
		GetDlgItem(IDC_BUTTON_START)->EnableWindow(true);
	}
}

void CInterface_Control_Grue_Dlg::OnBnClickedButtonStart()
{
	Start();
}


void CInterface_Control_Grue_Dlg::OnBnClickedButtonReset()
{
	m_param->Reset();
	m_param->Wait(STOP, true);
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
	m_param->UpdateCraneComp();
	m_param->Reset();
	m_param->Wait(STOP, false);
	m_param->UpdateCraneTrajPath();
	m_param->UpdateCraneTrajMode();

	//On commence a recolter les valeurs des capteurs
	m_param->SetCalcul(true);
	AfxBeginThread(Calcul_Grue, m_param);

	Traj_Disabled(true);
	Comp_Disabled(true);

	//Debut du deplacement de la grue
	//m_param->Run(CLOSE, RESTART);
	//m_param->Wait(STOP, false);
}

void CInterface_Control_Grue_Dlg::Stop()
{
	
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
			Sleep(500);
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

	ShowXbetaParam();
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


		GetDlgItem(IDC_STATIC_TRAJ_MODE)->ShowWindow(SW_HIDE);
		GetDlgItem(IDC_COMBO_TRAJ_MODE)->ShowWindow(SW_HIDE);
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

		GetDlgItem(IDC_STATIC_TRAJ_MODE)->ShowWindow(SW_SHOW);
		GetDlgItem(IDC_COMBO_TRAJ_MODE)->ShowWindow(SW_SHOW);
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

	ShowYalphaParam();
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

	ShowR_Param();
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
		GetDlgItem(IDC_STATIC_TRAJ_MODE)->EnableWindow(false);
		GetDlgItem(IDC_COMBO_TRAJ_MODE)->EnableWindow(false);

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
		GetDlgItem(IDC_STATIC_TRAJ_MODE)->EnableWindow(true);
		GetDlgItem(IDC_COMBO_TRAJ_MODE)->EnableWindow(true);

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

void CInterface_Control_Grue_Dlg::OnCbnSelchangeComboTrajMode()
{
	int sel = m_comboTraj.GetCurSel();

	if(sel == 0)
	{
		m_param->SetTrajMode(STOP);
	}

	else if(sel == 1)
	{
		m_param->SetTrajMode(LOOP);
	}

	else if(sel == 2)
	{
		m_param->SetTrajMode(HOLD);
	}
}

void CInterface_Control_Grue_Dlg::LoadINI()
{
	//xbeta
	m_param->SetKb(CharToFloat(m_iniFile->ReadString("xbeta", "kb")));

	if(m_iniFile->ReadString("xbeta", "mode") == "PID")
	{
		m_param->SetXbetaType(PID);
	}

	else
	{
		m_param->SetXbetaType(TF);
	}
	
	m_param->SetXbetaKp(CharToFloat(m_iniFile->ReadString("xbeta", "kp")));
	m_param->SetXbetaKd(CharToFloat(m_iniFile->ReadString("xbeta", "kd")));
	m_param->SetXbetaKi(CharToFloat(m_iniFile->ReadString("xbeta", "ki")));
	m_param->SetXbetaA0(CharToFloat(m_iniFile->ReadString("xbeta", "a0")));
	m_param->SetXbetaA1(CharToFloat(m_iniFile->ReadString("xbeta", "a1")));
	m_param->SetXbetaA2(CharToFloat(m_iniFile->ReadString("xbeta", "a2")));
	m_param->SetXbetaB0(CharToFloat(m_iniFile->ReadString("xbeta", "b0")));
	m_param->SetXbetaB1(CharToFloat(m_iniFile->ReadString("xbeta", "b1")));
	m_param->SetXbetaB2(CharToFloat(m_iniFile->ReadString("xbeta", "b2")));

	//yalpha
	m_param->SetKa(CharToFloat(m_iniFile->ReadString("yalpha", "ka")));

	if(m_iniFile->ReadString("yalpha", "mode") == "PID")
	{
		m_param->SetYalphaType(PID);
	}

	else
	{
		m_param->SetYalphaType(TF);
	}
	
	m_param->SetYalphaKp(CharToFloat(m_iniFile->ReadString("yalpha", "kp")));
	m_param->SetYalphaKd(CharToFloat(m_iniFile->ReadString("yalpha", "kd")));
	m_param->SetYalphaKi(CharToFloat(m_iniFile->ReadString("yalpha", "ki")));
	m_param->SetYalphaA0(CharToFloat(m_iniFile->ReadString("yalpha", "a0")));
	m_param->SetYalphaA1(CharToFloat(m_iniFile->ReadString("yalpha", "a1")));
	m_param->SetYalphaA2(CharToFloat(m_iniFile->ReadString("yalpha", "a2")));
	m_param->SetYalphaB0(CharToFloat(m_iniFile->ReadString("yalpha", "b0")));
	m_param->SetYalphaB1(CharToFloat(m_iniFile->ReadString("yalpha", "b1")));
	m_param->SetYalphaB2(CharToFloat(m_iniFile->ReadString("yalpha", "b2")));

	//R
	if(m_iniFile->ReadString("r", "mode") == "PID")
	{
		m_param->SetRType(PID);
	}

	else
	{
		m_param->SetRType(TF);
	}
	
	m_param->SetR_Kp(CharToFloat(m_iniFile->ReadString("r", "kp")));
	m_param->SetR_Kd(CharToFloat(m_iniFile->ReadString("r", "kd")));
	m_param->SetR_Ki(CharToFloat(m_iniFile->ReadString("r", "ki")));
	m_param->SetR_A0(CharToFloat(m_iniFile->ReadString("r", "a0")));
	m_param->SetR_A1(CharToFloat(m_iniFile->ReadString("r", "a1")));
	m_param->SetR_A2(CharToFloat(m_iniFile->ReadString("r", "a2")));
	m_param->SetR_B0(CharToFloat(m_iniFile->ReadString("r", "b0")));
	m_param->SetR_B1(CharToFloat(m_iniFile->ReadString("r", "b1")));
	m_param->SetR_B2(CharToFloat(m_iniFile->ReadString("r", "b2")));

	//Trajectoire
	m_param->SetTrajMode(CharToFloat(m_iniFile->ReadString("trajectoire", "mode")));
	m_strTmp = m_iniFile->ReadString("trajectoire", "path");
	m_param->SetTrajPath(m_strTmp);
}

void CInterface_Control_Grue_Dlg::SaveINI()
{
	//xbeta
	m_iniFile->WriteString("xbeta", "kb", CT2CA(floatToString(m_param->GetKb())));

	if(m_param->GetXbetaType() == PID)
	{
		m_iniFile->WriteString("xbeta", "mode", "PID");
	}

	else
	{
		m_iniFile->WriteString("xbeta", "mode", "TF");
	}
	
	m_iniFile->WriteString("xbeta", "kp", CT2CA(floatToString(m_param->GetXbetaKp())));
	m_iniFile->WriteString("xbeta", "kd", CT2CA(floatToString(m_param->GetXbetaKd())));
	m_iniFile->WriteString("xbeta", "ki", CT2CA(floatToString(m_param->GetXbetaKi())));
	m_iniFile->WriteString("xbeta", "a0", CT2CA(floatToString(m_param->GetXbetaA0())));
	m_iniFile->WriteString("xbeta", "a1", CT2CA(floatToString(m_param->GetXbetaA1())));
	m_iniFile->WriteString("xbeta", "a2", CT2CA(floatToString(m_param->GetXbetaA2())));
	m_iniFile->WriteString("xbeta", "b0", CT2CA(floatToString(m_param->GetXbetaB0())));
	m_iniFile->WriteString("xbeta", "b1", CT2CA(floatToString(m_param->GetXbetaB1())));
	m_iniFile->WriteString("xbeta", "b2", CT2CA(floatToString(m_param->GetXbetaB2())));

	//yalpha
	m_iniFile->WriteString("yalpha", "ka", CT2CA(floatToString(m_param->GetKa())));

	if(m_param->GetYalphaType() == PID)
	{
		m_iniFile->WriteString("yalpha", "mode", "PID");
	}

	else
	{
		m_iniFile->WriteString("yalpha", "mode", "TF");
	}

	m_iniFile->WriteString("yalpha", "kp", CT2CA(floatToString(m_param->GetYalphaKp())));
	m_iniFile->WriteString("yalpha", "kd", CT2CA(floatToString(m_param->GetYalphaKd())));
	m_iniFile->WriteString("yalpha", "ki", CT2CA(floatToString(m_param->GetYalphaKi())));
	m_iniFile->WriteString("yalpha", "a0", CT2CA(floatToString(m_param->GetYalphaA0())));
	m_iniFile->WriteString("yalpha", "a1", CT2CA(floatToString(m_param->GetYalphaA1())));
	m_iniFile->WriteString("yalpha", "a2", CT2CA(floatToString(m_param->GetYalphaA2())));
	m_iniFile->WriteString("yalpha", "b0", CT2CA(floatToString(m_param->GetYalphaB0())));
	m_iniFile->WriteString("yalpha", "b1", CT2CA(floatToString(m_param->GetYalphaB1())));
	m_iniFile->WriteString("yalpha", "b2", CT2CA(floatToString(m_param->GetYalphaB2())));

	//R
	if(m_param->GetRType() == PID)
	{
		m_iniFile->WriteString("r", "mode", "PID");
	}

	else
	{
		m_iniFile->WriteString("r", "mode", "TF");
	}

	m_iniFile->WriteString("r", "kp", CT2CA(floatToString(m_param->GetR_Kp())));
	m_iniFile->WriteString("r", "kd", CT2CA(floatToString(m_param->GetR_Kd())));
	m_iniFile->WriteString("r", "ki", CT2CA(floatToString(m_param->GetR_Ki())));
	m_iniFile->WriteString("r", "a0", CT2CA(floatToString(m_param->GetR_A0())));
	m_iniFile->WriteString("r", "a1", CT2CA(floatToString(m_param->GetR_A1())));
	m_iniFile->WriteString("r", "a2", CT2CA(floatToString(m_param->GetR_A2())));
	m_iniFile->WriteString("r", "b0", CT2CA(floatToString(m_param->GetR_B0())));
	m_iniFile->WriteString("r", "b1", CT2CA(floatToString(m_param->GetR_B1())));
	m_iniFile->WriteString("r", "b2", CT2CA(floatToString(m_param->GetR_B2())));

	//Trajectoire
	m_iniFile->WriteString("trajectoire", "mode", CT2CA(floatToString(m_param->GetTrajMode())));
	m_iniFile->WriteString("trajectoire", "path", CT2CA(m_param->GetTrajPath()));
}

bool CInterface_Control_Grue_Dlg::INIExists()
{
	return true;
}

void CInterface_Control_Grue_Dlg::OnBnClickedButtonSauvegarder()
{
	SaveINI();
}

CString CInterface_Control_Grue_Dlg::floatToString(float f)
{
	m_strTmp.Format(_T("%f"), f);
	return m_strTmp;
}

float CInterface_Control_Grue_Dlg::CharToFloat(char* c)
{
	m_strTmp = c;
	return _wtof(m_strTmp);
}

void CInterface_Control_Grue_Dlg::ShowAllParam()
{
	GetDlgItem(IDC_EDIT_XBETA_PARAM1)->SetWindowTextW(floatToString(m_param->GetKb()));

	if(m_param->GetXbetaType() == PID)
	{
		m_comboXbeta.SetCurSel(0);
		Xbeta_PID_Visible(true);

		GetDlgItem(IDC_EDIT_XBETA_PARAM2)->SetWindowTextW(floatToString(m_param->GetXbetaKp()));
		GetDlgItem(IDC_EDIT_XBETA_PARAM3)->SetWindowTextW(floatToString(m_param->GetXbetaKd()));
		GetDlgItem(IDC_EDIT_XBETA_PARAM4)->SetWindowTextW(floatToString(m_param->GetXbetaKi()));
	}

	else
	{
		m_comboXbeta.SetCurSel(1);
		Xbeta_PID_Visible(false);

		GetDlgItem(IDC_EDIT_XBETA_PARAM2)->SetWindowTextW(floatToString(m_param->GetXbetaB0()));
		GetDlgItem(IDC_EDIT_XBETA_PARAM3)->SetWindowTextW(floatToString(m_param->GetXbetaB1()));
		GetDlgItem(IDC_EDIT_XBETA_PARAM4)->SetWindowTextW(floatToString(m_param->GetXbetaB2()));
		GetDlgItem(IDC_EDIT_XBETA_PARAM5)->SetWindowTextW(floatToString(m_param->GetXbetaA0()));
		GetDlgItem(IDC_EDIT_XBETA_PARAM6)->SetWindowTextW(floatToString(m_param->GetXbetaA1()));
		GetDlgItem(IDC_EDIT_XBETA_PARAM7)->SetWindowTextW(floatToString(m_param->GetXbetaA2()));
	}

	GetDlgItem(IDC_EDIT_YALPHA_PARAM1)->SetWindowTextW(floatToString(m_param->GetKa()));

	if(m_param->GetYalphaType() == PID)
	{
		m_comboYalpha.SetCurSel(0);
		Yalpha_PID_Visible(true);

		GetDlgItem(IDC_EDIT_YALPHA_PARAM2)->SetWindowTextW(floatToString(m_param->GetYalphaKp()));
		GetDlgItem(IDC_EDIT_YALPHA_PARAM3)->SetWindowTextW(floatToString(m_param->GetYalphaKd()));
		GetDlgItem(IDC_EDIT_YALPHA_PARAM4)->SetWindowTextW(floatToString(m_param->GetYalphaKi()));
	}

	else
	{
		m_comboYalpha.SetCurSel(1);
		Yalpha_PID_Visible(false);

		GetDlgItem(IDC_EDIT_YALPHA_PARAM2)->SetWindowTextW(floatToString(m_param->GetYalphaB0()));
		GetDlgItem(IDC_EDIT_YALPHA_PARAM3)->SetWindowTextW(floatToString(m_param->GetYalphaB1()));
		GetDlgItem(IDC_EDIT_YALPHA_PARAM4)->SetWindowTextW(floatToString(m_param->GetYalphaB2()));
		GetDlgItem(IDC_EDIT_YALPHA_PARAM5)->SetWindowTextW(floatToString(m_param->GetYalphaA0()));
		GetDlgItem(IDC_EDIT_YALPHA_PARAM6)->SetWindowTextW(floatToString(m_param->GetYalphaA1()));
		GetDlgItem(IDC_EDIT_YALPHA_PARAM7)->SetWindowTextW(floatToString(m_param->GetYalphaA2()));
	}

	if(m_param->GetRType() == PID)
	{
		m_comboR.SetCurSel(0);
		R_PID_Visible(true);

		GetDlgItem(IDC_EDIT_R_PARAM2)->SetWindowTextW(floatToString(m_param->GetR_Kp()));
		GetDlgItem(IDC_EDIT_R_PARAM3)->SetWindowTextW(floatToString(m_param->GetR_Kd()));
		GetDlgItem(IDC_EDIT_R_PARAM4)->SetWindowTextW(floatToString(m_param->GetR_Ki()));
	}

	else
	{
		m_comboR.SetCurSel(1);
		R_PID_Visible(false);

		GetDlgItem(IDC_EDIT_R_PARAM2)->SetWindowTextW(floatToString(m_param->GetR_B0()));
		GetDlgItem(IDC_EDIT_R_PARAM3)->SetWindowTextW(floatToString(m_param->GetR_B1()));
		GetDlgItem(IDC_EDIT_R_PARAM4)->SetWindowTextW(floatToString(m_param->GetR_B2()));
		GetDlgItem(IDC_EDIT_R_PARAM5)->SetWindowTextW(floatToString(m_param->GetR_A0()));
		GetDlgItem(IDC_EDIT_R_PARAM6)->SetWindowTextW(floatToString(m_param->GetR_A1()));
		GetDlgItem(IDC_EDIT_R_PARAM7)->SetWindowTextW(floatToString(m_param->GetR_A2()));
	}
	
	if(m_param->GetTrajMode() == 0)
	{
		m_comboTraj.SetCurSel(0);
	}

	else if(m_param->GetTrajMode() == 1)
	{
		m_comboTraj.SetCurSel(1);
	}

	else if(m_param->GetTrajMode() == 2)
	{
		m_comboTraj.SetCurSel(2);
	}

	GetDlgItem(IDC_EDIT_TRAJ_PATH)->SetWindowTextW(m_param->GetTrajPath());
}

void CInterface_Control_Grue_Dlg::ShowXbetaParam()
{
	if(m_param->GetXbetaType() == PID)
	{
		m_comboXbeta.SetCurSel(0);
		Xbeta_PID_Visible(true);

		GetDlgItem(IDC_EDIT_XBETA_PARAM2)->SetWindowTextW(floatToString(m_param->GetXbetaKp()));
		GetDlgItem(IDC_EDIT_XBETA_PARAM3)->SetWindowTextW(floatToString(m_param->GetXbetaKd()));
		GetDlgItem(IDC_EDIT_XBETA_PARAM4)->SetWindowTextW(floatToString(m_param->GetXbetaKi()));
	}

	else
	{
		m_comboXbeta.SetCurSel(1);
		Xbeta_PID_Visible(false);

		GetDlgItem(IDC_EDIT_XBETA_PARAM2)->SetWindowTextW(floatToString(m_param->GetXbetaB0()));
		GetDlgItem(IDC_EDIT_XBETA_PARAM3)->SetWindowTextW(floatToString(m_param->GetXbetaB1()));
		GetDlgItem(IDC_EDIT_XBETA_PARAM4)->SetWindowTextW(floatToString(m_param->GetXbetaB2()));
		GetDlgItem(IDC_EDIT_XBETA_PARAM5)->SetWindowTextW(floatToString(m_param->GetXbetaA0()));
		GetDlgItem(IDC_EDIT_XBETA_PARAM6)->SetWindowTextW(floatToString(m_param->GetXbetaA1()));
		GetDlgItem(IDC_EDIT_XBETA_PARAM7)->SetWindowTextW(floatToString(m_param->GetXbetaA2()));
	}
}

void CInterface_Control_Grue_Dlg::ShowYalphaParam()
{
	if(m_param->GetYalphaType() == PID)
	{
		m_comboYalpha.SetCurSel(0);
		Yalpha_PID_Visible(true);

		GetDlgItem(IDC_EDIT_YALPHA_PARAM2)->SetWindowTextW(floatToString(m_param->GetYalphaKp()));
		GetDlgItem(IDC_EDIT_YALPHA_PARAM3)->SetWindowTextW(floatToString(m_param->GetYalphaKd()));
		GetDlgItem(IDC_EDIT_YALPHA_PARAM4)->SetWindowTextW(floatToString(m_param->GetYalphaKi()));
	}

	else
	{
		m_comboYalpha.SetCurSel(1);
		Yalpha_PID_Visible(false);

		GetDlgItem(IDC_EDIT_YALPHA_PARAM2)->SetWindowTextW(floatToString(m_param->GetYalphaB0()));
		GetDlgItem(IDC_EDIT_YALPHA_PARAM3)->SetWindowTextW(floatToString(m_param->GetYalphaB1()));
		GetDlgItem(IDC_EDIT_YALPHA_PARAM4)->SetWindowTextW(floatToString(m_param->GetYalphaB2()));
		GetDlgItem(IDC_EDIT_YALPHA_PARAM5)->SetWindowTextW(floatToString(m_param->GetYalphaA0()));
		GetDlgItem(IDC_EDIT_YALPHA_PARAM6)->SetWindowTextW(floatToString(m_param->GetYalphaA1()));
		GetDlgItem(IDC_EDIT_YALPHA_PARAM7)->SetWindowTextW(floatToString(m_param->GetYalphaA2()));
	}
}

void CInterface_Control_Grue_Dlg::ShowR_Param()
{
	if(m_param->GetRType() == PID)
	{
		m_comboR.SetCurSel(0);
		R_PID_Visible(true);

		GetDlgItem(IDC_EDIT_R_PARAM2)->SetWindowTextW(floatToString(m_param->GetR_Kp()));
		GetDlgItem(IDC_EDIT_R_PARAM3)->SetWindowTextW(floatToString(m_param->GetR_Kd()));
		GetDlgItem(IDC_EDIT_R_PARAM4)->SetWindowTextW(floatToString(m_param->GetR_Ki()));
	}

	else
	{
		m_comboR.SetCurSel(1);
		R_PID_Visible(false);

		GetDlgItem(IDC_EDIT_R_PARAM2)->SetWindowTextW(floatToString(m_param->GetR_B0()));
		GetDlgItem(IDC_EDIT_R_PARAM3)->SetWindowTextW(floatToString(m_param->GetR_B1()));
		GetDlgItem(IDC_EDIT_R_PARAM4)->SetWindowTextW(floatToString(m_param->GetR_B2()));
		GetDlgItem(IDC_EDIT_R_PARAM5)->SetWindowTextW(floatToString(m_param->GetR_A0()));
		GetDlgItem(IDC_EDIT_R_PARAM6)->SetWindowTextW(floatToString(m_param->GetR_A1()));
		GetDlgItem(IDC_EDIT_R_PARAM7)->SetWindowTextW(floatToString(m_param->GetR_A2()));
	}
}

void CInterface_Control_Grue_Dlg::Comp_Disabled(bool disabled)
{
	if(disabled)
	{
		m_comboXbeta.EnableWindow(false);
		m_comboYalpha.EnableWindow(false);
		m_comboR.EnableWindow(false);

		GetDlgItem(IDC_STATIC_XBETA)->EnableWindow(false);
		GetDlgItem(IDC_STATIC_YALPHA)->EnableWindow(false);
		GetDlgItem(IDC_STATIC_R)->EnableWindow(false);

		GetDlgItem(IDC_STATIC_XBETA_PARAM1)->EnableWindow(false);
		GetDlgItem(IDC_STATIC_XBETA_PARAM2)->EnableWindow(false);
		GetDlgItem(IDC_STATIC_XBETA_PARAM3)->EnableWindow(false);
		GetDlgItem(IDC_STATIC_XBETA_PARAM4)->EnableWindow(false);
		GetDlgItem(IDC_STATIC_XBETA_PARAM5)->EnableWindow(false);
		GetDlgItem(IDC_STATIC_XBETA_PARAM6)->EnableWindow(false);
		GetDlgItem(IDC_STATIC_XBETA_PARAM7)->EnableWindow(false);

		GetDlgItem(IDC_EDIT_XBETA_PARAM1)->EnableWindow(false);
		GetDlgItem(IDC_EDIT_XBETA_PARAM2)->EnableWindow(false);
		GetDlgItem(IDC_EDIT_XBETA_PARAM3)->EnableWindow(false);
		GetDlgItem(IDC_EDIT_XBETA_PARAM4)->EnableWindow(false);
		GetDlgItem(IDC_EDIT_XBETA_PARAM5)->EnableWindow(false);
		GetDlgItem(IDC_EDIT_XBETA_PARAM6)->EnableWindow(false);
		GetDlgItem(IDC_EDIT_XBETA_PARAM7)->EnableWindow(false);

		GetDlgItem(IDC_STATIC_YALPHA_PARAM1)->EnableWindow(false);
		GetDlgItem(IDC_STATIC_YALPHA_PARAM2)->EnableWindow(false);
		GetDlgItem(IDC_STATIC_YALPHA_PARAM3)->EnableWindow(false);
		GetDlgItem(IDC_STATIC_YALPHA_PARAM4)->EnableWindow(false);
		GetDlgItem(IDC_STATIC_YALPHA_PARAM5)->EnableWindow(false);
		GetDlgItem(IDC_STATIC_YALPHA_PARAM6)->EnableWindow(false);
		GetDlgItem(IDC_STATIC_YALPHA_PARAM7)->EnableWindow(false);

		GetDlgItem(IDC_EDIT_YALPHA_PARAM1)->EnableWindow(false);
		GetDlgItem(IDC_EDIT_YALPHA_PARAM2)->EnableWindow(false);
		GetDlgItem(IDC_EDIT_YALPHA_PARAM3)->EnableWindow(false);
		GetDlgItem(IDC_EDIT_YALPHA_PARAM4)->EnableWindow(false);
		GetDlgItem(IDC_EDIT_YALPHA_PARAM5)->EnableWindow(false);
		GetDlgItem(IDC_EDIT_YALPHA_PARAM6)->EnableWindow(false);
		GetDlgItem(IDC_EDIT_YALPHA_PARAM7)->EnableWindow(false);

		GetDlgItem(IDC_STATIC_R_PARAM1)->EnableWindow(false);
		GetDlgItem(IDC_STATIC_R_PARAM2)->EnableWindow(false);
		GetDlgItem(IDC_STATIC_R_PARAM3)->EnableWindow(false);
		GetDlgItem(IDC_STATIC_R_PARAM4)->EnableWindow(false);
		GetDlgItem(IDC_STATIC_R_PARAM5)->EnableWindow(false);
		GetDlgItem(IDC_STATIC_R_PARAM6)->EnableWindow(false);
		GetDlgItem(IDC_STATIC_R_PARAM7)->EnableWindow(false);

		GetDlgItem(IDC_EDIT_R_PARAM1)->EnableWindow(false);
		GetDlgItem(IDC_EDIT_R_PARAM2)->EnableWindow(false);
		GetDlgItem(IDC_EDIT_R_PARAM3)->EnableWindow(false);
		GetDlgItem(IDC_EDIT_R_PARAM4)->EnableWindow(false);
		GetDlgItem(IDC_EDIT_R_PARAM5)->EnableWindow(false);
		GetDlgItem(IDC_EDIT_R_PARAM6)->EnableWindow(false);
		GetDlgItem(IDC_EDIT_R_PARAM7)->EnableWindow(false);
	}

	else if(!disabled)
	{
		m_comboXbeta.EnableWindow(true);
		m_comboYalpha.EnableWindow(true);
		m_comboR.EnableWindow(true);

		GetDlgItem(IDC_STATIC_XBETA)->EnableWindow(true);
		GetDlgItem(IDC_STATIC_YALPHA)->EnableWindow(true);
		GetDlgItem(IDC_STATIC_R)->EnableWindow(true);

		GetDlgItem(IDC_STATIC_XBETA_PARAM1)->EnableWindow(true);
		GetDlgItem(IDC_STATIC_XBETA_PARAM2)->EnableWindow(true);
		GetDlgItem(IDC_STATIC_XBETA_PARAM3)->EnableWindow(true);
		GetDlgItem(IDC_STATIC_XBETA_PARAM4)->EnableWindow(true);
		GetDlgItem(IDC_STATIC_XBETA_PARAM5)->EnableWindow(true);
		GetDlgItem(IDC_STATIC_XBETA_PARAM6)->EnableWindow(true);
		GetDlgItem(IDC_STATIC_XBETA_PARAM7)->EnableWindow(true);

		GetDlgItem(IDC_EDIT_XBETA_PARAM1)->EnableWindow(true);
		GetDlgItem(IDC_EDIT_XBETA_PARAM2)->EnableWindow(true);
		GetDlgItem(IDC_EDIT_XBETA_PARAM3)->EnableWindow(true);
		GetDlgItem(IDC_EDIT_XBETA_PARAM4)->EnableWindow(true);
		GetDlgItem(IDC_EDIT_XBETA_PARAM5)->EnableWindow(true);
		GetDlgItem(IDC_EDIT_XBETA_PARAM6)->EnableWindow(true);
		GetDlgItem(IDC_EDIT_XBETA_PARAM7)->EnableWindow(true);

		GetDlgItem(IDC_STATIC_YALPHA_PARAM1)->EnableWindow(true);
		GetDlgItem(IDC_STATIC_YALPHA_PARAM2)->EnableWindow(true);
		GetDlgItem(IDC_STATIC_YALPHA_PARAM3)->EnableWindow(true);
		GetDlgItem(IDC_STATIC_YALPHA_PARAM4)->EnableWindow(true);
		GetDlgItem(IDC_STATIC_YALPHA_PARAM5)->EnableWindow(true);
		GetDlgItem(IDC_STATIC_YALPHA_PARAM6)->EnableWindow(true);
		GetDlgItem(IDC_STATIC_YALPHA_PARAM7)->EnableWindow(true);

		GetDlgItem(IDC_EDIT_YALPHA_PARAM1)->EnableWindow(true);
		GetDlgItem(IDC_EDIT_YALPHA_PARAM2)->EnableWindow(true);
		GetDlgItem(IDC_EDIT_YALPHA_PARAM3)->EnableWindow(true);
		GetDlgItem(IDC_EDIT_YALPHA_PARAM4)->EnableWindow(true);
		GetDlgItem(IDC_EDIT_YALPHA_PARAM5)->EnableWindow(true);
		GetDlgItem(IDC_EDIT_YALPHA_PARAM6)->EnableWindow(true);
		GetDlgItem(IDC_EDIT_YALPHA_PARAM7)->EnableWindow(true);

		GetDlgItem(IDC_STATIC_R_PARAM1)->EnableWindow(true);
		GetDlgItem(IDC_STATIC_R_PARAM2)->EnableWindow(true);
		GetDlgItem(IDC_STATIC_R_PARAM3)->EnableWindow(true);
		GetDlgItem(IDC_STATIC_R_PARAM4)->EnableWindow(true);
		GetDlgItem(IDC_STATIC_R_PARAM5)->EnableWindow(true);
		GetDlgItem(IDC_STATIC_R_PARAM6)->EnableWindow(true);
		GetDlgItem(IDC_STATIC_R_PARAM7)->EnableWindow(true);

		GetDlgItem(IDC_EDIT_R_PARAM1)->EnableWindow(true);
		GetDlgItem(IDC_EDIT_R_PARAM2)->EnableWindow(true);
		GetDlgItem(IDC_EDIT_R_PARAM3)->EnableWindow(true);
		GetDlgItem(IDC_EDIT_R_PARAM4)->EnableWindow(true);
		GetDlgItem(IDC_EDIT_R_PARAM5)->EnableWindow(true);
		GetDlgItem(IDC_EDIT_R_PARAM6)->EnableWindow(true);
		GetDlgItem(IDC_EDIT_R_PARAM7)->EnableWindow(true);
	}
}

LRESULT CInterface_Control_Grue_Dlg::OnCraneWaitDone(WPARAM wParam, LPARAM lParam)
{
	m_param->SetCraneWait(false);

	if(m_param->GetAffInterf())
	{

	}
	return 0;
}

void CInterface_Control_Grue_Dlg::OnBnClickedButtonRestaurer()
{
	LoadINI();
}
