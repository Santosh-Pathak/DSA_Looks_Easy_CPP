#include <iostream>
#include <stack>
#include <vector>
using namespace std;
int main()
{
    vector<int> arr = {2, 1, 4, 3};

    stack<int> s;
    s.push(-1);

    vector<int> ans(arr.size());
    for (int i = arr.size() - 1; i >= 0; i--)
    {
        int curr = arr[i];
        // apka answer stack m h
        while (s.top() >= curr)
        {  // if top element of stack is greater than arr[i]
            s.pop();
        }
        // store the answer in the answer vector list (answer mil chuka h )
        ans[i] = s.top();
        //push the the current element in stack for further comparison
        s.push(curr);
    }

    for (int i = 0; i < ans.size(); i++)
    {
        cout << ans[i] << " ";
    }
}