#include "log.h"  
    
int main()
{
    Log LogHowe;
    string name = "log";
    LogHowe.CommonLogInit(name);
	time_t pLocalTime;
	time_t nLocalTime;

    time_t pNowTime;
	time(&pNowTime);
	pLocalTime = pNowTime;

    time_t nNowTime;
	time(&nNowTime);
	nLocalTime = nNowTime;

	while (abs(pLocalTime - nLocalTime) < 2)
	{
    	time_t nNowTime;
		time(&nNowTime);
		nLocalTime = nNowTime;

		std::cout << pLocalTime << " - " << nLocalTime << " = " << abs(pLocalTime - nLocalTime) << std::endl;

		auto output = "这里是需要自己输入的信息: " ;
    	LogHowe << LogHowe.GetTimeStr() << output << std::endl;
	}
	LogHowe.Close();
}
