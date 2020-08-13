/*
Given two integers n and k, return all possible combinations of k numbers out of 1 ... n.

Example:

Input: n = 4, k = 2
Output:
[
  [2,4],
  [3,4],
  [2,3],
  [1,2],
  [1,3],
  [1,4],
]
*/

class Solution {
public:
    vector<vector<int>> combine(int n, int k) {
        
        vector<vector<int>> result;
        vector<int> curr;
        util(1,k,n,result,curr);
        return result;
        
    }
    
    void util(int first,
              int k,
              int n,
              vector<vector<int>> &result,
              vector<int> &curr){
        
        if(curr.size() == k){
            result.push_back(curr);
        }
        
        for(int i = first; i < n+1; i++){
            curr.push_back(i);
            util(i+1,k,n,result,curr);
            curr.pop_back();
        }

        
    }
};
