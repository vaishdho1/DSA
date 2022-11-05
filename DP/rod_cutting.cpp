/*
Partition dp
Given a rod of length n which can be cut at different points at a distance of 1 unit from.
Given a cuts array, which gives locations at which cuts can be made.
The cost of cutting the rod at a given point is equal to the length of the rod at the point when the
cut is performed.
Find the minimum cost with all the cuts performed.

Approach:
As the rod could be of very large length, just knowing the points where the cuts are performed is enough for us
to find the cost.(As the cuts are same as the different locations of the rod)
1) Sort the cuts array and push the value of 0 in the front and n behind.
   These values can be used to find the length of the rod when the first cut is performed.
   Ex: If the rod is from 0 to 12 and the cuts array = [1,4,5,7] inserting the values, [0,1,4,5,7,12] wherever the first cut is perfomed,
   the cost incurred is equal to 12(the length of the original rod).At every subproblem when the length
   reduces, the length can be found out by knowing the last cut point to the right and the last cut point to the left.
   i.e if start and end are the current partition's end points,cuts[j+1] - cuts[i-1] will give the length of the rod.
 2) Find the cost by going through all the possible cuts which lie in the given range of the partition and store the min.
 3)Return the min calculated to the larger problem.
 
 For bottom up dp:
 1) We build the dp array from i = c-2 to 1 and j from i to c-2 where c is the size of the modified cuts array.
 2) We finally return dp[1][c-2]
 
 
 Complexity:
 TC: O(n^3) : 2 main loops and one loop throught he range
 SC: O(n^2) : To hold the dp array.
*/

int min_cut(int start, int end, vector<int> &cuts,vector<vector<int>>&dp)
    {
        if(start > end)
            return 0;
        if(dp[start][end] != -1)
            return dp[start][end];
        int min_val = 1e9;
        for(int i=start;i<=end;i++)
        {
            int steps = min_cut(start,i-1,cuts,dp) + min_cut(i+1,end,cuts,dp) + cuts[end+1] - cuts[start-1];
            if(steps < min_val)
                min_val = steps;
        }
        return dp[start][end] = min_val;
    }
    int minCost(int n, vector<int>& cuts) {
        cuts.insert(cuts.begin(),0);
        cuts.push_back(n);
        sort(cuts.begin(),cuts.end());
        int c = cuts.size();
        vector<vector<int>>dp(c,vector<int>(c,0));
        //return min_cut(1,c-2,cuts,dp); //Call this for recursive dp

        for(int i=c-2;i>=1;i--)
        {
            for(int j = i;j<=c-2;j++)
            {
                int min_val = 1e9;
                for(int k=i;k<=j;k++)
                {
                    int steps = dp[i][k-1] + dp[k+1][j] + cuts[j+1] - cuts[i-1];
                    if(steps < min_val)
                        min_val = steps;
                }

                dp[i][j] = min_val;
                
            }
        }

        return dp[1][c-2];
