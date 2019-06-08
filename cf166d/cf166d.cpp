#include <bits/stdc++.h>

using namespace std;

#define LIMIT 100
typedef pair<int64_t, int64_t> ii;


vector<ii> dl;
vector<int64_t> cost(1000000001, -1);

int64_t solve(int i, bool thisisze, bool nextsize){
  int64_t budget = dl[i].first;
  int64_t size = dl[i].second;

  // Sell him this shoes
  if (cost[size] > -1){
    int64_t option1 = cost[size] + solve(i+1, false,  true);
  }

  // Sell him shoes of size+1
  int64_t option2 = ;

  // Not do not sell him anything
  int64_t option3 = ;
}

//  ***** MAIN *****
int main(){

  //ios::sync_with_stdio(false);
  cin.tie(NULL);

  int n; cin >> n;
  vector<ii> cs(n);


  int64_t c, s;
  for (int i = 0; i < n; ++i) {
    cin >> c >> s;
    cost[s] = c;
  }

  int m; cin >> m;
  dl.resize(m);

  for (int i = 0; i <m ; ++i) {
    cin >> dl[i].first >> dl[i].second;
  }

  sort(dl.begin(), dl.end(),
      [ ] (ii a, ii b) {
        return a.second > b.second;
      }
      );

  return 0;
}

