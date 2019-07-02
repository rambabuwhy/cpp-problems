
/*
 * Author: Rambabu Yerajana
 * Text:   HackerRank 
 * Topic:  Puzzle 
 * Statement: sparse Arrays or Matching Strings 
 * Description:  matching strings 
 * */

#include <bits/stdc++.h>

using namespace std;


vector<int> matchingStrings(vector<string> strings, vector<string> queries) {
  vector<int>result;
  for(int i = 0 ; i < queries.size() ; i++){
    int count = std::count(strings.begin(),strings.end(),queries[i]) ;
    result.emplace_back(count);
  }

  return result;
}

int main()
{
  ofstream fout(getenv("OUTPUT_PATH"));

  int strings_count;
  cin >> strings_count;
  cin.ignore(numeric_limits<streamsize>::max(), '\n');

  vector<string> strings(strings_count);

  for (int i = 0; i < strings_count; i++) {
    string strings_item;
    getline(cin, strings_item);

    strings[i] = strings_item;
  }

  int queries_count;
  cin >> queries_count;
  cin.ignore(numeric_limits<streamsize>::max(), '\n');

  vector<string> queries(queries_count);

  for (int i = 0; i < queries_count; i++) {
    string queries_item;
    getline(cin, queries_item);

    queries[i] = queries_item;
  }

  vector<int> res = matchingStrings(strings, queries);

  for (int i = 0; i < res.size(); i++) {
    fout << res[i];

    if (i != res.size() - 1) {
      fout << "\n";
    }
  }

  fout << "\n";

  fout.close();

  return 0;
}

