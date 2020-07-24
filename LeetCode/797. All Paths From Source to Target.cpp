/*Given a directed, acyclic graph of N nodes.  Find all possible paths from node 0 to node N-1, and return them in any order.

The graph is given as follows:  the nodes are 0, 1, ..., graph.length - 1.  graph[i] is a list of all nodes j for which the edge (i, j) exists.

*/

class Solution {
public:
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        
        vector<vector<int>> result;
        vector<int> path;
        path.push_back(0);
        dfs(graph,0,result,path);
        return result;
    }
    
    void dfs(vector<vector<int>> & graph, 
             int index, 
             vector<vector<int>> & result,
             vector<int> &path)  {
        
        if(index == graph.size()-1){
            result.push_back(path);
        }
        
        for(int child: graph[index]){
            path.push_back(child);
            dfs(graph,child,result,path);
            path.pop_back();
        }
    }
};
