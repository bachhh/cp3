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
#define MAX(a, b) ( (a > b ) ? a : b )
#define MIN(a, b) ( (a < b ) ? a : b )

void swap(int* a, int *b){
  *a ^= *b;
  *b ^= *a;
  *a ^= *b;
}

int main(){
  // Test IO
  ios::sync_with_stdio(false);
  int n, temp;
  cin >> n;
  vector<int> v;

  while(n--){
    cin >> temp;
    v.push_back(temp);
  }

  std::sort(v.begin(), v.end());
  cout << v[0];
  int i = 1;
  int j = v.size()-1;
  while (j-i > 0){
    cout << " " << v[j] << " " << v[i];
    ++i;
    --j;
    if (j == i){ cout << " " << v[i]; break;}
  }
  cout << endl;
  return 0;
}
