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
  while( cin >> n && n != 0){
    map<string, int> m;
    while(n--){
      vector<int> v;
      for (int i =0; i < 5; ++i){
        int temp; cin >> temp;
        v.push_back(temp);
        sort(v.begin(), v.end());
      }

      string s = "";
      for(int i : v){
        s += to_string(i);
      }
      m[s]++;
      v.clear();
    }

    int tot = 0;
    int max = 0;

    for (map<string, int>::iterator it = m.begin(); it != m.end(); ++it){
      if (max < it->second) {
        max = it->second;
        tot = it->second;
      }
      else if (max == it->second){
        tot += it->second;
      }
    }
    cout << tot << endl;
  }
  return 0;
}

