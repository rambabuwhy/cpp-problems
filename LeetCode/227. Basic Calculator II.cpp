/*
Implement a basic calculator to evaluate a simple expression string.

The expression string contains only non-negative integers, +, -, *, / operators and empty spaces . The integer division should truncate toward zero.

Example 1:

Input: "3+2*2"
Output: 7
Example 2:

Input: " 3/2 "
Output: 1
Example 3:

Input: " 3+5 / 2 "
Output: 5

*/
class Solution {
public:
    int calculate(string s) {
        
        if (s.size() == 0) return 0;
        
        //using stack
        stack<int> stack;
        
        int currentNumber = 0;
        char operation = '+';
        
        for (int i = 0; i < s.size(); i++) {
            
            //If the current character is a digit 0-9 ( operand ), add it to the number currentNumber.           
            if (isdigit(s[i])) {
                currentNumber = (currentNumber * 10) + (s[i] - '0');
            }
            
            //Otherwise
            if (!isdigit(s[i]) && !iswspace(s[i]) || i == s.size() - 1) {
                
                //if  + or -   :push 
                //if  * or /   :do operation and push to stack
                if (operation == '-') {
                    stack.push(-currentNumber);
                } else if (operation == '+') {
                    stack.push(currentNumber);
                } else if (operation == '*') {
                    int stackTop = stack.top();
                    stack.pop();
                    stack.push(stackTop * currentNumber);
                } else if (operation == '/') {
                    int stackTop = stack.top();
                    stack.pop();
                    stack.push(stackTop / currentNumber);
                }
                operation = s[i];
                currentNumber = 0;
            }
        }
        
        int result = 0;
        while (stack.size() != 0) {
            result += stack.top();
            stack.pop();
        }
        return result;
    }
};
