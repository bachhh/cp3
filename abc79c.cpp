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

  string s; cin >> s;
  int x[4];

  for (int i = 0; i < 4; ++i) { x[i] = s[i]-'0'; }

  for(int i = 0; i < (1<<3); ++i){

    int o = x[0];
    string w = ""; w += s[0];

    for(int j = 0; j < 3; ++j){
      if( i&(1<<j) ){
        o += x[j+1];
        w += "+";
        w += (s[j+1]);
      }
      else{
        o -= x[j+1];
        w += "-";
        w += (s[j+1]);
      }
    }
    w+= "=7";

    if(o==7){
      std::cout << w << std::endl;
      return 0;
    }

  }

  return 0;
}

