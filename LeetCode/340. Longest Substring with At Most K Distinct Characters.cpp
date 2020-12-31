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
    int lengthOfLongestSubstringKDistinct(string s, int k) {
        
        int n = s.size();
        
        if(k * n == 0)
        return 0;
        
        int ws = 0;
        int longest_str = 0;
        unordered_map<char,int> mp;
        
        for( int we =0; we<n; we++){
            
            char right_char = s[we];
            mp[right_char]++;
            
            if(mp.size() > k){
                
                int left_char = s[ws];
                mp[left_char]--;
                
                if(mp[left_char] == 0)
                mp.erase(left_char);
                
                ws++;
            }
            
            longest_str = max(longest_str, we - ws + 1);
            
            
        }
        
        return longest_str;
        
    }
};
