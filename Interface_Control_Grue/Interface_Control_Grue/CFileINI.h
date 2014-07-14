// *********************************************************************************************************
// File Header
// *********************************************************************************************************
// File:      CFileINI.h
// Author:    Fujioka, Michaël
// Username:  fujiokm
// Date:      2012-12-17
// 
// Purpose:   file containing the function declarations of the class CFileINI (INI file)
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

#pragma once

const int FILE_SIZE = 128;
const int FILE_SIZE_PATH = FILE_SIZE + 2 + 3;

// author: fujiokm
// date: 2012-11-20
// description:
//		represents a INI file, that can be created, loaded or modified
class CFileINI
{
public:
   CFileINI();
   CFileINI(char *p_cpFilePath);
   ~CFileINI();

   char* WriteString(const char *p_cpSection, const char *p_cpKey, const char *p_cpValue);
   char* ReadString(const char *p_cpSection, const char *p_cpKey, const int p_iSize = FILE_SIZE);
   BOOL DeleteSection(const char *p_cpSection);

   CString GetFilePath();
   CString GetFileName();
   CString GetLogPath();

private:
   char *m_cpProfileString;
   char *m_cpFilePath;
   char *m_cpFileName;
   CString m_strTmp;
   CString m_strFilePath;
   CString m_strLogPath;
   CString m_strFileName;

   void Init(char *p_cpFilePath);
};