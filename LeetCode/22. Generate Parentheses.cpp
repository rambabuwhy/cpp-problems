/*
Given n pairs of parentheses, write a function to generate all combinations of well-formed parentheses.

 

Example 1:

Input: n = 3
Output: ["((()))","(()())","(())()","()(())","()()()"]
Example 2:

Input: n = 1
Output: ["()"]

*/

class Solution {
public:
    vector<string> generateParenthesis(int n) {
        
        vector<string> result;
        util(result, "", 0 ,0, n);
        return result;
    }
    
    //take open/close parenthesis count
    void util (vector<string> &result, string curr, int open, int close, int n){
        
        if(curr.size() == 2*n){
            result.push_back(curr);
            return;
        }
        
        //include open parenthesis; increment open count
        if(open < n)        util(result, curr+"(", open+1, close, n);
        
        //include close parenthesis; increment close count
        if(close < open)    util(result, curr+")", open, close+1, n); 
        
    }
};
