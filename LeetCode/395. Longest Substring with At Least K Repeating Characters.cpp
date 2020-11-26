/*

Given a string s and an integer k, return the length of the longest substring of s such that the frequency of each character in this substring is less than or equal to k.

 

Example 1:

Input: s = "aaabb", k = 3
Output: 3
Explanation: The longest substring is "aaa", as 'a' is repeated 3 times.
Example 2:

Input: s = "ababbc", k = 2
Output: 5
Explanation: The longest substring is "ababb", as 'a' is repeated 2 times and 'b' is repeated 3 times.


*/


class Solution {
public:
    int longestSubstring(string s, int k) {
        
        
        unordered_map<char,int> Map;
        
        for(int i = 0; i< s.size();i++){
            Map[s[i]]++;
        }
        
        
        int result = 0;
        
        for(int currUniq = 1; currUniq <= Map.size(); currUniq++){
            
            //clear Map
            Map.clear();
            
            int Wstart = 0;
            int Wend = 0;
            
            //two counts for uniq chars and  atleast K  times
            int uniq = 0;
            int atLeast = 0;
            
            while(Wend < s.size()){
                
                
                if(uniq <= currUniq){  //expand  increase  uniq  and atleast
                    
                    if(Map[s[Wend]] == 0)  uniq++;
                    
                    Map[s[Wend]] ++;
                    
                    if(Map[s[Wend]] == k) atLeast++;
                    
                    Wend++;
                    
                }
                else {   //shrink  decrease uniq and  atleast
                    if (Map[s[Wstart]] == k) atLeast--;
                    
                    Map[s[Wstart]]--;
                    
                    if (Map[s[Wstart]] == 0) uniq--;
                    
                    Wstart++;
                    
                
                }
                
                if (uniq == currUniq && uniq == atLeast)
                    result = max(Wend - Wstart, result);
            
            }
        }
        
        return result;
  
    }
};
