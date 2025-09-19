// There are n cities labeled from 1 to n, and edges[i] = [u, v, cost] represents a bidirectional road between city u and city v with a construction cost of cost. Your task is to find the minimum cost to connect all the cities such that every city is reachable from any other city.

// Return the minimum cost to connect all the cities. If it is impossible to connect all cities, return -1.


// Examples:
// Input: n = 3, edges = [[1,2,5],[1,3,6],[2,3,1]]

// Output: 6

// Explanation: The minimum spanning tree consists of edges [2,3,1] and [1,2,5], with a total cost of 6.

class Solution {
public:
    int findParent(vector<int>&parent, int u){
        if(parent[u]==u)return u;
        return parent[u] = findParent(parent,parent[u]);
    }
    void findRank(int u, int v,vector<int>&parent,vector<int>&rank){
        u = findParent(parent,u);
        v = findParent(parent,v);
        if(rank[u]<rank[v]){
            rank[v]++;
            parent[u]=v;
        }
        else{
            rank[u]++;
            parent[v]=u;
        }
    }
    int minimumCost(int n, vector<vector<int>>& connections) {
        // Your Code Goes Here
        priority_queue<pair<int,pair<int,int>>, vector<pair<int,pair<int,int>>>, greater<pair<int,pair<int,int>>>>s;
        for(int i=0;i<connections.size();i++){
            int u = connections[i][0];
            int v = connections[i][1];
            int wt = connections[i][2];
            s.push({wt,{u,v}});
        }
        vector<int>rank(n+1,0);
        vector<int>parent(n+1,0);
        for(int i=0;i<=n;i++){
            parent[i]=i;
        }
        int sum =0;
        while(!s.empty()){
            auto fNode = s.top();
            s.pop();
            int wt = fNode.first;
            int u = fNode.second.first;
            int v = fNode.second.second;
            u = findParent(parent,u);
            v = findParent(parent,v);
            if(u!=v){
                sum+=wt;
                findRank(u,v,parent,rank);
            }
        }
        int c=0;
        for(int i=1;i<=n;i++){
            if(parent[i]==i){
                c++;
            }
        }
        if(c>1)return -1;
        return sum;

    }
};