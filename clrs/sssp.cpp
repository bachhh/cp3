#include <bits/stdc++.h>

using namespace std;
const double pi = acos(-1.0);

typedef long int int32; typedef long long int int64;
typedef unsigned long int uint32; typedef unsigned long long int uint64;
typedef pair<int, int> ii; typedef vector<ii> vii; typedef vector<int> vi;
typedef tuple<int, int, int> iii;
typedef vector<vi> vvi;

#define PI 3.1415926535897932384626433832795
#define VISITED 1
#define UNVISITED -1
#define EXPLORED 2
#define FLOAT_EPSILON 1e-6

#define FOREACH(it, l) for (auto it = l.begin(); it != l.end(); it++)

#define MAX(a, b) ( (a > b ) ? a : b )
#define MIN(a, b) ( (a < b ) ? a : b )
#define DEBUG(x) cerr << #x << " is " << x << endl;

#define LIMIT 100

void swap(int* a, int* b){
  *a ^= *b;
  *b ^= *a;
  *a ^= *b;
}

int p[LIMIT] = {-1};
int d[LIMIT];
int s, n;
vvi am;
vector<vii> al;

void Relax(int u, int v){
  if(d[v] > d[u] + am[u][v]){
    d[v] = d[u] + am[u][v];
    p[v] = u;
  }
}

bool BellManFord(int s){
  for (int i = 0; i < n; ++i) {
    p[i] = -1;
    d[i] = INT_MAX;
  }
  d[s] = 0;

  for (int node = 1; node < n; node++) {
    for (int i = 0; i < n; ++i) {
      for (int j = 0; j < n; j++) {
        if( i != j && am[i][j] < INT_MAX ){
          Relax(i, j);
        }
      }
    }
  }
  for(int i = 0; i < n; ++i){
    for(int j = 0; j < n; ++j){
      if( i != j && d[i] > d[j] + am[i][j]){
        return false;
      }
    }
  }
  return true;
}


priority_queue<ii, vector<ii>,  greater<ii> > pq;
void Dijkstra(int s){
  for (int i = 0; i < n; ++i) {
    if (i != s){
      p[i] = -1;
      pq.push({i, INT_MAX});
      d[i] = INT_MAX;
    }
  }
  pq.push({s, 0});
  d[s] = 0;
  while(!pq.empty()){
    int u = pq.top().first;
    int u_d = pq.top().second;
    pq.pop();
    for(auto pii : al[u]){
      int v = pii.first;
      int v_u = pii.second;
      if (d[v] > u_d + v_u){
        d[v] = u_d + v_u;
        p[v] = u;
        pq.push({d[v], v});
      }
    }
  }
}

//  ***** MAIN *****
int main(){
  //ios::sync_with_stdio(false);
  cin.tie(NULL);
  return 0;
}

