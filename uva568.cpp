#include <bits/stdc++.h>

using namespace std;

#define P 1000000
typedef pair<int64_t, int64_t> ii;
typedef int64_t ll;

ll dp[10000];

ll fact(ll n){
  if(n== 1) return dp[n] = 1;
  if(dp[n] != -1) return dp[n];
  else {
    ll temp = (n*(fact(n-1))%P);
    while(temp % 10 == 0) temp /= 10;
    return dp[n] = temp;
  }
}

//  ***** MAIN *****
int main(){

  //ios::sync_with_stdio(false);
  cin.tie(NULL);

  int n;
  memset(dp, -1, sizeof(dp[0])*10000);

  while(cin >> n){

    ll f = fact(n);
    f %= 10;

    printf("%5d -> %ld\n", n, f);
  }

  return 0;
}

