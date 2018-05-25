#include <iostream>
using namespace std;
//假设有基类Base
class Base
{
    public:
        //普通函数
        void f(int x)
        { 
                cout << "Base::f(int) " << x << endl;
        }
        //普通函数重载overloaded
        void f(float x)
        {
                cout << "Base::f(float) " << x << endl;
        } 
        virtual void g(float x)
        {
                cout << "Base::g(void)"<< x << endl;
        } //虚函数
};
//继承/派生类Derived
class Derived:public Base
{
    public:
        virtual void g(float x)//覆盖Base的virtual void g(float x)
        {
                cout << "Derived::g(void)"<< x << endl;
        }
};

int main(int argc, char **argv)
{
//注意不指明f的话默认是double
//用指针节约空间，不用指针直接声明也可以
       cout <<"********* Derived derived *********"<<endl;
       Derived derived;
       derived.f(1);    //继承了Base的f(int x)
       derived.f(2.0f); //继承了Base的f(float x)
       derived.g(3.0f); //覆盖了Base的virtual void g(float x)
       cout <<"********* Base *pderived = &derived *********"<<endl;
       Base *pderived = &derived; 
       pderived->f(1);  //继承了Base的f(int x)
       pderived->f(2.0f);//继承了Base的f(float x)
       pderived->g(3.0f);//覆盖了Base的virtual void g(float x)
       cout <<"********* Base *npderived = new Derived *********"<<endl;
       Base *npderived = new Derived; 
       npderived->f(1);  //继承了Base的f(int x)
       npderived->f(2.0f);//继承了Base的f(float x)
       npderived->g(3.0f);//覆盖了Base的virtual void g(float x)
//用指针或者直接声明，或者new一下都可以
       cout <<"********** Base base ********"<<endl;
       Base base;        //没有纯虚函数，因此可以声明
       base.f(1);        //调用Base的f(int x)
       base.f(2.0f);     //调用Base的f(float x)
       base.g(3.0f);     //调用Base的g(float x)
}
