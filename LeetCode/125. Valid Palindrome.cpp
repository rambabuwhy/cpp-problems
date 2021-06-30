/*

Given a string, determine if it is a palindrome, considering only alphanumeric characters and ignoring cases.

Note: For the purpose of this problem, we define empty string as valid palindrome.

Example 1:

Input: "A man, a plan, a canal: Panama"
Output: true
Example 2:

Input: "race a car"
Output: false

*/

class Solution {
public:
    bool isPalindrome(string s) {
        
        //sanity
        if(s.size() < 2) return true;
        
        //two pointers left and right
        int left = 0;
        int right = s.size()-1;
        while(left <= right){
            
            //step 1: skip if it is not alpa numeric
            if(!isalnum(s[left]))  { left++;   continue;}
            if(!isalnum(s[right])) { right--;  continue;}
             
            // step 2: return false if it is not match
            if(tolower(s[left]) != tolower(s[right])) return false;
        
            left++;
            right--;
        }
        
        return true;
    }
};
