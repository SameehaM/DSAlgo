#include <bits/stdc++.h>
#define ll long long 
using namespace std;

int main()
{
    string s;
    cin>>s;
    ll i,n = s.size();
    sort(s.begin(),s.end());
    for(i = 0; i < n-1; i++)                                  // O(nlogn) time complexity.
    {
        if(s[i] == s[i+1])
            break;
    }
    if(i == n)
        cout<<"YES"<<endl;
    else
        cout<<"NO"<<endl;
}
