class Solution {
public:
    int maxSubarraySumCircular(vector<int>& A) {
        if(A.size() < 1)  return 0;
        if(A.size() < 2) return A[0];
        
        int ans=A[0];
        int curr=A[0];
        
        //first subarray
        for(int i=1; i<A.size(); i++){
            curr = max(curr,0) + A[i];
            ans = max(ans,curr);
        }
        
        //second subarray
        vector<int> cumi_right(A.size());
        cumi_right[A.size()-1] = A[A.size()-1];
        
        for(int i = A.size()-2; i>=0; i--){
            cumi_right[i] = cumi_right[i+1] + A[i];
            
        }
        
        vector<int> cumi_r_max(A.size());
        cumi_r_max[A.size()-1] = A[A.size()-1];
        
        for(int i = A.size()-2; i>=0; i--){
            cumi_r_max[i] = max(cumi_r_max[i+1], cumi_right[i]);
        }
        
        
        // max of first + second
        
        int cSum = 0;
        for(int i=0; i<A.size()-2; i++){
            cSum = cSum + A[i];
            ans = max(ans,cSum + cumi_r_max[i+2]);
        }
        
        return ans;
        
    }
};
