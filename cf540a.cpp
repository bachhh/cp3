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
  int n;
  string s1, s2;
  cin >> n >> s1 >> s2;
  int count = 0;
  for(int i =0; i < n; ++i){
    count += MIN( abs(s2[i] -s1[i]), abs(MIN(s2[i],s1[i])+10 - MAX(s1[i], s2[i])));
  }
  cout << count << endl;


  return 0;
}
