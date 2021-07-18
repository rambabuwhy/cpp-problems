/*
There are a total of n courses you have to take, labeled from 0 to n-1.

Some courses may have prerequisites, for example to take course 0 you have to first take course 1, which is expressed as a pair: [0,1]

Given the total number of courses and a list of prerequisite pairs, return the ordering of courses you should take to finish all courses.

There may be multiple correct orders, you just need to return one of them. If it is impossible to finish all courses, return an empty array.

*/

class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& edges) {
        
        //Initialize graph, indegree and  result vector
        vector<vector<int>> graph(numCourses);
        vector<int> indegree(numCourses + 1, 0);
        
        //build graph for edge 1->0
        //[0, 1]: indicates take course 0 you have to first take course 1
        for(auto edge : edges) {
            graph[edge[1]].push_back(edge[0]);
            indegree[edge[0]]++;
        }

        //push all indegree == 0;
        queue<int> Q;
        for(int i = 0; i<numCourses; i++){
            if(indegree[i]==0) Q.push(i);
        }
        
        vector<int> result;
        while(!Q.empty()){
           
            //remove node of indegree 0
            int curr = Q.front();
            result.push_back(curr);
            Q.pop();
            
            //decrement indegree of its children
            for(auto child: graph[curr]) {
                indegree[child]--;
                if(indegree[child]==0) Q.push(child);
            }
        }
        
        if(result.size() == numCourses) return result;
        return vector<int>();
    }
};
