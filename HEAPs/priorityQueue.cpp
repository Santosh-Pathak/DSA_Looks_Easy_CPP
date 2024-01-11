#include <iostream>
#include <queue>
using namespace std;

int main()
{
    // MAXHEAP by STL
    // priority_queue<int> pq;
    // pq.push(4);
    // pq.push(7);
    // pq.push(9);
    // pq.push(3);
    // pq.push(11);
    // pq.push(6);
    // pq.push(15);
    // cout << "printing  Min heap : ";
    // while (!pq.empty())
    // {
    //     cout << pq.top() << " ";
    //     pq.pop();
    // }
    // MINHEAP by STL
    priority_queue<int, vector<int>, greater<int>> pq;
    pq.push(4);
    pq.push(7);
    pq.push(9);
    pq.push(3);
    pq.push(11);
    pq.push(6);
    pq.push(15);
    cout << "printing  Min heap : ";
    while (!pq.empty())
    {
        cout << pq.top() << " ";
        pq.pop();
    }
    
}
