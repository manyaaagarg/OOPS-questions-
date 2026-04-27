#include<iostream>
using namespace std;
template <class T>
T findmin(T arr[],int n){
T min=arr[0];
for (int i=1;i<n;i++){
if (arr[i]<min)
min=arr[i];
}
return min;
}
int main(){
int n;
cout<<"enter size";
cin>>n;
int arr[n];
cout<<"enter elements";
for (int i=0;i<n;i++)
cin>>arr[i];
cout<<"minimum  ="<<findmin(arr,n);
return 0;
}