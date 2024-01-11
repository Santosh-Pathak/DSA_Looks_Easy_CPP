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
        this->size=size;
        front=0;
        rear = 0;
        arr = new int[size];
    }


    void push(int data)
    {
        if (rear == size)
        {
            cout << "Queue Overloaded "<<endl;
            return;
        }
        else
        {
            arr[rear] = data;
            rear++;
        }
    }
    void pop()
    {
        if (front == rear)
        {
            cout << "Queue is Empty"<<endl;
            return;
        }
        else
        {
            arr[front] = -1;
            front++;
            if (front == rear)
            {
                front = 0;
                rear = 0;
            }
        }
    }

    int getFront()
    {
        if (front == rear)
        {
            cout << "Queue is Empty"<<endl;
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
            cout << "Queue is Empty"<<endl;
            return true; 
        }
        else
        {
            return false;
        }
    }
    int getSize()
    {
        return rear-front;
    }
};
int main()
{
    Queue q(5);

    q.push(1);
    q.push(2);
    q.push(3);

    cout<<q.getFront()<<" ";
    q.pop();
    cout<<q.getFront()<<" ";
    cout<<q.getSize()<<" ";


}