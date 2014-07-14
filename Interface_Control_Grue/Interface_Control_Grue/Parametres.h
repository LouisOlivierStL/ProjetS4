#pragma once

#include "craneexports.h"

class CInterface_Control_Grue_Dlg;

class Parametres
{
private:
	//Classe dialog principal
	CInterface_Control_Grue_Dlg* m_dialogPrincipal;

	//Compensateurs
	float m_ka;
	float m_kb;

	float m_xbeta_kp;
	float m_xbeta_kd;
	float m_xbeta_ki;
	float m_yalpha_kp;
	float m_yalpha_kd;
	float m_yalpha_ki;
	float m_r_kp;
	float m_r_kd;
	float m_r_ki;

	float m_xbeta_a0;
	float m_xbeta_a1;
	float m_xbeta_a2;
	float m_xbeta_b0;
	float m_xbeta_b1;
	float m_xbeta_b2;	
	float m_yalpha_a0;
	float m_yalpha_a1;
	float m_yalpha_a2;
	float m_yalpha_b0;
	float m_yalpha_b1;
	float m_yalpha_b2;
	float m_r_a0;
	float m_r_a1;
	float m_r_a2;
	float m_r_b0;
	float m_r_b1;
	float m_r_b2;

	//Capteurs
	float m_alpha;
	float m_beta;
	float m_r;
	float m_yw;
	float m_xp;

	//Position
	float m_xc;
	float m_yc;
	float m_zc;

	//Trajectoire
	float m_trajX;
	float m_trajY;
	float m_trajZ;

	CString m_trajPath;

	//Structure contenant les donnees des compensateurs
	CompParamdef m_comp;

	//Variable qui dit au thread de calculer ou non les valeurs
	bool m_calcul;
	//Variable qui empeche d'avoir des donnees bidons lors de l'affichage
	bool m_wait;

	//Classe crane pour le control de la grue
	Crane *m_crane;

public:
	Parametres(CInterface_Control_Grue_Dlg* parent);

	CInterface_Control_Grue_Dlg* GetDialog();

	//Compensateurs Set-Get
	void SetKa(float ka);
	float GetKa();
	void SetKb(float kb);
	float GetKb();

	void SetXbetaType(int type);
	void SetYalphaType(int type);
	void SetRType(int type);

	void SetXbetaKp(float kp);
	float GetXbetaKp();
	void SetXbetaKd(float kd);
	float GetXbetaKd();
	void SetXbetaKi(float ki);
	float GetXbetaKi();
	void SetYalphaKp(float kp);
	float GetYalphaKp();
	void SetYalphaKd(float kd);
	float GetYalphaKd();
	void SetYalphaKi(float ki);
	float GetYalphaKi();
	void SetR_Kp(float kp);
	float GetR_Kp();
	void SetR_Kd(float kd);
	float GetR_Kd();
	void SetR_Ki(float ki);
	float GetR_Ki();

	void SetXbetaA0(float a0);
	float GetXbetaA0();
	void SetXbetaA1(float a1);
	float GetXbetaA1();
	void SetXbetaA2(float a2);
	float GetXbetaA2();
	void SetXbetaB0(float b0);
	float GetXbetaB0();
	void SetXbetaB1(float b1);
	float GetXbetaB1();
	void SetXbetaB2(float b2);
	float GetXbetaB2();
	void SetYalphaA0(float a0);
	float GetYalphaA0();
	void SetYalphaA1(float a1);
	float GetYalphaA1();
	void SetYalphaA2(float a2);
	float GetYalphaA2();
	void SetYalphaB0(float b0);
	float GetYalphaB0();
	void SetYalphaB1(float b1);
	float GetYalphaB1();
	void SetYalphaB2(float b2);
	float GetYalphaB2();
	void SetR_A0(float a0);
	float GetR_A0();
	void SetR_A1(float a1);
	float GetR_A1();
	void SetR_A2(float a2);
	float GetR_A2();
	void SetR_B0(float b0);
	float GetR_B0();
	void SetR_B1(float b1);
	float GetR_B1();
	void SetR_B2(float b2);
	float GetR_B2();


	//Capteurs Set-Get
	void SetAlpha(float alpha);
	float GetAlpha();
	void SetBeta(float beta);
	float GetBeta();
	void SetR(float r);
	float GetR();
	void SetYw(float yw);
	float GetYw();
	void SetXp(float xp);
	float GetXp();

	//Position
	void SetXc(float xc);
	float GetXc();
	void SetYc(float yc);
	float GetYc();
	void SetZc(float zc);
	float GetZc();

	//Trajectoire
	void SetTrajX(float trajX);
	float GetTrajX();
	void SetTrajY(float trajY);
	float GetTrajY();
	void SetTrajZ(float trajZ);
	float GetTrajZ();

	void SetTrajPath(CString trajPath);
	CString GetTrajPath();

	//Structure contenant les donnees des compensateurs
	void InitCraneComp();
	void UpdateCraneComp();

	//Variable de calcul
	void SetCalcul(bool calcul);
	bool GetCalcul();

	//Variable wait
	void SetWait(bool wait);
	bool GetWait();

	//Crane
	Crane* GetCrane();
};