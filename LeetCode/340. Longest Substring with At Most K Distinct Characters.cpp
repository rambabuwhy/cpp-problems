/*

Given a string s and an integer k, return the length of the longest substring of s that contains at most k distinct characters.

 

Example 1:

Input: s = "eceba", k = 2
Output: 3
Explanation: The substring is "ece" with length 3.
Example 2:

Input: s = "aa", k = 1
Output: 2
Explanation: The substring is "aa" with length 2.

*/

class Solution {
public:
    
    //sliding window algorithm
    int lengthOfLongestSubstringKDistinct(string s, int k) {
        
        int n = s.size();
        unordered_map<char,int> lmap;
        
        if(k * n == 0) return 0;
        
        int max_length = 0;
        int wstart = 0;
        for( int wend=0; wend<n; wend++){
            
            char right_char = s[wend];
            lmap[right_char]++;
            
            //if window size is more than k; shrink it
            if(lmap.size() > k){
                
                int left_char = s[wstart];
                lmap[left_char]--;
                
                if(lmap[left_char] == 0) lmap.erase(left_char);
                
                wstart++;
            }
            max_length = max(max_length, wend - wstart + 1); 
        }
        return max_length;
    }
};
