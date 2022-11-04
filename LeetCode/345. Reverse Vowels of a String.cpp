/*
Given a string s, reverse only all the vowels in the string and return it.

The vowels are 'a', 'e', 'i', 'o', and 'u', and they can appear in both lower and upper cases, more than once.

 

Example 1:

Input: s = "hello"
Output: "holle"
Example 2:

Input: s = "leetcode"
Output: "leotcede"
*/

class Solution {
public:

    bool isVowel(char c){
        return (c=='a' || c=='e' || c=='i' || c=='o' || c=='u' ||
                c=='A' || c=='E' || c=='I' || c=='O' || c=='U' );
    }

    string reverseVowels(string s) {
        
        int l=0;
        int r=s.size()-1;

        while(l<r){

           while(l<r && isVowel(s[l]) == false){l++;}
           while(l<r && isVowel(s[r]) == false){r--;}
           if(l<r) swap(s[l],s[r]);
           l++,r--;
        }
        return s;
    }
};
