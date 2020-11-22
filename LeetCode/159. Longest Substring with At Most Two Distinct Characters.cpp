/*

Given a string s , find the length of the longest substring t  that contains at most 2 distinct characters.

Example 1:

Input: "eceba"
Output: 3
Explanation: t is "ece" which its length is 3.
Example 2:

Input: "ccaabbb"
Output: 5
Explanation: t is "aabbb" which its length is 5.

*/

class Solution {
public:
    int lengthOfLongestSubstringTwoDistinct(string s) {
        
        if(s.empty()) return 0;
        unordered_map<char,int> M;
        int start = 0;
        int result = 0;
        
        for(int end = 0; end <s.size(); end++){
            
            M[s[end]]++;
            
            if(M.size() > 2){
                if(--M[s[start]] == 0) M.erase(s[start]);
                start++;
                
            }
            
            result = max(result, end -start +1);
   
        }
        
        return result;
        
    }
};
