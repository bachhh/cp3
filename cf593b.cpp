#include <bits/stdc++.h>

using namespace std;

#define LIMIT 100000
#define EPS 1e-9

//  ***** MAIN *****
int main(){
  //ios::sync_with_stdio(false);
  cin.tie(NULL);
  int n;
  cin >> n;

  int64_t k;
  int64_t b;
  vector<pair<int64_t, int64_t>> y;
  int64_t x1, x2;
  cin >> x1 >> x2;

  for (int i = 0; i < n; i++) {
    cin >> k >> b;
    y.push_back(make_pair(k*x1+b, k*x2+b));
  }

  sort(y.begin(), y.end());

  /*
   * correctness: If ith and jth line intersect ( i > j), it follows thato
   * kith*xleft+bith > kjth*xleft+bjth && kith*xright+bith < kjth*xright + bjth
   * if i - j > 1  then there exist a kth line with yjthleft < ykthleft < yithleft
   * we have ykthleft  < yithleft && ykthright < yithright
   * (assumeing k don't interesct with ith
   * this kth line also interesect j because yjthright > yithright > ykthright
   * by the above of interesction definition, kth intersect with j
   * so this algorithm only check between adjacent line in the sorted list
   */

  for (int i = 1; i < n; i++) {
    if (y[i].first != y[i-1].first && y[i-1].second > y[i].second ){
      std::cout << "YES" << std::endl;
      return 0;
    }
  }
  std::cout << "NO" << std::endl;

  return 0;
}

