#include <bits/stdc++.h>
using namespace std;
    bool isPalindrome(string s) 
    {
        int n = s.size();
        string out;
        for (int i = 0; i < n; i++)
        {
            if (isalpha(s[i])){out += tolower(s[i]);}
        }
        int front = 0;
        int back = out.size()-1;
        cout << out;
        while (front <= back)
        {
            if(out[front]!=out[back]){return false;}
            front++; back--;
        }
        return true;
    }
int main()
{
    string s;
    cin >> s;
    cout << isPalindrome(s);
}
