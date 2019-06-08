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

int dfs(int u){
  int r = 0;
  for(int i = 0; i < AL[u].size(); ++i){
    r = MAX(r, dfs(AL[u][i]));
  }

  return r+1;
}

//  ***** MAIN *****
int main(){
  ios::sync_with_stdio(false);
  cin.tie(NULL);

  int n, p;
  cin >> n;
  LOOP(i, n){
    AL.push_back(vi {} );
  }

  for(int i = 0; i < n; ++i){
    cin >> p;
    if (p != -1){
      AL[p-1].push_back(i);
    }
  }
  int g = 0;
  for(int i = 0; i < n;++i){
    g = MAX(g, dfs(i));
  }
  cout << g << endl;

  return 0;
}

