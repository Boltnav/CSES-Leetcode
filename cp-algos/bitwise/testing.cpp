#include <bits/stdc++.h>
using namespace std;
using ll = long long;

bool isPowerOfTwo(unsigned int n) 
{
    return n && !(n & (n - 1));
}

ll clearRightmostSetBit(ll n)
{
    return n & (n-1);
}

ll countSetBits(ll n)   // Bern Kernighan !
{
    ll count = 0; 
    while (n)
    {
        n = n & (n-1);
        count++;
    }
    return count; 
}

int bit_width(int n) 
{
    return log2(n) + 1;
}
int countSetBits(int n) 
{
    int count = 0;
    while (n > 0) 
    {
        int x = bit_width(n) - 1;
        count += x << (x - 1);
        n -= 1 << x;
        count += n + 1;
    }
    return count;
}

int main()
{
    int n; cin >> n;
    cout << countSetBits(n);
}