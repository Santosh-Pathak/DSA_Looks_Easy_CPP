#include <iostream>
using namespace std;
class TrieNode
{
public:
    char data;
    TrieNode *children;
    bool isTerminal;

    TrieNode(char d)
    {
        this->data = d;
        children = new TrieNode(26);
        this->isTerminal = false;
    }
};
int main()
{
    TrieNode * root = new TrieNode('-');
}