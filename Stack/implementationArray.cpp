#include <iostream>
// #include <stack>
using namespace std;
class Stack{
    public:
    int *arr;
    int size;
    int top;
    //CONSTRUCTOR
    Stack(int size)
    {
        arr = new int[size];
        this->size = size;
        top =-1;
    }

    void push(int data)
    {
        if(size-top > 1)
        {
            //space available
            ++top;
            arr[top] = data;
        }
        else{
            
            cout<<"Stack OverFlow !!";
        }
    }
    void pop()
    {
        if(top == -1)
        {
            cout<<"Stack underFlow , Can't read Elements !!";
        }
        else
        {
            //element is present
            top--;
        }
    }
    int getTop()
    {
        if(top==-1)
        {
            cout<<"Stack underFlow , Can't read Elements !!";
            return -1;
        }

         return arr[top];
        
    }

    int getSize()
    {
        return top+1;
    }

    bool isEmpty()
    {
        return top==-1?true:false;
    }

};
// void print(stack<int>s)
// {
//     while(!s.isEmpty())
//     {
//          cout << s.top()<<" ";
//          s.pop();
//     }
// }
int main()
{
    Stack s(10);

    s.push(10);
    s.push(20);
    s.push(30);
    s.push(40);
    s.push(10);
    s.push(20);
    s.push(30);
    s.push(40);

    while(!s.isEmpty())
    {
        cout<<s.getTop()<<" ";
        s.pop();
    }
    cout<<endl<<"Size : "<<s.getSize()<<endl;
    s.pop();
}