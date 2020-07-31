/*
Given a non-empty string s and a dictionary wordDict containing a list of non-empty words, add spaces in s to construct a sentence where each word is a valid dictionary word. Return all such possible sentences.

Note:

The same word in the dictionary may be reused multiple times in the segmentation.
You may assume the dictionary does not contain duplicate words.
Example 1:

Input:
s = "catsanddog"
wordDict = ["cat", "cats", "and", "sand", "dog"]
Output:
[
  "cats and dog",
  "cat sand dog"
]
Example 2:

Input:
s = "pineapplepenapple"
wordDict = ["apple", "pen", "applepen", "pine", "pineapple"]
Output:
[
  "pine apple pen apple",
  "pineapple pen apple",
  "pine applepen apple"
]
Explanation: Note that you are allowed to reuse a dictionary word.
Example 3:

Input:
s = "catsandog"
wordDict = ["cats", "dog", "sand", "and", "cat"]
Out

*/

class Solution {
public:
    unordered_map<string,vector<string>> mp;
    vector<string> wordBreak(string s, vector<string>& wordDict) {
        
        if(mp.count(s)) return mp[s];
        
        
        vector<string> result;
        
        if(find(wordDict.begin(),wordDict.end(),s) != wordDict.end()) { 
            result.push_back(s);
        }
        
        for(int i = 1; i<s.size();  ++i){
            string first=s.substr(i);
            if(find(wordDict.begin(),wordDict.end(),first) != wordDict.end()) {
                
                string rem=s.substr(0,i);
                vector<string> subList = wordBreak(rem,wordDict);
                
                for(auto last:subList){
                    result.insert(result.end(), last + " " + first);
                    
                }
              }
        }
        
        mp[s]=result;
        
        
        return result;
        
    }
};
