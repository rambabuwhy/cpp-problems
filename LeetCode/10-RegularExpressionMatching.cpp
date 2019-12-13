
class Solution {
public:
    bool isMatch(string s, string p) {
        if(p.empty()) return s.empty();
        bool firstMatch = ((!s.empty()) && (p[0] == s[0] || p[0] == '.'));
        if(p.length() >=2 && p[1] == '*'){

            return (isMatch(s,p.substr(2)) || firstMatch && isMatch(s.substr(1),p));

        }
        else {
             return (firstMatch && isMatch(s.substr(1),p.substr(1)));
        }
    }
};
