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
        
        int needle_size = needle.size();
        int haystack_size = haystack.size();
        
        //p: base  m: modulo
        const int prime = 31; 
        const int mod = 1e9 + 9;
        
        //pre calculate powers into a vector
        vector<long> prime_pow(haystack_size); 
        prime_pow[0] = 1;  //p_pow ^ 0 = 1
        for (int i = 0; i < (int)prime_pow.size()-1; i++) 
            prime_pow[i+1] = (prime_pow[i] * prime) % mod;

        ////pre calculate hash of haystack into a vector
        vector<long> haystack_hash(haystack_size + 1, 0); 
        for (int i = 0; i < haystack_size; i++)
            haystack_hash[i+1] = (haystack_hash[i] + (haystack[i] - 'a' + 1) * prime_pow[i]) % mod; 
        
        //hash of needle
        long needle_hash = 0; 
        for (int i = 0; i < needle_size; i++) 
            needle_hash = (needle_hash + (needle[i] - 'a' + 1) * prime_pow[i]) % mod; 

        //rolling hash ;  compare hash
        vector<int> occurences;
        for (int i = 0; i + needle_size - 1 < haystack_size; i++) { 
            long cur_hash = (haystack_hash[i + needle_size] + mod - haystack_hash[i]) % mod; 
            if (cur_hash == needle_hash * prime_pow[i] % mod)
                occurences.push_back(i);
        }
        return occurences.size() < 1 ? -1 : occurences[0];
    }
  
};

