#include <bits/stdc++.h>

using namespace std;

#define LIMIT 100
typedef pair<int64_t, int64_t> ii;

//  ***** MAIN *****
int main(){
  //ios::sync_with_stdio(false);
  cin.tie(NULL);
  int n, k;

  cin >> n >> k;
  vector<ii> v(n);
  for (int i = 0; i < n; ++i) {
    cin >> v[i].first >> v[i].second;
  }
  sort(v.begin(), v.end(),
      [ ] (ii a , ii b){
        if(a.first == b.first){
          return a.second <b.second;
        }
        else return a.first > b.first;
      });

  k--;
  int l = k;
  int r = k;

  int counter = 0;
  while(l >= 0 && r < n){
    if(v[l-1] == v[l] ){
      l--;
      counter = 0;
    }
    else { counter++;}
    if(v[r+1] == v[r] ){
      counter = 0;
      r++;
    }
    else {
      counter++;
    }
    if ( counter>=2 ) break;
  }
  std::cout << r-l+1 << std::endl;

  return 0;
}

