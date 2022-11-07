/*
Idea:Front partition
Given an array and a value k, find the max sum possible such that subarray with 
at most k numbers can be in a partition.
eg: [1,3,4,5,6] k= 3
    valid partitons
    [1,3] [4,5,6] 
    [1,3,4][5,6]
    invalid partitons:
    [1][3,4,5,6] - More than 3 elements in a single partition
Approach:

Front partition approach : Here we partition from the front.(Top down)
1) f(ind) is the max sum from ind to n.
2) Go through each index and perform a partiton where it is possible from ind to n say(k)
  and solve the partition from f(k+1).
3) Here the possible split indices are either explicitly given(in this problem) or should be
   computed(palindorme partitioning).

Bottom up:

Here go through each index from ind to ind+k and find the max value possible at index ind with
the various splits at each of the indices.
Go in bottom up fashion by solving from n-1 to 0
dp[0]is the answer.

TC:O(n^2)
SC:O(n)
*/




int max_sum(int ind, vector<int> &arr,int n,int k,vector<int>&dp)
    {
        
        if(ind == n)
            return 0;
        if(dp[ind]!=-1)
            return dp[ind];
        
        int max_val = arr[ind];
        int max_ans = 0;
        for(int i=ind;i<min(ind+k,n);i++)
        {
            max_val = max(max_val,arr[i]);
            int val = (i-ind+1)*max_val + max_sum(i+1,arr,n,k,dp);
            max_ans = max(val,max_ans);
        }
        

        return dp[ind] = max_ans;
        
    }
    int maxSumAfterPartitioning(vector<int>& arr, int k) {

        int n = arr.size();
        vector<int>dp(n+1,0);

        //return max_sum(0,arr,n,k,dp);

        for(int i = n-1;i>=0;i--)
        {
            int max_val = arr[i];
            int max_sum = 0;
            for(int j = i;j<min(n,i+k);j++)
            {
                max_val = max(max_val,arr[j]);
                int val = (j-i+1)*max_val + dp[j+1];
                max_sum = max(max_sum,val); 
            }
            dp[i] = max_sum;
        }

        return dp[0];
        
    }
