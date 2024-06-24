#include <bits/stdc++.h>
using namespace std;

int getSum(int a, int b) 
{
    int c = 0;
    int flag = 0;
    while (a || b)
    {
        int bit = (a&1) ^ (b&1);
        int check = (a&1) & (b&1);
        
        bit ^= flag;
        flag = check;
        c |= bit;
        a >>= 1; b >>= 1;
        c <<= 1;
        cout << c << endl;
    }
    return c;
}

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int a, b; cin >> a >> b;
        int x = getSum(a, b);
        cout << endl;
    }
}