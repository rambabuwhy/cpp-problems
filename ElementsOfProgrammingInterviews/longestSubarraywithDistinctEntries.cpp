// Copyright (c) 2013 Elements of Programming Interviews. All rights reserved.

#include <algorithm>
#include <iostream>
#include <string>
#include <unordered_map>
#include <unordered_set>

using namespace std;
int LongestSubarrayWithDistinctEntries(const vector<int>& A) {
  for(int i = 0;i<A.size();i++)
  {
    cout<<A[i]<<" ";
  }
  cout<<endl;
  unordered_map<int, size_t> most_recent_occurrence;
  size_t longest_dup_free_subarray_start_idx = 0, result = 0;
  for (size_t i = 0; i < A.size(); ++i) {
    auto dup_idx = most_recent_occurrence.emplace(A[i], i);
    if (!dup_idx.second) {
      cout<< dup_idx.first->second ;
      cout<<": "<< dup_idx.first->first << endl;
      if (dup_idx.first->second >= longest_dup_free_subarray_start_idx) {
        result = max(result, i - longest_dup_free_subarray_start_idx);
        longest_dup_free_subarray_start_idx = dup_idx.first->second + 1;
      }
      dup_idx.first->second = i;
    }
  }
  result = max(result, A.size() - longest_dup_free_subarray_start_idx);
  return result;
}
int main()
{
  cout<<LongestSubarrayWithDistinctEntries({10, 20, 10, 30, 10, 20, 10})<<endl;
  return 0;
}
