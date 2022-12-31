/*
Problem:Minimum cost to reach cities with discount

A series of highways connect n cities numbered from 0 to n - 1.
You are given a 2D integer array highways where highways[i] = [city1i, city2i, tolli] indicates that there is a highway that connects city1i and city2i, allowing a car to go from city1i to city2i and vice versa for a cost of tolli.
You are also given an integer discounts which represents the number of discounts you have. 
You can use a discount to travel across the ith highway for a cost of tolli / 2 (integer division).
Each discount may only be used once, and you can only use at most one discount per highway.
Return the minimum total cost to go from city 0 to city n - 1, or -1 if it is not possible to go from city 0 to city n - 1.


Approach:
If there were no discounts,this is a classical problem of finding the shortest path from source to destination.
Due to the discount available, we have to options at every node whether to take the discount or not.
For this we need to know how many discounts are still available for the current node.
So, along with the distance and the node we will also store the number of discounts available in the priority queue.
Similar to Dijkstra, we can have a dis matrix where dis[k][i] - the shortest distance from 0 to i with k discounts left.
We will have 2 options at every node:
1) Add discount.
If we add the discount the adjacent node will have k-1 discounts left,so we check if the distance
for that state decreases with the new addition
if(k>0 && dis[k-1][adjNode] > curdis + wt/2)
  then add
2)Dont add discount
If the adjNode with k discounts left ,we check if the distance for this state decreases
  if(dis[k][adjNode] > curdis + wt)
    then add
 
 When we encounter n-1th node we return the distance
 
 TC:
 This is similar to Dijkstra Elog(V)
 V: the number of states = n*(k+1)
 E: (k+1)*E
 
 SC: n*k - Using a distance matrix
           and a queue
*/



#include <iostream>
#include<string>
#include<algorithm>
#include<queue>

using namespace std;
int minCost(vector<vector<int>>&highways,int n,int k)
{
    vector<vector<pair<int,int>>>graph(n);
    
    for(auto it:highways)
    {
        graph[it[0]].push_back({it[1],it[2]});
        graph[it[1]].push_back({it[0],it[2]});
    }
    //
    // dis[k][i] - Minimum distance from 0 to i with k discounts remaining
    vector<vector<int>>dis(k+1,vector<int>(n,1e9));
    priority_queue<pair<int,pair<int,int>>,vector<pair<int,pair<int,int>>>,greater<pair<int,pair<int,int>>>>pq;
    //dis,remain,node
    pq.push({0,{k,0}});
    for(int i=0;i<=k;i++)
        dis[i][0] = 0;
    
    while(!pq.empty())
    {
        auto it = pq.top();
        pq.pop();
        int curDis = it.first;
        int disc = it.second.first;
        int node = it.second.second;
        if(node == n-1)
            return curDis;
        
        for(auto it:graph[node])
        {
            int adjNode = it.first;
            int wt = it.second;
            //Apply discount
          
            if(disc > 0 && dis[disc-1][adjNode] > curDis + wt/2)
             {
                 dis[disc-1][adjNode] = curDis + wt/2;
                 pq.push({curDis + wt/2,{disc-1,adjNode}});
             }
           
            //No discount
            if(dis[disc][adjNode] > curDis + wt)
            {
                dis[disc][adjNode] = curDis + wt;
                pq.push({curDis + wt,{disc,adjNode}});
                
            }
            
        }
    }
    return -1;
    
    
    
}
int main()
{
    int n,m,discounts;
    cin>>n>>m>>discounts;
   
    vector<vector<int>>highways;
    
    for(int i=0;i<m;i++)
    {
        vector<int>res(3);
        for(int k=0;k<3;k++)
            cin>>res[k];
        highways.push_back(res);
    }
    
    cout<<minCost(highways,n,discounts)<<endl;
}
