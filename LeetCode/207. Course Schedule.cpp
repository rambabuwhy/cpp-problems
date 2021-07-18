/*

There are a total of numCourses courses you have to take, labeled from 0 to numCourses - 1. You are given an array prerequisites where prerequisites[i] = [ai, bi] indicates that you must take course bi first if you want to take course ai.

For example, the pair [0, 1], indicates that to take course 0 you have to first take course 1.
Return true if you can finish all courses. Otherwise, return false.

 

Example 1:

Input: numCourses = 2, prerequisites = [[1,0]]
Output: true
Explanation: There are a total of 2 courses to take. 
To take course 1 you should have finished course 0. So it is possible.
Example 2:

Input: numCourses = 2, prerequisites = [[1,0],[0,1]]
Output: false
Explanation: There are a total of 2 courses to take. 
To take course 1 you should have finished course 0, and to take course 0 you should also have finished course 1. So it is impossible.

*/

class Solution {
public:
    bool iscycle(vector<vector<int>> &adj, vector<int> &visited, int node){
        
        if(visited[node] == 1) return true;
        
        if(visited[node] == 0) {
            visited[node] = 1;
            for(auto edge : adj[node]) {
                if(iscycle(adj, visited, edge)) return true;
            }
        }
        visited[node] = 2;
        return false;
    }
    
    bool canFinish(int n, vector<vector<int>>& edges) {
        //build graph
        vector<vector<int>> adj(n);
        for(auto edge : edges) {
            adj[edge[1]].push_back(edge[0]);
        }
            
        //call  dfs 
        vector<int> visited(n, 0);
        for(int i=0; i<n; i++){
            if(visited[i] == 0 && iscycle(adj, visited, i)) return false;
        }
        return true;
    }
};
