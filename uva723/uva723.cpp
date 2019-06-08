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
#include <tuple>

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

void anagram(string input, string output,string stack, string ins){
  // If we reach end of output   
  if (output.empty()){
    if (input.empty() && stack.empty()){
      cout << ins.erase(ins.size()-1) << endl;
    }
    return;
  }
  if (!input.empty()){
    anagram(input.substr(1), output, input.at(0) + stack , ins + "i "); 
     
  }
  if (!stack.empty() && stack.at(0) == output.at(0) ){
    anagram(input, output.substr(1), stack.substr(1), ins + "o " );
  }
}

int main(){
  //freopen("input.txt", "r", stdin);
  //freopen("output.txt", "w", stdin);

  string input, output;

  while(getline(cin, input) && getline(cin, output)){
    cout << "[" << endl;
    if( input.length() == output.length()) { 
      anagram(input, output, "", "");
    } 
    cout << "]" << endl; 
  }
}

