/*
Given a string, find the length of the longest substring without repeating characters.

Example 1:

Input: "abcabcbb"
Output: 3 
Explanation: The answer is "abc", with the length of 3. 
Example 2:

Input: "bbbbb"
Output: 1
Explanation: The answer is "b", with the length of 1.
Example 3:

Input: "pwwkew"
Output: 3
Explanation: The answer is "wke", with the length of 3. 
             Note that the answer must be a substring, "pwke" is a subsequence and not a substring.
 */

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int maxlen = 0;
        int ws = 0;
        unordered_map<char,int> cc;
        for(int we = 0; we < s.length(); we++){
            if(cc.find(s[we]) != cc.end()){
                ws=max(ws,cc[s[we]]+1);
            }
            cc[s[we]]=we;
            maxlen=max(maxlen,we-ws+1);
        }
        return maxlen;
    }
};
