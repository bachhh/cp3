#include <bits/stdc++.h>

using namespace std;

#define LIMIT 100
typedef pair<int64_t, int64_t> ii;
typedef int64_t ll;
int gcd(ll a, ll b) { return (b==0)?a:gcd(b, a%b); }
int lcm(ll a, ll b) { ll i=(a/gcd(a,b))*b; assert(i>0); return i; }

//  ***** MAIN *****
int main(){
  //ios::sync_with_stdio(false);
  cin.tie(NULL);

  int n; cin >> n;
  int a[52] = {0};

  for (int i = 1; i < n; ++i) {
    cin >> a[i];
  }


  vector<ii> op;
  for(int i = 1; i < n; ++i){
    if(a[i] <0 ){
      if( a[i-1] < 0 ){
        op.push_back(ii(i+1, i));
        a[i-1] += a[i];
      }
      else {
        if(abs(a[i]) > abs(a[i-1]) ){
          op.push_back(ii(i+1, i));
          a[i-1] += a[i];
          op.push_back(ii(i+1, i));
          a[i-1] += a[i];
        }
        else {
          op.push_back(ii(i, i+1));
          a[i] += a[i-1];
          op.push_back(ii(i, i+1));
          a[i] += a[i-1];
        }
      }
    }
    if (a[i] >0){
      if (a[i-1] > a[i]){
        op.push_back(ii(i+1, i));
        a[i] += a[i-1];
      }
    }
  }

  std::cout << op.size() << std::endl;
  for(auto p : op){
    printf("%ld %ld\n",p.first, p.second);
  }

  return 0;
}

