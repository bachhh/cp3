#include <bits/stdc++.h>

using namespace std;
const double pi = acos(-1.0);

typedef long int int32; typedef long long int int64;
typedef unsigned long int uint32; typedef unsigned long long int uint64;
typedef pair<int, int> ii; typedef vector<ii> vii; typedef vector<int> vi;
typedef tuple<int, int, int> iii;
typedef tuple<int, int, int, int> iiii;
typedef vector<vi> vvi;

#define PI 3.1415926535897932384626433832795
#define VISITED 1
#define UNVISITED -1
#define EXPLORED 2
#define FLOAT_EPSILON 1e-6

#define FOREACH(it, l) for (auto it = l.begin(); it != l.end(); it++)
#define MAX(a, b) ( (a > b ) ? a : b )
#define MIN(a, b) ( (a < b ) ? a : b )

#define LIMIT 20000

//  ***** MAIN *****
int main(){
  ios::sync_with_stdio(false);
  cin.tie(NULL);

  int m, n, s, t, x, y, z;
  int tc; cin >> tc;

  int64 d[LIMIT];
  vector<vii> adjList;

  for(int cn = 1; cn <= tc; ++cn ){
    cin >> n >> m >> s >> t;

    adjList.clear();
    for (int i = 0; i < n; ++i){
      adjList.push_back(vii {});
      d[i] = INT_MAX-100;
    }
    d[s] = 0;

    for (int i = 0; i < m; ++i) {
      cin >> x >> y >> z;
      adjList[x].push_back(ii {y,z});
      adjList[y].push_back(ii {x,z});
    }

    priority_queue<ii, vector<ii>, greater<ii>> q; q.push(ii {0, s});

    while(!q.empty()){
      ii f = q.top();q.pop();
      int u = f.second;
      if(f.first> d[u]) continue;
      for (auto p : adjList[u]) {
        int neighbor = p.first;
        int weight = p.second;
        if (d[neighbor] > d[u] + weight){
          d[neighbor] = d[u] + weight;
          q.push(ii{d[neighbor], neighbor});
        }
      }
    }

    if (d[t] < INT_MAX-110) printf("Case #%d: %lld\n", cn, d[t]);
    else printf("Case #%d: unreachable\n", cn);
  }


  return 0;
}
