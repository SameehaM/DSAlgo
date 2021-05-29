#include <bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin>> t;
    while(t--){
        int N, K;
        cin>>N>>K;
        int a[N];
        for(int i = 0; i < N; i++)
            cin>>a[i];
        int j = 0, i = 0, sum = 0, ans = INT_MIN;
        while(j < N)
        {
            sum = sum + a[j];
            if(j - i + 1 < K){
                j++;
                continue;
            }
            if(j - i + 1 == K)
            {
                ans = max(ans, sum);
                j++;
                i++;
            }
            sum = sum - a[i-1];
        }
        cout<<ans<<"\n";
}
}
