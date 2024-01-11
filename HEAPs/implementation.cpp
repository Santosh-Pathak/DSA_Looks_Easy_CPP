#include <iostream>
using namespace std;
class Heap
{
public:
    int arr[100];
    int size;
    Heap()
    {
        size = 0;
    }
    void insert(int val)
    {
        // value insert karo
        ++size;
        int index = size;
        arr[index] = val;

        // place the value at its correct position
        while (index > 1)
        {
            int parentIndex = index / 2;
            if (arr[index] > arr[parentIndex])
            {
                swap(arr[index], arr[parentIndex]);
                index = parentIndex;
            }
            else
            {
                break;
            }
        }
    }

    void delete()
    {
        // replace root node value eith last node data
        arr[1] = arr[size];
        size--;

        // replace root node ka data on tis correct position
        int index = 1;
        while (index < size)
        {
            int left = 2 * index;
            int right = 2 * index + 1;

            int largest = index;

            if (left < size && arr[index] < arr[left])
            {
                largest = left;
            }
            if (right < size && arr[index] < arr[right])
            {
                largest = right;
            }

            if (largest == index)
            {
                // value a its correct postion
                return;
            }
            else
            {
                swap(arr[index], arr[largest]);
                index = largest;
            }
        }
    }

    void buildHeap(int arr[],int n)
    {
        for (int i = n/2; i>0; i--)
        {
            heapify(arr,n,i);
        }
        
    }
};

int main()
{
    Heap h;
    // h.arr[0] = -1;
    // // h.arr[1] = 100;
    // // h.arr[2] = 50;
    // // h.arr[3] = 60;
    // // h.arr[4] = 40;
    // // h.arr[5] = 45;
    // // h.arr[6] = 10;
    // // h.arr[7] = 20;
    // h.insert(50);
    // h.insert(30);
    // h.insert(60);
    // h.insert(45);
    // h.insert(90);

    // h.size = 5;
    // cout << "Printing the Heap Eleemnts : " << endl;
    // for (int i = 0; i <= h.size; i++)
    // {
    //     cout << h.arr[i] << " ";
    // }
    // h.insert(110);
    // cout << endl
    //      << "Printing the Heap Eleemnts : " << endl;
    // for (int i = 0; i <= h.size; i++)
    // {
    //     cout << h.arr[i] << " ";
    // }

    
   
}
