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
  // ios::sync_with_stdio(false);
  int64 n, temp;
  cin >> n;
  int v[600000];

  for(int i= 0; i < n; ++i){
    cin >> v[i];
  }

  int q, l , r, m;
  int64 mi, ma;
  cin >> q;

  for(int i = 0; i < q; ++i){
    cin >> temp;
    l = 0; r = n-1; m = (l+r)/2;
    while(temp != v[m] && l <= r){
      if ( temp < v[m]){
        r = m-1;
      }
      else if (temp > v[m]){
        l = m + 1;
      }
      m = (l+r)/2;
    }

    l = m; r = m;
    if (v[m] == temp){

      while( l > 0 && v[l] == v[l-1] ) l--;
      while( r < n-1 && v[r] == v[r+1]) r++;
      mi = (l>0)? (v[l-1]) : -1;
      ma = (r<n-1)? (v[r+1]) : -1;
    }

    else if(v[m] < temp){
      mi = v[m];
      while( r < n-1 && v[r] == v[r+1] ) r++;
      ma = (r<n-1)? (v[r+1]) : -1;
    }
    else if (v[m] > temp){
      ma = v[m];
      while( l > 0 && v[l] == v[l-1]) l--;
      mi = (l>0) ? (v[l-1]) : -1;
    }

    if (mi > 0) cout << mi;
    else cout << 'X';
    cout << " ";
    if (ma > 0) cout << ma;
    else  cout << 'X';
    cout << endl;
  }

  return 0;
}

