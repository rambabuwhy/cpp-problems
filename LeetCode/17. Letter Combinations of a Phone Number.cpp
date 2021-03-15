/*
Given a string containing digits from 2-9 inclusive, return all possible letter combinations that the number could represent. Return the answer in any order.

A mapping of digit to letters (just like on the telephone buttons) is given below. Note that 1 does not map to any letters.



 

Example 1:

Input: digits = "23"
Output: ["ad","ae","af","bd","be","bf","cd","ce","cf"]
Example 2:

Input: digits = ""
Output: []
Example 3:

Input: digits = "2"
Output: ["a","b","c"]

*/

class Solution {
    
    vector<string> P = {"","","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};
    
public:
    vector<string> letterCombinations(string digits) {
        
        if(digits.size() < 1) return vector<string>();
        
        vector<string> result;
        backtrack(result, digits, "", 0);
        return result;
        
    }
    
    void backtrack(vector<string> &result, string digits, string currString,int index){
        
        if(index == digits.size()){
            result.push_back(currString);
            return;
        }
        
        string curr = P[digits[index]-'0'];
        for(int i = 0; i< curr.size();i++){
            currString.push_back(curr[i]);
            backtrack(result, digits, currString,index+1);
            currString.pop_back();
        }
              
    }
};