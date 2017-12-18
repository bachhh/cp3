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

#define LIMIT 100001

//  ***** MAIN *****
int main(){
  //ios::sync_with_stdio(false);
  //cin.tie(NULL);

  int n; cin >> n;
  int t[LIMIT];
  int w[LIMIT];
  for (int i = 0; i < n; ++i) {
    cin >> t[i];
  }

  sort(t, t+n);

  int counter = 0;
  int last = 0;

  for (int i = 0; i < n; ++i) {
    if( last <= t[i]){
      last += t[i];
      counter++;
    }
  }

  std::cout << counter << std::endl;

  return 0;
}
