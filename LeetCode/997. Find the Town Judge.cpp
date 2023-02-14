class Solution {
public:
    int findJudge(int N, vector<vector<int>>& trust) {
        if(trust.size() < N-1) return -1;
        vector<int> Deg(N+1);
        for(auto e:trust){
            Deg[e[0]]--;
            Deg[e[1]]++;
            
        }
        for(int i =1;i<=N;i++ ){
            if(Deg[i]==N-1) return i;
        }
        
        return -1;
        
    }
};
