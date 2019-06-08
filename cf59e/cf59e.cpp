#include <bits/stdc++.h>

using namespace std;

#define LIMIT 100
typedef pair<int, int> ii;
typedef int64_t ll;

int n, m, k;
vector<vector<int>> al;

//  ***** MAIN *****
int main(){


  //ios::sync_with_stdio(false);
  cin.tie(NULL);

  cin >> n >> m >> k;
  al = vector<vector<int>> (n, vector<int>());
  int x, y;

  for (int i = 0; i < m; ++i) {
    cin >> x >> y;
    al[x-1].push_back(y-1);
    al[y-1].push_back(x-1);
  }

  set<iii
  static int parent[3000][3000];


  memset(parent, -1, sizeof(parent[0]) * 3000 );
  memset(avoid, -1, sizeof(avoid[0][0]) * 3000 * 3000 );

  int a, b, c;
  for (int i = 0; i < k; ++i) {
    cin >> a >> b >> c;
    avoid[a-1][b-1] = c-1;
  }

  queue<ii> qu;

  while(!qu.empty()){
    ii p = qu.front(); qu.pop();
    int prev = p.first;
    int cur = p.second;

    for (int i : al[cur]) {
    }
  }

  parent[0] = 0;

  vector<int> path;
  int cur = n-1;

  while(cur > 0 ){
    path.push_back(cur);
    cur = parent[cur];
    //std::cout << cur << std::endl;
  }

  if(parent[path.back()] != 0 ){
    std::cout << -1 << std::endl;
  }
  else {
    std::cout << path.size() << std::endl;
    cout << 1 << " ";
    for(int i = path.size()-1; i >= 0; --i){
      cout << path[i]+1 << " \n"[i==0];
    }
  }


  return 0;
}

