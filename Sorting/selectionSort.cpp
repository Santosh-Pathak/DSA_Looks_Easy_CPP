// in selection sort we pick up an correct data item and we place at correct position
#include <iostream>
using namespace std;
void selectionSort(int n, int arr[])
{
   for(int i=0;i<n-1;i++){
    int minIndex=i;
    for(int j=i+1;j<n;j++)
    {
        if(arr[minIndex]>arr[j])
        {
            minIndex = j;
        }
    }
    swap(arr[minIndex],arr[i]);
   }
}
int main()
{
    int arr[] = {5, 4, 2, 7, 1, 12, 3};
    int n = sizeof(arr) / sizeof(int);
    selectionSort(n, arr);
    cout << "Sorted Array is : ";
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
}