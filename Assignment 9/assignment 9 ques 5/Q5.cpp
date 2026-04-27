#include<iostream>
using namespace std;
template<class T>
int linearsearch(T arr[],int n,T key){
for (int i=0;i<n;i++){
if(arr[i]==key)
return i;
}
return -1;
}
int main(){
int n,key;
cout<<"enter size";
cin>>n;
int arr[n];
cout<<"enter elements";
for(int i=0;i<n;i++)
cin>>arr[i];
cout<<"enter elements to search";
cin>>key;
int result=linearsearch(arr,n,key);
if(result!=-1)
cout<<"element found at position"<<result;
else
cout<<"element not found";
return 0;
}