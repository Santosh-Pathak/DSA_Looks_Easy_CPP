#include <iostream>
using namespace std;
void BubbleSort(int n, int arr[])
{
    bool swapped =false;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n - 1 - i; j++)
        {
            if (arr[j] > arr[j + 1])
            {
                swap(arr[j], arr[j + 1]);
                swapped =true;
            }
        }
        if(swapped==false)
        {
            return ;
        }
    }
}
int main()
{
    int arr[] = {5, 4, 2, 7, 1, 12, 3};
    int n = sizeof(arr) / sizeof(int);
    BubbleSort(n, arr);
    cout << "Sorted Array is : ";
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
}