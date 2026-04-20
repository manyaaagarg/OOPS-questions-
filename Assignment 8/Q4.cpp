#include<iostream>
using namespace std;
// template function to sort array using bubble sort
template<class T>
void bubbleSort(T arr[], int n)
{
   int i, j;
    float temp;
    for(i = 0; i < n-1; i++)
    {
        for(j = 0; j < n-i-1; j++)
        {
            if(arr[j] > arr[j+1])
            {
                temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
        }
    }
}
int main()
{
    int n;
    cout << "Enter number of elements: ";
    cin >> n;
    float arr[50];
    cout << "Enter " << n << " elements: ";
    for(int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    cout << "Before sorting: ";
    for(int i = 0; i < n; i++)
        cout << arr[i] << " ";
    cout << endl;

    bubbleSort(arr, n);

    cout << "After sorting:  ";
    for(int i = 0; i < n; i++)
        cout << arr[i] << " ";
    cout << endl;
    return 0;
}