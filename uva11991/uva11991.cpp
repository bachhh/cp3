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

void swap(int* a, int *b){
  *a ^= *b;
  *b ^= *a;
  *a ^= *b;
}


//  ***** MAIN *****
int main(){
  ios::sync_with_stdio(false);
  cin.tie(NULL);

  int m, n, temp, k, v;
  map<int, vector<int>> ma;

  while(cin >> n >> m){
    ma.clear();
    for(int i = 1; i <= n; ++i){
      cin >> temp;
      if (ma.find(temp) != ma.end()){
        ma[temp].push_back(i);
      }
      else {
        ma[temp] = {i};
      }
    }

    for(int i = 0; i < m; i++){
      cin >> k >> v;
      if (ma.find(v) != ma.end() && k <= ma[v].size() ){
        cout << ma[v][k-1] << endl;
      }
      else {
        cout << 0 << endl;
      }
    }
  }

  return 0;
}

