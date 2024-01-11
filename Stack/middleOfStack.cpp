#include <iostream>
#include <stack>
using namespace std;
void printMiddle(stack<int> &s, int &totalsize)
{
    if (totalsize == 0)
    {
        cout << "empty stack !!!";
        return;
    }
    if (s.size() == ((totalsize / 2) + 1))
    {
        cout << "Middle Element is " << s.top();
        s.pop();
        return;
    }

    int temp = s.top();
    s.pop();

    // .recursion
    printMiddle(s, totalsize);
    // backtrack
    s.push(temp);
}
void insertAtBottom(stack<int> &s,int data)
{
   
    if (s.size() == 0)
    {
       
        s.push(data);
        return;
    }

    int temp = s.top();
    s.pop();

    // .recursion
    insertAtBottom(s,data);
    // backtrack
    s.push(temp);
}
void reverseStack(stack<int> &s,int data)
{
   
    if (s.size() == 0)
    {
        return;
    }

    int temp = s.top();
    s.pop();

    // .recursion
    reverseStack(s,temp);
    // backtrack
    s.push(temp);
}
int main()
{
    stack<int> s;

    s.push(10);
    s.push(20);
    s.push(30);
    s.push(40);
    s.push(50);
    s.push(60);
    s.push(70);

    int size = s.size();
    // printMiddle(s, size);
    // cout<<endl;
    // while (!s.empty())
    // {
    //     cout<<s.top()<<" ";
    //     s.pop();
    // }
    // cout<<endl;
    // insertAtBottom(s,1);
    // while (!s.empty())
    // {
    //     cout<<s.top()<<" ";
    //     s.pop();
    // }
    reverseStack(s,0);
    while (!s.empty())
    {
        cout<<s.top()<<" ";
        s.pop();
    }
    
}