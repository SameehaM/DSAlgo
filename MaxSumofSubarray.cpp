#include <bits/stdc++.h>
using namespace std;
int n,a[10000];
int maxsum()
{
    int sum = 0,ans = 0,min_sum = 0;
    for(int i = 0; i < n; i++)
    {
        sum = sum + a[i]; // sum of the entire array (if non negative then sum is the answer)
        ans = max(ans, sum - min_sum); //this is to avoid negative sum i.e min sum value will change only if sum is negative 
        min_sum = min(min_sum, sum);   //when a negative element gets added sum-minsum ensures the deletion of negative values from array in sum while comparing the maximum sum.
    }
    return ans;
}
int main()
{
    cin>>n;
    for(int i = 0; i < n; i++)
        cin>>a[i];
    cout<<maxsum()<<"\n";
}
