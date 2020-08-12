/*
Given a non-negative index k where k ≤ 33, return the kth index row of the Pascal's triangle.

Note that the row index starts from 0.


In Pascal's triangle, each number is the sum of the two numbers directly above it.

Example:

Input: 3
Output: [1,3,3,1]
Follow up:

Could you optimize your algorithm to use only O(k) extra space?

*/

class Solution {
public:
    vector<int> getRow(int rowIndex) {
        
        if(rowIndex == 0) return vector<int>({1});
        if(rowIndex == 1) return vector<int>({1,1});
       
        vector<vector<int>> dp(rowIndex+1,vector<int>(rowIndex+1,0));
      
        dp[0][0]=1;
        dp[1][0]=1;
        dp[1][1]=1;
        
        for(int i = 2; i <= rowIndex; i++){
            dp[i][0] = dp[i][rowIndex] = 1;
            for(int j = 1; j<=rowIndex; j++){
              
                dp[i][j] = dp[i-1][j-1] + dp[i-1][j];
            
            }
        }
        
    
        vector<int> result;
        for(int i = 0; i<=rowIndex; i++){
            result.push_back(dp[rowIndex][i]);
        }
        
        return result;
        
    }
};
