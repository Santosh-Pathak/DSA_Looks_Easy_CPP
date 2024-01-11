#include<iostream>
#include<stack>
using namespace std;

int main()
{   
    stack<char>st;
    string name = "santosh";
    for (int i = 0; i < name.size(); i++)
    {
        st.push(name[i]);
    }
    int i=0;
    while (!st.empty())
    {
        name[i++] = st.top();
        st.pop();
    }
    cout<<name;
    


    
}