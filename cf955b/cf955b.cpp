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

//  ***** MAIN *****
int main(){

  //ios::sync_with_stdio(false);
  cin.tie(NULL);

  string s; cin >> s;
  int a[26] = {0};
  for(char c : s){
    a[c-'a']++;
  }
  int c= 0;
  for (int i = 0; i < 26; ++i) {
    if(a[i]) c++;
  }
  if(c>4 || c==1){
    std::cout << "No"<< std::endl;
  }
  if(c==4){
    std::cout << "Yes" << std::endl;
  }
  if(c==3){
    int t= 0;
    for(int i = 0; i < 26; ++i){
      if(a[i] == 1){
        t++;
      }
    }
    if(t==3){
      std::cout << "No" << std::endl;
    }
    else {
      std::cout << "Yes" << std::endl;
    }
  }
  if(c==2){
    for (int i = 0; i < 26; ++i) {
      if(a[i]==1){
        std::cout << "No" << std::endl;
        return 0;
      }
    }
    std::cout << "Yes" << std::endl;
  }


  return 0;
}

