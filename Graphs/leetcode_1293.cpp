/*
Problem: Shortest Path in a Grid with Obstacles Elimination
You are given an m x n integer matrix grid where each cell is either 0 (empty) or 1 (obstacle).
You can move up, down, left, or right from and to an empty cell in one step.
Return the minimum number of steps to walk from the upper left corner (0, 0) to the lower right corner (m - 1, n - 1)
given that you can eliminate at most k obstacles. If it is not possible to find such walk return -1.


Approach:
If the obstacle removal was not there, this is a standard bfs from (0,0).
Now since we can remove some obstacles, we will have to keep track of how many obstacles
we can still remove at a given point.
So,along with the grid coordinates, we also store the obstacles we can remove at that point.
We can use a visited array which stores the number of obstacles that can be removed at x,y.
We start from (0,0,k)
As we add nodes, we check if the number of obstacles currently present at vis[x][y] are lesser,
if they are lesser we update and push this into the queue.
Similar to dfs we return the steps once we reach the end.

TC: O(V+E)
V: m*n*k - These many states which go into the queue and are popped only once
E: m*n*k*4

TC ~ O(m*n*k)

*/
class Solution {
public:
    int shortestPath(vector<vector<int>>& grid, int k) {
        int n = grid.size();
        int m = grid[0].size();
        int dir[5] = {-1,0,1,0,-1};
        queue<pair<int,pair<int,int>>>q;
        vector<vector<int>>vis(n,vector<int>(m,-1e9));

        q.push({k,{0,0}});
        vis[0][0] = k;
        int count = 0;

        while(!q.empty())
        {
            
            int p = q.size();
            while(p--)
            {
                auto it = q.front();
                q.pop();
                int ob = it.first;
                int x = it.second.first;
                int y = it.second.second;
                if(x == n-1 && y== m-1)
                    return count;
                for(int i=0;i<4;i++)
                {
                    int x_c = x + dir[i];
                    int y_c = y + dir[i+1];

                    if(x_c >=0&&x_c<n && y_c>=0 && y_c<m)
                    {
                        
                        int val = ob;
                        if( grid[x_c][y_c] == 1)
                            val--;
                        if(val <0)
                            continue;
                        if(vis[x_c][y_c] < val)
                        {
                            vis[x_c][y_c] = val;
                            q.push({val,{x_c,y_c}});
                        }


                    }
                }

            }
            count++;
            

        }
        return -1;
        
    }
};
