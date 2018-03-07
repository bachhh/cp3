#include <bits/stdc++.h>

using namespace std;

#define LIMIT 100
typedef int64_t ll;
typedef pair<ll, ll> ii;
typedef tuple<int, int, int> iii;
int gcd(ll a, ll b) { return (b==0)?a:gcd(b, a%b); }
int lcm(ll a, ll b) { ll i=(a/gcd(a,b))*b; assert(i>0); return i; }



//  ***** MAIN *****
int main(){
  //ios::sync_with_stdio(false);
  cin.tie(NULL);
  int n,h;
  cin >> n >> h;
  queue<iii> qu;

  int a[100000];
  int b[100000];

  for (int i = 0; i < n; ++i) {
    cin >> a[i] >> b[i];
  }
  sort(b, b+n);
  sort(a, a+n);
  int i = n-1, k = n-1;
  int t =0;
  while(h > 0){
    if(b[k] >a[i]){
      h -= b[k];
      k--;
    }
    else{
      h -= a[i];
    }
    t++;
  }
  std::cout << t << std::endl;

  return 0;
}


