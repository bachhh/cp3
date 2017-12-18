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
#define LIMIT 1002
#define INF INT_MAX


//  ***** MAIN *****
int main(){
  //ios::sync_with_stdio(false);
  //cin.tie(NULL);

  int l, u, temp;
  int r;
  int cn = 0;
  while(cin >> l >> u >> r && r && ++cn){

    vector<int> buttons;
    vector<int> dist(10000, INF - 10);

    for (int i = 0; i < r; ++i) {
      cin >> temp;
      buttons.push_back(temp);
    }
    priority_queue<ii, vector<ii>, greater<ii>> q;
    q.push(ii(0, l));
    dist[l] = 0;

    ii f;
    while(!q.empty()){
      f = q.top(); q.pop();
      int x = f.second;
      int d = f.first;
      if (d > dist[x]) continue;
      for (int i : buttons) {
        int v = (x+i)%10000;
        if (dist[v] > dist[x] + 1){
          dist[v] = dist[x] +1;
          q.push(ii(dist[v], v));
        }
      }
    }
    printf("Case %d: ", cn);
    if(dist[u] < INT_MAX-10){ std::cout << dist[u] << std::endl; }
    else std::cout << "Permanently Locked" << std::endl;
  }

  return 0;
}
