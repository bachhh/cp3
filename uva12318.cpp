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
#define LIMIT 11
#define INF INT_MAX


//  ***** MAIN *****
int main(){
  //ios::sync_with_stdio(false);
  //cin.tie(NULL);

  uint64 n, m;
  uint64 px;
  int k;
  int p[15];

  while(cin >> n >> m && (n||m)){
    cin >> k;
    for (int i = 0; i <= k ; i++) {
      cin >> p[i];
    }

    // P(x) mod n+1
    vector<bool> truth(n+9, false);

    for (int x = 0; x <= m; ++x) {
      px = 0;
      // Calculate px using p(x) = a0 + x(a1+x(a2+x...ak-1+xak)..)
      for (int i = k; i > 0 ; --i) {
        px += p[i];
        px *= x;
        // Modulo after each step to avoid overflow
        px %= n+1;
      }

      px += p[0];
      truth[px%(n+1)] = true;
    }

    uint64 counter = 0;
    for (int i = 0; i <= n; i++) {
      if ( truth[i] ) counter++;
    }

    std::cout <<  counter << std::endl;
  }
  return 0;
}
