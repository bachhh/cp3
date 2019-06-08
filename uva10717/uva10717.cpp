#include <bits/stdc++.h>

using namespace std;

#define LIMIT 1000000
typedef pair<int64_t, int64_t> ii;
typedef int64_t ll;

int gcd(int a, int b){
  if (b== 0) return a;
  return gcd(b, a%b);
}

int lcm(int a, int b){
  return (a*b)/gcd(a, b);
}
//  ***** MAIN *****
int main(){
  //ios::sync_with_stdio(false);
  cin.tie(NULL);

  int n, t;

  while(cin >> n >> t && (n|t)){

    int len[50];
    for (int i = 0; i < n; ++i) {
      cin >> len[i];
    }
    int h;

    for (int i = 0; i < t; ++i) {

      cin >> h;

      int mi = INT_MAX;
      int ma = 0;

      for (int i = 0; i < n; ++i) {
        for (int j = i+1; j < n; ++j) {
          for (int k = j+1; k < n; ++k) {
            for (int l = k+1; l < n; ++l) {
              int mul = 1;
              mul = lcm(mul, len[i]);
              mul = lcm(mul, len[j]);
              mul = lcm(mul, len[k]);
              mul = lcm(mul, len[l]);
              if (mul > h){
                mi = min(mi,mul );
              }
              else if(h%mul == 0) {
                mi = ma = h;
              }
              else{
                mi = min(mi, (h/mul+1)*mul);
                ma = max(ma, (h/mul)*mul);
              }
            }
          }
        }
      }

      printf("%d %d\n", ma, mi);
    }

  }

  return 0;
}

