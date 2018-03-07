#include <bits/stdc++.h>

using namespace std;

#define LIMIT 100
typedef int64_t ll;
typedef pair<ll, ll> ii;
int gcd(ll a, ll b) { return (b==0)?a:gcd(b, a%b); }
int lcm(ll a, ll b) { ll i=(a/gcd(a,b))*b; assert(i>0); return i; }

//  ***** MAIN *****
int main(){
  //ios::sync_with_stdio(false);

  cin.tie(NULL);
  int a, b; cin >> a >> b;
  string s; cin >> s;
  int flag = true;
  flag &=  (s.size() == a+b+1);
  for (int i = 0; i < s.size(); ++i) {
    if (i == a) flag &= s[i] == '-';
    else { flag &= (s[i] <= '9' && s[i] >= '0');
    }
  }
  if (flag) std::cout << "Yes" << std::endl;
  else  std::cout << "No" << std::endl;


  return 0;
}

