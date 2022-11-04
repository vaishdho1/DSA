/*
The minimum number of deletions to make 2 strings equal.
1)Find the length of the longest common subsequence.
2)The additional elements from each string need to be deleted,
to get the longest string.

TC:O(n^2)
SC:O(n)
*/

int minDistance(string word1, string word2) {

        int n = word1.size();
        int m = word2.size();

        vector<int>dp(m+1, 0);

        for(int i = 1; i <= n; i++)
        {
            vector<int>cur(m+1, 0);
            for(int j = 1; j <=m ; j++)
            {
                if(word1[i-1] == word2[j-1])
                    cur[j] = 1 + dp[j-1];
                else
                    cur[j] = max(dp[j], cur[j-1]);
            }
            dp = cur;
        }

        return (n - dp[m]) + (m - dp[m]);
        
    }
