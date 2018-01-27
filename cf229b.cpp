#include <bits/stdc++.h>

using namespace std;

#define LIMIT 100
#define INF 1e9

typedef tuple<int64_t, int64_t, int64_t> iii;
typedef pair<int64_t, int64_t> ii;
typedef vector<vector<int64_t>> vvi;

int64_t findNextTime(vvi busy, vvi avai, int64_t t, int ver){
  auto it = lower_bound(busy[ver].begin(), busy[ver].end(), t);
  if (it == busy[ver].end()){
    return t;
  }
  return avai[ver][it - busy[ver].begin()];
}

//  ***** MAIN *****
int main(){
  //ios::sync_with_stdio(false);
  cin.tie(NULL);

  int n, m;
  cin >> n >> m;

  vector<vector<ii>> AL(n, vector<ii>());
  vector<vector<int64_t>> avai(n,vector<int64_t>(n));
  vector<vector<int64_t>> busy(n,vector<int64_t>(n));
  vector<int> dist(n, INF);

  priority_queue<ii, vector<ii>, greater<ii>> pq;
  int64_t x, y , w;

  for (int i = 0; i < m; i++) {
    cin >> x >> y >> w;
    AL[x-1].push_back(ii(y-1, w));
    AL[y-1].push_back(ii(x-1, w));
  }

  int64_t k, t;
  for (int i = 0; i < n; i++) {
    cin >> k;
    for (int j = 0; j < k; j++) {
      cin >> busy[i][j];
    }
    // nice memoization tricks
    avai[i][k-1] = busy[i][k-1] +1;
    for (int j = n-2; j>= 0; --j) {
      if (busy[i][j]+1 == busy[i][j+1]){
        avai[i][j] = avai[i][j+1];
      }
      else {
        avai[i][j] = busy[i][j]+1;
      }
    }
  }

  int wait1 = findNextTime(busy, avai, 0, 0);
  for (ii p : AL[0]) { pq.push(ii(p.second, p.first+wait1)); }

  while(!pq.empty()){
    ii front = pq.top(); pq.pop();
    int64_t d = front.first, u = front.second;
    if (d > dist[u]) continue;

    int64_t depart = dist[u] + findNextTime(busy, avai,d, u);
    for (ii p : AL[u]) {
      int64_t arrive = depart + p.second;
      if ( arrive < dist[p.first] ){
        dist[p.first] = arrive;
        pq.push(ii(dist[p.first], p.first));
      }
    }
    if (dist[n-1] >= INF){
      std::cout << -1 << std::endl;
    }
    else {
      std::cout << dist[n-1] << std::endl;
    }
  }

  return 0;
}

