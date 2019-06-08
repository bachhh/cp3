#include <bits/stdc++.h>

using namespace std;

#define LIMIT 1003

int memo[1000][34];

int recurse(int* v, int* w, int n, int id, int remW){
  if(remW == 0) return 0;
  if (id >= n) return 0;
  if(w[id] > remW) return recurse(v, w, n, id+1, remW);

  if (w[id] <= remW){
    if (memo[id][remW] > -1) return memo[id][remW];
    memo[id][remW] = max( recurse(v, w, n, id+1, remW),
        v[id] + recurse(v, w, n, id+1, remW-w[id]));
    return memo[id][remW];
  }
}

int solve(int maxw, int *v, int *w, int n){
  for (int i = 0; i < n; i++) {
    for (int j = 0; j <= maxw; j++) { memo[i][j] = -1; }
  }
  return recurse(v, w, n, 0, maxw);
}

//  ***** MAIN *****
int main(){
  //ios::sync_with_stdio(false);
  cin.tie(NULL);

  int tc; cin >> tc;
  while(tc--){
    int n;
    cin >> n;
    int v[LIMIT], w[LIMIT];

    for (int i = 0; i < n; i++) {
      cin >> v[i] >> w[i];
    }

    int people, personMaxWeight;
    cin >> people;
    int output = 0;
    for (int person = 0; person < people; ++person) {
      cin >> personMaxWeight;
      output += solve(personMaxWeight, v, w, n);
    }
    std::cout << output << std::endl;
  }


  return 0;
}

