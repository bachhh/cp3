#include <bits/stdc++.h>

using namespace std;
const double pi = acos(-1.0);

typedef long int int32;
typedef long long int int64;
typedef unsigned long int uint32;
typedef unsigned long long int uint64;
typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef vector<int> vi;

#define INF (int)1e9
#define PI 3.1415926535897932384626433832795
#define VISITED 1
#define UNVISITED -1

#define FOREACH(it, l) for (auto it = l.begin(); it != l.end(); it++)
#define LOOP(i, n) for (int i = 0; i < n; ++i)
#define MAX(a, b) ( (a > b ) ? a : b )
#define MIN(a, b) ( (a < b ) ? a : b )


void swap(int32* a, int32* b){
  *a ^= *b;
  *b ^= *a;
  *a ^= *b;
}

// Adjacency List contain only 1 memeber
int AL[50000];
int dfs_flag[50000];
int dfs_count[50000];

int max_count;
int max_node;

int dfs(int u){
  dfs_flag[u] = VISITED;
  int r;
  if (dfs_flag[AL[u]] == UNVISITED){
    r = dfs(AL[u]) + 1;
  }
  else {
    r = 1;
  }
  dfs_count[u] = r;
  dfs_flag[u] = UNVISITED;
  return r;
}

//  ***** MAIN *****
int main(){
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  int tc, output, n, h, v, max_count, max_node, temp;

  cin >> tc;
  for(int c= 1; c<= tc; ++c){
    cin >> n;
    LOOP(i,n){
      AL[i] = -1;
      dfs_flag[i] = UNVISITED;
      dfs_count[i] = 0;
    }


    for(int i = 0; i < n; ++i){
      cin >> h >> v;
      AL[h-1] = v-1;
    }

    max_count = 0;
    for(int i = 0; i < n; ++i){
      if (dfs_count[i] == 0){
        dfs(i);
      }
      if ( dfs_count[i] > max_count){
        max_count = dfs_count[i];
        output = i;
      }
    }

    printf("Case %d: %d\n", c, output+1);
  }

  return 0;
}

