/*

Given an encoded string, return its decoded string.

The encoding rule is: k[encoded_string], where the encoded_string inside the square brackets is being repeated exactly k times. Note that k is guaranteed to be a positive integer.

You may assume that the input string is always valid; No extra white spaces, square brackets are well-formed, etc.

Furthermore, you may assume that the original data does not contain any digits and that digits are only for those repeat numbers, k. For example, there won't be input like 3a or 2[4].

 

Example 1:

Input: s = "3[a]2[bc]"
Output: "aaabcbc"
Example 2:

Input: s = "3[a2[c]]"
Output: "accaccacc"
Example 3:

Input: s = "2[abc]3[cd]ef"
Output: "abcabccdcdcdef"
Example 4:

Input: s = "abc3[cd]xyz"
Output: "abccdcdcdxyz"

*/

class Solution {
public:
    string decodeString(string s) {
        
        stack<char> st;
        
        for(int i = 0; i < s.size(); i++){
            
            //push until ']'
            if(s[i] != ']') {
                st.push(s[i]);
            }
            
            //decode if ']'
            else{
                string curr_str = "";
                
                while(st.top() != '['){
                    curr_str = st.top() + curr_str ;
                    st.pop();
                }
                
                st.pop();   
               
        
                //to integer  
                int number = 0;
                int base = 1;
                while(!st.empty() && isdigit(st.top())){
                  
                    number = number + (st.top() - '0') * base ;
                    st.pop();
                    
                    base = base * 10;
                }
                
                while(number--){
                    for(int p = 0; p < curr_str.size() ; p++)
                        st.push(curr_str[p]);
                }
            }
        }
        
        string result = "";
        while(!st.empty()){
            result = st.top() + result;
            st.pop();
        }
        return result;
        
        
    }
};
