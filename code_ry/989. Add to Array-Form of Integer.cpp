/*

Author: Rambabu Yerajana
Linkedin: https://www.linkedin.com/in/rambabuyerajana/
Problem:  Add to Array-Form of Integer

------------------------------------------------------------------

Description:
The array-form of an integer num is an array representing its digits in left to right order.

For example, for num = 1321, the array form is [1,3,2,1].
Given num, the array-form of an integer, and an integer k, return the array-form of the integer num + k.

 

Example 1:

Input: num = [1,2,0,0], k = 34
Output: [1,2,3,4]
Explanation: 1200 + 34 = 1234
Example 2:

Input: num = [2,7,4], k = 181
Output: [4,5,5]
Explanation: 274 + 181 = 455
Example 3:

Input: num = [2,1,5], k = 806
Output: [1,0,2,1]
Explanation: 215 + 806 = 1021


------------------------------------------------------------------

Solution:
The function takes two inputs - a reference to a vector of integers num, which represents the array-form of an integer, and an integer k, which is the number we want to add to num. 
The function returns a vector representing the array-form of the sum num + k.

The approach we take is similar to the standard addition algorithm we use in arithmetic. We iterate through num and k from right to left, adding each corresponding pair of digits, as well as any carry-over from the previous addition. 
We keep track of the carry-over in the variable carry.

Once we have computed the sum, we add the last digit to the result vector, and update the carry-over for the next iteration.

If there are still digits remaining in num or k, we continue the iteration until we have processed all the digits.

Finally, we reverse the result vector to get the correct order of digits, since we added them from right to left.


------------------------------------------------------------------

Notes:
The solution I provided is a standard solution to the problem and has a time complexity of O(N), where N is the length of the input array num.
This is because we need to traverse the entire input array once, and the time required to perform addition is constant.

In terms of space complexity, the solution uses O(N) extra space to store the result vector.

This solution is optimal in terms of time complexity, as any algorithm that needs to add all the digits of the input will require at least O(N) time, since we need to traverse all the digits at least once. 
However, there may be room for optimization in terms of space complexity, depending on the requirements of the problem.

For example, if the input array num is very large and we don't want to use a lot of extra space to store the result vector, we could modify the solution to update the input array num in place, rather than creating a new vector for the result. 
This would require us to work from right to left in the input array, updating each digit and carrying over any excess to the next digit. 
However, this approach could make the code more complex and harder to understand, so it should only be used if there are specific performance or space constraints that require it.


------------------------------------------------------------------
*/


#include <vector>

std::vector<int> addToArrayForm(std::vector<int>& num, int k) {
    std::vector<int> result;
    int carry = 0;
    int i = num.size() - 1;
    
    while (i >= 0 || k > 0 || carry > 0) {
        int sum = carry;
        if (i >= 0) {
            sum += num[i];
            i--;
        }
        if (k > 0) {
            sum += k % 10;
            k /= 10;
        }
        result.push_back(sum % 10);
        carry = sum / 10;
    }
    
    std::reverse(result.begin(), result.end());
    return result;
}


//comments added 
#include <vector>

std::vector<int> addToArrayForm(std::vector<int>& num, int k) {
    // Initialize an empty result vector to store the sum of the array-form integer and k
    std::vector<int> result;
    // Initialize a variable to keep track of any carry-over from previous digits
    int carry = 0;
    // Initialize an index variable to traverse the input array from right to left
    int i = num.size() - 1;
    
    // Continue iterating until we have processed all digits in both num and k, and there is no carry-over left
    while (i >= 0 || k > 0 || carry > 0) {
        // Initialize the sum variable to the carry-over from the previous addition
        int sum = carry;
        // Add the current digit from num to the sum, if there are any digits left
        if (i >= 0) {
            sum += num[i];
            i--;
        }
        // Add the current digit from k to the sum, if there are any digits left
        if (k > 0) {
            sum += k % 10;
            k /= 10;
        }
        // Add the last digit of the sum to the result vector, and update the carry-over for the next addition
        result.push_back(sum % 10);
        carry = sum / 10;
    }
    
    // Reverse the result vector to get the correct order of digits
    std::reverse(result.begin(), result.end());
    // Return the result vector
    return result;
}

