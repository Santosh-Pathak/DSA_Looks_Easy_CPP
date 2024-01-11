#include <iostream>
#include <unordered_map>
using namespace std;

int main()
{ // create  Unordered map
    unordered_map<string, int> m;
    // insertion type 1
    pair<string, int> p = make_pair("Santosh", 55);
    m.insert(p);
    // insertion type 2
    pair<string, int> p2("Ayush", 18);
    m.insert(p2);
    // insertion type 3
    m["Sweta"] = 71;
    // Display
    for (auto a : m)
    {
        cout << a.first << " -> " << a.second << endl;
    }
    // Access
    //  cout<<m.at("Santosh")<<endl;
    //  cout<<m.at("Ayush")<<endl;
    cout << m["Ayush"] << endl;
    // search
    //  cout<<m.count("Santosh")<<endl;

    if (m.find("Santosh") != m.end())
    {
        cout << "Santosh Found" << endl; 
    }
    else
    {
        cout << "Santosh  not Found " << endl;
    }
    cout<<m.size();         
    return 0;
}