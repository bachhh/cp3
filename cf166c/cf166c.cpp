#include <bits/stdc++.h>

using namespace std;

#define LIMIT 100
typedef pair<int64_t, int64_t> ii;

//  ***** MAIN *****
int main(){

  //ios::sync_with_stdio(false);
  cin.tie(NULL);

  int n; cin >> n;
  int x; cin >> x;

  int v[1000];

  for (int i = 0; i < n; ++i) {
    cin >> v[i];
  }

  sort(v, v+n);
  int counter = 0;

  while(v[(n+1)/2-1] != x){
    v[n] = x;
    n++;
    sort(v, v+n);
    counter++;
  }

  std::cout << counter << std::endl;


  return 0;
}

