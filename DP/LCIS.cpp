/*
LCIS : Variant of LIS
Find the longest common increasing subsequence between2 integer arrays.

Approach:
1) For each element in the first array,
2)Go through the second array and check if the value at any
index is less than the current value and the LCIS ending at that index
is greater than the current value.
Keep updating current value.When at an index, arr1 and arr2 have same values,
update the LCIS ending at this value.

Complexity:

TC: O(n^2)
SC: O(n)

*/

#include <iostream>
#include<vector>
#include<algorithm>
using namespace std;


void long_comm_incr(vector<int> &arr1 ,vector<int> &arr2)
{
    int n = arr1.size();
    int m = arr2.size();
    int maxi = 0;
    vector<int>dp(m);
    vector<int>par(m);
    for(int i=0;i<m;i++)
        par[i] = i;

    for(int i=0;i<n;i++)
    {
        int cur = 0;
        int prev = -1;
        for(int j=0;j<m;j++)
        {
            if(arr1[i] == arr2[j] && dp[j] < cur + 1)
            {
                dp[j] = cur + 1;
                par[j] = prev == -1 ? j : prev;
            }
            if(arr1[i] > arr2[j] && dp[j] > cur)
            {
                cur = dp[j];
                prev = j;
            }
        }
    }
    
    vector<int>res;
    int ind;
    for(int i=0;i<m;i++)
    {
        if(dp[i] > maxi)
        {
            maxi = dp[i];
            ind = i;
        }
    }
    while(par[ind] != ind)
    {
        res.push_back(arr2[ind]);
        ind = par[ind];
    }
    res.push_back(arr2[ind]);
    
    cout<<maxi<<endl;
    for(int i = maxi-1;i>=0;i--)
        cout<<res[i]<<" ";
    cout<<endl;
    
}
int main() {
    
    int n,m;
    cin>>n;
    vector<int>arr1(n);
    for(int i=0; i<n; i++)
    cin>>arr1[i];
    cin>>m;
    vector<int>arr2(m);
    for(int i =0; i<m; i++)
    cin>>arr2[i];
    long_comm_incr(arr1,arr2);
    
}
        
