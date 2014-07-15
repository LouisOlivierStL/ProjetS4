#include "stdafx.h"
#include "Parametres.h"

#include "Interface_Control_GrueDlg.h"

//Constructeur
Parametres::Parametres(CInterface_Control_Grue_Dlg* parent) : m_ka(0), m_kb(0), m_xbeta_kp(0), m_xbeta_kd(0), m_xbeta_ki(0), m_yalpha_kp(0), m_yalpha_kd(0), m_yalpha_ki(0),
	m_r_kp(0), m_r_kd(0), m_r_ki(0), m_xbeta_a0(0), m_xbeta_a1(0), m_xbeta_a2(0), m_xbeta_b0(0), m_xbeta_b1(0), m_xbeta_b2(0), m_yalpha_a0(0), 
	m_yalpha_a1(0), m_yalpha_a2(0), m_yalpha_b0(0), m_yalpha_b1(0), m_yalpha_b2(0), m_r_a0(0), m_r_a1(0), m_r_a2(0), m_r_b0(0), m_r_b1(0),
	m_r_b2(0), m_alpha(0), m_beta(0), m_r(0), m_yw(0), m_xp(0), m_trajX(0), m_trajY(0), m_trajZ(0), m_trajPath(""), m_calcul(true), m_wait(false), m_trajMode(STOP),
	m_xbeta_type(PID), m_yalpha_type(PID), m_r_type(PID), m_xc(0), m_yc(0), m_zc(0), m_waitMode(0), m_craneWait(false)
{
	InitCraneComp();
	m_crane = new Crane();

	m_dialogPrincipal = parent;
}

CInterface_Control_Grue_Dlg* Parametres::GetDialog()
{
	return m_dialogPrincipal;
}

//Compensateur Set-Get
void Parametres::SetKa(float ka)
{
	m_ka = ka;
	m_comp.ka = m_ka;
}

float Parametres::GetKa()
{
	return m_ka;
}

void Parametres::SetKb(float kb)
{
	m_kb = kb;
	m_comp.kb = m_kb;
}

float Parametres::GetKb()
{
	return m_kb;
}

void Parametres::SetXbetaType(int type)
{
	m_xbeta_type = type;
	m_comp.typeXBeta = type;
}

int Parametres::GetXbetaType()
{
	return m_xbeta_type;
}

void Parametres::SetYalphaType(int type)
{
	m_yalpha_type = type;
	m_comp.typeYAlpha = type;
}

int Parametres::GetYalphaType()
{
	return m_yalpha_type;
}

void Parametres::SetRType(int type)
{
	m_r_type = type;
	m_comp.typeR = type;
}

int Parametres::GetRType()
{
	return m_r_type;
}

void Parametres::SetXbetaKp(float kp)
{
	m_xbeta_kp = kp;
	m_comp.pidXBeta[0] = m_xbeta_kp;
}

float Parametres::GetXbetaKp()
{
	return m_xbeta_kp;
}

void Parametres::SetXbetaKd(float kd)
{
	m_xbeta_kd = kd;
	m_comp.pidXBeta[1] = m_xbeta_kd;
}
float Parametres::GetXbetaKd()
{
	return m_xbeta_kd;
}

void Parametres::SetXbetaKi(float ki)
{
	m_xbeta_ki = ki;
	m_comp.pidXBeta[2] = m_xbeta_ki;
}

float Parametres::GetXbetaKi()
{
	return m_xbeta_ki;
}

void Parametres::SetYalphaKp(float kp)
{
	m_yalpha_kp = kp;
	m_comp.pidYAlpha[0] = m_yalpha_kp;
}

float Parametres::GetYalphaKp()
{
	return m_yalpha_kp;
}

void Parametres::SetYalphaKd(float kd)
{
	m_yalpha_kd = kd;
	m_comp.pidYAlpha[1] = m_yalpha_kd;
}

float Parametres::GetYalphaKd()
{
	return m_yalpha_kd;
}

void Parametres::SetYalphaKi(float ki)
{
	m_yalpha_ki = ki;
	m_comp.pidYAlpha[2] = m_yalpha_ki;
}

float Parametres::GetYalphaKi()
{
	return m_yalpha_ki;
}

void Parametres::SetR_Kp(float kp)
{
	m_r_kp = kp;
	m_comp.pidR[0] = m_r_kp;
}

float Parametres::GetR_Kp()
{
	return m_r_kp;
}

void Parametres::SetR_Kd(float kd)
{
	m_r_kd = kd;
	m_comp.pidR[1] = m_r_kd;
}

float Parametres::GetR_Kd()
{
	return m_r_kd;
}

void Parametres::SetR_Ki(float ki)
{
	m_r_ki = ki;
	m_comp.pidR[2] = m_r_ki;
}

float Parametres::GetR_Ki()
{
	return m_r_ki;
}

void Parametres::SetXbetaA0(float a0)
{
	m_xbeta_a0 = a0;
	m_comp.denXBeta[2] = m_xbeta_a0;
}

float Parametres::GetXbetaA0()
{
	return m_xbeta_a0;
}

void Parametres::SetXbetaA1(float a1)
{
	m_xbeta_a1 = a1;
	m_comp.denXBeta[1] = m_xbeta_a1;
}

float Parametres::GetXbetaA1()
{
	return m_xbeta_a1;
}

void Parametres::SetXbetaA2(float a2)
{
	m_xbeta_a2 = a2;
	m_comp.denXBeta[0] = m_xbeta_a2;
}

float Parametres::GetXbetaA2()
{
	return m_xbeta_a2;
}

void Parametres::SetXbetaB0(float b0)
{
	m_xbeta_b0 = b0;
	m_comp.numXBeta[2] = m_xbeta_b0;
}

float Parametres::GetXbetaB0()
{
	return m_xbeta_b0;
}

void Parametres::SetXbetaB1(float b1)
{
	m_xbeta_b1 = b1;
	m_comp.numXBeta[1] = m_xbeta_b1;
}

float Parametres::GetXbetaB1()
{
	return m_xbeta_b1;
}

void Parametres::SetXbetaB2(float b2)
{
	m_xbeta_b2 = b2;
	m_comp.numXBeta[0] = m_xbeta_b2;
}

float Parametres::GetXbetaB2()
{
	return m_xbeta_b2;
}

void Parametres::SetYalphaA0(float a0)
{
	m_yalpha_a0 = a0;
	m_comp.denYAlpha[2] = m_yalpha_a0;
}

float Parametres::GetYalphaA0()
{
	return m_yalpha_a0;
}

void Parametres::SetYalphaA1(float a1)
{
	m_yalpha_a1 = a1;
	m_comp.denYAlpha[1] = m_yalpha_a1;
}

float Parametres::GetYalphaA1()
{
	return m_yalpha_a1;
}

void Parametres::SetYalphaA2(float a2)
{
	m_yalpha_a2 = a2;
	m_comp.denYAlpha[0] = m_yalpha_a2;
}

float Parametres::GetYalphaA2()
{
	return m_yalpha_a2;
}

void Parametres::SetYalphaB0(float b0)
{
	m_yalpha_b0 = b0;
	m_comp.numYAlpha[2] = m_yalpha_b0;
}

float Parametres::GetYalphaB0()
{
	return m_yalpha_b0;
}

void Parametres::SetYalphaB1(float b1)
{
	m_yalpha_b1 = b1;
	m_comp.numYAlpha[1] = m_yalpha_b1;
}

float Parametres::GetYalphaB1()
{
	return m_yalpha_b1;
}

void Parametres::SetYalphaB2(float b2)
{
	m_yalpha_b2 = b2;
	m_comp.numYAlpha[0] = m_yalpha_b2;
}

float Parametres::GetYalphaB2()
{
	return m_yalpha_b2;
}

void Parametres::SetR_A0(float a0)
{
	m_r_a0 = a0;
	m_comp.denR[2] = m_r_a0;
}

float Parametres::GetR_A0()
{
	return m_r_a0;
}

void Parametres::SetR_A1(float a1)
{
	m_r_a1 = a1;
	m_comp.denR[1] = m_r_a1;
}

float Parametres::GetR_A1()
{
	return m_r_a1;
}

void Parametres::SetR_A2(float a2)
{
	m_r_a2 = a2;
	m_comp.denR[0] = m_r_a2;
}

float Parametres::GetR_A2()
{
	return m_r_a2;
}

void Parametres::SetR_B0(float b0)
{
	m_r_b0 = b0;
	m_comp.numR[2] = m_r_b0;
}

float Parametres::GetR_B0()
{
	return m_r_b0;
}

void Parametres::SetR_B1(float b1)
{
	m_r_b1 = b1;
	m_comp.numR[1] = m_r_b1;
}

float Parametres::GetR_B1()
{
	return m_r_b1;
}

void Parametres::SetR_B2(float b2)
{
	m_r_b2 = b2;
	m_comp.numR[0] = m_r_b2;
}

float Parametres::GetR_B2()
{
	return m_r_b2;
}


//Capteur Set-Get
void Parametres::SetAlpha(float alpha)
{
	m_alpha = alpha;
}

float Parametres::GetAlpha()
{
	return m_alpha;
}

void Parametres::SetBeta(float beta)
{
	m_beta = beta;
}

float Parametres::GetBeta()
{
	return m_beta;
}

void Parametres::SetR(float r)
{
	m_r = r;
}

float Parametres::GetR()
{
	return m_r;
}

void Parametres::SetYw(float yw)
{
	m_yw = yw;
}

float Parametres::GetYw()
{
	return m_yw;
}

void Parametres::SetXp(float xp)
{
	m_xp = xp;
}

float Parametres::GetXp()
{
	return m_xp;
}

//Position Set-Get
void Parametres::SetXc(float xc)
{
	m_xc = xc;
}

float Parametres::GetXc()
{
	return m_xc;
}

void Parametres::SetYc(float yc)
{
	m_yc = yc;
}

float Parametres::GetYc()
{
	return m_yc;
}

void Parametres::SetZc(float zc)
{
	m_zc = zc;
}

float Parametres::GetZc()
{
	return m_zc;
}

//Trajectoire
void Parametres::SetTrajX(float trajX)
{
	m_trajX = trajX;
}

float Parametres::GetTrajX()
{
	return m_trajX;
}

void Parametres::SetTrajY(float trajY)
{
	m_trajY = trajY;
}

float Parametres::GetTrajY()
{
	return m_trajY;
}

void Parametres::SetTrajZ(float trajZ)
{
	m_trajZ = trajZ;
}

float Parametres::GetTrajZ()
{
	return m_trajZ;
}

void Parametres::SetTrajMode(int trajMode)
{
	m_trajMode = trajMode;
}

int Parametres::GetTrajMode()
{
	return m_trajMode;
}

void Parametres::SetTrajPath(CString trajPath)
{
	m_trajPath = trajPath;
}

CString Parametres::GetTrajPath()
{
	return m_trajPath;
}

void Parametres::InitCraneComp()
{
	m_comp.ka = 0;
	m_comp.kb = 0;

	m_comp.typeXBeta = PID;
	m_comp.pidXBeta[0] = 0;
	m_comp.pidXBeta[1] = 0;
	m_comp.pidXBeta[2] = 0;
	m_comp.numXBeta[0] = 0;
	m_comp.numXBeta[1] = 0;
	m_comp.numXBeta[2] = 0;
	m_comp.denXBeta[0] = 0;
	m_comp.denXBeta[1] = 0;
	m_comp.denXBeta[2] = 0;

	m_comp.typeYAlpha = PID;
	m_comp.pidYAlpha[0] = 0;
	m_comp.pidYAlpha[1] = 0;
	m_comp.pidYAlpha[2] = 0;
	m_comp.numYAlpha[0] = 0;
	m_comp.numYAlpha[1] = 0;
	m_comp.numYAlpha[2] = 0;
	m_comp.denYAlpha[0] = 0;
	m_comp.denYAlpha[1] = 0;
	m_comp.denYAlpha[2] = 0;

	m_comp.typeR = PID;
	m_comp.pidR[0] = 0;
	m_comp.pidR[1] = 0;
	m_comp.pidR[2] = 0;
	m_comp.numR[0] = 0;
	m_comp.numR[1] = 0;
	m_comp.numR[2] = 0;
	m_comp.denR[0] = 0;
	m_comp.denR[1] = 0;
	m_comp.denR[2] = 0;
}

void Parametres::UpdateCraneComp()
{
	int err = m_crane->SetComp(m_comp);

	if(err == ERR_PID)
	{
		m_dialogPrincipal->Msg_Status(_T("Statut: Tous les paramètres d’au moins un PID sont nuls. (UpdateCraneComp)"));
	}

	else if(err == ERR_TF)
	{
		m_dialogPrincipal->Msg_Status(_T("Statut: Tous les paramètres d’au moins une des fonctions de transfert sont nuls. (UpdateCraneComp)"));
	}

	else if(err == ERR_TYPE)
	{
		m_dialogPrincipal->Msg_Status(_T("Statut: Le type d’au moins un compensateur n’est pas reconnu. (UpdateCraneComp)"));
	}

	else if(err == ERR_WRITE_DSP)
	{
		m_dialogPrincipal->Msg_Status(_T("Statut: L’envoi de données au DSP a échoué. (UpdateCraneComp)"));
	}

	else if(err == ERR_NULL_PTR)
	{
		m_dialogPrincipal->Msg_Status(_T("Statut: Un pointeur nul a été rencontré lors de l'envoie de la structure des compensateurs. (UpdateCraneComp)"));
	}
}

void Parametres::UpdateCraneTrajMode()
{
	int err = m_crane->SetTrajMode(m_trajMode);

	if(err == ERR_TRAJ_MODE)
	{
		m_dialogPrincipal->Msg_Status(_T("Statut: Le mode de la trajectoire spécifié est invalide. (UpdateCraneTrajMode)"));
	}
}

void Parametres::UpdateCraneTrajPath()
{
	CT2CA cTrajPath(m_trajPath);
	int err = m_crane->LoadTrajFile(cTrajPath);

	if(err == ERR_PARSE_FILE)
	{
		m_dialogPrincipal->Msg_Status(_T("Statut: Fichier introuvable ou format du fichier non valide. (UpdateCraneTrajPath)"));
	}

	else if(err == ERR_NULL_PTR)
	{
		m_dialogPrincipal->Msg_Status(_T("Statut: Un pointeur nul a été rencontré lors de l'envoie du chemin du fichier. (UpdateCraneTrajPath)"));
	}
}

void Parametres::SetCraneWait(bool wait)
{
	m_craneWait = wait;
}

bool Parametres::GetCraneWait()
{
	return m_craneWait;
}

void Parametres::Run(int mode, int traj_flag)
{
	if(!m_craneWait)
	{
		int err = m_crane->Run(mode, traj_flag);

		if(err == 0)
		{
			m_dialogPrincipal->Msg_Status(_T("Statut: Debut du déplacement."));
		}

		else if(err == ERR_CTL_MODE)
		{
			m_dialogPrincipal->Msg_Status(_T("Statut: Le paramètre ctlMode est non valide. (Run)"));
		}

		else if(err == ERR_RUNNING)
		{
			m_dialogPrincipal->Msg_Status(_T("Statut: La grue est déjà en train d’exécuter un déplacement. (Run)"));
		}

		else if(err == ERR_TRAJ)
		{
			m_dialogPrincipal->Msg_Status(_T("Statut: La trajectoire n’est pas spécifiée ou est non valide. (Run)"));
		}

		else if(err == ERR_TRAJ_FLAG)
		{
			m_dialogPrincipal->Msg_Status(_T("Statut: Le paramètre trajFlag est non valide. (Run)"));
		}

		else if(err == ERR_WRITE_DSP)
		{
			m_dialogPrincipal->Msg_Status(_T("Statut: L’envoi de données au DSP a échoué. (Run)"));
		}
	}
}

void Parametres::Reset()
{
	if(!m_craneWait)
	{
		m_dialogPrincipal->Msg_Status(_T("Statut: Réinitialisation de la position de la grue."));
		m_crane->Reset();
	}
}

void Parametres::Stop()
{
	int err = m_crane->Stop();

	if(err == ERR_READ_DSP)
	{
		m_dialogPrincipal->Msg_Status(_T("Statut: La réception de données du DSP a échouée. (Stop)"));
	}
}

void Parametres::Wait(int mode, bool affInterf)
{
	m_afficherInterf = affInterf;

	m_waitMode = mode;
	m_craneWait = true;
	AfxBeginThread(WaitCraneThread, this);
}

UINT Parametres::WaitCraneThread(LPVOID obj)
{
	Parametres* param = (Parametres*) obj;

	param->GetCrane()->Wait(param->GetWaitMode());

	::PostMessage(param->GetDialog()->m_hWnd, CRANE_WAIT_DONE, 0, 0);
	return 0;
}

bool Parametres::GetAffInterf()
{
	return m_afficherInterf;
}	

int Parametres::GetWaitMode()
{
	return m_waitMode;
}

//Calcul
void Parametres::SetCalcul(bool calcul)
{
	m_calcul = calcul;
}

bool Parametres::GetCalcul()
{
	return m_calcul;
}

//Wait
void Parametres::SetWait(bool wait)
{
	m_wait = wait;
}

bool Parametres::GetWait()
{
	return m_wait;
}

//Variable Crane
Crane* Parametres::GetCrane()
{
	return m_crane;
}