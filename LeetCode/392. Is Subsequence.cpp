/*
Given two strings s and t, return true if s is a subsequence of t, or false otherwise.

A subsequence of a string is a new string that is formed from the original string by deleting some (can be none) of the characters without disturbing the relative positions of the remaining characters. (i.e., "ace" is a subsequence of "abcde" while "aec" is not).

 

Example 1:

Input: s = "abc", t = "ahbgdc"
Output: true
Example 2:

Input: s = "axc", t = "ahbgdc"
Output: false
*/

class Solution {
public:
    bool isSubsequence(string s, string t) {

        int sl = 0 , sr = s.size();  //pointers for string s 
        int tl = 0,  tr = t.size();  //pointer for string t

        while(sl < sr && tl < tr){

            //increment pointer sl only if find same char in t
            if(s[sl]==t[tl]) sl++;

            //always increment pointer for string t
            tl++;
        }

        //check sl and sr pointer if all character match then subsequence exist
        return sl == sr;
    }
};
