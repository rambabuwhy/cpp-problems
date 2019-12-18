class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int maxlen = 0;
        int ws = 0;
        unordered_map<char,int> cc;
        for(int we = 0; we < s.length(); we++){
            if(cc.find(s[we]) != cc.end()){
                ws=max(ws,cc[s[we]]+1);
            }
            cc[s[we]]=we;
            maxlen=max(maxlen,we-ws+1);
        }
        return maxlen;
    }
};
