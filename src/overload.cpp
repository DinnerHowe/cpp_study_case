#include <iostream>
using namespace std;

class Status
{
    public:
        int code_;
        Status():code_(2){cout << "list init code: "<< code_ << endl;}
        ~Status();
        Status(int a)
        {
                cout << "int Fun(int a)"<< a << endl;
        }

        Status(float a)
        {
                cout << "void Fun(float a)"<< a << endl;
        }
        
        int Fun(int a)
        {
                cout << "void Fun(int a)"<< a << endl;
                return a;
        }
        float Fun(float a)
        {
                cout << "void Fun(float a)"<< a << endl;
                return a;
        }
        //int Fun(float a) //无法重载因为输入的参数和float Fun(float a)一样
        //{
        //        cout << "void Fun(float a)"<< a << endl;
        //        return 1;
        //}
};

int main(int argc, char **argv)
{
        Status *pfun = new Status();
        Status *pfun1 = new Status(9);
        Status *pfun2 = new Status(0.1f);
        cout << pfun1->Fun(3) << endl;
        cout << pfun2->Fun(0.3f) << endl;
        cout << "#########" << endl;
        cout << "code_ "<< pfun->code_ <<endl;
        cout << "code_ "<< pfun1->code_ <<endl;
        cout << "code_ "<< pfun2->code_ <<endl;
        return 0;
}
