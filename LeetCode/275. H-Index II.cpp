/*
Given an array of citations sorted in ascending order (each citation is a non-negative integer) of a researcher, write a function to compute the researcher's h-index.

According to the definition of h-index on Wikipedia: "A scientist has index h if h of his/her N papers have at least h citations each, and the other N − h papers have no more than h citations each."
*/
class Solution {
public:
    int hIndex(vector<int>& citations) {
        
        int idx = 0, n = citations.size();
        int pivot, left = 0, right = n - 1;
        while (left <= right) {
          pivot = left + (right - left) / 2;
          if (citations[pivot] == n - pivot) return n - pivot;
          else if (citations[pivot] < n - pivot) left = pivot + 1;
          else right = pivot - 1;
        }
        return n - left;
        
    }
};
