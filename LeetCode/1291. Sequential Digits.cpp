/*

An integer has sequential digits if and only if each digit in the number is one more than the previous digit.

Return a sorted list of all the integers in the range [low, high] inclusive that have sequential digits.

 

Example 1:

Input: low = 100, high = 300
Output: [123,234]
Example 2:

Input: low = 1000, high = 13000
Output: [1234,2345,3456,4567,5678,6789,12345]

*/


class Solution {
public:
    vector<int> sequentialDigits(int low, int high) {
        
        string all_int = "123456789";
        int low_length = to_string(low).length();
        int high_length = to_string(high).length();
        
        vector<int> results;
        for(int i = low_length; i <= high_length; i++){
            for(int j = 0; j < 10 - i; j++){
                
                int res = stoi(all_int.substr(j, i));
                if(res >= low && res <= high){
                    results.push_back(res);
                } 
            }
        }
        return results;        
    }
};
