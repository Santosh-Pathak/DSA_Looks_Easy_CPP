#include <iostream>
using namespace std;
void mergeArray(int arr[], int s, int e)
{
    int length= e - s + 1;
    int gap = length/2 + (length%2);
    while (gap >0)
    {
        int i = s ,j = s + gap;
        while (j<=e)
        {
            if(arr[i] > arr[j])
            swap(arr[i],arr[j]);
            
        i++;
        j++;

        }
        gap = gap <=1?0:(gap/2)+(gap%2);
    }
    
  
     
}
void mergeSort(int s, int e, int arr[])
{
    if (s >= e)
    {
        return;
    }
    int mid = (s + e) / 2;
    // left part sort krna h
    mergeSort(s, mid, arr);
    // right part sort krna h
    mergeSort(mid + 1, e, arr);
    // merge two sub sorted array
    mergeArray(arr, s, e);
}

int main()
{
    int arr[] = {39, 27, 48, 3, 9, 82, 10};
    int n = sizeof(arr) / sizeof(int);
    mergeSort(0, n - 1, arr);
    cout<<" Sorted Array is :";
    for (int i = 0; i < n; i++)
    {
        cout << " " << arr[i];
    }
}