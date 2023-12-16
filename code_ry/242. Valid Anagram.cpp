/*

Author: Rambabu Yerajana
Linkedin: https://www.linkedin.com/in/rambabuyerajana/
medium: https://rambabuy.medium.com/
Problem: Valid Anagram
------------------------------------------------------------------
Description:

Given two strings s and t, return true if t is an anagram of s, and false otherwise.

An Anagram is a word or phrase formed by rearranging the letters of a different word or phrase, typically using all the original letters exactly once.

 

Example 1:

Input: s = "anagram", t = "nagaram"
Output: true
Example 2:

Input: s = "rat", t = "car"
Output: false
 


------------------------------------------------------------------
Solution:

# Intuition
The intuition behind this solution is to use an unordered map to count the occurrences of characters in both strings. If two strings are anagrams, they should have the same counts for each character.

# Approach
1. Check if the lengths of the input strings `s` and `t` are equal. If not, they cannot be anagrams, and the function returns false.
2. Use an `std::unordered_map<char, int>` to count the occurrences of characters in string `s`.
3. Iterate through string `t`, decrement the counts in the map, and erase the entry if the count becomes zero.
4. After processing both strings, check if the map is empty. If it is, the strings are anagrams; otherwise, they are not.


------------------------------------------------------------------
Notes:
# Complexity
- Time complexity: O(n), where n is the length of the longer string among `s` and `t`. The function iterates through both strings once.
- Space complexity: O(c), where c is the number of unique characters in the input strings. The space complexity is determined by the size of the unordered map, which holds the counts of characters.



------------------------------------------------------------------
*/

bool isAnagram(const std::string& s, const std::string& t) {
    // Check if the lengths of the strings are equal
    if (s.length() != t.length()) {
        return false;
    }

    // Use unordered_maps to count character occurrences
    std::unordered_map<char, int> counts;

    // Count characters in string s
    for (char c : s) {
        counts[c]++;
    }

    // Decrement counts for characters in string t
    for (char c : t) {
        if (--counts[c] == 0) {
            counts.erase(c);
        }
    }

    // If both strings are anagrams, the map should be empty
    return counts.empty();
}
