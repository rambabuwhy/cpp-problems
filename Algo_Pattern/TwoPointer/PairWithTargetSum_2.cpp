using namespace std;

#include <iostream>
#include <vector>

class PairWithTargetSum {
 public:
  static pair<int, int> search(const vector<int>& arr, int targetSum) {
    int left = 0, right = arr.size() - 1;
    while (left < right) {
      // comparing the sum of two numbers to the 'targetSum' can cause integer overflow
      // so, we will try to find a target difference instead
      int targetDiff = targetSum - arr[left];
      if (targetDiff == arr[right]) {  // found the pair
        return make_pair(left, right);
      }

      if (targetDiff > arr[right])
        left++;  // we need a pair with a bigger sum
      else
        right--;  // we need a pair with a smaller sum
    }
    return make_pair(-1, -1);
  }
};

int main(int argc, char* argv[]) {
  auto result = PairWithTargetSum::search(vector<int>{1, 2, 3, 4, 6}, 6);
  cout << "Pair with target sum: [" << result.first << ", " << result.second << "]" << endl;
  result = PairWithTargetSum::search(vector<int>{2, 5, 9, 11}, 11);
  cout << "Pair with target sum: [" << result.first << ", " << result.second << "]" << endl;
}