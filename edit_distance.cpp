
/*
 * Author: Rambabu Yerajana
 * Text:   Algorithm Tool Box 
 * Topic:  Puzzle 
 * Statement: Edit Distance 
 * Description:The edit distance between two strings is the minimum number of operations (insertions, deletions, and
 * substitutions of symbols) to transform one string into another. It is a measure of similarity of two strings.
 * Edit distance has applications, for example, in computational biology, natural language processing, and spell
 * checking. Your goal in this problem is to compute the edit distance between two strings.
 * */

#include <iostream>
#include <string>
#include<bits/stdc++.h>

using std::string;
using namespace std;
int min(int x, int y, int z) 
{ 
      return min(std::min(x, y), z); 
} 
int edit_distance(const string &str1, const string &str2) {
  //write your code here
  int m = str1.length();
  int n = str2.length();
  int table[m+1][n+1];
  for (int i = 0 ; i <= m ;i++)
  {
    for(int j = 0;j <= n ;j++)
    {
      if(i==0)
        table[i][j]=j;
      else if(j==0)
        table[i][j]=i;
      else
      {
        if(str1[i-1] == str2[j-1])
          table[i][j] = table[i-1][j-1];
        else
          table[i][j]= 1+ min(table[i][j-1],table[i-1][j],table[i-1][j-1]);

      }
    }
  }
  return table[m][n];
}

int main() {
  string str1;
  string str2;
  std::cin >> str1 >> str2;
  std::cout << edit_distance(str1, str2) << std::endl;
  return 0;
}
