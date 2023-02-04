/*
Given two strings s1 and s2, return true if s2 contains a permutation of s1, or false otherwise.

In other words, return true if one of s1's permutations is the substring of s2.

 

Example 1:

Input: s1 = "ab", s2 = "eidbaooo"
Output: true
Explanation: s2 contains one permutation of s1 ("ba").
Example 2:

Input: s1 = "ab", s2 = "eidboaoo"
Output: false

*/

class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        
        // return false if the length of s1 is greater than s2
        if (s1.length() > s2.length()) return false;

        // create a hash table to store the character count of s1
        unordered_map<char, int> charCounts;
        for (char c : s1) charCounts[c]++;

        // initialize two pointers, left and right
        int left = 0, right = 0;
        // initialize a count to store the number of characters matched
        int count = s1.length();

        while (right < s2.length()) {
            // if the current character exists in the hash table and its count is greater than 0,
            // decrement the count in the hash table and decrement the count variable
            if (charCounts[s2[right++]]-- >= 1) count--;

            // if count reaches 0, it means a permutation of s1 is found in s2
            if (count == 0) return true;

            // if the length of the current window (right - left) is equal to the length of s1,
            // it means the window is sliding past a valid permutation, so increment the left pointer
            // and increment the count in the hash table and increment the count variable
            if (right - left == s1.length() && charCounts[s2[left++]]++ >= 0) count++;
        }

        // return false if no permutation of s1 is found in s2
        return false;
    }
};
