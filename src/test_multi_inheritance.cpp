#include <iostream>
using namespace std;
class B1
{
public:
       B1(int i)
       {
              b1 = i;
              cout<<"构造函数 B1."<<i<< endl;
       }
       void print()
       {
              cout<<"B1.print()"<<b1<<endl;
       }
private:
       int b1;
};
 
class B2
{
public:
       B2(int i)
       {
              b2 = i;
              cout<<"构造函数 B2."<<i<< endl;
       }
       void print()
       {
              cout<<"B2.print()"<<b2<<endl;
       }
private:
       int b2;
};

class Derived : public B2, public B1//先继承B2后继承B1，所以先打印B2再打印B1。
{
public:
       Derived(int i, int j, int k):B1(i),B2(j)//初始化列表不分先后
       {
              cout<<"构造函数 Derived."<<k<<endl;
       }
       void print()
       {
              B1::print();
              B2::print();
       }
private:
       int a;
};
int main()
{
       Derived derived(1, 2, 3);
       derived.print();      
}
