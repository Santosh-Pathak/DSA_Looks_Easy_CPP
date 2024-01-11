#include <iostream>
using namespace std;

int binarySearch(int a[], int s, int e, int x)
{
    int mid = s + (e - s) / 2;
    while (s <= e)
    {
        if (a[mid] == x)
            return mid;
        else if (a[mid] > x)
            e = mid - 1;
        else
            s = mid + 1;

        mid = s + (e - s) / 2;
    }
    return -1;
}
int expSearch(int a[], int n, int x)
{
    if (a[0] == x)
        return 0;
    int i = 1;
    while (i < n && a[i] <= x)
    {
        i *= 2; // i=i*2//i= i<<1
    }
    return binarySearch(a, i / 2, min(i, n - 1), x);
}
int main()
{
    int a[] = {3, 4, 5, 6, 11, 13, 14, 15, 56, 70};
    int n = sizeof(a) / sizeof(int);
    int x = 13;
    int ans = expSearch(a, n, x);
    cout << "Index = " << ans;
    return 0;
}

