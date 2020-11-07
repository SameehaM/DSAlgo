#include <bits/stdc++.h>
#define ll long long
using namespace std;
//Stack is LIFO i.e adding and removing happens from one side only
int main()
{
    stack <pair < ll, ll > > st; //store element and min of stack till that particular element;
    ll x, n;
    cin>>n;
    for(int i = 0; i < n; i++)
    {
        cin>>x;
        mi = min(mi,x);
        st.push({x,mi});
    }
    cout<<"Minimum Element is "<<st.top().second<<endl;
}
