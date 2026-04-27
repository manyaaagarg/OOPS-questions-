#include<iostream>
using namespace std;
template<class T>
class stack{
T arr[50];
int top;
public:
stack9
{
top=-1;
}
void push(T value){
if(top==49)
cout<<"overflow";
else
arr[++top]=value;
}
void pop(){
if(top==-1)
cout<<"underflow";
else top--

}
void display(){
for(int i=top;i>=0;i--)
cout<<arr[i]<<" ";
cout<<endl;
}
};
int main(){
stack<int>s;
int n,x;
cout<<"enter number of elements";
cin>>n;
for(int i=0;i<n;i++){
cin>>x;
s.push(x);
}
cout<<"stack";
s.display();
s.pop();
cout<<"after pop";
s.display();
return 0;   d
}
