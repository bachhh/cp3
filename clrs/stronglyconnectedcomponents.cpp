#include <bits/stdc++.h>

using namespace std;
const double pi = acos(-1.0);

typedef long int int32; typedef long long int int64;
typedef unsigned long int uint32; typedef unsigned long long int uint64;
typedef pair<int, int> ii; typedef vector<ii> vii; typedef vector<int> vi;
typedef vector<vi> vvi;

#define INF (int)1e9
#define PI 3.1415926535897932384626433832795
#define VISITED 1
#define UNVISITED -1
#define FLOAT_EPSILON 1e-6

#define FOREACH(it, l) for (auto it = l.begin(); it != l.end(); it++)
#define LOOP(i, n) for (int i = 0; i < n; ++i)
#define MAX(a, b) ( (a > b ) ? a : b )
#define MIN(a, b) ( (a < b ) ? a : b )
#define DEBUG(x) cerr << #x << " is " << x << endl;


int n, r;
vvi al;
int dfs_num[200];
int dfs_low[200];
bool isInTree[200];
map<string, int> s_i;
map<int, string> i_s;
int dfsCounter, sccCount;
stack<int> s;

void tarjan( int u){
  dfs_low[u] = dfs_num[u] = dfsCounter;
  dfsCounter++;

  // This boolean is to check if the vertex u is reachable in
  // this one recursion run of dfs
  isInTree[u] = true;
  s.push(u);
  for(int neighbor : al[u]){
    if(dfs_num[neighbor] == UNVISITED){
      tarjan(neighbor);;
    }
    // You don't want to update u based on dfs_low of other dfs tree
    if(isInTree[neighbor] == true) {
      dfs_low[u] = MIN(dfs_low[u], dfs_low[neighbor]);
    }
  }
  // Let recursion backtrack to the root node of the cycle
  if(dfs_low[u] == dfs_num[u]){
    sccCount++;
    // Reset the status of spanning tree
    int v = -1;
    do {
      v = s.top(); s.pop();
      isInTree[v] = false;
    }while(v!= u);
  }
}

//  ***** MAIN *****
int main(){
  //ios::sync_with_stdio(false);
  cin.tie(NULL);
  int p, t;
  string s, a, b;
  while( cin >> p >> t && p != 0){

    sccCount = 0; dfsCounter = 0;
    getline(cin, s);
    al.clear(); s_i.clear(); i_s.clear();
    LOOP(i, p){
      getline(cin, s);
      al.push_back(vi {});
      s_i[s] = i; i_s[i] = s;
      dfs_num[i] = UNVISITED; dfs_low[i] = UNVISITED; isInTree[i] = false;
    }

    LOOP(i, t){
      getline(cin, a); getline(cin, b);
      al[s_i[a]].push_back(s_i[b]);
    }
    for(int i  = 0; i < p; ++i){
      if (dfs_num[i] == UNVISITED){
        tarjan(i);
      }
    }
    cout << sccCount << endl;
  }

  return 0;
}

