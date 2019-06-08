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

  int n, m, a, b;
  vector< vector<int> > AL;
  map<int, set<int> > q_k;
  int color[100001];

  cin >> n >> m;
  for(int i = 0; i < n; ++i){
    cin >> color[i];
    q_k[color[i]].insert(color[i]);
  }
  for(int edge = 0; edge < m; ++edge){
    cin >> a >> b;
    q_k[color[a-1]].insert(color[b-1]);
    q_k[color[b-1]].insert(color[a-1]);
  }

  int max_q_k = 0;
  int max_color = 10001;
  for(map<int, set<int>>::iterator it = q_k.begin(); it != q_k.end(); ++it){
    if ( (it->second).size() > max_q_k ){
      max_q_k = (it->second).size();
      max_color = it->first;
    }
    else if ( (it->second).size() == max_q_k && it->first < max_color){
      max_color = it->first;
    }
  }

  cout << max_color << endl;
  return 0;
}

