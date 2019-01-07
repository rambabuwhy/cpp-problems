#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <map>
using namespace std;


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    
    map<string,string> name_phone;
    int n;
    cin>>n;
    string key="";
    string phone="";
    for(int i =0 ;i<n;i++){
       cin>>key;
        cin>>phone;
        name_phone[key]=phone;
    }
   
      
    while(std::getline(std::cin, key)){
              
             
              if(key.empty())continue;
              map<string,string> ::iterator itr=name_phone.find(key);
              if(itr != name_phone.end())
              {   
                  string name1=itr->first;
                  string phone1=itr->second;
    
                  cout<<name1<<"="<<phone1<<endl;
              }   
              else
              {   
                          cout<<"Not found"<<endl;
              }
       
       
        }
    return 0;
}