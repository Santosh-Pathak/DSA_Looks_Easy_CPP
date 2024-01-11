#include <iostream>
#include <vector>
using namespace std;

class Nstack
{

    int *a, *top, *next;
    int n;        // no.of stack
    int size;     // sizeof main array
    int freeSpot; // tells free space in arrray

public:
    Nstack(int n, int s)
    {
        this->n = n;
        this->size = s;
        freeSpot = 0;
        a = new int[size];
        top = new int[n];
        next = new int[size];
        for (int i = 0; i < n; i++)
        {
            top[i] = -1;
        }

        for (int i = 0; i < size; i++)
        {
            next[i] = i + 1;
        }
        next[size - 1] = -1;
    }
    // push X into Mth stack
    bool push(int x, int m)
    {
        if (freeSpot == -1)
        {
            return false;
            //  stack OverFlow
        }
        // 1; find INdex
        int index = freeSpot;
        // 2; update freeSpot
        freeSpot = next[index];
        // 3; enter the data
        a[index] = x;
        // 4; update next
        next[index] = top[m - 1];
        // 5; update top
        top[m - 1] = index;

        return true;
    }
    // pop from Mth stack
    int pop(int m)
    {
        if (top[m - 1] == -1) // stack underFlow
            return -1;

        int index = top[m - 1];
        top[m - 1] = next[index];
        int poppedElement = a[index];
        next[index] = freeSpot;
        freeSpot = index;
        return poppedElement;
    }
    ~Nstack()
    {
        delete[] a;
        delete[] top;
        delete[] next;
    }
};
int main()
{
    Nstack s(3, 6);
    cout << s.push(10, 1) << endl;
    cout << s.push(1, 2) << endl;
    cout << s.push(40, 1) << endl;
    cout << s.push(10, 1) << endl;
    cout << s.push(10, 1) << endl;
    cout << s.pop(1) << endl;
    cout << s.pop(1) << endl;
    cout << s.pop(1) << endl;
    cout << s.pop(1) << endl;
    cout << s.pop(1) << endl;




}