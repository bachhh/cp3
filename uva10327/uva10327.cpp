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

int bubbleSort(vector<int> &v){
  int count = 0;
  int i = 0, temp;

  // i was promoted to size_t, hence size_t -1 > v.size()
  // Cast v.size() to int
  while( i < ((int)v.size()-1) ){
    if (i > -1 && v[i] > v[i+1]){
      v[i] ^= v[i+1];
      v[i+1] ^= v[i];
      v[i] ^= v[i+1];
      --i;
      count++;
    }
    else {
      i++;
    }
  }
  return count;
}

int main(){
  int n, temp;
  vector<int> v;
  int a = 2, b = 3, c = a^b;
  while(cin >> n ){
    v.clear();
    while(n--){
      cin >> temp;
      v.push_back(temp);
    }

    cout << "Minimum exchange operations : " << bubbleSort(v) << endl;
  }
  return 0;
}
