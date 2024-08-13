#include <iostream>
using namespace std;

int partition(int arr[], int s, int e)
{

    int pivot = arr[s];

    int cnt = 0;
    for (int i = s + 1; i <= e; i++)
    {
        if (arr[i] <= pivot)
        {
            cnt++;
        }
    }

    // place pivot at right position
    int pivotIndex = s + cnt;
    swap(arr[pivotIndex], arr[s]);

    // left and right wala part smbhal lete h
    int i = s, j = e;

    while (i < pivotIndex && j > pivotIndex)
    {

        while (arr[i] <= pivot)
        {
            i++;
        }

        while (arr[j] > pivot)
        {
            j--;
        }

        if (i < pivotIndex && j > pivotIndex)
        {
            swap(arr[i++], arr[j--]);
        }
    }

    return pivotIndex;
}

void quickSort(int arr[], int s, int e)
{

    // base case
    if (s >= e)
        return;

    // partitioon karenfe
    int p = partition(arr, s, e);

    // left part sort karo
    quickSort(arr, s, p - 1);

    // right wala part sort karo
    quickSort(arr, p + 1, e);
}

int main()
{

    int arr[] = {28, 153, 174, 499, 281, 117, 471, 367, 281, 460, 501, 574,
                 277, 156, 926, 800, 694, 502, 445, 723, 700, 519, 752, 629, 269, 76, 357,
                 502, 413, 102, 566, 794, 255, 92, 293, 888, 209, 765, 607, 491, 577, 460,
                 417, 854, 616, 343, 6, 311, 845, 804, 34, 28, 153, 174, 499, 281, 117, 471,
                 367, 281, 460, 501, 574, 277, 156, 926, 800, 694, 502, 445, 723, 700, 519, 752,
                 629, 269, 76, 357, 502, 413, 102, 566, 794, 255, 92, 293, 888, 209, 765, 607, 491, 577,
                 460, 417, 854, 616, 343, 6, 311, 845, 804, 34, 28, 153, 174, 499, 281, 117, 471,
                 367, 281, 460, 501, 574, 277, 156, 926, 800, 694, 502, 445, 723, 700, 519, 752, 629, 269,
                 76, 357, 502, 413, 102, 566, 794, 255, 92, 293, 888, 209, 765, 607, 491, 577, 460, 417, 854,
                 616, 343, 6, 311, 845, 804, 34, 28, 153, 174, 499, 281, 117, 471, 367, 281, 460, 501, 574, 277,
                 156, 926, 800, 694, 502, 445, 723, 700, 519, 752, 629, 269, 76, 357, 502, 413, 102, 566, 794, 255,
                 92, 293, 888, 209, 765, 607, 491, 577, 460, 417, 854, 616, 343, 6, 311, 845, 804, 34};
    int n = sizeof(arr) / sizeof(int);
    quickSort(arr, 0, n - 1);

    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;

    return 0;
}
