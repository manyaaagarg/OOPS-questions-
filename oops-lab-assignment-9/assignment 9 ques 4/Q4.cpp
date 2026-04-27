#include<iostream>
using namespace std;
template <class T>
void bubblesort(T arr[],int n){
for (int i=0;i<n-1;i++){
for(int j=0;j<n-i-1;j++){
if (arr[j]>arr[j+1]){
T temp =arr[j];
arr[j]=arr[j+1];
arr[j+1]=temp;
}
}
}
}
int main(){
int n;
cout<<"enter size ";
cin>>n;
int arr[n];
cout<<"enter elements";
for(int i=0;i<n;i++)
cin>>arr[i];
bubblesort(arr,n);
cout<<"sorted array";
for(int i=0;i<n;i++)
cout<<arr[i]<<" ";
return 0;
}