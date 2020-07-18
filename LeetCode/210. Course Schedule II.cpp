/*
There are a total of n courses you have to take, labeled from 0 to n-1.

Some courses may have prerequisites, for example to take course 0 you have to first take course 1, which is expressed as a pair: [0,1]

Given the total number of courses and a list of prerequisite pairs, return the ordering of courses you should take to finish all courses.

There may be multiple correct orders, you just need to return one of them. If it is impossible to finish all courses, return an empty array.

*/

class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        
        //Initialize grapph, indegree and  result vector
        vector<int> indegree(numCourses+1,0);
        vector<vector<int> > graph(numCourses);
        vector<int> result;
        
        //build graph
        for(int i = 0; i < prerequisites.size(); i++){
            graph[prerequisites[i][1]].push_back(prerequisites[i][0]);
            indegree[prerequisites[i][0]]++;
            
        }
     

        //BFS start
        
        queue<int> Q;
        
        //push  all indegree == 0;
        for(int i = 0;  i < numCourses;  i++){
            if(indegree[i]==0){
                Q.push(i);
            }
        }
        
        while(!Q.empty()){
           
            int curr = Q.front();
            
            result.push_back(curr);
            Q.pop();
            
            for(auto child: graph[curr]) {
                
                indegree[child]--;
                if(indegree[child]==0) {
                    Q.push(child);
                }
             
            }
        }
        
        if(result.size() == numCourses){
            return result;
        }
        return vector<int>();
    }
};
