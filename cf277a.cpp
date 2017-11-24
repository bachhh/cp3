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


vector<vi> AL;
// vector of language of employee
vector<vi> lang;
int dfs_flag[101];

void dfs(int u){
  dfs_flag[u] = VISITED;
  for(int i = 0; i < AL[u].size(); ++i){
    if (dfs_flag[AL[u][i]] == UNVISITED){
      dfs(AL[u][i]);
    }
  }
}

//  ***** MAIN *****
int main(){
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  int n, m, k, a;

  cin >> n >> m;
  for(int i = 0; i < m; ++i){
    lang.push_back(vi {});
  }
  for(int i = 0; i < n; ++i){
    dfs_flag[i] = UNVISITED;
    AL.push_back(vi {});
  }
  bool flag = false;
  for(int employee = 0; employee < n; ++employee){
    cin >> k;
    for(int j = 0; j < k; ++j){
      cin >> a;
      // At least 1 language exist
      flag = true;
      lang[a-1].push_back(employee);
    }
  }

  for(int a = 0; a < m; ++a){
    for(int e = 0; e < lang[a].size(); ++e){
      for(int other = e; other < lang[a].size(); ++other){
        AL[lang[a][e]].push_back(lang[a][other]);
        AL[lang[a][other]].push_back(lang[a][e]);
      }
    }
  }

  int output = -1;
  for(int node = 0; node < n; ++node){
    if(dfs_flag[node] == UNVISITED){
      output++;
      dfs(node);
    }
  }
  if (flag){
    cout << output << endl;
  }
  else {
    cout << output+1 << endl;
  }

  return 0;
}

