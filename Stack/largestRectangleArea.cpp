#include <iostream>
#include <vector>
#include<limits.h>
#include <stack>
using namespace std;
vector<int> nextSmaller(vector<int> &heights)
{
    stack<int> s;
    s.push(-1);

    vector<int> ans(heights.size());
    for (int i = heights.size()-1; i >= 0; i--)
    {
        int curr = heights[i];
        while (heights[s.top()] >= curr && s.top() != -1)
        {
            s.pop();
        }

        ans[i] = s.top();
        s.push(i);
    }
    return ans;
}
vector<int> prevSmaller(vector<int> &heights)
{
    stack<int> s;
    s.push(-1);

    vector<int> ans(heights.size());

    for (int i =0; i <heights.size(); i++)
    {
        int curr = heights[i];
        while (heights[s.top()] >= curr && s.top() != -1)
        {
            s.pop();
        }

        ans[i] = s.top();
        s.push(i);
    }
    return ans;
}
int largestReactangleArea(vector<int> &heights)
{
    vector<int>next = nextSmaller(heights);
    vector<int>prev = prevSmaller(heights);
    int maxArea = INT_MIN;
    int size = heights.size();
    for (int i = 0; i < heights.size(); i++)
    {
        int l = heights[i];
        if(next[i] ==-1)
        {
            next[i] = size;
        }
        int w = next[i] - prev [i] -1;
        int area = l*w;
        maxArea = max(area,maxArea);
    }
    return maxArea;
    
}
int main()
{
    vector<int> heights;
    heights.push_back(2);
    heights.push_back(1);
    heights.push_back(5);
    heights.push_back(6);
    heights.push_back(2);
    heights.push_back(3);

    cout<<"Maximum Rectangular Height is : "<<largestReactangleArea(heights);

}
