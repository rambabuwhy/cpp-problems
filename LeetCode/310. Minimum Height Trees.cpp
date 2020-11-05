/*

A tree is an undirected graph in which any two vertices are connected by exactly one path. In other words, any connected graph without simple cycles is a tree.

Given a tree of n nodes labelled from 0 to n - 1, and an array of n - 1 edges where edges[i] = [ai, bi] indicates that there is an undirected edge between the two nodes ai and bi in the tree, you can choose any node of the tree as the root. When you select a node x as the root, the result tree has height h. Among all possible rooted trees, those with minimum height (i.e. min(h))  are called minimum height trees (MHTs).

Return a list of all MHTs' root labels. You can return the answer in any order.

The height of a rooted tree is the number of edges on the longest downward path between the root and a leaf.

*/

 class Solution {
public:
    vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges) {
        
        //Base Case
        vector<int> result;
        if (n == 1) {
          result.push_back(0);
          return result;
        }
      
        //build graph
        vector<unordered_set<int>> adj(n);
        for (auto p : edges) {
          adj[p[0]].insert(p[1]);
          adj[p[1]].insert(p[0]);
        }
      
        //push all node which has degree 1 ; means leaf nodes
        for (int i = 0; i < adj.size(); ++i) {
          if (adj[i].size() == 1) {
            result.push_back(i);
          }
        }
        
        
        //1.BFS 2.remove leafs/ degree 1  2. return root nodes
        while (!result.empty()) {
          vector<int> curr;
          for (int node : result) {
            for (int neighbor : adj[node]) {
              adj[neighbor].erase(node);
              if (adj[neighbor].size() == 1) curr.push_back(neighbor);
            }
          }
          if (curr.empty()) return result;
          result = curr;
        }
        
        return result;
        
     }
};
