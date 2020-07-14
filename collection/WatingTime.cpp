
/*
 * Author: Rambabu Yerajana
 * Text:   ElementsOfProgrammingInterviews 
 * Topic:  Puzzle
 * Problem Statement:  Maximum Waiting Time 
 * Problem Description: logic: how many time we should multiply means how manay
 * time we shoud add.
 * */
#include<iostream>
#include <algorithm>
#include <vector>
using namespace std;

int waitTime(vector<int> & s)
{
  int w=0;
  for(int i=0;i<s.size();i++)
  {
    int r = s.size() - (i+1);
    w += s[i] * r;
  }
  return w;
}

int main()
{ 

  vector<int> s;
  s.push_back(8);
  s.push_back(5);
  s.push_back(1);
  s.push_back(3);

  sort(s.begin(),s.end());
  cout<<"Total waiting Time: "<<waitTime(s)<<endl;
  return 0;
}
