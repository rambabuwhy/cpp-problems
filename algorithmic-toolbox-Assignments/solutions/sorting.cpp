
/*
 * Author: Rambabu Yerajana
 * Text:   Algorithm Tool Box 
 * Topic:  Puzzle 
 * Statement: Improving Quick Sort 
 * Description: The goal in this problem is to redesign a given implementation
 * of the randomized quick sort algorithm so that it works fast even on sequences containing
 * many equal elements.
 * */

#include <iostream>
#include <vector>
#include <cstdlib>

using std::vector;
using std::swap;
using namespace std;

int partition2(vector<int> &a, int l, int r) {
  int x = a[l];
  int j = l;
  for (int i = l + 1; i <= r; i++) {
    if (a[i] <= x) {
      j++;
      swap(a[i], a[j]);
    }
  }
  swap(a[l], a[j]);
  return j;
}

void partition3(vector<int> &a, int l, int r ,int &i, int &j) {

  int m = l; 
  int pivot = a[r]; 
  while (m <= r) 
  { 
      if (a[m] < pivot) 
      {
          swap(a[l++], a[m++]); 
      }
      else if (a[m]==pivot) 
      {
          m++; 
      }
      else if (a[m] > pivot) 
      {
          swap(a[m], a[r--]); 
      }
   } 
          
   i = l-1; 
   j = m; 
}

void randomized_quick_sort(vector<int> &a, int l, int r) {
  if (l >= r) {
    return;
  }

  int k = l + rand() % (r - l + 1);
  swap(a[l], a[k]);

  //int m = partition2(a, l, r);
  int i,j;
  partition3(a, l, r,i,j);

  randomized_quick_sort(a, l,i);
  randomized_quick_sort(a, j, r);
}

int main() {
  int n;
  std::cin >> n;
  vector<int> a(n);
  for (size_t i = 0; i < a.size(); ++i) {
    std::cin >> a[i];
  }
  randomized_quick_sort(a, 0, a.size() - 1);
  for (size_t i = 0; i < a.size(); ++i) {
    std::cout << a[i] << ' ';
  }
}
