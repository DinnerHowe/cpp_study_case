#ifndef  LOGGER_HOWE_H_
#define  LOGGER_HOWE_H_
 
#include <fstream>  
#include <string>  
#include <sstream>  
#include <ctime>  
#include <cstdlib>
#include <iostream>

using namespace std;
 

class Log
{
public:
	Log();
	~Log();
 
	bool Open(string strFileName);
	void Close();
 
	bool CommonLogInit(string name); 
 
	void Enable();
	void Disable();
 
	string GetTimeStr();
 
	template <typename T> void LogOut(const T& value)
	{
		if (m_bEnabled)
		{
			m_tOLogFile << value;
			
		}
	}
 
	template <typename T> void LogOutLn(const T& value)
	{
		if (m_bEnabled)
		{
			m_tOLogFile << value << std::endl;
		}
	}
 
	void LogOutLn()
	{
		if (m_bEnabled)
		{
			m_tOLogFile << std::endl;
		}
	}
 
	template <typename T> Log& operator<<(const T& value)
	{
		if (m_bEnabled)
		{
			m_tOLogFile << value;
			std::cout << value << std::endl;
		}
		return (*this);
	}
 
	Log& operator<<(ostream& (*_Pfn)(ostream&))
	{
		if (m_bEnabled)
		{
			(*_Pfn)(m_tOLogFile);
		}
		return (*this);
	}
 
private:
	template<typename T> string ValueToStr(T value)
	{
		ostringstream ost;
		ost << value;
		return ost.str();
	}
private:
	ofstream m_tOLogFile;
 
	bool m_bEnabled;
};
 
 
#endif  


