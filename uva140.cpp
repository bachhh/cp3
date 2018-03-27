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

int maxBandwidth(string w, vector<string> neighbor){
  int bw = 1;
  for(int i = 0; i <w.size(); ++i){
    char c = w[i];
    for(char nei : neighbor[c-'A'] ){
      bw = max(bw, abs( (int)w.find(nei) - i) );
    }
  }
  //std::cout << w << " " << bw  << std::endl;
  return bw;
}
//  ***** MAIN *****
int main(){
  //ios::sync_with_stdio(false);
  cin.tie(NULL);

  string s;

  while(cin >> s && s != "#"){
    int ind = 0;
    vector<string> v(8, "");
    while(ind != s.npos){
      int colon = s.find(':', ind+1);
      char node = s.substr(ind+(ind>0),1)[0];
      string neighbor = s.substr(colon+1, s.find(';', colon+1)-colon-1);
      v[node-'A'] = neighbor;
      ind = s.find(';', colon+1);
    }

    string w = "ABCDEFGH";
    string ans;
    int mint = INT_MAX;
    do {
      int t = maxBandwidth(w, v);
      if(t < mint){
        ans = w;
        mint = t;
      }
      if(t==mint){
        if(w<ans){
          ans = w;
        }
      }
    }while(next_permutation(w.begin(), w.end()));

    for(char c : ans){
      cout << c << " ";
    }
    cout << "-> " << mint << endl;
  }

  return 0;
}

