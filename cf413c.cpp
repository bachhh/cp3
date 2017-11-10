#include <iostream>
#include <assert.h>
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
#define LOOP(n) for (int z = 0; z < n; ++z)
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
  int n, m; cin >> n >> m;
  vector<pair<int, bool>> v;
  int64 temp;
  LOOP(n){
    cin >> temp;
    v.push_back(make_pair(temp, false));
  }
  LOOP(m){
    cin >> temp;
    v[temp-1].second = true;
  }
  // Sort auction question last, then sort by decreasing points
  sort(v.begin(), v.end(), [] ( pair<int, bool> a, pair<int, bool> b ){
          return ( !(a.second != b.second) || (!a.second) ) &&
          ( (a.second != b.second) || (a.first > b.first) ) ;
       });
  temp = 0;
  for(pair<int, bool> q : v){
    // For each auction question, you either double or win the prize, whichever gain greater points
    temp += (q.second) ? MAX(temp, q.first) : q.first;
  }
  cout << temp << endl;
  return 0;
}


