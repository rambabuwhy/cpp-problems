/*
Given a string s and a string t, check if s is subsequence of t.

A subsequence of a string is a new string which is formed from the original string by deleting some (can be none) of the characters without disturbing the relative positions of the remaining characters. (ie, "ace" is a subsequence of "abcde" while "aec" is not).

Follow up:
If there are lots of incoming S, say S1, S2, ... , Sk where k >= 1B, and you want to check one by one to see if T has its subsequence. In this scenario, how would you change your code?

*/
class Solution {
public:
    bool isSubsequence(string s, string t) {
     
        if(s.empty() && !t.empty()) return true;
        if(s.empty() && t.empty()) return true;
        if(!s.empty() && t.empty()) return false;
        //if(!s.empty() && !t.empty());
        
        cout<<s.size();
           
        int ll = 0 , lr = s.size();
        int rl = 0,  rr = t.size();
        while(ll < lr && rl < rr){
            if(s[ll]==t[rl]) ll++;
            rl++;
        }
        return ll == lr;
    }
};
