
/*
Implement atoi which converts a string to an integer.

The function first discards as many whitespace characters as necessary until the first non-whitespace character is found. Then, starting from this character, takes an optional initial plus or minus sign followed by as many numerical digits as possible, and interprets them as a numerical value.

The string can contain additional characters after those that form the integral number, which are ignored and have no effect on the behavior of this function.

If the first sequence of non-whitespace characters in str is not a valid integral number, or if no such sequence exists because either str is empty or it contains only whitespace characters, no conversion is performed.

If no valid conversion could be performed, a zero value is returned.

*/

class Solution {
public:
    int myAtoi(string str) {
     int result = 0;
        int index = 0;
        bool neg = false;
        while(str[index]==' '){
            index++;
        }
        if(str[index]=='-'){
            neg=true;
            index++;
        }
        else if(str[index]=='+'){
            neg=false;
            index++;
        }
        else if(!isdigit(str[index])){
            return 0;
        }
        while(isdigit(str[index])){
            int digit = str[index++]-'0';

            if (result > INT_MAX/10 || (result == INT_MAX / 10 && digit > 7))
                    if (neg) return INT_MIN;
                    else return INT_MAX;

            result = result * 10 + digit;
        }
        if(neg) {
            result=-result;
        }
        return result;
    }
};
