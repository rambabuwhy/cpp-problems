/*

Given two non-negative integers num1 and num2 represented as strings, return the product of num1 and num2, also represented as a string.

Note: You must not use any built-in BigInteger library or convert the inputs to integer directly.

 

Example 1:

Input: num1 = "2", num2 = "3"
Output: "6"
Example 2:

Input: num1 = "123", num2 = "456"
Output: "56088"

*/

class Solution {
public:
    string multiply(string num1, string num2) {
        
        string result(num1.size() + num2.size(), '0');
        
        //iterate from back
        for(int i = num1.size()-1; i>=0; i--){
            int carry = 0;
            for(int j = num2.size()-1; j>=0; j--){
                
                int temp = (result[i+j+1] -'0') + (num1[i]-'0') * (num2[j]-'0') + carry;
                result[i+j+1] = temp % 10 +'0';
                carry = temp / 10;
                
            }
            
            //add carry
            result[i] = result[i] + carry;
        }
        
        //remove zeros  by finding first non zero
        size_t spos = result.find_first_not_of("0");
        if(string::npos != spos){
            return result.substr(spos);
            
        }
        
        return "0";
    }
};
