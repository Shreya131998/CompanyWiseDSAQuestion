// You have a graph of n nodes labeled from 0 to n - 1. You are given an integer n and a list of edges where edges[i] = [ai, bi] indicates that there is an undirected edge between nodes ai and bi in the graph.

// Return true if the edges of the given graph make up a valid tree, and false otherwise.


class Solution {
public:
    bool validTree(int n, vector<vector<int>>& edges) {
        // Your code goes here
        vector<vector<int>> adjList(n);
        for (const auto& edge : edges) {
            adjList[edge[0]].push_back(edge[1]);
            adjList[edge[1]].push_back(edge[0]);
        }
        unordered_map<int, int> parentMap;
        parentMap[0] = -1;
        queue<int> bfsQueue;
        bfsQueue.push(0);

        // Perform BFS to explore the graph
        while (!bfsQueue.empty()) {
            // Get the current node from the queue
            int node = bfsQueue.front();
            bfsQueue.pop();

            // Explore all neighbors of the current node
            for (int neighbor : adjList[node]) {
                /* Skip if the neighbor is the
                parent of the current node */
                if (parentMap[node] == neighbor) {
                    continue;
                }
                /* If neighbor is already visited and
                not the parent, a cycle exists */
                if (parentMap.find(neighbor) != parentMap.end()) {
                    return false;  
                }
                /* Add the neighbor to the queue 
                and mark its parent */
                bfsQueue.push(neighbor);
                parentMap[neighbor] = node;
            }
        }

        // Check if all nodes are visited 
        return parentMap.size() == n;
    }
};