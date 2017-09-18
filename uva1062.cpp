#include <iostream>
#include <assert.h>
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

vector<stack<char>> port;

int main(){
  string n;
  int test = 0;
  while( cin >> n && n != "end"){

    port.clear();
    stack<char> first;
    port.push_back(first);

    for (char c : n){
      bool found= false;
      for (int i = 0; i < port.size()-1 && !found; i++){
        if ( c <= port[i].top()){
          port[i].push(c);
          found = true;
        }
      }
      if (!found){
        port[port.size()-1].push(c);
        stack<char> new_st;
        port.push_back(new_st);
      }
    }
    test++;
    cout << "Case " << test << ": " << port.size()-1 << endl;
  }
  return 0;
}

