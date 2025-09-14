// There are n cities and m edges connected by some number of flights. Given an array of flights where flights[i] = [ fromi, toi, pricei] indicates that there is a flight from city fromi to city toi with cost pricei. Given three integers src, dst, and k, and return the cheapest price from src to dst with at most k stops. If there is no such route, return -1.

class Solution{
public:
    int CheapestFlight(int n, vector<vector<int>> &flights,
                       int src, int dst, int K) {
        unordered_map<int,vector<pair<int,int>>>adj;
        for(int i=0;i<flights.size();i++){
            int u = flights[i][0];
            int v = flights[i][1];
            int p = flights[i][2];
            adj[u].push_back({v,p});
        }
        queue<pair<int,pair<int,int>>>s;
        vector<int>dist(n,INT_MAX);
        dist[src]=0;
        s.push({0,{src,0}});
        while(!s.empty()){
            auto fNode = s.front();
            s.pop();
            int d = fNode.first;
            int node = fNode.second.first;
            int stops = fNode.second.second;
            if(stops>K)continue;
            // if(node==dst && stops<=k)return d;
            for(auto i: adj[node]){
                if(dist[i.first]>d+i.second){
                    dist[i.first] = d+i.second;
                    s.push({dist[i.first],{i.first,stops+1}});
                }
            }
        }
        if(dist[dst]!=INT_MAX){
            return dist[dst];
        }
        return -1;
    }
};
