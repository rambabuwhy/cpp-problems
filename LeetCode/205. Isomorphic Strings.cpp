/*
Given two strings s and t, determine if they are isomorphic.

Two strings s and t are isomorphic if the characters in s can be replaced to get t.

All occurrences of a character must be replaced with another character while preserving the order of characters. No two characters may map to the same character, but a character may map to itself.

 

Example 1:

Input: s = "egg", t = "add"
Output: true
Example 2:

Input: s = "foo", t = "bar"
Output: false
Example 3:

Input: s = "paper", t = "title"
Output: true

*/



class Solution {
public:
    bool isIsomorphic(string s, string t) {
        if (s.empty()) return true;

        // need to check s->t  and t->s mapping
        //why s->t and t->s  because the failed example is:  "badc" "baba"
        return helper(s, t) && helper(t, s);
    }
    bool helper(string s, string t) {
    	
        unordered_map<char, char> lmap;
        for (auto i = 0; i != s.size(); ++i) {
            
            // if map does not contain the char mapping then create a map s->t
            if (!lmap.count(s[i])) lmap.insert({s[i], t[i]});

            //if map has already mapping s->t then 
            //check previous mapping and the current mapping is same or not 
            //if not then return false
        	else if (lmap[s[i]] != t[i])  return false;
        }
        return true;
    }
};
