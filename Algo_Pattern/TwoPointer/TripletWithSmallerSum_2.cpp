using namespace std;

#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

class TripletWithSmallerSum {
 public:
  static vector<vector<int>> searchTriplets(vector<int> &arr, int target) {
    sort(arr.begin(), arr.end());
    vector<vector<int>> triplets;
    for (int i = 0; i < arr.size() - 2; i++) {
      searchPair(arr, target - arr[i], i, triplets);
    }
    return triplets;
  }

 private:
  static void searchPair(vector<int> &arr, int targetSum, int first,
                         vector<vector<int>> &triplets) {
    int left = first + 1, right = arr.size() - 1;
    while (left < right) {
      if (arr[left] + arr[right] < targetSum) {  // found the triplet
        // since arr[right] >= arr[left], therefore, we can replace arr[right] by any number between
        // left and right to get a sum less than the target sum
        for (int i = right; i > left; i--) {
          triplets.push_back({arr[first], arr[left], arr[i]});
        }
        left++;
      } else {
        right--;  // we need a pair with a smaller sum
      }
    }
  }
};

int main(int argc, char *argv[]) {
  vector<int> vec = {-1, 0, 2, 3};
  auto result = TripletWithSmallerSum::searchTriplets(vec, 3);
  for (auto vec : result) {
    cout << "[";
    for (auto num : vec) {
      cout << num << " ";
    }
    cout << "]";
  }
  cout << endl;

  vec = {-1, 4, 2, 1, 3};
  result = TripletWithSmallerSum::searchTriplets(vec, 5);
  for (auto vec : result) {
    cout << "[";
    for (auto num : vec) {
      cout << num << " ";
    }
    cout << "]";
  }
}
