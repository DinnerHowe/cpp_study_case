#include <iostream>
using namespace std;
//基类Base
class Base
{
    public:
        //普通函数
        void f1(int x)
        { 
                cout << "\nBase::f1(int) " << x << endl;
        } 
        //虚函数
        virtual void f2(int x)
        {
                cout << "Base::f2(int)"<< x << endl;
        } 
        //纯虚函数，将由子类实现
        virtual void f3(int x)=0;

};
//继承Derived
class Derived:public Base
{
    public:
        void f1(int x)
        {
                cout<<"\nDerived:g1(int)"<< x << endl;
        }
        //覆盖Base的f2
        void f2(int x)
        {
                cout<<"Derived:g2(int)"<< x << endl;
        }
        //在子类中被重载，以多态的形式被调用，实现Base的纯虚函数
        //a.编译时多态性：通过重载函数实现
        //b 运行时多态性：通过虚函数实现。
        void f3(int x)
        {
                cout<<"Derived:g3(int)"<< x << endl;
        }
};

int main(int argc, char **argv)
{
       Derived *pderived = new Derived;
       pderived->f1(1);
       pderived->f2(2);
       pderived->f3(3);

       
       Base *pbase = new Derived; 
       pbase->f1(1);
       pbase->f2(2);
       pbase->f3(3); 
       
       Derived derived;
       derived.f1(1);
       derived.f2(2);
       derived.f3(3);
       
       //Base base; //有纯虚函数不能声明
       //Base *base = new base; //有纯虚函数不能new
       //base.f1(1);
       //base.f2(2);
       //base.f3(3);       
}
