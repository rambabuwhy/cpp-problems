using namespace std;

#include <iostream>
#include <vector>

class WaterContainer {
 public:
  static int findMaxWater(const vector<int>& buildingHeights) {
    // use two pointer approach to find the maximum area
    int left = 0, right = buildingHeights.size() - 1;
    int maxArea = 0, currentArea = 0;

    while (left < right) {
      if (buildingHeights[left] < buildingHeights[right]) {
        currentArea = (right - left) * buildingHeights[left];
        left++;
      } else {
        currentArea = (right - left) * buildingHeights[right];
        right--;
      }
      maxArea = max(maxArea, currentArea);
    }

    return maxArea;
  }
};

int main(int argc, char* argv[]) {
  cout << WaterContainer::findMaxWater(vector<int>{1, 3, 5, 4, 1}) << endl;
  cout << WaterContainer::findMaxWater(vector<int>{3, 2, 5, 4, 2}) << endl;
  cout << WaterContainer::findMaxWater(vector<int>{1, 4, 3, 2, 5, 8, 4}) << endl;
}
