/*
Implement strStr().

Return the index of the first occurrence of needle in haystack, or -1 if needle is not part of haystack.

Clarification:

What should we return when needle is an empty string? This is a great question to ask during an interview.

For the purpose of this problem, we will return 0 when needle is an empty string. This is consistent to C's strstr() and Java's indexOf().

 

Example 1:

Input: haystack = "hello", needle = "ll"
Output: 2
Example 2:

Input: haystack = "aaaaa", needle = "bba"
Output: -1
Example 3:

Input: haystack = "", needle = ""
Output: 0
*/

class Solution {

    
public:
    
    //haystack.size() > needle.size()
    int strStr(string haystack, string needle) {
        
        //sanity
        if(haystack.size() < needle.size()) return -1;
        if(!needle.size()) return 0;
        
        int NS = needle.size(), HS = haystack.size();
        
        //p: base  m: modulo
        const int p = 31; 
        const int m = 1e9 + 9;
        
        vector<long> p_pow(HS); //pre calculate powers into a vector
        p_pow[0] = 1;  //p_pow ^ 0 = 1
        for (int i = 1; i < (int)p_pow.size(); i++) 
            p_pow[i] = (p_pow[i-1] * p) % m;

        vector<long> h(HS + 1, 0); 
        for (int i = 0; i < HS; i++)
            h[i+1] = (h[i] + (haystack[i] - 'a' + 1) * p_pow[i]) % m; 
        
        long h_s = 0; 
        for (int i = 0; i < NS; i++) 
            h_s = (h_s + (needle[i] - 'a' + 1) * p_pow[i]) % m; 

        for (int i = 0; i + NS - 1 < HS; i++) { 
            long cur_h = (h[i+NS] + m - h[i]) % m; 
            if (cur_h == h_s * p_pow[i] % m)
                return i;
        }
        return -1;
    }
  
};
