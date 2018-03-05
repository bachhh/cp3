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
  int n;

  cin >> n;

  getchar();
  for (int i = 0; i < n; ++i) {
    string s;

    getline(cin, s);

    ll a[10000];

    int n = 0, from = 0, to;
    while( from < s.size()){
      to = s.find(' ', from);
      if (to == s.npos) to = s.size()-1;
      a[n] = stoi( s.substr(from,to -from+1 ) );
      n++;
      from = to+1;
    }

    ll ma = -1;

    if (n==1) {std::cout << a[0] << std::endl; continue;}

    for (int j = 0; j < n; ++j) {
      for (int k = j+1; k < n; ++k) {
        ma = max<ll>(ma, gcd(a[j], a[k]));
      }
    }

    std::cout << ma << std::endl;
  }


  return 0;
}

