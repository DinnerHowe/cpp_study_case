

#include <iostream>
#include <thread>
#include <chrono>
#include <string.h>

#ifdef WIN32
#include <windows.h>
#include <psapi.h>
//#include <tlhelp32.h>
#include <direct.h>
#include <process.h>
#else
#include <sys/stat.h>
// #include <sys/sysinfo.h>
#include <sys/time.h>
#include <unistd.h>
#endif

// get current process pid
inline int GetCurrentPid()
{
    return getpid();
}

// get specific process physical memeory occupation size by pid (MB)
inline float GetMemoryUsage(int pid)
{
#ifdef WIN32
    uint64_t mem = 0, vmem = 0;
    PROCESS_MEMORY_COUNTERS pmc;

    // get process hanlde by pid
    HANDLE process = OpenProcess(PROCESS_ALL_ACCESS, FALSE, pid);
    if (GetProcessMemoryInfo(process, &pmc, sizeof(pmc)))
    {
        mem = pmc.WorkingSetSize;
        vmem = pmc.PagefileUsage;
    }
    CloseHandle(process);

    // use GetCurrentProcess() can get current process and no need to close handle

    // convert mem from B to MB
    return mem / 1024.0 / 1024.0;

#else
#define VMRSS_LINE 22

    char file_name[64] = {0};
    FILE *fd;
    char line_buff[512] = {0};
    sprintf(file_name, "/proc/%d/status", pid);

    fd = fopen(file_name, "r");
    if (nullptr == fd)
        return 0;

    char name[64];
    int vmrss = 0;
    for (int i = 0; i < VMRSS_LINE - 1; i++)
        fgets(line_buff, sizeof(line_buff), fd);

    fgets(line_buff, sizeof(line_buff), fd);
    sscanf(line_buff, "%s %d", name, &vmrss);
    fclose(fd);

    // cnvert VmRSS from KB to MB
    return vmrss / 1024.0;
#endif
}

int main(int argc, char **argv)
{
    // launch some task to occupy cpu and memory
    for (int i = 0; i < 5; i++)
        std::thread([]
                    { std::this_thread::sleep_for(std::chrono::milliseconds(10)); })
            .detach();

    int current_pid = GetCurrentPid(); // or you can set a outside program pid
    float memory_usage = GetMemoryUsage(current_pid);

    while (true)
    {
        std::cout << "current pid: " << current_pid << std::endl;
        std::cout << "memory usage: " << memory_usage << "MB" << std::endl;

        std::this_thread::sleep_for(std::chrono::milliseconds(1000));
    }

    return 0;
}