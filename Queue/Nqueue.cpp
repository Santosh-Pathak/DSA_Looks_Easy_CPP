#include <iostream>
using namespace std;
class Kqueue
{

    int n, k, freeSpot;
    int *arr, *front, *rear, *next;

    Kqueue(int n, int k)
    {
        this->n = n;
        this->k = k;
        arr = new int[n];
        front = new int[k];
        rear = new int[k];
        next = new int[n];
        // intialize the array with -1
        for (int i = 0; i < k; i++)
        {
            front[i] = rear[i] = -1;
        }
        // push the index of next element in
        for (int i = 0; i < n; i++)
        {
            next[i] = i + 1;
        }
        next[n - 1] = -1;

        // push x into q th Queue
        bool push(int x, int qi)
        {
            if (freeSpot == -1)
            {
                return false;
            }

            int index = freeSpot;

            // update freeSpot
            freeSpot = next[index];

            // if first element in queue is coming
            if (front[qi] == -1)
            {
                front[qi] = index;
            }
            else
            {
                // link new elemtn to that q's rearest elemtn
                next[rear[qi]] = index;
            }

            // update next
            next[index] = -1;

            // update rear
            rear[qi] = index;
            arr[index] = x;
            return true;
        }
    }
    int pop(int qi)
    {
        //underFlow
        if(front[qi] == -1)
        {
            return -1;
        }
        //find the index to pop
        int index = front[qi];

        //front update
        front[qi] = next[index];

        //update freeSpot
        next[index] = freeSpot;
        freeSpot=index;

        return arr[index];

    }

};
 int main()
{
}