/*



ou have an array of logs.  Each log is a space delimited string of words.

For each log, the first word in each log is an alphanumeric identifier.  Then, either:

Each word after the identifier will consist only of lowercase letters, or;
Each word after the identifier will consist only of digits.
We will call these two varieties of logs letter-logs and digit-logs.  It is guaranteed that each log has at least one word after its identifier.

Reorder the logs so that all of the letter-logs come before any digit-log.  The letter-logs are ordered lexicographically ignoring identifier, with the identifier used in case of ties.  The digit-logs should be put in their original order.

Return the final order of the logs.

 

Example 1:

Input: logs = ["dig1 8 1 5 1","let1 art can","dig2 3 6","let2 own kit dig","let3 art zero"]
Output: ["let1 art can","let3 art zero","let2 own kit dig","dig1 8 1 5 1","dig2 3 6"]
 

Constraints:

0 <= logs.length <= 100
3 <= logs[i].length <= 100
logs[i] is guaranteed to have an identifier, and a word after the identifier.



*/


class Solution {
public:
    vector<string> reorderLogFiles(vector<string>& logs) {
        
        
        vector<string> digitLogs;
        vector<pair<string, string>> letterLogs;
        
        //seperate digit and letter logs
        for (string &s : logs) {
            int i = 0;
            //step 1: divide log into two part  
            //part1: first word  part2:remaining words
            
            while (s[i] != ' ') ++i;
            
            //step2:  to sort letter logs itself ( no need for digit)
            //part2 should be sorted :-  store pair<first word,  remaing words>
            if (isalpha(s[i + 1])) letterLogs.emplace_back(s.substr(0, i), s.substr(i + 1));
            else digitLogs.push_back(s);
        }
        
        //step 3: sort letter itself  part2
        sort(letterLogs.begin(), letterLogs.end(), [&](auto& a, auto& b) {
            return a.second == b.second ? a.first < b.first : a.second < b.second;
        });
        
        //step 4:  store all into single vector
        vector<string> result;
        for (auto &p : letterLogs) result.push_back(p.first + " " + p.second);
        for (string &s : digitLogs) result.push_back(s);
        return result;
  
        
    }
};
