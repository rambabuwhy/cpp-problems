
/*
 * Author: Rambabu Yerajana
 * Text:   Algorithm Tool Box 
 * Topic:  Puzzle 
 * Statement: Maximum Value of the Loot
 * Description: A thief finds much more loot than his bag can fit. Help him to
 * find the most valuable combination  of items assuming that any fraction of 
 * a loot item can be put into his bag. 
 * */

#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
#include <iomanip> 
#include <unistd.h>

using std::vector;
using std::map;
using namespace std;



void v_print(vector<long double> myVector)
{
  //print
  cout<<" Vector:"<<endl;
  for(int i=0;i<myVector.size();i++) 
  { 
    std::cout.precision(10);
    cout<<myVector[i]<<" , ";
  }
  cout<<endl;
  //print
}

void m_print(multimap<long double,long long > myMap)
{
  cout<<"  Map: "<<endl;
  for (multimap<long double,long long >::const_iterator iter = myMap.begin(); iter != myMap.end(); ++iter)
  {
        std::cout.precision(10);
        cout << iter->first << ", " << iter->second << '\n';
        //std::cout << it->first << " ,  " << it->second << "\n";
  }
}

double get_optimal_value(long long  capacity, vector<long long > weights, vector<long long > values) {
  long double value = 0.0;

  // write your code here
  vector<long double> vow(weights.size());
  multimap<long double,long long >i_vow;
  for(int i = 0;i < weights.size() ;i ++)
  {
    vow[i] = (long double)values[i]/(long double)weights[i];
    i_vow.insert ( std::pair<long double,long long >(vow[i],weights[i]) );
    //m_print(i_vow);
  }
  //cout<<"----------BEFORE SORT-------------------"<<endl;
  //v_print(vow);
  //cout<<"-----------------------------"<<endl;
  //m_print(i_vow);
  //cout<<"-----------------------------"<<endl;
  //cout<<"  Map at: "<<i_vow[2]<<end;
  std::sort(vow.begin(), vow.end(), std::greater<int>());
  //cout<<" Total Capacity: "<<capacity<<endl;
  //cout<<"------AFTER SORT-----------------------"<<endl;
  //v_print(vow);
  //cout<<"-----------------------------"<<endl;
  //m_print(i_vow);
  //cout<<"-----------------------------"<<endl;
  for(int i = 0; i < weights.size(); i++ )
  {
    if(capacity <=0)  break;
    std::multimap<long double,long long>::iterator it = i_vow.find(vow[i]);
    long double a  = std::min((long double)capacity,(long double)it->second);
    //cout<<"-----------BEFORE PROCESS-----------"<<endl;
    //cout<<" cpacity: "<< capacity;
    //cout<<" itr: "<< it->second;
    //cout<< " Minimum: "<<a;
    //cout<< " value: "<<value;
    //cout<<endl;
    value = value + a * vow[i];
    capacity = capacity - a; 
    //cout<<"-----------AFTER PROCESS-----------"<<endl;
    //cout<<" cpacity: "<< capacity;
    //cout<<" itr: "<< it->second;
    //cout<< " Minimum: "<<a;
    //cout<< " value: "<<value;
    //cout<<endl;
    i_vow.erase(it);

  }
 // cout<<endl<<"-----------------------------"<<endl;
 // cout<<endl<<" Final: "<<value<<endl;
  return value;
}

long long get_next_vow(vector<long long>weights,vector<long long>values)
{
  long double max = 0.0;
  long long index = -1;
  for(int i =0 ;i < weights.size() ;i++)
  {
    if(weights[i])
    {
      long double vow = (long double) values[i] / weights[i];
      //cout<<" vow: "<< vow ;
      if( max < (values[i] / weights[i]))
      {
        index = i;
        max =(long double) values[i] / weights[i];
      }
    }
  }
 // cout <<" max: "<<max<<"  , "<<index<<endl;
  return index;

}

double get_Naive_value(long long  capacity, vector<long long > weights, vector<long long > values) {
  long double value = 0.0;

  // write your code here
  for(int i = 0; i < weights.size(); i++ )
  {
    if(capacity <=0)  break;
    long long index = get_next_vow(weights,values);
    long double max_vow = (long double) values[index] / weights[index];
    long double a  = std::min((long double)capacity,(long double)weights[index]);
    //cout<<" a: "<<a<<endl;
    //cout<<" max_vow: "<<max_vow<<endl;
    value = value + a * max_vow;
    capacity = capacity - a; 
    values[index]= 0.0;
    weights[index] =  0.0;

  }

  return value;
}
int main() {

#define __STRESS_TEST__

  long long n;
  long long capacity;
#ifndef __STRESS_TEST__
  std::cin >> n >> capacity;
#endif
  vector<long long > values(n);
  vector<long long > weights(n);
#ifndef __STRESS_TEST__
  for (int i = 0; i < n; i++) {
    std::cin >> values[i] >> weights[i];
  }
#endif
 
  //cout << " N: "<<n<<"  ,"<<capacity<<endl;
  
#ifdef __STRESS_TEST__
//STRESS TEST
  while(true)
  {
    long long  n = rand() % 3 + 1 ;
    long long  capacity = rand() % 500 + 1;
    
    vector<long long > values(n);
    vector<long long > weights(n);

    for (int i = 0; i < n; i++) {
      long long  value = rand() % 5000 + 501 ;
      long long  weight = rand() % 500 + 1 ;
      values[i]= value;
      weights[i] = weight;
    }

    long double naive =  get_Naive_value(capacity,weights,values);
    long double fast = get_optimal_value(capacity, weights, values);

      cout << " --------------------------"<<endl;
      cout<<" N: "<<n <<" , "<<" Capacity: "<<capacity<<endl;
    for(int i =0 ; i < n ; i++)
    {
      cout<<values[i]<<" , "<<weights[i] <<endl;
    }
      cout << " --------------------------"<<endl;

    if( naive != fast)
    {
      cout<<" Wrong Answer: " << naive <<" , "<<fast<<endl;
      return 0;
    }
    else
      cout <<" Correct :"<<naive<<" - "<<fast<<endl;

    //sleep(1);
  }


//STRESS TEST
#endif

  long double optimal_value = get_optimal_value(capacity, weights, values);

  std::cout.precision(10);
  //cout<<endl;
 // cout<<" Answer: "<<endl;
  std::cout << optimal_value << std::endl;
  return 0;
}
