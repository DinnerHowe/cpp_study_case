/*********************************************************************
 * @file: planning_change_lane_analyse.cpp
 * @copyright (C) Alibaba-inc - All Rights Reserved
 * Unauthorized copying of this file, via any medium is strictly prohibited
 * @date: 27/08/2018
 * @author: howe <zhihao.xzh@alibaba-inc.com>
 * @details: This node is used for record log file
 * @version 2.6
*********************************************************************/
#include "log.h"

Log::Log()
	:m_bEnabled(true)
{
}
 
Log::~Log()
{
}
 
bool Log::Open(string sFileName)
{
	m_tOLogFile.open(sFileName.c_str(), ios_base::out | ios_base::app);
 
	if (!m_tOLogFile)
	{
		return false;
	}
 
	return true;
}
 
void Log::Close()
{
	if (m_tOLogFile.is_open())
	{
		m_tOLogFile.close();
	}
}
 
bool Log::CommonLogInit(string name)
{
	time_t tNowTime;
	time(&tNowTime);
 
	tm* tLocalTime = localtime(&tNowTime);
 
	string sDateStr = "-" + ValueToStr(tLocalTime->tm_year + 1900) + "-" +
		ValueToStr(tLocalTime->tm_mon + 1) + "-" +
		ValueToStr(tLocalTime->tm_mday) + "-" + ValueToStr(tLocalTime->tm_hour) + "-" + ValueToStr(tLocalTime->tm_min);
    const char* home = getenv("HOME");
    if(home)
    {
        std::string path(home);
        std::cout << path + "/" + name << std::endl;
        return Open( path + "/" + name + sDateStr + ".txt");
    }

}
 
void Log::Enable()
{
	m_bEnabled = true;
}
 
void Log::Disable()
{
	m_bEnabled = false;
}
 
string Log::GetTimeStr()
{
	time_t tNowTime;
	time(&tNowTime);
 
	tm* tLocalTime = localtime(&tNowTime);
 
	string strFormat = "[%Y-%m-%d %H:%M:%S] ";
 
	char strDateTime[30] = { '\0' };
	strftime(strDateTime, 30, strFormat.c_str(), tLocalTime);
 
	string strRes = strDateTime;
 
	return strRes;
}