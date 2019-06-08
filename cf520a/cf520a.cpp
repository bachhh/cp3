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
#include <functional>

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
  int n; cin >> n;
  map<char, bool> m;
  int count = 26;
  if (n < 26){
    cout << "NO" << endl;
    return 0;
  }

  string s;
  cin >> s;
  for (char c : s){
    if (m.count(tolower(c)) != 1){
      m[tolower(c)] = true;
      count--;
    }
  }
  if (!count) cout << "YES" << endl;
  else cout << "NO" << endl;

  return 0;
}

