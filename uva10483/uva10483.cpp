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

string convert(int a){
  string ret = "";
  int dec = 2;
  while(dec--){
    ret+= to_string(a%10);
    a/= 10;
  }
  ret += '.';
  if(!a) ret += '0';
  while(a){
    ret+= to_string(a%10);
    a/=10;
  }
  reverse(ret.begin(), ret.end());
  return ret;
}

string convertABC(int i, int j, int k, int a){
  string ret ="";
  string si = convert(i);
  string sj = convert(j);
  string sk = convert(k);
  string sa = convert(a);
  ret += sa + " = " + si + " + " + sj + " + " + sk;
  ret += " = " + si + " * " + sj + " * " + sk;
  return ret;
}

//  ***** MAIN *****
int main(){
  //ios::sync_with_stdio(false);
  cin.tie(NULL);

  double a, b;
  cin >> a >> b;

  int x = a*100;
  int y = b*100;

  vector<string> v;

  for(ll i = 0; i*3 <= y; ++i){
    for (ll j = i; i+j*2 <= y; ++j) {
      if(i*j<=10000) continue;
      ll k = (i+j)*10000/(i*j-10000);
      if (k < i || k < j ) continue;
      if( ((i+j)*10000)%(i*j-10000) != 0) continue;
      else if(i+j+k <= y && i+j+k >= x) {
        v.push_back(convertABC(i, j, k, i+j+k));
      }
    }
  }


  sort(v.begin(), v.end(),
      [ ](string a, string b){
        //if(a.size()!= b.size()) return a.size() < b.size();
        string wa = a.substr(0, a.find(' '));
        string wb = b.substr(0, b.find(' '));
      if(wa.size() != wb.size() ) return wa.size()<wb.size();
        return wa < wb ;
      });

  for(string s : v){
    std::cout << s << std::endl;
  }


  return 0;
}
