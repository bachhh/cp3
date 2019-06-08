#include <bits/stdc++.h>

using namespace std;
typedef long int int32;
typedef long long int int64;
typedef unsigned long int uint32;
typedef unsigned long long int uint64;
typedef pair<int, int> ii;
typedef vector<pair<int, int>> V_ii;
const double pi = acos(-1.0);

#define PI 3.1415926535897932384626433832795
#define INF (int)1e9
#define FOREACH(it, l) for (auto it = l.begin(); it != l.end(); it++)
#define LOOP(i, n) for (int i = 0; i < n; ++i)
#define MAX(a, b) ( (a > b ) ? a : b )
#define MIN(a, b) ( (a < b ) ? a : b )

void swap(int64* a, int64* b){
  *a ^= *b;
  *b ^= *a;
  *a ^= *b;
}


//  ***** MAIN *****
int main(){
  ios::sync_with_stdio(false);
  cin.tie(NULL);

  int n, q;
  int x[100000];
  int m;

  cin >> n;
  LOOP(i, n){
    cin >> x[i];
  }
  sort(x, x+n);

  int low, high, mid;
  cin >> q;
  LOOP(i, q){
    cin >> m;
    low = 0;
    high = n-1;
    while(low < high){
      mid = low + (high - low + 1)/2;
      if (x[mid] > m){
        high = mid-1;
      }
      else{
        low = mid;
      }
    }
    if (x[low] > m) cout << low << endl;
    else cout << low + 1 << endl;
  }

  return 0;
}

