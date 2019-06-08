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

#define LIMIT 1000

// @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
// I'm just being lazy
// @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@

void relax(int vx, int vy, int ux, int uy, int d[][LIMIT], int w[][LIMIT]){
  // w(u, v) = w[vx][vy]
  d[vx][vy] = MIN(d[ux][uy] + w[vx][vy], d[vx][vy]);
}

class Compare
{
public:
  bool operator() (const iii a, const iii b) const{
    if (get<2>(a) < get<2>(b)) return true;
    if (get<2>(a) > get<2>(b)) return false;
    if (get<0>(a) < get<0>(b)) return true;
    if (get<0>(a) > get<0>(b)) return false;
    if (get<1>(a) < get<1>(b)) return true;
    if (get<1>(a) > get<1>(b)) return false;
    return true;
  }
};
//  ***** MAIN *****
int main(){
  ios::sync_with_stdio(false);
  cin.tie(NULL);

  int m, n;
  int w[LIMIT][LIMIT];
  int d[LIMIT][LIMIT];
  int dx[4] ={1,0,-1,0};
  int dy[4] ={0,1,0,-1};

  int tc; cin >> tc;
  while(tc--){
    cin >> m >> n;
    for (int i = 0; i < m; ++i) {
      for (int j = 0; j < n; ++j) {
        cin >> w[i][j];
        d[i][j] = 100000;
      }
    }
    d[0][0] = w[0][0];
    int adjx, adjy;

    /*
    // Bellman Ford
    for (int i = 0; i < m*n; ++i) {
      for (int x = 0; x < m; ++x) {
        for (int y = 0; y < n; ++y) {
          for (int change = 0;  change < 4; ++ change) {
            adjx = x+dx[change];
            adjy = y+dy[change];
            if(adjx < 0 || adjy < 0 || adjx >m-1 || adjy>n-1)continue;
            else{
              relax(x, y, adjx, adjy, d, w);
            }
          }
        }
      }
    }
    */
    int counter = 0;

    // Dijkstra with parallel queuing
    vector<priority_queue<iii, vector<iii>, Compare>> v;
    for (int i = 0; i < 10; ++i) {
      v.push_back( priority_queue<iii, vector<iii>, Compare>() );
    }
    priority_queue<iii, vector<iii>, Compare> q;

    v[w[0][0]].push(iii {0, 0, w[0][0]});

    int i = 0;
    counter = 0;
    while(counter<10){
      if(!v[i].empty()){
        counter = 0;
        iii f = v[i].top(); v[i].pop();

        int ux = get<0>(f), uy = get<1>(f);

        if (get<2>(f) > d[ux][uy]) continue;

        for (int change = 0; change < 4; ++change) {
          int vx = ux+dx[change];
          int vy = uy+dy[change];
          if(vx < 0 || vy < 0 || vx > m-1 || vy > n-1)continue;
          else if(d[vx][vy] > d[ux][uy] + w[vx][vy]){
            d[vx][vy] = d[ux][uy] + w[vx][vy];
            v[ (i + w[vx][vy])%10 ].push(iii(vx,vy,d[vx][vy]));
          }
        }
      }
      i = (i+1)%10;
      counter++;
    }

    std::cout << d[m-1][n-1] << "\n";
  }
  return 0;
}
