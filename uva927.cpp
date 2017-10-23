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

uint64 generateA(vector<int> coef, int index){
  uint64 a = 0;
  for(int i =0; i < coef.size(); ++i){
    a += coef[i]*pow(index, i);
  }
  return a;
}

//  ***** MAIN *****
int main(){
  ios::sync_with_stdio(false);
  int tc; cin >> tc;

  int i, d, k, ci, n;
  while(tc--){
    vector<int> coef;
    cin >> i; i++;
    while(i--){
      cin >> ci;
      coef.push_back(ci);
    }
    cin >> d;
    cin >> k;
    i=0; n=0;
    while(i < k){
      n++;
      i += n*d;
    }
    cout << generateA(coef, n) << endl;
  }
  return 0;
}

