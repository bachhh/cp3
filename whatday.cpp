#include <iostream>
#include <stdio.h>
#include <cmath>
#include <string>
#include <vector>
#include <map>
#include <sstream>
#include <queue>
#include <deque>
#include <iterator>
#include <bitset>

using namespace std;

typedef long int int32;
typedef long long int int64;
typedef unsigned long int uint32;
typedef unsigned long long int uint64;

const double pi = acos(-1.0);

#define PI 3.1415926535897932384626433832795
#define INF (int)1e9
#define FOREACH(it, l) for (auto it = l.begin(); it != l.end(); it++)


int main(){
  freopen("input.txt","r", stdin);
  // freopen("output.txt","r", stdin);
  string output;
  string tempString;
  string find_string = "love";

  getline(cin, tempString); 

  while(tempString.compare(0, 7, "......." )!= 0 ){
    output += tempString + " ";
    getline(cin, tempString); 
  }
  
   
  int pos = 0; 
  vector<int> pos_arr;
  pos = output.find(find_string, pos);  
  cout << output << endl;
  while(pos != -1){
    pos_arr.push_back(pos); 
    pos = output.find(find_string, pos+1);
  }

  for(auto const &i: pos_arr){ cout << i << " "; }  
  cout << endl;

  return 0;
}
