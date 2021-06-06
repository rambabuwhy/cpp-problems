/*
Given a string s, remove the vowels 'a', 'e', 'i', 'o', and 'u' from it, and return the new string.

 

Example 1:

Input: s = "leetcodeisacommunityforcoders"
Output: "ltcdscmmntyfrcdrs"
Example 2:

Input: s = "aeiou"
Output: ""

*/



class Solution {
public:
    string removeVowels(string s) {
        string result;
        for(auto c:s) if(c != 'a' && c!='e' && c!='i' && c != 'o' && c !='u') result = result + c; 
        return result;
    }
};
