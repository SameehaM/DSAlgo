

int recursive_knapsack(int w[], int val[], int W, int N)
{
    if(N == 0 || W == 0)
        return 0;
    if(w[N-1] <= W)
        return max(recursive_knapsack(w, val, W - w[N-1], N-1) + val[N-1] , recursive_knapsack(w, val, W, N-1));
    if(w[N-1] > W)
        return recursive_knapsack(w, val, W, N-1);
}
// T(N) = 2T(N-1) + O(1), which is simplified to O(2^N).


-----------------------------------------------------------------------------------------------------------------------------

  
//memoization / Top-down
dp[1000][1000];
memset(dp, -1, sizeof(dp));
int mem_knapsack(int w[], int val[], int W, int N)
{
    if(N == 0 || W == 0)
        return 0;
    if(dp[N][W] != -1)
        return dp[N][W];
    if(w[N-1] <= W)
        return dp[N][W] = max(mem_knapsack(w, val, W - w[N-1], N-1) + val[N-1] , mem_knapsack(w, val, W, N-1);
    if(w[N-1] > W)
        return dp[N][W] = mem_knapsack(w, val, W, N-1);
}

                              
------------------------------------------------------------------------------------------------------------------------------
                              
                              
//tabulation / Bottom Up
dp[1000][1000];
memset(dp, -1, sizeof(dp));
int tab_knapsack(int w[], int val[], int W, int N)
{
    for(int i = 0; i < N+1; i++)
    {
        for(int j = 0; j < W+1; j++)
            dp[i][j] = 0;
    }
    for(int i = 1; i < N+1; i++)
    {
        for(int j = 1; j < W+1; j++)
        {
            if(w[i-1] <= j)// current wt can fit in bag // this is for the choice diagram of the recursive solution
                dp[i][j] = max(val[i-1] + dp[i-1][j - w[i-1]], dp[i-1][j]);
            else
                dp[i][j] = dp[i-1][j];
        }
    }
    return dp[N][W];
}
/* Complexity Analysis: 
Time Complexity: O(N*W). 
where ‘N’ is the number of weight element and ‘W’ is capacity. As for every weight element we traverse through all weight capacities 1<=w<=W.
Auxiliary Space: O(N*W). 
The use of 2-D array of size ‘N*W’.
*/
