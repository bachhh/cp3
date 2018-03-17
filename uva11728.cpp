#include <bits/stdc++.h>

using namespace std;

#define LIMIT 10000010
#define PLIMIT 10000010
#define MOD 1000000007ll
#define INF 1e9
typedef long long ll;
typedef pair<ll, ll> ii;
int gcd(ll a, ll b) { return (b==0)?a:gcd(b, a%b); }
int lcm(ll a, ll b) { ll i=(a/gcd(a,b))*b; assert(i>0); return i; }

vector<int> primes;

ll sumDiv(ll N) {
  ll PF_idx = 0, PF = primes[PF_idx], ans = 1;
  // start from ans = 1
  while (PF * PF <= N) {
    ll power = 0;
    while (N % PF == 0) { N /= PF; power++; }
    ans *= ((ll)pow((double)PF, power + 1.0) - 1) / (PF - 1);
    PF = primes[++PF_idx];
  }
  if (N != 1) ans *= ((ll)pow((double)N, 2.0) - 1) / (N - 1); // last
  return ans;
}

//  ***** MAIN *****
int main(){
  //ios::sync_with_stdio(false);
  cin.tie(NULL);

  // check
  bitset<LIMIT> bs; bs.set();
  for (int i = 2; i*i < PLIMIT; ++i) {
    for (int j = i*i; bs[i] &&  j < PLIMIT; j += i) {
      bs[j] = 0;
    }
  }

  // check
  for (int i = 2; i < LIMIT; ++i) {
    if(bs[i]) primes.push_back(i);
  }

  ll s, tc = 1;
  while(cin >> s && s ) {

    bool flag = false;
    for (int i = s; i > 0; --i) {
      if(sumDiv(i) == s){
        printf("Case %lld: %d\n",tc, i);
        flag = true;
        break;
      }
    }

    if(!flag) {
      printf("Case %lld: -1\n", tc);
    }
    tc++;
  }
  return 0;
}

