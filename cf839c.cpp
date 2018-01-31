#include <bits/stdc++.h>

using namespace std;

#define LIMIT 100
#define EPS 1e-6

#define VISITED 1
#define UNVISITED -1

vector<vector<int>> al;
int state[100000];
int64_t total;

int dfs(int i, int depth){
  if(state[i] == VISITED) return 0;

  state[i] = VISITED;

  int child = 0;
  for (int neighbor : al[i]) {
    if(state[neighbor] == UNVISITED){
      child += dfs(neighbor, depth+1);
    }
  }
  // if we hit a deadend
  if(child == 0){
    total += depth;
    return 1;
  }

  return child;
}

//  ***** MAIN *****
int main(){
  //ios::sync_with_stdio(false);
  cin.tie(NULL);
  int n;
  cin >> n;
  int x, y;
  total = 0;

  al.resize(n);
  for (int i = 0; i < n; i++) {
    state[i] = UNVISITED;
  }

  for (int i = 0; i < n-1; i++) {
    cin >> x >> y;
    al[x-1].push_back(y-1);
    al[y-1].push_back(x-1);
  }

  if (n == 1){
    return std::cout << 0 << std::endl, 0;
  }
  double deno = dfs(0, 0);
  //std::cout << deno << std::endl;
  printf("%.12f\n", total/deno);

  return 0;
}

