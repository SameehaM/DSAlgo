#include <bits/stdc++.h>
#define ll long long

using namespace std;

int main()
{
	ll n, stages;
	cin>>n;
	cout<<"Enter Stages"<<endl;
	cin>>stages;
	n++; //index 0,0 = {0}
	ll adj[n][n] = {0};
	cout<<"Enter Adjacency matrix"<<endl;
	for(ll i = 0; i < n; i++)
		for(ll j = 0; j < n; j++)
        {
            cin>>adj[i][j];
        }
	ll cost[n] = {0}, d[n] = {0}, min = INT_MAX;
	for(ll i = n-1; i > 0; i--)
	{
		min = INT_MAX;
		for(ll j = i+1; j < n; j++)
		{
			if(adj[i][j] != 0 && adj[i][j] + cost[j] < min)
			{
				min = adj[i][j] + cost[j];
				cost[i] = min;
				d[i] = j;
			}
		}
	}
	cout<<"Cost"<<endl;
	for(ll i = 0; i < n; i++)
		cout<<cost[i]<<" ";
	cout<<endl<<"D "<<endl;
	for(ll i = 0; i < n; i++)
		cout<<d[i]<<" ";
	cout<<endl;
	ll path[stages+1];
	path[1] = 1;
	for(ll i = 2; i <= stages; i++)
	{
		path[i] = d[path[i-1]];
	}
	cout<<"Total Cost "<<cost[1]<<endl<<"Path is: "<<endl;
	for(ll i = 1; i <= stages; i++)
		cout<<path[i]<<"->";
	cout<<"Done"<<endl;
}

/*
OUTPUT:-
9
Enter Stages
5
Enter Adjacency matrix
0 0 0 0 0 0 0 0 0 0
0 0 5 2 0 0 0 0 0 0
0 0 0 0 3 0 3 0 0 0
0 0 0 0 6 5 8 0 0 0
0 0 0 0 0 0 0 1 4 0
0 0 0 0 0 0 0 6 2 0
0 0 0 0 0 0 0 6 2 0
0 0 0 0 0 0 0 0 0 7
0 0 0 0 0 0 0 0 0 3
0 0 0 0 0 0 0 0 0 0
Cost
0 12 8 10 7 5 5 7 3 0
D
0 3 6 5 8 8 8 9 9 0
Total Cost 12
Path is:
1->3->5->8->9->Done
*/
