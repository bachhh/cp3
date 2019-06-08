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
#define INF INT_MAX/2

#define LIMIT 100

int t[5];
int d[100][5];
bool matrix[100][5];

int w(int f1, int l1, int f2, int l2){
  if (f1==f2) return 1;
  if (l1 == l2) return t[l1];
  return INF;
}

//  ***** MAIN *****
int main(){
  //ios::sync_with_stdio(false);
  //cin.tie(NULL);

  int n, k;
  string temp;

  // State space will be (floor, lift)
  while(cin >> n >> k){
    // Elevator speed input
    for (int i = 0; i < n; ++i) {
      cin >> t[i];
    }

    for (int i = 0; i < LIMIT; ++i) {
      for (int j = 0; j < 5; ++j) {
        matrix[i][j] = false;
        d[i][j] = INF;
      }
    }

    // queue of <distance, floor, lift>
    priority_queue<iii, vector<iii>, greater<iii> > q;

    getchar();
    for (int lift = 0; lift < n; ++lift) {
      getline(cin, temp); stringstream ss(temp);
      int nf;
      while(ss >> nf){
        if (ss.peek() == ' ') ss.ignore();
        if (nf == 0){
          d[nf][lift] = 0;
          q.push(iii(0, nf, lift));
        }
        matrix[nf][lift] = true;
      }
    }

    iii triplet;
    while(!q.empty()){
      triplet = q.top(); q.pop();
      int curfloor = get<1>(triplet);
      int curlift = get<2>(triplet);
      if(get<0>(triplet) > d[curfloor][curlift]) continue;


      // Consider above and below foor
      int above, below;
      for(above = curfloor+1; above < 100 && !matrix[above][curlift]; ++above);
      for(below = curfloor-1; below >-1 && !matrix[below][curlift]; --below);
      if(above < 100){
        if (d[above][curlift] > d[curfloor][curlift] + (above-curfloor)*t[curlift]){
          d[above][curlift] = d[curfloor][curlift] + (above-curfloor)*t[curlift];
          q.push(iii {d[above][curlift], above, curlift});
        }
      }
      if(below > -1){
        if (d[below][curlift] > d[curfloor][curlift] + (curfloor-below)*t[curlift]){
          d[below][curlift] = d[curfloor][curlift] + (curfloor-below)*t[curlift];
          q.push(iii {d[below][curlift], below, curlift});
        }
      }

      // Consider switching lift
      for (int nextlift = 0; nextlift < 5; ++nextlift) {
        if (  matrix[curfloor][nextlift]  &&
              nextlift != curlift         &&
              d[curfloor][nextlift] > d[curfloor][curlift] + 60){
          d[curfloor][nextlift] = d[curfloor][curlift] + 60;
          q.push(iii {d[curfloor][nextlift], curfloor, nextlift });
        }
      }
    }

    int min_time = INF;
    for (int i = 0; i < n; ++i) {
      min_time = MIN(min_time, d[k][i]);
    }
    if (min_time < INF)std::cout << min_time << std::endl;
    else std::cout << "IMPOSSIBLE" << std::endl;

  }
  return 0;
}
