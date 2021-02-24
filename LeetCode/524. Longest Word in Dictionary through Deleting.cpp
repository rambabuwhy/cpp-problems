/*
Given a string and a string dictionary, find the longest string in the dictionary that can be formed by deleting some characters of the given string. If there are more than one possible results, return the longest word with the smallest lexicographical order. If there is no possible result, return the empty string.

Example 1:

Input:
s = "abpcplea", d = ["ale","apple","monkey","plea"]

Output: 
"apple"
 

Example 2:

Input:
s = "abpcplea", d = ["a","b","c"]

Output: 
"a"
*/

class Solution {
public:
    
    //word is subsequence of str
    //iterate both and if word_i == word.size()  then "yes"
    bool canFormByDeleting(string word, string str) {
        int word_i = 0, str_i = 0;
        
        while (word_i < word.size() && str_i < str.size()) {
            
            if (word[word_i] == str[str_i])
                word_i++; 
            
            str_i++;
        }
        
        return word_i == word.size();
    }
    
    string findLongestWord(string s, vector<string>& d) {
        
        string result = "";
        
        for (auto dstr : d) {
            
            if (canFormByDeleting(dstr, s)) {
                
                if (dstr.size() > result.size() || (dstr.size() == result.size() && dstr < result))
                    result = dstr;
            }
        }
        
        return result;
    }
};
