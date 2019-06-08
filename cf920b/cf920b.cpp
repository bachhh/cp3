#include <bits/stdc++.h>

using namespace std;

#define LIMIT 100

typedef pair<int, int> ii;

//  ***** MAIN *****
int main(){
  //ios::sync_with_stdio(false);
  cin.tie(NULL);


  int tc; cin >> tc;
  while(tc--){
    int n; cin >> n;
    int l, r;
    vector<ii> v;
    for (int i = 0; i < n; i++) {
      cin >> l >> r;
      v.push_back(ii(l, r));
    }

    std::cout << v[0].first << " \n"[0==n-1];
    int done = v[0].first+1;

    for (int i = 1; i < v.size(); i++) {

      if(v[i].first >= done){
        cout << v[i].first  << " \n"[i==n-1];
        done = v[i].first + 1;
      }
      else if(v[i].first < done){
        // if the student can wait
        if (v[i].second >= done){
          std::cout << done << " \n"[i==n-1];
          done++;
        }
        else {
          cout << 0 << " \n"[i==n-1];
        }
      }
    }

  }


  return 0;
}

