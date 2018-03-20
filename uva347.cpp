#include <bits/stdc++.h>

using namespace std;

#define LIMIT 100
#define PLIMIT 10000010
#define MOD 1000000007ll
#define INF 1e9
typedef long long ll;
typedef pair<ll, ll> ii;
int gcd(ll a, ll b) { return (b==0)?a:gcd(b, a%b); }
int lcm(ll a, ll b) { ll i=(a/gcd(a,b))*b; assert(i>0); return i; }
int dx[4] = {0, 1, 0, -1}, dy[4] = {-1, 0, 1, 0};

bool check(string a){
  int counter[10]= {0};
  for(char c : a){ counter[c-'0']++; }
  for (int i = 0; i < 10; ++i) { if(counter[i] >1) return false; }
  int p = 0, n=0, c= 0;
  while(a[n] != '0'){
    p = n;
    n = (n+(a[n]-'0'))%a.size();
    c++;
    a[p] = '0';
  }
  return n == 0 && c == a.size();
}

//  ***** MAIN *****
int main(){
  //ios::sync_with_stdio(false);
  cin.tie(NULL);
  int r;

  int c = 1;

  vector<int> v;
  for (int i = 0; i < 10000000; ++i) {
    if(check(to_string(i))) v.push_back(i);
  }

  while(cin >> r && r){
    printf("Case %d: %d\n", c++,
        *lower_bound(v.begin(), v.end(), r));
  }

  return 0;
}

