#include <bits/stdc++.h>

using namespace std;

#define LIMIT 100
typedef pair<int64_t, int64_t> ii;
typedef int64_t ll;
int gcd(ll a, ll b) { return (b==0)?a:gcd(b, a%b); }
int lcm(ll a, ll b) { ll i=(a/gcd(a,b))*b; assert(i>0); return i; }

int toInt(string a, int &i){
  string w = a.substr(i, a.find(i, ' '));
  i = a.find(i, ' ')+1;
  return stoi(w);
}

//  ***** MAIN *****
int main(){
  //ios::sync_with_stdio(false);
  cin.tie(NULL);
  string s;
  ll a;
  while(cin >> a && a != 0){

    vector<int> v; v.push_back(a);

    ll b;

    while(cin >> b && b!= 0){ v.push_back(b); }

    ll o = abs(v[1]- v[0]);

    for(int i  = 1; i < v.size(); ++i) v[i] = abs(v[i] - v[0]);


    for(int i = 3; i < v.size(); ++i) o = gcd(o, v[i]);
    std::cout << o << std::endl;

  }

  return 0;
}

