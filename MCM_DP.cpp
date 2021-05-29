#include <bits/stdc++.h>
using namespace std;
int dp[100][100];
    int mcmdp(int a[], int i, int j)
    {
        if(i == j)
            return 0;
        if(dp[i][j] != -1)
            return dp[i][j];
        dp[i][j] = INT_MAX;
        for(int k = i; k < j; k++)
        {
            dp[i][j] = min(dp[i][j], mcmdp(a, i, k) + mcmdp(a, k+1, j) + a[i-1]*a[k]*a[j]);
        }
        return dp[i][j];
    }
    
    int matrixMultiplication(int N, int arr[])
    {
        int i = 1, j = N - 1;
        memset(dp, -1, sizeof dp);
        return mcmdp(arr, i, j);
    }
    int main()
    {
        int n;
        cin>>n;
        int a[n];
        for(int i = 0; i < n; i++)
            cin>>a[i];
        cout<<matrixMultiplication(n, a)<<"\n";
    }
