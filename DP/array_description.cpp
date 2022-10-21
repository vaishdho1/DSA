/*
You know that an array has n integers between 1 and m, and the absolute difference between two adjacent values is at most 1.

Given a description of the array where some values may be unknown, your task is to count the number of arrays that match the description.
*/
#include<iostream>
using namespace std;
#include <vector>
#include <string>

int main()
{
	int n,m;
	int mod = 1e9+7;
	cin>>n>>m;

	vector<int>arr(n);
	for(int i = 0;i<n;i++)
		cin>>arr[i];
	vector<vector<int>>dp(n,vector<int>(m+2,0));

	if(arr[0] == 0)
	{
		for(int i = 1;i<=m;i++)
			dp[0][i] = 1;
	}
	else
		dp[0][arr[0]] = 1;

	for(int i = 1;i<n;i++)
	{
		if(arr[i]!=0)
		{
			int j = arr[i];
			dp[i][j] = ((dp[i-1][j] + dp[i-1][j-1])%mod + dp[i-1][j+1])%mod;
		}
		else
		{
			for(int j=1;j<=m;j++)
				dp[i][j] = ((dp[i-1][j] + dp[i-1][j-1])%mod + dp[i-1][j+1])%mod;
		}
	}

    int res = 0;
	for(int j=1;j<=m;j++)
		res = (res+dp[n-1][j])%mod;
	
	cout<<res;
}



