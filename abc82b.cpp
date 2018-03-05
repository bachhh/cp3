#include <bits/stdc++.h>

using namespace std;

#define LIMIT 100
typedef pair<int64_t, int64_t> ii;
typedef int64_t ll;
int gcd(ll a, ll b) { return (b==0)?a:gcd(b, a%b); }
int lcm(ll a, ll b) { ll i=(a/gcd(a,b))*b; assert(i>0); return i; }

int lesser(string a, string b){

  for(int i = 0; i <min(a.size(), b.size()); ++i){
    if(a[i] < b[i]){
      return true;
    }
    if (a[i] > b[i]){
      return false;
    }
  }

  return a.size()<b.size();
}

//  ***** MAIN *****
int main(){
  //ios::sync_with_stdio(false);
  cin.tie(NULL);
  string s, t;
  cin >> s >> t;
  sort(s.begin(),  s.end());
  sort(t.begin(), t.end(), greater<char>());

  if(lesser(s, t)){
    std::cout << "Yes" << std::endl;
  }
  else{
    std::cout << "No" << std::endl;
  }

  return 0;
}

