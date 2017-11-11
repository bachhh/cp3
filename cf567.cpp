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
  int n; cin >> n;
  int32 temp;
  vector<int32> v;
  v.push_back(0);
  cin >> temp;

  v.push_back(temp);
  cin >> temp;
  v.push_back(temp);
  v[0] = v[1]- abs(v[1]-v[2]) -1;

  LOOP(n-2){
    cin >> temp;
    v.push_back(temp);
  }

  v.push_back(v[n] + abs(v[n]-v[n-1])+1);

  for(int i =1; i <= n; i++){
    printf("%ld %ld\n", MIN(abs(v[i]-v[i+1]), abs(v[i]-v[i-1])),
                       MAX(abs(v[i]-v[1]), abs(v[i]-v[n])));
  }

  return 0;
}


