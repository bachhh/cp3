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


//  ***** MAIN *****
int main(){
  ios::sync_with_stdio(false);
  int n, m, k; cin >> n >> m >> k;
  int32 temp;
  vector<int32> army;
  for(int i =1; i <= m; ++i){
    cin >> temp;
    army.push_back(temp);
  }
  cin >> m;
  int count = 0;
  int similar;
  for(int32 i : army){
    similar = 0;
    temp = i ^ m;
    for(int bit = 0; bit < n; ++bit){
      if ((temp >> bit) & 1) similar++;
    }
    if (similar <= k) count++;
  }
  cout << count << endl;

  return 0;
}


