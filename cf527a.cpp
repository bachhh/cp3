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
#define LOOP(n) for (int z = 0; z < n; ++z)
#define MAX(a, b) ( (a > b ) ? a : b )
#define MIN(a, b) ( (a < b ) ? a : b )
#define FLOAT_PRECISION 1e-8

void swap(int64* a, int64* b){
  *a ^= *b;
  *b ^= *a;
  *a ^= *b;
}


//  ***** MAIN *****
int main(){
  ios::sync_with_stdio(false);
  cin.tie(NULL);

  int64 a, b;
  cin >> a >> b;
  int64 count = 0;
  while(a != 0 && b != 0){
    count += a/b;
    a = a%b;
    if(b > a){
      swap(&a, &b);
    }
  }
  cout << count << endl;

  return 0;
}

