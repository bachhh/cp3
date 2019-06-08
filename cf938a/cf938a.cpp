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

bool isVow( char c){
  return c == 'a' || c == 'e' || c == 'i' || c=='o' || c=='u' || c == 'y';
}

//  ***** MAIN *****
int main(){
  //ios::sync_with_stdio(false);
  cin.tie(NULL);

  int n; cin >> n;

  string s; cin >> s;

  stack<char> st;

  for(char c : s){
    if(!isVow(c)){
      st.push(c);
    }
    else {
      if(st.empty() || !isVow(st.top())){
        st.push(c);
      }
    }
  }
  string w  = "";
  while(!st.empty()){
    w+= st.top(); st.pop();
  }
  reverse(w.begin(), w.end());

  std::cout << w << std::endl;
  return 0;
}

