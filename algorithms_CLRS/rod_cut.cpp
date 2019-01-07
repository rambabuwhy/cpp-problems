/*
 * Author:        Rambabu Yerajana
 * Text:          CLRS  Third Edition
 * Topic:         Dynamic Programming
 * Statement:     rod-cutting Problem
 * Description:   The rod-cutting problem is the following. Given a rod of length n inches and 
 *                a table of prices pi for i D 1;2; : : : ;n, determine the maximum revenue rn 
 *                obtainable by cutting up the rod and selling the pieces. Note that if the 
 *                price pn for a rod of length n is large enough, an optimal solution may require 
 *                no cutting at all.
 * */

#include<iostream>
#include<vector>
using namespace std;

int MAX3(int i, int j, int k) { return i > j? (i > k? i: k): (j > k? j: k); }
int MAX2(int i, int j)  { return i > j?  i:  j; }


int Cut_Rod(vector<int> &price, int r_length)
{
  if(r_length == 0 ) return 0;

  int temp = -1;
  for( int i = 1 ; i <=r_length; i++)
  {
    temp = MAX2(temp,price[i-1] + Cut_Rod(price,r_length - i ));
  }
  return temp;
}

void _print_(vector<int> price)
{
  cout << " Output: ";
  for(int i = 0; i < price.size(); i++)
    cout<< i << "-" << price[i] << "   ";
  cout << endl;
}

int main()
{
  int r_length = 0, p = 0,no_rods=0;
  vector<int> price;
  cout << " Enter No of Rods: ";
  cin >> no_rods;
  cout << " Enter Rod Lengths:";
  for(int i = no_rods; i > 0; i--)
  {
    cin >> p;
    price.push_back(p);
  }
  cout << " Enter Rod Length: ";
  cin >> r_length;
  _print_(price);
  cout << endl << " Total Highest Profit:" << Cut_Rod(price,r_length);
  cout << endl;
  return 0;
}
