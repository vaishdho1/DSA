/*
Minimum Cost to Make at Least One Valid Path in a Grid

Approach:
Since the egge weights can either be 0 or 1,
we can use 0-1 BFS.
Here at a point of time the queue can only contain weights of y and y+1.
So, we can use a double ended queue which stores y in the front and y+1 at the back.
Towards the end we get the least cost to reach the end.


TC: O(V+E)
V: n*m
E:4*n*m
*/
class Solution {
public:
    
    int minCost(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<int>>vis(n,vector<int>(m,1e9));
        deque<pair<int,pair<int,int>>>dq;
        int x_dir[4] = {0,0,1,-1};
        int y_dir[4] = {1,-1,0,0};

        dq.push_front({0,{0,0}});
        vis[0][0] = 0;

        while(!dq.empty())
        {
            auto it = dq.front();
            dq.pop_front();
            int c = it.first;
            int x = it.second.first;
            int y = it.second.second;
            if(x == n-1 && y==m-1)
                return c;
            for(int i=0;i<4;i++)
            {
                int x_c = x + x_dir[i];
                int y_c = y + y_dir[i];
                if(x_c >=0 && x_c <n && y_c>=0 && y_c<m)
                {
                    int val = c;
                
                    if(grid[x][y] != i+1)
                        val++;
                    if(vis[x_c][y_c] > val)
                    {
                        vis[x_c][y_c] = val;
                        if(val == c)
                            dq.push_front({val,{x_c,y_c}});
                        else
                            dq.push_back({val,{x_c,y_c}});
                    }
                }

            }            
        }
        return -1;      
    }
};
