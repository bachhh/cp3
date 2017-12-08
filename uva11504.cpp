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
#define EXPLORED 2
#define FLOAT_EPSILON 1e-6

#define FOREACH(it, l) for (auto it = l.begin(); it != l.end(); it++)
#define LOOP(i, n) for (int i = 0; i < n; ++i)
#define MAX(a, b) ( (a > b ) ? a : b )
#define MIN(a, b) ( (a < b ) ? a : b )
#define DEBUG(x) cerr << #x << " is " << x << endl;


int n, r;
vvi al;
vvi al_t;
int dfs_num[100001];
int dfs_low[100001];
int dfs_parents[100001];
bool isVisited[100001];
int inEdge[100001];
int dfsCounter, sccCount;
vector<int> scc_nodes;
stack<int> s;

void dfs(int u ){
  if(dfs_num[u] != UNVISITED ) return;
  dfs_num[u] = EXPLORED;
  for(auto neighbor : al[u]){
    if (dfs_num[neighbor] == UNVISITED){
      dfs(neighbor);
    }
  }
  dfs_num[u] = VISITED;
  s.push(u);
}

//  ***** MAIN *****
int main(){
  //ios::sync_with_stdio(false);
  cin.tie(NULL);
  int tc, n, m, x, y;
  cin >> tc;
  int counter;
  while(tc--){
    cin >> n >> m;

    al.clear();
    while(!s.empty()) s.pop();

    LOOP(i, n+1){
      al.push_back(vi {});
      dfs_num[i] = UNVISITED;
    }

    LOOP(i, m){
      cin >> x >> y;
      al[x].push_back(y);
    }

    for(int i = 1; i <= n; ++i){
      if(dfs_num[i] == UNVISITED){
        dfs(i);
      }
    }

    LOOP(i, n+1){
      dfs_num[i] = UNVISITED;
    }
    int counter = 0;
    while(!s.empty()){
      int i = s.top(); s.pop();
      if (dfs_num[i] == UNVISITED){
        counter++;
        dfs(i);
      }
    }
    cout << counter << endl;
  }

  return 0;
}

