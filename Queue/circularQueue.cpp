#include <iostream>
using namespace std;

class Queue
{
public:
    int *arr;
    int size;
    int front;
    int rear;

    Queue(int size)
    {
        this->size = size;
        front = -1;
        rear = -1;
        arr = new int[size];
    }

    void push(int data)
    {
        if (front == -1 && rear == size - 1)
        {
            cout << "Queue is Full" << endl;
            return;
        }
        else if (rear == -1 && front == -1)
        {
            front = rear = 0;
            arr[rear] = data;
        }
        else if (rear == size - 1 &&front ! = 0)
        {
            rear = 0;
            arr[rear] = data;
        }
        else if (rear == front - 1)
        {
            cout << "Queue is Full" << endl;
            return;
        }
        else
        {
            rear++;
            arr[rear] = data;
        }
    }

    void pop()
    {
        if (front == -1 && rear == -1)
        {
            cout << "Q is Empty " << endl;
            return;
        }
        else if (front == rear)
        {
            arr[front] == -1;
            front = -1;
            rear = -1;
        }
        else if (front == size - 1)
        {
            front = 0;
        }
        else
        {
            arr[front] =-1;
            front++;
        }
    }

    int getFront()
    {
        if (front == rear)
        {
            cout << "Queue is Empty" << endl;
            return -1;
        }
        else
        {
            return arr[front];
        }
    }

    bool isEmpty()
    {

        if (front == rear)
        {
            cout << "Queue is Empty" << endl;
            return true;
        }
        else
        {
            return false;
        }
    }

    int getSize()
    {
        return rear - front;
    }
};
int main()
{
    Queue q(5);

    q.push(1);
    q.push(2);
    q.push(3);

    cout << q.getFront() << " ";
    q.pop();
    cout << q.getFront() << " ";
    cout << q.getSize() << " ";
}