#include <iostream>
using namespace std;
void insertionSort(int n, int arr[])
{
    int j = 0;
    int shift =0;
    int compare =0;
    for (int i = 1; i < n; i++)
    {
        int x = arr[i];
        for (j = i - 1; j >= 0; j--)
        {
            if (arr[j] > x)
            {
                // shift
                cout<<"shift "<<shift++;
                arr[j + 1] = arr[j];
            }
            else
            { // stop the iteration
                break;
            }
           cout<<"compare "<<compare++;
        }
         arr[j + 1] = x;
    }
}
int main()
{
    int arr[] = {5, 4, 2, 7, 1, 12, 3};
    int n = sizeof(arr) / sizeof(int);
    insertionSort(n, arr);
    cout << "Sorted Array is : ";
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
}