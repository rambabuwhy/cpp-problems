using namespace std;

#include <iostream>
#include <string>
#include <vector>

class FindCorruptNums {
 public:
  static vector<int> findNumbers(vector<int> &nums) {
    int i = 0;
    while (i < nums.size()) {
      if (nums[i] != nums[nums[i] - 1]) {
        swap(nums, i, nums[i] - 1);
      } else {
        i++;
      }
    }

    for (i = 0; i < nums.size(); i++) {
      if (nums[i] != i + 1) {
        return vector<int>{nums[i], i + 1};
      }
    }

    return vector<int>{-1, -1};
  }

 private:
  static void swap(vector<int> &arr, int i, int j) {
    int temp = arr[i];
    arr[i] = arr[j];
    arr[j] = temp;
  }
};

int main(int argc, char *argv[]) {
  vector<int> v1 = {3, 1, 2, 5, 2};
  vector<int> nums = FindCorruptNums::findNumbers(v1);
  cout << nums[0] << ", " << nums[1] << endl;

  v1 = {3, 1, 2, 3, 6, 4};
  nums = FindCorruptNums::findNumbers(v1);
  cout << nums[0] << ", " << nums[1] << endl;
}
