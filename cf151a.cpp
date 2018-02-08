#include <bits/stdc++.h>

using namespace std;

#define LIMIT 100
typedef pair<int64_t, int64_t> ii;

//  ***** MAIN *****
int main(){
  //ios::sync_with_stdio(false);
  cin.tie(NULL);

  int n, k , l, c, d, p, nl, np;
  cin >> n >> k  >> l >> c >> d >> p >> nl >> np;
  int a = min((k*l)/nl, min(c*d, p/np));
  std::cout << a/n << std::endl;

  return 0;
}

