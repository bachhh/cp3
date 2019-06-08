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

bool check(string s1, string s2, int n1, int n2){
  int ret1 = 0;
  for (int i = 0; i < 4; ++i) {
    if(s1[i] == s2[i]) {
      ret1++;
      s1[i] = '*';
      s2[i] = '!';
    }
  }
  int ret2 =0;
  for (int i = 0; i < 4; ++i) {
    for (int j = 0; j < 4; ++j) {
      if(s1[i] == s2[j]){
        ret2++;
      }
    }
  }
  return ret1==n1 && ret2==n2;
}

//  ***** MAIN *****
int main(){
  //ios::sync_with_stdio(false);
  cin.tie(NULL);

  int tc; cin >> tc;
  //std::cout << diff("ABCD", "EFAB") << std::endl;
  while(tc--){
    string s1, s2;
    int n1, n2, n3, n4;
    cin >> s1  >>  n1 >>  n2>>  s2 >>  n3 >>  n4;
    string seq = "BGORVY";
    int t = 0;
    do {
      if(check(s1, seq, n1, n2) && check(s2, seq, n3, n4)){
        t++;
      }
    } while(next_permutation(seq.begin(), seq.end() ));

    if(t>0){
      std::cout << "Possible" << std::endl;
    }
    else{
      std::cout << "Cheat" << std::endl;
    }
  }


  return 0;
}

