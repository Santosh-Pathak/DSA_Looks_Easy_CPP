#include<iostream>
using namespace std;

int getithBit(int n ,int i)
{
    int mask = 1 << i;
    int ans = n & mask;
    return ans==0?0:1;
}
void setithBit(int n ,int i)
{   
    int mask = 1 << i; // creat mask
    int ans = n | mask;
    cout<<ans;
    // return ans;
}   
void clearithBit(int n, int i)
{
    int mask = ~(1<<i);
    int ans = n & mask;
    cout<< ans;
}
void clearLastiBits(int n ,int i)
{
    // int mask = (-1 << i); // another way is
    int mask = (~0) << i; // here ~0 == (-1)
    int ans = n & mask;
    cout<<ans;
}

void clearBitsinRange(int n ,int i,int j)
{
    int mask1 = (~(0) << (i+1));
    int mask2 = (1<<j) - 1;
    int mask =mask1 | mask2;
    int ans = mask & n;
    cout<<ans; 
}
int main()
{
    // int ans  =  getithBit(10,1);
    // cout<<ans;
    // setithBit(10,2);
    // clearithBit(10,1);
    // clearLastiBits(7,2);
    clearBitsinRange(15,2,1);
}