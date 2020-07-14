using namespace std;

#include <iostream>
#include <vector>

class FindDuplicate {
 public:
  static int findNumber(vector<int> &nums) {
    int i = 0;
    while (i < nums.size()) {
      if (nums[i] != i + 1) {
        if (nums[i] != nums[nums[i] - 1]) {
          swap(nums, i, nums[i] - 1);
        } else  // we have found the duplicate
        {
          return nums[i];
        }
      } else {
        i++;
      }
    }

    return -1;
  }

 private:
  static void swap(vector<int> &arr, int i, int j) {
    int temp = arr[i];
    arr[i] = arr[j];
    arr[j] = temp;
  }
};

int main(int argc, char *argv[]) {
  vector<int> v1 = {1, 4, 4, 3, 2};
  cout << FindDuplicate::findNumber(v1) << endl;

  v1 = {2, 1, 3, 3, 5, 4};
  cout << FindDuplicate::findNumber(v1) << endl;

  v1 = {2, 4, 1, 4, 4};
  cout << FindDuplicate::findNumber(v1) << endl;
}
