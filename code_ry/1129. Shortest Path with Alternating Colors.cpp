/*

Author: Rambabu Yerajana
linkedin: https://www.linkedin.com/in/rambabuyerajana/
medium: https://rambabuy.medium.com/
problem: Shortest Path with Alternating Colors

------------------------------------------------------------------
Description:
You are given an integer n, the number of nodes in a directed graph where the nodes are labeled from 0 to n - 1. Each edge is red or blue in this graph, and there could be self-edges and parallel edges.

You are given two arrays redEdges and blueEdges where:

redEdges[i] = [ai, bi] indicates that there is a directed red edge from node ai to node bi in the graph, and
blueEdges[j] = [uj, vj] indicates that there is a directed blue edge from node uj to node vj in the graph.
Return an array answer of length n, where each answer[x] is the length of the shortest path from node 0 to node x such that the edge colors alternate along the path, or -1 if such a path does not exist.

 

Example 1:

Input: n = 3, redEdges = [[0,1],[1,2]], blueEdges = []
Output: [0,1,-1]
Example 2:

Input: n = 3, redEdges = [[0,1]], blueEdges = [[2,1]]
Output: [0,1,-1]
-------------------------------------------------
Solution:

This solution uses the BFS algorithm to traverse the graph and find the shortest alternating path from node 0 to every other node in the graph. 
The BFS algorithm uses a queue to store the next node to be processed and uses a 2D boolean array to keep track of which nodes have been visited with each color.
The solution starts by initializing the answer array with -1 for all nodes, meaning that a path does not exist yet. 
Then, the BFS algorithm is performed by first pushing the starting node 0 with number of steps as 0 and the previous color as -1 (meaning undefined color) into the queue. The BFS algorithm continues until the queue is empty.
For each node, the algorithm checks all of its neighbors with a different color from the previous edge and updates the answer array with the new shortest distance if it is not yet updated.
------------------------------------------------



*/



class Solution {
public:
    vector<int> shortestAlternatingPaths(int n, vector<vector<int>>& redEdges,
                                         vector<vector<int>>& blueEdges) {
        vector<vector<pair<int, int>>> adj(n);  // Adjacency list to store the graph

        // Add the red edges to the adjacency list
        for (auto& redEdge : redEdges) {
            adj[redEdge[0]].push_back({redEdge[1], 0});
        }

        // Add the blue edges to the adjacency list
        for (auto& blueEdge : blueEdges) {
            adj[blueEdge[0]].push_back({blueEdge[1], 1});
        }

        vector<int> answer(n, -1);  // Initialize the answer array with -1 for all nodes
        vector<vector<bool>> visit(n, vector<bool>(2));  // Keep track of which nodes have been visited with each color
        queue<vector<int>> q;  // Queue to store the nodes to be processed in BFS

        // Start with node 0, with number of steps as 0 and undefined color -1.
        q.push({0, 0, -1});
        visit[0][1] = visit[0][0] = true;  // Mark node 0 as visited with both colors
        answer[0] = 0;  // The starting node is 0 steps away from itself

        // Continue until the queue is empty
        while (!q.empty()) {
            auto element = q.front();
            int node = element[0], steps = element[1], prevColor = element[2];
            q.pop();

            // Check all neighbors of the current node
            for (auto& [neighbor, color] : adj[node]) {
                // If the neighbor has not been visited with this color and the color is different from the previous edge
                if (!visit[neighbor][color] && color != prevColor) {
                    visit[neighbor][color] = true;  // Mark the neighbor as visited with this color
                    q.push({neighbor, 1 + steps, color});  // Push the neighbor into the queue for processing
                    if (answer[neighbor] == -1) answer[neighbor] = 1 + steps;  // Update the answer array if it is not yet updated
                }
            }
        }
        return answer;
    }
};
