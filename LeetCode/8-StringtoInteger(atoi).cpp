
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
