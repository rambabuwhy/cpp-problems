using namespace std;

#include <iostream>
#include <queue>
#include <string>
#include <vector>

class ParenthesesString {
 public:
  string str;
  int openCount = 0;   // open parentheses count
  int closeCount = 0;  // close parentheses count

  ParenthesesString(const string &s, int openCount, int closeCount) {
    this->str = s;
    this->openCount = openCount;
    this->closeCount = closeCount;
  }
};

class GenerateParentheses {
 public:
  static vector<string> generateValidParentheses(int num) {
    vector<string> result;
    queue<ParenthesesString> queue;
    queue.push({"", 0, 0});
    while (!queue.empty()) {
      ParenthesesString ps = queue.front();
      queue.pop();
      // if we've reached the maximum number of open and close parentheses, add to the result
      if (ps.openCount == num && ps.closeCount == num) {
        result.push_back(ps.str);
      } else {
        if (ps.openCount < num) {  // if we can add an open parentheses, add it
          queue.push({ps.str + "(", ps.openCount + 1, ps.closeCount});
        }

        if (ps.openCount > ps.closeCount) {  // if we can add a close parentheses, add it
          queue.push({ps.str + ")", ps.openCount, ps.closeCount + 1});
        }
      }
    }
    return result;
  }
};

int main(int argc, char *argv[]) {
  vector<string> result = GenerateParentheses::generateValidParentheses(2);
  cout << "All combinations of balanced parentheses are: ";
  for (auto str : result) {
    cout << str << " ";
  }
  cout << endl;

  result = GenerateParentheses::generateValidParentheses(3);
  cout << "All combinations of balanced parentheses are: ";
  for (auto str : result) {
    cout << str << " ";
  }
  cout << endl;
}
