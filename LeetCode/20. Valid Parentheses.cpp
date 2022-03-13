/*
Given a string s containing just the characters '(', ')', '{', '}', '[' and ']', determine if the input string is valid.

An input string is valid if:

Open brackets must be closed by the same type of brackets.
Open brackets must be closed in the correct order.
 

Example 1:

Input: s = "()"
Output: true
Example 2:

Input: s = "()[]{}"
Output: true
Example 3:

Input: s = "(]"
Output: false
Example 4:

Input: s = "([)]"
Output: false
Example 5:

Input: s = "{[]}"
Output: true

*/

class Solution {
public:
    bool isValid(string s) {   

        if(s.empty()) return true;        
        if(s.size()<2) return false;
        
        stack<char> stk;      
        unordered_map<char,char> umap ={{'(',')'},  {'{','}'},  {'[',']'}};
        int index = 0;
        while(index < s.size()) {
                         
            if( s[index] == '[' || s[index] == '{' || s[index] == '(') {                
               stk.push(s[index]);  //if s[index] then push stk
            } else {
                if(stk.empty()) return false;                
                char t = stk.top(); //stack only contains open brace
                stk.pop(); 
                cout<<t<<endl;
                if(umap[t] != s[index]) return false;                
            }            
            index++;
        } 
        return stk.empty();  
    }
};
