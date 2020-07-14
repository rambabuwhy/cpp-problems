
/*
 * Author: Rambabu Yerajana
 * Text:   ElementsOfProgrammingInterviews 
 * Topic:  Puzzle 
 * Statement: maximum sum sub array 
 * Description: maximum sum sub array 
 * */

#include<iostream>
#include<vector>
using namespace std;

int maxSubArray(vector<int> &a)
{
  int max=0,min=0,sum=0;
  for(int i=0;i<a.size();i++)
  {
    sum += a[i];
    if(sum < min )
      min = sum;
    if((sum - min) > max )
      max = sum - min;
  }
  return max;
}

int main()
{
  int n=10;
  vector<int> a(n);
  for(int i=0;i<n;i++)
    cin>>a[i];
  cout<<"Max:"<<maxSubArray(a)<<endl;;
  return 0;
}
