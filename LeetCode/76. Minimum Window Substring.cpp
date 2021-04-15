/*
Given two strings s and t, return the minimum window in s which will contain all the characters in t. If there is no such window in s that covers all characters in t, return the empty string "".

Note that If there is such a window, it is guaranteed that there will always be only one unique minimum window in s.

 

Example 1:

Input: s = "ADOBECODEBANC", t = "ABC"
Output: "BANC"
Example 2:

Input: s = "a", t = "a"
Output: "a"

*/



class Solution {
public:
    string minWindow(string s, string t) {
        
        string result;
        int minLength = s.size()+1;
        int matched = 0;
        int subStrStart = 0;
        
        unordered_map<char, int> charFrequencyMap;
        for(auto c:t){
            charFrequencyMap[c]++;
        }
        
        int windowStart = 0;
        
        for (int windowEnd = 0; windowEnd < s.length(); windowEnd++) {
              char rightChar = s[windowEnd];
              if (charFrequencyMap.find(rightChar) != charFrequencyMap.end()) {
                charFrequencyMap[rightChar]--;
                if (charFrequencyMap[rightChar] >= 0) {  // count every matching of a character
                  matched++;
                }
              }

              // shrink the window if we can, finish as soon as we remove a matched character
              while (matched == t.length()) {
                if (minLength > windowEnd - windowStart + 1) {
                  minLength = windowEnd - windowStart + 1;
                  //result = s.substr(windowStart, windowEnd);
                  subStrStart = windowStart;
                }

                char leftChar = s[windowStart++];
                if (charFrequencyMap.find(leftChar) != charFrequencyMap.end()) {
                  // note that we could have redundant matching characters, therefore we'll decrement the
                  // matched count only when a useful occurrence of a matched character is going out of the
                  // window
                  if (charFrequencyMap[leftChar] == 0) {
                    matched--;
                  }
                  charFrequencyMap[leftChar]++;
                }
              }
        }
        
        return minLength > s.length() ? "" : s.substr(subStrStart, minLength);;
  
    }
};
