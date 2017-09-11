#include <iostream>
#include <stdio.h>
#include <cmath>
#include <string>
#include <vector>
#include <map>
#include <list>
#include <unordered_map>
#include <sstream>
#include <stack>
#include <queue>
#include <deque>
#include <iterator>
#include <bitset>
#include <algorithm>
#include <stdexcept>

using namespace std;

typedef long int int32;
typedef long long int int64;
typedef unsigned long int uint32;
typedef unsigned long long int uint64;

const double pi = acos(-1.0);

#define PI 3.1415926535897932384626433832795
#define INF (int)1e9
#define FOREACH(it, l) for (auto it = l.begin(); it != l.end(); it++)
#define MAX(a, b) ( (a > b ) ? a : b )
#define MIN(a, b) ( (a < b ) ? a : b )



int main(){
  //freopen("input.txt", "r", stdin);
  //freopen("output.txt", "w", stdin);
  int count = 1;

  map<string, int> word_map;   
  queue<string> queue; 

  for (char c = 'a'; c <= 'z'; c++){
    queue.push(string(1,c));
  }

  while(!queue.empty() && count <= 83681){
    string s = queue.front();
    queue.pop(); 
    word_map[s] = count++;
    for (char c = s.back() + 1; c <= 'z'; c++){
      queue.push(s+c);
    }
  }
  string input;
  while(getline(cin, input)){
    try{
      cout << word_map.at(input) << endl;
    }
    catch (std::out_of_range &oor){
      cout << 0 << endl;
    }
  }
    
  return 0;
}

