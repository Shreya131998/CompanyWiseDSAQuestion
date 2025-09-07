// You have a graph of n nodes. You are given an integer n and an array edges where edges[i] = [ai, bi] indicates that there is an edge between ai and bi in the graph.

// Return the number of connected components in the graph.




class Solution {
public:
    void solve(int src,unordered_map<int,vector<int>>&adj,unordered_map<int,int>&vis){
        vis[src]=1;
        for(auto i: adj[src]){
            if(!vis[i]){
                solve(i,adj,vis);
            }
        }
    }
    int countComponents(int n, vector<vector<int>>& edges) {
        // Your code goes here
        unordered_map<int,int>vis;
        unordered_map<int,vector<int>>adj;
        for(int i=0;i<edges.size();i++){
            int u = edges[i][0];
            int v = edges[i][1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        int c=0;
        for(int i=0;i<n;i++){
            if(!vis[i]){
                c++;
                solve(i,adj,vis);
            }
        }
        return c;
    }
};