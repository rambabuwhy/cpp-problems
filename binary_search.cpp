
/*
 * Author: Rambabu Yerajana
 * Text:   Algorithm Tool Box 
 * Topic:  Puzzle 
 * Statement: Binary Search 
 * Description:In this problem, you will implement the binary search algorithm
 * that allows searching very efficiently (even huge) lists, provided that the list is sorted. 
 * */


#include <iostream>
#include <cassert>
#include <vector>
#include <unistd.h>

using std::vector;
using namespace std;
int binary_search(const vector<int> &a, int x) {

  //cout<<endl;
  //cout<<"-------- B S -----------"<<endl;
  int left = 0, right = (int)a.size() - 1; 
  //write your code here
  while(left <= right )
  {
    //cout<<"left: "<<left<<"  right: "<<right<<endl;
    int mid = left + (right - left ) / 2; 
    //cout <<"mid: "<<mid<<endl;
    if(a[mid] == x)
    { 
      return mid;
    }
    else if( x < a[mid])
    { 
      right = mid - 1;
    }
    else 
    {
      left = mid + 1;
    }
  }
  //cout<<"-------- B S -----------"<<endl;
  return -1;
}
int linear_search(const vector<int> &a, int x) {
  for (size_t i = 0; i < a.size(); ++i) {
    if (a[i] == x) return i;
  }
  return -1;
}

int main() {
//#define __STRESS_TEST__

#ifndef __STRESS_TEST__
  int n;
  std::cin >> n;
  vector<int> a(n);
  for (size_t i = 0; i < a.size(); i++) 
  {
    std::cin >> a[i];
  }
  int m;
  std::cin >> m;
  vector<int> b(m);
  for (int i = 0; i < m; ++i) 
  {
    std::cin >> b[i];
  }
#endif
#ifdef __STRESS_TEST__
//STRESS TEST
  while(true)
  {
    int n = rand() % 20  + 1;
    vector<int> a(n);
    int val1 = rand() % 20  + 1;
    int Init = val1;
    for (size_t i = 0; i < a.size(); i++) 
    {
      a[i] = val1;
      int val2 = rand() % 21 + 1;
      val1 += val2;
    }
    int m = rand() % 20  + 1;
    vector<int> b(m);
    for (int i = 0; i < m; ++i) 
    {
       b[i] = rand() % 100  + 1;
    }

    
    for (int i = 0; i < m; ++i) 
    {
      int naive =  linear_search(a, b[i]) ;
      int fast = binary_search(a,b[i]);
      if( naive != fast)
      {
        cout<<"-----------------------------------------------"<<endl;
        cout<<"Intial: "<<Init<<endl;
        cout<<""<<n<<" ";
        for(int i = 0 ; i < a.size() ; i++)
        {
          cout<<a[i] <<" ";
        }
        cout<<endl;
        cout<<""<<m<<" ";
        for(int i = 0 ; i < b.size() ; i++)
        {
          cout<<b[i] <<" ";
        }
        cout<<endl;
        cout<<" Wrong Answer for: " <<b[i]<< " Linear: "<<naive<< " "<<" Binary: "<<fast<<endl;
        return 0;
      }
      else
        cout <<" Correct :"<<endl;
    }
  }


//STRESS TEST
#endif
#ifndef __STRESS_TEST__
  for (int i = 0; i < m; ++i) {
    //replace with the call to binary_search when implemented
    std::cout << binary_search(a, b[i]) << ' ';
  }
#endif
}
