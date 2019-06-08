#include <bits/stdc++.h>

using namespace std;
const double pi = acos(-1.0);

typedef long int int32; typedef long long int int64;
typedef unsigned long int uint32; typedef unsigned long long int uint64;
typedef pair<int, int> ii; typedef vector<ii> vii; typedef vector<int> vi;
typedef tuple<int, int, int> iii; typedef tuple<int, int, int, int> iiii;
typedef vector<vi> vvi;

#define MAX(a, b) ( (a > b ) ? a : b )
#define MIN(a, b) ( (a < b ) ? a : b )

#define LIMIT 100

//  ***** MAIN *****
int main(){
  ios::sync_with_stdio(false);
  cin.tie(NULL);

  int n, e, t, m, x, y, z;
  int tc; cin >> tc;

  vector<vii> adjList;
  while(tc--){

    adjList.clear();

    cin >> n >> e >> t >> m;

    for (int i = 0; i < n; ++i) {
      adjList.push_back(vii {});
    }

    for (int i = 0; i < m; ++i) {
      cin >> y >> x >> z;
      adjList[x-1].push_back(ii(y-1, z));
    }

    vector<int> d(n, 1000000000);
    priority_queue<ii, vector<ii>, greater<ii>> q;

    d[e-1] = 0;
    q.push(ii(0, e-1));
    while(!q.empty()){
      ii f = q.top(); q.pop();
      int u = f.second;

      if (f.first > d[u]) continue;

      for(auto p : adjList[u]){
        int v = p.first;
        if(d[v] > d[u] + p.second){
          d[v] = d[u] + p.second;
          q.push(ii(d[v], v));
        }
      }

    }

    int counter = 0;
    for(int i = 0; i < n; ++i){
      if(d[i] <= t) counter++;
    }
    std::cout << counter << "\n";
    if (tc > 0) std::cout << std::endl;
  }


  return 0;
}
