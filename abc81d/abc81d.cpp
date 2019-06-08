#include <bits/stdc++.h>

using namespace std;

#define LIMIT 100
typedef pair<int, int> ii;
typedef int64_t ll;
int gcd(ll a, ll b) { return (b==0)?a:gcd(b, a%b); }
int lcm(ll a, ll b) { ll i=(a/gcd(a,b))*b; assert(i>0); return i; }

//  ***** MAIN *****
int main(){
  //ios::sync_with_stdio(false);
  cin.tie(NULL);

  int n; cin >> n;
  int a[52] = {0};

  int ma = INT_MIN, mi = INT_MAX;
  int imax, imin;

  for (int i = 0; i < n; ++i) {
    cin >> a[i];
    if (a[i] > ma){
      ma = a[i];
      imax = i;
    }
    if(a[i] < mi){
      mi = a[i];
      imin = i ;
    }
  }

  if(abs(ma) > abs(mi)){
    std::cout << 2*n-1 << std::endl;
    for (int i = 0; i < n; ++i) {
      printf("%d %d\n", imax+1, i+1);
      a[i] += a[imax];
    }
    for (int i = 1; i < n; ++i) {
      printf("%d %d\n", i, i+1);
      a[i] += a[i-1];
    }
  }
  else {
    std::cout << 2*n-1 << std::endl;
    for (int i = 0; i < n; ++i) {
      printf("%d %d\n", imin+1, i+1);
      a[i] += a[imin];
    }
    for (int i = n-2; i >= 0; --i) {
      printf("%d %d\n", i+2, i+1);
      a[i] += a[i+1];
    }
  }

  //for (int i = 0; i < n; ++i) { cout << a[i] << " \n"[i==n-1];}



  return 0;
}

