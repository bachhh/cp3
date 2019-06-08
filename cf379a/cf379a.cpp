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
  int a, b, time = 0;
  cin >> a >> b; 
  int make = b;
  stack<int> candle;
  while(a--) candle.push(1);
  while(!candle.empty()){
    candle.pop();
    time++;
    make--;
    if (make == 0){
      make = b;
      candle.push(1);
    }
  }
  cout << time;

  return 0;
}

