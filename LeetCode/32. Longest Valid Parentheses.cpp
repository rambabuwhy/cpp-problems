/*
Given a string containing just the characters '(' and ')', find the length of the longest valid (well-formed) parentheses substring.

 

Example 1:

Input: s = "(()"
Output: 2
Explanation: The longest valid parentheses substring is "()".
Example 2:

Input: s = ")()())"
Output: 4
Explanation: The longest valid parentheses substring is "()()".
Example 3:

Input: s = ""
Output: 0
*/


class Solution {
public:
    int longestValidParentheses(string s) {
        
        int result = 0;
        stack<int> lstk;
        
        //push -1
        lstk.push(-1);
        for(int i=0; i<s.size(); i++){
            
            if(s[i] == '('){
                lstk.push(i);
            }
            
            else{
                lstk.pop();
                if(lstk.empty()){
                    lstk.push(i);
                }
                else{
                    //diff i - stack.top
                    result = max(result, i - lstk.top());
                }
            }
        }
        
        return result;
        
    }
};
