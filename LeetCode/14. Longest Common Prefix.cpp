/*

Write a function to find the longest common prefix string amongst an array of strings.

If there is no common prefix, return an empty string "".

 

Example 1:

Input: strs = ["flower","flow","flight"]
Output: "fl"
Example 2:

Input: strs = ["dog","racecar","car"]
Output: ""
Explanation: There is no common prefix among the input strings.

*/

class Solution {
public:
    
    //Divide and conquer
    string longestCommonPrefix(vector<string>& strs) {
        if(strs.size() == 0 ) return "";
        if(strs.size() == 1) return strs[0];
        return longestCommonPrefixUtil(strs,0,strs.size()-1);
        
    }
    string longestCommonPrefixUtil(vector<string> & strs,int l, int r){
        if(l==r){
            return strs[l];
        }
        else{
            int mid = (l + r) / 2;
            string str1 = longestCommonPrefixUtil(strs,l,mid);
            string str2 = longestCommonPrefixUtil(strs,mid+1,r);
            return commonPrefix(str1,str2);
        }
        
    }
     string commonPrefix(string s1, string s2){
        int minimum = min(s1.length(),s2.length());
        string result;
        for (int i=0;i<minimum;i++){
            if(s1[i] != s2[i]) break;
            else result += s1[i];
        }
        return result;
    }
   
};
