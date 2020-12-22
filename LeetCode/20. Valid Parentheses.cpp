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
        
        map<char,char> mp ={ 
                            {'(',')'},
                            {'{','}'},
                            {'[',']'}
                           };
        if(s.empty()) 
        return true;
        
        if(s.size() < 2)
        return false;
        
        stack<char> stk;
        
        int index = 0;
        while(index < s.size()){
                         
            if(s[index] == '[' || s[index] == '{' ||  s[index] == '(')
            stk.push(s[index]);
            
            else {
                if(stk.empty())
                return false;
                
                char t = stk.top();
                stk.pop();
                
                
                if(mp[t] != s[index])
                return false;
                
            }
            
            index++;
        } 
        return stk.empty();  
    }
};
