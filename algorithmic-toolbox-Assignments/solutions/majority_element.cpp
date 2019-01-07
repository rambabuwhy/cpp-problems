
/*
 * Author: Rambabu Yerajana
 * Text:   Algorithm Tool Box 
 * Topic:  Puzzle 
 * Statement: Majority Element 
 * Description: Majority rule is a decision rule that selects the alternative
 * which has a majority,that is, more than half the votes.
 * Given a sequence of elements 𝑎1, 𝑎2, . . . , 𝑎𝑛, you would like to check
 * whether it contains an element that appears more than 𝑛/2 times.. 
 * */


#include <algorithm>
#include <iostream>
#include <vector>
#include <map>

using std::vector;
using namespace std;
//using divide and conqour
int fast_get_majority_element(vector<int> &a, int left, int right) {
  if (left == right) return -1;
  if (left + 1 == right) return a[left];
  //write your code here
  int mid = left + (right - left) / 2; 
  fast_get_majority_element(a,left,mid);
  fast_get_majority_element(a,mid+1,right);
  return -1;
}

//using Hash
int fast3_get_majority_element(vector<int> &a, int left, int right) {
  if (left == right) return -1;
  if (left + 1 == right) return 1;
  //write your code here
  map<int,int> hash;
  for(int i=0;i<a.size();i++)
  {
    map<int,int>::iterator it = hash.find(a[i]);
    if(it != hash.end())
    {
      int count = it->second + 1;
      if(count > a.size() / 2)
      {
        return 1;
      }
      it->second = count;

    }
    else
    {
      hash.insert ( std::pair<int,int >(a[i],1) );
    }
  }
  return -1;
}

//using moore
int fast2_get_majority_element(vector<int> &a, int left, int right) {
  if (left == right) return -1;
  if (left + 1 == right) return a[left];
  //write your code here
  while(left <= right)
  {


  }
  return -1;
}

int naive_get_majority_element(vector<int> &a, int left, int right) {
  if (left == right) return -1;
  if (left + 1 == right) return 1;
  for ( int i = 0 ; i < a.size();i++)
  {
    int current = i;
    int count = 0;
    for ( int j=0; j< a.size();j++)
    {
      if(a[current] == a[j])
      {
        count++;
        if(count > (a.size()/2))
        {
          return 1;
        }

      }
    }
  }
  return -1;
}
int main() {
//#define __STRESS_TEST__
#ifndef __STRESS_TEST__
  int n;
  std::cin >> n;
  vector<int> a(n);
  for (size_t i = 0; i < a.size(); ++i) {
    std::cin >> a[i];
  }
#endif
#ifdef __STRESS_TEST__
//STRESS TEST
  while(true)
  {

    int n = rand() % 10  + 1;
    vector<int> a(n);
    for (size_t i = 0; i < a.size(); i++) 
    {
      int val = rand() % 7 + 1;

      a[i]=val;
    }
    
      int naive =  naive_get_majority_element(a,0,a.size()) ;
      int fast =  fast3_get_majority_element(a,0,a.size()) ;
      if( naive != fast)
      {
        cout<<"-----------------------------------------------"<<endl;
        cout<<""<<n<<" "<<endl;
        for(int i = 0 ; i < a.size() ; i++)
        {
          cout<<a[i] <<" ";
        }
        cout<<endl;
        cout<<" Wrong Answer : " <<naive<< " : "<<fast<<endl;
        cout<<"-----------------------------------------------"<<endl;
        return 0;
      }
      else
      {
        cout<<"-----------------------------------------------"<<endl;
        for(int i = 0 ; i < a.size() ; i++)
        {
          cout<<a[i] <<" ";
        }
        cout<<" correct : " <<naive<< " : "<<fast<<endl;
      }
        cout<<"-----------------------------------------------"<<endl;
  }


//STRESS TEST
#endif
#ifndef __STRESS_TEST__
  std::cout << (fast3_get_majority_element(a, 0, a.size()) != -1) << '\n';
#endif
}
