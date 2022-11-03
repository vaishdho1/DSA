#include <iostream>
#include<vector>
#include<algorithm>
using namespace std;
/* Variant of LIS.TC:O(n^2) SC:O(n) */

bool comp(vector<int>&a,vector<int>&b)
{
    if(a[0] == b[0])
        return a[1]<b[1];
    return a[0]<b[0];
}

int max_overlap(vector<vector<int>>&co_ord)
{
    int n = co_ord.size();
    sort(co_ord.begin(),co_ord.end(),comp);
    vector<int>dp(n,1);
    int max_len = 0;
    for(int i = 0;i<n;i++)
    {
        for(int j=0;j<i;j++)
        {
            if(co_ord[i][1] > co_ord[j][1] && dp[i]<dp[j]+1)
                dp[i] = dp[j] + 1;
        }
        max_len = max(max_len,dp[i]);
    }
    
    return max_len;
}
int main() {
    
    vector<vector<int>>co_ord;
    int n;
    cin>>n;
    for(int i=0;i<n;i++)
    {
        vector<int>row;
        for(int j=0;j<2;j++)
        {
            int temp;
            cin>>temp;
            row.push_back(temp);
        }
        co_ord.push_back(row);
    }
    cout<<max_overlap(co_ord);
}
        
