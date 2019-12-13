using namespace std;

#include <iostream>
#include <vector>

class CircularArrayLoop {
 public:
  static bool loopExists(const vector<int> &arr) {
    for (int i = 0; i < arr.size(); i++) {
      bool isForward = arr[i] >= 0;  // if we are moving forward or not
      int slow = i, fast = i;

      // if slow or fast becomes '-1' this means we can't find cycle for this number
      do {
        slow = findNextIndex(arr, isForward, slow);  // move one step for slow pointer
        fast = findNextIndex(arr, isForward, fast);  // move one step for fast pointer
        if (fast != -1) {
          fast = findNextIndex(arr, isForward, fast);  // move another step for fast pointer
        }
      } while (slow != -1 && fast != -1 && slow != fast);

      if (slow != -1 && slow == fast) {
        return true;
      }
    }

    return false;
  }

 private:
  static int findNextIndex(const vector<int> &arr, bool isForward, int currentIndex) {
    bool direction = arr[currentIndex] >= 0;
    if (isForward != direction) {
      return -1;  // change in direction, return -1
    }

    // wrap around for negative numbers
    int nextIndex = (currentIndex + arr[currentIndex] + arr.size()) % arr.size();

    // one element cycle, return -1
    if (nextIndex == currentIndex) {
      nextIndex = -1;
    }

    return nextIndex;
  }
};

int main(int argc, char *argv[]) {
  cout << CircularArrayLoop::loopExists(vector<int>{1, 2, -1, 2, 2}) << endl;
  cout << CircularArrayLoop::loopExists(vector<int>{2, 2, -1, 2}) << endl;
  cout << CircularArrayLoop::loopExists(vector<int>{2, 1, -1, -2}) << endl;
}
