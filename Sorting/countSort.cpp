#include <iostream>
#include <vector>
using namespace std;
int main()
{
    int n;
    int val;
    cout << "Enter the number of elements : ";
    cin >> n;
    cout << "Enter the Elements : ";
    vector<int> v(n);
    for (int i = 0; i < n; i++)
    {
        cin >> val;
        v.push_back(val);
    }
}