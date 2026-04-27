#include<iostream>
using namespace std;
template <class T>
T findmax(T arr[],int n)
{
    T max=arr[0];
    for (int i=1;i<n;i++)
    {
        if (arr[i]>max)
        max=arr[i];
    }
    return max;
}
int main()
{
    int n;
    cout<<"Enter size";
    cin>>n;
    int arr[n];
    cout<<"enter elements";
    for(int i=0;i<n;i++)
    cin>>arr[i];
    cout<<"maximum ="<<findmax(arr,n);
    return 0;
}