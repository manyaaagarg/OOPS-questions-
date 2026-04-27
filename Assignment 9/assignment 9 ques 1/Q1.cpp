#include <iostream>
using namespace std;
template<class T>
void swap(T&a,T&b)
{
T temp;
temp=a;
a=b;
b=temp;
}
int main(){
int x,y;
cout<<"enter two numbers";
cin>>x>>y;
swap(x,y);
cout<<"after swapping"<<x<< " "<<y;
return 0;
}