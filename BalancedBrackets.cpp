#include <map>
#include <set>
#include <list>
#include <cmath>
#include <ctime>
#include <deque>
#include <queue>
#include <stack>
#include <string>
#include <bitset>
#include <cstdio>
#include <limits>
#include <vector>
#include <climits>
#include <cstring>
#include <cstdlib>
#include <fstream>
#include <numeric>
#include <sstream>
#include <iostream>
#include <algorithm>
#include <unordered_map>

using namespace std;

bool is_balanced(string expression) {
    if(expression.length() == 0)
        {
        return true;
    }
    
    
    std::stack<char> first; 
 
    for(int i=0;i<expression.length();i++){
        
        if(expression[i] == '{' ||
           expression[i] == '[' ||
           expression[i] == '(' )
            {
            
            first.push(expression[i]);
        }
        else{ 
            if(first.size() <= 0)
                return false;
            if(expression[i] == '}' ){
                
                if(first.top() == '{'){
                    first.pop();
                }
                else
                    return false;
            }
            else if(expression[i] == ']' ){
                
                if(first.top() == '['){
                    first.pop();
                }
                else
                    return false;
               
           }
           else if(expression[i] == ')' ){
            
           
                if(first.top() == '('){
                    first.pop();
                }
               else
                   return false;
           }
            else
                return false;
        }
        
    }
   if(first.size() == 0){
    return true;
   }
    else
        return false;
    
}

int main(){
    int t;
    cin >> t;
    for(int a0 = 0; a0 < t; a0++){
        string expression;
        cin >> expression;
        bool answer = is_balanced(expression);
        if(answer)
            cout << "YES\n";
        else cout << "NO\n";
    }
    return 0;
}