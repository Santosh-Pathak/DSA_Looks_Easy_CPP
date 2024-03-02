#include <iostream>
using namespace std;
void mergeArray(int arr[], int s, int e)
{
    int mid = (s + e) / 2;
    int l1 = mid - s + 1;
    int l2 = e - mid;

    int *first = new int[l1];
    int *second = new int[l2];

    // copy values
    int k = s;
    for (int i = 0; i < l1; i++)
    {
        first[i] = arr[k++];
    }
    k = mid + 1;
    for (int i = 0; i < l2; i++)
    {
        second[i] = arr[k++];
    }
    // merge
    int index1 = 0;
    int index2 = 0;
    k = s;
    while (index1 < l1 && index2 < l2)
    {
        if (first[index1] < second[index2])
        {
            arr[k++] = first[index1++];
        }
        else
        {
            arr[k++] = second[index2++];
        }
    }
    while (index1 < l1)
    {
        arr[k++] = first[index1++];
    }
    while (index2 < l2)
    {
        arr[k++] = second[index2++];
    }
    delete []first;
    delete []second;
    
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
    cout<<" Sorted Array is :"
    for (int i = 0; i < n; i++)
    {
        cout << " " << arr[i];
    }
}