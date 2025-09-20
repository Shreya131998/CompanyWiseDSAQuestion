class Solution{
public:
    bool solve(int src,vector<int> adj[],vector<int>&color, int clr){
        color[src]=clr;
        for(auto i: adj[src]){
            if(color[i]==-1){
                bool ans = solve(i,adj,color,!clr);
                if(!ans)return false;
            }
            else{
                if(color[i]==clr)return false;
            }
        }
        return true;
    }
    bool isBipartite(int V, vector<int> adj[])  {
        vector<int>color(V,-1);
        for(int i=0;i<V;i++){
            if(color[i]==-1){
                bool ans = solve(i,adj,color,0);
                if(!ans)return false;
            }
        }
        return true;
    }
};
