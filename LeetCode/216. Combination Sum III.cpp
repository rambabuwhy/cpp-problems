/*
Find all valid combinations of k numbers that sum up to n such that the following conditions are true:

Only numbers 1 through 9 are used.
Each number is used at most once.
Return a list of all possible valid combinations. The list must not contain the same combination twice, and the combinations may be returned in any order.

 

Example 1:

Input: k = 3, n = 7
Output: [[1,2,4]]
Explanation:
1 + 2 + 4 = 7
There are no other valid combinations.
Example 2:

Input: k = 3, n = 9
Output: [[1,2,6],[1,3,5],[2,3,4]]
Explanation:
1 + 2 + 6 = 9
1 + 3 + 5 = 9
2 + 3 + 4 = 9
There are no other valid combinations.
Example 3:

Input: k = 4, n = 1
Output: []
Explanation: There are no valid combinations. [1,2,1] is not valid because 1 is used twice.
Example 4:

Input: k = 3, n = 2
Output: []
Explanation: There are no valid combinations.
Example 5:

Input: k = 9, n = 45
Output: [[1,2,3,4,5,6,7,8,9]]
Explanation:
1 + 2 + 3 + 4 + 5 + 6 + 7 + 8 + 9 = 45
​​​​​​​There are no other valid combinations.

*/

class Solution {
public:
    vector<vector<int>> combinationSum3(int k, int n) {
        
        vector<vector<int>> result;
        vector<int> curr;
        backTrack(k, n, 1, result, curr);
        return result;
        
    }
    
    void backTrack(int set_size, int target, int index, vector<vector<int>> &result, vector<int> &curr){
        
        if(target == 0 && curr.size() == set_size){
            result.push_back(curr);
        }
        else if( target < 0 || curr.size() == set_size){
            return;
        }
        
        for(int i=index; i<=9; i++){
            curr.push_back(i);
            backTrack(set_size, target-i, i+1, result, curr);
            curr.pop_back();
        } 
        
    }
};
