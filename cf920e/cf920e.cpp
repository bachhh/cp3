#include <bits/stdc++.h>

using namespace std;

#define LIMIT 200006

int state[200000];

vector<vector<int>> al;

int dfs(int v ){
  if (state[v] == -1) return 0;
  state[v] = -1;

  for (int i = 0; i < al[v].size(); i++) {
  }


}



//  ***** MAIN *****
int main(){
  //ios::sync_with_stdio(false);
  cin.tie(NULL);
  int n, m;

  cin >> n >> m;
  al.resize(n);
  int x, y;
  memset(state, -1, sizeof(int)*200000);
  for (int i = 0; i < m; i++) {
    cin >> x >> y;
    x--;y--;
    al[x].push_back(y);
    al[y].push_back(x);
  }
  vector<int> v;
  for (int i = 0; i < n; i++) {
    if (state[i] == -1){
      v.push_back(dfs(i));
    }
  }



  return 0;
}

