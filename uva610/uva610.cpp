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

vvi al;
int dfs_num[1001];
int dfs_low[1001];
int dfs_parents[1001];
int n, m;
int dfsCounter;

void dfsPoints(int u){
  dfs_num[u] = dfs_low[u] = dfsCounter;
  dfsCounter++;
  for(int neighbor : al[u]){
    if(dfs_num[neighbor] == UNVISITED ){
      dfs_parents[neighbor] = u;

      dfsPoints(neighbor);
      // It's a bridge
      if (dfs_low[neighbor] > dfs_num[u]){
        printf("%d %d\n", u, neighbor);
        printf("%d %d\n", neighbor, u);
      }
      else{
      // Not a bridge
        printf("%d %d\n", u, neighbor);
      }
    dfs_low[u] = MIN(dfs_low[u], dfs_low[neighbor]);
    }
    else if( neighbor != dfs_parents[u]){
      if (dfs_num[neighbor] < dfs_num[u])
        printf("%d %d\n", u, neighbor);
      dfs_low[u] = MIN(dfs_low[u], dfs_num[neighbor]);
    }
  }
}

//  ***** MAIN *****
int main(){
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  string s;
  int case_no = 1;
  int a, b;

  while(cin >> n >> m && n != 0){
    printf("%d\n\n", case_no++);

    al.clear();
    dfsCounter = 0;

    LOOP(i, n+1){
      al.push_back(vi {});
      dfs_num[i] = UNVISITED;
      dfs_low[i] = UNVISITED;
      dfs_parents[i] = 0;
    }
    LOOP(i, m){
      cin >> a >> b;
      al[a].push_back(b);
      al[b].push_back(a);
    }
    dfsCounter = 0;
    dfsPoints(1);
    printf("#\n");
  }

    return 0;
}

