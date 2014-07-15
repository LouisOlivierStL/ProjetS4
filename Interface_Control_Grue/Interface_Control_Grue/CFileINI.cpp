// *********************************************************************************************************
// File Header
// *********************************************************************************************************
// File:      CFileINI.cpp
// Author:    Fujioka, Michaël
// Username:  fujiokm
// Date:      2012-12-17
// 
// Purpose:   file containing the function definitions of the class CFileINI (INI file)
// 
// Modification Log:
// User       Version   Date(yyyy-mm-dd)   Description
// --------   -------   ----------------   -----------------------------------------------------------------
// fujiokm    1.01      2012-12-17         added file header
// 
// 
// 
// 
// 
// *********************************************************************************************************

#include "stdafx.h"
#include "CFileINI.h"

// author: fujiokm
// date: 2012-11-20
// description:
//		constructor
CFileINI::CFileINI()
{
   Init(NULL);
}

// author: fujiokm
// date: 2012-11-20
// description:
//		constructor
// parameters:
//		char *p_cpFilePath: full path of file
CFileINI::CFileINI(char *p_cpFilePath = NULL)
{
   Init(p_cpFilePath);
}

// author: fujiokm
// date: 2012-11-20
// description:
//		destructor
CFileINI::~CFileINI()
{
   delete [] m_cpProfileString;
   delete [] m_cpFilePath;
   delete [] m_cpFileName;
}

// author: fujiokm
// date: 2012-11-20
// description:
//		find and set the file name, the file path, the extension
// parameters:
//		char *p_cpFilePath: full path of file
void CFileINI::Init(char *p_cpFilePath = NULL)
{
   int iExtIndex = 0;
   int iDirIndex = 0;

   m_strTmp.Empty();
   m_cpProfileString = new char[FILE_SIZE];
   m_cpFilePath = new char[FILE_SIZE_PATH];
   m_cpFileName = new char[FILE_SIZE];

   char caFilePath[FILE_SIZE] = {0};

   strcpy(m_cpProfileString,"\0");
   strcpy(m_cpFilePath,"\0");
   strcpy(m_cpFileName,"\0");

   strcpy(caFilePath,"\0");

   if(p_cpFilePath == NULL)
   {
      // gets the exe file name
      if(GetModuleFileNameA(NULL, caFilePath, FILE_SIZE) == 0)
      {
         m_strTmp.Empty();
         m_strTmp.Format(_T("Cannot get file name"));
         //throw ERROR_ARG((char*)((LPCSTR)m_strTmp),-1);
      }
   }
   else
   {
      strcpy(caFilePath, p_cpFilePath);
   }

   m_strTmp.Empty();
   m_strTmp = caFilePath;

   // get extension dot index
   iExtIndex = m_strTmp.ReverseFind('.');

   // adds ".ini" to file
   m_strTmp = m_strTmp.Mid(0,iExtIndex);
   m_strTmp += ".ini";

   CT2CA cTmp(m_strTmp);

   strcpy(m_cpFilePath, cTmp);

   iExtIndex = m_strTmp.ReverseFind('.');
   iDirIndex = m_strTmp.ReverseFind('\\');

   // get path
   m_strFilePath = m_strTmp.Mid(0,iDirIndex+1);

   // get name
   m_strFileName = m_strTmp.Mid(iDirIndex+1,iExtIndex-iDirIndex-1);

   CT2CA cFileName(m_strFileName);

   strcpy(m_cpFileName, cFileName);
}

// author: fujiokm
// date: 2012-11-20
// description:
//		return the file name
CString CFileINI::GetFileName()
{
   return m_strFileName;
}

// author: fujiokm
// date: 2012-11-20
// description:
//		return the file path
CString CFileINI::GetFilePath()
{
   return m_strFilePath;
}

// author: fujiokm
// date: 2012-11-20
// description:
//		return the log path
CString CFileINI::GetLogPath()
{
   return m_strLogPath;
}

// author: fujiokm
// date: 2012-11-20
// description:
//		delete section of INI file
// parameters:
//		const char *p_cpSection: the section delete
BOOL CFileINI::DeleteSection(const char *p_cpSection)
{
   return WritePrivateProfileStringA(p_cpSection,NULL,NULL, m_cpFilePath);
}

// author: fujiokm
// date: 2012-11-20
// description:
//		writes data in the INI file
// parameters:
//		const char *p_cpSection: the section
//		const char *p_cpKey: the key
//		const char *p_cpValue: the value
char* CFileINI::WriteString(const char *p_cpSection, const char *p_cpKey, const char *p_cpValue)
{
   if(WritePrivateProfileStringA(p_cpSection,p_cpKey,p_cpValue, m_cpFilePath) != 0)
   {
      //return true;
   }

   return m_cpFilePath;
}

// author: fujiokm
// date: 2012-11-20
// description:
//		gets data from the INI file
// parameters:
//		const char *p_cpSection: the section
//		const char *p_cpKey: the key
//		const int p_iSize: the size
// return:
//		char *: the value
char* CFileINI::ReadString(const char *p_cpSection, const char *p_cpKey, const int p_iSize)
{
   GetPrivateProfileStringA(p_cpSection,p_cpKey,NULL,m_cpProfileString,p_iSize,m_cpFilePath);

   return m_cpProfileString;
}
