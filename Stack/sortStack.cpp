#include <iostream>
#include <stack>
using namespace std;
void insertSorted(stack<int>&s,int data)
{
    if(s.empty())
    {
        s.push(data);
        return;
    }
    if(s.top()>= data)
    {
        s.push(data);
        return;
    }

    int top = s.top();
    s.pop();

    insertSorted(s,data);
    //backtrack
    s.push(top);
}
void sortStack(stack<int>&s)
{
    if(s.size()==0)
    {
        return;
    }
    int top = s.top();
    s.pop();

    sortStack(s);
    //
    insertSorted(s,top);

}
int main()
{
    stack<int> s;

    s.push(10);
    s.push(20);
    s.push(50);
    s.push(60);
    s.push(30);
    s.push(70);
    s.push(40);


    int size = s.size();
    
    // while (!s.empty())
    // {
    //     cout<<s.top()<<" ";
    //     s.pop();
    // }
    cout<<endl;
    sortStack(s);
    while (!s.empty())
    {
        cout<<s.top()<<" ";
        s.pop();
    }

    
}