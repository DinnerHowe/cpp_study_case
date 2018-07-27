#include <iostream>

#include <glog/logging.h>
#include <glog/raw_logging.h>

using namespace std;


int main(int argc, char **argv)
{
    google::InitGoogleLogging((const char *)argv[0]);  //参数为自己的可执行文件名  
    google::SetLogDestination(google::GLOG_INFO,"./my_test_glog");  
    LOG(INFO) << "info:asdasdasdasd ";
    LOG(WARNING) << "warning:  123423423";
    LOG(ERROR) << "error: !@#$%^&*()";
    LOG(FATAL) << "fatal: fatal fatal fatal";
    google::ShutdownGoogleLogging();
    return 0;
}
