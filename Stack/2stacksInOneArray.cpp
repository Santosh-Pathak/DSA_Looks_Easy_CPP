#include<iostream>
using namespace std;
class Stack{
    public:
    int *arr;
    int size;
    int top1;
    int top2;
    Stack(int size)
    {
        arr = new int[size];
        this->size=size;
        top1=-1;
        top2=size;
    }
    //helper function
    void push1(int data){
        if(top2 -top1 == 1)
        {
            cout<<" OVERFLOW (Space Not Available) !!!"<<endl;
        }
        else
        {
            ++top1;
            arr[top1] = data;
        }
    }
    
    void pop1(){
        if(top1 == -1 )
        {
            cout<<" UNDERFLOW (Data Not Available) in Stack 1 !!!"<<endl;

        }
        else
        {
            top1--;
        }
    }
     bool isEmpty1()
    {
        return top1==-1?true:false;
    }
     int getTop1()
    {
        if(top1==-1)
        {
            cout<<"Stack underFlow , Can't read Elements !!";
            return -1;
        }

         return arr[top1];
        
    }
    void push2(int data){
         if(top2 -top1 == 1)
        {
            cout<<" OVERFLOW (space Not Available) !!!"<<endl;
        }
        else
        {
            --top2;
            arr[top2] = data;
        }
    }

    void pop2(){
         if(top2 == size )
        {
            cout<<" UNDERFLOW (Data Not Available) in Stack 2 !!!"<<endl;
        }
        else
        {
            top2++;
        }
    }
     bool isEmpty2()
    {
        return top2==size?true:false;
    }
     int getTop2()
    {
        if(top2==size)
        {
            cout<<"Stack underFlow , Can't read Elements !!";
            return -1;
        }

         return arr[top2];
        
    }
};
int main()
{
    Stack  s(10);
    s.push1(10);
    s.push1(20);
    s.push1(30);
    s.push2(40);
    s.push2(50);
    s.push2(60);
    while (!s.isEmpty1())
    {
        cout<<s.getTop1()<<" ";
        s.pop1();
    }
    cout<<endl;
    while (!s.isEmpty2())
    {
        cout<<s.getTop2()<<" ";
        s.pop2();
    }
    
    
}