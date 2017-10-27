#include <iostream>
#include <assert.h>
#include <stdio.h>
#include <cmath>
#include <string>
#include <string.h>
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
#include <functional>
#include <ctime>

using namespace std;

typedef long int int32;
typedef long long int int64;
typedef unsigned long int uint32;
typedef unsigned long long int uint64;
const double pi = acos(-1.0);

#define PI 3.1415926535897932384626433832795
#define INF (int)1e9
#define FOREACH(it, l) for (auto it = l.begin(); it != l.end(); it++)
#define LOOP(n) for (int i = 0; i < n; ++i)
#define MAX(a, b) ( (a > b ) ? a : b )
#define MIN(a, b) ( (a < b ) ? a : b )

void swap(int* a, int *b){
  *a ^= *b;
  *b ^= *a;
  *a ^= *b;
}

//  ***** MAIN *****
int main(){
  ios::sync_with_stdio(false);
  int n, temp;
  map<int, int> map1;
  map<int, int> map2;
  // Set all bits on
  cin >> n;

  LOOP(n){
    cin >> temp;
    if(map1.find(temp) == map1.end()) map1[temp] = 1;
    else map1[temp]++;
  }

  LOOP(n-1){
    cin >> temp;
    map1[temp]--;
    if(map2.find(temp) == map2.end()) map2[temp] = 1;
    else map2[temp]++;
  }
  for(const auto &iter : map1){
    if (iter.second){
      cout << iter.first << endl;
      break;
    }
  }
  LOOP(n-2){
    cin >> temp;
    map2[temp]--;
  }
  for(const auto &iter : map2){
    if (iter.second){
      cout << iter.first << endl;
      break;
    }
  }
  return 0;
}

