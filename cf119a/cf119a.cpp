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

int gcd(int u, int v){
  if (u == v) 
    return u;
  if (u == 0) 
    return v;
  if (v == 0) 
    return u;
  if (~u & 1) {
    if(v & 1) {
      return gcd(u >> 1, v);
    } 
    else {
      return gcd(u >> 1, v >> 1) << 1;
    }
  }
  if (~v & 1){
    return gcd(u, v >> 1);
  }
  if (u > v){
    return gcd( (u-v) >> 1, v);
  }
  else {
    return gcd( (v-u) >> 1, u);
  }
}
int main(){
  //freopen("input.txt", "r", stdin);
  //freopen("output.txt", "w", stdin);
  
  int a, b, heap;
  cin >> a >> b >> heap;


  while(true){

    heap -=  gcd(a, heap);
    if (heap <= 0) {
      cout << 0 << endl;
      break;
    }

    heap -=  gcd(b, heap);
    if (heap <= 0){
      cout << 1 << endl;
      break;
    }

  }

  return 0;
}

